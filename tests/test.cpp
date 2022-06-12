#include <gtest/gtest.h>
#include "../sampler.h"

class SamplerTests : public ::testing::Test
{
protected:
    void SetUp() override
    {
        setMicros(1000 * 0);
    }
};

TEST_F(SamplerTests, Disabled)
{
    Sampler s;
    ASSERT_FALSE(s.shouldSample());
    setMicros(1000 * -1);
    ASSERT_FALSE(s.shouldSample());
}

TEST_F(SamplerTests, Enable_ZeroDelay)
{
    Sampler s;
    s.enable();
    ASSERT_TRUE(s.shouldSample());
    ASSERT_TRUE(s.shouldSample());
}

TEST_F(SamplerTests, Enable_WithDelay)
{
    Sampler s(100);
    s.enable();
    ASSERT_FALSE(s.shouldSample());
    setMicros(1000 * 100);
    ASSERT_TRUE(s.shouldSample());
    ASSERT_FALSE(s.shouldSample());
}

TEST_F(SamplerTests, EnableAndTrigger)
{
    Sampler s(100);
    s.enable_and_trigger();
    ASSERT_TRUE(s.shouldSample());
    ASSERT_FALSE(s.shouldSample());
    setMicros(1000 * 100);
    ASSERT_TRUE(s.shouldSample());
    ASSERT_FALSE(s.shouldSample());
}

TEST_F(SamplerTests, Frequency)
{
    Sampler s;
    s.setFrequency(10);
    s.enable();
    ASSERT_FALSE(s.shouldSample());
    setMicros(1000 * 100);
    ASSERT_TRUE(s.shouldSample());
    ASSERT_FALSE(s.shouldSample());
    setMicros(1000 * 200);
    ASSERT_TRUE(s.shouldSample());
    ASSERT_FALSE(s.shouldSample());
}

TEST_F(SamplerTests, TimeWraparound)
{
    Sampler s;
    s.setDelayMs(200);
    setMicros(1000 * -100);
    s.enable();
    ASSERT_FALSE(s.shouldSample());
    setMicros(1000 * 99);
    ASSERT_FALSE(s.shouldSample());
    setMicros(1000 * 100);
    ASSERT_TRUE(s.shouldSample());
    ASSERT_FALSE(s.shouldSample());
}