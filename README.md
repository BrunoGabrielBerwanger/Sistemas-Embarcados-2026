# Repositório para Projeto de Sistemas Embarcados 2026/1 GA

## Integrantes
- Bruno Gabriel Berwanger
- Gabriel Krabbe Fonseca

# Descrição Inicial
 
Vamos utilizar o microcontrolado **STM32F446** para realizar uma comunicação I2C com o sensor de batimento cardíaco c/ oxímetro **MAX30100**.
 
## Objetivo
- Detectar pulso de batimento cardíaco e utilizar uma saída visual (Led) para indicar cada pulso.
 
 
## Descrição
- Utilizar o sensor **MAX30100** para realizar medições cardíacas
  - A comunicação com o sensor será feita utilizando o protocolo I2C
- Utilizar o LED integrado do STM32F446 para indicar detecção de pulso.
 
## Atendimento de Requisitos
- Comunicação I2C com o sensor MAX30100
- GPIO para controle do Led e para receber os inputs dos botões.
- TIMM para controle de debounce do botão
