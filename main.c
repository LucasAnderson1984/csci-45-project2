#include <stdio.h>
#include <errno.h>
#include <wiringPi.h>
#define RelayPin1 17
#define RelayPin2 27
#define DOpin 22

int main(void) {

  if(wiringPiSetupGpio() < 0) {
    fprintf(stderr, "Unable to setup wiringPi:%s\n",strerror(errno));
    return 1;
  }

  pinMode(DOpin, INPUT);
  pinMode(RelayPin1, OUTPUT);
  pinMode(RelayPin2, OUTPUT);
  digitalWrite(RelayPin1, LOW);
  digitalWrite(RelayPin2, HIGH);

  while(1) {
    if(digitalRead(DOpin)) {
      digitalWrite(RelayPin1, HIGH);
      delay (10000);
    }
    else {
      digitalWrite(RelayPin1, LOW);
      delay (500);
    }
  }

  return 0;
}
