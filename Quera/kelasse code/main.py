def generator():
    number_list = ""
    for i in range(1, 5000 + 1, 1):
        number_list += str(i)
    
    return number_list

all_numbers = generator()

k = int(input())

print(all_numbers[k - 1])
# print(all_numbers)