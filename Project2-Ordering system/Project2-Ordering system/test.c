#include"Order.h"

int dishTotal = 6, managerTotal = 3;

Menu dishMenu[20] = {
	{1, "表弟橙汁", 11.11f, 10, 0, 5.5f},
	{2, "表哥橙汁", 33.33f, 10, 0, 15.15f},
	{3, "纯粹橙汁", 44.44f, 10, 0, 22.22f},
	{4, "小骑士橙汁", 99.99f, 10, 0, 45.45f},
	{5, "辐光橙汁", 55.55f, 10, 0, 25.25f},
	{6, "大黄蜂橙汁", 66.66f, 10, 0, 33.33f}
};

Bill billGeneration[20] = {
	{1, "表弟橙汁", 11.11f, 0, 5.5f},
	{2, "表哥橙汁", 33.33f, 0, 15.15f},
	{3, "纯粹橙汁", 44.44f, 0, 22.22f},
	{4, "小骑士橙汁", 99.99f, 0, 45.45f},
	{5, "辐光橙汁", 55.55f, 0, 25.25f},
	{6, "大黄蜂橙汁", 66.66f, 0, 33.33f}
};

Manager restaurantManager[8] = {
	{"tsgqdm", "wznz", 1},//超级管理员
	{"jslqdm", "jsnz", 0},//普通管理员1
	{"sslqdm", "yqsb", 0}//普通管理员2
};


//函数声明
void menuDisplay(Menu* dishMenu1, int dishTotal1);
void dishOrder(Menu* dishMenu2, int dishTotal2);
void orderChange(Menu* dishMenu3, int dishTotal3);
float billSettlement(Menu* dishMenu4, int dishTotal4);
void managerLogin(Manager* managerList, int managerTotal2);
void normalManager();
void superManager();


int main()
{
	int choice1 = -1;

	//1)登陆页面
	while (choice1)
	{
		printf("欢迎来到辐光餐厅！\n");
		printf("请选择：0.退出  1.登录  2.点餐\n");
		scanf("%d", &choice1);
		switch (choice1)
		{
		case 0:
			printf("再见！欢迎下次光临！\n");
			break;
		case 1:
			//1.管理员登陆
			managerLogin(restaurantManager, managerTotal);
			break;
		case 2:
			//2.点餐页面
			//2.1.菜单展示
			menuDisplay(dishMenu, dishTotal);
			//2.2.下单
			dishOrder(dishMenu, dishTotal);
			break;
		default:
			printf("输入有误！请重新输入：\n");
		}
	}
	return 0;
}