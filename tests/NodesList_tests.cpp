#include "NodesList.hpp"

#include <gtest/gtest.h>

TEST(NodesList, check_create_size_and_push_size_and_element)
{
    std::list<int> a;
    int element;
    size_t s1, s2, s3;

    s1 = a.size();
    a.push_back(2);
    s2 = a.size();
    element = *a.begin();
    a.pop_back();
    s3 = a.size();


    ASSERT_EQ(s1, 0);
    ASSERT_EQ(s2, 1);
    ASSERT_EQ(s3, 0);
    ASSERT_EQ(element, 2);    
}

TEST(NodesList, check_iterator_arifmetic)
{
    std::list<int> a;
    int mas[3];

    a.push_back(3);
    a.push_back(0);
    a.push_back(2);

    mas[0] = *a.begin();
    mas[1] = *(++a.begin());
    mas[2] = *(--a.end());

    ASSERT_EQ(mas[0], 3);
    ASSERT_EQ(mas[1], 0);
    ASSERT_EQ(mas[2], 2);
}

TEST(NodesList, check_insert)
{
    std::list<int> a;
    int el1;
    size_t s1;

    a.insert(a.begin(), 1);    
    el1 = *a.begin();
    s1 = a.size();
    a.pop_back();

    ASSERT_EQ(el1, 1);
    ASSERT_EQ(s1, 1);
};

TEST(NodesList, check_erase)
{
    std::list<int> a;
    size_t s1;

    a.push_back(1);
    a.erase(a.begin());
    s1 = a.size();

    ASSERT_EQ(s1, 0);
}

TEST(NodesList, pop_push_front)
{
    std::list<int> a;
    size_t s1, s2;
    int el1;    
    a.push_front(3);
    el1 = *a.begin();
    s1 = a.size();
    a.pop_front();
    s2 = a.size();

    ASSERT_EQ(s1, 1);
    ASSERT_EQ(s2, 0);
    ASSERT_EQ(el1, 3);
}