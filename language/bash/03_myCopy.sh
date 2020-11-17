#!/bin/bash
# A simple copy script

# $1 == argv[1]
# $2 == argv[2]

cp $1 $2

# Let's verify the copy worked

echo Details for $2
ls -lh $2
