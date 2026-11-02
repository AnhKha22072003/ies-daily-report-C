#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>

//Bài 1
// định nghĩa 1 macro với giá trị là 1 dịch trái 0 bit, tức là 0000 0001
// 1U có nghĩa là 1 là một số nguyên không dấu (unsigned int), và << 0 có nghĩa là dịch trái 0 bit, tức là giữ nguyên giá trị ban đầu.
#define READY_MASK (1U << 0)
// định nghĩa 1 macro với giá trị là 1 dịch trái 1 bit, tức là 0000 0010
#define ERROR_MASK (1U << 1)
// định nghĩa 1 macro với giá trị là 1 dịch trái 2 bit, tức là 0000 0100
#define BUSY_MASK (1U << 2)

// int main(void) {
//     uint8_t status = 0;

//     // 1. Bat READY
//     status |= READY_MASK;

//     // 2. Bat BUSY
//     status |= BUSY_MASK;

//     // 3. Kiem tra ERROR
//     if ((status & ERROR_MASK) != 0) {
//         printf("Sensor ERROR\n");
//     } else {
//         printf("Sensor OK\n");
//     }

//     // 4. Tat BUSY
//     status &= ~BUSY_MASK;

//     printf("Decimal: %u\n", (unsigned)status);
//     printf("Hex: 0x%02" PRIX8 "\n", status);

//     return 0;
// }

//Bài 2

const char *check_temperature(int16_t temp)
{
    if (temp < 300)
    {
        return "NORMAL";
    }
    else if (temp < 400)
    {
        return "WARNING";
    }
    else
    {
        return "CRITICAL";
    }
}

// int main(void)
// {
//     int16_t temperatures[] = {
//         285, 300, 350, 399, 400, 450};
//     size_t size = sizeof(temperatures) / sizeof(temperatures[0]);
//     // kiểu dữ liệu trả về của sizeof là size_t, đây là một kiểu dữ liệu không dấu (unsigned) được sử dụng để biểu diễn kích thước của các đối tượng trong bộ nhớ. Nó được định nghĩa trong thư viện <stddef.h> và thường được sử dụng trong các phép toán liên quan đến kích thước và chỉ số mảng. Sử dụng size_t giúp đảm bảo rằng các giá trị kích thước luôn không âm và có thể đại diện cho các kích thước lớn hơn so với các kiểu dữ liệu số nguyên thông thường như int hoặc long.
//     //điểm khác biệt giữa C và PHP,javascript đã học là C không có foreach như PHP và javascript, thay vào đó C sử dụng vòng lặp for để lặp qua các phần tử của mảng
//     for (size_t i = 0; i < size; i++)
//     {
//         int16_t temp = temperatures[i];

//         printf("Temperature: %.1f C | %s\n",
//                (double)temp / 10.0,
//                check_temperature(temp));
//     }

//     return 0;
// }

// Bài 3
bool is_timeout(uint32_t start,
                uint32_t now,
                uint32_t timeout) {

    uint32_t elapsed = (uint32_t)(now - start);

    return elapsed >= timeout;
}

// int main(void) {
//     uint32_t start = UINT32_MAX - 5U;
//     uint32_t now = 5U;
//     uint32_t timeout = 10U;

//     uint32_t elapsed = (uint32_t)(now - start);

//     printf("Start: %" PRIu32 "\n", start);
//     printf("Now: %" PRIu32 "\n", now);
//     printf("Elapsed: %" PRIu32 "\n", elapsed);

//     if (is_timeout(start, now, timeout)) {
//         printf("TIMEOUT\n");
//     } else {
//         printf("WAITING\n");
//     }

//     return 0;
// }
// Bài 4
// định nghĩa số lượng chân GPIO là 16
#define GPIO_PIN_COUNT 16U
// biến toàn cục để lưu trạng thái của các chân GPIO, mỗi bit đại diện cho một chân GPIO
static uint32_t gpio_output = 0U;

void gpio_set(uint8_t pin) {
    if (pin >= GPIO_PIN_COUNT) {
        printf("Invalid pin: %u\n", (unsigned)pin);
        return;
    }

    gpio_output |= (1UL << pin);
}

void gpio_reset(uint8_t pin) {
    if (pin >= GPIO_PIN_COUNT) {
        printf("Invalid pin: %u\n", (unsigned)pin);
        return;
    }

    gpio_output &= ~(1UL << pin);
}

void gpio_toggle(uint8_t pin) {
    if (pin >= GPIO_PIN_COUNT) {
        printf("Invalid pin: %u\n", (unsigned)pin);
        return;
    }

    gpio_output ^= (1UL << pin);
}

void gpio_print(void) {
    printf("GPIO: 0x%08" PRIX32 "\n", gpio_output);
}

int main(void) {
    gpio_set(3);
    gpio_print();

    gpio_set(7);
    gpio_print();

    gpio_toggle(3);
    gpio_print();

    gpio_reset(7);
    gpio_print();

    gpio_set(20);
    gpio_print();

    return 0;
}