attempt = int(input())
for T in range(1, attempt+1):
    K, N, M = map(int, input().split())
    chargers = list(map(int, input().split()))

    # index는 버스정류장 번호에 해당
    stations = [0]*N

    # 1인 경우 충전기가 있음, 0인 경우 없음.
    for index in chargers:
        stations[index] = 1

    # 버스 운전사가 충전한 위치와 충전횟수를 기록할 변수들
    busdriver = 0
    charged = 0

    # 충전한 위치에서 도착점까지 충전 없이 갈 수 있을때까지,
    while (busdriver + K) < N:
        boool = 0

        # 충전 후부터 K 범위 안에 1이 있는가?
        for i in stations[busdriver + 1:busdriver + K + 1]:
            boool = i or boool

        # 1이 없으면 도착하지 못함. (충전불가)
        if not(boool):
            charged = 0
            break

        # 닿을 수 있는 가장 먼 충전소를 새로운 위치로 함.
        # 충전횟수 1 추가.
        else:
            for index in range(busdriver+K, busdriver, -1):
                if stations[index]:
                    busdriver = index
                    charged += 1
                    break

    print("#{0} {1}".format(T, charged))
