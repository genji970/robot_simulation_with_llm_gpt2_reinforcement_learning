cmake_minimum_required(VERSION 3.5)
project(robot)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(gazebo_msgs REQUIRED)
find_package(std_msgs REQUIRED)

# Include TinyXML2 manually (since it's a system library)
include_directories(include)
include_directories(/usr/include)
link_directories(/usr/lib/x86_64-linux-gnu)

# urdf_parser as a library
add_library(urdf_parser src/urdf_parser.cpp)
target_link_libraries(urdf_parser tinyxml2)
ament_target_dependencies(urdf_parser rclcpp std_msgs)

# robot_node
add_executable(robot_node src/robot_node.cpp)
target_link_libraries(robot_node urdf_parser tinyxml2)
ament_target_dependencies(robot_node rclcpp std_msgs)

# gazebo_spawn
add_executable(gazebo_spawn src/gazebo_spawn.cpp)
target_link_libraries(gazebo_spawn tinyxml2)
ament_target_dependencies(gazebo_spawn rclcpp gazebo_msgs)

install(TARGETS
  robot_node
  gazebo_spawn
  RUNTIME DESTINATION lib/${PROJECT_NAME})

install(TARGETS urdf_parser
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

ament_package()
