#include <stdio.h>
#include <stdlib.h>

int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize)
{
    int cnt[2];
    for (int i=0; i<studentsSize; i++)
    {
        cnt[students[i]]++;
    }
    for (int i=0; i<sandwichesSize; i++)
    {
        if (--cnt[sandwiches[i]] < 0)
        {
            return (sandwichesSize - i);
        }
    }
    return 0;
}

int main()
{
    int students[] = {1,1,1,0,0,1};
    int sandwiches[] = {1,0,0,0,1,1};
    int ret = countStudents(students, (sizeof(students)/sizeof(students[0])), sandwiches, (sizeof(sandwiches)/sizeof(sandwiches[0])));
    printf ("%d\n", ret);
    return 0;
}