#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void bubble_Sort(int *s,int size)
{
  for(int i=0;i<size;i++){
    for(int j=0;j<size-1-i;j++){
      if(s[j] > s[j+1]){
        s[j] ^= s[j+1];
        s[j+1] ^= s[j];
        s[j] ^= s[j+1];
      }
    }
  }
}
int main()
{
  int s[10] = {20,60,30,10,80,70,50,90,40,1};
  bubble_Sort(s,10);
  for(int i=0;i<10;i++)
    printf("%d ",s[i]);
  printf("\n");
  return 0;
}
