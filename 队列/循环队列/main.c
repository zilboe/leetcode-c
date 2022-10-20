#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 11
typedef struct _QUEUE
{
    int val[N];
    int front;
    int rear;
    int size;
}queue_t;
/**
 * @brief 循环队列入队列
 * @param queue 队列
 * @param val 值
 * @return 循环队列的大小
*/
int insertValToQueue(queue_t *queue, int val)
{
    if (!queue)
    {
        return -1;
    }
    if (queue->size == (N-1))
    {
        printf ("insert fail\n");
        return queue->size;
    }
    queue->val[queue->rear] = val;
    queue->rear = (queue->rear+1)%N;
    queue->size++;
    return queue->size;
}
/**
 * @brief 循环队列出数据
 * @param queue 队列
 * @return 循环队列大小
*/
int popValQueue(queue_t *queue)
{
    if (!queue)
    {
        return -1;
    }
    if (queue->front == queue->rear)
    {
        printf ("queue is empty\n");
        return 0;
    }
    int val = 0;
    val = queue->val[queue->front];
    queue->front = (queue->front+1)%N;
    queue->size--;
    printf ("popVal = %d\n", val);
    return queue->size;
}
/**
 * @brief 遍历打印
 * @param queue 队列
 * @return 无
*/
void priQueue(queue_t *queue)
{
    if (!queue)
    {
        return;
    }
    if (queue->front == queue->rear)
    {
        printf ("queue is empty\n");
        return;
    }
    int pFront = queue->front;
    int pRear = queue->rear;
    for (int i=pFront; i!=pRear; i=(i+1)%N)
    {
        printf ("%d ", queue->val[i]);
    }
}

int main(int argc, char *argv[])
{
    queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;
    for (int i=0; i<10; i++)
    {
        insertValToQueue(queue, i); //入10个元素 0 1 2 3 4 5 6 7 8 9
    }
    printf ("size = %d\n", queue->size); //打印长度
    for (int i=0; i<10; i++)
    {
        popValQueue(queue); //以此出10个元素
    }
    printf ("size = %d\n", queue->size); // 打印长度
    return 0;
}