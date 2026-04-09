
# Descrição Inicial

Vamos utilizar o microcontrolado *STM32F446* para realizar uma comunicação I2C com o sensor de batimento cardíaco c/ oxímetro *MAX30100*.

## Objetivo
- Utilizar o sensor MAX30100 para realizar medições cardíacas, de oxímetro e temperatura
  - As medições serão realizadas pelo ADC no pino **XX**
  - A comunicação com o sensore será feita utilizando o protocolo I2C

- Os valores das leituras serão enviados e exibidos no display **Nokia 5110** ou **Display Oled** (se conseguirmos a lib)
- A partir de testes práticos, vamos determinar valores de medições em condições normais e criar valores limites. Estes valores seão utilizados para criar um valor limite, que quando ultrapassado, será acionado um **buzzer** ou **led**.
