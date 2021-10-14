/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
// Nia Anderson
// 02939348

int alarmIsOn = 0;
int numAlarm = 0;

time_t start, stop;

void handlesAlarm(int signum)
{ //signal handler
  printf("Hello World!\n");
  sleep(2);
  alarmIsOn = 1;
  numAlarm++;

}

void handleSigint(int signum){
  int timeTotal;
  stop = time(NULL);
  timeTotal = stop - start;
  
  printf("The number of alarms is %d\n", timeTotal);
}

int main(int argc, char * argv[])
{
  signal(SIGALRM, handlesAlarm); //register handler to handle SIGALRM
  signal(SIGINT, handleSigint);
  start = time(NULL);
  while(1){
    alarmIsOn = 0;
    alarm(2);
    
    while(!alarmIsOn);
      printf("Turing was right!\n");
    
    
  }
  return 0;
}