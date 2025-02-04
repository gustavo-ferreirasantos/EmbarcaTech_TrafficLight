#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define RED_LED_PIN 11
#define YELLOW_LED_PIN 12
#define GREEN_LED_PIN 13

int event = 0;

void init(){
    // Inicializar os pinos como GPIO
    gpio_init(RED_LED_PIN);
    gpio_init(YELLOW_LED_PIN);
    gpio_init(GREEN_LED_PIN);

    // Definir direção como saída
    gpio_set_dir(RED_LED_PIN, GPIO_OUT);
    gpio_set_dir(YELLOW_LED_PIN, GPIO_OUT);
    gpio_set_dir(GREEN_LED_PIN, GPIO_OUT);
}

bool repeating_timer_callback(struct repeating_timer *t){
    if(!event){
        gpio_put(RED_LED_PIN, false);
        gpio_put(YELLOW_LED_PIN, true);
        event++;
    }else if(event == 1){
        gpio_put(YELLOW_LED_PIN, false);
        gpio_put(GREEN_LED_PIN, true);
        event++;
    }else{
        gpio_put(GREEN_LED_PIN, false);
        gpio_put(RED_LED_PIN, true);
        event=0;    
    }
    return true;
}


int main() {
    int seconds = 3;
    // Inicializa a comunicação serial, permitindo o uso de funções como printf. E também inicializa os leds
    stdio_init_all();
    init();

    // Inicializando o semáforo com o led vermelho.
    gpio_put(RED_LED_PIN, true);
    gpio_put(YELLOW_LED_PIN, false);
    gpio_put(GREEN_LED_PIN, false);
    printf("Changing the traffic light in %d seconds\n", seconds--);

    
    // Declaração de uma estrutura de temporizador de repetição. Esta estrutura armazenará informações sobre o temporizador configurado
    struct repeating_timer timer;
    // Configura o temporizador para chamar a função de callback a cada 3 segundos.
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);


    // Loop infinito que mantém o programa em execução.
    while (true) {
        sleep_ms(1000);
        seconds = (!seconds) ? 3 : seconds;
        printf("Changing the traffic light in %d seconds\n", seconds--);
    }
    return 0;
}