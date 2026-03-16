#!/bin/bash

echo "welcome to linux learning"

read -sp "enter a number" num

if [ "$num" -ge 0 ]
then
echo "num entered is $num"
else
echo "number is negative"
fi
