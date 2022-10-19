#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 链表结构体 */
typedef struct list
{
    int val;
    struct list *next;
} list_t;


/**
 * @brief 把数组转换成链表
 * @param arr 要转换的数组
 * @param size 数组长度
 * @return 成功返回链表地址/失败返回NULL
*/
list_t *arrToList(int *arr, int size)
{
    if (arr == NULL || size == 0)
    {
        return NULL;
    }

    list_t *list = (list_t *)malloc(sizeof(list_t));
    list_t *pList = list;
    list_t *p = NULL;
    for (int i = 0; i < size; i++)
    {
        if (i == 0)
        {
            list->val = arr[i];
            continue;
        }
        p = (list_t *)malloc(sizeof(list_t));
        p->val = arr[i];
        pList->next = p;
        pList = p;
    }
    p->next = NULL;
    return list;
}
/**
 * @brief 打印链表节点
 * @param list 打印的链表
 * @return 无
*/
void priList(list_t *list)
{
    if (!list)
    {
        return;
    }
    list_t *p = list;
    while (p != NULL)
    {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}
/**
 * @brief 冒泡排序
 * @param arr 要排序的数组
 * @param size 数组大小
 * @return 无
*/
void bubbleSort(int *arr ,int size)
{
    for (int i=0; i<size; i++)
    {
        for (int j=0; j<size-i-1; j++)
        {
            arr[j] ^= arr[j+1];
            arr[j+1] ^= arr[j];
            arr[j] ^= arr[j+1];
        }
    }
}

/**
 * @brief 合并K个链表到一个链表,暴力法
 * @param list 二维数组
 * @param listSize 二维数组长度
 * @return 返回链表的地址
 */
list_t *mergeKLists(list_t **list, int listSize)
{
    /* 对链表初值进行判断 */
    if (list == NULL || (listSize == 0 && listSize == 1))
    {
        return list;
    }
    int size = 0;
    for (int i=0; i<listSize; i++)
    {
        int count = 0;
        list_t *pNode = list[i];
        while (pNode != NULL)
        {
            count ++;
            pNode = pNode->next;
        }
        size+=count;
    }
    if (size <= 0)
    {
        return NULL;
    }
    int *arr = (int *)malloc((size+1)*sizeof(int));
    int index = 0;
    for (int i=0; i<listSize; i++)
    {
        list_t *pNode = list[i];
        while (pNode!=NULL)
        {
            arr[index++] = pNode->val;
            pNode = pNode->next;
        }
    }
    arr[index] = '\0';
    bubbleSort(arr, size);
    list_t *ret = arrToList(arr, size);
    return ret;
}

int main()
{
    
    return 0;
}