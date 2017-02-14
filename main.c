#include <stdio.h>
#include <errno.h>
#include <wiringPi.h>
#include <time.h>
#define DOpin 19
#define RelayPin1 17
#define TouchPin 26

int main(void) {

  if(wiringPiSetupGpio() < 0) {
    fprintf(stderr, "Unable to setup wiringPi:%s\n",strerror(errno));
    return 1;
  }

  int temp = 0;
  time_t rawtime;
  struct tm *info;
  char buffer[10];
  char nightcheck[4] = {6, ' ', 'P', 'M'};
  char morningcheck[4] = {6, ' ', 'A', 'M'};
  pinMode(DOpin, INPUT);
  pinMode(TouchPin, INPUT);
  pinMode(RelayPin1, OUTPUT);
  digitalWrite(RelayPin1, LOW);

  while(1) {
    time( &rawtime );
    info = localtime( &rawtime );

    strftime (buffer, 10, "%I %p", info);
    if(((buffer == nightcheck) {
      digitalWrite(RelayPin1, LOW);
      while(buffer != morningcheck) {
        time( &rawtime );
        info = localtime( &rawtime );
        strftime (buffer, 10, "%I %p", info);
      }
    }

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
