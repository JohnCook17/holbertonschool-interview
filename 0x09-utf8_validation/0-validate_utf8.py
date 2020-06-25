#!/usr/bin/python3
"""checks if a list of numbers represents a valid utf-8 char"""


def count_ones(byte):
    """counts the leading ones"""
    for i in range(8):
        if byte >> (7 - i) == 0b11111111 >> (7 - i) & ~1:
            return i
    return 8


def validUTF8(data):
    """checks if data is a valid utf-8"""
    for start_byte in data:
        ones = count_ones(start_byte)
        if ones in (1, 7, 8):
            return False
        for i in range(ones - 1):
            end_byte = data[i]
            if end_byte is None or end_byte >> 6 != 0b10:
                return False
    return True
