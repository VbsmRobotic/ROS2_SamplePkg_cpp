#include "number_publisher/number_publisher.hpp"
#include <chrono>

namespace number_publisher
{

NumberPublisher::NumberPublisher()
: Node("number_publisher_node")
{
  // Load parameters from YAML file
  loadParameters();
  
  // Create publisher
  publisher_ = this->create_publisher<std_msgs::msg::Int32>(
    topic_name_, 10);
  
  // Create timer
  timer_ = this->create_wall_timer(
    std::chrono::milliseconds(static_cast<int>(1000.0 / publish_rate_)),
    std::bind(&NumberPublisher::timerCallback, this));
    
  RCLCPP_INFO(this->get_logger(), "Number Publisher started");
  RCLCPP_INFO(this->get_logger(), "Publishing to topic: %s", topic_name_.c_str());
  RCLCPP_INFO(this->get_logger(), "Number 1: %d, Number 2: %d", number1_, number2_);
}

void NumberPublisher::loadParameters()
{
  // Declare parameters with default values
  this->declare_parameter("number1", 5);
  this->declare_parameter("number2", 10);
  this->declare_parameter("topic_name", "sum_topic");
  this->declare_parameter("publish_rate", 1.0);
  
  // Get parameters
  number1_ = this->get_parameter("number1").as_int();
  number2_ = this->get_parameter("number2").as_int();
  topic_name_ = this->get_parameter("topic_name").as_string();
  publish_rate_ = this->get_parameter("publish_rate").as_double();
}

void NumberPublisher::timerCallback()
{
  auto message = std_msgs::msg::Int32();
  message.data = number1_ + number2_;
  
  publisher_->publish(message);
  RCLCPP_INFO(this->get_logger(), "Published: %d + %d = %d", 
              number1_, number2_, message.data);
}

} // namespace number_publisher

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<number_publisher::NumberPublisher>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
} 