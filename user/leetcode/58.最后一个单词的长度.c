/*
 * @lc app=leetcode.cn id=58 lang=c
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start


int lengthOfLastWord(char * s){
    char *p1, *p2;
    int length;
    p1 = s;
    while(*p1 == ' ')
    p1++;
    while(*p1 != '\0')
    {
        length = 0;
        while(*p1 != ' ' && *p1 != '\0')
        length++, p1++;
        while(*p1==' ')
        p1++;
    }
    return length;
}
// @lc code=end

