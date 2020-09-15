#include "ros/ros.h"
#include "std_msgs/Float64.h"

double X;

void jointCallback(const std_msgs::Float64 msg){
    if(msg.data > X) X=msg.data;
}

int main(int argc, char **argv){
    X = 0;

    ros::init(argc, argv, "joint_cmd_sender");

    ros::NodeHandle n;

    ros::Publisher cmd_pub4 = n.advertise<std_msgs::Float64>("/robot/joint4_position_controller/command", 100);

    ros::Subscriber cmd_sub = n.subscribe("joint_cmd_lab3", 1000, jointCallback);

    ros::Rate loop_rate(10);

    while(ros::ok()){
        std_msgs::Float64 joint_angle;
        joint_angle.data = X;
        cmd_pub4.publish(joint_angle);
        ROS_INFO("sending command to joint4");
        ros::spinOnce();
        loop_rate.sleep();
    }
}