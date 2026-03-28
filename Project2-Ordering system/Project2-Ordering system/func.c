#include"Order.h"

extern Bill billGeneration[];
extern Menu dishMenu[];
extern Manager restaurantManager[];
extern int dishTotal;
extern int managerTotal;
int billOrderedCount = 0;
void dishOrder(Menu* dishMenu2, int dishTotal2);
void orderChange(Menu* dishMenu3, int dishTotal3);
float billSettlement(Menu* dishMenu4, int dishTotal4);
void normalManager();
void superManager();
void menuDisplayManager(Menu* dishMenu5, int dishTotal5);
void menuUpdate(Menu* dishMenu6, int dishTotal6);
void billDisplay();
void managementAdministrator();
void managerUpateInitial();

//菜单文件
void menuUpdateInitial()
{
	FILE* fpMenu = NULL;
	Menu* pointerInitial = dishMenu;
	int dishTotalCount = dishTotal;

	//读取菜单
	//菜单文件不存在
	if (_access("D:\\C Code\\2511class\\2511-C\\Project2-Ordering system\\Project2-Ordering system\\Menu.txt", 0) != 0)
	{
		//创建菜单
		fpMenu = fopen("D:\\C Code\\2511class\\2511-C\\Project2-Ordering system\\Project2-Ordering system\\Menu.txt", "w");
		if (fpMenu == NULL)
		{
			perror("菜单创建失败！\n");
			exit(1);
		}
		fprintf(fpMenu, "%d\n", dishTotal);
		while (dishTotalCount--)
		{
			fprintf(fpMenu, "%d, %s, %.2f, %d, %.2f\n", pointerInitial->id, pointerInitial->dishName, pointerInitial->price, pointerInitial->inventory, pointerInitial->cost);
			pointerInitial++;
		}
	}
	//菜单文件存在
	else
	{
		fpMenu = fopen("D:\\C Code\\2511class\\2511-C\\Project2-Ordering system\\Project2-Ordering system\\Menu.txt", "r");
		//更新菜单数组
		fscanf(fpMenu, "%d", &dishTotal);
		dishTotalCount = dishTotal;
		while (dishTotalCount--)
		{
			fscanf(fpMenu, "%d, %s, %f, %d, %f", &pointerInitial->id, &pointerInitial->dishName, &pointerInitial->price, &pointerInitial->inventory, &pointerInitial->cost);
			pointerInitial++;
		}
	}
	fclose(fpMenu);
}

//管理员文件
void managerUpateInitial()
{

	FILE* fpManager = NULL;
	Manager* pointerInitial4 = restaurantManager;
	int managerTotalCount = managerTotal;

	//读取管理员管理员列表
	//管理员文件不存在
	if (_access("D:\\C Code\\2511class\\2511-C\\Project2-Ordering system\\Project2-Ordering system\\Manager.txt", 0) != 0)
	{
		//创建管理员列表
		fpManager = fopen("D:\\C Code\\2511class\\2511-C\\Project2-Ordering system\\Project2-Ordering system\\Manager.txt", "w");
		if (fpManager == NULL)
		{
			perror("菜单创建失败！\n");
			exit(1);
		}
		fprintf(fpManager, "%d\n", managerTotal);
		while (managerTotalCount--)
		{
			fprintf(fpManager, "%s, %s, %d\n", pointerInitial4->accountName, pointerInitial4->accountPassword, pointerInitial4 ->identity);
			pointerInitial4++;
		}
	}
	//管理员文件存在
	else
	{
		fpManager = fopen("D:\\C Code\\2511class\\2511-C\\Project2-Ordering system\\Project2-Ordering system\\Manager.txt", "r");
		//更新管理员数组
		fscanf(fpManager, "%d", &dishTotal);
		managerTotalCount = dishTotal;
		while (managerTotalCount--)
		{
			fscanf(fpManager, "%s, %s, %d\n", &pointerInitial4->accountName, &pointerInitial4->accountPassword, &pointerInitial4 ->identity);
			pointerInitial4++;
		}
	}
	fclose(fpManager);
}



//1.菜单展示
void menuDisplay(Menu* dishMenu1, int dishTotal1)
{
	Menu* menuInitial = dishMenu1;
	printf("菜单如下：");
	while (dishTotal1)
	{
		printf("****************\n");
		printf("序号：%d\n", menuInitial->id);
		printf("菜名：%s\n", menuInitial->dishName);
		printf("价格：%.2f\n", menuInitial->price);
		if (menuInitial->inventory > 0)
		{
			printf("当前可下单!\n");
		}
		else
		{
			printf("该菜品当前已售罄！\n");
		}
		printf("已点份数：%d\n", menuInitial->order);
		menuInitial++;
		dishTotal1--;
	}
	printf("菜单展示完毕！\n********************\n");
}


//2.下单
void dishOrder(Menu* dishMenu2, int dishTotal2)
{
	Menu* menuInitial1 = dishMenu2;
	int orderId1 = -1, change1 = -1, orderTotal1 = 0;
	float totalAmount = 0.0;

	printf("请输入每道菜的序号下单：\n");
	while (orderId1)
	{
		printf("如下单完毕，输入“0”：\n");
		printf("请输入菜品序号：\n");
		scanf("%d", &orderId1);
		if (orderId1 < 0 || orderId1 >= dishTotal2)
		{
			printf("序号输入错误！\n");
			continue;
		}
		if (orderId1 == 0)
		{
			break;
		}
		//*******************goto语句1份额有错************************
		again1:printf("请输入下单份数：\n");
		scanf("%d", &orderTotal1);
		if (((menuInitial1 + orderId1 - 1)->inventory >= orderTotal1) && ((menuInitial1 + orderId1 - 1)->inventory > 0))
		{
			(menuInitial1 + orderId1 - 1)->inventory -= orderTotal1;
			(menuInitial1 + orderId1 - 1)->order += orderTotal1;
		}
		else if ((menuInitial1 + orderId1 - 1)->inventory == 0)
		{
			printf("该菜品已售罄！\n");
		}
		else
		{
			printf("%s当前最多可下单%d份，请重新确定份额！\n"
				, (menuInitial1 + orderId1 - 1)->dishName, (menuInitial1 + orderId1 - 1)->inventory);
			goto again1;
		}
	}
	while (change1)
	{
		printf("是否结算？\n是：输入“0”  否：输入其它任意数字\n");
		scanf("%d", &change1);
		switch (change1)
		{
		case 0:
			break;
		default:
			orderChange(dishMenu2, dishTotal2);
		}
	}
	totalAmount = billSettlement(dishMenu2, dishTotal2);
	printf("您消费的总金额为:%.2f\n", totalAmount);
	printf("请支付！\n");
}

//3.结算前的菜品改动
void orderChange(Menu* dishMenu3, int dishTotal3)
{
	Menu* menuInitial2 = dishMenu3;
	int orderId2 = 0, change2 = -1, orderTotal2 = 0;

	while (change2)
	{
		printf("请选择您想执行的操作：\n");
		printf("1.增加菜品  2.删除菜品  3.改变份额\n");
		printf("改动完毕，则输入“0”：\n");
		scanf("%d", &change2);
		switch (change2)
		{
		case 0:
			break;
		case 1:
			//1.增加
			printf("请输入菜品序号：\n");
			scanf("%d", &orderId2);
			if (orderId2 <= 0 || orderId2 >= dishTotal3)
			{
				printf("序号输入错误！\n");
				break;
			}
			//*******************goto语句2份额有错************************
		again2:printf("请输入下单份数：\n");
			scanf("%d", &orderTotal2);
			if (((menuInitial2 + orderId2 - 1)->inventory >= orderTotal2) && ((menuInitial2 + orderId2 - 1)->inventory > 0))
			{
				(menuInitial2 + orderId2 - 1)->inventory -= orderTotal2;
				(menuInitial2 + orderId2 - 1)->order += orderTotal2;
			}
			else if ((menuInitial2 + orderId2 - 1)->inventory == 0)
			{
				printf("该菜品已售罄！\n");
			}
			else
			{
				printf("%s当前最多可下单%d份，请重新确定份额！\n"
					, (menuInitial2 + orderId2 - 1)->dishName, (menuInitial2 + orderId2 - 1)->inventory);
				goto again2;
			}
			break;
		case 2:
			//2.删除
			printf("请输入菜品序号：\n");
			scanf("%d", &orderId2);
			if (orderId2 <= 0 || orderId2 >= dishTotal3)
			{
				printf("序号输入错误！\n");
				break;
			}
			if ((menuInitial2 + orderId2 - 1)->order == 0)
			{
				printf("该菜品不在您的订单中！\n");
				break;
			}
			(menuInitial2 + orderId2 - 1)->inventory = 10;
			(menuInitial2 + orderId2 - 1)->order = 0;
			printf("%s已从您的订单移除！\n", (menuInitial2 + orderId2 - 1)->dishName);
			break;
		case 3:
			//3.改份额
			printf("请输入菜品序号：\n");
			scanf("%d", &orderId2);
			if (orderId2 <= 0 || orderId2 >= dishTotal3)
			{
				printf("序号输入错误！\n");
				break;
			}
			if ((menuInitial2 + orderId2 - 1)->order == 0)
			{
				printf("该菜品不在您的订单中！\n");
				break;
			}
			//*******************goto语句3份额有错************************
		again3:printf("请输入修改之后的份额：\n");
			scanf("%d", &orderTotal2);
			(menuInitial2 + orderId2 - 1)->inventory = 10;
			if (((menuInitial2 + orderId2 - 1)->inventory >= orderTotal2) && ((menuInitial2 + orderId2 - 1)->inventory > 0))
			{
				(menuInitial2 + orderId2 - 1)->order = orderTotal2;
				(menuInitial2 + orderId2 - 1)->inventory -= orderTotal2;
				printf("修改完毕！\n");
			}
			else if ((menuInitial2 + orderId2 - 1)->inventory == 0)
			{
				printf("该菜品已售罄！\n");
			}
			else
			{
				printf("%s当前最多可下单%d份，请重新确定份额！\n"
					, (menuInitial2 + orderId2 - 1)->dishName, (menuInitial2 + orderId2 - 1)->inventory);
				goto again3;
			}
			break;
		default:
			printf("输入有误！请重新输入：\n");
		}
	}
}

//4.结算与账单生成
float billSettlement(Menu* dishMenu4, int dishTotal4)
{
	FILE* fpMenu2 = NULL;
	Menu* menuInital3 = dishMenu4;
	Menu* pointerInitial2 = dishMenu4;
	Bill* billGeneration2 = billGeneration;
	FILE* fpBill = NULL;
	int pointerMove = 0, bufferClear2 = 0;
	float totalAmount2 = 0.0, profitTotal = 0;

	fpBill = fopen("D:\\C Code\\2511class\\2511-C\\Project2-Ordering system\\Project2-Ordering system\\Bill.txt", "w");
	if (fpBill == NULL)
	{
		printf("账单生成失败！\n");
		exit(2);
	}
	while (((bufferClear2 = getchar()) != '\n') && (bufferClear2 != EOF));//清空缓冲区
	while (dishTotal4)
	{
		if (((menuInital3 + pointerMove)->order) > 0)
		{
			billOrderedCount++;
			(billGeneration2 + pointerMove)->orderBill = (menuInital3 + pointerMove)->order;
			fprintf(fpBill, "序号：%d\n菜名：%s\n单价：%.2f\n份数：%d\n***********\n",
				(billGeneration2 + pointerMove) ->idBill, (billGeneration2 + pointerMove) ->dishNameBill, (billGeneration2 + pointerMove) ->priceBill, (billGeneration2 + pointerMove) ->orderBill);
			totalAmount2 += (((billGeneration2 + pointerMove) ->orderBill) * ((billGeneration2 + pointerMove) ->priceBill));
			profitTotal += (((billGeneration2 + pointerMove)->orderBill) * ((billGeneration2 + pointerMove)->priceBill - (billGeneration2 + pointerMove)->costBill));
		}

		pointerMove++;
		dishTotal4--;
	}
	fprintf(fpBill, "总金额为：%.2f\n", totalAmount2);
	fprintf(fpBill, "总利润为：%.2f\n", profitTotal);
	fclose(fpBill);

	//更新菜单	
	//直接创建新菜单
	fpMenu2 = fopen("D:\\C Code\\2511class\\2511-C\\Project2-Ordering system\\Project2-Ordering system\\Menu.txt", "w");
	if (fpMenu2 == NULL)
	{
		perror("菜单创建失败！\n");
		exit(1);
	}
	fprintf(fpMenu2, "%d\n", dishTotal);
	dishTotal4 = dishTotal;
	while (dishTotal4--)
	{
		fprintf(fpMenu2, "%d, %s, %.2f, %d, %.2f\n", pointerInitial2->id, pointerInitial2->dishName, pointerInitial2->price, pointerInitial2->inventory, pointerInitial2->cost);
		pointerInitial2++;
	}
	fclose(fpMenu2);
	
	return totalAmount2;
}




//5.管理员登陆
void managerLogin(Manager* managerList, int managerTotal2)
{
	Manager* listInitial = managerList;
	int managerCount = managerTotal2;
	int trueFlag = 0, inputFrequency = 3, bufferClear1 = 0;
	char accountName2[20] = "";
	char accountPassword2[20] = "";
	char* enterDelete = NULL;

	while (((bufferClear1 = getchar()) != '\n') && (bufferClear1 != EOF));//清空缓冲区
	while (inputFrequency && trueFlag == 0)
	{
		printf("请输入账号：\n");
		
		if (fgets(accountName2, 20, stdin) == NULL)
		{
			printf("输入发生错误！\n");
			exit(1);
		}
		enterDelete = strchr(accountName2, '\n');
		//去掉换行符
		if (enterDelete != NULL)
		{
			*enterDelete = '\0';
		}
		printf("请输入密码：\n");
		if (fgets(accountPassword2, 20, stdin) == NULL)
		{
			printf("输入发生错误！\n");
			exit(1);
		}
		//去换行符2
		enterDelete = NULL;
		enterDelete = strchr(accountPassword2, '\n');
		if (enterDelete != NULL)
		{
			*enterDelete = '\0';
		}
		managerCount = managerTotal2;
		listInitial = managerList;
		while (managerCount)
		{
			if (strcmp(listInitial->accountName, accountName2) == 0)
			{
				if (strcmp(listInitial->accountPassword, accountPassword2) == 0)
				{
					trueFlag = 1;
					if (listInitial->identity == 0)
					{
						printf("欢迎您！普通管理员！\n");
						//1.nor管理员功能模块
						normalManager();
						printf("退出成功！\n");
						break;
					}
					else
					{
						printf("欢迎您！超级管理员！\n");
						//2.sup管理员功能模块
						superManager();
						printf("退出成功！\n");
						break;
					}
				}
			}
			managerCount--;
			listInitial++;
		}
		inputFrequency--;
		if (trueFlag == 0 && inputFrequency > 0)
		{
			printf("账号或密码输入有误！\n还有%d次机会！请重新输入：\n", inputFrequency);
		}
	}
	if (inputFrequency == -1 && trueFlag == 0)
	{
		printf("登陆失败！自动退出登录界面！\n");
	}
}

//1.普通管理员
void normalManager()
{
	int choice3 = -1;

	while (choice3)
	{
		printf("1.查看菜单  2.更新菜单 3.查看用户账单 0.退出\n");
		printf("请选择您要执行的操作：\n");
		scanf("%d", &choice3);
		switch (choice3)
		{
		case 0:
			break;
		case 1:
			//1.查看菜单
			menuDisplayManager(dishMenu, dishTotal);
			break;
		case 2:
			//2.更新菜单
			menuUpdate(dishMenu, dishTotal);
			break;
		case 3:
			//3.查看用户账单
			billDisplay();
			break;
		default:
			printf("输入有误！请重新输入：\n");
		}
	}
}




//2.超级管理员

void superManager()
{
	int choice5 = -1;

	while (choice5)
	{
		printf("1.查看菜单  2.更新菜单 3.查看用户账单 4. 管理员操作 0.退出\n");
		printf("请选择您要执行的操作：\n");
		scanf("%d", &choice5);
		switch (choice5)
		{
		case 0:
			break;
		case 1:
			//1.查看菜单
			menuDisplayManager(dishMenu, dishTotal);
			break;
		case 2:
			//2.更新菜单
			menuUpdate(dishMenu, dishTotal);
			break;
		case 3:
			//3.查看用户账单
			billDisplay();
			break;
		case 4:
			//4.管理员操作
			managementAdministrator();
			break;
		default:
			printf("输入有误！请重新输入：\n");
		}
	}
}


//1.manager查看菜单
void menuDisplayManager(Menu* dishMenu5, int dishTotal5)
{
	Menu* menuInitia5 = dishMenu5;
	printf("菜单如下：");
	while (dishTotal5)
	{
		printf("****************\n");
		printf("序号：%d\n", menuInitia5->id);
		printf("菜名：%s\n", menuInitia5->dishName);
		printf("价格：%.2f\n", menuInitia5->price);
		printf("库存：% d\n", menuInitia5->inventory);
		printf("当前已下单：% d\n", menuInitia5->order);
		printf("成本：% .2f\n", menuInitia5->cost);
		menuInitia5++;
		dishTotal5--;
	}
	printf("菜单展示完毕！\n****************\n");
}


//2.更新菜单
void menuUpdate(Menu* dishMenu6, int dishTotal6)
{
	FILE* fpMenu3 = NULL;
	Menu* menuInitial6 = dishMenu6;
	Menu* pointerInitial3 = dishMenu6;
	Bill* billInitial6 = billGeneration;
	int choice4 = -1, bufferClear2, originalId = 0, inventoryNew = 0, inventoryAdd = 0;
	float dishPriceNew = 0, dishAddPrice = 0, dishAddCost = 0;
	char dishNameNew[20] = "";
	char dishAddName[20] = "";
	char* enterDelete2 = NULL;

	while (choice4)
	{

		printf("1.更改菜名 2.更改价格 3.更新库存 4. 新增菜品 0.退出\n");
		printf("请选择您要对菜单执行的操作：\n");
		scanf("%d", &choice4);
		while (((bufferClear2 = getchar()) != '\n') && (bufferClear2 != EOF));//清空缓冲区
		switch (choice4)
		{
		case 0:
			break;
		case 1:
			//1.菜名
			printf("请输入您想更改的菜品序号(1 - %d)：\n", dishTotal);
			scanf("%d", &originalId);
			while (((bufferClear2 = getchar()) != '\n') && (bufferClear2 != EOF));//清空缓冲区
			if (originalId <= 0 || originalId > dishTotal)
			{
				printf("序号输入错误！\n");
				break;
			}
			printf("该菜品为%s：\n", (menuInitial6 + originalId - 1)->dishName);
			printf("请输入更改后的菜名：\n");
			if (fgets(dishNameNew, 20, stdin) == NULL)
			{
				printf("输入发生错误！\n");
				exit(1);
			}
			//去换行符3
			enterDelete2 = strchr(dishNameNew, '\n');
			if (enterDelete2 != NULL)
			{
				*enterDelete2 = '\0';
			}
			if (strcpy((menuInitial6 + originalId - 1)->dishName, dishNameNew) == NULL)
			{
				printf("菜名录入发生错误！\n");
				exit(3);
			}
			printf("更改成功！\n");
			printf("第%d道菜目前名为：%s\n", originalId, (menuInitial6 + originalId - 1)->dishName);
			break;
		case 2:
			//2..价格
			printf("请输入您想更改的菜品序号(1 - %d)：\n", dishTotal);
			scanf("%d", &originalId);
			while (((bufferClear2 = getchar()) != '\n') && (bufferClear2 != EOF));//清空缓冲区
			if (originalId <= 0 || originalId > dishTotal)
			{
				printf("序号输入错误！\n");
				break;
			}
			printf("该菜品为%s： , 售价为：%.2f\n", (menuInitial6 + originalId - 1)->dishName, (menuInitial6 + originalId - 1) ->price);
			printf("请输入更改后的价格：\n");
			scanf("%f", &dishPriceNew);
			while (((bufferClear2 = getchar()) != '\n') && (bufferClear2 != EOF));//清空缓冲区
			(menuInitial6 + originalId - 1)->price = dishPriceNew;
			printf("价格更改成功！\n");
			printf("%s目前售价为：%.2f\n", (menuInitial6 + originalId - 1)->dishName, (menuInitial6 + originalId - 1) ->price);
			break;
		case 3:
			//3.库存
			printf("请输入您想更改的菜品序号(1 - %d)：\n", dishTotal);
			scanf("%d", &originalId);
			while (((bufferClear2 = getchar()) != '\n') && (bufferClear2 != EOF));//清空缓冲区
			if (originalId <= 0 || originalId > dishTotal)
			{
				printf("序号输入错误！\n");
				break;
			}
			printf("该菜品为%s： , 库存剩余：%d\n", (menuInitial6 + originalId - 1)->dishName, (menuInitial6 + originalId - 1)->inventory);
			printf("请输入更新后的库存：\n");
			scanf("%d", &inventoryNew);
			while (((bufferClear2 = getchar()) != '\n') && (bufferClear2 != EOF));//清空缓冲区
			(menuInitial6 + originalId - 1)->inventory = inventoryNew;
			printf("库存更新成功！\n");
			printf("%s目前库存剩余：%d\n", (menuInitial6 + originalId - 1)->dishName, (menuInitial6 + originalId - 1)->inventory);
			break;
		case 4:
			//4.新菜
			//更新menu数组
			printf("当前菜单中共有%d道菜\n", dishTotal);
			dishTotal++;
			(menuInitial6 + dishTotal - 1)->id = dishTotal;
			(menuInitial6 + dishTotal - 1)->order = 0;
			printf("请分别输入新增菜的信息：\n");
			printf("请输入第%d道菜的菜名：\n", dishTotal);
			if (fgets(dishAddName, 20, stdin) == NULL)
			{
				printf("输入发生错误！\n");
				exit(1);
			}
			//去换行符4
			enterDelete2 = NULL;
			enterDelete2 = strchr(dishAddName, '\n');
			if (enterDelete2 != NULL)
			{
				*enterDelete2 = '\0';
			}
			if (strcpy((menuInitial6 + dishTotal - 1)->dishName, dishAddName) == NULL)
			{
				printf("菜名录入发生错误！\n");
				exit(3);
			}
			printf("请输入售价：\n");
			scanf("%f", &dishAddPrice);
			while (((bufferClear2 = getchar()) != '\n') && (bufferClear2 != EOF));//清空缓冲区
			(menuInitial6 + dishTotal - 1)->price = dishAddPrice;
			printf("请输入该菜品库存：\n");
			scanf("%d", &inventoryAdd);
			while (((bufferClear2 = getchar()) != '\n') && (bufferClear2 != EOF));//清空缓冲区
			(menuInitial6 + dishTotal - 1)->inventory = inventoryAdd;
			printf("请输入该菜品成本：\n");
			scanf("%f", &dishAddCost);
			while (((bufferClear2 = getchar()) != '\n') && (bufferClear2 != EOF));//清空缓冲区
			(menuInitial6 + dishTotal - 1)->cost = dishAddCost;
			//更新bill数组
			(billGeneration + dishTotal - 1)->idBill = (menuInitial6 + dishTotal - 1)->id;
			if (strcpy((billGeneration + dishTotal - 1)->dishNameBill, (menuInitial6 + dishTotal - 1)->dishName) == NULL)
			{
				printf("菜名录入发生错误！\n");
				exit(3);
			}
			(billGeneration + dishTotal - 1)->priceBill = (menuInitial6 + dishTotal - 1)->price;
			(billGeneration + dishTotal - 1)->orderBill = (menuInitial6 + dishTotal - 1)->order;
			(billGeneration + dishTotal - 1)->costBill = (menuInitial6 + dishTotal - 1)->cost;
			printf("新增菜品信息已成功录入菜单！\n");
			printf("以下为该菜品完整信息：\n");
			printf("****************\n");
			printf("序号：%d\n", (menuInitial6 + dishTotal - 1)->id);
			printf("菜名：%s\n", (menuInitial6 + dishTotal - 1)->dishName);
			printf("价格：%.2f\n", (menuInitial6 + dishTotal - 1)->price);
			printf("库存：% d\n", (menuInitial6 + dishTotal - 1)->inventory);
			printf("当前已下单：% d\n", (menuInitial6 + dishTotal - 1)->order);
			printf("成本：% .2f\n", (menuInitial6 + dishTotal - 1)->cost);
			printf("****************\n");
			break;
		default:
			printf("输入有误！请重新输入：\n");
		}
	}
	//直接创建新菜单
	fpMenu3 = fopen("D:\\C Code\\2511class\\2511-C\\Project2-Ordering system\\Project2-Ordering system\\Menu.txt", "w");
	if (fpMenu3 == NULL)
	{
		perror("菜单创建失败！\n");
		exit(1);
	}
	fprintf(fpMenu3, "%d\n", dishTotal);
	dishTotal6 = dishTotal;
	while (dishTotal6--)
	{
		fprintf(fpMenu3, "%d, %s, %.2f, %d, %.2f\n", pointerInitial3->id, pointerInitial3->dishName, pointerInitial3->price, pointerInitial3->inventory, pointerInitial3->cost);
		pointerInitial3++;
	}
	fclose(fpMenu3);
}





//3.查看用户账单
void billDisplay()
{
	int readCount = 0;
	char readGap[20];

	printf("以下是顾客账单信息：\n");
	FILE* fpReadBill = fopen("D:\\C Code\\2511class\\2511-C\\Project2-Ordering system\\Project2-Ordering system\\Bill.txt", "r");
	if (fpReadBill == NULL)
	{
		printf("账单文件读取失败！\n");
		exit(2);
	}
	readCount = 102;
	while (readCount--)
	{
		if (fscanf(fpReadBill, "%s", &readGap) != EOF)
		{
			printf("%s\n", readGap);
		}
		else
		{
			break;
		}
	}
	fclose(fpReadBill);
}


//4.管理员操作
void managementAdministrator()
{
	int choice6 = -1, bufferClear3 = 0, managerNum = 0;
	char accountAddName[20] = "";
	char accountAddPassword[20] = "";
	char* enterDelete3 = NULL;
	Manager* pointerInitial5 = restaurantManager;
	FILE* fpManager2 = NULL;
	int managerTotalCount2 = managerTotal;

	while (choice6)
	{
		printf("请问您要对普通管理员执行什么操作：\n");
		printf("1.增加普通管理员 \n2.修改管理员账号密码\n3.查找管理员账号密码\n0.退出\n");
		scanf("%d", &choice6);
		while (((bufferClear3 = getchar()) != '\n') && (bufferClear3 != EOF));//清空缓冲区

		switch (choice6)
		{
		case 0:
			break;
		case 1:
			//1.增加
			printf("当前有%d个普通管理员\n", managerTotal - 1);
			managerTotal++;
			printf("请输入第%d个管理员的信息：\n", managerTotal);
			(restaurantManager + managerTotal - 1)->identity = 0;
			printf("请输入账号：\n");
			if (fgets(accountAddName, 20, stdin) == NULL)
			{
				printf("输入发生错误！\n");
				exit(1);
			}
			//去换行符5
			enterDelete3 = strchr(accountAddName, '\n');
			if (enterDelete3 != NULL)
			{
				*enterDelete3 = '\0';
			}
			if (strcpy((restaurantManager + managerTotal - 1) ->accountName, accountAddName) == NULL)
			{
				printf("账号录入发生错误！\n");
				exit(3);
			}
			printf("请输入密码：\n");
			if (fgets(accountAddPassword, 20, stdin) == NULL)
			{
				printf("输入发生错误！\n");
				exit(1);
			}
			//去换行符6
			enterDelete3 = NULL;
			enterDelete3 = strchr(accountAddPassword, '\n');
			if (enterDelete3 != NULL)
			{
				*enterDelete3 = '\0';
			}
			if (strcpy((restaurantManager + managerTotal - 1)->accountPassword, accountAddPassword) == NULL)
			{
				printf("密码录入发生错误！\n");
				exit(3);
			}
			printf("录入完毕！以下是新增普通管理员账号密码：\n");
			printf("****************\n");
			printf("账号：%s\n", (restaurantManager + managerTotal - 1) ->accountName);
			printf("密码：%s\n", (restaurantManager + managerTotal - 1) ->accountPassword);
			printf("****************\n");
			break;
		case 2:
			//2.修改
			printf("请输入要修改第几位管理员的账号密码（2 - %d）：\n", managerTotal);
			scanf("%d", &managerNum);
			while (((bufferClear3 = getchar()) != '\n') && (bufferClear3 != EOF));//清空缓冲区
			printf("请输入修改后的账号：\n");
			if (fgets(accountAddName, 20, stdin) == NULL)
			{
				printf("输入发生错误！\n");
				exit(1);
			}
			//去换行符7
			enterDelete3 = NULL;
			enterDelete3 = strchr(accountAddName, '\n');
			if (enterDelete3 != NULL)
			{
				*enterDelete3 = '\0';
			}
			if (strcpy((restaurantManager + managerNum - 1)->accountName,accountAddName) == NULL)
			{
				printf("账号录入发生错误！\n");
				exit(3);
			}
			printf("请输入修改后的密码：\n");
			if (fgets(accountAddPassword, 20, stdin) == NULL)
			{
				printf("输入发生错误！\n");
				exit(1);
			}
			//去换行符8
			enterDelete3 = NULL;
			enterDelete3 = strchr(accountAddPassword, '\n');
			if (enterDelete3 != NULL)
			{
				*enterDelete3 = '\0';
			}
			if (strcpy((restaurantManager + managerNum - 1)->accountPassword, accountAddPassword) == NULL)
			{
				printf("密码录入发生错误！\n");
				exit(3);
			}
			printf("修改完毕！以下是修改后的普通管理员账号密码：\n");
			printf("****************\n");
			printf("账号：%s\n", (restaurantManager + managerNum - 1)->accountName);
			printf("密码：%s\n", (restaurantManager + managerNum - 1)->accountPassword);
			printf("****************\n");
			break;
		case 3:
			//3.查找
			printf("请输入要查找第几位普通管理员（2 - %d）：\n", managerTotal);
			scanf("%d", &managerNum);
			while (((bufferClear3 = getchar()) != '\n') && (bufferClear3 != EOF));//清空缓冲区
			printf("以下是第%d位普通管理员账号密码：\n", managerNum);
			printf("****************\n");
			printf("账号：%s\n", (restaurantManager + managerNum - 1)->accountName);
			printf("密码：%s\n", (restaurantManager + managerNum - 1)->accountPassword);
			printf("****************\n");
			break;
		default:
			printf("输入有误！请重新输入：\n");
		}
	}
	//直接创建管理员列表
	fpManager2 = fopen("D:\\C Code\\2511class\\2511-C\\Project2-Ordering system\\Project2-Ordering system\\Manager.txt", "w");
	if (fpManager2 == NULL)
	{
		perror("菜单创建失败！\n");
		exit(1);
	}
	fprintf(fpManager2, "%d\n", managerTotal);
	while (managerTotalCount2--)
	{
		fprintf(fpManager2, "%s, %s, %d\n", pointerInitial5->accountName, pointerInitial5->accountPassword, pointerInitial5 ->identity);
		pointerInitial5++;
	}
	fclose(fpManager2);
}

