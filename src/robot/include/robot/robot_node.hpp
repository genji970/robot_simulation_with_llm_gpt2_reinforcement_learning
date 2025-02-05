#ifndef ROBOT_NODE_HPP
#define ROBOT_NODE_HPP

#include <rclcpp/rclcpp.hpp>
#include "robot/urdf_parser.hpp"

class RobotNode : public rclcpp::Node
{
public:
    RobotNode();
};

#endif
