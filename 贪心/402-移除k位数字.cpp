#include<iostream>
#include<string>
#include<vector>
using namespace std;	
class Solution {
public:
    string removeKdigits(string num, int k) {
        std::vector<int> S;
        std::string result = "";
        for(int i = 0; i < num.length(); i++){
        	int number = num[i] - '0';
        	while(S.size() != 0 && S.back() > number	&& k > 0){
	        	S.pop_back();
	        	k--;
	        }
	        //如果number是 0 但是 栈不空，也可以插入栈 
	        if(number != 0 || S.size() != 0){  
        		S.push_back(number);
        	}
        }
        while(S.size() != 0 && k > 0){
        	S.pop_back();
        	k--;
        } 
        //储存数字
		for(int i = 0; i < S.size(); i++){	
			result.append(1,'0' + S.at(i));
		} 
		if(result == ""){
			result = "0";
		}
		return result;
    }
};