#define BOOST_TEST_MODULE version_boost

#include "lib.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(version_boost)

BOOST_AUTO_TEST_CASE(version_boost) { BOOST_CHECK(version() > 0); }
}