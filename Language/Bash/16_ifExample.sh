#!/bin/bash

if [ $1 -gt 100 ]    # This conditional expression is actually test command
then
	echo Hey that\'s a large number.
	pwd
fi

date
