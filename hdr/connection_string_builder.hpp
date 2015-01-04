#ifndef CONNECTION_STRING_BUILDER_H
#define CONNECTION_STRING_BUILDER_H

#include <string>

class connection_string_builder {
public:
	~connection_string_builder();
	connection_string_builder();
	connection_string_builder(std::string host, int port, std::string user,
		 std::string password, std::string db_name);

	//setters
	void set_host(std::string const &host);
	void set_port(int const &port);
	void set_user(std::string const &user);
	void set_password(std::string const &password);
	void set_db_name(std::string const &db_name);

	//getters
	std::string get_host() const;
	int get_port() const;
	std::string get_user() const;
	std::string get_password() const;
	std::string get_db_name() const;

	std::string get_connection_string() const;

private:
	std::string m_host;
	int m_port;
	std::string m_user;
	std::string m_password;
	std::string m_db_name;
};

#endif
