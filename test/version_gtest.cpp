#include "lib.h"
#include <gtest/gtest.h>

TEST(Version, Positive) { ASSERT_GT(version(), 0); }