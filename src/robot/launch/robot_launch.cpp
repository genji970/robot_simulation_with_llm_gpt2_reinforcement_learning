#include <rclcpp/rclcpp.hpp>
#include "robot/robot_node.hpp"

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<RobotNode>();
    RCLCPP_INFO(node->get_logger(), "Robot Node has been launched.");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
