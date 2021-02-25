#!/usr/bin/python3
"""A change making program for money"""


def makeChange(coins, total):
    """tries to give exact change given a list of coins with a specified values
       if unable to do so returns -1"""

    if total == 0:
        return 0

    coins.sort(reverse=True)

    new_total = total
    total_change = 0
    total_value = 0

    for coin in coins:
        current_change = 0
        if coin == new_total:
            current_change = new_total // coin
            total_value += current_change * coin
            total_change += current_change
        elif total % coin > 0:
            current_change = new_total // coin
            new_total = new_total % coin
            total_value += current_change * coin
            total_change += current_change

    if total == total_value:
        return total_change
    else:
        return - 1
