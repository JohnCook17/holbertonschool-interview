#!/usr/bin/python3
"""uses re to parse logs"""
import sys
import re

line_number = 0
file_size = 0
file_size_matcher = r"\d+$"
error_code_matcher = r" \d\d\d "
my_dict = {"200": 0, "301": 0, "400": 0, "401": 0, "403": 0, "404": 0,
           "405": 0, "500": 0}
try:
    for line in sys.stdin:
        # print(line)
        file_size_str = re.findall(file_size_matcher, line)
        error_code = re.findall(error_code_matcher, line)
        error_code = error_code[0][1:4]
        if error_code in my_dict.keys():
            my_dict[error_code] = my_dict[error_code] + 1
        if file_size_str is not None:
            file_size += int(file_size_str[0])
        if line_number % 10 == 0 and line_number >= 10:
            print("File size: {}".format(file_size))
            for key in sorted(my_dict.keys()):
                if my_dict[key] > 0:
                    print("{}: {}".format(key, my_dict[key]))
            my_dict = {"200": 0, "301": 0, "400": 0, "401": 0, "403": 0,
                       "404": 0, "405": 0, "500": 0}
        line_number += 1
    print("File size: {}".format(file_size))
    for key in sorted(my_dict.keys()):
        if my_dict[key] > 0:
            print("{}: {}".format(key, my_dict[key]))
except KeyboardInterrupt:
    print("File size: {}".format(file_size))
    for key in sorted(my_dict.keys()):
        if my_dict[key] > 0:
            print("{}: {}".format(key, my_dict[key]))
    raise
