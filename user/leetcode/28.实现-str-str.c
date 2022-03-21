/*
 * @lc app=leetcode.cn id=28 lang=c
 *
 * [28] 实现 strStr()
 */

// @lc code=start

void get_next(char *s, int *next)
{
    int i, j, len;
    len = strlen(s);
    i = 1, j = 0;
    next[0] = 0;
    while(i<len)
    {
        if(j == 0 || s[i-1] == s[j-1])
        {
            i++;
            j++;
            next[i-1] = j;
        }
        else
        {
            j = next[j-1];
        }
    }
}


int Index_KMP(char *S, char *T)
{
    int i,j,len1,len2;
    len1 = strlen(S);
    len2 = strlen(T);
    if(len2 == 0)
    return 0;
    int *next = (int *)malloc(sizeof(int) * len2);
    i = 0, j = 0;
    get_next(T, next);
    while(i<len1 && j<len2)
    {
        if(j == -1 || S[i] == T[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j]-1;
        }
    }
    if(j>=len2)
    return i-len2;
    else
    return -1;

}


int strStr(char * haystack, char * needle){
    return Index_KMP(haystack, needle);
}
// @lc code=end

