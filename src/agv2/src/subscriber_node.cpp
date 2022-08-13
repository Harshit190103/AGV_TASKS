#include "ros/ros.h"
#include "agv2/person_data.h"

void writeMessage(const agv2::person_data& person_data)
{
    ROS_INFO("NAME IS: %s", person_data.name.c_str());
    ROS_INFO("NAME IS: %i", person_data.age);
    ROS_INFO("NAME IS: %s", person_data.color.c_str());
}

int main(int argc ,char **argv)
{
    ros::init(argc, argv, "Subscriber");  // "publisher" is the name of node we choose"
    ros::NodeHandle nh;                  // started the node by creating this object   

    ros::Subscriber topic_pub = nh.subscribe("agv", 1000,writeMessage);
                                            //standard mssg    //name of topic we choose "agv" , seconf is que size teh number of message we print  // Call function which receive the message
    
    
    ros::spin();



                             
    return 0;
}