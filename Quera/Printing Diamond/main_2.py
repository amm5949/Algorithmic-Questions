def printing_pattern(vasat_1: int, vasat_2: int, i: int, j: int):
    if j >= vasat_1 - i and j <= vasat_1 + i:
        print("*", end="")
    
    elif j >= vasat_2 - i and j <= vasat_2 + i:
        print("*", end="")
    
    else:
        print(" ", end="")


n_odd = int(input())

ghotr = 2 * n_odd

vasat_1 = int(n_odd / 2)
vasat_2 = n_odd + vasat_1

for i in range(n_odd):
    satr = i - vasat_1
    satr = vasat_1 - satr
    for j in range(ghotr):

        if i <= vasat_1:
            printing_pattern(vasat_1, vasat_2, i, j) 
        
        else:
            if satr <= vasat_1:
                printing_pattern(vasat_1, vasat_2, satr, j)
        

    print()
