#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int val;
    struct node *next;
} node_t;
typedef struct stack
{
    node_t *top;
    int count;
} stack_t;

stack_t *arrToStack(int *arr, int size)
{
    if (!arr)
    {
        return NULL;
    }
    stack_t *stack = (stack_t *)malloc(sizeof(stack_t));
    stack->count = 0;
    stack->top = NULL;
    node_t *firstNode = (node_t *)malloc(sizeof(node_t));
    node_t *pStackNode = firstNode;
    for (int i = 0; i < size; i++)
    {
        if (i == 0)
        {
            firstNode->val = arr[i];
            firstNode->next = NULL;
            stack->top = firstNode;
            stack->count++;
            continue;
        }
        node_t *pNode = (node_t *)malloc(sizeof(node_t));
        pNode->val = arr[i];
        pNode->next = stack->top;
        stack->top = pNode;
        stack->count++;
    }
    return stack;
}
int is_empty(stack_t *stack)
{
    if (!stack)
    {
        return -1;
    }
    if (stack->count == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int insertNode(stack_t *stack, int val)
{
    if (!stack)
    {
        return -1;
    }
    node_t *pNode = (node_t *)malloc(sizeof(node_t));
    pNode->val = val;
    pNode->next = stack->top;
    stack->top = pNode;
    stack->count++;
}

void popStack(stack_t *stack)
{
    if (is_empty(stack)!= -1 && is_empty(stack) == 0)
    {
        return;
    }
    node_t *pNode = stack->top;
    stack->top = pNode->next;
    pNode->next = NULL;
    stack->count--;
    printf ("%d", pNode->val);
    free(pNode);
    pNode = NULL;
}
void priStack(stack_t *stack)
{
    if (!stack)
    {
        return;
    }
    node_t *pNode = stack->top;
    for (int i=0; i<stack->count; i++)
    {
        printf ("%d ", pNode->val);
        pNode = pNode->next;
    }
    printf ("\n");
}
int main(int argc, char *argv[])
{
    stack_t *stack = (stack_t *)malloc(sizeof(stack_t));
    stack->count = 0;
    stack->top = NULL;
    int a=1234;
    int b;
    while (a!=0)
    {
        b = a%2;
        insertNode(stack, b);
        a = a/2;
    }
    while(stack->count!=0)
    {
        popStack(stack);
    }
    printf ("\n");
    return 0;
}