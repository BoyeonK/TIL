def isPalin(str):
	reverse_str = str[::-1]
	if str == reverse_str:
		print(reverse_str)
		print('입력하신 단어는 회문(Palindrome)입니다.')
        
str = input()
isPalin(str)