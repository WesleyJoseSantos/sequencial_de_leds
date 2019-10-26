/*------------------------
SEQUENCIAL LEDS
Fellipe Couto
16/07/2011
------------------------*/

#include <EEPROM.h>
#include "modificacoes.h"

int qtd = 10; //Quantidade de leds.
int qtdSequencia = 10; //Quantidade de sequencias;

int led[] = {
    2, 3, 4, 5, 6, 7, 8, 9, 10, 11
}; //Pinos dos leds.

int controle = 0;

void setup() {
    for (int i = 0; i < qtd; i++) { //Configura os pinos dos leds como saída.
        pinMode(led[i], OUTPUT);
    }
    LeEEPROM();
}

void loop() {
    delay(10);
    //VerificaBotaoControle();
    TimerAlteraEfeito();
    if (controle == 0) {
        //AUTOMÁTICO
        for (int j = 1; j <= qtdSequencia; j++) {
            for (int i = 0; i < 5; i++) {
                sequencia(j);
                if (controle != 0) break;
            }
            if (controle != 0) break;
        }
    }
    else {
        sequencia(controle);
    }
}

void VerificaBotaoControle() {
    //Botão controle ligado ao pino analógico 5. Com resistor de pull down 10k.
    //if (analogRead(5) > 800) {
    //    ApagaTodos();
    //    delay(1000);
    //    controle++;
    //    if (controle > qtdSequencia) {
    //        controle = 0;
    //    }
    //}
    //if (controle == 0) {
    //    digitalWrite(ledControle, HIGH);
    //}
    //else {
    //    digitalWrite(ledControle, LOW);
    //}
    //GravaEEPROM();
}

void TimerAlteraEfeito() {
    //Botão controle ligado ao pino analógico 5. Com resistor de pull down 10k.
    static long timer = tempoAutomatico;
    if (millis() > timer) {
        timer += tempoAutomatico;
        ApagaTodos();
        delay(100);
        controle++;
        if (controle > qtdSequencia) {
            controle = 0;
        }
    }
    GravaEEPROM();
}

void LeEEPROM() {
    controle = EEPROM.read(0);
}

void GravaEEPROM() {
    EEPROM.write(0, controle);
}

void AcendeTodos() {
    for (int i = 0; i < qtd; i++) {
        digitalWrite(led[i], HIGH);
    }
}

void ApagaTodos() {
    for (int i = 0; i < qtd; i++) {
        digitalWrite(led[i], LOW);
    }
}

void sequencia(int s) {
    switch (s) {
      case 1:
        s1();
        break;
      case 2:
        s2();
        break;
      case 3:
        s3();
        break;
      case 4:
        s4();
        break;
      case 5:
        s5();
        break;
      case 6:
        s6();
        break;
      case 7:
        s7();
        break;
      case 8:
        s8();
        break;
      case 9:
        s9();
        break;
      case 10:
        s10();
        break;
      case 11:
        s11();
        break;
    }
}

void s1() {
    //int t1 = getTempo();
    VerificaBotaoControle();
    ApagaTodos();
    //Acende um por um.
    for (int i = 0; i < qtd; i++) {
        digitalWrite(led[i], HIGH);
        delay(getTempo());
        VerificaBotaoControle();
    }
    //Apaga um por um.
    for (int i = 0; i < qtd; i++) {
        digitalWrite(led[i], LOW);
        delay(getTempo());
        VerificaBotaoControle();
    }
}

void s2() {
    VerificaBotaoControle();
    ApagaTodos();
    //Acende um por um.
    for (int i = 0; i < qtd; i++) {
        digitalWrite(led[i], HIGH);
        delay(getTempo());
        VerificaBotaoControle();
    }
    //Apaga um por um.
    for (int i = 0; i < qtd - 1; i++) {
        digitalWrite(led[i], LOW);
        delay(getTempo());
        VerificaBotaoControle();
    }
    //Acende um por um. (inverso)
    for (int i = qtd - 1; i >= 0; i--) {
        digitalWrite(led[i], HIGH);
        delay(getTempo());
        VerificaBotaoControle();
    }
    //Apaga um por um. (inverso)
    for (int i = qtd - 1; i > 0; i--) {
        digitalWrite(led[i], LOW);
        delay(getTempo());
        VerificaBotaoControle();
    }
}

void s3() {
    //ABRE E FECHA.
    //int t1 = getTempo();
    VerificaBotaoControle();
    ApagaTodos();
    for (int i = 0; i < qtd / 2; i++) {
        digitalWrite(led[i], HIGH);
        digitalWrite(led[qtd - 1 - i], HIGH);
        delay(getTempo());
        VerificaBotaoControle();
    }
    for (int i = 0; i < (qtd / 2) - 1; i++) {
        digitalWrite(led[i], LOW);
        digitalWrite(led[qtd - 1 - i], LOW);
        delay(getTempo());
        VerificaBotaoControle();
    }
    for (int i = (qtd / 2) - 2; i >= 0; i--) {
        digitalWrite(led[i], HIGH);
        digitalWrite(led[qtd - 1 - i], HIGH);
        delay(getTempo());
        VerificaBotaoControle();
    }
    for (int i = (qtd / 2) - 1; i > 0; i--) {
        digitalWrite(led[i], LOW);
        digitalWrite(led[qtd - 1 - i], LOW);
        delay(getTempo());
        VerificaBotaoControle();
    }
}

void s4() {
    //POLÍCIA 01
    int t1 = getTempo();
    VerificaBotaoControle();
    //Lado 1 acesso. (piscando)
    ApagaTodos();
    for (int j = 0; j < qtd / 2; j++) {
        for (int i = 0; i < qtd / 2; i++) {
            digitalWrite(led[i], HIGH);
        }
        delay(getTempo());
        for (int i = 0; i < qtd / 2; i++) {
            digitalWrite(led[i], LOW);
        }
        delay(getTempo());
        VerificaBotaoControle();
    }
    //Lado 2 acesso. (piscando)
    ApagaTodos();
    for (int j = 0; j < qtd / 2; j++) {
        for (int i = qtd / 2; i < qtd; i++) {
            digitalWrite(led[i], HIGH);
        }
        delay(getTempo());
        for (int i = qtd / 2; i < qtd; i++) {
            digitalWrite(led[i], LOW);
        }
        delay(getTempo());
        VerificaBotaoControle();
    }
}

void s5() {
    //POLÍCIA 02
    int t1 = 50;
    int t2 = 300;
    VerificaBotaoControle();
    for (int i = 0; i < qtd - 1; i++) {
        AcendeTodos();
        delay(getTempo());
        ApagaTodos();
        delay(getTempo());
        VerificaBotaoControle();
    }
    delay(getTempo()*6);
}

void s6() {
    //FLASHS UM POR UM
    int t1 = getTempo();
    int t2 = getTempo()*2;
    VerificaBotaoControle();
    ApagaTodos();
    for (int i = 0; i < qtd; i++) {
        digitalWrite(led[i], HIGH);
        delay(getTempo());
        digitalWrite(led[i], LOW);
        delay(getTempo() * 2);
        VerificaBotaoControle();
    }
}

void s7() {
    //FLASHS RANDOMICOS
    randomSeed(analogRead(0));  //Para o random ficar aleatorio, sem repetir a sequencia.
    int t1 = getTempo();
    int t2 = getTempo()*2;
    int p = random(qtd);
    VerificaBotaoControle();
    ApagaTodos();
    for (int i = 0; i < 15; i++) {
        digitalWrite(led[p], HIGH);
        delay(getTempo());
        digitalWrite(led[p], LOW);
        delay(getTempo() * 2);
        p = random(qtd);
        VerificaBotaoControle();
    }
}

void s8() {
    int t1 = getTempo();
    VerificaBotaoControle();
    for (int i = 0; i < 2; i++) {
        AcendeTodos();
        delay(getTempo());
        ApagaTodos();
        for (int x = 0; x < 100; x++) {
            VerificaBotaoControle();
            //delay(getTempo());
        }
    }
}

void s9() {
    //CORRE NUM EFEITO MEIO 3D. :P
    int t1 = getTempo();
    VerificaBotaoControle();
    ApagaTodos();
    for (int i = 1; i < qtd; i++) {
        digitalWrite(led[i - 2], LOW);
        digitalWrite(led[i - 1], LOW);
        digitalWrite(led[i], HIGH);
        delay(getTempo());
        digitalWrite(led[i], LOW);
        digitalWrite(led[i - 1], HIGH);
        delay(getTempo());
        VerificaBotaoControle();
    }
}

void s10() {
    int t1 = getTempo()*3;
    VerificaBotaoControle();
    ApagaTodos();
    for (int x = 0; x < 3; x++) {
        for (int i = 0; i < qtd; i++) {
            if (i % 2 == 0) {
                digitalWrite(led[i], HIGH);
            }
            else {
                digitalWrite(led[i], LOW);
            }
        }
        VerificaBotaoControle();
        delay(getTempo());
        for (int i = 0; i < qtd; i++) {
            if (i % 2 == 0) {
                digitalWrite(led[i], LOW);
            }
            else {
                digitalWrite(led[i], HIGH);
            }
        }
        VerificaBotaoControle();
        delay(getTempo());
    }
}

void s11() {
    int t1 = getTempo();
    int t2 = getTempo()*3;
    VerificaBotaoControle();
    ApagaTodos();
    delay(getTempo() * 3);
    for (int i = 0; i < qtd; i++) {
        if (i != 0) {
            digitalWrite(led[i - 1], LOW);
        }
        digitalWrite(led[i], HIGH);
        delay(getTempo());
        VerificaBotaoControle();
    }
    for (int i = 0; i < qtd - 1; i++) {
        if (i != 0) {
            digitalWrite(led[i - 1], LOW);
        }
        digitalWrite(led[i], HIGH);
        delay(getTempo());
        VerificaBotaoControle();
    }
    for (int i = 0; i < qtd - 2; i++) {
        if (i != 0) {
            digitalWrite(led[i - 1], LOW);
        }
        digitalWrite(led[i], HIGH);
        delay(getTempo());
        VerificaBotaoControle();
    }
    for (int i = 0; i < qtd - 3; i++) {
        if (i != 0) {
            digitalWrite(led[i - 1], LOW);
        }
        digitalWrite(led[i], HIGH);
        delay(getTempo());
        VerificaBotaoControle();
    }
    for (int i = 0; i < qtd - 4; i++) {
        if (i != 0) {
            digitalWrite(led[i - 1], LOW);
        }
        digitalWrite(led[i], HIGH);
        delay(getTempo());
        VerificaBotaoControle();
    }
    for (int i = 0; i < qtd - 5; i++) {
        if (i != 0) {
            digitalWrite(led[i - 1], LOW);
        }
        digitalWrite(led[i], HIGH);
        delay(getTempo());
        VerificaBotaoControle();
    }
    for (int i = 0; i < qtd - 6; i++) {
        if (i != 0) {
            digitalWrite(led[i - 1], LOW);
        }
        digitalWrite(led[i], HIGH);
        delay(getTempo());
        VerificaBotaoControle();
    }
    for (int i = 0; i < qtd - 7; i++) {
        if (i != 0) {
            digitalWrite(led[i - 1], LOW);
        }
        digitalWrite(led[i], HIGH);
        delay(getTempo());
        VerificaBotaoControle();
    }
    for (int i = 0; i < qtd - 8; i++) {
        if (i != 0) {
            digitalWrite(led[i - 1], LOW);
        }
        digitalWrite(led[i], HIGH);
        delay(getTempo());
        VerificaBotaoControle();
    }
    delay(getTempo());
    VerificaBotaoControle();
    digitalWrite(led[0], HIGH);
    delay(getTempo());
    for (int i = 0; i < qtd; i++) {
        if (i != 0) {
            digitalWrite(led[i - 1], HIGH);
        }
        digitalWrite(led[i], LOW);
        delay(getTempo());
        VerificaBotaoControle();
    }
    for (int i = 0; i < qtd - 1; i++) {
        if (i != 0) {
            digitalWrite(led[i - 1], HIGH);
        }
        digitalWrite(led[i], LOW);
        delay(getTempo());
        VerificaBotaoControle();
    }
    for (int i = 0; i < qtd - 2; i++) {
        if (i != 0) {
            digitalWrite(led[i - 1], HIGH);
        }
        digitalWrite(led[i], LOW);
        delay(getTempo());
        VerificaBotaoControle();
    }
    for (int i = 0; i < qtd - 3; i++) {
        if (i != 0) {
            digitalWrite(led[i - 1], HIGH);
        }
        digitalWrite(led[i], LOW);
        delay(getTempo());
        VerificaBotaoControle();
    }
    for (int i = 0; i < qtd - 4; i++) {
        if (i != 0) {
            digitalWrite(led[i - 1], HIGH);
        }
        digitalWrite(led[i], LOW);
        delay(getTempo());
        VerificaBotaoControle();
    }
    for (int i = 0; i < qtd - 5; i++) {
        if (i != 0) {
            digitalWrite(led[i - 1], HIGH);
        }
        digitalWrite(led[i], LOW);
        delay(getTempo());
        VerificaBotaoControle();
    }
    for (int i = 0; i < qtd - 6; i++) {
        if (i != 0) {
            digitalWrite(led[i - 1], HIGH);
        }
        digitalWrite(led[i], LOW);
        delay(getTempo());
        VerificaBotaoControle();
    }
    for (int i = 0; i < qtd - 7; i++) {
        if (i != 0) {
            digitalWrite(led[i - 1], HIGH);
        }
        digitalWrite(led[i], LOW);
        delay(getTempo());
        VerificaBotaoControle();
    }
    for (int i = 0; i < qtd - 8; i++) {
        if (i != 0) {
            digitalWrite(led[i - 1], HIGH);
        }
        digitalWrite(led[i], LOW);
        delay(getTempo());
        VerificaBotaoControle();
    }
    delay(getTempo());
    VerificaBotaoControle();
    digitalWrite(led[0], LOW);
    delay(getTempo());
}
