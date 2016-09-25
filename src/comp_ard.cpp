#include <ros/ros.h>
#include <std_msgs/Float64.h>

std_msgs::Float64 storing;

void get_frm_ard(const std_msgs::Float64::ConstPtr& msg)
{
	 storing.data = msg->data;
  ROS_INFO("I got [%f] as input, now doubling it.", storing.data);

}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "computer");
  ros::NodeHandle nh;
  ros::Subscriber sub = nh.subscribe("chatter", 1000, get_frm_ard);
  ros::spinOnce();

  
  ros::Publisher pub = nh.advertise<std_msgs::Float64>("sending", 1000);
  ros::Rate loop_rate(10);

while (ros::ok())
  {
    storing.data = 2*(storing.data);
    pub.publish(storing);
    ROS_INFO("Now, I'm sending [%f].", storing.data);
    ros::spinOnce();
    loop_rate.sleep();
}

}
