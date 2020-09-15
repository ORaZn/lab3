#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include <math.h>

#define pi 3.1416

int main(int argc, char **argv){

    ros::init(argc, argv, "joint_cmd_sender_sine");

    ros::NodeHandle n;

    ros::Publisher cmd_pub4 = n.advertise<std_msgs::Float64>("/robot/joint4_position_controller/command", 100);

    ros::Rate loop_rate(10);

    ros::Time begin = ros::Time::now();

    while(ros::ok()){
        std_msgs::Float64 joint_angle;
        joint_angle.data = sin (2*pi*(ros::Time::now() - begin).toSec());
        cmd_pub4.publish(joint_angle);
        ros::spinOnce();
        loop_rate.sleep();
    }
}