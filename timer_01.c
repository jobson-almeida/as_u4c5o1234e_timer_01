#include <stdio.h>
#include "pico/stdlib.h"

// disposição dos LEDs na placa BitDogLab que disponho
#define LED_RED 13
#define LED_BLUE 12 // cor substituta ao amarelo ausente na placa
#define LED_GREEN 11

int main()
{
    stdio_init_all();

    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);

    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);

    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    while (true)
    {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
