#include <aslam/common/channel-declaration.h>
#include <aslam/common/entrypoint.h>
#include <aslam/common/eigen-helpers.h>

DECLARE_CHANNEL(TEST, Eigen::Matrix2Xd);

TEST(Channel, FailUnavailableChannel) {
aslam::channels::ChannelGroup channels;
EXPECT_DEATH(aslam::channels::get_TEST_Data(channels), "^");
}

TEST(Channel, AddChannel) {
aslam::channels::ChannelGroup channels;
EXPECT_DEATH(aslam::channels::get_TEST_Data(channels), "^");
aslam::channels::add_TEST_Channel(&channels);
Eigen::Matrix2Xd& data = aslam::channels::get_TEST_Data(channels);
}

TEST(Channel, HasChannelAddChannelExists) {
aslam::channels::ChannelGroup channels;
EXPECT_FALSE(aslam::channels::has_TEST_Channel(channels));
aslam::channels::add_TEST_Channel(&channels);
EXPECT_TRUE(aslam::channels::has_TEST_Channel(channels));
}

TEST(Channel, SetRetrieveChannel) {
aslam::channels::ChannelGroup channels;
aslam::channels::add_TEST_Channel(&channels);
Eigen::Matrix2Xd& data = aslam::channels::get_TEST_Data(channels);
data.setRandom();
Eigen::Matrix2Xd data2 = data;
Eigen::Matrix2Xd& data3 = aslam::channels::get_TEST_Data(channels);
EXPECT_TRUE(aslam::common::MatricesEqual(data3, data2, 1e-8));
}

ASLAM_UNITTEST_ENTRYPOINT
