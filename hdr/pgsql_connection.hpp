/*
 * pgsql_connection.hpp
 *
 *  Created on: 8 sie 2014
 *      Author: macylapka
 */

#ifndef PGSQL_CONNECTION_HPP_
#define PGSQL_CONNECTION_HPP_

#include <string>
#include <libpq-fe.h>

#define CONNECTION_STRING_OK 0
#define CONNECTION_STRING_BAD -1

class pgsql_connection {
public:
	~pgsql_connection();
	pgsql_connection();
	pgsql_connection(std::string const &);

	void set_pgsql_connection_string(std::string &);
	std::string const &get_pgsql_connection_string();

	PGconn *get_pgconn();

	bool	is_connected();

	int 	connect();
	bool	disconnect();
	bool	restart_connection();
protected:
	int parse_connection_string();

private:
	std::string m_connection_string;
	PGconn *m_pgsql_conn;

};



#endif /* PGSQL_CONNECTION_HPP_ */
