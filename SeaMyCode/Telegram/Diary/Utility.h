#ifndef _FILE_IO_H
#define _FILE_IO_H

#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <string>
#include <curl/curl.h>
#include <unistd.h>
#include <json/value.h>
#include <json/json.h>
#include <json/writer.h>
#include <ctime>
#include <fstream>
#include <algorithm>
#include <fcntl.h>    /* For O_RDWR */
#include <unistd.h>   /* For open(), creat() */

using namespace std;

char * GetCurrentTime();
tm * GetLocalTime();
bool IsFileExists(const char* fname);
bool CreateFile(const std::string& fname);
void WriteToFile(const std::string& fname,const std::string& str);
void ReadFile(const std::string& fname,std::string& str);
static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
void SendCurlData(const std::string &url,std::string &response);
bool ParseFile(Json::Value &root,const std::string &file);
bool ParseString(Json::Value &root,const std::string &str);
std::string UrlEncode(const std::string &s);
bool is_number(const std::string& s);

#endif


/*
 *
 *
{
	"BotToken":"AAEnzsZn6uWKga6LUrLj5GIdtlQoatz5200",
	"BotID":"6394761818",
	"MessageID":"6396500404",
	"Name":"NKSys Technology Services"
}

{
	"BotToken":"AAE14nw6biq8PQPGvG8Wu_Sr_q-BngUP3aM",
	"BotID":"5264603873",
	"MessageID":"2058010923",
	"Name":"Nandeesh"
}

#https://api.telegram.org/bot6394761818:AAEnzsZn6uWKga6LUrLj5GIdtlQoatz5200/getUpdates?offset=667470157?limit=1
 * https://api.telegram.org/bot6394761818:AAEnzsZn6uWKga6LUrLj5GIdtlQoatz5200/sendMessage?chat_id=6394761818&&text="Hello Nandeesh"
 *
 */
