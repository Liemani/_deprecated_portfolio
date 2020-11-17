#!/bin/bash
# expr calculate the expression and also echo it

expr 5 + 4    # 9

expr "5 + 4"    # 5 + 4

expr 5+4    # 5+4

expr 5 \* $1    # The result of 5 * $1

expr 11 % 2    # 1

a=$( expr 10 - 3 )

echo $a    # 7

