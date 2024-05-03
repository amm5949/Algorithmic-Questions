def inserting(insert_list: list, all_list: list, pos: int):
    for i in range(len(insert_list)):
        all_list.insert(i + pos, insert_list[i])

    return all_list


def sum_two_numbers(my_list: list, pos: int):
    temp = []
    for i in range(len(my_list)):
        a = my_list[i]
        if i == len(my_list) - 1:
            break
        b = my_list[i + 1]

        c = a + b

        temp.append(c)

    return inserting(temp, [1, 1], pos)


# First
n = int(input())

list1 = []
all = []

for i in range(1, n + 1):

    if i <= 2:
        list1 = [1] * i

        all.append(list1)
    else:
        akhari = all[len(all) - 1]
        list1 = sum_two_numbers(akhari, 1)
        all.append(list1)


# writing the output
for i in range(len(all)):
    for j in range(len(all[i])):
        print(all[i][j], end=" ")
    print()