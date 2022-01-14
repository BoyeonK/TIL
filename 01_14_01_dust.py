
# input()  => 사용자 입력 받기
# 받은 정보 => 글자
input_string = input()
# 글자를 숫자로 바꾸기
dust = int(input_string)

if  150 < dust:
    print('매우나쁨')
elif 80 < dust:
    print('나쁨')
elif 30 < dust:
    print('보통')
else:
    print('좋음')
