array=(one two three four five)
echo "Array Size : ${#array[*]}"
echo "Array Items : "
for item in ${array[*]}
do
    echo $item
done
echo "Array Indexes:"
for index in ${!array[*]}
do
    echo $index
done

echo "Array items and indexes"
for index in ${!array[*]}
do
    echo $index ${array[$index]}
done

#READ ARRAYS
read -a arr
for i in ${arr[*]}
do
    echo $i
done

echo "printing first element"
echo ${arr[0]}
echo ${arr:0}

echo "Printing all elements"
echo ${arr[@]}
echo ${arr[@]:0}

echo "Printing all elements excpet first one"
echo ${arr[@]:1}

echo "Printing elements in a range"
echo ${arr[@]:1:4}

echo "Prining length of first element"
echo ${#arr[0]}
echo ${#arr}

echo "Number of elements"
echo ${#arr[*]}
echo ${#arr[@]}