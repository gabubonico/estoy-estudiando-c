#!/bin/bash

for i in $1/*
do
	if [ -d $i ]
	then
		./findbigfiles.sh $i/*
	fi
done
