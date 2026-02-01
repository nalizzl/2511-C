#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
//int main()
//{
//    int i, sum;
//    int a[5] = { 0 };
//    for (i = 0, sum = 0; i <= 4; i++)
//    {
//        printf("please input num %d\n", i);
//        scanf("%d", &a[i]);
//        sum += a[i];
//    }
//    printf("%d", sum);
//}

//int main()
//{
//	int i, sum1, sum2 = 0;
//	int a[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	for (i = 0, sum1 = 0; i <= 2; i++)
//	{
//		sum1 += a[i][i];
//	}
//	for (i = 0, sum2 = 0; i <= 2; i++)
//	{
//		sum2 += a[i][2 - i];
//	}
//	printf("主对角线和：%d\n副对角线和：%d\n", sum1, sum2);
//	return 0;
//}


////斐波那契数列
//int main()
//{
//	int i, sum;
//	int a[100] = { 0 };
//	a[0] = 0;
//	a[1] = 1;
//	printf("%d\n%d\n", a[0], a[1]);
//	for (i = 2, sum = 0; i < 10; i++)
//	{
//		a[i] = a[i - 2] + a[i - 1];
//		printf("%d\n", a[i]);
//	}
//	return 0;
//}


////数组转置
//int main()
//{
//	int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
//	int b[4][3] = { 0 };
//	for (int i = 0, j = 0; i < 3; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			b[j][i] = a[i][j];
//		}
//	}
//	for (int i = 0, j = 0; i < 4; i++)
//	{
//		for (j = 0; j < 3; j++)
//		{
//			printf("%d ", b[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}