#include "types.h"
#include "stat.h"
#include "user.h"

int main(){
    int pid;
    printf(1,"Father pid is %d" ,getpid());
    //Wait 10 Seconds
    sleep(100);
    printf(1,"Father is awake");
    pid = fork();
    exit();
	return 0;
}