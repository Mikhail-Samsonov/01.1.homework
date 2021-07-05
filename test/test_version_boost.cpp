#define BOOST_TEST_MODULE test_version_boost

#include "../lib/lib.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_version_boost)

BOOST_AUTO_TEST_CASE(test_valid_version) { BOOST_CHECK(version() > 0); }
}