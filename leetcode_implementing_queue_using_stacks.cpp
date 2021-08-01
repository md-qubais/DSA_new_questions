class MyQueue{
public:
    int size=0;
    stack<int> s1;
    stack<int> s2;
    MyQueue(){
    }
    void push(int x){
        size++;
        s1.push(x);
    }
    int pop(){
        size--;
        if(!s2.empty()){
            int num=s2.top();
            s2.pop();
            return num;
        }
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int num=s2.top();
        s2.pop();
        return num;
    }
    int peek() {
        if(!s2.empty()){
            return s2.top();
        }
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        return s2.top();
    }
    bool empty(){
        return size==0;
    }
};


