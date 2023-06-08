class MyStack {
    queue<int> q1, q2;
public:

    MyStack() {

    }
    
    void push(int x) {
        if(!q1.empty()){
            q1.push(x);
        }else{
            q2.push(x);
        }
    }
    
    int pop() {
        int ele;
        if(!q1.empty()){
            while(!q1.empty()){
                ele = q1.front();
                if(q1.size() != 1){
                    q2.push(ele);
                }
                q1.pop();
            }
        }else{
            while(!q2.empty()){
                ele = q2.front();
                if(q2.size() != 1){
                    q1.push(ele);
                }
                q2.pop();
            }
        }
        return ele;
    }
    
    int top() {
        int ele;
        if(!q1.empty()){
            while(!q1.empty()){
                ele = q1.front();
                q2.push(ele);
                q1.pop();
            }
        }else{
            while(!q2.empty()){
                ele = q2.front();
                q1.push(ele);
                q2.pop();
            }
        }
        return ele;
    }
    
    bool empty() {
        return q1.empty() && q2.empty(); 
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */