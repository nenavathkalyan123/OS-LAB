#include<stdio.h>
void main()
{
int i,j,n,a[50],frame[10],fno,k,avail,pagefault=0;
printf("\nenter the number of frames");
scanf("%d",&fno);
printf("\nenter number of reference strings");
scanf("%d",&n);
printf("\nenter reference string");
for(i=0;i<n;i++){
scanf("%d",&a[i]);
}
for(i=0;i<fno;i++)
frame[i]=-1;
j=0;
printf("\n fifo page replacement algorithm \n\n the given reference string is:");
for(i=0;i<n;i++){
printf("%d",a[i]);
}
printf("\n");
for(i=0;i<n;i++){
printf("\n reference no%d ->",a[i]);
avail=0;
for(k=0;k<fno;k++)
if(frame[k]==a[i])
avail=1;
if(avail==0){
frame[j]=a[i];
j=(j+1)%fno;
pagefault++;
for(k=0;k<fno;k++)
if(frame[k]!=-1)
printf("%2d",frame[k]);
}
printf("\n");
}
printf("\npage fault is %d",pagefault);
