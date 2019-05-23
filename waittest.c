// Test that fork fails gracefully.
// Tiny executable so that the limit can be filling the proc table.

#include "types.h"
#include "stat.h"
#include "user.h"

#define N  1000
/*
void
printf(int fd, char *s, ...)
{
  write(fd, s, strlen(s));
}
*/

void
foo()
{
  int i;
  for (i=0;i<290;i++)
     printf(2, "wait test %d\n",i);
  sleep(20);
  for (i=0;i<290;i++)
     printf(2, "wait test %d\n",i);

}

void
waittest(void)
{
  int wTime;
  int rTime;
  int pid;
  printf(1, "wait test\n");


    pid = fork();
    if(pid == 0)
    {
      foo();
      getPerformanceData(&wTime,&rTime);
      printf(1, "wTime: %d rTime: %d \n",wTime,rTime);
      exit();
    }
    wait();

}
int
main(void)
{
  waittest();
  exit();
}