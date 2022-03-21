/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
public:
    MinStack() {
        MinOne.push_back(__INT_MAX__);
    }
    
    void push(int val) {
        Stack.push_back(val);
        MinOne.push_back(val < *(MinOne.end()-1) ? val : *(MinOne.end()-1));
        return ;
    }
    
    void pop() {
        Stack.pop_back();
        MinOne.pop_back();
        return ;
    }
    
    int top() {
        return *(Stack.end() - 1);
    }
    
    int getMin() {
        return *(MinOne.end() - 1);
    }
private:
    vector<int> Stack;
    vector<int> MinOne;

};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

