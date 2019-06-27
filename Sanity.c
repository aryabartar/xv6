#include "types.h"
#include "stat.h"
#include "user.h"
#define CHILD_NUMBER 30
#define PRINT_NUMBER 100

void do_print(int n){
      for (int j = 0; j < PRINT_NUMBER; j++){
            printf(0," [%d] ", n);
      }
      printf(0,"\n {%d} \n",getpid());
}

void make_nice(){
    if (getpid() % 3 == 0)  {nice();}
    else if( getpid() % 3 == 1)
         {
            nice();
            nice();
         }
}

int cal_div(int x , int y){return x/y;}

void print_detail_of_child(int info[CHILD_NUMBER][4]){
   for (int h = 0; h < CHILD_NUMBER; h++)
   {
      printf(0, "<cid = %d> | wtime: %d | rtime: %d | turnaroundtime: %d \n", info[h][2], info[h][0], info[h][1], info[h][3]);
   }
}

void print_answer(int ht , int hw , int mt , int mw , int lt , int lw){
   printf(0, "\n\nHigh_PriorityAverage_TurnAroundTime : %d   \nHigh_Priority_WaitingTime : %d \n\n", ht, hw);
   printf(0, "\n\nMid_PriorityAverage_TurnAroundTime : %d   \nMid_Priority_WaitingTime : %d \n\n",mt,mw);
   printf(0, "\n\nLow_PriorityAverage_TurnAroundTime : %d   \nLow_Priority_WaitingTime : %d \n\n", lt,lw);
}

void Sanity_test(){
 for (int i = 0; i < CHILD_NUMBER; i++)
   {
      int pid = fork();
      if (pid == 0)
      {
         make_nice();
         do_print(i);
         exit();
      }
   }

   int info[CHILD_NUMBER][4];
   for (int k = 0; k < CHILD_NUMBER; k++){
      int wTime = 0;
      int rTime = 0;
      int child_pid = wait2(&wTime, &rTime);
      int turnAroundTime = wTime + rTime;
      info[k][0] = wTime;
      info[k][1] = rTime;
      info[k][2] = child_pid;
      info[k][3] = turnAroundTime;
   }

   print_detail_of_child(info);
   
   int tt = 0;
   int tw = 0;
   for (int i = 0; i < CHILD_NUMBER; i++)
   {
      tt = tt  + (info[i][3] / CHILD_NUMBER);
      tw = tw  + (info[i][0] / CHILD_NUMBER);
   }
   printf(0, "\n\nTotalAverageTurnAroundTime : %d   \nTotalAverageWaitingTime : %d \n\n", tt , tw);

   int NHIGH = 0;
   int NMID = 0;
   int NLOW = 0;
   int ht = 0;
   int mt = 0;
   int lt = 0;
   int hw = 0;
   int mw = 0;
   int lw = 0;

   for (int i = 0; i < CHILD_NUMBER; i++){

      if (info[i][2] % 3 == 0){
         mt = mt + info[i][3];
         mw = mw + info[i][0];
         NMID++;
      }
      else if (info[i][2] % 3 == 1){
         lt = lt + info[i][3];
         lw = lw + info[i][0];
         NLOW++;
      }
      else{
         ht = ht + info[i][3];
         hw = hw + info[i][0];
         NHIGH++;
      }
   }

   ht = cal_div(ht,NHIGH);
   hw = cal_div(hw,NHIGH);
   mt = cal_div(mt,NMID);
   mw = cal_div(mw,NMID);
   lt = cal_div(lt,NLOW);
   lw = cal_div(lw,NLOW);

   print_answer(ht,hw,mt,mw,lt,lw);
}

int main(void)
{
   Sanity_test();
   exit();
}
