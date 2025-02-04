#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_RED 13
#define LED_BLUE 12 // cor substituta ao amarelo ausente na placa de desenvolvimento
#define LED_GREEN 11

bool repeating_timer_callback(struct repeating_timer *t)
{
    printf("repeating_timer_callback\n");
}

int main()
{
    stdio_init_all();

    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);

    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);

    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    // armazenara as informações sobre o temporizador
    struct repeating_timer timer;

    // configura o time com delay de 3000 milisegundos 
    // para cada uma das chamadas da função de callback
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    while (true)
    {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
