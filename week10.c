#include<stdio.h>
#include<unistd.h>
int main()
{
int pid[10],bt[10],wt[10],tat[10],n,twt=0,ttat=0;
float awt,atat;
printf("Enter no.of processes:");
scanf("%d",&n);
printf("\n Enter burst time");
for(int i=0;i<n;i++)
scanf("%d",&bt[i]);
wt[0]=0;
tat[0]=bt[0];         
for(int i=1;i<n;i++)
{
wt[i]=tat[i-1];
tat[i]=bt[i]+wt[i];
}
for(int i=0;i<n;i++)
{                
ttat=ttat+tat[i];
twt=twt+wt[i];
}
printf("\n PID \t BT \t wt \t tat");     
for(int i=0;i<n;i++)
printf("\n %d \t %d \t %d \t %d",i+1,bt[i],wt[i],tat[i]);
awt=(float)twt/n;
atat=(float)ttat/n;
printf("\n avg waiting time=%f",awt);
printf("\n avg turn around time=%f",atat);
}
