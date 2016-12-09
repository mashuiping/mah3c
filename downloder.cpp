#include "downloder.h"
#include "curl.h"
#include "QDebug"
#include "externalvar.h"
using namespace std;
downloder::downloder()
{

}
int writer(char *data, size_t size, size_t nmemb, string *writerData)
{
    if (writerData == NULL)
        return 0;
    int len = size*nmemb;
    writerData->append(data, len);
    return len;
}

QString downloder::downlode(string toDownlodeUrl)
{
    CURL * curl;
    CURLcode res;
    curl = curl_easy_init();
    string buffer;
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, toDownlodeUrl.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    if (buffer.empty())
    {
        qDebug() << "The server return NULL!";
    }
    return QString::fromStdString(buffer);

}
