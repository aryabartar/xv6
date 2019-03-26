#include "types.h"
#include "user.h"

int main(void) {

  int pid = fork();


  if(pid > 0){
  printf(1, "Parent says: (child pid is=%d) \n", pid);
  pid = wait();
  printf(1, "Parent says: (child %d is done)\n", pid);
  } else if(pid == 0){
  printf(1, "Child says: (exiting)\n");
  printf(1, "Child says: (My parent pid is: %d)", getppid());
  exit();
  } else {
  printf(1, "Fork error\n");
  }
}
