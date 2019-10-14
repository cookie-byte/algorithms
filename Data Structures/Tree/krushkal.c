#include<stdio.h>
#include<conio.h>
int root[10],flag=0,count=0,temp,min;
int a[20],cost[20][20],n,i,j,k,totalcost=0,x,y;
void find_min(),check_cycle(),update();
void main()
{
  clrscr();
  printf("Enter the number of vertices please\n");
  scanf("%d",&n);
  printf("Enter the cost of the matrix please\n");
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
      scanf ("%d",&cost[i][j]);
  find_min();
  while (min!=999 && count!=n-1)
  {
	check_cycle();
	if (flag)
	{
		printf ("%d  --->  %d  =  %d\n",x,y,cost[x][y]);
		totalcost+=cost[x][y];
		update();
		count++;
	}
	cost[x][y]=cost[y][x]=999;
	find_min();
    }
    if (count<n - 2)
	printf("The graph is not connected\n");
    else
	printf("The graph is connected & the min cost is %d\n",totalcost);
    getch();
}
void check_cycle()
{
  if ((root[x]==root[y])&&(root[x]!=0))
	flag=0;
  else
	flag=1;
}
void find_min ()
{
	min = 999;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(min>cost[i][j])
			{
			    min = cost[i][j];
			    x = i;
			    y = j;
			}
}
void update()
{
	if(root[x]==0 && root[y]==0)
		root[x]=root[y]=x;
	else if(root[x]==0)
		root[x]=root[y];
	else if(root[y]==0)
		root[y]=root[x];
	else
	 {
	      temp = root[y];
		   for(i=1;i<=n;i++)
			if(root[i]==temp)
			   root[i]=root[x];
	 }
}
