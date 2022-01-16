# 딕셔너리 자료형

my_home = {
    # key : value (짝꿍, 콤마로 구분함)
    'location': 'seoul',
    'area-code': '02',
}

# 원소 접근 => key값으로 접근한다. => value가 나온다.
print(my_home['location'])
print(my_home.get('location'))

print(my_home.get('number'))    #key가 없으면 None 반환
#print(my_home['number'])        #key가 없으면 에러

# 원소 변경
my_home['area-code'] = '007'
print(my_home['area-code'])
