#include "ros/ros.h"
#include <beginner_tutorials/SensorMsg.h>

void chatterCallback(const beginner_tutorials::SensorMsg::ConstPtr& msg)
{
  ROS_INFO("I heard: [%d]", msg->data1);
}

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "cust_msg_listener");

  
  ros::NodeHandle n;

  
  ros::Subscriber sub = n.subscribe("transferring", 1000, chatterCallback);

  ros::spin();

  return 0;
}
