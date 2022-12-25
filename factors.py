#!/usr/bin/python3
"""RSA Factoring Challenge"""

import sys
try:
    if sys.argv[1]:
        pass
except IndexError:
    print("USAGE: {} <file>".format(sys.argv[0]))
    sys.exit(-1)

try:
    with open(sys.argv[1], "r") as fi:
        contents = fi.readlines()
        for line in contents:
            message="{:d}={:d}*{:d}"
            test_num = 2
            num = int(line)
            if num == 1:
                print(message.format(num, num, num))
            while num > 0 and test_num != num and (num % test_num) != 0:
                test_num += 1
            print(message.format(num, num // test_num, test_num))
except FileNotFoundError:
    print("E: Unable to open file \"{}\"".format(sys.argv[1]))
    sys.exit(-1)
