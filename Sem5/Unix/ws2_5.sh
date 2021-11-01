if [ $# -eq 0 ]
then
	echo "No arguments are passed."
else
	for arg in $@
	do
		count=`stat -c'%F' $arg | grep 'regular file'`
		if  [ ! -z "$count" ]
		then
			echo "The file $arg has $(wc -l "$arg" | cut -d" " -f1) lines."
		else
			echo "$arg is not a file."
		fi
	done
fi
