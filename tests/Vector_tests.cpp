#include "Vector.hpp"
#include <gtest/gtest.h>

TEST(Vector, push_pop)
{
    std::vector vc = {1};
    int element;
    size_t s1, s2, s3;

    s1 = vc.size();
    vc.push_back(1);
    element = vc[0];
    s2 = vc.size();
    vc.pop_back();
    s3 = vc.size();

    ASSERT_EQ(s2-s1, 1);
    ASSERT_EQ(element, 1);
    ASSERT_EQ(s3, s1);
}

TEST(Vector, indexes)
{
    std::vector vc = {1};
    
    EXPECT_THROW(vc[-1], std::exception);
    ASSERT_THROW(vc.at(-1), std::exception);
    ASSERT_THROW(vc.at(1), std::exception);
}

TEST(Vector, check_resize)
{
    std::vector vc = {1,2};
    vc.resize(3);
    EXPECT_EQ(vc[2], 0);
    vc.resize(1);
    ASSERT_THROW(vc.at(1), std::exception);
}