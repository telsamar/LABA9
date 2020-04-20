// Copyright 2020 telsamar

#ifndef INCLUDE_URL_HPP_
#define INCLUDE_URL_HPP_

#include <header.hpp>
#include <string>

struct URL{
    std::string protocol{};
    std::string host{};
    std::string path{};
    std::string port{};
    explicit URL(const std::string& url){
        std::string s(url);
        std::regex regex(R"((https?:)\/\/([a-z.]*)\/?([a-z.\/]*))");
        std::smatch values;
        if (std::regex_search(s, values, regex)){
            if (values.size() > 1){
                protocol = values[1];
                port = (protocol == "https:") ? "443" : "80";
                if (values.size() > 2){
                    host = values[2];
                    if (values.size() > 3){
                        path = "/" + values[3].str();
                    } else {
                        path = "/";
                    }
                }
            }
        }
    }
};

#endif //INCLUDE_URL_HPP_
