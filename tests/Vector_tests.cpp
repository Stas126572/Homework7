#include "Vector.hpp"
#include <gtest/gtest.h>

TEST(Vector, check_create_size_and_index)
{
    std::vector<int> v;
    size_t s1, s2, s3;
    int element;
    s1 = v.size();
    v.push_back(5);
    element = v[0];
    s2 = v.size();
    v.pop_back();
    s3 = v.size();

    ASSERT_EQ(s1, 0);
    ASSERT_EQ(s2, 1);
    ASSERT_EQ(element, 5);
    ASSERT_EQ(s3, 0);
}

TEST(Vector, check_resize_and_capacity)
{
    std::vector<int> b;
    size_t s1, s2;
    int element;

    b.resize(3);
    s1 = b.size();
    element = b[1];
    b.reserve(10);
    s2 = b.capacity();

    ASSERT_EQ(s1, 3);
    ASSERT_EQ(element, 0);
    ASSERT_EQ(s2, 10);
}

TEST(Vector, check_insert_and_erase)
{
    std::vector<int> v;
    int element;


    v.insert(v.begin(), 5);
    element = v[0];
    ASSERT_EQ(element, 5);
}

TEST(Vector, check_at_and_empty)
{
    std::vector<int> v;
    bool is_empty;
    
    is_empty = v.empty();

    ASSERT_TRUE(is_empty);
    ASSERT_THROW(v.at(-1), std::out_of_range);
}

