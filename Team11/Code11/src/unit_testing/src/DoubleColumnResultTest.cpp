#include "DoubleColumnResult.h"
#include "catch.hpp"
#include "QueryElement.h"
#include <unordered_set>

using namespace std;
TEST_CASE("testDoubleColumnResultToString") {
    DoubleColumnResult test = DoubleColumnResult("a", "b");
    cout << "test: \n";
    test.add("a", "b", QueryElement(1), QueryElement("heh"));
    test.add("a", "b", QueryElement(1), QueryElement("heh2"));
    test.add("a", "b", QueryElement(1), QueryElement("heh3"));
    test.add("a", "b", QueryElement(1), QueryElement("heh4"));
    test.add("a", "b", QueryElement(1), QueryElement("heh5"));
    test.add("b", "a", QueryElement(80), QueryElement("heh"));
    cout << test.to_string();
    test.erase("a", QueryElement(1));
    cout << test.to_string();
    REQUIRE(true);
}

TEST_CASE("testDoubleColumnResultIntersect") {
    DoubleColumnResult test1 = DoubleColumnResult("a", "b", {make_pair(QueryElement(6), QueryElement(4)),
                                                            make_pair(QueryElement(3), QueryElement(4)),
                                                             make_pair(QueryElement(7), QueryElement(4)),
                                                             make_pair(QueryElement(20), QueryElement(15)),
                                                             make_pair(QueryElement("random string1"), QueryElement(4)),
                                                            make_pair(QueryElement(10), QueryElement(11)),});
    DoubleColumnResult test2 = DoubleColumnResult("a", "b", {make_pair(QueryElement(6), QueryElement(4)),
                                                             make_pair(QueryElement(3), QueryElement(4)),
                                                             make_pair(QueryElement(20), QueryElement(15)),
                                                             make_pair(QueryElement(10), QueryElement(15)),
                                                             make_pair(QueryElement(3600), QueryElement("random string2")),
                                                             make_pair(QueryElement(11), QueryElement(11)),});
    cout << "test1: " << endl << test1.to_string();
    cout << "test2: " << endl << test2.to_string();
    //cout << "intersect: " << endl << DoubleColumnResult::intersectOf(test1, test2).to_string();
    REQUIRE(true);
}


