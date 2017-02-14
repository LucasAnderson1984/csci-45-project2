#include <stdio.h>
#include <errno.h>
#include <wiringPi.h>
#include <time.h>
#define DOpin 22
#define RelayPin1 17
#define RelayPin2 27
#define TouchPin 18

int main(void) {

  if(wiringPiSetupGpio() < 0) {
    fprintf(stderr, "Unable to setup wiringPi:%s\n",strerror(errno));
    return 1;
  }

  int temp = 0;

  pinMode(DOpin, INPUT);
  pinMode(TouchPin, INPUT);
  pinMode(RelayPin1, OUTPUT);
  digitalWrite(RelayPin1, LOW);

  while(1) {
    if(digitalRead(DOpin)) {
      digitalWrite(RelayPin1, HIGH);
      delay (10000);
    }
    else if (digitalRead(TouchPin) != temp) {
      digitalWrite(RelayPin1, HIGH);
      temp = digitalRead(TouchPin);
      delay(10000);
    }
    else {
      digitalWrite(RelayPin1, LOW);
      delay (500);
    }
  }

  return 0;
}
