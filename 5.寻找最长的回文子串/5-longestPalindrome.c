#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *longestPalindrome(char *s)
{
    int len = strlen(s);
    // printf("len = {%d}\n", len);

    //1.申请2*n+1长度内存格式化s
    int new_len = 2*len+1;
    char *mem_s = (char*)malloc(sizeof(char)*new_len+1);
    memset(mem_s, '\0', sizeof(char)*new_len);
    int ind = 0;
    for(int i=0; i<new_len; i++)
    {
        if(i%2)
            mem_s[i] = s[ind++];
        else
            mem_s[i] = '#';
    }
    // printf("new mem = {%s}\n", mem_s);

    //2.开辟新的数组来保存每个点的回文半径
    int *mem_ind = (int*)malloc(sizeof(int)*new_len+1);
    memset(mem_ind, 0, (sizeof(int)*new_len));
    // 中心扩展法
    for(int i=0; i<new_len; i++)
    {
        int left = i, right = i;
        while(left > 0 && right < new_len)
        {
            left--;
            right++;
            if(mem_s[left]==mem_s[right])
                mem_ind[i]++;
            else
                break;
        }
    }

    // for(int i=0; i<new_len; i++)
    //     printf("%d ", mem_ind[i]);
    // printf("\n");

    //3.寻找最大半径的起始边界和终止边界
    int temp_max_index = 0;
    int start = 0, end = 0;
    for(int i=0; i<new_len; i++)
    {
        if(temp_max_index < mem_ind[i])
        {
            temp_max_index = mem_ind[i];
            start = (i-temp_max_index)/2;
            end = (i + temp_max_index)/2;
        }
    }
    // printf("start = {%d}, end = {%d}\n", start, end);

    //4.拷贝出来
    char *ret = (char*)malloc(sizeof(char)*(end-start+1)+1);
    memset(ret, '\0', sizeof(char)*(end-start+1));
    for(int i=0; i<(sizeof(char)*(end-start)); i++)
    {
        ret[i] = s[start+i];
    }
    free(mem_s);
    free(mem_ind);
    return ret;
}

int main(int argc, const char *argv[])
{
    char *str = "babad";
    char *p = longestPalindrome(str);
    printf("%s\n", p);
    return 0;
}
