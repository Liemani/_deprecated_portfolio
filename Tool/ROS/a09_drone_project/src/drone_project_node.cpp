#include <ros/ros.h>
#include <bebop_msgs/Ardrone3PilotingStatePositionChanged.h>
#include <mysql/mysql.h>
#include <string>
#include <sstream>

using std::string;
using std::ostringstream;

const char* host = "localhost";
const char* user = "root";
const char* pw = "1234";
const char* db = "droneDB";

int counter = 1;

MYSQL* connection = NULL;
MYSQL conn;
MYSQL_RES* sql_result;
MYSQL_ROW sql_row;

void callback(const bebop_msgs::Ardrone3PilotingStatePositionChanged::ConstPtr& msg) {
    if (connection == NULL) {    // error
        std::cout << "Connection Error: " << mysql_error(&conn) << std::endl;
    } else {
        std::cout << "Connection Success" << std::endl;

        ostringstream counterString;
        counterString << counter;

        ostringstream latitude;
        latitude << msg->latitude;

        ostringstream longitude;
        longitude << msg->longitude;

        ostringstream altitude;
        altitude << msg->altitude;  

        // select * from Album
        string query = "insert into gps value(" + counterString.str() + ", " + latitude.str() + ", " + longitude.str() + ", " + altitude.str() + ")";

        int state = 0;
        state = mysql_query(connection, query.c_str());

        if (state == 0) {    // normal executing condition
            std::cout << "Success" << std::endl;
        } else {    // error
            std::cout << "Querry Error!" << std::endl;
        }

        ++counter;
    }
}

int main(int argc, char** argv) {
    // DB part
    mysql_init(&conn);

    connection = mysql_real_connect(&conn, host, user, pw, db, 3306, (const char*)NULL, 0);

    // ros part
    ros::init(argc, argv, "drone_project");    // what that string mean?
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("/bebop/states/ardrone3/PilotingState/PositionChanged", 1, callback);

    try {
        ros::spin();
    } catch(...) {
        ROS_ERROR("ERROR!!!!!");
        ros::shutdown();
    }

    mysql_close(connection);

    return 0;
}