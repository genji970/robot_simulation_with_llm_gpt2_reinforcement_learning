#include "robot/robot_node.hpp"

RobotNode::RobotNode() : Node("robot_node")
{
    RCLCPP_INFO(this->get_logger(), "Robot Node has started.");

    std::string urdf_path = "src/robot/urdf/robot.urdf";
    if (!URDFParser::parseURDF(urdf_path)) {
        RCLCPP_ERROR(this->get_logger(), "Failed to parse URDF.");
    } else {
        RCLCPP_INFO(this->get_logger(), "URDF successfully parsed.");
    }
}

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<RobotNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
