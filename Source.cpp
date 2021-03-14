#include <string>
#include <iostream>
#include <curl/curl.h>

using namespace std;

string contents = "";

class url
{
public:
    string theURL;
    string getContents(string theURL)
    {
        CURL* curl = curl_easy_init();
        curl_easy_setopt(curl, CURLOPT_URL, theURL);
        CURLcode res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        cout << contents << endl;
    }
};

int main()
{
    url u1;
    u1.theURL = "http://www.google.com";
    url u2;
    u2.theURL = "https://api.hearthstonejson.com/v1/25770/enUS/cards.json";

    u1.getContents(u1.theURL);
    u2.getContents(u2.theURL);

    return 0;
}