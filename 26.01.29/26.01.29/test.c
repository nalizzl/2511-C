#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>

//int main()
//{
//	printf("%.2f\n", 5.125);
//	return 0;
//}


//
//int main() {
//    int dec = 255;
//    unsigned int udec = 255; // 无符号十进制
//
//    printf("===== 十进制转其他进制 =====\n");
//    printf("十进制 %d -> 八进制（纯数字）：%o\n", dec, dec);
//    printf("十进制 %d -> 八进制（带前缀）：%#o\n", dec, dec);
//    printf("十进制 %d -> 十六进制小写（纯数字）：%x\n", dec, dec);
//    printf("十进制 %d -> 十六进制小写（带前缀）：%#x\n", dec, dec);
//    printf("十进制 %d -> 十六进制大写（带前缀）：%#X\n", dec, dec);
//    printf("无符号十进制 %u -> 十六进制：%#x\n", udec, udec);
//
//    return 0;
//}





//int main()
//{
//	int i, j = 0;
//	int b[20] = { 0 };
//	scanf("%d", &i);
//	for (; i >= 0; j++)
//	{
//		if (i == 0 || i == 1)
//		{
//			b[j] = i;
//			j++;
//			break;
//		}
//		b[j] = i % 2;
//		i /= 2;
//	}
//	for (j -= 1; j >= 0; j--)
//	{
//		printf("%d ", b[j]);
//	}
//	return 0;
//}


//int main()
//{
//	char str[128];
//	scanf("%s", str);
//	size_t i = strlen(str);
//	for (int j = 0; i > 0; i--)
//	{
//		if (str[j] >= 97 && str[j] <=122)
//		{
//			str[j] -= 32;
//		}
//		else if(str[j] >= 65 && str[j] <= 90)
//		{
//			str[j] += 32;
//		}
//		j++;
//	}
//	printf("%s", str);
//	return 0;
//}

