/*
  This is the code for testing the utility offered by bounding_boxes_to_world_coordinates_node.
*/

#include <ros/ros.h>

// Custom msgs
#include <bounding_boxes_to_world_coordinates_msgs/bounding_box.h>
#include <bounding_boxes_to_world_coordinates_msgs/bounding_box_collection.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "BoundingBoxPublisherNode");
  ros::NodeHandle n;
  ros::Publisher bounding_box_pub_ = n.advertise<bounding_boxes_to_world_coordinates_msgs::bounding_box_collection>("/bounding_box/collection", 1);
  ros::Rate loop_rate(100);

  int count = 0;
  while (ros::ok())
  {
    /**
     * This is a message object. You stuff it with data, and then publish it.
     */
    bounding_boxes_to_world_coordinates_msgs::bounding_box_collection bounding_box_collection;
    bounding_boxes_to_world_coordinates_msgs::bounding_box bounding_box;

    bounding_box.upper_left_corner_x = 300;
    bounding_box.upper_left_corner_y = 220;
    bounding_box.bounding_box_width = 40;
    bounding_box.bounding_box_height = 40;

    bounding_box_collection.bounding_box.push_back(bounding_box);
    bounding_box_collection.header.stamp = ros::Time::now();

    std::cout << "upper_left_corner_x: " << bounding_box_collection.bounding_box[0].upper_left_corner_x << std::endl;

    /**
     * The publish() function is how you send messages. The parameter
     * is the message object. The type of this object must agree with the type
     * given as a template parameter to the advertise<>() call, as was done
     * in the constructor above.
     */
    bounding_box_pub_.publish(bounding_box_collection);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
    std::cout << "count: " << count << std::endl;
  }

  return 0;

}