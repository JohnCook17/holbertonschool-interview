#!/usr/bin/python3
"""determines how much rain can be trapped in an area"""


def rain(walls):
    """walls is an list of the hight of a 1x1 uint wall"""
    water = 0

    for i in range(1, len(walls) - 1):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])

        right = walls[i]

        for j in range(i + 1, len(walls)):
            right = max(right, walls[j])

        water = water + (min(left, right) - walls[i])

    return water
