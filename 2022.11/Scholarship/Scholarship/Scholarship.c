#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

/*
��ѧ��Ҫ��
Ժʿ��ѧ��ÿ�� 8000 Ԫ����ĩƽ���ɼ����� 80 �֣�>80>80�������ڱ�ѧ���ڷ���1ƪ��1ƪ�������ĵ�ѧ�����ɻ�ã�
���Ľ�ѧ��ÿ�� 4000 Ԫ����ĩƽ���ɼ����� 85 �֣�>85>85�������Ұ༶����ɼ����� 80 �֣�>80����ѧ�����ɻ�ã�
�ɼ����㽱��ÿ�� 2000 Ԫ����ĩƽ���ɼ����� 90 �֣�>90>90),��ѧ�����ɻ�ã�
������ѧ��ÿ�� 1000 Ԫ����ĩƽ���ɼ����� 85 �֣�>85>85��������ʡ��ѧ�����ɻ�ã�
�༶���׽���ÿ�� 850 Ԫ���༶����ɼ����� 80 �֣�>80>80����ѧ���ɲ����ɻ�ã�
*/
//�ȶ���һ��ѧ���ṹ��

typedef struct Stu
{
	char name[20]; //����
	int score_end; //��ĩƽ���ɼ�
	int score_class; //�༶����
	char is_esat;  // �������� ��YΪ�ǣ�NΪ��
	char is_cadre; //�Ƿ�Ϊѧ���ɲ�
	int thesis; //����
	int bonus; //��ý���
}Stu;

int main()
{
	int n = 0;
	scanf("%d",&n); //ѧ������
	Stu stus[4]; //�����ṹ������ ���䳤������� n
	int sum = 0;//�����˵Ľ�ѧ��
	int max = 0;//�洢���ѧ������
	int index = -1; //���ѧ�����ߵ��±�����
	//¼��ѧ����Ϣ
	int i = 0; 
	for (i = 0; i < n; i++)
	{
		scanf("%s %d %d %c %c %d",stus[i].name, &stus[i].score_end
		, &stus[i].score_class, &stus[i].is_cadre, &stus[i].is_esat, &stus[i].thesis
		);
		stus[i].bonus = 0; //��ʼ�� 0
	}
	//������ѧ��
	i = 0;
	for (i; i < n; i++)
	{
//Ժʿ��ѧ��ÿ�� 8000 Ԫ����ĩƽ���ɼ����� 80 �֣�>80�������ڱ�ѧ���ڷ���1ƪ��1ƪ�������ĵ�ѧ�����ɻ�ã�
		if (stus[i].score_end > 80 && stus[i].thesis > 0)
		{
			stus[i].bonus += 8000;
			sum += 8000;
		}
//���Ľ�ѧ��ÿ�� 4000 Ԫ����ĩƽ���ɼ����� 85 �֣� > 85�������Ұ༶����ɼ����� 80 �� > 80����ѧ�����ɻ�ã�
		if (stus[i].score_end > 85 && stus[i].score_class > 80)
		{
			stus[i].bonus += 4000;
			sum += 4000;
		}
//�ɼ����㽱��ÿ�� 2000 Ԫ����ĩƽ���ɼ����� 90 �֣�>90),��ѧ�����ɻ�ã�
		if (stus[i].score_end > 90)
		{
			stus[i].bonus += 2000;
			sum += 2000;
		}
//������ѧ��ÿ�� 1000 Ԫ����ĩƽ���ɼ����� 85 �֣�>85>85��������ʡ��ѧ�����ɻ�ã�
		if (stus[i].score_end > 85 && (stus[i].is_esat == 'Y'))
		{
			stus[i].bonus += 1000;
			sum += 1000;
		}
//�༶���׽���ÿ�� 850 Ԫ���༶����ɼ����� 80 �֣� > 80 > 80����ѧ���ɲ����ɻ�ã�
		if (stus[i].score_class > 80 && (stus[i].is_cadre == 'Y'))
		{
			stus[i].bonus += 850;
			sum += 850;
		}
		//�ж�˭���ܽ�ѧ�����
		if (stus[i].bonus > max)
		{
			max = stus[i].bonus;
			index = i;
		}
	}
	//�����߽�ѧ��ѧ��
	printf("%s\n",stus[index].name);
	printf("%d\n", stus[index].bonus);
	printf("%d\n", sum);



	return 0;
}