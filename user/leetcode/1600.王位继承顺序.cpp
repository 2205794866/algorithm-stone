/*
 * @lc app=leetcode.cn id=1600 lang=cpp
 *
 * [1600] 王位继承顺序
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;


class ThroneInheritance {
    private:
        unordered_map<string, vector<string>> edge;
        unordered_set<string> dead;
        string king;
public:
    ThroneInheritance(string kingName) {
        king = kingName;
    }
    
    void birth(string parentName, string childName) {
        edge[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    void preorder(string name, vector<string> &ans)
    {
        if(!dead.count(name))
        {
            ans.push_back(name);
        }
        for(auto childName: edge[name])
        {
            preorder(childName, ans);
        }
    }


    vector<string> getInheritanceOrder() {
        vector<string> ans;
        preorder(king, ans);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
// @lc code=end

