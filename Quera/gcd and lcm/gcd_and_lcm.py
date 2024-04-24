def gcd(x , y):
    if y == 0:
        return x
    else:
        return gcd(y, x % y)
    
n, m = map(int, input().split())

gcd_of_numbers = gcd(n, m)

print(gcd_of_numbers, int((n*m)/gcd_of_numbers) )