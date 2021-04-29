#!/usr/bin/python3


def isWinner(x, nums):
    """"""
    def is_prime(n):
        """"""
        remainders = []
        if (n <= 1):
            return False
        if (n <= 3):
            return True
        if (n % 2 == 0 or n % 3 == 0):
            return False
        i = 5
        while(i * i <= n):
            if (n % i == 0 or n % (i + 2) == 0):
                return False
            i = i + 6
        return True

    nums.sort()

    def primes(nums):
        """"""
        primes = []
        for n in nums:
            if is_prime(n):
                primes.append(n)

        return primes

    print(primes(nums))

