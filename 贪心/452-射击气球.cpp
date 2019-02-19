//
// Created by simzhang on 2019/1/28.
//
#include <vector>
#include <string>
#include <stdio.h>
#include <algorithm>

bool cmp(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.first < b.first;
}
class Solution {
public:
    int findMinArrowShots(std::vector<std::pair<int, int> >& points) {
        if(points.size() == 0) {
            return 0;
        }

        std::sort(points.begin(), points.end(), cmp);

        int shoot_num = 1;
        int shoot_begin = points[0].first;
        int shoot_end = points[0].second;

        for (int i = 1; i < points.size() ; ++i){
            if(points[i].first <= shoot_end) {
                shoot_begin = points[i].first;
                if(shoot_end > points[i].second) {
                    shoot_end = points[i].second;
                }
            } else {
                shoot_num++;
                shoot_begin = points[i].first;
                shoot_end = points[i].second;
            }
        }
        return shoot_num;
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
            printf("ballon_num per this time is : %d\n", *it);
        }
        return max;
    }
};

typedef std::pair<int, int> Ballon;
int main() {
    // 记录每次射击的气球个数
    std::vector<Ballon > ballon_vec;
    ballon_vec.push_back(Ballon(10, 16));
    ballon_vec.push_back(Ballon(2, 8));
    ballon_vec.push_back(Ballon(1, 7));
    ballon_vec.push_back(Ballon(7, 12));

    Solution solve;
    int res = solve.findMaxBallonShots(ballon_vec);
    printf("need arrows number: %d", res);
}