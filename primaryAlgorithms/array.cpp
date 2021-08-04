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
        BOOST_REQUIRE_EQUAL(arraySize, outputArray.at(index).size());
        int anotherIndex = 0;
        for (auto& i: outputArray.at(index)) {
            BOOST_REQUIRE_EQUAL(i, v.at(anotherIndex));
            anotherIndex++;
        }
        index++;
    }
}

BOOST_AUTO_TEST_SUITE_END()  /* NOLINT */