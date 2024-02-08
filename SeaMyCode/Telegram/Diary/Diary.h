#ifndef DIARY_H
#define DIARY_H

#include "Utility.h"

#define BOT_CFG_FILE "/home/nksys/SeaMyCode/Telegram/Diary/botconfig.cfg"

std::string g_Weekday[7]= {"Sunday",
				"Monday",
				"Tuesday",
				"Wednesday",
				"Thursday",
				"Friday",
				"Saturday"};
struct BotConfig 
{
	std::string botID;
	std::string botToken;
	std::string msgID;
	std::string name;
};

class Diary
{
	public:
		Diary();
		~Diary();
		void Init();

	private:
		BotConfig *m_botCfg;
		std::string m_botData;
		std::string m_data;
		unsigned long long m_offset;
		std::string m_senderID;
		void ReadBotConfig();
		bool ReadData();
		void ProcessCommand();
		void ProcessData();
		void SendDailyReport();
		void SendMonthlyReport();
		void SendReport(int date = 0);
		void SetReminder();
		std::string ExtractInfoFromJson(const Json::Value &root,int day_);
		void SendToBot(std::string data);
		void SendFile(const std::string &file);
		void LogDiary();
		void LogExpense();
		bool Parse(std::string &str);
		void PrintCurrentMonthExpenses();
};

std::string SLEEPING_MESSAGE = "I am sleeping as you dint respond";
std::string FIRST_MESSAGE = "What would you like to log?\n1) Diary\n2) Expense";
std::string DINT_UNDERSTAND = "I dint understand your input";

std::string ADD_DIARY = "You can add the event and I will note it down";

std::string AMOUNT = "What is the amount?";
std::string MODE ="What is the mode?\n1) Cash \n2) Bank Debit \n3) Credit Card";
std::string WHY = "Why did you spend?";
std::string WHERE = "Where did you spend?";
std::string REMARK_YN = "Do you want add any remark? (Y/N)";
std::string REMARK = "Okay Add the remark";
std::string CONFIRM_EXPENSE = "This cannot be edited. Do you want to save it?(Y/N)";
std::string END_EXPENSE = "Expense is noted";

std::string g_mode[3]={"Cash","Bank debit","Credit Card"};


#endif
