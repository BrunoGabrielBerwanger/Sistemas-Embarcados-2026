
# Descrição Inicial

Vamos utilizar o microcontrolado **STM32F446** para realizar uma comunicação I2C com o sensor de batimento cardíaco c/ oxímetro **MAX30100**.

## Objetivo
- Realizar medições de batimentos cardíacos e categorizar-los nas 5 zonas de batimento cardíaco.
- A categorização dos estados será informado ao usuário através de um sinal luminoso (LED)


## Descrição
- Utilizar o sensor **MAX30100** para realizar medições cardíacas
  - As medições serão realizadas pelo ADC no pino **XX**
  - A comunicação com o sensore será feita utilizando o protocolo I2C
- Utilizar LED RGB para informar a categoria dos batiamentos cardíacos
  - Cada cor será uma categoria de batimento cardíaco
- Os valores das leituras serão enviados e exibidos no display **Nokia 5110** ou **Display Oled** (se conseguirmos a lib)
- Serão utilizados botões

## Atendimento de Requisitos
- Comunicação I2C com o sensor MAX30100
- Periférico ADC para leitura do sinal cardiáco
- GPIO para controle do led RGB e para receber os inputs dos botões (com interrupção)
