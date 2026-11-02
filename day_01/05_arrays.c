// C không có những "collection" cấp cao (như List, Map, Set, Dictionary, Queue...) như java và C#
//Cơ bản array trong C tương tự với C#

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

int main(void) {
    int16_t temperatures[5] = {25, 28, 30};
    size_t count = 3;
    const size_t capacity = 5;

    int16_t new_values[] = {32, 35};

    for (size_t i = 0; i < 2; i++) {
        if (count < capacity) {
            temperatures[count] = new_values[i];
            count++;
        }
    }

    int32_t total = 0;

    for (size_t i = 0; i < count; i++) {
        printf("%d ", (int)temperatures[i]);
        total += temperatures[i];
    }

    if (count > 0) {
        float average = (float)total / count;
        printf("\nAverage: %.2f\n", (double)average);
    }

    return 0;
}
    