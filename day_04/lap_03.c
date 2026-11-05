#include <stdio.h>

#define SAMPLE_COUNT 8
#define ADC_MIN 0
#define ADC_MAX 4095
#define HIGH_THRESHOLD 3000

int is_valid_sample(int raw);

int main(void)
{
    int valid_count = 0;
    int invalid_count = 0;
    int high_count = 0;
    int sum = 0;
    int min = 0;
    int max = 0;

    for (int i = 0; i < SAMPLE_COUNT; ++i) {
        int raw;

        if (scanf("%d", &raw) != 1) {
            fprintf(stderr, "Can nhap du 8 so nguyen.\n");
            return 1;
        }

        if (!is_valid_sample(raw)) {
            ++invalid_count;
            continue;
        }

        if (valid_count == 0) {
            min = raw;
            max = raw;
        } else {
            if (raw < min) {
                min = raw;
            }
            if (raw > max) {
                max = raw;
            }
        }

        ++valid_count;
        sum += raw;

        if (raw >= HIGH_THRESHOLD) {
            ++high_count;
        }
    }

    printf("VALID=%d\n", valid_count);
    printf("INVALID=%d\n", invalid_count);

    if (valid_count == 0) {
        printf("NO_VALID_DATA\n");
        return 0;
    }

    double average = (double)sum / valid_count;

    printf("MIN=%d\n", min);
    printf("MAX=%d\n", max);
    printf("AVG=%.2f\n", average);
    printf("HIGH=%d\n", high_count);

    return 0;
}

int is_valid_sample(int raw)
{
    return raw >= ADC_MIN && raw <= ADC_MAX;
}
