#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//int main() {
//    int a[3][5] = {
//        {0, 1, 2, 3, 4},
//        {5, 6, 7, 8, 9},
//        {10, 11, 12, 13, 14}
//    };
//
//    //int *p = a;
//    int (*p)[5] = a;
//
//    //printf("%d\n", *(p + 1 * 5 + 2));
//    printf("%d\n", *(*(p + 1) + 2));
//    return 0;
//}



#include <stdio.h>

int main()
{
    /************************ 1. 二维数组 + 字符串：存储联系人数据 ************************/
    char contacts_names[5][20] = { "Zhang San", "Li Si", "Wang Wu", "Zhao Liu", "Chen Qi" };
    char contacts_phones[5][15] = { "13800138000", "13900139000", "13700137000", "13600136000", "13500135000" };

    /************************ 2. 一维指针数组 + 指针：指向二维数组行 ************************/
    char* p_names[5];
    char* p_phones[5];
    int i;
    char** pp_temp1 = (char**)p_names;
    char** pp_temp2 = (char**)p_phones;
    for (i = 0; i < 5; i++)
    {
        *pp_temp1 = contacts_names[i];
        *pp_temp2 = contacts_phones[i];
        pp_temp1++;
        pp_temp2++;
    }

    /************************ 3. 二级指针 + 一维数组：批量打印所有联系人 ************************/
    printf("==================== 全部联系人信息 ====================\n");
    char** pp_cur_name = p_names;
    char** pp_cur_phone = p_phones;
    int count = 0;
    while (count < 5)
    {
        printf("联系人%2d：姓名 = %-12s  电话 = %s\n", count + 1, *pp_cur_name, *pp_cur_phone);
        pp_cur_name++;
        pp_cur_phone++;
        count++;
    }

    /************************ 4. 指针 + 字符串 + 一维数组：用户查询功能（修复输入问题） ************************/
    printf("\n==================== 联系人查询功能 ====================\n");
    char input_name[20] = { 0 };
    printf("请输入要查询的联系人姓名：");

    // 【修改点1】替换scanf为fgets，支持读取带空格的字符串
    fgets(input_name, sizeof(input_name), stdin);

    // 【修改点2】手动去除fgets读取到的换行符（fgets会把回车"\n"也存入数组）
    char* p_newline = input_name;  // 指针遍历输入字符串，寻找换行符
    while (*p_newline != '\0')
    {
        if (*p_newline == '\n')
        {
            *p_newline = '\0';  // 把换行符替换为字符串结束符'\0'，不影响后续比较
            break;
        }
        p_newline++;  // 指针偏移，继续查找
    }

    char* p_input = input_name;
    int find_flag = 0;
    pp_cur_name = p_names;
    pp_cur_phone = p_phones;
    count = 0;

    while (count < 5)
    {
        char* p_cur_name = *pp_cur_name;
        char* p_temp_input = p_input;
        int is_match = 1;

        while (*p_temp_input != '\0' && *p_cur_name != '\0')
        {
            if (*p_temp_input != *p_cur_name)
            {
                is_match = 0;
                break;
            }
            p_temp_input++;
            p_cur_name++;
        }

        if (*p_temp_input != '\0' || *p_cur_name != '\0')
        {
            is_match = 0;
        }

        if (is_match == 1)
        {
            printf("查询成功！\n");
            printf("姓名：%s  电话：%s\n", *pp_cur_name, *pp_cur_phone);
            find_flag = 1;
            break;
        }

        pp_cur_name++;
        pp_cur_phone++;
        count++;
    }

    if (find_flag == 0)
    {
        printf("查询失败！未找到姓名为\"%s\"的联系人。\n", input_name);
    }

    return 0;
}