#define _CRT_SECURE_NO_WARNINGS 1


//
//5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ����������
//Aѡ��˵��B�ڶ����ҵ�����
//Bѡ��˵���ҵڶ���E���ģ�
//Cѡ��˵���ҵ�һ��D�ڶ���
//Dѡ��˵��C����ҵ�����
//Eѡ��˵���ҵ��ģ�A��һ��
//����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�
#include <stdio.h>

int main()
{
	
	int player[5] = { 0 }; //A B C D E ������
	//���������ÿ���˶��п��ܣ�����ÿ����ѭ��һ��
	for (player[0] = 1; player[0] <= 5; player[0]++)
		for (player[1] = 1; player[1] <= 5; player[1]++)
			for (player[2] = 1; player[2] <= 5; player[2]++)
				for (player[3] = 1; player[3] <= 5; player[3]++)
					for (player[4] = 1; player[4] <= 5; player[4]++)
						//ÿ���˵Ļ�����һ����һ��٣���ô�����ӵ���1���Ǿ���1��Ϊ0��1��Ϊ1
						// Ϊ�˱��������ظ���1*2*3*4*5 �������120������ 1+2+3+4+5 ���� 15��ȷ���������ظ�
						if ((((player[1] == 2) + (player[0] == 3)) == 1) &&
							(((player[1] == 2) + (player[4] == 4)) == 1) &&
							(((player[2] == 1) + (player[3] == 2)) == 1) &&
							(((player[2] == 5) + (player[3] == 3)) == 1) &&
							(((player[4] == 4) + (player[0] == 1)) == 1) &&
							(player[0]* player[1]* player[2]* player[3]* player[4] == 120 ) &&
							(player[0] + player[1] + player[2] + player[3] + player[4] == 15)
							)
							printf("A = %d,B = %d,C = %d,D = %d,E = %d\n",player[0],
								player[1], player[2], player[3], player[4]
								);


	


	return 0;
}