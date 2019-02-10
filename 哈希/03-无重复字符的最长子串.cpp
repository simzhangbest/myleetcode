//
// Created by sim.zhang on 2019/2/8.
//


class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int begin = 0;
        int result = 0;
        std::string word = "";
        int char_map[128] = {0};
        for (int i = 0; i < s.length(); ++i) {
            char_map[s[i]]++;

            if (char_map[s[i]] == 1) {
                // word 中没有出现过该字符
                word += s[i];
                if (result < word.length()) {
                    result = word.length();
                }
            } else {
                //将重复的字符s[i]去掉
                while (begin < i && char_map[s[i]] > 1) {
                    char_map[s[begin]]--;
                    begin++;
                }
                word = "";
                for (int j = 0; j < i; ++j) {
                    word += s[j];
                }
            }
        }
        return result;
    }
};
