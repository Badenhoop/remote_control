cmake_minimum_required(VERSION 2.8.3)
project(remote_control)

set(CMAKE_CXX_STANDARD 14)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

set(Boost_NO_SYSTEM_PATHS TRUE)
set(BOOST_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/vendor/boost_1_66_0")
add_subdirectory(vendor/asionet)
find_package(asionet PATHS ${PROJECT_BINARY_DIR}/vendor/asionet)

set(SOURCE_FILES
        include/remote_control/json.hpp
        include/remote_control/Message.h
        include/remote_control/Receiver.h
        include/remote_control/Sender.h
        include/remote_control/Utils.h
        src/Receiver.cpp
        src/Sender.cpp)

## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if your package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES remote_control_receiver
#  CATKIN_DEPENDS roscpp std_msgs
#  DEPENDS system_lib
)

include_directories(
  include
  ${asionet_INCLUDE_DIRS}
  ${catkin_INCLUDE_DIRS}
)

set(LIBRARIES
        ${catkin_LIBRARIES}
        ${asionet_LIBRARIES}
        ${CMAKE_THREAD_LIBS_INIT})

add_executable(sender_node src/SenderNode.cpp ${SOURCE_FILES})
add_executable(receiver_node src/ReceiverNode.cpp ${SOURCE_FILES})

target_link_libraries(sender_node ${LIBRARIES})
target_link_libraries(receiver_node ${LIBRARIES})
