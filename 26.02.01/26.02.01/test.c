#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>



//int main()
//{
//	int q[10];
//	int* p = q;
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%d", p + i);
//	}
//	for (int j = 0; j < 10; j++)
//	{
//		printf("p + j = %d ", *(p + j));
//	}
//	printf("\n");
//	for (int a = 0; a < 10; a++)
//	{
//		printf("q + a = %d ", *(q + a));
//	}
//	printf("\n");
//	for (int b = 0; b < 10; b++)
//	{
//		printf("p[b] = %d ", q[b]);
//	}
//	printf("\n");
//	for (int c = 0; c < 10; c++)
//	{
//		printf("q[c] = %d ", q[c]);
//	}
//	return 0;
//}

//int main()
//{
//	int arr[10];
//	int* p1 = arr;
//	int* p2 = arr + 4;
//	printf(" p1 - p2 = %d\n", p1 - p2);
//	printf(" p2 - p1 = %d\n", p2 - p1);
//	return 0;
//}




//#include <stdio.h>
//
//int main() {
//    // 1. 定义一维int数组（连续内存存储，下标0~4）
//    int arr[5] = { 10, 20, 30, 40, 50 };
//    // 2. 定义指针变量p，指向数组首元素（arr[0]）
//    // 方式1：直接用数组名（数组名arr是指向首元素的地址常量，等价于&arr[0]）
//    int* p = arr;
//    // 方式2：显式取首元素地址（与方式1完全等价，更直观）
//    // int *p = &arr[0];
//
//    printf("===== 数组基础信息 =====\n");
//    printf("数组首元素地址: %p\n", arr);    // 输出arr[0]的内存地址
//    printf("指针p的指向地址: %p\n", p);     // 与arr地址完全相同
//    printf("arr[0]的值: %d\n", arr[0]);     // 直接通过数组下标访问
//    printf("*p解引用的值: %d\n\n", *p);    // 通过指针解引用访问首元素（等价于arr[0]）
//
//    printf("===== 指针遍历数组（3种方式） =====\n");
//    // 方式1：指针算术运算（核心！p+i 指向arr[i]，解引用*p++逐个访问）
//    int* p_traverse = arr; // 重新定义遍历用指针，避免修改原指针p
//    printf("方式1（指针算术）: ");
//    for (int i = 0; i < 5; i++) {
//        printf("%d ", *p_traverse++); // 后缀++：先解引用取值，再指针后移1个int元素
//    }
//    printf("\n");
//
//    // 方式2：指针+下标（指针变量可像数组名一样用[]访问，等价于*(p+i)）
//    printf("方式2（指针下标）: ");
//    for (int i = 0; i < 5; i++) {
//        printf("%d ", p[i]); // p[i] 完全等价于 *(p+i)，也等价于 arr[i]
//    }
//    printf("\n");
//
//    // 方式3：数组名+指针算术（数组名是地址常量，不可自增，需用arr+i）
//    printf("方式3（数组名算术）: ");
//    for (int i = 0; i < 5; i++) {
//        printf("%d ", *(arr + i)); // 直接通过数组名做指针算术，解引用访问arr[i]
//    }
//    printf("\n\n");
//
//    printf("===== 指针指向数组指定元素 =====\n");
//    int* p3 = &arr[3]; // 指针直接指向数组第4个元素（下标3）
//    printf("指针p3指向arr[3]，解引用值: %d\n", *p3); // 输出40
//    printf("p3[-1] 访问前一个元素（arr[2]）: %d\n", p3[-1]); // 指针下标支持负数，等价于*(p3-1)
//    printf("p3+1 指向后一个元素（arr[4]），解引用值: %d\n", *(p3 + 1)); // 输出50
//
//    return 0;
//}

//#include<stdio.h>
//void menu()
//{
//	printf("*** 请选择查找方式 ***\n");
//	printf("***     0.退出     ***\n");
//	printf("***     1.下标查找 ***\n");
//	printf("***     2.值查找   ***\n");
//}
//void subscript(int * p1)
//{
//	int seek1, quit = 1;
//	while(quit != 0)
//	{
//		printf("请输入要查找的下标(0 - 5)：\n");
//		scanf("%d", &seek1);
//		if (seek1 >= 0 && seek1 < 5)
//		{
//			printf("找到了，值为： %d \n", *(p1 + seek1));
//		}
//		else
//		{
//			printf("输入下标有误，请重新输入\n");
//		}
//		printf("退出请输入“0”，否则输入非零值\n");
//		scanf("%d", &quit);
//	}
//	
//}
//
//void value(int * p2)
//{
//	int seek2, quit= 1, error = 0;
//	while (quit != 0)
//	{
//		printf("请输入要查找的数据：\n");
//		scanf("%d", &seek2);
//		for (int a = 0; a < 5; a++)
//		{
//			if (*(p2 + a) == seek2)
//			{
//				printf("找到了，下标为： %d \n", a);
//				error = 1;
//			}
//		}
//		if (error == 0)
//		{
//			printf("找不到\n");
//		}
//		error = 0;
//		printf("退出请输入“0”，否则输入非零值\n");
//		scanf("%d", &quit);
//	}
//}
//int main()
//{
//	int i = 5, choose = 1;
//	int arr[5];
//	int* p1 = arr;
//	int* p2 = arr;
//	printf("请输入5个数据：\n");
//	while (i--)
//	{
//		scanf("%d", p2++);
//	}
//	while (choose)
//	{
//		menu();
//		scanf("%d", &choose);
//		switch (choose)
//		{
//		case 0:
//			break;
//		case 1:
//			subscript(p1);
//			break;
//		case 2:
//			value(p1);
//			break;
//		default:
//			printf("输入有误，请重新输入！\n");
//		}
//	}
//	return 0;
//}