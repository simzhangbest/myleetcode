
#include<iostream>
#include<stack>	
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
		_data.push(x);
		if(_min.empty() || _min.top() > x){
			_min.push(x);
		}        
		else{ 
			if(_min.top() <= x){
				_min.push(_min.top());
			}
		}
    }
    
    void pop() {
    	_data.pop();
		_min.pop();    
    }
    
    int top() {
    	return _data.top();    
    }
    
    int getMin() {
    	return _min.top();    
    }

private:
	std::stack<int> _data;//����ջ
	std::stack<int> _min; // ��Сֵջ 
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */