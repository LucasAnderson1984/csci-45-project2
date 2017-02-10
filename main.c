#include <stdio.h>
#include <errno.h>
#include <wiringPi.h>
#include <pcf8591.h>
#include <math.h>
#define RelayPin 0
#define PCF 120
#define DOpin 0

int main(void) {

  if(wiringPiSetupGpio() < 0) {
    fprintf(stderr, "Unable to setup wiringPi:%s\n",strerror(errno));
    return 1;
  }

  pinMode(RelayPin, OUTPUT);
  pcf8591Setup(PCF, 0x48);

  while(1) {
    analogVal = analogRead(PCF + 0);
    printf("Value: %d\n", analogVal);
    delay (200);
    digitalWrite(RelayPin, LOW);
    delay(1000);
    digitalWrite(RelayPin, HIGH);
    delay(1000);
  }

  return 0;
}
