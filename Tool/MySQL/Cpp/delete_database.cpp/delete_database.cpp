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

        const char* query = "delete from Artist where name = \"BTS\"";

        int state = 0;
        state = mysql_query(connection, query);

        if (state == 0) {
            const char* query2 = "select * from Artist";

            int state2 = 0;
            int result_field_num = 0;

            state2 = mysql_query(connection, query2);

            if (state2 == 0) {    // normal excutation
                sql_result = mysql_store_result(connection);
                result_field_num = sql_result->field_count;

                while ((sql_row = mysql_fetch_row(sql_result)) != NULL) {
                    for (int i = 0; i < result_field_num; ++i) {
                        std::cout << sql_row[i] << " | ";
                    }

                    std::cout << std::endl;
                }

                mysql_free_result(sql_result);
            }
        }

        mysql_close(connection);
    }

    return 0;
}