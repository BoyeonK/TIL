point = [88,30,61,55,95]
for i in range(0, len(point)):
	if point[i] < 60:
		print(f'{i+1}번 학생은 {point[i]}점으로 불합격입니다.')
	else:
		print(f'{i+1}번 학생은 {point[i]}점으로 합격입니다.')
        