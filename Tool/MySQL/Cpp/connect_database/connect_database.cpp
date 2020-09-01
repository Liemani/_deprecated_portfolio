#include <iostream>
#include <mysql/mysql.h>

// host ip, Id, pw, db;

const char* host = "localhost";
const char* user = "root";
const char* pw = "1234";
const char* db = "Chinook";

int main(int argc, char** argv) {
    MYSQL* connection = NULL;
    MYSQL conn;
    MYSQL_RES* sql_result;
    MYSQL_ROW sql_row;

    if (mysql_init(&conn) == NULL) {
        std::cout << "mysql_init() error" << std::endl;
    }

    connection = mysql_real_connect(&conn, host, user, pw, db, 3306, (const char*)NULL, 0);

    if (connection == NULL) {
        std::cout << "Connection Error: " << mysql_error(&conn) << std::endl;
    } else {
        std::cout << "Connection Success" << std::endl;

        // Code here...

        mysql_close(connection);
    }

    return 0;
}