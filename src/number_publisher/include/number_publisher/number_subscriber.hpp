#ifndef NUMBER_SUBSCRIBER_HPP_
#define NUMBER_SUBSCRIBER_HPP_

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32.hpp>

namespace number_publisher
{

class NumberSubscriber : public rclcpp::Node
{
public:
  NumberSubscriber();

private:
  void topicCallback(const std_msgs::msg::Int32::SharedPtr msg);
  
  rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr subscription_;
};

} // namespace number_publisher

#endif // NUMBER_SUBSCRIBER_HPP_ 