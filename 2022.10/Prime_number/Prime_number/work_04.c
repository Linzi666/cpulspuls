#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>


//写一个代码打印1-100之间所有3的倍数的数字
int main() {
	int i = 0;
	while ((i++) * 3 < 100) {
		if (i * 3 < 100)
			printf("%d  ", i * 3);
	}
	return 0;
}

//写代码将三个整数数按从大到小输出
//int main() {
//	int num1 = 0;
//	int num2 = 0;
//	int num3 = 0;
//	scanf("%d %d %d", &num1, &num2, &num3);
//	printf("%d ", num1 > num2 ? num1 > num3 ? num1 : num3 : num2 > num3 ? num2 : num3);
//	printf("%d ", num1 > num2 ? num2 > num3 ? num2 : num1 > num3 ? num3 : num1 : num1 > num3 ? num1 : num2 > num3 ? num3 : num2);
//	printf("%d ", num1 > num2 ? num2 < num3 ? num2 : num3 : num1 < num3 ? num1 : num3);
//	return 0;
//}



//求1-100之间的素数
//int prime(int a) {
//	int i = 2;
//	while (i < a) {
//		if (a % i == 0 )
//			return 0;
//		i++;
//	}
//	return 1;
//}
//
//
//int main() {
//
//	int i = 3;
//
//	while (i < 100) {
//		if (prime(i))
//			printf("%d ",i);
//		i++;
//	}
//
//
//	return 0;
//}

//求1000-2000年的闰年

//int main() {
//	int year = 1000;
//	while (year % 4 != 0)
//		year++;   //先找出1000年开始的第一个闰年
//	 
//	while (year <= 2000) {
//		printf("%d ",year);
//		year += 4;  //再第一个闰年上每年+4,直到2000
//	}
//	return 0;
//}

//  
//求2数的最大公约数
//int main() {
//	int num1 = 0;
//	int num2 = 0;
//	int ys = 0;
//	scanf("%d %d",&num1,&num2);
//
//	while (num1 % num2) {
//		ys = num1 % num2;
//		num1 = num2;
//		num2 = ys;
//	}
//	printf("%d",num2);
//
//}
