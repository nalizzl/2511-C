#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char arr[20] = "";
	FILE* fp1 = NULL;
	fp1 = fopen("D:\\C Code\\2511class\\2511-C\\26.03.23\\1.txt", "w");
	if (fp1 == NULL)
	{
		printf("cannot open file\n");
		exit(1);
	}
	if (fputs("hello bit!", fp1) == EOF)
	{
		printf("fail!\n");
		exit(2);
	}
	fclose(fp1);
	
	fp1 = fopen("D:\\C Code\\2511class\\2511-C\\26.03.23\\1.txt", "r");
	if (fp1 == NULL)
	{
		printf("cannot open file\n");
		exit(1);
	}
	if(fgets(arr, 20, fp1) != NULL)
	{
		printf("%s\n", arr);
	}

	fclose(fp1);
	return 0;
}