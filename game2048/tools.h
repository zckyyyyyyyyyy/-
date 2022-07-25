#ifndef TOOLS_H
#define TOOLS_H

#include <stdio.h>
#include <stdbool.h>
#include <getch.h>
		
#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__);
#else
    #define debug(...)
#endif


//  随机位置生成2
void rand_two(void);

//  显示界面
void show_view(void);

//  检查是否还能继续
bool is_die(void);
	



#endif//TOOLS_H
