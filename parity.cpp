#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
int data[8];
int i=0,c=0;
printf("Kulvir Singh - 19BCE2074\n");
printf("Enter the 7 bits\n");
for(i=0;i<7;i++)
scanf("%d",&data[i]);
for(i=0;i<7;i++)
{
if(data[i]==1)
c=c+1;
}
for(i=0;i<7;i++)
printf("%d",data[i]);
if(c%2==0)
{
printf("\nEven parity\n");
data[7]=0;
}
else
{
printf("\nOdd parity\n");
data[7]=1;
}
printf("original data:");
for(i=0;i<7;i++)
printf("%d",data[i]);
srand(time(0));
int r=0,j=0;
for(j=0;j<5;j++)
r=rand()%((8-0)+1);
printf("\nBit changed randomly at position:%d\n",r+1);
if(data[r]==1)
data[r]=0;
else
data[r]=1;
printf("\nData after adding the parity bits:");
for(i=0;i<8;i++)
printf("%d",data[i]);
int cn=0;
for(i=0;i<8;i++)
{
if(data[i]==1)
cn=cn+1;
}
if(cn%2==0)
printf("\nno error");
else
printf("\nerror");
return 0;
}
