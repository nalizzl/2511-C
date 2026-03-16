#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


typedef struct 
{
	int year;
	int month;
	int day;
}Date;

typedef struct
{
	char name[20];
	Date birth;
	float score;
}Student;

void printPointStudent(Student* student2)
{
	printf("姓名：%s\n", student2->name);
	printf("出生日期：%d年", student2->birth.year);
	printf("%d月", student2->birth.month);
	printf("%d日\n", student2->birth.day);
	printf("成绩：%.1f\n", student2->score);
}

void printStudent(Student student3)
{
	printf("姓名：%s\n", student3.name);
	printf("出生日期：%d年", student3.birth.year);
	printf("%d月", student3.birth.month);
	printf("%d日\n", student3.birth.day);
	printf("成绩：%.1f\n", student3.score);
}

int main()
{
	Student student1 = { "zhangyihua", {1005, 05, 29}, 99.9 };
	printPointStudent(&student1);
	printStudent(student1);
	return 0;
}