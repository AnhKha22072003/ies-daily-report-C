#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <math.h>

#define NAME_SIZE 50
#define INITIAL_CAPACITY 4
#define SCHOLARSHIP_FLAG (1u << 0)
#define DATA_FILE "students.txt"

typedef enum {
    STUDYING = 0,
    PAUSED = 1
} Status;

typedef struct {
    int32_t id;
    char name[NAME_SIZE];
    double score;
    Status status;
    uint8_t flags;
} Student;

typedef struct {
    Student *data;
    size_t size;
    size_t capacity;
} StudentList;

static int read_line(FILE *stream, char *buffer, size_t capacity)
{
    if (fgets(buffer, (int)capacity, stream) == NULL)
        return 0;

    char *newline = strchr(buffer, '\n');

    if (newline != NULL) {
        *newline = '\0';
        return 1;
    }

    int ch = fgetc(stream);

    if (ch == '\n' || ch == EOF)
        return 1;

    while ((ch = fgetc(stream)) != '\n' && ch != EOF) {
    }

    return 0;
}

static int only_spaces(const char *text)
{
    while (*text != '\0') {
        if (!isspace((unsigned char)*text))
            return 0;
        ++text;
    }
    return 1;
}

static int parse_number(const char *text, double *result)
{
    char *end;
    errno = 0;
    double value = strtod(text, &end);

    if (end == text || errno == ERANGE ||
        !isfinite(value) || !only_spaces(end))
        return 0;

    *result = value;
    return 1;
}

static int input_number(const char *prompt,
                        double min, double max,
                        int integer_only, double *result)
{
    char buffer[128];

    for (;;) {
        printf("%s", prompt);

        if (!read_line(stdin, buffer, sizeof buffer)) {
            if (feof(stdin))
                return 0;
            puts("data is too long.Please reenter it");
            continue;
        }

        double value;

        if (parse_number(buffer, &value) &&
            value >= min && value <= max &&
            (!integer_only || value == (double)(int64_t)value)) {
            *result = value;
            return 1;
        }

        puts("invalid data.Please reenter it.");
    }
}

static void update_scholarship(Student *student)
{
    student->flags &= (uint8_t)~SCHOLARSHIP_FLAG;

    if (student->status == STUDYING && student->score >= 8.0)
        student->flags |= SCHOLARSHIP_FLAG;
}

static Student *find_student(StudentList *list, int32_t id)
{
    for (size_t i = 0; i < list->size; ++i) {
        if (list->data[i].id == id)
            return &list->data[i];
    }

    return NULL;
}

static int append_student(StudentList *list, Student student)
{
    if (list->size == list->capacity) {
        size_t capacity;

        if (list->capacity == 0) {
            capacity = INITIAL_CAPACITY;
        } else {
            if (list->capacity > SIZE_MAX / 2)
                return 0;
            capacity = list->capacity * 2;
        }

        if (capacity > SIZE_MAX / sizeof *list->data)
            return 0;

        /* Giữ con trỏ cũ nếu realloc thất bại. */
        Student *temporary =
            realloc(list->data, capacity * sizeof *list->data);

        if (temporary == NULL)
            return 0;

        list->data = temporary;
        list->capacity = capacity;
    }

    list->data[list->size++] = student;
    return 1;
}

static void print_student(const Student *student)
{
    printf("%ld | %s | %.2f | %s | scholarship: %s\n",
           (long)student->id,
           student->name,
           student->score,
           student->status == STUDYING ? "Studying" : "Paused",
           (student->flags & SCHOLARSHIP_FLAG) ? "Yes" : "No");
}

static void add_student(StudentList *list)
{
    Student student = {0};
    double value;

    if (!input_number("Student ID: ", 1, INT32_MAX, 1, &value))
        return;

    student.id = (int32_t)value;

    if (find_student(list, student.id) != NULL) {
        puts("StudyID already exits.");
        return;
    }

    printf("Ho ten: ");

    if (!read_line(stdin, student.name, sizeof student.name) ||
        only_spaces(student.name)) {
        puts("Name can not empty or too long.");
        return;
    }

    if (!input_number("Diem [0..10]: ", 0, 10, 0, &value))
        return;

    student.score = value;

    if (!input_number("Status (0: Studying, 1: Pause): ",
                      0, 1, 1, &value))
        return;

    student.status = (Status)(int)value;
    update_scholarship(&student);

    puts(append_student(list, student)
             ? "Add susses."
             : "dont enough memory.");
}

static void delete_student(StudentList *list, int32_t id)
{
    for (size_t i = 0; i < list->size; ++i) {
        if (list->data[i].id != id)
            continue;

        for (size_t j = i + 1; j < list->size; ++j)
            list->data[j - 1] = list->data[j];

        --list->size;
        puts("Deleted Student.");
        return;
    }

    puts("No find student.");
}

static int compare_score(const void *left, const void *right)
{
    const Student *a = left;
    const Student *b = right;

    return (a->score < b->score) - (a->score > b->score);
}

static int save_students(const StudentList *list)
{
    FILE *file = fopen(DATA_FILE, "w");

    if (file == NULL)
        return 0;

    int success = 1;

    for (size_t i = 0; i < list->size; ++i) {
        const Student *student = &list->data[i];

        if (fprintf(file, "%ld %d\n%s\n%.17g\n",
                    (long)student->id,
                    (int)student->status,
                    student->name,
                    student->score) < 0) {
            success = 0;
            break;
        }
    }

    if (fclose(file) != 0)
        success = 0;

    return success;
}

static int load_students(StudentList *list)
{
    FILE *file = fopen(DATA_FILE, "r");

    if (file == NULL)
        return 0;

    StudentList temporary = {0};
    char line[128];
    int success = 1;

    for (;;) {
        if (!read_line(file, line, sizeof line)) {
            if (!feof(file) || ferror(file))
                success = 0;
            break;
        }

        Student student = {0};
        long id;
        int status;
        char extra;

        if (sscanf(line, "%ld %d %c", &id, &status, &extra) != 2 ||
            id < 1 || id > INT32_MAX ||
            (status != STUDYING && status != PAUSED)) {
            success = 0;
            break;
        }

        student.id = (int32_t)id;
        student.status = (Status)status;

        if (!read_line(file, student.name, sizeof student.name) ||
            only_spaces(student.name) ||
            !read_line(file, line, sizeof line) ||
            !parse_number(line, &student.score) ||
            student.score < 0 || student.score > 10 ||
            find_student(&temporary, student.id) != NULL) {
            success = 0;
            break;
        }

        update_scholarship(&student);

        if (!append_student(&temporary, student)) {
            success = 0;
            break;
        }
    }

    if (fclose(file) != 0)
        success = 0;

    if (!success) {
        free(temporary.data);
        return 0;
    }

    free(list->data);
    *list = temporary;
    return 1;
}

int main(void)
{
    StudentList list = {0};

    for (;;) {
        puts("\n1. Add");
        puts("2. Show");
        puts("3. Find code");
        puts("4. Delete with code");
        puts("5. Arange");
        puts("6. Save file");
        puts("7. Read file");
        puts("0. Exit");

        double value;

        if (!input_number("Select: ", 0, 7, 1, &value))
            break;

        int choice = (int)value;

        if (choice == 0)
            break;

        switch (choice) {
        case 1:
            add_student(&list);
            break;

        case 2:
            if (list.size == 0)
                puts("Empty.");

            for (size_t i = 0; i < list.size; ++i)
                print_student(&list.data[i]);
            break;

        case 3:
        case 4: {
            if (!input_number("ID Find/Delete: ",
                              1, INT32_MAX, 1, &value))
                break;

            int32_t id = (int32_t)value;

            if (choice == 4) {
                delete_student(&list, id);
            } else {
                Student *student = find_student(&list, id);

                if (student != NULL)
                    print_student(student);
                else
                    puts("Student not found.");
            }
            break;
        }

        case 5:
            if (list.size > 1)
                qsort(list.data, list.size,
                      sizeof *list.data, compare_score);
            puts("Arranged.");
            break;

        case 6:
            puts(save_students(&list)
                     ? "Save file."
                     : "Save file fail.");
            break;

        case 7:
            puts(load_students(&list)
                     ? "Read file."
                     : "Error");
            break;

        default:
            break;
        }
    }

    free(list.data);
    return EXIT_SUCCESS;
}