#include "types.h"
#include "stat.h"
#include "user.h"

int main(){
    int pid;
    printf(1,"Father pid is %d\n" ,getpid());
    //Wait 10 Seconds
    sleep(100);
    printf(1,"Father is awake\n");
    pid = fork();
    //Father
    if(pid  != 0 ){
        for(int i=0; i<50; i++){
            printf(1,"Process %d is printing for the %d time\n" , getpid() , i);

        }
        printf(1,"Finished Parent Work\n");
        wait();
    }
    //Child 
    else if(pid  == 0 ){
        for(int i=0; i<50; i++){
            printf(1,"Process %d is printing for the %d time\n" , getpid() , i);

        }
        printf(1,"Finished Child Work\n");
        exit();
    }

    exit();
	return 0;
}