#include "types.h"
#include "stat.h"
#include "user.h"

void rrtest(void)
{
    int pid;
    int N = 10;
    long long int wTime, rTime;

    for (int n = 0; n < N; n++)
    {
        pid = fork();
        if (pid < 0)
        {
            return;
        }
        if (pid == 0)
        {
            int i;
            for (i = 0; i < 20; i++)
            {
                printf(1, "[%d running]\n", getpid());
            }
            break;
        }
    }
    for (int i = 0; i < N; i++)
    {
        wait();
    }

    getPerformanceData(&wTime, &rTime);
    printf(1, "\n[FINISHED pid: %d | ", getpid());
    printf(1, "wTime: %d | ", wTime);
    printf(1, "rTime: %d] \n\n", rTime);

}

int main(void)
{
    rrtest();
    exit();
}