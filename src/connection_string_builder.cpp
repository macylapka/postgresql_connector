/*
 * connection_string_builder.cpp
 *
 *  Created on: 4 sie 2014
 *      Author: macylapka
 */

#include "connection_string_builder.hpp"

connection_string_builder::~connection_string_builder() { }

connection_string_builder::connection_string_builder() : m_host(""),
		m_port(0), m_user(""), m_password(""), m_db_name("") {

}

connection_string_builder::connection_string_builder(std::string host, int port,
		std::string user, std::string password, std::string db_name) : m_host(host),
		m_port(port), m_user(user), m_password(password), m_db_name(db_name) {

}

void connection_string_builder::set_host(std::string const &host) {
	m_host = host;
}

void connection_string_builder::set_port(int const &port) {
	m_port = port;
}

void connection_string_builder::set_user(std::string const &user) {
	m_user = user;
}

void connection_string_builder::set_password(std::string const &password) {
	m_password = password;
}

void connection_string_builder::set_db_name(std::string const &db_name) {
	m_db_name = db_name;
}

std::string connection_string_builder::get_host() const {
	return m_host;
}

int connection_string_builder::get_port() const {
	return m_port;
}

std::string connection_string_builder::get_user() const {
	return m_user;
}

std::string connection_string_builder::get_password() const {
	return m_password;
}

std::string connection_string_builder::get_db_name() const {
	return m_db_name;
}

std::string connection_string_builder::get_connection_string() const {
	std::string connection_string = "";
	if(!m_host.empty())
		connection_string += "host=" + m_host + " ";

	connection_string += "port=" + std::to_string(m_port) + " ";

	if(!m_user.empty())
		connection_string += "user=" + m_user + " ";

	if(!m_password.empty())
		connection_string += "password=" + m_password + " ";

	if(!m_db_name.empty())
		connection_string += "dbname=" + m_db_name + " ";

	return connection_string;
}




