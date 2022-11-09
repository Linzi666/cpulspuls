#define _CRT_SECURE_NO_WARNINGS 1


//
//5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：
//A选手说：B第二，我第三；
//B选手说：我第二，E第四；
//C选手说：我第一，D第二；
//D选手说：C最后，我第三；
//E选手说：我第四，A第一；
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
#include <stdio.h>

int main()
{
	
	int player[5] = { 0 }; //A B C D E 的名次
	//五个排名，每个人都有可能，所以每个人循环一次
	for (player[0] = 1; player[0] <= 5; player[0]++)
		for (player[1] = 1; player[1] <= 5; player[1]++)
			for (player[2] = 1; player[2] <= 5; player[2]++)
				for (player[3] = 1; player[3] <= 5; player[3]++)
					for (player[4] = 1; player[4] <= 5; player[4]++)
						//每个人的话都有一半真一半假，那么如果相加等于1，那就是1个为0，1个为1
						// 为了避免排名重复，1*2*3*4*5 必须等于120，并且 1+2+3+4+5 等于 15，确保排名不重复
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