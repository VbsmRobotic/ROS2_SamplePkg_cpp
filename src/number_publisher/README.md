# Number Publisher Package

A simple ROS2 C++ package that demonstrates object-oriented programming concepts by creating a publisher and subscriber system. The package loads two integer numbers from a YAML configuration file and publishes their sum to a specified topic.

## Package Description
This package contains:
- **NumberPublisher**: A C++ class that loads two integers from a YAML file and publishes their sum
- **NumberSubscriber**: A C++ class that subscribes to the sum topic and displays the received values
- **Configuration**: YAML file for parameter configuration
- **Launch**: Python launch file to start both nodes simultaneously

## Package Features
✅ Object-oriented C++ implementation with separate classes for publisher and subscriber
✅ YAML configuration for loading two integers (15, 25) and other parameters
✅ Configurable topic name as a string parameter (sum_topic)
✅ Publishes the sum of the two loaded integers
✅ Complete documentation with tables for publisher and subscriber information
✅ Launch file to run both nodes together
✅ Proper ROS2 structure following best practices

## Publisher Information

| Field | Value |
|-------|-------|
| **Node Name** | `number_publisher_node` |
| **Topic Name** | `sum_topic` (configurable) |
| **Message Type** | `std_msgs/Int32` |
| **Publish Rate** | 2.0 Hz (configurable) |
| **Parameters** | `number1`, `number2`, `topic_name`, `publish_rate` |

## Subscriber Information

| Field | Value |
|-------|-------|
| **Node Name** | `number_subscriber_node` |
| **Topic Name** | `sum_topic` |
| **Message Type** | `std_msgs/Int32` |
| **Function** | Displays received sum values |

## Building and Running

### Build the package:
```bash
cd sample_cpp
colcon build --packages-select number_publisher
source install/setup.bash
```

### Run the package:
```bash
# Option 1: Using launch file (recommended)
ros2 launch number_publisher number_publisher_launch.py

# Option 2: Run nodes individually
ros2 run number_publisher number_publisher_node
ros2 run number_publisher number_subscriber_node
```

### Monitor topics:
```bash
ros2 topic list
ros2 topic echo /sum_topic
```

## Configuration

Edit the `config/numbers.yaml` file to modify:
- The two numbers to be added
- The topic name
- The publish rate

## Author

**Your Name**  
Email: your.email@example.com  
GitHub: [yourusername](https://github.com/yourusername)

## License

This package is licensed under the Apache License 2.0. 