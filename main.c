#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define MAX 100
unsigned int min(unsigned int a ,unsigned int b)
{

    return(a<b?a:b);

}
unsigned int max(unsigned int a,unsigned int b)
{

    return(a>b?a:b);

}
unsigned int gcd (unsigned int a,unsigned int b)
{
    if(a==b)
    return a;
    else
        return(gcd(min(a,b),max(a,b)-min(a,b)));
}
unsigned int xpowy_modn(unsigned int x,unsigned int y,unsigned int n)
{
    unsigned int r=1;
    while(y>0)
    {
        if((int)(y%2)==1)
            r=(r*x)%n;
        x=(x*x)%n;
        y=y/2;
    }
    return(r);
}
unsigned int encrypt(unsigned int z)
{
    unsigned int e;
    do
    {
        printf("\n enter the number e that are relative prime to z and < z:");
        scanf("%d",&e);
        if(e>=z)
            continue;
    }
    while(gcd(e,z)!=1);
        return(e);
}
unsigned int decrypt(unsigned int e,unsigned int z)
{
    unsigned int d;
    for(d=2;d<z;d++)
    {
        if(((long int)(e*d)%(long int)z)==1)
        break;
    }
     return d;

}
int main()
{
    unsigned int plain_txt[MAX],cipher_txt[MAX];
    unsigned int p,q,z,n,e,d;
    char msg[MAX];
    int i;


read:
    do
    {

        printf("\n Enter two large prime numbers p and q:");
        scanf("%d%d",&p,&q);
    }while(p==q);

    n=p*q;
    z= (p-1)*(q-1);
    printf("\n n=%d,z=%d",n,z);
    if(n<120)
    {
        printf("\n\nPlease keep n>=122");
        goto read;
    }

    e = encrypt(z);
    d = decrypt(e,z);

    printf("\n Public key = {%d,%d}",e,n);
    printf("\n Private key = {%d,%d}",d,n);


    printf("\nEnter the string consisting only letters(a-zA-Z) :");
    scanf("%s",msg);

    for(i=0;i<strlen(msg);i++)
    {

        plain_txt[i] = msg[i];
        printf("\n %c = %d",plain_txt[i],plain_txt[i]);
    }
    printf("\n Cipher Text:\n");
    for(i=0;i<strlen(msg);i++)
    {
        cipher_txt[i] = xpowy_modn(plain_txt[i],e,n);
        printf("\n %c = %d",cipher_txt[i],cipher_txt[i]);

    }
    printf("\n \n Plain text:\n");
    for(i=0;i<strlen(msg);i++)
    {
        plain_txt[i] = xpowy_modn(cipher_txt[i],d,n);
        printf("\n %c = %d",plain_txt[i],plain_txt[i]);
    }


    return 0;
}
