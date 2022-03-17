#!/bin/bash 

for i in * # aqui puede ir cualquier conjunto de elementos "1 2 tres 4 cin co" "{1..6}"
do
	echo $i
done

# si queremos usar la salida de un comando como parametro del for ponemos `COMANDO` o $(COMANDO)
