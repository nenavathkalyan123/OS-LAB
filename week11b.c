#include<stdio.h>
#include<math.h>
void main()
{
int pid[10],bt[10],bt1[10],wt[10],tat[10],tot=0,n,twt=0,ttat=0,i,j=0,ts;
float awt,atat;
printf("enter no.of processes");
scanf("%d",&n);
printf("enter the time slice");
scanf("%d",&ts);
printf("enter the burst times");
for(i=1;i<=n;i++)
{
scanf("%d",&bt1[i]);
bt[i]=bt1[i];
}
while(j<n)
{
for(i=1;i<=n;i++)
{
if(bt[i]>0)
{
if(bt[i]>=ts)
{
tot+=ts;
bt[i]=bt[i]-ts;
if(bt[i]==0)
{
j++;
tat[i]=tot;
}
}
else
{
tot+=bt[i];
bt[i]=0;
j++;
tat[i]=tot;
}
}
}
}
for(i=1;i<=n;i++)
{
wt[i]=tat[i]-bt1[i];
twt=twt+wt[i];
ttat=ttat+tat[i];
}
awt=(float)twt/n;
atat=(float)ttat/n;
printf("\n PID \t BT \t WT \t TAT");
for(i=1;i<=n;i++){
printf("\n %d \t %d \t %d \t %d",i,bt1[i],wt[i],tat[i]);
}
printf("\n Avg waiting time=%f",awt);
printf("\n Avg turn around time=%f",atat);
}


