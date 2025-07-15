#include "SumoIR.h"

SumoIR IR;
void setup() {
    Serial.begin(115200);
  
    IR.begin(15); // sensor conectado no pino 15
    IR.setLed(2,HIGH,180); // led no pino 2, acende quando esta HIGH e irá piscar com intervalo de 180ms
    //^ comente se não houver LED
  
    // IR.debug(false); // <- descomente se não quiser debug na serial
}

void loop() {
    IR.update();

    if (IR.prepare()) { /* robô em preparação */
      Serial.println("-> sumo prepare");
      delay(400);
    } else if (IR.start()) { /* movimento inicial*/
      // executa apenas na primeira transição para esse estado
      Serial.println("-> sumo start");
    } else if (IR.on()) { /* código do robô ligado */
      Serial.println("-> sumo on");
      delay(400);
    } else if (IR.stop()) { /* código que desliga o robô */
      // executa apenas na primeira transição para esse estado
      Serial.println("-> sumo stop");
    } else { /* código do robô desligado */
      Serial.println("-> sumo off");
      delay(400);
    }
}
