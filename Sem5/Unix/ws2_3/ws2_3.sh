doc=`ls | grep ".doc$"`
txt=`ls | grep ".txt$"`
echo "$doc"
echo "$(rm -r doc)"
echo "$(rm -r txt)"
if [ ! -z "$doc" ]
then
	echo "$(mkdir doc)"
	echo "$(cp $doc doc)"
fi
if [ ! -z "$txt" ]
then
	echo "$(mkdir txt)"
	echo "$(cp $txt txt)"
fi
