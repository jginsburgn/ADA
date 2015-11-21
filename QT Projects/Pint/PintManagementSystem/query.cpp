#include "query.h"

query::query()
{
    op = insert;
}

void query::run() {
    std::string connDetails = "dbname=" + database + " host=" + host + " user=" +
            username + " password = " + password;
    try {
        pqxx::connection conn(connDetails.c_str());
        pqxx::work txn(conn);
        if (isPersonalized){

        }
        else if (op == insert) {

        }
        else if (op == select) {
            r = txn.exec("select * "
                                        "from system_users "
                                        "where username=" + txn.quote(user.username)
                                        + "and a_password=" + txn.quote(user.password));
        }
        else if (op == update) {

        }
        else if (op == erase) {

        }
        failed = false;
    }
    catch (PGSTD::runtime_error e) {
        message = connectionError;
    }
    catch (PGSTD::logic_error e) {
        message = connectionError;
    }
}

/*

    return false;
 * /
