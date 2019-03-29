#include <iostream>
#include <istream>
#include <string>

#include "client.cpp"

int main()
{
    FtpClient::DataFetch dataFetch;

    dataFetch.fetchData();

    return 0;
}
