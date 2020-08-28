#!/bin/bash

let a=5+4
echo $a    #9

let "b = 5 + 4"
echo $b    #9

let a++    # Equalt to ++a

echo $a    # 10

let "c = 4 * 5"
echo $c    # 20

let "d = $1 + 30"
echo $d    # The result of $1 + 30
