#ifndef PINTGD
#define PINTGD

#include <pqxx/pqxx>
#include <pqxx/except.hxx>
#include "Helper.h"
#include <sstream>

typedef std::vector<std::vector<std::string>> stringMatrix;
typedef std::vector<std::string> stringVector;

const std::string host = "localhost";
const std::string database = "pint";
const std::string username = "pint";
const std::string password = "pint";

const std::string connectionError = "Cannot connect to server.";

const std::string loginFailed = "Login failed.";
const std::string loggingIn = "Logging in...";
const std::string sessionFinished = "Logged out.";

const std::string rfcexistscustomer = "That customer's RFC already exists.";
const std::string nrfcexistscustomer = "RFC uniqueness verified.";
const std::string nameexistscustomer = "That customer's name already exists.";
const std::string nnameexistscustomer = "Name's uniqueness verified.";

class pg {
public:

    static std::string quote(const std::string & str) {
        std::stringstream retVal;
        retVal << "'" << str << "'";
        return retVal.str();
    }

};

#endif // PINTGD

