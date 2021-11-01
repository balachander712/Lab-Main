echo "1. ENTER RECORD"
echo "2. DELETE RECORD"
echo "3. LIST ALL BOOKS"
echo "4. PRINT BOOK OF AN AUTHOR"
echo "Enter your choice"
read ch
case $ch in
1) echo "Enter the record in the format accession-no|name of the book|author"
    read data
    echo $data >> books.dat
    ;;
2) echo "Enter the book name to delete"
    read book_name
    grep -v "$book_name" books.dat > tmpfile && mv tmpfile books.dat
    ;;
3) cat books.dat
    ;;
4) echo "Enter the author name"
    read author
    echo $(grep "$author$" books.dat)
    #echo $data
esac