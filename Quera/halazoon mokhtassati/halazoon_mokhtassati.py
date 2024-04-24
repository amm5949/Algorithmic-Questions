n = int(input())

count = 1
i = 0
count_horizontal = 1
count_vertical = 1

x, y = 0, 0

while (count < n):
    # print(f'x:{x} y: {y}')
    if i == 0:
        if count_horizontal % 2 == 1:
            x += count_horizontal
        else:
            x -= count_horizontal
        count_horizontal += 1

    elif i == 1:
        if count_vertical % 2 == 1:
            y += count_vertical
        else:
            y -= count_vertical
        count_vertical += 1
    i = (i + 1) % 2
    
    count += 1

# print(f'final x: {x}, final y: {y}')
print(f'{x} {y}')