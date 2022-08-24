#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void quickSort(int *s,int left,int right)
{
  if(left > right)
    return;
  int temp=s[left];
  int i=left,j=right;
  int t;
  if(i < j){
    while(i < j)
    {
      while(i < j && s[j] >= temp)
        j--;
      while(i < j && s[i] <= temp)
        i++;
      if(i < j)
      {
        t = s[i];
        s[i] = s[j];
        s[j] = t;
      }
    }
    s[left] = s[i];
    s[i] = temp;
    quickSort(s,left,i-1);
    quickSort(s,i+1,right);
  }
}
int main()
{
  int s[10] = {20,40,10,80,50,70,60,30,90,1};
  quickSort(s,0,9);
  for(int i=0;i<10;i++)
    printf("%d ",s[i]);
  printf("\n");
  return 0;
}
