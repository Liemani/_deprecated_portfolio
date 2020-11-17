#!/bin/bash
# Demonstrate how read actually works

echo What colors do you like?

read -p 'Colors(Enter 3 colors): ' color1 color2 color3

echo Your first color is $color1
echo Your second color is $color2
echo Your third color is $color3
