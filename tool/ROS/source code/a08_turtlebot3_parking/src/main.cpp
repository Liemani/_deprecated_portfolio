#include "Parking.h"

int main(int argc, char** argv) {
    int target_marker = 685;

    Parking turtlebot_parking(argc, argv, target_marker);

    while (ros::ok()) {
        ros::spinOnce();
        ROS_INFO("looping");
        if (turtlebot_parking.is_find_tag == false) {
            turtlebot_parking.get_tag();
        } else if (turtlebot_parking.is_move_to_target_angle == false) {
            turtlebot_parking.move_to_target_angle();
        } else if (turtlebot_parking.is_move_to_target_distance == false) {
            turtlebot_parking.move_to_target_distance();
        } else if (turtlebot_parking.is_turn_ninety_degree == false) {
            turtlebot_parking.turn_ninety_degree();
        } else if (turtlebot_parking.is_close_to_marker == false) {
            turtlebot_parking.close_to_marker();
        }
    }

    return 0;
}