#include <stdio.h>
#include <stdlib.h>
//功能函数
int* twoSum(int* nums, int numsSize, int target){
    //*returnSize = 2;
    int *ret = malloc(2 * sizeof(int));
    for(int i=0;i<numsSize-1;i++){
        for(int j=i+1;j<numsSize;j++){
            if((nums[i]+nums[j])==target){
                ret[0] = i;
                ret[1] = j;
                return ret;
            }
        }
    }
    return ret;
}
//打印结果
void print(int *nums,int resize){
    for(int i=0;i<resize;i++){
        printf("%d\t",nums[i]);
    }
}

int main(){
    int nums[3]= {3,2,4};
    int target=6;
    int *s = twoSum(nums,3,target);
    print(s,2);
    return 0;
}
