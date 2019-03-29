#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include <Poco/Exception.h>
#include <Poco/LocalDateTime.h>
#include <Poco/DateTimeFormat.h>
#include <Poco/DateTimeFormatter.h>
#include <Poco/AutoPtr.h>
#include <Poco/Util/PropertyFileConfiguration.h>
#include <memory>

namespace GetData
{
    namespace Logger
    {
        template <class T>
        void logging(T status)
        {
            Poco::LocalDateTime now;
            auto dateAndTime = Poco::DateTimeFormatter::format(now, Poco::DateTimeFormat::ISO8601_FORMAT);
            std::cout << "Data fetcher:: " << dateAndTime << " : " << status << std::endl;
        }
    }

    namespace Config
    {
        static std::string getStr(const std::string key)
        {
            std::string value{};

            using Poco::AutoPtr;
            using Poco::Util::PropertyFileConfiguration;
            const std::string configFile = "config.properties";

            AutoPtr<PropertyFileConfiguration> pConf;

            pConf = new PropertyFileConfiguration(configFile);

            if (!pConf->getString(key).empty())
            {
                value = pConf->getString(key);
            }

            return value;
        }

        static std::string get(const std::string& key)
        {
            std::string value{};

            std::string fileName {"config.properties"};

            std::ifstream openFile(fileName);

            if (!openFile.is_open())
            {
                GetData::Logger::logging(fileName + " is not found");
                throw Poco::NotFoundException("\"" + fileName + "\" file is failed to open ...");
            }

            std::string stringToStore; //string to store file line

            while (std::getline(openFile, stringToStore))
            {
                const std::string::size_type equal = stringToStore.find('=');

                const std::string keyString = stringToStore.substr(0, equal);

                if (key.compare(keyString) == 0)
                {
                    value = stringToStore.substr( equal + 1, stringToStore.length() );
                }
                else
                {
                    value = "\"" + key + "\" is not found in config file";
                }
            }

            openFile.close(); //closes file after done

            return value;
        }
    }   // namespace Config
} 
