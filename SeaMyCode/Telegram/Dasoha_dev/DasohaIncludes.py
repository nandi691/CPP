import time

import telebot
from telebot import types
from telegram_bot_calendar import DetailedTelegramCalendar, LSTEP
 # For Calendar view
menu_dict_general ={
    "check_slot":"Check for the availability",
    "book_slot":"Book the slot",
    "donate" : "Make Donations",
    "my_slots" : "Your slots"
}

introStr = "Welcome to Dasoha Bot !"
selectStr = "Select one of the option below : \n\n"

TOKEN = '5264603873:AAE14nw6biq8PQPGvG8Wu_Sr_q-BngUP3aM' #Bot Token taken from Telegram BotFather
