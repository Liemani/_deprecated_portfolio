#!/bin/bash

counter=1
while [ $counter -le $(ls | wc -l) ]
do
	mv $(ls | sed -n ${counter}p) $(ls | sed 's/script/sh/' | sed -n ${counter}p)
	((++counter))
done

echo All done

