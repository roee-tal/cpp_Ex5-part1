#include "doctest.h"
#include <iostream>
#include "OrgChart.hpp"
using namespace std;
using namespace ariel;

TEST_CASE("good input"){
    OrgChart organization1;

    SUBCASE("level order"){
    CHECK_NOTHROW(organization1.add_root("CEO")); // just for start a root
    CHECK_NOTHROW(organization1.add_sub("CEO", "CTO"));
    CHECK_NOTHROW(organization1.add_sub("CEO", "CFO"));
    CHECK_NOTHROW(organization1.add_sub("CEO", "COO"));
    CHECK_NOTHROW(organization1.add_sub("CTO", "VP_SW"));
    CHECK_NOTHROW(organization1.add_sub("COO", "VP_BI"));
   vector<string>l_order;
    for (auto i = organization1.begin_level_order(); i != organization1.end_level_order(); ++i)
    {
      l_order.push_back(*i);
    }
          CHECK_EQ(l_order.at(0), "CEO");
          CHECK_EQ(l_order.at(1), "CTO");
          CHECK_EQ(l_order.at(2), "CFO");
          CHECK_EQ(l_order.at(3), "COO");
          CHECK_EQ(l_order.at(4), "VP_SW");
          CHECK_EQ(l_order.at(5),"VP_BI");
    }
    SUBCASE("reverse order"){
    CHECK_NOTHROW(organization1.add_root("CEO")); // just for start a root
    CHECK_NOTHROW(organization1.add_sub("CEO", "CTO"));
    CHECK_NOTHROW(organization1.add_sub("CEO", "CFO"));
    CHECK_NOTHROW(organization1.add_sub("CEO", "COO"));
    CHECK_NOTHROW(organization1.add_sub("CTO", "VP_SW"));
    CHECK_NOTHROW(organization1.add_sub("COO", "VP_BI"));
    vector<string>r_order;
    for (auto i = organization1.begin_reverse_order(); i != organization1.reverse_order(); ++i)
    {
     r_order.push_back(*i);
    }
          CHECK_EQ(r_order.at(5), "CEO");
          CHECK_EQ(r_order.at(4), "COO");
          CHECK_EQ(r_order.at(3), "CFO");
          CHECK_EQ(r_order.at(2), "CTO");
          CHECK_EQ(r_order.at(1), "VP_BI");
          CHECK_EQ(r_order.at(0),"VP_SW");
    }
    SUBCASE("preorder"){
    CHECK_NOTHROW(organization1.add_root("CEO")); // just for start a root
    CHECK_NOTHROW(organization1.add_sub("CEO", "CTO"));
    CHECK_NOTHROW(organization1.add_sub("CEO", "CFO"));
    CHECK_NOTHROW(organization1.add_sub("CEO", "COO"));
    CHECK_NOTHROW(organization1.add_sub("CTO", "VP_SW"));
    CHECK_NOTHROW(organization1.add_sub("COO", "VP_BI"));
    vector<string>p_order;
    for (auto i = organization1.begin_preorder(); i != organization1.end_preorder(); ++i)
    {
     p_order.push_back(*i);
    }
          CHECK_EQ(p_order.at(0), "CEO");
          CHECK_EQ(p_order.at(1), "CTO");
          CHECK_EQ(p_order.at(2), "VP_SW");
          CHECK_EQ(p_order.at(3), "CFO");
          CHECK_EQ(p_order.at(4), "COO");
          CHECK_EQ(p_order.at(5),"VP_BI");
    }

}
TEST_CASE("bad input"){
    OrgChart organization1;
    CHECK_NOTHROW(organization1.add_root("CEO"));
    CHECK_NOTHROW(organization1.add_sub("CEO", "CTO"));
    CHECK_NOTHROW(organization1.add_sub("CEO", "CFO"));
    CHECK_THROWS(organization1.add_sub("CP", "CL"));
    CHECK_THROWS(organization1.add_sub("LP", "D"));
    CHECK_THROWS(organization1.add_sub("D", "CEO"));
}