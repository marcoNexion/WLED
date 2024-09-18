#include "wled.h"
//Use userVar0 and userVar1 (API calls &U0=,&U1=, uint16_t)

unsigned long lastTime = 0;
int delayMs = 10;
const int pinA = 5;
const int pinB = 0;
int oldA = LOW, oldB = LOW;

//gets called once at boot. Do all initialization that doesn't depend on network here
void userSetup() {
  pinMode(pinA, INPUT_PULLUP);
  pinMode(pinB, INPUT_PULLUP);
  oldA = digitalRead(pinA);
  oldB = digitalRead(pinB);
}

//gets called every time WiFi is (re-)connected. Initialize own network interfaces here
void userConnected() {
}

//loop. You can use "if (WLED_CONNECTED)" to check for successful connection
void userLoop() {
  if (millis()- lastTime > delayMs) {
    int A = digitalRead(pinA);
    int B = digitalRead(pinB);

    if (A == LOW && B == HIGH) {
      applyPreset(1);
    }
    else if (A == HIGH && B == LOW) {
      applyPreset(2);
    }
    else{
      applyPreset(3);
    }

    lastTime = millis();
  }
}
