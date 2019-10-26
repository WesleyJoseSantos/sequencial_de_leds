 //*************************************************************************************************/
//   Projeto    : Sequencial de Leds
//   Arquivo    : modificacoes.h
//   Descrição  : 
//   Data       : 09/05/2019
//*************************************************************************************************/

const int pinoPotenciometro = A0;       //pino onde está ligado o potenciometro

const int escalaTempo = 10;             //valor que ajusta a sensibilidade do potenciometro.

const int tempoAutomatico = 5000;       //tempo para alternar entre os efeitos.

int getTempo()
{
    int value = analogRead(pinoPotenciometro) / escalaTempo;
    return(value);
}