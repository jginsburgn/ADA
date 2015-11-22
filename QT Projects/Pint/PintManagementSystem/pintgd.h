#ifndef PINTGD
#define PINTGD

#include <pqxx/pqxx>
#include <pqxx/except.hxx>
#include "Helper.h"
#include <sstream>

const std::string host = "localhost";
const std::string database = "pint";
const std::string username = "pint";
const std::string password = "pint";

const std::string connectionError = "Cannot connect to server.";
const std::string loginFailed = "Login failed.";
const std::string loggingIn = "Logging in...";
const std::string sessionFinished = "Logged out.";

class pg {
public:

    static std::string quote(std::string & str) {
        std::stringstream retVal;
        retVal << "'" << str << "'";
        return retVal.str();
    }

};

#endif // PINTGD

