#include <pluginlib/class_list_macros.h>
#include "social_planner.h"
using namespace std;

PLUGINLIB_EXPORT_CLASS(social_planner::SocialPlanner, nav_core::BaseGlobalPlanner)
    
namespace social_planner {
  SocialPlanner::SocialPlanner(){
  }
  
  SocialPlanner::SocialPlanner(std::string name, costmap_2d::Costmap2DROS* costmap_ros){
      initialize(name, costmap_ros);
  }
   
   
  void SocialPlanner::initialize(std::string name, costmap_2d::Costmap2DROS* costmap_ros){
  
    }
   
  bool SocialPlanner::makePlan(const geometry_msgs::PoseStamped& start, const geometry_msgs::PoseStamped& goal,  std::vector<geometry_msgs::PoseStamped>& plan ){
       plan.push_back(start);
      for (int i=0; i<30; i++){
        geometry_msgs::PoseStamped new_goal = goal;
        tf::Quaternion goal_quat = tf::createQuaternionFromYaw(1.57);
   
         new_goal.pose.position.x = 2.0;
         new_goal.pose.position.y = 2.0+(0.1*i);
   
         new_goal.pose.orientation.x = goal_quat.x();
         new_goal.pose.orientation.y = goal_quat.y();
         new_goal.pose.orientation.z = goal_quat.z();
         new_goal.pose.orientation.w = goal_quat.w();
   
        plan.push_back(new_goal);
      }
      plan.push_back(goal);
    return true;
    }
 };

