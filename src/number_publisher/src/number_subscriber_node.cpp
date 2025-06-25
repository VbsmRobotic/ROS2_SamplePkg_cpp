#include "number_publisher/number_subscriber.hpp"

namespace number_publisher
{

NumberSubscriber::NumberSubscriber()
: Node("number_subscriber_node")
{
  // Create subscription
  subscription_ = this->create_subscription<std_msgs::msg::Int32>(
    "sum_topic", 10, std::bind(&NumberSubscriber::topicCallback, this, std::placeholders::_1));
    
  RCLCPP_INFO(this->get_logger(), "Number Subscriber started");
  RCLCPP_INFO(this->get_logger(), "Subscribed to topic: sum_topic");
}

void NumberSubscriber::topicCallback(const std_msgs::msg::Int32::SharedPtr msg)
{
  RCLCPP_INFO(this->get_logger(), "Received sum: %d", msg->data);
}

} // namespace number_publisher

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<number_publisher::NumberSubscriber>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
} 