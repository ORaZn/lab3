#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>
#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>
#include <moveit_visual_tools/moveit_visual_tools.h>
#include "ros/ros.h"
#include <vector>

int main(int argc, char **argv){
    ros::init(argc, argv, "move_group_interface_tutorial");
    ros::NodeHandle node_handle;
    ros::AsyncSpinner spinner(0);
    spinner.start();
    static const std::string PLANNING_GROUP = "snake_body";
    moveit::planning_interface::MoveGroupInterface move_group(PLANNING_GROUP);
    const robot_state::JointModelGroup *joint_model_group = move_group.getCurrentState()->getJointModelGroup(PLANNING_GROUP);
    geometry_msgs::PoseStamped current_pose;
    current_pose = move_group.getCurrentPose();
    std::vector<std::pair<double,double>> relativecoordinates = {{-0.8,0},{0,0.2},{0.5,0},{0,-0.2}};
    geometry_msgs::Pose start_pose = move_group.getCurrentPose().pose;
    geometry_msgs::Pose target_pose = start_pose;
    std::vector<geometry_msgs::Pose> waypoints;
    for(auto coordinate : relativecoordinates){
        target_pose.position.x += coordinate.first;
        target_pose.position.y += coordinate.second;
        waypoints.push_back(target_pose);
    }

    moveit_msgs::RobotTrajectory trajectory;
    double fraction = move_group.computeCartesianPath(waypoints,0.01,0.0,trajectory);
    //sleep(15.0);
    moveit::planning_interface::MoveGroupInterface::Plan goal_plan;
    goal_plan.trajectory_ = trajectory;
    move_group.execute(goal_plan);
    ROS_INFO("Done");
    ros::shutdown();
    return 0;
}