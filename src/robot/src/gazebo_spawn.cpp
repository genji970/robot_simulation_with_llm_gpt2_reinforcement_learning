#include <gazebo_msgs/srv/spawn_entity.hpp>
#include <rclcpp/rclcpp.hpp>
#include <fstream>
#include <sstream>

class GazeboSpawner : public rclcpp::Node
{
public:
    GazeboSpawner() : Node("gazebo_spawner")
    {
        client_ = this->create_client<gazebo_msgs::srv::SpawnEntity>("/spawn_entity");

        std::string model_path = "../urdf/robot.urdf";

        std::ifstream file(model_path);
        if (!file.is_open())
        {
            RCLCPP_ERROR(this->get_logger(), "Failed to open model file: %s", model_path.c_str());
            return;
        }

        std::stringstream buffer;
        buffer << file.rdbuf();
        file.close();
        std::string model_xml = buffer.str();

        auto request = std::make_shared<gazebo_msgs::srv::SpawnEntity::Request>();
        request->name = "robot";
        request->xml = model_xml;
        request->robot_namespace = "robot_ns";
        request->initial_pose.position.x = 0.0;
        request->initial_pose.position.y = 0.0;
        request->initial_pose.position.z = 0.5;

        while (!client_->wait_for_service(std::chrono::seconds(3)))
        {
            RCLCPP_WARN(this->get_logger(), "Waiting for Gazebo spawn_entity service...");
        }

        auto result_future = client_->async_send_request(request);
        RCLCPP_INFO(this->get_logger(), "Spawn request sent!");
    }

private:
    rclcpp::Client<gazebo_msgs::srv::SpawnEntity>::SharedPtr client_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<GazeboSpawner>());
    rclcpp::shutdown();
    return 0;
}
