n = int(input())

films = [""] * n

# print(films)

for i in range(n):
    films[i] = input()

for i in range(n):
    print(films[i].title())