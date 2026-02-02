#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>
#define BOOKS_COUNT 6


//登录模块
int	pass(int* identify)
{
	int num = 3;//验证次数
	int error = 0;//单次验证出现错误
	char user_Name_Normal[50] = "zzl";//普通用户名
	char user_Name_Root[50] = "lqx";//Root用户名
	char password_Normal[50] = "zzl111";//普通密码
	char password_Root[50] = "lqx111";//Root密码
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
				*identify = 1;
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
				*identify = 2;
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

//书籍结构体
typedef struct
{
	char book_Title[100];//书名
	char book_Author[100];//作者
	char book_Genre[100];//体裁
	char book_Status[2];//库存状态
	char book_Borrower[100];//借阅人
	char book_Chapter[100];
} Book;

//书名, 作者，体裁，库存状态, 借阅人， 章节
Book books[BOOKS_COUNT] = { {"Lolita", "Vladimir Nabokov", "novel" ,"1", "", "Section One"},//在库
							{ "Poems", "Emily Dickinson", "poetry collection", "1", "","Section One"},//在库
							{ "War", "Carl von Clausewitz", "military theory", "0" , "xnl", "Section One"},//已借出
							{ "Dune", "Frank Herbert", "novel", "1", "", "Section One"},//在库
							{ "It", "Stephen King", "novel", "0" , "lqx", "Section One"} //已借出
};

//查书
Book* menu_Book(const char* Title1)
{
	if (Title1 == NULL || *Title1 == '\0')
	{
		printf("书库中找不到此书\n");
		return NULL;
	}
	for (int i = 0; i < BOOKS_COUNT; i++)
	{
		if (strcmp(Title1, books[i].book_Title) == 0)
		{
			return &books[i];
		}
	}
	printf("书库中找不到此书\n");
	return NULL;
}

//查找书籍资料
void book_Seek(Book* book1)
{
	int choose_Seek = -1;
	while (choose_Seek)
	{
		choose_Seek = -1;
		printf("请输入要查找的内容：0.退出  1.作者  2.体裁  3.在库状态  4.第一节\n");
		scanf("%d", &choose_Seek);
		switch (choose_Seek)
		{
		case 0:
			break;
		case 1:
			printf("本书作者为：%s\n", book1->book_Author);
			break;
		case 2:
			printf("本书体裁为：%s\n", book1->book_Genre);
			break;
		case 3:
			printf("本书在库状态为（0表示借出，1表示在库）：%s\n", book1->book_Status);
			break;
		case 4:
			printf("本书第一节为：%s\n", book1->book_Chapter);
			break;
		default:
			printf("输入有误，请重新输入！\n");
		}
	}
}

//借书
void borrow_Book(Book* Title2)
{
	printf("本书在库状态为（0表示借出，1表示在库）：%s\n", Title2->book_Status);
	if (strcmp(Title2->book_Status, "0") == 0)
	{
		printf("本书已借出，无法借阅！\n");
	}
	else
	{
		printf("已成功借阅《%s》\n", Title2->book_Title);
		printf("请输入您的名字：\n");
		char borrower2[100] = "";
		scanf("%s", borrower2);
		strcpy(Title2->book_Borrower, borrower2);
		strcpy(Title2->book_Status, "0");
		printf("登记成功，请保管好书籍！\n");
	}
}

//还书
void return_Book(Book* Title3)
{
	strcpy(Title3->book_Status, "1");
	strcpy(Title3->book_Borrower, "");
	printf("已成功归还《%s》\n", Title3->book_Title);
}

//删除书籍
void delete_Book(const char* Title4)
{
	int exist = -1;
	for (int j = 0; j < BOOKS_COUNT; j++)
	{
		if (strcmp(Title4, books[j].book_Title) == 0)
		{
			exist = j;
			break;
		}
	}
	if (exist != -1)
	{
		for (int k = exist; k < BOOKS_COUNT - 1; k++)
		{
			books[k] = books[k + 1];
		}
		printf("已删除书籍《%s》\n", Title4);
	}
	else
	{
		printf("找不到此书，无法删除\n");
	}
}

//增加书籍信息
void add_Information(Book* Title5)
{
	int choose_Add = -1;
	while (choose_Add)
	{
		choose_Add = -1;
		printf("请输入要增加的内容：0.退出  1.书名  2.作者  3.体裁  4.库存状态  5.借阅人  6.章节\n");
		scanf("%d", &choose_Add);
		switch (choose_Add)
		{
		case 0:
			break;
		case 1:
			printf("本书书名增加内容：\n");
			char add1[100] = "";
			scanf("%s", add1);
			strcat(Title5->book_Title, add1);
			printf("增加后的书名为：%s\n", Title5->book_Title);
			break;
		case 2:
			printf("本书作者增加内容：\n");
			char add2[100] = "";
			scanf("%s", add2);
			strcat(Title5->book_Author, add2);
			printf("增加后的作者为：%s\n", Title5->book_Author);
			break;
		case 3:
			printf("本书体裁增加内容：\n");
			char add3[100] = "";
			scanf("%s", add3);
			strcat(Title5->book_Genre, add3);
			printf("增加后的体裁为：%s\n", Title5->book_Genre);
			break;
		case 4:
			printf("本书的库存状态修改为(0 or 1)：\n");
			char add4[2] = "";
			scanf("%s", add4);
			strcpy(Title5->book_Status, add4);
			printf("修改后的库存状态为：%s\n", Title5->book_Status);
			break;
		case 5:
			printf("本书的借阅人修改为：\n");
			char add5[100] = "";
			scanf("%s", add5);
			strcpy(Title5->book_Borrower, add5);
			printf("修改后的借阅人为：%s\n", Title5->book_Borrower);
			break;
		case 6:
			printf("本书章节增加内容：\n");
			char add6[100] = "";
			scanf("%s", add6);
			strcat(Title5->book_Chapter, add6);
			printf("增加后的章节为：%s\n", Title5->book_Chapter);
			break;
		default:
			printf("输入有误，请重新输入！\n");
		}
	}
}
//Root用户权限
void menu_operate1()
{
	int choose_Operate = -1;
	while (choose_Operate)
	{
		choose_Operate = -1;
		printf("*** 请选择要执行的操作 ***\n");
		printf("***     0.退出         ***\n");
		printf("***     1.查阅书籍资料 ***\n");
		printf("***     2.借书         ***\n");
		printf("***     3.还书         ***\n");
		printf("***     4.删除书籍     ***\n");
		printf("***     5.增加书籍信息 ***\n");
		scanf("%d", &choose_Operate);
		switch (choose_Operate)
		{
		case 0:
			break;
		case 1:
			//查阅书籍资料
			printf("请输入要查询的书名：\n");
			char book_Title1[100] = "";
			scanf("%s", book_Title1);
			Book* book1 = menu_Book(book_Title1);
			if (book1 == NULL)
			{
				break;
			}
			book_Seek(book1);
			break;
		case 2:
			printf("请输入要借阅的书名：\n");
			char book_Title2[100] = "";
			scanf("%s", book_Title2);
			Book* book2 = menu_Book(book_Title2);
			if (book2 == NULL)
			{
				break;
			}
			borrow_Book(book2);
			break;
		case 3:
			//还书（缺陷：只有能查询到书名的能还书：War，It，除非先执行了借书程序，且无设置输入错误判断）
			printf("请输入要归还的书（只能输入：War或It）\n");
			printf("ps：若在本次程序中已执行了借书程序，则也可归还：\n");
			char book_Title3[100] = "";
			scanf("%s", book_Title3);
			Book* book3 = menu_Book(book_Title3);
			if (book3 == NULL)
			{
				break;
			}
			return_Book(book3);
			break;
		case 4:
			//删除书籍
			printf("请输入要删除的书籍：\n");
			char book_Title4[100] = "";
			scanf("%s", book_Title4);
			delete_Book(book_Title4);
			break;
		case 5:
			//增加书籍信息
			printf("请输入要增加信息的书籍书名：\n");
			char book_Title5[100] = "";
			scanf("%s", book_Title5);
			Book* book5 = menu_Book(book_Title5);
			if (book5 == NULL)
			{
				break;
			}
			add_Information(book5);
			break;
		default:
			printf("输入有误，请重新输入！\n");
		}
	}
}

//普通用户权限
void menu_operate2()
{
	int choose_Operate = -1;
	while (choose_Operate)
	{
		choose_Operate = -1;
		printf("*** 请选择要执行的操作 ***\n");
		printf("***     0.退出         ***\n");
		printf("***     1.查阅书籍资料 ***\n");
		printf("***     2.借书         ***\n");
		printf("***     3.还书         ***\n");
		scanf("%d", &choose_Operate);
		switch (choose_Operate)
		{
		case 0:
			break;
		case 1:
			//查阅书籍资料
			printf("请输入要查询的书名：\n");
			char book_Title1[100] = "";
			scanf("%s", book_Title1);
			Book* book6 = menu_Book(book_Title1);
			if (book6 == NULL)
			{
				break;
			}
			book_Seek(book6);
			break;
		case 2:
			//借书（缺陷：只有能查询到书名的能还书：War，It，且无设置输入错误判断）
			printf("请输入要借阅的书名：\n");
			char book_Title2[100] = "";
			scanf("%s", book_Title2);
			Book* book2 = menu_Book(book_Title2);
			if (book2 == NULL)
			{
				break;
			}
			borrow_Book(book2);
			break;
		case 3:
			//还书（缺陷：只有能查询到书名的能还书：War，It，且无设置输入错误判断）
			printf("请输入要归还的书（只能输入：War或It）：\n");
			printf("ps：若在本次程序中已执行了借书程序，则也可归还：\n");
			char book_Title3[100] = "";
			scanf("%s", book_Title3);
			Book* book3 = menu_Book(book_Title3);
			if (book3 == NULL)
			{
				break;
			}
			return_Book(book3);
			break;
		default:
			printf("输入有误，请重新输入！\n");
		}
	}
}


int main()
{
	//1.登录
	int identify = 0;
	int ret = pass(&identify);
	if (ret == 0)
	{
		printf("验证次数过多，无法登录！\n");
		return 0;
	}
	//2.权限区分
	if (identify == 1)//Root 1
	{
		menu_operate1();
	}
	else//Normal 2
	{
		menu_operate2();
	}
	return 0;
}