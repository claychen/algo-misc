/*
 * This program is modified from 
 * http://zh.wikipedia.org/wiki/%E5%BD%92%E5%B9%B6%E6%8E%92%E5%BA%8F
 */
/*=============================================================================
#
#     FileName: merge_sort_in_c.c
#         Desc: 归并排序
#
#       Author: gavinyao
#        Email: gavinyao_tencent.com
#
#      Created: 2013-12-25 23:55:02
#      Version: 0.0.1
#      History:
#               0.0.1 | gavinyao | 2013-12-25 23:55:02 | initialization
#
=============================================================================*/
#include <stdio.h>
#include <stdlib.h> // rand sranddev
#include <time.h>

#define DEBUG 1
#define SORT_NUM 10
 
void print_array(int *list, int len);
void merge_array(int *list1, int list1_size, int *list2, int list2_size);
 
/**
 * @brief 归并排序
 *
 * @param *list 要排序的数组
 * @param n 数组中的元素数量
 */
void merge_sort(int *list, int list_size)
{
    if (list_size > 1)
    {
        // 把数组平均分成两个部分
        int *list1 = list;
        int list1_size = list_size / 2;
        int *list2 = list + list_size / 2;
        int list2_size = list_size - list1_size;
        // 分别归并排序
        merge_sort(list1, list1_size);
        merge_sort(list2, list2_size);
 
        // 归并
        merge_array(list1, list1_size, list2, list2_size);
    }
}
 
/**
 * @brief 归并两个有序数组
 *
 * @param list1
 * @param list1_size
 * @param list2
 * @param list2_size
 */
void merge_array(int *list1, int list1_size, int *list2, int list2_size)
{
    int i, j, k;
    i = j = k = 0;
 
    // 声明临时数组用于存储归并结果
    int *list = malloc((list1_size + list2_size)*sizeof(int));
 
    // note: 只要有一个数组到达了尾部就要跳出
    // 也就是说只有两个都没有到达尾部的时候才执行这个循环
    while (i < list1_size && j < list2_size)
    {
        // 把较小的那个数据放到结果数组里， 同时移动指针
        list[k++] = list1[i] < list2[j] ? list1[i++] : list2[j++];
    }
 
    // 如果 list1 还有元素，把剩下的数据直接放到结果数组
    while (i < list1_size)
    {
        list[k++] = list1[i++];
    }
 
    // 如果 list2 还有元素，把剩下的数据直接放到结果数组
    while (j < list2_size)
    {
        list[k++] = list2[j++];
    }
 
    // 把结果数组 copy 到 list1 里
    for (int ii = 0; ii < (list1_size + list2_size); ++ii)
    {
        list1[ii] = list[ii];
    }
    free(list);
 
}
 
/**
 * @brief 打印数组
 *
 * @param list[]
 * @param len
 */
void print_array(int *list, int len)
{
    int i;
    for (i = 0; i < len; ++i)
    {
        // printf("%3d", *(list+i));
        printf("%3d", list[i]);
        if (i < len - 1)
            printf(" ");
    }
    printf("\n");
}
 
int main(void)
{
    int len = SORT_NUM;
    int list[len];
    srand(time(NULL));
    for (int i = 0; i < len; ++i)
    {
	//sranddev();
        list[i] = rand() % (SORT_NUM * SORT_NUM);
    }
 
    print_array(list, len);
    merge_sort(list, len);
    print_array(list, len);
 
    return 0;
}

