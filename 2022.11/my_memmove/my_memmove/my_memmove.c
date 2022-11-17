#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
//memmove����ʵ��
void* my_memmove(void* desc,const void* src, size_t count)
{
	assert(desc && src);
	void* ret = desc;
	//���dest > src �Ӻ���ǰ�����������ǰ����
	if (desc > src)
	{
		//����ǰ
		while (count--)
		{
			*((char*)desc + count) = *((char*)src + count);
		}

	}
	else
	{
		//ǰ����
		while (count--)
		{
			*((char*)desc) = *((char*)src);
			desc = (char*)desc + 1;
			src = (char*)src + 1;
		}
	}
	return ret;
}


int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9 ,10};
	my_memmove(arr,arr+2,20);

	int i = 0;
	for (; i < 10; i++)
		printf("%d ",arr[i]);

	return 0;
}