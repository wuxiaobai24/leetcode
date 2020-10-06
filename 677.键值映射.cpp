/*
 * @lc app=leetcode.cn id=677 lang=cpp
 *
 * [677] 键值映射
 */

// @lc code=start

class TireNode {
public:
    TireNode(int _value = 0):value(_value), isLeaf(false), sum(0) {}

    unordered_map<char, TireNode *> child;
    int value, sum;
    bool isLeaf;
};

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TireNode(0);
    }
    
    void insert(string key, int val) {
        TireNode *p = root;
        stack<TireNode*> st;
        for(int i = 0;i < key.size(); i++) {
            st.push(p);
            char index = key[i];
            if (p->child[index] == nullptr) {
                p->child[index] = new TireNode();
            }
            p = p->child[index];
        }
        int diff = val - p->value;
        while(!st.empty()) {
            st.top()->sum += diff;
            st.pop();
        }
        p->sum += diff;
        p->value  = val;
        p->isLeaf = true;
    }
    
    int sum(string prefix) {
        TireNode *p = root;
        for(int i = 0;i < prefix.size() && p != nullptr; i++) {
            char index = prefix[i];
            p = p->child[index];
        }
        return p == nullptr ? 0 : p->sum;
    }
    int sum(TireNode *p) {
        if (p == nullptr) return 0;
        int res = p->isLeaf ? p->value : 0;
        for(auto &pair: p->child) {
            res += sum(pair.second);
        }
        return res;
    }
    TireNode *root;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
// @lc code=end

