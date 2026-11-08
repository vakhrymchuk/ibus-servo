#include <Arduino.h>
#include <Servo.h>

#include <iBus.h>

#define MAX_CHANNELS 10

iBus receiver(Serial, MAX_CHANNELS);  // Serial on ATMega328 boards(Uno, Nano, etc.)
                                     // Serial1 on ATMega32u4 boards(Micro, Leonardo)

Servo s3,s4,s5,s6,s7,s8,s9,s10;

void setup() {
  receiver.begin();
  pinMode(LED_BUILTIN, OUTPUT);
  s3.attach(3);
  s4.attach(4);
  s5.attach(5);
  s6.attach(6);
  s7.attach(7);
  s8.attach(8);
  s9.attach(9);
  s10.attach(10);
  s3.write(90);
  s4.write(90);
  s5.write(90);
  s6.write(90);
  s7.write(90);
  s8.write(90);
  s9.write(90);
  s10.write(90);
}

int map180(int x) {
  return map(x, 0, 100, 0, 180);
}

void loop() {

  receiver.process();

  digitalWrite(LED_BUILTIN, receiver.available());

  s3.write(map180(receiver.get(3)));
  s4.write(map180(receiver.get(4)));
  s5.write(map180(receiver.get(5)));
  s6.write(map180(receiver.get(6)));
  s7.write(map180(receiver.get(7)));
  s8.write(map180(receiver.get(8)));
  s9.write(map180(receiver.get(9)));
  s10.write(map180(receiver.get(10)));

  delay(10);
}
