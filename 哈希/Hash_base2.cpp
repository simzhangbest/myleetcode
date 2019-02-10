//
// Created by simzhang on 2019/2/3.
//


// 哈希用来排序  只能是正整数  数字规模不能太大

#include <stdio.h>

int main() {
    int random[10] = { 999, 1, 555, 55, 43, 2, 1,99,88,1};
    int hash_map[1000] = {0};
    for (int i = 0; i < 10; ++i) {
        hash_map[random[i]]++;
    }
    for (int i = 0; i < 1000; ++i) {
        for (int j = 0; j < hash_map[i]; ++j) {
            printf("%d\n", i);
        }
    }

    return 0;
}
