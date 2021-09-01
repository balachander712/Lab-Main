read -p "Enter the character" c
if [[ $c == [A-Z] ]]
then 
    echo "Upper"
elif [[ $c == [a-z] ]]
then
    echo "Lower"
elif [[ $c == [0-9] ]]
then
    echo "Digit"
else
    echo "Special Character"

fi