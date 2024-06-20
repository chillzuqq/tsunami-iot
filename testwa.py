import pywhatkit
import pyautogui
import time
from datetime import datetime

now = datetime.now()

arr = ["+6281319362661", "+6281271524551", "+6281251700170", "+6285732053557"]


def sendMSG(number, msg):
    pywhatkit.sendwhatmsg_instantly(number, msg, 10)
    # time.sleep(1)
    pyautogui.click()
    # time.sleep(1)
    pyautogui.press('enter')


# for i in arr: