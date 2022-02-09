ASCII = {65:'A', 66:'B', 67:'C'}
IICSA = {}
for key, value in ASCII.items(): #.items() 안쓰면 작동하지 않는다!
        IICSA[value] = key

print(IICSA)