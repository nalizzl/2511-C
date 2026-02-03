#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//int main()
//{
//	int i = 0;
//	float tmp, arr[20];
//	while (i < 20)
//	{
//		scanf("%f", arr + i);
//		i++;
//	}
//	i--;
//	for (int j = 0; j < i; )
//	{
//		tmp = *(arr + j);
//		*(arr + j) = *(arr + i);
//		*(arr + i) = tmp;
//		i--;
//		j++;
//	}
//	for (int k = 0; k < 20; k++)
//	{
//		printf("%.1f ", *(arr + k));
//	}
//	return 0;
//}


//int main()
//{
//	char arr1[5][20], *p[5] = {NULL}, **p2 = NULL;
//	int i = 0, j = 0;
//	for ( i = 0; i < 5; i++)
//	{
//		scanf("%s", arr1 + i);
//		p[i] = arr1[i];
//	}
//	p2 = p;
//	for ( j = 1; j < 5; j++)
//	{
//		if (strcmp(*p2, p[j]) <= 0)
//		{
//			p2 = p + j;
//		}
//	}
//	printf("%s", *p2);
//	return 0;
//}





//int main()
//{
//	int flag = -1;
//	char *p1 = NULL, *arr[4] = { "banana", "apple", "cherry", "date" };
//	while (flag)
//	{
//		flag = 0;
//		for (int i = 0; i < 3; i++)
//		{
//			if (strcmp(arr[i], arr[i + 1]) >= 0)
//			{
//				p1 = arr[i];
//				arr[i] = arr[i + 1];
//				arr[i + 1] = p1;
//				flag++;
//			}
//		}
//	}
//		
//	for (int j = 0; j < 4; j++)
//	{
//		printf("%s  ", arr[j]);
//	}
//	return 0;
//}


//char* my_strcat(char* p1, const char* p2)
//{
//	char* p3 = p1;
//	while (*p1 != '\0')
//	{
//		p1++;
//	}
//	while (*p1++ = *p2++);
//	return p3;
//}
//int main()
//{
//
//	char arr1[50], arr2[50];
//	scanf("%s %s", arr1, arr2);
//	char *p4 = my_strcat(arr1, arr2);
//	printf("%s", p4);
//	return 0;
//}