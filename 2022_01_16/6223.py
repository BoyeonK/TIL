from cmath import pi

class Circle:
    def __init__(self, r):
        Vol = pi * r * r
        print(f'원의 면적: {Vol:.2f}')

r=1.9995
Circle(r)