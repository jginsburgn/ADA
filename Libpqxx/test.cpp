#include <iostream>
#include <pqxx/pqxx>

int main(int, char *argv[])
{
  pqxx::connection c("dbname=test user=test host=localhost password=123456");
  pqxx::work txn(c);

  pqxx::result r = txn.exec(
    "SELECT id "
    "FROM Employee "
    "WHERE name = " + txn.quote(argv[1]));

  if (r.size() != 1)
  {
    std::cerr
      << "Expected 1 employee with name " << argv[1] << ", "
      << "but found " << r.size() << std::endl;
    return 1;
  }

  int employee_id = r[0][0].as<int>();
  std::cout << "Updating employee #" << employee_id << std::endl;

  txn.exec(
    "UPDATE EMPLOYEE "
    "SET salary = salary + 1 "
    "WHERE id = " + txn.quote(employee_id));

  //txn.commit();
}
