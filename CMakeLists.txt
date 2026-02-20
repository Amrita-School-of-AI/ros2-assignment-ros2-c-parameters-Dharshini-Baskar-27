cmake_minimum_required(VERSION 3.8)
project(ros2_parameters)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

# create executable (AUTOGRADER EXPECTS THIS NAME)
add_executable(param_node src/param_node.cpp)

# link dependencies
ament_target_dependencies(param_node rclcpp)

# install target
install(TARGETS
  param_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
