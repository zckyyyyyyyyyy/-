#include <stdlib.h>
#include "tools.h"
#include "game2048.h"



//  显示界面
void show_view(void)
{
	//debug("%s\n",__func__);
	system("clear");
	for(int i=0;i<4;i++)
	{
		printf("--------------------\n");
		for(int j=0;j<4;j++)
		{
			if(p[i][j])
			{
				printf("|%4d",p[i][j]);
			}
			else
			{
				printf("|    ");
			}
		}
		printf("|\n");
	}
	printf("--------------------\n");
}

//
static bool is_full(void)
{
	int* num = (int*)p;
	for(int i=0;i<16;i++)
	{
		if(0 == num[i])
		{
			return false;
		}
	}
	return true;
}

//  随机位置生成2
void rand_two(void)
{
	//debug("%s\n",__func__);
	if(is_full())
	{
		return;
	}
	for(;is_move_merge;)
	{
		int x =rand()%4;
		int y =rand()%4;
		if(0 == p[x][y])
		{
			p[x][y] = 2;
			return;
		}
	}
}

//  检查是否还能继续
bool is_die(void)
{
	//debug("%s\n",__func__);
	if(!is_full()) return false;
	for(int y=0;y<4;y++)
	{
		for(int x=0;x<3;x++)
		{
			if(p[x][y] == p[x+1][y]) return false;
		}
	}
	
	for(int x=0;x<4;x++)
	{
		for(int y=0;y<3;y++)
		{
			if(p[x][y] == p[x][y+1]) return false;
		}
	}
	return true;
}
