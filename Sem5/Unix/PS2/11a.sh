#!/bin/bash


#with arguments

fresh()
{
    echo "First argument " $1
    echo "All arguments passed $@"
    echo "Args passed $*"
}

echo "Calling first time"
fresh tomato

echo "Calling fresh with 3 args"
fresh tomato chilli paneer