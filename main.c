#include<stdio.h>
#define INFINITY 999
struct node
{
int cost;
int via;
}c[10][10];
int n;
void findPath(int n1,int n2)
{
int t;
t=c[n1][n2].via;
if(t<n2)
findPath(n1,t);
if(t!=n2)
printf("%d-->",t);
}
void createRtable()
{
int i,j,k;
int cost,x,via;
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
cost=INFINITY;
if(i!=j)
{
for (k=1; k<=n; k++)
{
if(i!=k)
{
x=c[i][k].cost+c[k][j].cost;
if(cost>x)
{
cost=x;
via=k;
}
}
}
c[i][j].cost=cost;
c[i][j].via=via;
}
else
{
c[i][i].cost=0;
c[i][i].via=i;
}
}
}
}//end of function
void dispRtable()
{
int i,j;
printf("Node");
for(i=1;i<=n;i++)
printf("\tcost\tvia");
printf("\n");
for(i=1;i<=n;i++)
{
printf("row %d\t",i);
for(j=1;j<=n;j++)
{
printf("%d\t%d\t",c[i][j].cost,c[i][j].via);
} printf("\n");
}}
int main()
{
int i,j;
int src,dst;
int choice;
printf("Enter the number of nodes:");
scanf("%d",&n);

printf("Enter the initial routing table (enter 999 if nodirect edge)\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
printf("cost[%d][%d]=",i,j);
scanf("%d",&c[i][j].cost);
c[i][j].via=INFINITY;
}
}
printf("Initial Routing table:\n");
dispRtable();
createRtable();


printf("The Final Routing Table:\n");
dispRtable();

choice=1;
while(choice) {
printf("Enter the two node numbers to find the path\n");
printf("Enter the source node:");
scanf("%d",&src);
printf("Enter the destination node:");
scanf("%d",&dst);
printf("\n The shortest path to reach %d from %d has cost =%d",dst,src,c[src][dst].cost);
printf("\n The path is:\n");
printf("%d-->",src);
findPath(src,dst);
printf("%d",dst);
printf("\nwould you like to continue (0/1)");
scanf("%d",&choice);
}
return 0;
}
