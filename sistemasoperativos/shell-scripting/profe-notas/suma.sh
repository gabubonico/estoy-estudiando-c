#!/bin/bash

num=13
echo $num
num=$(expr $num + 1)
# o tambien puedes poner num = $(($num + 1))
echo $num
