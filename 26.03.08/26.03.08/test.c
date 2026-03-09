#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//
//	printf("请输入一个月份：\n");
//	scanf("%d", &i);
//	switch (i)
//	{
//	case 12:
//	case 1:
//	case 2:
//		printf("冬季\n");
//		break;
//	case 3:
//	case 4:
//	case 5:
//		printf("春季\n");
//		break;
//	case 6:
//	case 7:
//	case 8:
//		printf("夏季\n");
//		break;
//	case 9:
//	case 10:
//	case 11:
//		printf("秋季\n");
//		break;
//	default:
//		printf("输入错误！\n");
//		break;
//	}
//	return 0;
//}


//#include<stdio.h>
//#include<time.h>
//#include<stdlib.h>
//
//int main()
//{
//	int i, sum = 0;
//	float avg = 0;
//	int arr[10] = { 0 };
//	int* p = arr;
//
//	srand((unsigned int)time(NULL));
//
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = rand() % 100 + 1;
//		sum += *(p + i);
//	}
//	avg = (float)sum / 10;
//	printf("和为：%d \n平均数为：%.1f\n", sum, avg);
//	return 0;
//}