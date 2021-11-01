echo "1. Content of /etc/passwd"
echo "2. List of users currently logged in"
echo "3. Sum, product of the digits and factorial of a number"
echo "4. Find Power"
echo "5. EXIT"
read -p "Enter your choice" choice
case $choice in
1)  echo "Contents of /etc/passwd"
    `head -n15 /etc/passwd` 
    ;;
2) echo "Logged in users : " $(users)
    ;;
3) read -p "Enter the number : " number
    declare -i sum=0
    declare -i product=1
    declare -i factorial=1
    num=$number
    while [ $num -gt 0 ]
    do
        sum=$(expr $sum + $(expr $num % 10))
        product=$(expr $product \* $(expr $num % 10))
        num=$(expr $num / 10)
    done
    echo "Sum of digits ;" $sum
    echo "Product of digits :" $product
    num=$number
    while [ $num -gt 0 ]
    do
        factorial=$(expr $factorial \* $num)
        num=$(expr $num - 1)
    done
    echo "Factorial is :" $factorial
    ;;
4) read -p "Enter the number" number
   read -p "Enter the exponent" exp
   declare -i result=1
   for ((i = 1; i <= exp; i++))
   do
    result=$(expr $result \* $exp)
   done
   echo "The $number power $exp is $result"
    ;;
5) exit
    ;;

*) echo "Invalid choice"
esac
