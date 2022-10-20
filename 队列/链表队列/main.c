#include <stdio.h>
#include <stdlib.h>
typedef struct _NODE
{
    int val;
    struct _NODE *next;
}node_t;
typedef struct _QUEUELIST
{
    node_t *front;
    node_t *rear;
    int size;
} queueList_t;
/**
 * @brief 入链表队列
 * @param queueList 链表队列
 * @param val 值
 * @return 返回队列长度
*/
int pushQueue(queueList_t *queueList, int val)
{
    if (!queueList)
        return -1;
    node_t *pNew = (node_t *)malloc(sizeof(node_t));
    pNew->val = val;
    pNew->next = NULL;
    if (queueList->size == 0)
    {
        queueList->front = pNew;
        queueList->rear = pNew;
        queueList->size++;
    }
    else
    {
        node_t *p = queueList->rear;
        p->next = pNew;
        queueList->rear = pNew;
        queueList->size++;
    }
    return queueList->size;
}
/**
 * @brief 元素出队列
 * @param queueList 队列链表
 * @return 队列长度
*/
int pushValQueueList(queueList_t *queueList)
{
    if (!queueList)
        return -1;
    if (queueList->size == 0)
    {
        printf ("queueList is empty\n");
        return 0;
    }
    node_t *p = queueList->front;
    queueList->front = p->next;
    int val = p->val;
    printf ("val = %d\n", val);
    free(p);
    p = NULL;
    queueList->size--;
    return queueList->size;
}

/**
 * @brief 遍历打印
 * @param queueList 链表队列
 * @return 无
*/
void priQueueList(queueList_t *queueList)
{
    if (!queueList)
        return;
    if (queueList->size == 0)
    {
        printf ("queueList is empty\n");
        return;
    }
    node_t *p = queueList->front;
    for (int i=0; i<queueList->size; i++)
    {
        printf ("%d ", p->val);
        p = p->next;
    }
    printf ("\n");
}

int main(int argc, char *argv[])
{
    queueList_t *queueList = (queueList_t *)malloc(sizeof(queueList_t));
    queueList->front = NULL;
    queueList->rear = NULL;
    queueList->size = 0;
    // 初始化完成
    for (int i=0; i<10; i++)
        pushQueue(queueList, i); // 入10个元素 0 1 2 3 4 5 6 7 8 9
    printf ("size = %d\n", queueList->size); // 打印长度
    priQueueList(queueList); // 遍历打印
    for (int i=0; i<10; i++)
        pushValQueueList(queueList); // 出10个元素,函数中有打印元素值
    printf ("size = %d\n", queueList->size); // 查看链表长度
    return 0;
}