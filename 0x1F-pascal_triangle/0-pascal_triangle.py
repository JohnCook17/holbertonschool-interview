#!/usr/bin/env python3
""""""


def pascal_triangle(n):
    """"""
    if n <= 0:
        return []

    triangle = [[1]]
    for row in range(1, n):
        N = [1]
        for col in range(1, row):
            a = triangle[row - 1][col - 1]
            b = triangle[row - 1][col]
            N.append(a + b)
        N.append(1)
        triangle.append(N)

    return triangle
