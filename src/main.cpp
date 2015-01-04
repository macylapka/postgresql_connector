#include <iostream>
#include "connection_string_builder.hpp"
#include "pgsql_connection.hpp"
#include "pgsql_command.hpp"

int main(void) {

  try {
    connection_string_builder conn_string_builder;
    conn_string_builder.set_host("localhost");
    conn_string_builder.set_port(5432);
    conn_string_builder.set_user("postgres");
    conn_string_builder.set_password("vfr750rc36");
    conn_string_builder.set_db_name("booktown");

    std::string update_query("UPDATE books SET subject_id=1 WHERE id=41472;");
    std::string select_query("SELECT * FROM books;");

    pgsql_connection conn(conn_string_builder.get_connection_string());
    pgsql_command command(&select_query, &conn);
    pgsql_query_result result = command.execute_query_without_params();

    std::cout << result.get_rows_number() << std::endl;

    while(result.move_next()) {
      for(int i = 0; i < result.get_columns_number(); ++i) {
        std::cout << result.get_value(i) << "\t|\t";
      }
      std::cout << std::endl;
    }
  
  } catch (std::exception const &e) {
    std::cerr << "Exception occure in db connection: " << e.what() << std::endl;
    return -1;
  }

  return 0;
}
