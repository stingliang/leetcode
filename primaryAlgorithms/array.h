//
// Created by Liang on 2021/8/4.
//

#include <common.h>

/*
 * 给你一个有序数组nums，请你原地删除重复出现的元素，使每个元素只出现一次，返回删除后数组的新长度
 * 不要使用额外的数组空间，你必须在原地修改输入数组并在使用O(1)额外空间的条件下完成
 * */
int removeDuplicates(std::vector<int>& nums) {
    // 排除边界情况
    if (nums.empty()) {
        return 0;
    }
    if (nums.size() == 1) {
        return 1;
    }
    // 迭代器移动的次数加一就是结果数组的大小
    int arraySize = 1;
    auto left = nums.begin();
    for (auto right = left + 1; right != nums.end(); right++) {
        if (*left != *right) {
            left++;
            arraySize++;
            *left = *right;
        }
    }
    return arraySize;
}
