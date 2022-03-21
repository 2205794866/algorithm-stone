/*
 * @lc app=leetcode.cn id=67 lang=c
 *
 * [67] 二进制求和
 */

// @lc code=start

void reverse(char *p, int len)
{
    int i;
    char temp;
    i = 0;
    while(i<len/2)
    {
        temp = p[i];
        p[i] = p[len-i-1];
        p[len -i -1] = temp;
        i++;
    }
}


char * addBinary(char * a, char * b){
    int len1 = strlen(a), len2 = strlen(b), i, cf;
    reverse(a, len1);
    reverse(b, len2);
    int len = len1>len2 ? len1 : len2;
    len ++;
    char *ans = (char *)malloc(sizeof(char) * (len +1));
    i = 0, cf = 0;
    while(i<len)
    {
        int n = 0;
        if(*a != '\0')
        {
            n += *a - '0';
            a ++;
        }
        if(*b != '\0')
        {
            n+=*b - '0';
            b ++;
        }
        n += cf;
        ans[i] = n%2 + '0';
        cf = n/2;
        i++;
    }
    if(ans[len-1] == '0')
    len --;
    ans[len] = '\0';
    reverse(ans, len);
    return ans;
}
// @lc code=end

