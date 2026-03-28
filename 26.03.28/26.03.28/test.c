#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//int main()
//{
//	int i = 23;
//	char freadBill[14] = "";
//	FILE* fpRead = fopen("D:\\C Code\\2511class\\2511-C\\Project2-Ordering system\\Project2-Ordering system\\Bill.txt", "rb");
//	FILE* fpWrite = fopen("D:\\C Code\\2511class\\2511-C\\26.03.28\\26.03.28\\fWrite.txt", "wb");
//	while (i--)
//	{
//		if (fread(freadBill, 12, 1, fpRead) != EOF)
//		{
//			fwrite(freadBill, 12, 1, fpWrite);
//		}
//	}
//	
//	fclose(fpRead);
//	fclose(fpWrite);
//	return 0;
//}


typedef struct
{
	int idBill;//序号
	char dishNameBill[20];//菜名
	float priceBill;//价格
	int orderBill;//下单份额
}Bill;

Bill billTest[5] = {0};


//int main()
//{
//	char buffer1[50] = "";
//	
//	FILE* fpTest1 = fopen("D:\\C Code\\2511class\\2511-C\\26.03.28\\26.03.28\\fWrite.txt", "r");
//	if (fpTest1 == NULL)
//	{
//		perror("cannot open\n");
//		exit(1);
//	}
//	FILE* fpTest2 = fopen("D:\\C Code\\2511class\\2511-C\\26.03.28\\26.03.28\\fWriteTest2.txt", "w");
//	if (fpTest2 == NULL)
//	{
//		perror("cannot open\n");
//		exit(2);
//	}
//	fscanf(fpTest1, "%d %s %f %d ", &(billTest[0].idBill), &(billTest[0].dishNameBill), &(billTest[0].priceBill), &(billTest[0].orderBill));
//	fprintf(fpTest2, "%d\n%s\n%.2f\n%d ", billTest[0].idBill, billTest[0].dishNameBill, billTest[0].priceBill, billTest[0].orderBill);
//
//	return 0;
//}



//int main()
//{
//	char inputFile[20] = "Hello! Bit!";
//	char readFile[20] = "";
//	FILE* fpTest3 = NULL;
//
//	fpTest3 = fopen("D:\\C Code\\2511class\\2511-C\\26.03.28\\26.03.28\\fTest3.txt", "w");
//	if (fpTest3 == NULL)
//	{
//		perror("cannot open!\n");
//		exit(1);
//	}
//	fprintf(fpTest3, "%s", inputFile);
//	fclose(fpTest3);
//	fpTest3 = fopen("D:\\C Code\\2511class\\2511-C\\26.03.28\\26.03.28\\fTest3.txt", "r");
//	if (fpTest3 == NULL)
//	{
//		perror("cannot open!\n");
//		exit(2);
//	}
//	fseek(fpTest3, -6L, 2);
//	fread(readFile, 1, 6, fpTest3);
//	printf("%s\n", readFile);
//	fclose(fpTest3);
//	return 0;
//}



#include<string.h>

int main()
{
	char inputchr[20] = "";
	char inputStr[20] = "";
	char output[40] = "";
	char seek[2] = "#";
	FILE* fpTest4 = NULL;
	char* enterDelete = NULL;
	char* mark = NULL;
	long lenStr = 0;

	fpTest4 = fopen("D:\\C Code\\2511class\\2511-C\\26.03.28\\26.03.28\\fTest4.txt", "w");
	if (fpTest4 == NULL)
	{
		perror("cannot open!\n");
		exit(1);
	}
	if (fgets(inputchr, 20, stdin) != NULL)
	{
		//去\n
		enterDelete = strchr(inputchr, '\n');
		if (enterDelete != NULL)
		{
			*enterDelete = '\0';
		}
	}
	fprintf(fpTest4, "%s", inputchr);
	fclose(fpTest4);
	mark = strstr(inputchr, seek);
	mark++;
	lenStr = mark - inputchr;
	fpTest4 = fopen("D:\\C Code\\2511class\\2511-C\\26.03.28\\26.03.28\\fTest4.txt", "r+");//ps:使用a追加会直接从文件末尾开始，无法实现在#后面还有字符的情况下覆盖后面的内容！
	if (fpTest4 == NULL)
	{
		perror("cannot open!\n");
		exit(2);
	}
	fseek(fpTest4, lenStr, 0);

	if (fgets(inputStr, 20, stdin) != NULL)
	{
		//去\n
		enterDelete = strchr(inputStr, '\n');
		if (enterDelete != NULL)
		{
			*enterDelete = '\0';
		}
	}
	fprintf(fpTest4, "%s", inputStr);

	fclose(fpTest4);

	fpTest4 = fopen("D:\\C Code\\2511class\\2511-C\\26.03.28\\26.03.28\\fTest4.txt", "r");
	if (fpTest4 == NULL)
	{
		perror("cannot open!\n");
		exit(3);
	}
	fread(output, 40, 1, fpTest4);
	printf("%s", output);
	fclose(fpTest4);
	return 0;
}