//
// Created by simzhang on 2019/2/8.
//

#include <vector>
#include <map>
#include <string>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string> > groupAnagrams (std::vector<std::string>& strs){
        std::map<std::string, std::vector<std::string> > anagram;
        //内部进行排序的各个单词为key, 以字符串向量(vector<string>为value,存储各字符数量相同的字符串)
        std::vector<std::vector<std::string> > result;
        for (int i = 0; i < strs.size(); ++i) {
            std::string str = strs[i];
            sort(str.begin(), str.end());//对str进行内部排序
            if (anagram.find(str) == anagram.end()) { //如果无法在哈希表中找到str
                std::vector<std::string> item;
                anagram[str] = item;
            }
            anagram[str].push_back(strs[i]);// str 用来做key,其实是需要push的strs[i]
        }
        std::map<std::string, std::vector<std::string> >::iterator it;
        for (it = anagram.begin(); it != anagram.end(); it++) {
            result.push_back((*it).second);
        }
        return result;
    }
};



int main() {
    std::vector<std::string> strs;
    strs.push_back("eat");
    strs.push_back("tea");
    strs.push_back("tan");
    strs.push_back("ate");
    strs.push_back("nat");
    strs.push_back("bat");
    Solution solve;
    std::vector<std::vector<std::string> > result =
            solve.groupAnagrams(strs);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size() ; ++j) {
            printf("[%s]", result[i][j].c_str());
        }
        printf("\n");
    }
    return 0;
}