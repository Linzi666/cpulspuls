#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
//洛谷 P1042 [NOIP2003 普及组] 乒乓球


int main()
{
	char arr[26] = { 0 };
	
	while (scanf("%s", arr) != EOF)
	{
		char* p = arr;
		//每输入一行，输出
		int len = 0;
		while ((*p != 'E') && (*p != '\0'))
		{
			len++;
			p++;
		}
		

		p = arr;
		//WWWWWWWWWWWWWWWWWWWWWWLWE

		//11 分制比赛输出
		//11个一节
		int j = len / 11;
		int myscore = 0;//华华的比分
		int rival = 0;//对手的比分
		//每场比赛
		int i = 0;
		for (i = 0; i < j; i++)
		{
			int cs = 0;
			for (cs = 0; cs < 11; cs++)
			{
				if (*p == 'W')
					myscore++;
				else if (*p == 'L')
					rival++;
				p++;
			}

			//输出这一轮的分数
			printf("%d:%d\n", myscore, rival);
			myscore = 0;
			rival = 0;
		}
		//最后一场比赛
		while ((*p) != '\0')
		{
			if (*p == 'W')
				myscore++;
			else if (*p == 'L')
				rival++;

			p++;
		}
		//输出这一轮的分数
		printf("%d:%d\n", myscore, rival);
		printf("\n");
		myscore = 0;
		rival = 0;
		p = arr;

		//21分制
		j = len / 21;
		//每场比赛
		for (i = 0; i < j; i++)
		{
			//21次一个循环
			int cs = 0;
			for (cs = 0; cs < 21; cs++)
			{
				if (*p == 'W')
					myscore++;
				else if (*p == 'L')
					rival++;
				p++;
			}
			//一场结束后打印
			printf("%d:%d\n", myscore, rival);
			//分数清空
			myscore = 0;
			rival = 0;
		}
		//打印剩余比赛
		while (*p != '\0')
		{
			if (*p == 'W')
				myscore++;
			else if (*p == 'L')
				rival++;
			p++;
		}
		//一场结束后打印
		printf("%d:%d\n", myscore, rival);
		//分数清空
		myscore = 0;
		rival = 0;
		printf("\n");
	}
	return 0;
}