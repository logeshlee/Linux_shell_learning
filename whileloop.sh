#!/bin/bash


#$(()) for assigning value
#"multiline comments"

x=5
while [ 1 -le $x ]
do
echo "hi"
((x--))
done
