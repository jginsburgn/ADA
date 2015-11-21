#ifndef QUERY_H
#define QUERY_H

#include "pintgd.h"

enum operation {
    select,
    insert,
    update,
    erase
};

class query
{
private:
    std::string buildColumns();
    std::string buildConditions();
    std::string buildTables();

public:
    query(operation newOp) : op(newOp) {}

    operation op;
    std::vector<std::string> tables;
    std::vector<std::string> columns;
    std::vector<std::string> conditions;
    std::string value;

    bool isPersonalized;
    std::string personalizedQuery;

    bool failed;
    std::string message;
    pqxx::result r;

    void run();
};

#endif // QUERY_H
