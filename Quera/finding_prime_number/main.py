import math

def is_prime(num):
    """Check if a number is prime."""
    if num <= 1:
        return False
    if num == 2:
        return True
    if num % 2 == 0:
        return False

    sqrt_num = math.isqrt(num)
    for divisor in range(3, sqrt_num + 1, 2):
        if num % divisor == 0:
            return False

    return True

def get_sum(n):
    """Calculate the sum of digits of a number."""
    return sum(int(digit) for digit in str(n))

n = int(input())
b = get_sum(n)

count = 0
num = n + 1
while count < b:
    if is_prime(num):
        count += 1
    num += 1

print(num - 1)
