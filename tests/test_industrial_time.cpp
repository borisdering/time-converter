#include <gtest/gtest.h>
#include "industrial_time.h"

TEST(TimeConverterTest, ConvertsStandardToIndustrial) {
    ASSERT_EQ(146.75, standard_to_industrial(146, 45));
    ASSERT_EQ(148.68333333333334, standard_to_industrial(148, 41));
    ASSERT_EQ(148.00, standard_to_industrial(148, 00));
    ASSERT_EQ(0, standard_to_industrial(0, 0));
    ASSERT_EQ(0.98333333333333328, standard_to_industrial(0, 59));
    ASSERT_THROW(standard_to_industrial(0, 61), std::invalid_argument);
    ASSERT_THROW(standard_to_industrial(0, -100), std::invalid_argument);
}

TEST(TimeConverterTest, ConvertsIndustrialToStandard) {
    uint16_t hours, minutes;
    industrial_to_standard(146.75, hours, minutes);
    ASSERT_EQ(146, hours);
    ASSERT_EQ(45, minutes);

    hours = 0;
    minutes = 0;
    industrial_to_standard(148.68333333333334, hours, minutes);
    ASSERT_EQ(148, hours);
    ASSERT_EQ(41, minutes);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}