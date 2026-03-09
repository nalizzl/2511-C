#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//int swap(int a, int b)
//{
//	printf("%d %d\n", a, b);
//	a = 30;
//	b = 50;
//	return a >= b ? a : b;
//}
//float swap2(float* a, float* b)
//{
//	printf("%.2f %.5f\n", *a, *b);
//	return *a >= *b ? *a : *b;
//}
//int main()
//{
//	float a = 3.14, b = 3.14159;
//	int ret = 0;
//	ret = swap(a, b);
//	printf("%d %d %d\n", a, b, ret);
//	float ret2 = swap2(&a, &b);
//	printf("%.2f %.5f %.5f\n", a, b, ret2);
//	return 0;
//}


//float 的二进制存储方式为IEEE754，使用%d打印会直接用解读int二进制的方式强行解读
//float swap(float* a, float* b);
//int main() {
//	float a = 3.14, b = 3.14159, result;
//	result = swap(&a, &b);
//	printf("%f %f %d\n", a, b, result);
//	float i = 50;
//	printf("%d %f", i, i);
//	return 0;
//}
//float swap(float* a, float* b) {
//	*a = 30;
//	*b = 50;
//	return *a >= *b ? *a : *b;
//}



//void test(int a, int b, int c)
//{
//	printf("%d %d %d\n", a, b, c);
//}
//
//void main()
//{
//	int i;
//	i = 3;
//	test(i, ++i, i);
//	i = 3;
//	test(i, i++, i);
//}



//void func1(int a, int b, int *sum, int * diff)
//{
//	if (a >= b)
//	{
//		*sum = a * a + b * b;
//		*diff = a - b;
//	}
//	printf("%d %d %d %d\n", a, b, *sum, *diff);
//}
//
//int main()
//{
//	int a, b, sum, diff;
//	scanf("%d%d", &a, &b);
//	func1(a, b, &sum, &diff);
//	printf("%d %d %d %d\n", a, b, sum, diff);
//	return 0;
//}