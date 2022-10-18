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
    if (!stack)
    {
        return;
    }
    node_t *pNode = stack->top;
    stack->top = pNode->next;
    pNode->next = NULL;
    stack->count--;
    printf ("val = %d\n", pNode->val);
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
    int arr[10] = {2,5,1,3,6,7,9,8,0,4};
    stack_t *stack = arrToStack(arr, 10);
    priStack(stack);
    printf ("count = %d\n", stack->count);
    popStack(stack);
    priStack(stack);
    return 0;
}