#include <geometry/Utils.h>
#include <catch.hpp>

/**
 * Tests equals
 */
TEST_CASE("equals", "[Utils]")
{
    REQUIRE(equals(1.101, 1.101, 0));
    REQUIRE(equals(1.101, 0, 1.101));
    REQUIRE_FALSE(equals(1.101, 0, 1.100));
}

/**
 * Tests getOrDefault
 */
TEST_CASE("getOrDefault", "[Utils]")
{
    double val = 1;

    double* ptr = &val;
    REQUIRE(getOrDefault(ptr, 2.) == 1.);

    ptr = nullptr;
    REQUIRE(getOrDefault(ptr, 2.) == 2.);
}