#include"mystruct.h"

void menu()
{
	printf("***************************\n");
	printf("****** 1.录入/修改     ****\n");
	printf("****** 2.计算平均分    ****\n");
	printf("****** 3.查找最高/低分 ****\n");
	printf("****** 4.统计及格      ****\n");
	printf("****** 0. 退出         ****\n");
	printf("***************************\n");
}

void amend(Student* score)
{
	Student* score2 = score;
	Student* score3 = score;
	int input2 = -1;

	printf("请输入要执行的操作：1.录入成绩  2.修改成绩 \nps: 成绩范围：0 - 100 \n");
	scanf("%d", &input2);
	//1.
	if (input2 == 1)
	{
		int num = COUNT;

		printf("学生名单如下：\n");
		printf("zzl, zyh, lhx, wxh, zzj\n");
		printf("请按名单顺序录入成绩：\n");
		while (num--)
		{
			scanf("%f", &(score2->score));
			score2++;
		}
		printf("录入完成！\n");
	}
	else if (input2 == 2)
	{
		int num2 = COUNT;
		char name2[20] = { 0 };

		printf("学生名单如下：\n");
		printf("zzl, zyh, lhx, wxh, zzj\n");
		printf("请输入学生姓名：\n");
		scanf("%s", name2);
		while (num2--)
		{
			if (strcmp(score3->name, name2) == 0)
			{
				printf("请输入修改后的成绩：\n");
				scanf("%f", &(score3->score));
				break;
			}
			score3++;
		}
	}
}

float sum(Student* score4)
{
	int num3 = COUNT;
	float sum = 0;

	while (num3--)
	{
		sum += score4->score;
		score4++;
	}
	return sum;
}

void average(Student* score)
{
	Student* score4 = score;
	float ret = 0, avg = 0;

	ret = sum(score4);
	avg = ret / COUNT;
	printf("班级平均分为：%.2f\n", avg);
}

float * search(Student* score, int input3)
{
	Student* score5 = score;
	Student* score6 = score;
	int num4 = COUNT, num5 = COUNT;
	float* max = &(score5->score);
	float* min = &(score5->score);

	while (input3)
	{
		switch (input3)
		{
		case 1:
			while (num4--)
			{
				if ((score5->score) > (*max))
				{
					max = &(score5->score);
				}
				score5++;
			}
			return max;
			break;
		case 2:
			while (num5--)
			{
				if ((score6->score) < (*min))
				{
					min = &(score6->score);
				}
				score6++;
			}
			return min;
			break;
		default:
			printf("输入有误！\n");
		}
	}
	return NULL;
}

void statistics(Student* score, float pass)
{
	int pass_num = 0, fail_num = 0, num6 = COUNT;
	Student* score7 = score;

	while (num6--)
	{
		if (score7->score >= pass)
		{
			pass_num++;
		}
		else
		{
			fail_num++;
		}
		score7++;
	}
	printf("班级及格人数为：%d\n不及格人数为：%d\n", pass_num, fail_num);
}

