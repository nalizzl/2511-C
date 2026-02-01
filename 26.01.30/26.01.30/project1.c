#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
//int	pass()
//{
//		int num = 3;//验证次数
//		char user_name[50] = "zzl";//用户名
//		char password[50] = "zzl123456";//密码
//		char name_try[50] = "";
//		char password_try[50] = "";
//		while (num)
//		{
//			printf("请输入登陆用户名：\n");
//			gets(name_try);
//			printf("请输入登陆密码：\n");
//			gets(password_try);
//			int a = strcmp(user_name, name_try);
//			int b = strcmp(password, password_try);
//			if (a == 0 && b == 0)
//			{
//				printf("登陆成功！\n");
//				break;
//			}
//			else if(a != 0 && b == 0)
//			{
//				num--;
//				printf("用户名错误，还有%d次机会\n", num);
//				continue;
//			}
//			else if(a == 0 && b != 0)
//			{
//				num--;
//				printf("密码错误，还有%d次机会\n", num);
//				continue;
//			}
//			else
//			{
//				num--;
//				printf("用户名、密码均有误，还有%d次机会\n", num);
//				continue;
//			}
//		}
//		return num;
//}
//void menu()
//{
//	printf("******请选择要查看的家电******\n");
//	printf("******       0.退出     ******\n");
//	printf("******       1.冰箱     ******\n");
//	printf("******       2.灯       ******\n");
//	printf("******       3.监控     ******\n");
//}
//int main()
//{
//	//1.用户登录
//	int ret = pass();
//	if (ret == 0)
//	{
//		printf("验证次数过多，无法登录！\n");
//		return 0;
//	}
//	//2.家电选择
//	int choose = 1;
//	while (choose)
//	{
//		menu();
//		scanf("%d", &choose);
//		switch (choose)
//		{
//		case 0:
//			break;
//		case 1:
//			printf("冰箱状态：\n温度：-2摄氏度\n");
//			break;
//		case 2:
//			printf("灯状态：\n关闭\n");
//			break;
//		case 3:
//			printf("监控状态：\n正常工作\n");
//			break;
//		}
//	}
//	return 0;
//}