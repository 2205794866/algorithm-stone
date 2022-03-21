/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // int i, j;
        // bool flag = false;
        // vector<int> res;
        // for(i = 0; i<numbers.size(); i++)
        // {
        //     for(j = i+1; j < numbers.size() ; j++)
        //     {
        //         if(numbers[i] + numbers[j] == target)
        //         {
        //             res.push_back(i+1);
        //             res.push_back(j+1);
        //             flag = true;
        //             break;
        //         }
        //         else
        //         if(numbers[i] + numbers[j] > target)
        //         break;
        //     }
        //     if(flag == true)
        //     break;
        // }
        // return res;
        vector<int> res;
        unordered_map<int, int> map;
        unordered_map<int, int>::iterator got;
        int i;
        for(i = 0; i<numbers.size(); i++)
        {
            got = map.find(target-numbers[i]);
            if(got != map.end())
            {
                res.push_back(got->second+1);
                res.push_back(i+1);
                break;
            }
            map.insert(make_pair(numbers[i], i));
        }
        return res;
    }
};
// @lc code=end

