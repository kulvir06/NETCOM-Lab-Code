#include<stdio.h>
#include<math.h>
int main()
{
    printf("GO BACK N ARQ \n");
    int noframes,windowsize,sent=0,ack,m,i,j=0;
    printf("Enter number of frames: ");
    scanf("%d",&noframes);
    printf("Enter m: ");
    scanf("%d",&m);
    //Window Size
    windowsize=(int)pow(2,m)-1;

    int seq_no[noframes];
    //Sequence Number allocation
    for(i=0;i<noframes;i++)
    {
        seq_no[i]=i%(int)pow(2,m);
    }
    while(1)
    {
        for( i = 0; i < windowsize; i++)
        {
            printf("Sending Frame: %d Seq. Number: %d\n",sent,seq_no[sent]);
            sent++;
            if(sent==noframes)
                break;
        }

        printf("\nEnter last ack received: ");
        scanf("%d",&ack);

        if(ack != windowsize)
            sent = ack;
        if(ack==noframes)
            break;
    }
    printf("Sent all frames\n");
    return 0;
}
