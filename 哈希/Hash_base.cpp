//
// Created by simzhang on 2019/2/3.
//
// 最简单的hash
#include <stdio.h>
#include <string>

int main() {
    int char_map[128] = {0};
    std::string str = "abcdefgaaxxhh";
    for (int i = 0; i < str.length(); ++i) {
        char_map[str[i]] ++;
    }

    for (int i = 0; i < 128; ++i) {
        if (char_map[i] > 0) {
            printf("[%c][%d] : %d\t\n", i, i, char_map[i]);
        }
    }
    return 0;
}