//
// Created by simzhang on 2019/2/8.
//
#include <stdio.h>
#include <string>
class Solution {
public:
    int longestPalindrome(std::string s) {
        int char_map[128] = {0};// 字符串哈希
        int max_length = 0; // 回文串偶数部分的最大长度
        int flag = 0; // 是否有中心点
        for (int i = 0; i < s.length(); ++i) {
            char_map[s[i]]++;
        }
        for (int i = 0; i < 128; ++i) {
            if (char_map[i] % 2 == 0) { // 如果字符数为偶数个，则可以直接使用在回文串里面
                max_length += char_map[i];
            } else {
                max_length += char_map[i] - 1;// 如果某个数字为奇数个，那么放弃一个，其余使用在回文中
                flag = 1;
            }
        }
        return max_length + flag;
    }
};

int main() {
    std::string s = "abcccccdda";
    Solution solve;
    printf("%d\n", solve.longestPalindrome(s));
    return 0;
}