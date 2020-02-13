//#include"stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#define BUCKETSIZE 250
#define OUTRATE 25
struct{
int arrtime;
int weight;
}packet[15];
void read_packets(int n)
{
int i;
for(i=0;i<n;i++)
{
printf("Enter arrival time :");
scanf("%d",&packet[i].arrtime);
printf("Enter the packet size:");
scanf("%d",&packet[i].weight);
}
} // leaky bucket algorithm
void lky_bucket()
{
int excess=BUCKETSIZE;
int i,j=0,rem=0; // receive packets for 20 cosec
for(i=0;i<=30;i++)
{
if(packet[j].arrtime==i)
{

if(packet[j].weight<=excess)
{
rem=packet[j].weight+rem;
excess=excess-packet[j].weight;
 printf("At time=%d: packet %d inserted into bucket\n",i,j+1);
 printf("remaining bucket size= %d\n",excess);
 j=j+1;
 }

else
{

printf("At time = %d packet %d discarded\n",i,j+1);
printf("Packet size is more than buffer size\n");
j=j+1;
}
}
if ((i%5)==0)
{
if(rem>=OUTRATE)
{
rem=rem-OUTRATE;
excess=excess+OUTRATE;
 printf("AT time = %d : 25 Kbytes are transfered\n ",i);
 printf("Free available space in the bucket=%d\n",excess);
 }
else if(rem>0) {
excess=excess+rem;
printf("At time = %d : %d Kbytes are transferred \n",i,rem);
printf("Free available space in the bucket%d\n",excess);
rem=0;
}
}
}
while(rem !=0) {
if(rem < OUTRATE) {
excess=excess+rem;
printf("At time =%d : %dKbytes are transfered \n",i++,rem);
printf("Free available space in the bucket=%d\n",excess);
break;
}
rem=rem-OUTRATE;
excess=excess + OUTRATE;
printf("At time = %d: %d Kbytes are transfered\n",i++,OUTRATE);
printf("Free available space in the bucket=%d\n",excess);
}
printf("Bucket is empty");
}
int main()
{
int n;
printf("Enter the number of packets:");
scanf("%d",&n);
read_packets(n);
lky_bucket();
return 0;
}

