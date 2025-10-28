cmake_minimum_required(VERSION 3.8)
project(cpp_3nos)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(num1 src/num1.cpp)
ament_target_dependencies(num1 rclcpp std_msgs)

add_executable(num2 src/num2.cpp)
ament_target_dependencies(num2 rclcpp std_msgs)

add_executable(string src/string.cpp)
ament_target_dependencies(string rclcpp std_msgs)

install(TARGETS
  num1
  num2
  string
  DESTINATION lib/${PROJECT_NAME})

ament_package()
