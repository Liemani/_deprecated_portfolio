#include <iostream>
#include <mysql/mysql.h>

const char* host = "localhost";
const char* user = "root";
const char* pw = "1234";
const char* db = "Chinook";

int main(int argc, char** argv) {
    MYSQL* connection = NULL;
    MYSQL conn;
    MYSQL_RES* sql_result;
    MYSQL_ROW sql_row;

    mysql_init(&conn);

    connection = mysql_real_connect(&conn, host, user, pw, db, 3306, (const char*)NULL, 0);

    if (connection == NULL) {
        std:: cout << "Connection Error: " << mysql_error(&conn) << std::endl;
    } else {
        std::cout << "Connection Success" << std::endl;

        // select * from Album
        const char* query = "select * from Album";

        int state = 0;
        state = mysql_query(connection, query);

        if (state == 0) {    // normal executing condition
            sql_result = mysql_store_result(connection);

            while ((sql_row= mysql_fetch_row(sql_result)) != NULL) {
                std::cout << sql_row[0] << " | " << sql_row[1] << " | " << sql_row[2] << std::endl;
            }

            mysql_free_result(sql_result);
        } else {    // error
            std::cout << "Querry Error!" << std::endl;
        }

        mysql_close(connection);
    }

    return 0;
}