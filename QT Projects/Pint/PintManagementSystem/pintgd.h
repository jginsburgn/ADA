#ifndef PINTGD
#define PINTGD

#include <pqxx/except.hxx>
#include "Helper.h"

const std::string host = "localhost";
const std::string database = "pint";
const std::string username = "pint";
const std::string password = "pint";

const std::string connectionError = "Cannot connect to server.";
const std::string loginFailed = "Login failed.";
const std::string loggingIn = "Logging in...";
const std::string sessionFinished = "Logged out.";

#endif // PINTGD

