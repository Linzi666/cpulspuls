#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

/*
奖学金要求
院士奖学金，每人 8000 元，期末平均成绩高于 80 分（>80>80）并且在本学期内发表1篇或1篇以上论文的学生均可获得；
五四奖学金，每人 4000 元，期末平均成绩高于 85 分（>85>85），并且班级评议成绩高于 80 分（>80）的学生均可获得；
成绩优秀奖，每人 2000 元，期末平均成绩高于 90 分（>90>90),的学生均可获得；
西部奖学金，每人 1000 元，期末平均成绩高于 85 分（>85>85）的西部省份学生均可获得；
班级贡献奖，每人 850 元，班级评议成绩高于 80 分（>80>80）的学生干部均可获得；
*/
//先定义一个学生结构体

typedef struct Stu
{
	char name[20]; //名字
	int score_end; //期末平均成绩
	int score_class; //班级评议
	char is_esat;  // 西部地区 ，Y为是，N为否
	char is_cadre; //是否为学生干部
	int thesis; //论文
	int bonus; //获得奖金
}Stu;

int main()
{
	int n = 0;
	scanf("%d",&n); //学生人数
	Stu stus[4]; //创建结构体数组 ，变长数组等于 n
	int sum = 0;//所有人的奖学金
	int max = 0;//存储最大奖学金获得者
	int index = -1; //最大奖学金获得者的下标索引
	//录入学生信息
	int i = 0; 
	for (i = 0; i < n; i++)
	{
		scanf("%s %d %d %c %c %d",stus[i].name, &stus[i].score_end
		, &stus[i].score_class, &stus[i].is_cadre, &stus[i].is_esat, &stus[i].thesis
		);
		stus[i].bonus = 0; //初始化 0
	}
	//评定奖学金
	i = 0;
	for (i; i < n; i++)
	{
//院士奖学金，每人 8000 元，期末平均成绩高于 80 分（>80）并且在本学期内发表1篇或1篇以上论文的学生均可获得；
		if (stus[i].score_end > 80 && stus[i].thesis > 0)
		{
			stus[i].bonus += 8000;
			sum += 8000;
		}
//五四奖学金，每人 4000 元，期末平均成绩高于 85 分（ > 85），并且班级评议成绩高于 80 （ > 80）的学生均可获得；
		if (stus[i].score_end > 85 && stus[i].score_class > 80)
		{
			stus[i].bonus += 4000;
			sum += 4000;
		}
//成绩优秀奖，每人 2000 元，期末平均成绩高于 90 分（>90),的学生均可获得；
		if (stus[i].score_end > 90)
		{
			stus[i].bonus += 2000;
			sum += 2000;
		}
//西部奖学金，每人 1000 元，期末平均成绩高于 85 分（>85>85）的西部省份学生均可获得；
		if (stus[i].score_end > 85 && (stus[i].is_esat == 'Y'))
		{
			stus[i].bonus += 1000;
			sum += 1000;
		}
//班级贡献奖，每人 850 元，班级评议成绩高于 80 分（ > 80 > 80）的学生干部均可获得；
		if (stus[i].score_class > 80 && (stus[i].is_cadre == 'Y'))
		{
			stus[i].bonus += 850;
			sum += 850;
		}
		//判断谁的总奖学金最多
		if (stus[i].bonus > max)
		{
			max = stus[i].bonus;
			index = i;
		}
	}
	//输出最高奖学金学生
	printf("%s\n",stus[index].name);
	printf("%d\n", stus[index].bonus);
	printf("%d\n", sum);



	return 0;
}