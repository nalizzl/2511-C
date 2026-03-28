#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
	int id;//序号
	char dishName[20];//菜名
	float price;//价格
	int inventory;//库存
	int order;//下单份额
	float cost;//成本
}Menu;

typedef struct
{
	int idBill;//序号
	char dishNameBill[20];//菜名
	float priceBill;//价格
	int orderBill;//下单份额
	float costBill;//成本
}Bill;

typedef struct
{
	char accountName[20];//账号
	char accountPassword[20];//密码
	int identity;//管理员身份标识
}Manager;

