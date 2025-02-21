in progress not end

After colcon build `source install/setup.bash` is necessary. since in my case, there was an error, "Package 'robot' not found"

tinyxml was the problem when building. make sure in CMakeLists.txt, tinyxml is in find_libraries not find_packages

## how to run ##

# Gazebo 실행 (Terminal 1)
`ros2 launch gazebo_ros gazebo.launch.py gui:=true`

# 기존 로봇 제거 (Terminal 2)
`ros2 service call /delete_entity gazebo_msgs/srv/DeleteEntity "{name: 'my_robot'}"`

# 로봇 스폰
`ros2 run gazebo_ros spawn_entity.py -entity my_robot -file ~/ros_ws/src/robot/urdf/robot.urdf -x 0 -y 0 -z 1`

## third change
add gazebo_spawn.cpp in order to simulate robot in gazebo env. 

## Next step
0) change xacro, urdf
1) simulation in gazebo
2) add llm
3) add rl method such as ppo/actor critic

## mathematics
1) gravity(vector calculation)

2) culvature : wondering if it is needed in gazebo since it's a flat world(for simple background, do not consider like a ball or something)

3) velocity. I'm not sure but jacobian is needed in some cases.
   according to chatgpt, v of end effector = jacobian mat * v of joint.(I'm not sure. I forgot a lot).<br> if jacobian mat -> homogeneous coordinate -> square mat -> inverse process can be also calculated

   jacobian is needed since each joint has each orthogonal coordinate(in this case orthonormal?). so Jacobian mat is needed.
