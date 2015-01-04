/*
 * pgsql_query_result.hpp
 *
 *  Created on: 3 paź 2014
 *      Author: macylapka
 */

#ifndef PGSQL_QUERY_RESULT_HPP_
#define PGSQL_QUERY_RESULT_HPP_

#include <string>
#include <libpq-fe.h>

class pgsql_query_result {
public:
	~pgsql_query_result();
	pgsql_query_result(PGresult *);

	int 				get_rows_number();
	int 				get_columns_number();
	int					get_column_number_by_name(std::string const &);
	std::string get_column_name(int);
	int					get_column_format(int);
	int 				get_column_type(int);
	int					get_column_type_size(int);
	std::string get_value(int);

	bool				is_null_value(int);
	bool				move_next();

	void 				reset();

protected:
	PGresult *m_pgsql_result;

private:
	int m_current_column_number;
	int m_current_row_number;
};



#endif /* PGSQL_QUERY_RESULT_HPP_ */
