trap abort SIGINT

abort() {
    printf "\nAborted...\n"
    exit
}


while [ true ]
do
    echo "THANK YOU"
    sleep 40
done