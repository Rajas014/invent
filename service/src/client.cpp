#include <iostream>

#include <Poco/Net/FTPClientSession.h>
#include <Poco/String.h>
//#include "../../external/xlntMaster/include/xlnt/xlnt.hpp"
//#include "../include/libxl.h"
#include "config.h"

//using namespace libxl;

namespace FtpClient
{
    class DataFetch
    {
    public:

//        void paraseData()
//        {
//            Book* book = xlCreateBook();
//            if(book)
//            {
//                if(book->load("/home/rajasekhar/RaJa/makeIt/files/p17012019M1.xls"))
//                {
//                    Sheet* sheet = book->getSheet(0);
//                    if(sheet)
//                    {
//                        const char* s = sheet->readStr(2, 1);
//                        if(s) std::cout << s << std::endl;
//
//                        double d = sheet->readNum(3, 1);
//                        std::cout << d << std::endl;
//
//                        int year, month, day;
//                        book->dateUnpack(sheet->readNum(4, 1), &year, &month, &day);
//                        std::cout << year << "-" << month << "-" << day << std::endl;
//                    }
//                }
//
//                book->release();
//            }
//        }

        void parseFile(std::string& is)
        {
            //std::string str;
            //printf("Please input xls file name");
            //std::cin>>str;
//            std::ifstream ifs("/home/rajasekhar/RaJa/makeIt/files/p17012019M1.xls");
//
//            if(!ifs)
//            {  std::cerr <<"input file name is incorrect" << std::endl;   exit(1);     }
//
//            std::ofstream ofs("new1.csv");
//
//            ofs<<ifs.rdbuf();
//            if (!ofs)
//            {   std::cerr <<"error: can not open \"new.xls\" for output\n";  exit(1);}
//            //ifs.close();
//
//            std::string res;
//
//            ofs << res;
//
//            std::cout << "=-=-=->:" << res << std::endl;
//
//            ofs.close();
//            std::cout<<"copied one file！";
//            std::cin.get();

//            std::ifstream iss("/home/rajasekhar/RaJa/makeIt/files/p17012019M1.xls");
//
//            std::string line;
//            while (std::getline(iss, line))
//            {
//                const char *begin = line.c_str();
//                std::cout << "-->" << std::endl;
//                // strip beyond first comma
//                if (const char *end = strchr(begin, ','))
//                {
//                    std::string column1(begin, end - begin);
//                    std::cout << "-->" << column1 << std::endl;
//                }
//            }

        }

        void fetchData()
        {
            try
            {
                const std::string hostName = GetData::Config::getStr("data.fetch.target.ip");
                const std::string user {GetData::Config::getStr("data.fetch.target.ip.user")};
                const std::string pass {GetData::Config::getStr("data.fetch.target.ip.password")};
                const std::string filePath {GetData::Config::getStr("data.fetch.target.file.path")};

                Poco::Net::FTPClientSession session(hostName, 21);

                session.login(user, pass);

                if (session.isLoggedIn())
                {
                    auto& response = session.beginDownload(filePath);

                    std::string responseStr{};

                    while (std::getline(response, responseStr))
                    {
                        //paraseData();
                        parseFile(responseStr);
                        //std::cout << "Response: " << responseStr << std::endl;
                    }
                }

                session.endDownload();
                session.logout();
            }
            catch (const Poco::PathNotFoundException &ex)
            {
                GetData::Logger::logging("Exception at: " + ex.displayText());
            }
            catch (const Poco::Exception &ex)
            {
                GetData::Logger::logging("Exception at: " + ex.displayText());
            }
            catch (const std::exception &ex)
            {
                std::string exception = "Exception at: ";
                GetData::Logger::logging(exception + ex.what());
            }
        }
    };

}
