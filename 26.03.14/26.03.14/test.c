#include"mystruct.h"

void menu();
void amend(Student* score);
float sum(Student* score4);
void average(Student* score);
float* search(Student* score, int input3);
void statistics(Student* score, float pass);
Student score[COUNT] = { {"zzl", 0},{"zyh", 0},{"lhx", 0},{"wxh", 0},{"zzj", 0} };

int main()
{
	int input = -1, input3 = -1;
	float pass = 0;

	while (input)
	{
		menu();
		printf("请选择要执行的操作：\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			//a.录入/修改
			amend(score);
			break;
			//b.平均分
		case 2:
			average(score);
			break;
			//c.查找最高/低
		case 3:
			printf("请问您要查找最高分还是最低分？\n输入：1.最高分 2.最低分\n");
			scanf("%d", &input3);
			float* ret2 = search(score, input3);
			if (ret2 != NULL)
			{
				switch (input3)
				{
				case 1:
					printf("班级最高分为：%.2f\n", *ret2);
					break;
				case 2:
					printf("班级最低分为：%.2f\n", *ret2);
				}
			}
			break;
			//d.统计（不）及格
		case 4:
			printf("请设置及格线：\n");
			scanf("%f", &pass);
			statistics(score, pass);
			break;
		case 0:
			break;
		default:
			printf("输入有误！请重新输入：\n");
		}
	}
	return 0;
}
