var=`ls -l | grep "^d" | cut -d" " -f9`
for i in $var
do
	echo "$i"
	upper=$(echo "$i" | tr [:lower:] [:upper:])
	mv $i $upper
done
