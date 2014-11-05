#include <stdio.h>
#include <stdlib.h>

#include "TesMacros.h"
#include "FloydWarshallFile.h"

TEST_INIT("FloydWarshallFile Tests");

void Test_FloydWarshallFile_Load() {

    PFloydWarshallData data = fw_load("A:/Projects/CLang/FloydWarshall/tests/test-load.grh");

    TEST_ASSERT(data);
    TEST_ASSERT(fw_size(data) == 6)

    TEST_ASSERT(fw_get_dist(data, 0, 1) == 1);
    TEST_ASSERT(fw_get_dist(data, 1, 0) == 2);
    TEST_ASSERT(fw_get_dist(data, 1, 2) == 3);
    TEST_ASSERT(fw_get_dist(data, 1, 3) == -4);
    TEST_ASSERT(fw_get_dist(data, 3, 1) == 5);
    TEST_ASSERT(fw_get_dist(data, 2, 3) == 6);
    TEST_ASSERT(fw_get_dist(data, 2, 4) == 7);
    TEST_ASSERT(fw_get_dist(data, 3, 5) == 9);

    TEST_ASSERT(fw_get_next(data, 0, 1) == 1);
    TEST_ASSERT(fw_get_next(data, 1, 0) == 0);
    TEST_ASSERT(fw_get_next(data, 1, 2) == 2);
    TEST_ASSERT(fw_get_next(data, 1, 3) == 3);
    TEST_ASSERT(fw_get_next(data, 3, 1) == 1);
    TEST_ASSERT(fw_get_next(data, 2, 3) == 3);
    TEST_ASSERT(fw_get_next(data, 2, 4) == 4);
    TEST_ASSERT(fw_get_next(data, 3, 5) == 5);
}

TEST_BEGIN;

TEST(Test_FloydWarshallFile_Load);

TEST_END;