#include <wiringSerial.h>
#include <wiringPi.h>
#include <iostream>


int main(){
  int data;
  int connection = serialOpen("/dev/serial0",9600);
  while (serialDataAvail(connection) > -1) {
    data = serialGetchar(connection);
    printf("%d",data);
    // fflush(stdout);
  }
  printf("%d",serialDataAvail(connection));
}