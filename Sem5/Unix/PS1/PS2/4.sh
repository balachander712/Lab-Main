echo "Enter the file name"
read filename

if test -f "$filename"
then
    echo "File exists"
    echo "The size of the file is "
    size=`stat -c '%s' books.dat`
    echo $size
    echo "The owner of the file is"
    owner=`stat -c '%U' books.dat`
    echo $owner
    echo "The permissions of the file are "
    perms=`stat -c '%A' books.dat`
    echo $perms
    echo "The file is last modified on"
    last_modified=`stat -c '%y' books.dat`
    echo $last_modified

    if file $filename | grep -q text$ 
    then
        echo Number of words : $(wc -w "$filename" | cut -d " " -f 1)
        echo Number of words having more than 5 characters: $(grep -o "[a-zA-Z]\{5,\}" "$filename" | wc -l)
        echo Number of words that start with a vowel: $(grep -o "\<[aeiouAEIOU][a-zA-Z]\+" "$filename" | wc -l)
        echo Number of articles in the text file: $(grep -o "\<(a\|the\|an\|A\|The\|An)\>" "$filename" | wc -l)
    else
        exit
    fi

else
    echo "File doest exist"

fi