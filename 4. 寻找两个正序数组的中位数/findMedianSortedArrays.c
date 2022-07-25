#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int *s = (int*)malloc((nums1Size+nums2Size)*sizeof(int));
    int newindex = 0;
    int i=0,j=0;
    while((i<nums1Size) && (j<nums2Size)){
        s[newindex++] = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
    }
    while(i<nums1Size){
        s[newindex++] = nums1[i++];
    }
    while(j<nums2Size){
        s[newindex++] = nums2[j++];
    }
    float mid;
    if((nums1Size+nums2Size)%2 != 0){
        return (float)s[(nums1Size+nums2Size)/2];
    }
    else{
        return (((float)s[(nums1Size+nums2Size)/2]) + ((float)s[((nums1Size+nums2Size)/2)-1])) / 2;
    }
}

int main(int argc,char* argv[]){
    int num1[6] = {1,2,5,7,9,10};
    int num2[4] = {3,4,6,8};

    float s = findMedianSortedArrays(num1,6,num2,4);
    printf("s = %f\n",s);
    return 0;
}
