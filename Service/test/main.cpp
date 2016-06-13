#include <gtest/gtest.h>

TEST(SampleTestCase, SampleTest)
{
    EXPECT_EQ(1, 1) << "Testiranje radi!";
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
}