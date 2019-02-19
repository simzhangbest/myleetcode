//
// Created by simzhang on 2019/2/19.
//
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <algorithm>
using  namespace std;
// 分隔符可能会多次分割
std::vector<std::string> split_multi(std::string& s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        if (token[0] != 0x00) {
            tokens.push_back(token);
        }
    }
    return tokens;
}

int strToInt(std::string& str_input ) {
    stringstream ss;
    ss << str_input;
    int i;
    ss >> i;
    return i;
}

bool cmp(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.first < b.first;
}

class Solution {

public:
    int theSameTimeOlineNumberOfPeople (std::string& filename) {
        //打开日志 逐行分析
        char buffer[256];
        ifstream logfile(filename.c_str());
        if (! logfile.is_open())
        {
            cout << "Error opening file"; exit (1);
        }
        std::vector<std::pair<int, int> > vec_login_out_time;
        while (!logfile.eof())
        {
            logfile.getline(buffer,100);
            std::string buffer_str = buffer;
            std::vector<std::string> vec_tmp = split_multi(buffer_str, ' ');
            // string to int
            std::pair<int, int> pair_tmp(strToInt(vec_tmp.at(1)), strToInt(vec_tmp.at(2)));
            //printf("pair info: left -> %d /t right -> %d \n", strToInt(vec_tmp.at(1)), strToInt(vec_tmp.at(2)));
            vec_login_out_time.push_back(pair_tmp);
        }

        int max_number_online_thesame_time = findMaxBallonShots(vec_login_out_time);

        return max_number_online_thesame_time;

    }

    int findMaxBallonShots(std::vector<std::pair<int, int> >& points) {
        if(points.size() == 0) {
            return 0;
        }

        std::sort(points.begin(), points.end(), cmp);
        std::vector<int> max_per_time;
        int ballon_num = 1;
        int shoot_begin = points[0].first;
        int shoot_end = points[0].second;

        for (int i = 1; i < points.size() ; ++i){
            if(points[i].first <= shoot_end) {
                shoot_begin = points[i].first;
                ballon_num++;
                max_per_time.push_back(ballon_num);
                if(shoot_end > points[i].second) {
                    shoot_end = points[i].second;
                }
            } else {
                ballon_num = 1;
                shoot_begin = points[i].first;
                shoot_end = points[i].second;
            }
        }

        std::vector<int>::iterator it;

        int max = 0;
        for ( it  = max_per_time.begin(); it != max_per_time.end(); it++) {
            if (max < *it ) {
                max = *it;
            }
        }
        return max;
    }

};

int main() {
    // test
    string filename = "log.txt";
    Solution solve;
    int res = solve.theSameTimeOlineNumberOfPeople(filename);
    printf("res=%d", res);
}