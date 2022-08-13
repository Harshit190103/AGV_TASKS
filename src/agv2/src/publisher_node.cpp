#include "ros/ros.h"
#include "agv2/person_data.h"

int main(int argc ,char **argv)
{
    ros::init(argc, argv, "Publisher");  // "publisher" is the name of node we choose"
    ros::NodeHandle nh;                  // started the node by creating this object   

    ros::Publisher topic_pub = nh.advertise<agv2::person_data>("agv", 1000);
                                            //standard mssg    //name of topic we choose "agv" , seconf is que size teh number of message we print
    
    ros::Rate loop_rate(1);  //publish a message afte each 1 second  
    while(ros::ok())  //run as long as we dont press ctrl c
    {
        agv2::person_data person_data;
        person_data.name = "HARSHIT";
        person_data.age = 19;
        person_data.color = "BLACk";

        topic_pub.publish(person_data);
        ros::spinOnce();
        loop_rate.sleep();

    }



                             
    return 0;
}