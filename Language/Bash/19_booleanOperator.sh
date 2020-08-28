#!/bin/bash

if [ -r $1 ] && [ -s $1 ]
then
	echo This file is useful.
else
	echo This file is useless.
fi

