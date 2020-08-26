#!/usr/bin/python3
"""rain algorithm"""


def rain(walls):
    """calculates the volume of rain given a shape"""
    n = len(walls)

    left = [0] * n  # init left
    right = [0] * n  # init right

    water = 0  # init water

    left[0] = walls[0]  # set left wall
    for i in range(1, n):
        left[i] = max(left[i - 1], walls[i])  # finds high point on the left

    right[n - 1] = walls[n - 1]
    for i in range(n - 2, -1, -1):
        right[i] = max(right[i + 1], walls[i])  # find hight point on the right

    for i in range(n):
        water += min(left[i], right[i]) - walls[i]  # fills with water
        # water can not be higher then the min wall height
    return water
