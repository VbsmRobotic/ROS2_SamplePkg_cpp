#ifndef NUMBER_PUBLISHER_HPP_
#define NUMBER_PUBLISHER_HPP_

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32.hpp>
#include <string>

namespace number_publisher
{

class NumberPublisher : public rclcpp::Node
{
public:
  NumberPublisher();

private:
  void loadParameters();
  void timerCallback();
  
  rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
  
  int number1_;
  int number2_;
  std::string topic_name_;
  double publish_rate_;
};

} // namespace number_publisher

#endif // NUMBER_PUBLISHER_HPP_ 