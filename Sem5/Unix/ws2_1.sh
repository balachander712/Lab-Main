while [ true ]
do
	read -p "Enter the choice: " choice
	case $choice in
	"a")
		echo "The employee with highest salary is $(sort -t "|" -k 5 -n -r employee.dat | head -n1)"
	;;
	"c")
		echo "$(cat employee.dat | tr "|" ":")"
	;;
	"d")
		echo "$(grep "marketing" employee.dat | cut -d"|" -f2 | tr [:lower:] [:upper:])"
	;;
	"e")
		echo "$(grep -i "gupta" employee.dat | cut -d"|" -f2 | sort -r -u)"
	;;
	"f")
		echo "$()"
	;;
	"g")
		echo "$(grep "012\|123\|234\|345\|456\|567\|678\|789" employee.dat)"
	;;
	"h")
		echo "$(ls -l | grep "^-\|d" | wc -l)"
	;;
	"11")
		echo "Exiting the program..."
		break;
	;;
	esac

done
