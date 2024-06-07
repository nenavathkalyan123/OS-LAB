#include<stdio.h>
int main(){
int i,j,l,min,flag1,n,a[50],temp,frame[10],flag,fno,k,avail,pagefault=0,opt[10];
printf("\nenter no.of frames:");
scanf("%d",&fno);
printf("\nenter no.of reference  string:");
scanf("%d",&n);
printf("\nenter the reference string:\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<fno;i++){
frame[i]=-1;
opt[i]=0;
}
printf("\noptimal page replacement algorithm\n\nthe given reference string is:\n\n");
for(i=0;i<n;i++)
printf("%d",a[i]);
printf("\n");
j=0;
for(i=0;i<n;i++){
flag=0;
flag1=0;
printf("\nreference no %d->",a[i]);
avail=0;
for(k=0;k<fno;k++)
if(frame[k]==a[i]){
avail=1;
break;
}
if(avail==0){
temp=frame[j];
frame[j]=a[i];
for(k=0;k<fno;k++){
if(frame[k]==-1){
j=k;
flag=1;
break;
}
}
if(flag==0){
for(k=0;k<fno;k++){
opt[k]=0;
for(l=1;l<n;l++){
if(frame[k]==a[l]){
flag1=1;
break;
}
}
if(flag1=1)
opt[k]=l-i;
else{
opt[k]=-1;
break;
}
}
min=0;
for(k=0;k<fno;k++)
if(opt[k]<opt[min]&&opt[k]!=-1)
min=k;
else if(opt[k]==-1){
min=k;
frame[j]=temp;
frame[k]=a[i];
break;
}
j=min;
}
pagefault++;
for(k=0;k<fno;k++)
if(frame[k]!=-1)
printf("%2d",frame[k]);
}
printf("\n");
}
printf("\npage fault is %d",pagefault);
return 0;
}

