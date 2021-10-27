class MinStack {
public:
    vector< pair<int,int> > res;
    MinStack() { }
    void push(int val) {
        if(res.size() == 0)
            res.push_back({val,val});
        else
            res.push_back({val,min(res.back().second,val)});    
    }
    
    void pop() { res.pop_back(); }
    
    int top() { return res.back().first; }
    
    int getMin() { return res.back().second; }
};