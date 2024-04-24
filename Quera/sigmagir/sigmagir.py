n = int(input())

m = int(input())

result = 0

min1 , max1 = min(10, m), max(10, m)

min2, max2 = min(1, n), max(1, n)


for i in range(min1, max1 + 1, 1):
    for j in range(min2, max2 + 1, 1):
        sorat = i + j
        sorat = sorat ** 3
        result += sorat / (j ** 2)

print(result)


# def double_sum(m:int , n: int):
#     total_sum = 0
#     for i in range(10, m+1, -1): # i starts from 10 and goes up to m
#         for j in range(1, n+1, 1): # j starts from 1 and goes up to n
#             total_sum += ((i+j)**3) / (j**2)
#     return total_sum

# # Example usage:
# m = 3 # Example value for m
# n = 2   # Example value for n
# result = double_sum(m, n)
# print(f"The result of the double summation for m={m} and n={n} is: {result}")
