/*
 * sql_command.hpp
 *
 *  Created on: 5 sie 2014
 *      Author: macylapka
 */

#ifndef PGSQL_COMMAND_HPP_
#define PGSQL_COMMAND_HPP_

#include <string>
#include "pgsql_connection.hpp"
#include "pgsql_query_result.hpp"

class pgsql_command {
  public:
    ~pgsql_command();
    pgsql_command();
    pgsql_command(std::string *);
    pgsql_command(std::string *, pgsql_connection *);

    pgsql_query_result execute_query_without_params();
    pgsql_query_result execute_query_with_params(int params_count = 0, 
        Oid const * = NULL, char const *const * = NULL, int const * = NULL, 
        int const * = NULL, int = 0);

    void set_command(std::string *);
    std::string get_command();

    void set_connection_object(pgsql_connection *);
    pgsql_connection get_connection_object();

  protected:
    std::string *m_command = nullptr;
    pgsql_connection *m_connection = nullptr;
  
  private:

};

#endif /* SQL_COMMAND_HPP_ */
