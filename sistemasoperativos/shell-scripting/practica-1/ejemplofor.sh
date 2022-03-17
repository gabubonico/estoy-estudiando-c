#!/bin/bash

for i in *
do
	if [ -f "$i" ]
	then
		echo "$i es un fichero"
	else
		echo "$i NO es un fichero"
	fi
done
