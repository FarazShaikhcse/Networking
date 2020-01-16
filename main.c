#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int data[50],r,code[50];
int calc(int k,int r)
{
    int n=1,i,ones;
    int j=1,errsum=0;
    while(n<pow(2,r))
    {

        i=n;
        ones=0;
        while(i<=(k+r))
        {
            for(j=0;j<n;j++)
            {
                if(code[i+j]==1)
                    ones++;
            }
            i=i+2*n;

        }
        if(ones%2!=0)
        {
            code[n]=1;
            errsum+=n;
        }
        else
        {
            code[n]=0;
        }
        n=n*2;
    }
    return errsum;
}
void hamcode(int k)
{

    int i,j,d=0;
    r=1;
    while(k>pow(2,r)-r-1)
        r++;
    j=k;
    for(i=1;i<=(k+r);i++)
    {
        if(i==pow(2,d))
        {
            code[i]=0;
            d++;

        }
        else
          code[i]=data[j--];


    }
    printf("\nNo of parity bits r=%d",r);
    calc(k,r);

}

    int main()
{
    int k,i,p,flag=0,errpos=0;
    printf("Enter the no of databits\n");
    scanf("%d",&k);
    printf("Enter the data:\n");
    for(i=1;i<=k;i++)
       scanf("%d",&data[i]);
    hamcode(k);
    printf("\nThe hamming code for data is\n");
    for(i=1;i<=(k+r);i++)
        printf("%d",code[i]);
        printf("\nEnter the received data:\n");
        for(i=1;i<=k+r;i++)
            scanf("%d",&code[i]);
    errpos=calc(k,r);
    if(errpos!=0)
    {
        for(i=1;i<pow(2,r);i=i*2)
        {
            if(errpos==i)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            printf("Parity bit P%d is corrupted,data is fine",errpos);
        else
        {
            printf("Data bit is corrupted, pos=D%d",errpos);
            code[errpos]=!(code[errpos]);
            printf("\nCorrected data with parity bits\n");
            for(i=1;i<=(k+r);i++)
                printf("%d",code[i]);
        }
    }
    else
        printf("No error");
    return 0;
}
