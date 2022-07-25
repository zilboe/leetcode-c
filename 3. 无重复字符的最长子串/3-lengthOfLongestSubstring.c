#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 128
typedef struct{
    char map[N];
    int count;
}map_t;
//创建线性数组
void create_map(map_t **s){
    *s = (map_t*)malloc(sizeof(map_t));
    (*s)->count = 0;
}
//判断数组中是否存在某个元素，存在返回0，不存在返回1
int isext(map_t *s,char ch){
    for(int i=0;i<s->count;i++){
        if(s->map[i]==ch){
            return 0;
        }
    }
    return 1;
}
//向数组中插入元素,当然也需要判断元素存在与否
int insertmap(map_t *s,char ch)
{
    if(isext(s,ch)){
        s->map[s->count] = ch;
        s->count++;
        return 1;
    }else{
        printf("insertmap error\n");
        return 0;
    }
}
//遍历打印数组
void print(map_t *s){
    for(int i=0;i<s->count;i++){
        printf("%c ",s->map[i]);
    }
    printf("\n");
}
//根据元素的值移除某个元素
int removemap(map_t *s,char ch){
    int flag = 0;
    for(int i=0;i<s->count;){
        flag = 0;
        if(s->map[i] == ch){
            for(int j=i+1;j<s->count;j++){
                s->map[j-1] = s->map[j];
            }
            s->count--;
            flag = 1;
        }
        if( 0 == flag ){
            i++;
        }
    }
    return 0;
}
//求出无重复数组的最长长度
int lengthOfLongestSubstring(char *s){
    map_t *map = NULL;
    create_map(&map);
    //滑动窗口法,双指针+两个长度变量
    int left,right,length,maxlength;
    left = 0;
    right = 0;
    length = 0;
    maxlength = 0;
    //窗口的右指针为边界
    while(right<strlen(s)){
        //判断右指针的值是否在map中，如果不存在，将元素添加到map中，然后length+1，右指针向右移动，
        //然后用maxlength记录最大的length值
        if(isext(map,s[right])){
            insertmap(map,s[right]);
            length++;
            if(length > maxlength){
                maxlength = length;
            }
            right++;
        }
        //右指针元素在map中存在，说明滑动区间存在两个相同的元素
        else{
            //当右指针元素的值存在map时，我们移除map中左指针的值，然后将左指针向右移动一个单位，length相应的要减一
            while(!isext(map,s[right])){
                removemap(map,s[left]);
                left++;
                length--;
            }
            //上述while结束或者map中不存在左指针值，说明map中又是无重复的元素，那我们继续添加右指针值，
            //然后长度加一，右指针继续向右移动，
            insertmap(map,s[right]);
            length++;
            right++;
        }
    }
    //循环结束，maxlength会记录滑动数组中无重复的最大字串的个数。
    return maxlength;
}

int main(int argc,char *argv[]){
    char *s = "wqeqeq";
    int l = lengthOfLongestSubstring(s);
    printf("%d\n",l);
    return 0;
}
