#!/bin/python3

import math
import os
import random
import re
import sys



if __name__ == '__main__':
    N = int(input())
    list1=[]

    for N_itr in range(N):
        firstNameEmailID = input().split()

        firstName = firstNameEmailID[0]

        emailID = firstNameEmailID[1]
        if emailID.endswith('@gmail.com'):
            list1.append(firstName)
    list1.sort()
    for i in range(0,len(list1)):
        print(list1[i])
