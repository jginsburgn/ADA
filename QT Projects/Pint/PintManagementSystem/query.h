#ifndef QUERY_H
#define QUERY_H

#include "pintgd.h"

class Query
{
private:
    std::string qry;

public:
    Query();
    Query(const std::string & newQuery);

    bool failed;
    std::string message;
    pqxx::result r;

    void run();
    void run(const std::string & newQuery);
    void setQuery(const std::string & newQuery);
};

#endif // QUERY_H
