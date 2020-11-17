#!/bin/bash

entryCounts=$( ls /etc | wc -l )

echo There are $entryCounts entries in the directory /etc
