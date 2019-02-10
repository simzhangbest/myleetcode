//
// Created by simzhang on 2019/2/8.
//

#include <stdio.h>
#include <map>
#include <string>
class Solution {
public:
    bool wordPattern(std::string pattern, std::string str) {
        std::map<std::string, char> word_map; // 单词到pattern字符的映射
        char used[128] = {0}; // 已映射的pattern字符
        std::string word; // 临时保存 拆分出来的单词
        int pos = 0; //当前指向pattern的字符（无需处理最后一个单词）
        str.push_back(' ');
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] == ' ') { //遇到空格 拆分出一个新的单词
                if (pos == pattern.length()) {
                    return false; //分割出来的单词，没有与其对应的pattern
                }
                if (word_map.find(word) == word_map.end()) {
                   if (used[pattern[pos]]) {
                       return false;
                   }
                   word_map[word] = pattern[pos];
                   used[pattern[pos]] = 1;
                } else {
                    if (word_map[word] != pattern[pos]) {
                        return false;
                    }
                }
                word = "";// 完成一个单词的插入和查询后，清空word 指向pattern字符的pos索引前移
                pos++;
            } else {
                word += str[i];
            }

        }
        if (pos != pattern.length()) {
            return false;
        }
        return true;
    }
};

int main(){
    std::string pattern = "abba";
    std::string str = "dog cat cat dog";
    Solution solve;
    printf("%d\n", solve.wordPattern(pattern, str));
}