#include "query.h"

Query::Query(const std::string & newQuery) {
    run(newQuery);
}

void Query::run(const std::string & newQuery) {
    setQuery(newQuery);
    run();
}

void Query::run() {
    std::string connDetails = "dbname=" + database + " host=" + host + " user=" +
            username + " password = " + password;
    try {
        pqxx::connection conn(connDetails.c_str());
        pqxx::work txn(conn);
        Helper::print("Executing query: " + qry + ";");
        r = txn.exec(qry);
        txn.commit();
        failed = false;
    }
    catch (PGSTD::runtime_error e) {
        message = e.what();
        failed = true;
    }
    catch (PGSTD::logic_error e) {
        message = e.what();
        failed = true;
    }
}

void Query::setQuery(const string &newQuery){
    qry = "";
    qry = newQuery;
}
