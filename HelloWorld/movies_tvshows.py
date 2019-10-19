from selenium import webdriver
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
import time
c=2
driver=webdriver.Chrome(r"C:\Users\Ayush\.spyder-py3/chromedriver")
driver.get("https://www.pirateproxy.space/")
search= driver.find_element_by_xpath("//input[@name='q']")
TVshow=input("Enter a movie or tv show")
search.send_keys(TVshow)
enter=driver.find_element_by_xpath("//input[@type='submit' and @title='Pirate Search']")
enter.click()
