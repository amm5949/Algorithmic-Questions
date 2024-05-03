# from math import ceil

def printing_pattern(vasat: int, i: int, j: int):
    if i <= vasat:
        if j >= vasat - i and j <= vasat + i:
            print("*", end="")

        else:
            print(" ", end="")


n = int(input())

ghotr = 2 * n + 1

vasat = int(ghotr / 2)

for i in range(ghotr):
    satr = i - vasat
    satr = vasat - satr
    for j in range(ghotr):

        if i <= vasat:
            printing_pattern(vasat, i, j)

        else:
            printing_pattern(vasat, satr, j)

    print()
