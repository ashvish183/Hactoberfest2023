// C program to find the length of the longest substring
// without repeating characters
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
 
int max(int num1, int num2)
{
    return (num1 > num2) ? num1 : num2;
}
 
bool areDistinct(char str[], int i, int j)
{
    bool visited[256];
    for (int i = 0; i < 256; i++)
        visited[i] = 0;
 
    for (int k = i; k <= j; k++) {
        if (visited[str[k]] == true)
            return false;
        visited[str[k]] = true;
    }
    return true;
}
 
int longestUniqueSubsttr(char str[])
{
    int n = strlen(str);
    int res = 0; // result
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (areDistinct(str, i, j))
                res = max(res, j - i + 1);
    return res;
}

int main()
{
    char str[] = "HacktoberFestIsAmazing";
    printf("The input string is %s \n", str);
    int len = longestUniqueSubsttr(str);
    printf("The length of the longest non-repeating "
           "character substring is %d",
           len);
    return 0;
}