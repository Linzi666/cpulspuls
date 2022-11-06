#define _CRT_SECURE_NO_WARNINGS 1

//题目：
//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分。
void adj(int* p,int sz)
{
	int i = 0;
	int j = 0; //替换到第几个了
	for(i ; i < sz ; i++)
		if(p[i] % 2 == 1 ) //是奇数 ，交换位置 
		{ 
			int temp = p[i];
			p[i] = p[j];
			p[j] = temp;
			j++;
		}
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int len = sizeof(arr) / sizeof(arr[0]);
	adj(arr,len);
	return 0;
}
