#!/bin/bash
for i in *		# Para cada entrada "i" del directorio donde se ejecuta el script
do 
	if [ -d $i ]	# Chequea si dicha entrada "$i" es un directorio
	then		# En caso de serlo
		FILES=`ls -l "$i" | wc -l`	# Lista el contenido del directorio "$i" y 
# cuenta el numero de líneas
		FILES2=`expr $FILES - 1`	# Le restamos uno puesto que una de las líneas es el
# número de bloques que ocupa el directorio
		# si el directorio esta vacio wc da como resultado 0 y al restarle 1 FILES2 valdra -1
		# en este caso, reasignamos FILES2 a su valor correcto que es 0
		if [ $FILES2 -eq -1 ]  
		then
			FILES2=0
		fi
		echo "$i: $FILES2"	# Muestra el nombre del directorio y el numero de
# entradas que hay en él
	fi  	
done
