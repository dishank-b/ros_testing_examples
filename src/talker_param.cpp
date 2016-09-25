#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>


int main(int argc, char **argv)
{
  int count;
  ros::init(argc, argv, "talker_param");

  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

  ros::Rate loop_rate(10);
  n.getParam("/talking/count", count);
  
  while (ros::ok())
  {
    std_msgs::String msg;
    std::cout << count;
    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());

    chatter_pub.publish(msg);
    count = count +5;
    ros::spinOnce();

    loop_rate.sleep();
    
  }


  return 0;
}
