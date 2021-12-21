#!/bin/bash


#Returning values

func1()
{
    echo "Func 1"
    return 4
}

func2()
{
    echo "Func 2"
    return 8
}

func1
echo "Return value from func 1 is " $?

func2
echo "Return value from func2 is " $?