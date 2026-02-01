#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#define PI 3.14159
void test()
{
	static int b = 20;
	printf("%d ", b);
	b--;
}
int main()
{
	/*int R = 0;
	scanf("%d", &R);
	float C = PI * 2 * R;
	printf("C = %f", C);
	const int a = 20;
	printf("%d ", a);*/
	test();
	int b = 0;
	printf("%d ", b);
	test();
	printf("%d", b);
	return 0;
}