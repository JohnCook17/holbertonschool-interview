#!/usr/bin/python3
"""calculates the min number of operations needed to reach a number"""


def minOperations(n):
    """uses prime numbers to calculate the minimum operations of n"""
    if not isinstance(n, int):
        return 0
    if n < 1:
        return 0
    ops = []
    while n % 2 == 0:
        n = n // 2
        ops.append(2)
    for i in range(3, (int((n ** .5)) + 1), 2):
        while n % i == 0:
            ops.append(i)
            n = n // i
    ops.append(n)
    return sum(ops)
