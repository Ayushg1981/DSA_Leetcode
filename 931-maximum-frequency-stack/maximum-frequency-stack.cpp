class FreqStack {
public:
    unordered_map<int,int> mp;
    unordered_map<int, stack<int>> m;
    int x;
    FreqStack() {
        x=0;
    }
    
    void push(int val) {
        mp[val]++;
        x=max(x,mp[val]);
        m[mp[val]].push(val);
    }
    
    int pop() {
        int y = m[x].top();
        m[x].pop();
        if (!m[mp[y]--].size()) x--;
        return y;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */