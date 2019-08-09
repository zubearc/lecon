#include "WebGet.h"

    std::string WebGet::Get(const std::string& url, std::vector<std::string> headers) {
        CURLcode res;
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, this);

        curl_slist *headerlist = NULL;

        for (auto header : headers) {
            headerlist = curl_slist_append(NULL, header.c_str());
        }

        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);

        ss.str("");
        http_code = 0;
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            printf("curl: FAIL!\n", http_code);
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
            return "";
        }
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
        // printf("curl: OK: %d\n", http_code);
        return ss.str();
    }