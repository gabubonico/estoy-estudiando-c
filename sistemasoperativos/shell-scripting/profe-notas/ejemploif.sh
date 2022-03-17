#!/bin/bash

if [ -d $1 ] #$1 es el valor tomado como parametro (./ejemploif.sh INSERTE-AQUI-SU-ARCHIVO)
then
	echo "$1 es un directorio"
else
	echo "$1 NO es un directorio"
fi

# "[" es un alias de test, por ello se tiene que dejar el espacio. 
# por ejemplo [ -d $1 ] revisa que $1 es un directorio
