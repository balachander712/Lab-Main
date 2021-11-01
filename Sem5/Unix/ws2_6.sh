user_write=`ls -l | cut -c3 | grep "w" | wc -l`
group_read=`ls -l | cut -c5 | grep "r" | wc -l`
others_execute=`ls -l | cut -c10 | grep "x" | wc -l`
echo "Detail \t\t Permissions \t No of files"
echo "User \t\t W \t\t $user_write"
echo "Group \t\t R \t\t $group_read"
echo "Other \t\t X \t\t $others_execute"
