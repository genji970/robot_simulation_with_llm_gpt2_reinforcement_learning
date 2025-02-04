in progress not end

After colcon build `source install/setup.bash` is necessary. since in my case, there was an error, "Package 'robot' not found"


## Intermediate result

VirtualBox:~/robot_ws$ ros2 run robot robot_node
[INFO] [1738687624.749665976] [robot_node]: Robot Node has started.
Successfully loaded URDF for robot: robot
[INFO] [1738687624.764242557] [robot_node]: URDF successfully parsed.
[INFO] [1738687631.349815891] [rclcpp]: signal_handler(signum=2)

## Next step
0) change xacro, urdf
1) simulation in gazebo
2) add llm from https://github.com/genji970/llm_data_collecting-processing_inference
3) add rl method such as ppo/actor critic
