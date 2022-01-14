import requests
from bs4 import BeautifulSoup

# 응답 <= get 요청
response=requests.get('https://finance.naver.com/marketindex/')
# data <= HTML을 분석
data=BeautifulSoup(response.text, 'html.parser')
# data에게 선택적으로 정보를 가져오기
#print(data.select('#exchangeList > li.on > a.head.usd > div > span.value'))
result = data.select_one('#exchangeList > li.on > a.head.usd > div > span.value')

print(f'현재 환율은 {result.text}원/달러 입니다.')
