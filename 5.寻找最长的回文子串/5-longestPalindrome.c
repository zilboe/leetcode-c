#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifndef bool
#define bool int
#define true 1
#define false 0
#endif 
typedef struct node
{
    char s;
    struct node *next;
    struct node *pre;
}node_t;
typedef struct map
{
    int size;
    node_t *first;
    node_t *new;
}map_t;

// bool isHuiWen(const char* s, int left,int right)
// {
//     if (s==NULL)
//         return false;
//     if(left==right)
//         return true;
//     while(s[left]==s[right-left-1]&&left<right)
//     {
//         if(left==right-1)
//             return true;
//         left++;
//     }
//     return false;
// }
/**
 * @brief 创建表
*/
map_t* createMap()
{
    map_t *newMap = (map_t*)malloc(sizeof(map_t));
    newMap->size = 0;
    newMap->first=newMap->new=NULL;
    return newMap;
}
/**
 * @brief 插入数据字符
 * @param map 表
 * @param s 数据
 * @remark 测试成功
*/
void insert(map_t *map, char s)
{
    node_t *newNode = (node_t*)malloc(sizeof(node_t));
    newNode->s = s;
    newNode->next=NULL;
    newNode->pre = NULL;
    if(map->size==0)
    {
        map->size++;
        map->first = newNode;
        map->new = newNode;
    }
    else
    {
        map->size++;
        newNode->pre = map->new;
        map->new->next = newNode; //容易丢
        map->new = newNode;
    }
}

void insertArr(map_t *map, char *s, int len)
{
    for(int i=0; i<len; i++)
    {
        insert(map,s[i]);
    }
}
void cleanMap(map_t *map)
{
    if (map==NULL)
    {
        return;
    }
    node_t *pDel = NULL;
    while(map->size!=0 && map->first!=map->new)
    {
        pDel = map->first;
        map->first = map->first->next;
        free(pDel);
        map->size--;
    }
    free(map->first);
    pDel = NULL;
    map->first=map->new=NULL;
    map->size--;
}
/**
 * @brief 判断表中是不是回文
 * @param map 表
 * @return false 不是 true 是
 * 
*/
bool isHuiWen(map_t *map)
{
    if (map->size==0)
        return false;
    if (map->size==1)
        return true;
    node_t *pPre = map->new;
    node_t *pNext = map->first;
    while(pPre!=pNext)
    {
        if(pPre->s != pNext->s)
            return false;
        pNext = pNext->next;
        pPre = pPre->pre;
    }
    return true;
}
int main(int argc, const char *argv[])
{
    //1.创建表
    map_t *map = createMap();
    char *str="1";
    char *ret = NULL;
    int len = strlen(str);
    int left=0,right=0;
    int maxSize=0;
    int size = 0;
    for(int a=0;a<len;a++)
    {
        for(int b=a;b<len;b++)
        {
           insert(map,str[b]);
           if(isHuiWen(map))
           {
                size=map->size;
           } 
           else
           {
            continue;
           }
           if(size>maxSize)
           {
            left=a;
            right=b;
            maxSize = size;
           }
        }
        cleanMap(map);
    }
    printf("Size = %d,left = %d, right = %d\n",maxSize,left,right);
    ret = (char*)malloc(maxSize+1);
    int startIndex=0,endIndex=maxSize;
    ret[endIndex]='\0';
    if (maxSize==0)
    {
        return 0;
    }
    else
    {
        for(int i=left;i<=right;i++)
        {
            ret[startIndex++] = str[i];
        }
    }
    //接下来就是拷贝
    printf("%s\n",ret);
    return 0;
}
