#include "NodesList.hpp"

#include <gtest/gtest.h>

TEST(NodesList, check_push_size_element_positive)
{
    NodesList nd;
    int element;
    size_t s1, s2, s3;
    

    s1 = nd.size();
    nd.push_back(3);
    element = *nd.begin();
    s2 = nd.size();
    nd.pop_back();
    s3 = nd.size();;

    ASSERT_EQ(s2-s1, 1);
    ASSERT_EQ(s1,s3);
    ASSERT_EQ(element, 3);
}

TEST(NodesList, check_incorected_index_insert)
{
    NodesList nd;

    ASSERT_THROW(nd.begin()--, std::exception);
    ASSERT_THROW(nd.end()++, std::exception);
}

TEST(NodesList, check_append_to_self_node)
{
    NodesList nd;

    nd.push_back(1);
    std::list<int>::iterator it = nd.begin();
    nd.pop_back();
    ASSERT_THROW(nd.insert(it, 3), std::exception);
};





