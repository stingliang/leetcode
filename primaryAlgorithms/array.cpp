//
// Created by Liang on 2021/8/4.
//

#include "array.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(s_array)  /* NOLINT */

BOOST_AUTO_TEST_CASE(c_removeDuplicates) {  /* NOLINT */
    std::array<std::vector<int>, 5> inputArray {
            std::vector<int>{0, 0, 1, 1, 2, 2, 3, 3},
            std::vector<int>{0, 0, 0, 1, 1, 1, 2, 3},
            std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7},
            std::vector<int>{0, 0, 0, 0, 0, 0, 0, 0},
            std::vector<int>{}
    };
    std::array<std::vector<int>, 5> outputArray {
            std::vector<int>{0, 1, 2, 3},
            std::vector<int>{0, 1, 2, 3},
            std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7},
            std::vector<int>{0},
            std::vector<int>{}
    };
    int index = 0;
    for (auto& v: inputArray) {
        int arraySize = removeDuplicates(v);
        BOOST_CHECK_EQUAL(arraySize, outputArray.at(index).size());
        int anotherIndex = 0;
        for (auto& i: outputArray.at(index)) {
            BOOST_CHECK_EQUAL(i, v.at(anotherIndex));
            anotherIndex++;
        }
        index++;
    }
}

BOOST_AUTO_TEST_CASE(c_maxProfit) {  /* NOLINT */
    std::array<std::vector<int>, 3> inputArray {
            std::vector<int>{7, 1, 5, 3, 6, 4},
            std::vector<int>{1, 2, 3, 4, 5},
            std::vector<int>{7, 6, 4, 3, 1}
    };
    std::array<int, 3> outputArray {7, 4, 0};
    auto it = outputArray.begin();
    for (auto& v: inputArray) {
        BOOST_CHECK_EQUAL(maxProfit(v), *it);
        it++;
    }
}

BOOST_AUTO_TEST_CASE(c_rotate) {  /* NOLINT */
    std::array<std::pair<std::vector<int>, int>, 3> inputArray {
        std::make_pair<std::vector<int>, int>(std::vector<int>{1, 2, 3, 4, 5, 6, 7}, 3),
        std::make_pair<std::vector<int>, int>(std::vector<int>{-1, -100, 3, 99}, 2),
        std::make_pair<std::vector<int>, int>(std::vector<int>{1, 2, 3, 4}, 7)
    };
    std::array<std::vector<int>, 3> outputArray {
        std::vector<int>{5, 6, 7, 1, 2, 3, 4},
        std::vector<int>{3, 99 ,-1, -100},
        std::vector<int>{2, 3, 4, 1}
    };
    auto it = outputArray.begin();
    for (auto& v: inputArray) {
        rotate(v.first, v.second);
        int index = 0;
        for (auto& i: v.first) {
            BOOST_CHECK_EQUAL(i, (*it)[index]);
            index++;
        }
        it++;
    }
}

BOOST_AUTO_TEST_CASE(c_isValidSudoku) {  /* NOLINT */
    std::vector<std::vector<char>> boardTrue {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    BOOST_CHECK_EQUAL(isValidSudoku(boardTrue), true);
    std::vector<std::vector<char>> boardFalse {
        {'8', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    BOOST_CHECK_EQUAL(isValidSudoku(boardFalse), false);
}

BOOST_AUTO_TEST_CASE(c_rotateImage) {  /* NOLINT */
    std::vector<std::vector<std::vector<int>>> inputVector {
        {
            {{1, 2, 3},{4, 5, 6},{7, 8, 9}},
            {{5, 1, 9, 11},{2, 4, 8, 10},{13, 3, 6, 7},{15, 14, 12, 16}},
            {{1}},
            {{1, 2},{3, 4}}
        }
    };
    std::vector<std::vector<std::vector<int>>> outputVector {
        {
            {{7, 4, 1},{8, 5, 2},{9, 6, 3}},
            {{15, 13, 2, 5},{14, 3, 4, 1},{12, 6, 8, 9},{16, 7, 10, 11}},
            {{1}},
            {{3, 1},{4, 2}}
        }
    };
    for (int i = 0; i < inputVector.size(); i++) {
        rotateImage(inputVector.at(i));
        for (int j = 0; j < inputVector.at(i).size(); j++) {
            for (int k = 0; k < inputVector.at(i).at(j).size(); k++) {
                BOOST_CHECK_EQUAL(outputVector.at(i).at(j).at(k), inputVector.at(i).at(j).at(k));
            }
        }
    }
}

BOOST_AUTO_TEST_SUITE_END()  /* NOLINT */