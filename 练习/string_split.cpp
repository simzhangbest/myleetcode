

/*
 *  string split
 * */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
//分隔符只会一次分割
std::vector<std::string> split(const std::string& s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        printf("get token[0] : %d \n", token[0]);
        tokens.push_back(token);
    }
    return tokens;
}
// 分隔符可能会多次分割
std::vector<std::string> split_multi(const std::string& s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        if (token[0] != 0x00) {
            printf("get token[0] : %d \n", token[0]);
            tokens.push_back(token);
        }
    }
    return tokens;
}

int main() {
    std::vector<std::string> res;
    res = split_multi("ni%%%hao%haha%%%%%%ni", '%');
    std::vector<std::string>::iterator it;
    for(it = res.begin(); it != res.end(); it++) {
        std::cout << "res:" << *it << std::endl;
    }
}
