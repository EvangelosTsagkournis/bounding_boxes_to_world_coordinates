# Bounding Boxes to World Coordinates

## Description
This is the repository for the ROS package bounding_boxes_to_world_coordinates. The package makes use of a robot's kinect sensor and its localization to estimate the detected object's world coordinates (x and y). 

## How to install
Clone the repository into your catkin_ws. Then run the following command to build your workspace:
```
cd ~/catkin_ws && catkin_make
```

## How to use

The bounding boxes are expected to be published to the topic "/bounding_box/collection" by default. The package contains a special message type for the bounding boxes, with each bounding box requiring the upper left corner's x and y pixel coordinates as well as the width and height of the bounding box. Use the bounding_box_collection message to gather and publish all of the bounding boxes you wish to find their coordinates. The bounding_boxes_to_world_coordinates_node subscribes to the aforementioned topic and gathers the bounding boxes and publishes the same bounding boxes filled in with the world coordinates for each one to the topic "/bounding_box/collection_with_world_coordinates" by default.

## More information

Due to the kinect's limitation of about 5 meters for depth data, invalid or out of range values will result in world coordinates of 0 for both x and y.

The logic finds the middle pixel corresponding to each bounding box and finds a depth value. It may be possible that the depth value may not be correct due to irregularities in the shape of the object being detected. A classic scenario would be a ring or a donut whose hole faces the camera. Despite being able to detect such a shape, the bounding box would lead the logic to get an invalid value for the depth distance, possibly of some other object in the background or an out-of-range value. Such cases are not covered as of now.
