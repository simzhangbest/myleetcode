//
// Created by simzhang on 2019/2/19.
//

/*
 * char*  char[]   string 互转
 * */

#include <string>
#include <stdio.h>
#include <cstring>
using  namespace std;

/*
 * 将char* char[] 转成 string
 * */
void test01() {
    string x;
    const char* y = "hello";
    const char z[] = "hello world";

    x = y;
    printf("char* to string test: char* is %s, string is %s \n", y, x.c_str());
    printf("char* to string address test : char* address is %p, string address is %p \n", y, x.c_str());

    x = z;
    printf("char[] to string test: char[] is %s, string is %s \n", z, x.c_str());
    printf("char[] to string address test : char[] address is %p, string address is %p \n", z, x.c_str());
}

void test02() {
    char x[20];
    string y = "hello world";

    strcpy(x, y.c_str());
    printf("string to char[]: string is: %s, char[] is: %s \n", y.c_str(), x);

    string str = "abc";
    const char *p = str.data();//data除了返回字符串内容外，不附加结束符'\0'，而c_str()返回一个以‘\0’结尾的字符数组
    printf("string to char*: string is: %s, char* is: %s \n", str.c_str(), p);
}
/*
 * 将string 转成char* char[]
 * */

int main() {
    test01();
    printf("-------------");
    test02();
}