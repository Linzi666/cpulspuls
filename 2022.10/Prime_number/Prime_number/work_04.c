#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>


//дһ�������ӡ1-100֮������3�ı���������
int main() {
	int i = 0;
	while ((i++) * 3 < 100) {
		if (i * 3 < 100)
			printf("%d  ", i * 3);
	}
	return 0;
}

//д���뽫�������������Ӵ�С���
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



//��1-100֮�������
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

//��1000-2000�������

//int main() {
//	int year = 1000;
//	while (year % 4 != 0)
//		year++;   //���ҳ�1000�꿪ʼ�ĵ�һ������
//	 
//	while (year <= 2000) {
//		printf("%d ",year);
//		year += 4;  //�ٵ�һ��������ÿ��+4,ֱ��2000
//	}
//	return 0;
//}

//  
//��2�������Լ��
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
