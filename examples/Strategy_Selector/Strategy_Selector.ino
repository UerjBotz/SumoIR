#include "SumoIR.h"

int strategy = 0; // estratégia

SumoIR IR;
void setup() {
    Serial.begin(115200);
  
    IR.begin(15); // sensor conectado no pino 15
    IR.setLed(2,HIGH,180); // led no pino 2, acende quando sensor está HIGH e pisca com intervalo de 180ms
    //^ comente se não houver LED
  
    // IR.debug(false); // <- descomente se não quiser debug na serial
}

void loop() {
    IR.update();

    if (IR.available()) { /* quando o sensor tiver ativado */
        // salva o número lido pelo sensor, estando ou não de 1 a 3
        int cmd = IR.read();
      
        // substitui a estatégia atual por esse número
        if (cmd >= 4 && cmd <= 9) strategy = cmd;
    }

    if (IR.on()) { /* código do robô ligado */
        Serial.println("running strategy " + String(strategy));
      
        switch (strategy) {
          default:
          case 4: /* estratégia 4 */ break;
          case 5: /* estratégia 5 */ break;
          case 6: /* estratégia 6 */ break;

          // ... outras estratégias
        }
    } else {
        /* codigo do robô desligado */
    }
}
