/*
 * pgsql_query_result.cpp
 *
 *  Created on: 3 paź 2014
 *      Author: macylapka
 */

#include "pgsql_query_result.hpp"

pgsql_query_result::~pgsql_query_result() {
  if(m_pgsql_result != nullptr)
    PQclear(m_pgsql_result);
}

pgsql_query_result::pgsql_query_result(PGresult *pgsql_result) {
  m_current_row_number 		= -1;
  m_current_column_number = -1;
  this->m_pgsql_result = pgsql_result;
}

int pgsql_query_result::get_rows_number() {
  return PQntuples(m_pgsql_result);
}

int pgsql_query_result::get_columns_number() {
  return PQnfields(m_pgsql_result);
}

int	pgsql_query_result::get_column_number_by_name(std::string const &column_name) {
  return PQfnumber(m_pgsql_result, column_name.c_str());
}

std::string pgsql_query_result::get_column_name(int column_number) {
  return std::string(PQfname(m_pgsql_result, column_number));
}

int	pgsql_query_result::get_column_format(int column_number) {
  return PQfformat(m_pgsql_result, column_number);
}

int pgsql_query_result::get_column_type(int column_number) {
  return PQftype(m_pgsql_result, column_number);
}

int pgsql_query_result::get_column_type_size(int column_number) {
  return PQgetlength(m_pgsql_result, m_current_row_number, column_number);
}

std::string pgsql_query_result::get_value(int column_number) {
  return std::string(PQgetvalue(m_pgsql_result, m_current_row_number, column_number));
}

bool pgsql_query_result::is_null_value(int column_number) {
  return PQgetisnull(m_pgsql_result, m_current_row_number, column_number);
}

bool pgsql_query_result::move_next() {
  int row_count = get_rows_number();

  if(m_current_row_number < row_count - 1) {
    ++m_current_row_number;
    return true;
  }

  return false;
}

void pgsql_query_result::reset() {
  m_current_row_number 		= -1;
  m_current_column_number = -1;
}
