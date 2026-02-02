#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>

int main()
{
	int i, j, * p1 = NULL, * p2 = NULL;
	int arr[2][3];
	printf("请输入2行3列的矩阵：\n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf("%d", *(arr + i) + j);
		}
	}
	int a, b, c, d;
	judge1: printf("请输入要取出的行、列号1：\n");
	scanf("%d%d", &a, &b);
	if (!(a >= 0 && a < 2))
	{
		printf("行号输入有误！\n");
		goto judge1;
	}
	else if (!(b >= 0 && b < 3))
	{
		printf("列号输入有误！\n");
		goto judge1;
	}
	p1 = *(arr + a) + b;
	judge2: printf("请输入要取出的行、列号2：\n");
	scanf("%d%d", &c, &d);
	if (!(c >= 0 && c < 2))
	{
		printf("行号输入有误！\n");
		goto judge2;
	}
	else if (!(d >= 0 && d < 3))
	{
		printf("列号输入有误！\n");
		goto judge2;
	}
	p2 = *(arr + c) + d;
	int choose = -1;
	while (choose)
	{
		printf("0.退出\n1.加法\n2.减法\n3.乘法\n4.除法\n");
		scanf("%d", &choose);
		switch (choose)
		{
		case 0:
			break;
		case 1:
			printf("%d\n", *(*(arr + a) + b) + *(*(arr + c) + d));
			break;
		case 2:
			printf("%d\n", *(*(arr + a) + b) - *(*(arr + c) + d));
			break;
		case 3:
			printf("%d\n", *(*(arr + a) + b) * *(*(arr + c) + d));
			break;
		case 4:
			printf("%d\n", *(*(arr + a) + b) / *(*(arr + c) + d));
			break;
		}
	}
	return 0;
}