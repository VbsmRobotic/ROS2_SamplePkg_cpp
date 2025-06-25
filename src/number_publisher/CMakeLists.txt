cmake_minimum_required(VERSION 3.8)
project(number_publisher)

# Set C++ standard to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

include_directories(
  include
)

# Create the publisher executable
add_executable(number_publisher_node src/number_publisher_node.cpp)
ament_target_dependencies(number_publisher_node rclcpp std_msgs)

# Create the subscriber executable
add_executable(number_subscriber_node src/number_subscriber_node.cpp)
ament_target_dependencies(number_subscriber_node rclcpp std_msgs)

# Install targets
install(TARGETS
  number_publisher_node
  number_subscriber_node
  DESTINATION lib/${PROJECT_NAME}
)

# Install directories
install(DIRECTORY
  config
  launch
  DESTINATION share/${PROJECT_NAME})

ament_package() 