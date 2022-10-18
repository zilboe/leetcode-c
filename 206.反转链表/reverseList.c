#include <stdio.h>
#include <stdlib.h>
/*
 *顺序表的删除和增加操作
typedef struct node
{
    int val;
}node_t;

typedef struct seq
{
    node_t S[50];
    int size;
}seq_list;
int insertSeqList(seq_list *list, int *arr, int size)
{
    if (!list)
    {
        return -1;
    }
    for (int i=0; i<size; i++)
    {
        list->S[i].val = arr[i];
        list->size++;
    }
    return list->size;
}
void priList(seq_list *list)
{
    if (!list)
    {
        return;
    }
    for (int i=0; i<list->size; i++)
    {
        printf ("%d ", list->S[i].val);
    }
    printf ("\n");
}
int delFromList(seq_list *list, int val)
{
    if (!list)
    {
        return -1;
    }
    for (int i=0; i<list->size; i++)
    {
        if (val == list->S[i].val)
        {
            for (int j=i; j<list->size-1; j++)
            {
                list->S[j] = list->S[j+1];
            }
            i--;
            list->size--;
        }
    }
    return list->size;
}
*/
typedef struct node
{
    int val;
    struct node *next;
} list_t;

/**
 * @brief 把数组转换成链表
 * @param arr 数组
 * @param size 数组大小
 * @return 返回节点开头地址
*/
list_t *insertList(int *arr, int size)
{
    if (!arr)
    {
        return NULL;
    }
    list_t *list = (list_t *)malloc(sizeof(list_t));
    list_t *pList = list;
    list_t *p = NULL;
    for (int i=0; i<size; i++)
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
 * @brief 打印链表 
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
 * @brief 反转链表
 * @param list 需要反转的链表
 * @return 返回节点
*/
list_t *reverseList(list_t *list)
{
    if (!list)
    {
        return NULL;
    }
    list_t *p1 = list->next;
    list_t *p2 = p1->next;
    list->next = NULL;
    while(p2 != NULL)
    {
        p1->next = list;
        list = p1;
        p1 = p2;
        if (p2->next == NULL)
        {
            p2->next = list;
            break;
        }
        else
        {
            p2 = p2->next;
        }
    }
    return p2;
}
int main()
{
    int arr[10] = {1,6,2,3,4,0,8,7,9,5};
    list_t *list = insertList(arr, 10);
    priList(list); 
    list_t *p1 = reverseList(list);
    priList(p1);
    return 0;
}