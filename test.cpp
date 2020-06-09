#include "TXLib.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "functions.hpp"
#include <algorithm>

TEST_CASE("Something works") {
    int DATA_SIZE = 350;
    std::vector<numbers> a(DATA_SIZE);
    Fill (a, a.size());
    SortB (a, a.size());
    REQUIRE(std::is_sorted(a.begin(), a.end()));
    Fill (a, a.size());
    SortQ (a, a.size(), 0);
    REQUIRE(std::is_sorted(a.begin(), a.end()));
    Fill (a, a.size());
    SortPyr (a, a.size());
    REQUIRE(std::is_sorted(a.begin(), a.end()));
    Fill (a, a.size());
    SortPyr (a, a.size());
    REQUIRE(std::is_sorted(a.begin(), a.end()));
    Fill (a, a.size());
    SortQ (a, a.size(), 0);
    REQUIRE(std::is_sorted(a.begin(), a.end()));
    Fill (a, a.size());
    SortS (a, a.size());
    REQUIRE(std::is_sorted(a.begin(), a.end()));
    Fill (a, a.size());
    SortCo (a, a.size());
    REQUIRE(std::is_sorted(a.begin(), a.end()));
    Fill (a, a.size());
    SortPyr (a, a.size());
    REQUIRE(std::is_sorted(a.begin(), a.end()));
    Fill (a, a.size());
    SortGn (a, a.size());
    REQUIRE(std::is_sorted(a.begin(), a.end()));}
