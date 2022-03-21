#!/bin/bash

if  [ ! $(ls $2) ]
then
	mkdir --parents $2
fi

for i in $1/*
do
	artista=$(cat $i | grep "autor" | cut -d ":" -f 2)
	cancion=$(cat $i | grep "titulo" | cut -d ":" -f 2)

	if  [ ! $(ls $2/$artista) ]
	then
		mkdir --parents $2/$artista
	fi

	cp $i $2/$artista/$cancion.mp3
done
