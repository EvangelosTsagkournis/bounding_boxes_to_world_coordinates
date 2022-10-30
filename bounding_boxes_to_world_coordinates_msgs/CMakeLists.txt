cmake_minimum_required(VERSION 3.0.2)
project(bounding_boxes_to_world_coordinates_msgs)


find_package(catkin REQUIRED COMPONENTS
  message_generation
  std_msgs
)

add_message_files(
  FILES
  bounding_box.msg
  bounding_box_collection.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS 
  std_msgs message_runtime
)
