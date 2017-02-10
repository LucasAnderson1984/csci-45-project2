#include <stdio.h>
#include <errno.h>
#include <wiringPi.h>
#include <math.h>
#define RelayPin1 17
#define RelayPin2 27
#define DOpin 22

int main(void) {

  if(wiringPiSetupGpio() < 0) {
    fprintf(stderr, "Unable to setup wiringPi:%s\n",strerror(errno));
    return 1;
  }

  pinMode(RelayPin1, OUTPUT);
  pinMode(RelayPin2, OUTPUT);
  digitalWrite(RelayPin2, HIGH);

  while(1) {
    if(digitalRead(DOpin)) {
      digitalWrite(RelayPin1, HIGH);
      delay (2000);
    }
    else {
      delay (1000);
    }
  }

  return 0;
}
