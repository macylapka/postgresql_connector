/*
 * pgsql_connection.cpp
 *
 *  Created on: 8 sie 2014
 *      Author: macylapka
 */
#include "pgsql_connection.hpp"
#include <iostream>

pgsql_connection::~pgsql_connection() {
  disconnect();
}

pgsql_connection::pgsql_connection() :
  m_connection_string(""), m_pgsql_conn(nullptr) {
}

pgsql_connection::pgsql_connection(std::string const &connection_string) :
  m_connection_string(connection_string), m_pgsql_conn(nullptr){
}

void pgsql_connection::set_pgsql_connection_string(std::string &connection_string) {
  m_connection_string = connection_string;
}

std::string const &pgsql_connection::get_pgsql_connection_string() {
  return m_connection_string;
}

PGconn *pgsql_connection::get_pgconn() {
  return m_pgsql_conn;
}

bool pgsql_connection::is_connected() {
  if (nullptr == m_pgsql_conn)
    return false;

  if (CONNECTION_BAD == PQstatus(m_pgsql_conn))
    return false;

  return true;
}

int pgsql_connection::connect() {
  int rc = 0;

  if(CONNECTION_STRING_BAD == parse_connection_string())
    throw "pgsql_connection::init_connection - error while parsing connection string";

  m_pgsql_conn = PQconnectdb(m_connection_string.c_str());

  switch(PQstatus(m_pgsql_conn)) {
    case CONNECTION_OK:
      rc = CONNECTION_OK;
      break;
    case CONNECTION_BAD:
      rc = CONNECTION_BAD;
      break;
    default:
      std::cout << "Connecting..." << std::endl;
      break;
  }
  return rc;
}

bool pgsql_connection::disconnect() {
  if (nullptr == m_pgsql_conn)
    return false;

  PQfinish(m_pgsql_conn);
  return true;
}

bool pgsql_connection::restart_connection() {
  if (nullptr == m_pgsql_conn)
    return false;

  PQreset(m_pgsql_conn);
  return true;
}

int pgsql_connection::parse_connection_string() {
  if(0 == m_connection_string.length())
    return CONNECTION_STRING_BAD;

  if(NULL == PQconninfoParse(m_connection_string.c_str(), NULL))
    return CONNECTION_STRING_BAD;

  return CONNECTION_STRING_OK;
}
