from DasohaIncludes import *
#Follow single responsibility principle

def SelectAppropriateAction(bot):
    @bot.message_handler(commands=['check_slot'])
    def command_start(m):
        cid = m.chat.id
        print("Check Slot")
    pass

def InitDasohaModule():
    bot = telebot.TeleBot(token=TOKEN)
    while(True):
        SelectAppropriateAction(bot)
    pass
def main():
    #print("Hello World!")
    #print(menu_dict_general)
    #global selectStr
    #for k,v in menu_dict_general.items():
        #selectStr_ += ("/"+k+" : "+v+"\n\n")
    #print(selectStr_)
    InitDasohaModule()
    pass


if __name__ == "__main__":
    main()