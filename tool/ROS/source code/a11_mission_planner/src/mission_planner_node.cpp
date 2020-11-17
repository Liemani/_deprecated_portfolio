#include <ros/ros.h>
#include <std_msgs/Empty.h>
#include <geometry_msgs/Twist.h>
#include <bebop_msgs/Ardrone3PilotingStatePositionChanged.h>
#include <bebop_msgs/Ardrone3PilotingStateAltitudeChanged.h>
#include <bebop_msgs/Ardrone3PilotingStateAttitudeChanged.h>

#include <iostream>
#include <termio.h>

using std::cout;
using std::endl;

int input_data;
std_msgs::Empty emptyMsg;
geometry_msgs::Twist twistMsg;

ros::Publisher takeoff_pub;
ros::Publisher land_pub;
ros::Publisher reset_pub;
ros::Publisher cmd_vel_pub;

int getch() {
    int ch;

    struct termios buf, save;
    tcgetattr(0, &save);
    buf = save;

    buf.c_lflag &= ~(ICANON|ECHO);

    buf.c_cc[VMIN] = 1;
    buf.c_cc[VTIME] = 0;

    tcsetattr(0, TCSAFLUSH, &buf);
    ch = getchar();

    tcsetattr(0, TCSAFLUSH, &save);

    return ch;
}

void positionCallBack(const bebop_msgs::Ardrone3PilotingStatePositionChanged::ConstPtr& msg) {
    cout << "Seq: " << msg->header.seq << endl;
    cout << "Latitude: " << msg->latitude << endl;
    cout << "Longitude: " << msg->longitude << endl;
    cout << "Altitude: " << msg->altitude << endl;
    cout << "----------------" << endl;
}

void altitudeCallBack(const bebop_msgs::Ardrone3PilotingStateAltitudeChanged::ConstPtr& msg) {
    cout << "Seq: " << msg->header.seq << endl;
    cout << "Altitude: " << msg->altitude << endl;
    cout << "----------------" << endl;
}

void attitudeCallback(const bebop_msgs::Ardrone3PilotingStateAttitudeChanged::ConstPtr& msg) {
    cout << "Seq: " << msg->header.seq << endl;
    cout << "Roll: " << msg->roll << endl;
    cout << "Pitch: " << msg->pitch << endl;
    cout << "Yaw: " << msg->yaw << endl;
    cout << "----------------" << endl;
}

void publishing() {
    input_data = getch();
    if (input_data == 116) {    // takeoff
        takeoff_pub.publish(emptyMsg);
        return;
    } else if (input_data == 98) {    // land
        land_pub.publish(emptyMsg);
        return;
    } else if (input_data == 103) {    // reset
        reset_pub.publish(emptyMsg);
        return;
    } else if (input_data == 119) {    // forward
        twistMsg.linear.x = 0.5;
        twistMsg.linear.y = 0;
        twistMsg.linear.z = 0;
        twistMsg.angular.z = 0;
    } else if (input_data == 115) {    // backward
        twistMsg.linear.x = -0.5;
        twistMsg.linear.y = 0;
        twistMsg.linear.z = 0;
        twistMsg.angular.z = 0;
    } else if (input_data == 97) {    // leftward
        twistMsg.linear.x = 0;
        twistMsg.linear.y = 0.5;
        twistMsg.linear.z = 0;
        twistMsg.angular.z = 0;
    } else if (input_data == 100) {    // rightward
        twistMsg.linear.x = 0;
        twistMsg.linear.y = -0.5;
        twistMsg.linear.z = 0;
        twistMsg.angular.z = 0;
    } else if (input_data == 105) {    // upward
        twistMsg.linear.x = 0;
        twistMsg.linear.y = 0;
        twistMsg.linear.z = 0.5;
        twistMsg.angular.z = 0;
    } else if (input_data == 107) {    // downward
        twistMsg.linear.x = 0;
        twistMsg.linear.y = 0;
        twistMsg.linear.z = -0.5;
        twistMsg.angular.z = 0;
    } else if (input_data == 106) {    // turn left
        twistMsg.linear.x = 0;
        twistMsg.linear.y = 0;
        twistMsg.linear.z = 0;
        twistMsg.angular.z = 0.5;
    } else if (input_data == 108) {    // turn right
        twistMsg.linear.x = 0;
        twistMsg.linear.y = 0;
        twistMsg.linear.z = 0;
        twistMsg.angular.z = -0.5;
    } 

    cmd_vel_pub.publish(twistMsg);
}

int main(int argc, char** argv) {

    ros::init(argc, argv, "mission_planner");
    ros::NodeHandle nh;

    ros::Subscriber positionSub = nh.subscribe("/bebop/states/ardrone3/PilotingState/PositionChanged", 1, positionCallBack);
    ros::Subscriber altitudeSub = nh.subscribe("/bebop/states/ardrone3/PilotingState/AltitudeChanged", 1, altitudeCallBack);
    ros::Subscriber attitudeSub = nh.subscribe("/bebop/states/ardrone3/PilotingState/AttitudeChanged", 1, attitudeCallback);

    takeoff_pub = nh.advertise<std_msgs::Empty>("/bebop/takeoff", 1);
    land_pub = nh.advertise<std_msgs::Empty>("/bebop/land", 1);
    reset_pub = nh.advertise<std_msgs::Empty>("/bebop/reset", 1);
    cmd_vel_pub = nh.advertise<geometry_msgs::Twist>("/bebop/cmd_vel", 1);

    while (ros::ok()) {
        ros::spinOnce();

        publishing();
    }

    return 0;
}