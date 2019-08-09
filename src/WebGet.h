#pragma once
#include <string>
#include <sstream>
#include <vector>
#include <curl/curl.h>

class WebGet
{
private:
    CURL* curl;
    std::stringstream ss;
    long http_code;
public:
    inline WebGet() : curl(curl_easy_init()), http_code(0) {

    }


    inline ~WebGet() {
        if (curl) curl_easy_cleanup(curl);
    }

    std::string Get(const std::string& url, std::vector<std::string> headers);

    inline long GetHttpCode() {
        return http_code;
    }
private:
    static inline size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp)
    {
        return static_cast<WebGet*>(userp)->Write(buffer,size,nmemb);
    }
    size_t inline Write(void *buffer, size_t size, size_t nmemb)
    {
        ss.write((const char*)buffer,size*nmemb);
        return size*nmemb;
    }
};