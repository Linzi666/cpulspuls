#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>


//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水（编程实现）。

//第一种方法
int fun1(int money)
{
	//money钱的数量
	int emp = 0; //空瓶数量
	int drink = 0; //买了汽水的数量
	while (money--) //每循环一次，买一瓶汽水，花掉一块钱
	{
		drink++; //买了汽水后，汽水数量+1
		emp++;//瓶子数量也+1
		if (emp == 2) //如果空瓶数量有2个
		{
			emp = 0; //空瓶清空
			drink++;//汽水+1 ，所以此时空瓶又多了1个
			emp++;// 所以可以直接 emp = 1 ，这样写放别理解
		}
	} //循环结束，买了多少瓶汽水 都在drink里面
	
	return drink;

}


int fun2(int n)
{
	//第二种方法
	// n 空瓶数量
	int a = n; //汽水总数
	while (1) //瓶子为 0 结束循环
	{
		if (n == 1) //如果瓶子最后只有1个，那么就不能兑换了，结束循环
			break;
		if (n % 2 == 1)
		{
			//如果瓶子是单数，那么换了之后会剩下一个，所以再换掉之后加上这一个
			a += n / 2;
			n++; //加上没有换掉的瓶子
		}
		else //瓶子是偶数，直接/2换掉
			a += n / 2; 
		n /= 2;
	}
	return a;
}

//第一种方法需要循环20次，第二种方法 也要循环几次，那么有没有更简单的方法？
int fun3(int n)
{
	return n * 2 - 1;
} //没错，直接 *2-1 就是最后结果=.=


int main()
{
	int n = 20;
	printf("第一种方法，汽水:%d\n",fun1(n));
	printf("第二种方法，汽水:%d\n", fun2(n));
	printf("第三种方法，汽水:%d\n", fun3(n));


	return 0;
}
