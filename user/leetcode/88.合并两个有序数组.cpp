/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = m-1; i >= 0; i--)
        {
            nums1[n+i] = nums1[i];
        }
        std::vector<int>::iterator i, j, k;
        k = nums1.begin(), j = nums2.begin(), i = k + n;
        while(i < nums1.end() && j < nums2.end())
        {
            int x;
            if(*i <= *j)
            {
                x = *i;
                i++;
            }
            else
            {
                x = *j;
                j++;
            }
            *k = x;
            k++;
        }
        while(i< nums1.end())
        {
            *k = *i;
            k++, i++;
        }
        while(j < nums2.end())
        {
            *k = *j;
            k++, j++;
        }
        return ;
    }
};
// @lc code=end

