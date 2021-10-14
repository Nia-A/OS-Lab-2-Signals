/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
// Nia Anderson
// 02939348

int alarmIsOn = 0;

void handlesAlarm(int signum)
{ //signal handler
  printf("Hello World!\n");
  sleep(2);
  
  alarmIsOn = 1;

}


int main(int argc, char * argv[])
{
  signal(SIGALRM, handlesAlarm); //register handler to handle SIGALRM
  alarm(2);
  while(1){
    alarmIsOn = 0;
    alarm(2);
    
    while(!alarmIsOn);
      printf("Turing was right!\n");
    
  }
  return 0;
}