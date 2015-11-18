Libpqxx is a library for connecting C++ with postgreSQL :)

To compile with libpqxx first download a stable version from:
http://pqxx.org/development/libpqxx/wiki/DownloadPage.
Also install a postgreSQL server with developer tools.
Make a project similar to <test.cpp>, located in this same directory.
Remember to include <pqxx/pqxx>.
Then depending on where your binaries and libraries are installed,
run something like:
g++ test.cpp -I/usr/local/Cellar/libpqxx/4.0.1/include/ /usr/local/Cellar/libpqxx/4.0.1/lib/libpqxx.a -lpq,
where the libpqxx.a is the downloaded library and lpq is a sublibrary of pqxx;
in addition, include the include directory.

Jonathan Ginsburg,
November 18, 2015.