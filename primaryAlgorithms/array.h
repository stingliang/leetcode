//
// Created by Liang on 2021/8/4.
//

#include <common.h>

int removeDuplicates(std::vector<int>& nums) {
    // 排除边界情况
    if (nums.empty()) {
        return 0;
    }
    if (nums.size() == boost::lexical_cast<size_t, int>(1)) {
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

int maxProfit(std::vector<int>& prices) {
    int earnings(0);
    for (auto todayPrice = prices.begin(); todayPrice + 1 != prices.end(); todayPrice++) {
        if (*(todayPrice + 1) > *todayPrice) {
            earnings += *(todayPrice + 1) - *todayPrice;
        }
    }
    return earnings;
}

void rotate(std::vector<int>& nums, size_t k) {
    if (nums.empty() || k == boost::lexical_cast<size_t, int>(0)) {
        return;
    }
    auto realMove = std::stoi(std::to_string(k % nums.size()));
    std::reverse(nums.begin(), nums.end());
    std::reverse(nums.begin(), nums.begin() + realMove);
    std::reverse(nums.begin() + realMove, nums.end());
}

bool isValidSudoku(std::vector<std::vector<char>>& board) {
    // box_index = (rows/3)*3 + columns/3
    std::array<std::unordered_set<char>, 9> columnsSetArray;
    std::array<std::unordered_set<char>, 9> boxSetArray;
    for (int rowsIndex = 0; rowsIndex < 9; rowsIndex++) {
        std::unordered_set<char> rowsSet;
        for (int columnsIndex = 0; columnsIndex < 9; columnsIndex++) {
            auto cell = board[rowsIndex][columnsIndex];
            if (cell == '.') {
                continue;
            }
            // 在行中是否重复
            if (rowsSet.find(cell) == rowsSet.end()) {
                rowsSet.insert(cell);
            } else {
                return false;
            }
            // 在列中是否重复
            if (columnsSetArray[columnsIndex].find(cell) == columnsSetArray[columnsIndex].end()) {
                columnsSetArray[columnsIndex].insert(cell);
            } else {
                return false;
            }
            // 在九宫格中是否重复
            int boxIndex = (rowsIndex / 3) * 3 + (columnsIndex / 3);
            if (boxSetArray[boxIndex].find(cell) == boxSetArray[boxIndex].end()) {
                boxSetArray[boxIndex].insert(cell);
            } else {
                return false;
            }
        }
    }
    return true;
}

void rotateImage(std::vector<std::vector<int>>& matrix) {
    int n = boost::lexical_cast<int>(matrix.size());
    for (int row = 0; row < (n + 1) / 2; row++) {
        for (int col = 0; col < n / 2; col++) {
            int temp = matrix[row][col];
            matrix[row][col] = matrix[n - col - 1][row];
            matrix[n - col - 1][row] = matrix[n - row - 1][n - col - 1];
            matrix[n - row - 1][n - col - 1] = matrix[col][n - row - 1];
            matrix[col][n - row - 1] = temp;
        }
    }
}
