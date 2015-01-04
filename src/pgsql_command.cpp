/*
 * sql_command.cpp
 *
 *  Created on: 5 sie 2014
 *      Author: macylapka
 */

#include "pgsql_command.hpp"


pgsql_command::~pgsql_command() { }
pgsql_command::pgsql_command() { }
pgsql_command::pgsql_command(std::string *command) : m_command(command) { }
pgsql_command::pgsql_command(std::string *command, pgsql_connection *connection) : m_command(command), m_connection(connection) { }

pgsql_query_result pgsql_command::execute_query_without_params() {
  if(!m_connection->is_connected())
    m_connection->connect();

  return pgsql_query_result(PQexec(m_connection->get_pgconn(), m_command->c_str()));
}

pgsql_query_result pgsql_command::execute_query_with_params(
    int                 params_count,
    Oid const           *params_types,
    char const *const   *param_values,
    int const 	        *param_lengths,
    int const           *param_formats,
    int                 result_format) {
  
  if(!m_connection->is_connected())
    m_connection->connect();

  return pgsql_query_result(PQexecParams(m_connection->get_pgconn(),
      m_command->c_str(), params_count, params_types, param_values,
      param_lengths, param_formats, result_format));
}

void pgsql_command::set_command(std::string *command) {
  m_command = command;
}

std::string pgsql_command::get_command() {
  return *m_command;
}

void pgsql_command::set_connection_object(pgsql_connection *connection) {
  m_connection = connection;
}

pgsql_connection pgsql_command::get_connection_object() {
  return *m_connection;
}
