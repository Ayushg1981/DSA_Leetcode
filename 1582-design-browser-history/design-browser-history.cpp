class BrowserHistory {
public:
    stack<string> st;
    stack<string> s;
    BrowserHistory(string homepage) {
        st.push(homepage);
    }
    
    void visit(string url) {
        st.push(url);
        s=stack<string>();
    }
    
    string back(int steps) {
        while(st.size()>1 && steps--){
            s.push(st.top());
            st.pop();
        }
        return st.top();
    }
    
    string forward(int steps) {
        while(s.size()>0 && steps--){
            st.push(s.top());
            s.pop();
        }
        return st.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */