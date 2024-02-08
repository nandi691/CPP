#ifndef DASOHA_H_
#define DASOHA_H_

#include "Utility.h"

#define BOT_CFG_FILE "/home/nksys/SeaMyCode/Telegram/Diary/botconfig.cfg"


struct BotConfig
{
	std::string botID;
	std::string botToken;
	std::string msgID;
	std::string name;
};

struct DasohaKartha
{
	DasohaKartha();
	DasohaKartha(const std::string &name,int date,int month ,int year,const std::string &address, const std::string &phn);
	virtual ~DasohaKartha();
	std::string m_name;
	unsigned int m_date;
	unsigned int m_month;
	unsigned int m_year;
	std::string m_address;
	std::string m_phn_num;
};

class Dasoha{
public:
	Dasoha();
	virtual ~Dasoha();
	void Init();

private:
	BotConfig *m_botCfg;
	std::string m_botData;
	std::string m_data;
	std::string m_options;
	unsigned long long m_offset;
	std::string m_senderID;
	std::string m_senderName;

	DasohaKartha m_kartha[31];
	void ReadBotConfig();
	void SendToBot(std::string data);
	bool ReadData();
	void ProcessCommand();
	bool CheckForValidMonthInput();
	bool WaitForData();
	int GetMonthNumber();
	int ValidateDate(int month=0);
	int GetSlotAvailableStatus(int date,int month,int year);
	int GetSlotForTheDay(int &date,int &month,int & year,bool isItForBooking=false);
	void SaveCfg(DasohaKartha *kartha);
	void GetSlotDetails(const int date,const int month,int year);
	void GetSlot(bool tomorrow = false);
	void SendMonthDetails(int month,int year,bool nextMonth=false);
	void BookSlot();
	void PrintSlotDetails(DasohaKartha *kartha,std::string &retStr );
	void ResetDasohaStruct();
	void PrepareOptions();
	void PrintDasohaStruct();

};

#endif
