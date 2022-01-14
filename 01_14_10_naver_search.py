import requests
from bs4 import BeautifulSoup

query = 'ssafy'
response = requests.get(f'https://search.naver.com/search.naver?query={query}')
data=BeautifulSoup(response.text, 'html.parser')
print(data.select('#web_1 > div > div.total_tit_group'))
