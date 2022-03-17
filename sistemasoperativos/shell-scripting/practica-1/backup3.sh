#!/bin/bash 

date=$(date +"%Y%m%d")

if [ ! $(ls backup/$date) ]
then
	mkdir --parents backup/$date
fi

for i in "$@"
do
	if [ ! -f "$i" ]
	then
		echo $i no existe
	else
		cp $i backup/$date/
	fi
done
