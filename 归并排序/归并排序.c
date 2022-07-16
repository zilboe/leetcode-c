#include <stdio.h>
#include <stdlib.h>
void merge(int* nums,int *p,int l,int m,int r){
    int i=l,j=m+1,x=l;
    while(i<=m && j<=r){
        if(nums[i]<=nums[j])
            p[x++] = nums[i++];
        else{
            p[x++] = nums[j++];
        }
    }
    while(i<=m){
        p[x++] = nums[i++];
    }
    while(j<=r){
        p[x++] = nums[j++];
    }
    for(int i=0;i<=r;i++){
        nums[i] = p[i];
    }
}
void process(int* nums,int *p,int l,int r)
{
    if(l<r){
        int m = l+((r-l)>>1);
        process(nums,p,l,m);
        process(nums,p,m+1,r);
        merge(nums,p,l,m,r);
    }
}
int main(){

    int nums[8]={50, 10, 20, 30, 70, 40, 80, 60};
    int p[8];
    process(nums,p,0,7);
    for(int i=0;i<8;i++){
        printf("%d ",nums[i]);
    }
    return 0;
}
