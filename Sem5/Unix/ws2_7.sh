min=9999999999
for i in $@
do
	ones=`expr $i % 10`
	tens=`expr $i / 10`
	diff=`expr $ones - $tens`
	if [ $diff -lt 0 ]
	then
		diff=`expr $diff \* -1`
	fi
	if [ $diff -lt $min ]
	then
		min=$diff
	fi
done
echo "The minimum difference is $min."
