#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define N 8
#define M 5
int obstaclesMap[M][N] ;//карта с препятствиями
int ways[M][N];
void setObstacles() {
  int i;
  int j;
  srand(time(NULL));
  for (i = 0; i < N; i++)
	for (j = 0; j < M; j++)
	  obstaclesMap[i][j] = rand()%2;
  obstaclesMap[0][0]=0;
}
void printObstacles() {
  int i;
  int j;
  srand(time(NULL));
  for (i = 0; i < N; i++)
  {
	for (j = 0; j < M; j++)
	  printf("%d ",obstaclesMap[i][j]);
	printf("\n");
  }
}
int routesWithObstacles(int x, int y)
{
	if (x==0 && y==0 || obstaclesMap[x][y]==1)
		return 0;
	if (x==0&&y==1 || x==1&&y==0)
		return 1;
	if (x==0)
	{
		if (obstaclesMap[x][y-1] == 1) //если сверху препятствие, то не дойдем
			return 0;
		if (routesWithObstacles(x,y-1)==0)
			return 0;
		return 1;
	}
	if (y==0)
	{
		if (obstaclesMap[x-1][y] == 1) //если слева препятствие, то не дойдем
			return 0;
		if (routesWithObstacles(x-1,0)==0)
			return 0;
		return 1;
	}
	if (obstaclesMap[x][y-1] == 1 && obstaclesMap[x-1][y] == 1)
		return 0;
	else if (obstaclesMap[x][y-1]==1) //препятствие сверху
		return routesWithObstacles(x-1,y); //подойти можем только слева
	else if (obstaclesMap[x-1][y] == 1) // препятствие слева
		return routesWithObstacles(x,y-1); //подойти можем только сверху
	return routesWithObstacles(x-1,y)+routesWithObstacles(x,y-1);
		
}
int main()
{
	setObstacles();
	printObstacles();
	printf("\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%d ",routesWithObstacles(i,j));
		}
		printf("\n");
	}
	return 0;
}