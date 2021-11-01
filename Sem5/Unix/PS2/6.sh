#!/bin/bash

filesize(){
    if [ $# = 0 ]
    then
        echo `ls`
        exit
    else
        declare -i sum=0
        for file in $@
        do
            size=$(stat -c '%s' $file)
            sum=$(expr $sum + $size)
        done
    fi
    echo $sum
    return $sum
}

echo $(filesize $@)