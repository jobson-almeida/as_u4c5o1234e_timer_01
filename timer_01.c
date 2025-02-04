#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_RED 13
#define LED_BLUE 12 // cor substituta ao amarelo ausente na placa de desenvolvimento
#define LED_GREEN 11

bool repeating_timer_callback(struct repeating_timer *t)
{
    if (!gpio_get(LED_GREEN) && !gpio_get(LED_BLUE)) // LED green e blue desligados
    {
        gpio_put(LED_RED, !gpio_get(LED_RED)); // inverte o sinal lógico do LED red
    }

    if (!gpio_get(LED_RED) && !gpio_get(LED_GREEN)) // LED red e green desligados
    {
        gpio_put(LED_BLUE, !gpio_get(LED_BLUE)); // inverte o sinal lógico do LED blue
    }

    if (!gpio_get(LED_RED) && !gpio_get(LED_BLUE)) // LED red e blue desligados
    {
        gpio_put(LED_GREEN, !gpio_get(LED_GREEN)); // inverte o sinal lógico do LED green
    }

      if (!gpio_get(LED_BLUE) && !gpio_get(LED_GREEN) && !gpio_get(LED_RED)) // LED blue, green e red desligados
    {
        gpio_put(LED_RED, !gpio_get(LED_GREEN)); // inverte o sinal lógico do LED red de acordo nível lógico do LED green
    }
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

    gpio_put(LED_RED, true);

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
