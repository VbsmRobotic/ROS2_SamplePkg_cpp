from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    # Get the package directory
    pkg_share = get_package_share_directory('number_publisher')
    
    # Declare launch arguments
    config_file = LaunchConfiguration('config_file')
    
    # Declare the launch argument
    declare_config_file_cmd = DeclareLaunchArgument(
        'config_file',
        default_value=os.path.join(pkg_share, 'config', 'numbers.yaml'),
        description='Path to the YAML configuration file'
    )
    
    # Create the publisher node
    publisher_node = Node(
        package='number_publisher',
        executable='number_publisher_node',
        name='number_publisher_node',
        parameters=[config_file],
        output='screen'
    )
    
    # Create the subscriber node
    subscriber_node = Node(
        package='number_publisher',
        executable='number_subscriber_node',
        name='number_subscriber_node',
        output='screen'
    )
    
    # Create and return launch description
    return LaunchDescription([
        declare_config_file_cmd,
        publisher_node,
        subscriber_node
    ]) 