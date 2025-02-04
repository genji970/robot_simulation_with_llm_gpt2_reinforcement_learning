cmake_minimum_required(VERSION 3.5)
project(robot)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

# tinyxml2 라이브러리 수동 검색
find_path(TINYXML2_INCLUDE_DIR NAMES tinyxml2.h)
find_library(TINYXML2_LIBRARY NAMES tinyxml2)

if(NOT TINYXML2_LIBRARY)
  message(FATAL_ERROR "tinyxml2 라이브러리를 찾을 수 없습니다.")
endif()

include_directories(${TINYXML2_INCLUDE_DIR})
include_directories(include)  # 헤더 파일 경로 추가

add_executable(robot_node src/robot_node.cpp src/urdf_parser.cpp)

# tinyxml2 추가 (직접 링크)
target_link_libraries(robot_node ${TINYXML2_LIBRARY})

# ament dependencies
ament_target_dependencies(robot_node rclcpp)

install(TARGETS
  robot_node
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY launch/
  DESTINATION share/${PROJECT_NAME}/launch
)

install(DIRECTORY urdf/
  DESTINATION share/${PROJECT_NAME}/urdf
)

ament_package()
