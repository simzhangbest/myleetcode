//
// Created by simzhang on 2019/2/1.
//

#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int index = -1;
        int begin = 0;
        int end = nums.size() - 1;
        while(index == -1) {
            int mid = (begin + end) / 2;
            if (target == nums[mid]) {
                index = mid;
            } else if (target < nums[mid]) {
                if (target > nums[mid - 1] || mid == 0) {
                    index = mid;
                }
                end = mid - 1;
            } else if (target > nums[mid]) {
                if (target < nums[mid + 1] || mid == nums.size() - 1) {
                    index = mid + 1;
                }
                begin = mid + 1;
            }
        }
        return  index;
    }
};