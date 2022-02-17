T = int(input())
numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9}
for tc in range(1, T+1):

    sudoku = [list(map(int, input().split())) for _ in range(9)]
    ans = 1
    for i in range(9):
        row = set()
        col = set()
        square = set()
        for j in range(9):
            row.add(sudoku[i][j])
            col.add(sudoku[j][i])
            square.add(sudoku[3*(i//3) + (j//3)][3*(i % 3) + (j % 3)])
        if (row != numbers) or (col != numbers) or (square != numbers):
            ans = 0
    print(f"#{tc} {ans}")
