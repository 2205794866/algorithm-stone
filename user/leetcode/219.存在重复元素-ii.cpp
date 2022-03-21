/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
class Solution {
public:
// typedef struct _NumsandIndex
// {
//     int val;
//     int index;

// } NumsandIndex;

// static bool cmp( NumsandIndex a,NumsandIndex b)
// {
//     return a.val <= b.val;
// }

    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // bool flag = false;
        // vector<NumsandIndex> res;
        // for(int i = 0; i<nums.size(); i++)
        // {
        //     NumsandIndex x;
        //     x.val = nums[i];
        //     x.index = i;
        //     res.push_back(x);
        // }
        // sort(res.begin(), res.end(), cmp);
        // for(int i = 0; i<res.size() - 1; i++)
        // {
        //     if(res[i].val == res[i+1].val && res[i].index - res[i+1].index <= k)
        //     {
        //         flag = true;
        //         break;
        //     }
        // }
        // return flag;
        bool flag = false;
        unordered_map<int , int> map;
        for(int i = 0; i<nums.size(); i++)
        {
            unordered_map<int, int>::iterator p;
            p = map.find(nums[i]);
            if(p != map.end())
            {
                if(i - p->second <= k)
                {
                    flag = true;
                    break;
                }
                else p->second = i;
            }
            map[nums[i]] = i;
        }
        return flag;
    }
};
// @lc code=end

