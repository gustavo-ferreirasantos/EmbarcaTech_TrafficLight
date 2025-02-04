# EmbarcaTech_TrafficLight 🚦

## 📌 DESCRIÇÃO
Este projeto implementa a simulação de um semáforo utilizando o Raspberry Pi Pico W, com temporização controlada pela função add_repeating_timer_ms() do Pico SDK. O semáforo segue um fluxo padronizado, alternando entre os estados vermelho → amarelo → verde em intervalos de 3 segundos. Além disso, o sistema exibe mensagens na porta serial a cada segundo. A simulação pode ser realizada no Wokwi, conforme a configuração sugerida, e também testada fisicamente com o auxílio da ferramenta educacional BitDogLab, utilizando um LED RGB nos GPIOs 11, 12 e 13.

---

## 📋 FUNCIONALIDADES
🔹 O semáforo muda de estado a cada 3 segundos, seguindo a sequência: vermelho → amarelo → verde.
🔹 A lógica de troca de LEDs é gerenciada pela função de callback do temporizador.  
🔹 Mensagens são exibidas na porta serial a cada 1 segundo.  

---

## 🛠️ PRÉ-REQUISITOS

- 🛠️ HARDWARE NECESSÁRIO:
  
  - Microcontrolador Raspberry Pi Pico W.  
  - 03 LEDs (vermelho, amarelo e verde).  
  - 03 Resistores de 330 Ω.  
  
- 🖥 SOFTWARE NECESSÁRIO:
  - Raspberry Pi Pico SDK configurado.
  - CMake para compilação.
  - VS Code com a extensão Raspberry Pi Pico.

---

## 🔧 REQUISITOS DO PROJETO  
✅ O acionamento dos LEDs (sinais do semáforo) deve iniciar na cor vermelha, alterando para amarela e, em seguida, verde.  
✅ O temporizador deve ser ajustado para um atraso de 3 segundos (3.000ms).  
✅ A mudança de estado dos LEDs deve ser implementada na função de callback do temporizador.   
✅ A rotina principal, presente no interior da estrutura de repetição while, deve imprimir algum tipo de informação a cada segundo (1.000 ms).

---

## 🚀 COMO EXECUTAR

1️⃣ **Clone este repositório:**

       git clone https://github.com/gustavo-ferreirasantos/EmbarcaTech_TrafficLight.git

2️⃣ **Abra o VS Code e importe o projeto**

3️⃣ **Compile o projeto**

4️⃣ **Execute:**

  - Wokwi para simulação.
  - BitDogLab para testes físicos utilizando um LED RGB.

---

## 🎥 Vídeo de demonstração
🔗 <u>[Assista aqui](https://youtu.be/EIUsXni3w7w)</u>

