#ifndef QUERY_H
#define QUERY_H

#include "pintgd.h"

class Query
{
public:
    Query();
    Query(const std::string & newQuery);

    std::string qry;
    bool failed;
    std::string message;
    pqxx::result r;

    void run();
    void run(const std::string & newQuery);
};

#endif // QUERY_H
