#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//struct Book
//{
//	char title[20];
//	char author[20];
//	float price;
//};
//
//void book_int_print_msg()
//{
//	struct Book book1 = { "sanwenji", "me", 110.1 };
//	printf("书名：%s\n", book1.title);
//	printf("作者：%s\n", book1.author);
//	printf("价格：%.2f\n", book1.price);
//	book1.price = 2.16;
//	printf("打折价：%.2f\n", book1.price);
//}
//int main()
//{
//	book_int_print_msg();
//	return 0;
//}




typedef struct 
{
	int id;
	char name[20];
	float score;
}StudentMsg;

StudentMsg StudentMsg1[3] = { {25, "lqx", 66}, {28, "zzl", 88}, {18, "xwy", 99} };

int main()
{
	int num = 0, flag = 0;
	float max = StudentMsg1->score;
	StudentMsg* StudentMsg2 = StudentMsg1;

	while (num != 3)
	{
		if ((StudentMsg2->score) > max)
		{
			max = StudentMsg2->score;
			flag = num;
		}
		StudentMsg2++;
		num++;
	}
	printf("成绩最高的学生为：%s\nid: %d\n成绩：%.2f\n", (StudentMsg1 + flag)->name, (StudentMsg1 + flag) ->id, (StudentMsg1 + flag) ->score);
	return 0;
}