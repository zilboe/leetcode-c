#include <stdio.h>
#include <stdlib.h>
struct ListNode{
    int val;
    struct ListNode *next;
};
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head = NULL,*tail = NULL;
    int count = 0;
    while (l1 || l2){
        int n1 = l1 ? l1->val : 0;
        int n2 = l2 ? l2->val : 0;
        int sum = n1 + n2 + count;
        if(!head){
            head = tail = malloc(sizeof(struct ListNode));
            tail->val = sum % 10;
            tail->next = NULL;
        }else{
            tail->next = malloc(sizeof(struct ListNode));
            tail = tail->next;
            tail->val = sum % 10;
            tail->next = NULL;
        }
        count = sum / 10;
        if(l1)  l1 = l1->next;
        if(l2)  l2 = l2->next;
    }
    if(count > 0){
        tail->next = malloc(sizeof(struct ListNode));
        tail = tail->next;
        tail->val = count;
        tail->next = NULL;
    }
    return head;
}
int main(){
    //把数组转换成链表
    int nums1[]={2,4,3};
    int nums2[]={5,6,4};
    int size1 = sizeof(nums1)/sizeof(nums1[0]);
    struct ListNode *h1 = NULL;
    struct ListNode *p = NULL;
    h1 = malloc(sizeof(struct ListNode));
    struct ListNode *end = h1;
    for(int i=0;i<size1;i++){
        p = malloc(sizeof(struct ListNode));
        p->val = nums1[i];
        end->next = p;
        end = p;
    }
    end->next = NULL;
    struct ListNode *l1 = h1->next;

    int size2 = sizeof(nums2)/sizeof(nums2[0]);
    struct ListNode *h2 = NULL;
    h2 = malloc(sizeof(struct ListNode));
    end = h2;
    p = NULL;
    for(int i=0;i<size2;i++){
        p = malloc(sizeof(struct ListNode));
        p->val = nums2[i];
        end->next = p;
        end = p;
    }
    end->next = NULL;
    struct ListNode *l2 = h2->next;
    //得到两个链表l1和l2

    struct ListNode *ret = addTwoNumbers(l1,l2);

    p = ret;
    while(p!=NULL){
        printf("%d ",p->val);
        p = p->next;
    }

    printf("\n");
    return 0;
}
