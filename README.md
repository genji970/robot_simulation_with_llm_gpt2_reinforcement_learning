in progress not end

After colcon build `source install/setup.bash` is necessary. since in my case, there was an error, "Package 'robot' not found"


## Intermediate result

VirtualBox:~/robot_ws$ ros2 run robot robot_node<br>
[INFO] [1738687624.749665976] [robot_node]: Robot Node has started.
Successfully loaded URDF for robot: robot
[INFO] [1738687624.764242557] [robot_node]: URDF successfully parsed.
[INFO] [1738687631.349815891] [rclcpp]: signal_handler(signum=2)

## third change
add gazebo_spawn.cpp in order to simulate robot in gazebo env.

## Next step
0) change xacro, urdf
1) simulation in gazebo
2) add llm from https://github.com/genji970/llm_data_collecting-processing_inference
3) add rl method such as ppo/actor critic

## mathematics
1) gravity(vector calculation)

2) culvature : wondering if it is needed in gazebo since it's a flat world(for simple background, do not consider like a ball or something)

3) velocity. I'm not sure but jacobian is needed in some cases.
   according to chatgpt, v of end effector = jacobian mat * v of joint.(I'm not sure. I forgot a lot).<br> if jacobian mat -> homogeneous coordinate -> square mat -> inverse process can be also calculated

   jacobian is needed since each joint has each orthogonal coordinate(in this case orthonormal?). so Jacobian mat is needed.
