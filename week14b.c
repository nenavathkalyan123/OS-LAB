#include<stdio.h>
void main()
{
int i,j,l,max,n,a[50],frame[10],flag,fno,k,avail,pagefault=0,lru[10];
printf("\nEnter the number of Frames:");
scanf("%d",&fno);
printf("\nEnter no.of reference string:");
scanf("%d",&n);
printf("\nEnter the Reference string :\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<fno;i++)
{
frame[i]=-1;
lru[i]=0;
}
printf("\nlru Page replacement Algorithm\n\nthe given reference string is:\n\n");
for(i=0;i<n;i++)
{
printf("%d",a[i]);
}
printf("\n");
j=0;
for(i=0;i<n;i++)
{
max=0;
flag=0;
printf("\nrefernece no %d->",a[i]);
avail=0;
for(k=0;k<fno;k++)
if(frame[k]==a[i])
{
avail=1;
lru[k]=0;
break;
}
if(avail==1)
{
for(k=0;k<fno;k++)
if(frame[k]!=-1)
++lru[k];
max=0;
for(k=1;k<fno;k++)
if(lru[k]>lru[max])
max=k;
j=max;
}
if(avail==0)
{
lru[j]=0;
frame[j]=a[i];
for(k=0;k<fno;k++)
{
if(frame[k]!=-1)
++lru[k];
else
{
j=k;
flag=1;
break;
}
}
if(flag==0){
max=0;
for(k=1;k<fno;k++)
if(lru[k]>lru[max])
max=k;
j=max;
}
pagefault++;
for(k=0;k<fno;k++)
if(frame[k]!=-1)
printf("%2d",frame[k]);
}
printf("\n");
}
printf("\npage fault is %d",pagefault);
