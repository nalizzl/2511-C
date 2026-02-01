#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>


menu_book()
{
	char book1[50] = "book1 ";//在库
	char book2[50] = "Jane Eyre1";//在库
	char book3[50] = "Jane Eyre0";//已借出

}

int	pass(int * distinguish)
{
	int num = 3;//验证次数
	int error = 0;//单次验证出现错误
	char user_Name_Normal[50] = "zzl";//普通用户名
	char user_Name_Root[50] = "zzllqx";//Root用户名
	char password_Normal[50] = "zzl123";//普通密码
	char password_Root[50] = "zzllqx111";//Root密码
	char name_Try[50] = "";
	char password_Try[50] = "";
	while (num)
	{
		error = 0;
		printf("请输入登陆用户名(数字+英文)：\n");
		gets(name_Try);
		printf("请输入登陆密码(数字+英文)：\n");
		gets(password_Try);
		size_t len1 = strlen(name_Try);
		size_t len2 = strlen(password_Try);
		for (int i = 0; i < len1; i++)
		{
			if (isalnum(name_Try[i]) == 0)
			{
				printf("请输入数字+英文组合的用户名\n");
				num--;
				printf("用户名错误，还有%d次机会\n", num);
				error = 1;
				break;
			}
		}
		if (error)
		{
			continue;
		}
		for (int j = 0; j < len2; j++)
		{
			if (isalnum(password_Try[j]) == 0)
			{
				printf("请输入数字+英文组合的用户密码\n");
				num--;
				printf("密码错误，还有%d次机会\n", num);
				error = 1;
				break;
			}
		}
		if (error)
		{
			continue;
		}
		//验证Root用户
		if (strcmp(user_Name_Root, name_Try) == 0)
		{
			if (strcmp(password_Root, password_Try) == 0)
			{
				printf("登陆成功，欢迎您，Root用户！\n");
				* distinguish = 1;
				break;
			}
			else
			{
				num--;
				printf("密码错误，还有%d次机会\n", num);
				continue;
			}
		}
		else//验证普通用户
		{
			int a = strcmp(user_Name_Normal, name_Try);//普通用户名
			int b = strcmp(password_Normal, password_Try);//普通用户密码
			if (a == 0 && b == 0)
			{
				printf("登陆成功，欢迎您，普通用户！\n");
				*distinguish = 2;
				break;
			}
			else if (a != 0 && b == 0)
			{
				num--;
				printf("用户名错误，还有%d次机会\n", num);
				continue;
			}
			else if (a == 0 && b != 0)
			{
				num--;
				printf("密码错误，还有%d次机会\n", num);
				continue;
			}
			else
			{
				num--;
				printf("用户名、密码均有误，还有%d次机会\n", num);
				continue;
			}
		}
	}
	return num;
}

int main()
{
	//1.登录
	int distinguish = 0;
	int ret = pass(&distinguish);
	if (ret == 0)
	{
		printf("验证次数过多，无法登录！\n");
		return 0;
	}
	if (distinguish == 1)//Root
	{

	}
	else//Normal
	{

	}
	return 0;
}