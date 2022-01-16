import requests
from bs4 import BeautifulSoup

response = requests.get('https://finance.naver.com/sise/')
# print(response.text)
data=BeautifulSoup(response.text, 'html.parser')
# print(data)
print(data.select('#KOSPI_now'))

