#!/bin/bash

path="."

if [ $# = 1 ] 
then
    if [ -d $1 ]
    then
        path=$1
    else   
        echo "Enter path of a directory"
        exit 1
    fi 
fi

declare -i sum=0

for file in $(ls $path)
do
    #echo $file
    echo -e "Files greater than 10KB are... \n"
    size=$(stat -c '%s' $path/$file)
    #echo $size
    if [ $size -gt 10000 ]; then
        echo $file
    fi
done

echo -e "The files older than 10 days are...\n"
old=`find $path -type f -mtime +10`
echo $old

echo -e "Size of files older than 10 days are...\n"
echo `find $path -type f -mtime +10 -exec du -ch {} + | grep total$`
