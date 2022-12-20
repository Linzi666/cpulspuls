#define _CRT_SECURE_NO_WARNINGS 1

#include "my_qsort.h"
#include <string.h>

int IntCmp(void* e1, void* e2)
{
	return *((int*)e2) - *((int*)e1);
}

int FloatCmp(void* e1, void* e2)
{
	return *((float*)e2) - *((float*)e1);
}

int CharCmp(void* e1, void* e2)
{
	return strcmp(((char*)e2) ,((char*)e1));
}

void FloatPrintArr(float* arr, int len)
{
	for (int i = 0; i < len; i++)
		printf("%f ", arr[i]);

	printf("\n");
}

int main()
{
	int arr[] = { 5,6,7,8,4,3,2,1 };
	int len = sizeof(arr) / sizeof(arr[0]);
	PrintArr(arr, len);

	my_qsort(arr, len,sizeof(arr[0]), IntCmp);
	PrintArr(arr, len);

	float farr[] = { 5.5,6.6,7.7,8.8,4.4,3.3,2.2,1.1 };
	int Flen = sizeof(farr) / sizeof(farr[0]);

	FloatPrintArr(farr, Flen);
	my_qsort(farr, Flen, sizeof(farr[0]), FloatCmp);
	FloatPrintArr(farr, Flen);

	char strarr1[] = "aksjfbhasfkavz";
	int slen = strlen(strarr1);
	printf("%s\n", strarr1);
	my_qsort(strarr1, slen, sizeof(strarr1[0]),CharCmp);
	printf("%s\n", strarr1);



	
	return 0;
}