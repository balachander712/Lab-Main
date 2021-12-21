#!/bin/bash

length=0

function len
{
    length=`echo -n $1 | wc -m`
}

read -p "Enter a string :" str
len $str
echo -e "\n Length $length"