//the size of the sender and receiver window must be at most one-half of 2^m 
//eg window size = 8
//8 = (2^m)/2 therefore m = 4 
#include<stdio.h>
#include<math.h>
int main()
{
printf("\nKulvir Singh\n19BCE2074\n");
printf("==========SELECTIVE REPEAT ARQ ==========\n");
int noframes,windowsize,sent=0,nak,m,i,j=0;
printf("Enter number of frames: ");
scanf("%d",&noframes);
printf("Enter m: ");
scanf("%d",&m);
windowsize=(int)pow(2,m-1);
printf("Window Size: %d\n",windowsize);
int seq_no[noframes];
for(i=0;i<noframes;i++)
{
seq_no[i]=i%(int)pow(2,m);
}
int ch;
while(1)
{
for( i = 0; i < windowsize; i++)
{
printf("Sending Frame: %d Sequence Number:%d\n",sent,seq_no[sent]);
sent++;
if(sent==noframes)
break;
}
ch=1;
while(ch==1)
{
printf("Error occured? 1/0: ");
scanf("%d",&ch);
if (ch==0)
break;
printf("Enter nak received: ");
scanf("%d",&nak);
printf("Sending Frame: %d Sequence Number: %d\n",nak,seq_no[nak]);
}
if(sent==noframes)
break;
}
printf("Frames sent\n");
return 0;
}
