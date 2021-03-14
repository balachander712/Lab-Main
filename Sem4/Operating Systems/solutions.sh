#!/bin/bash

#QUESTION_1

#1.a
echo ~
echo $HOME

#1.b
mkdir OS

#1.c
cd OS
mkdir assign1

#1.d
mkdir assign2

#1.e
ls

#l.f
rmdir assign2

#1.g
ls

#QUESION 2

#2.a
cd OS

#2.b
mkdir assign2

#2.c
touch MyFile.txt
echo "The shawshank Redemption is my fav movie" > MyFile.txt
echo "Biriyani is my fav food" >> MyFile.txt

#2.d
cat MyFile.txt

#2.e
cp /home/madman/OS/MyFile.txt /home/madman/OS/assign1
mv MyFile.txt t_1.txt

#2.f
cd assign1

#2.g
cp t_1.txt t_2.txt

#2.h
ls

#2.i
cp t_1.txt /home/madman/OS/assign2

#2.j
ls /home/madman/OS/assign2

#2.k
rm t_1.txt

#2.l
ls /home/madman/OS/assign1

#QUESTION 3

#3.a
cd OS

#3.b
mkdir assign3

#3.c
touch Test_1.txt Test_2.txt Test_1-1.txt Test_2-1.txt Test_1-2.txt Test_2-2.txt Test_1-1.bak Test_2-1.bak File_1.bat

#3.d
ls

#3.e
ls *.txt

#3.f
ls -R | grep 't$'

#3.g
cp -R $(ls | grep 't_1') assign3

#3.h
ls /home/madman/OS/assign3

#3.i
ls -R | grep 'Test_2'

#3.j
cp -R $(ls | grep 'Test_1.txt') tot.txt

#3.k
ls | wc -l

#3.l
ls > list.txt

#3.m
cp /home/madman/a* .

#3.n
rm -r $(ls -d ??)

#3.o
rm -rf test

#3.p
ls /

#Qn4 

#4.a
df -h

#4.b
du

#4.c
wc -l MyFile.txt
wc -c MyFile.txt
wc -L MyFile.txt

#4.d
now=$(date)
echo "now"

#4.e
echo $(date "+%d/%m/%Y")

#4.f
ls -a
#we can see the hidden files like .bash_history,.bash_logout,.bashrc,.landscape,.profile

#4.g
ls -R

#4.h
wc -l #count number of lines
wc -w #count number of words
wc -m #count number of characters

#4.i
wc -l

#4.j
cat tot.txt

#4.k
more tot.txt

#4.l
more -d tot.txt

#4.m
grep 'Length' tot.txt | more
grep 'Length' tot.txt | less
#less command is silimar to more command but it have more options than more command

#4.n
head -5 verylong.seq


#QUESTION 5

# Create several empty files 'File1', 'mypersonaldetails', 'myfrienddetails',
# 'file2', 'file3' quickly by one command.
touch File1.txt mypersonaldetails.txt myfrienddetails.txt file2.txt file3.txt

# Store your personal data such as name, age, course, college, and city
# (separated by comma) into a file File1 and display the contents
echo "Balachander, 20, SS, PSG tech, Coimbatore" > File1.txt
cat File1.txt

# Copy the contents of the file File1 into another file mypersonaldetails.
cp File1.txt mypersonaldetails.txt

# Create another file myfrienddetails to store the details given in question 2.
echo "Balachander, 20, SS, PSG tech, Coimbatore" > myfrienddetails.txt

# Combine the contents of the files mypersonaldetails and myfrienddetails
# into another file details.txt.
cat myfrienddetails.txt mypersonaldetails.txt > details.txt

# Append the current date and time into the file details.txt.
date > details.txt

# Create the following directories using a
# single line command in your home directory.
# Dir1, Dir2, Dir3 and Dir4
mkdir ~/Dir1 ~/Dir2 ~/Dir3 ~/Dir4


# Move the file details.txt into Dir1.
mv details.txt ~/Dir1

# Delete the file File1.
rm File1.txt

# Change your current working directory to Dir1.
cd ~/Dir1

# Write the path of your current working directory.
pwd

# Go back to your home directory without using its name.
cd

# Copy the file details.txt into the directories Dir2, Dir3 and Dir4.
cp ~/Dir1/details.txt Dir2
cp ~/Dir1/details.txt Dir3
cp ~/Dir1/details.txt Dir4

# Create a directory Dir5 under Dir1.
mkdir ~/Dir1/Dir5

# Go to Dir5 using a single line command.
cd ~/Dir1/Dir5

# List all the files in your home directory.
ls ~

# Copy the file mypersonaldetails into Dir2 without changing the working directory
cp ~/OS/mypersonaldetails.txt ~/Dir2

# List all the files in your home directory.
echo "Same as second-last question"
# Delete the directory Dir3.
rm ~/Dir3 -r

# Create the following files : apple, orange1, orange2, orange3, pineapple, quartz.
# Write the output of the following commands.
# a) ls a?    b)ls a*    c)ls *.*    d)ls[!abc]ange    e) ls[a!bc]ange    f)ls[b-efg-z]*
touch apple.txt orange1.txt orange2.txt orange3.txt pineapple.txt quartz.txt
echo "a) no matches found: a?"
echo "b) apple.txt"
echo "c) apple.txt  orange1.txt  orange2.txt  orange3.txt  pineapple.txt  quartz.txt"
echo "d) event not found: abc]ange"
echo "e) event not found: bc]ange"
echo "f) orange1.txt  orange2.txt  orange3.txt  pineapple.txt  quartz.txt"

# List all the file names in which the character
# just before the last character is a digit.
ls -d *[0-9]?

# List all the files that starts with the letter a or b or c.
ls -d [abc]*

# Write the access permissions of files after each of the following command is executed.
# a) chmod  777 details.txt    b) chmodu+w g-w details.txt
# c)chmod 000 details.txt    d) chmodug+rw a=x details.txt
# e) chmodu+t Dir1
echo "a) -rwxrwxrwx"
echo "b) -rwxr-xrwx"
echo "c) ----------"
echo "d) ---x--x--x"
echo "e) drwxr-xr-x"

# Remove read and execute permissions for the owner of the file details.txt
chmod u-rx details.txt

# List all the files in your home directory along with the inode number
ls -ia

# Create a soft link for the file sum.txt and check the inode numbers
ln -s details.txt sum.txt

# Create a hard link for the file sum1.txt and place it under
# Dir2 and check the inode numbers
ln details.txt sum1.txt

# Create a link for the directory Dir1( check both hard and soft links).
ln -s ~/Dir1 sum.txt
ln ~/Dir1 sum1.txt

# Change the modification time of the file mypersonaldetails.txt
touch -m ~/OS/mypersonaldetails.txt

# List the files of the parent directory.
ls ../

# Append A Text File's Contents To Another Text File
cp ../details.txt copy.txt
cat ../details.txt >> copy.txt

# Display Line Numbers in File
wc -l copy.txt

# Find out the number of files in a directory.
ls | wc -l

# Create two regular files ‘file1’ and ‘file2’. Fill up the files with some text. Write a
# command to display the differences in the files, if any.
echo "My test string" > file1.txt
echo "My test string 1" > file2.txt
diff file1.txt file2.txt

# Display the time in 12-Hour and 24 Hour Notations
date +'%r'
date +'%R'

# Display Today’s date and time in the following format. DATE: 12/08/15 TIME:15:50:44
date +'DATE: %x TIME: %X'

# Display the calendar for the month of July in the year 2020
cal 07 2020

# Create the two files namely f1 and f2 with the following contents.
echo 'Henry\nMonty\nSumit\nCharlie\nJulie\nSumit' > f1
echo 'Charlie\nJulie\nMonty\nBob\nHarry' > f2

echo "Lines in f2 but not in f1: "
while IFS= read -r line;
do
    if ! grep -q $line f1; then
        echo $line
    fi
done < f2

# Combine the contents of f1 and f2 and display the details.
cat f1 f2

# Sorting Contents of Multiple Files in a Single File
sort f1 f2 | uniq > f0

# Write a command to display the following: “There are ______ files in the current directory.” (without the quotes)
echo "There are ______ files in the current directory."

# The ______ (dash) is to be replaced with the number of files in the current directory.
echo "There are $(ls -d | wc -l) file(s) in the current directory."

#QUESTIOn 7

uname -r

# To print the login name
echo $USER

# To print the host name
hostname

# Find out the users who are currently logged in and find the particular user too.
who

# Display the calendar for
# Jan 2000
cal jan 2000
# Feb 1999
cal feb 1999
# 9th month of the year 7 A.D
cal 9 7
# For the current month
cal
# Current Date Day Abbreviation , Month Abbreviation along with year
cal

# Display the time in 12-Hour and 24 Hour Notations.
echo 'Repeat of 5th Qn 35'

# Display the Current Date and Current Time.
echo 'Repeat of 5th Qn 36'

# Display the message “GOOD MORNING” in enlarged characters.
banner 'GOOD MORNING' # Does not work by default on Arch

# Display the name of your home directory.
echo $HOME

# Create a directory SAMPLE under your home directory.
mkdir ~/SAMPLE

# Create a sub-directory by name TRIAL under SAMPLE.
mkdir ~/SAMPLE/TRIAL

# Change to SAMPLE.
cd ~/SAMPLE

# Change to your home directory.
cd ~

# Change from home directory to TRIAL by using absolute and relative pathname.
cd ./SAMPLE/TRIAL
cd $HOME/SAMPLE/TRIAL

# Remove directory TRIAL.
rm -r ~/SAMPLE/TRIAL

# Create a directory TEST using absolute pathname.
mkdir ~/TEST

# Using a single command change from current directory to home directory.
cd ~

# Create empty files myfile and yourfile under Present Working Directory.
touch myfile yourfile

# Add some lines in the myfile and yourfile files.
echo 'Some random line\nblah blah blah' > myfile
echo 'Some random line2\nblah blah blah ver 2' > yourfile

# Display the files myfile and yourfile.
cat myfile yourfile

# Create a hidden file myhid.
touch .myhid

# Display all files in the current working directory
ls

# Display all files including hidden files in the current working directory
ls -a

# Copy myfile file to another file emp.
cp myfile emp

# Write the command to create alias name for the file myfile. ?
alias file_temp='myfile'

# Move yourfile file to another file dept.
mv yourfile dept

# Copy emp file and dept file to TRIAL directory
echo 'TRIAL dir already deleted. Recreating it'
mkdir ~/SAMPLE/TRIAL
cp emp ~/SAMPLE/TRIAL

# Compare a file with itself.
cmp dept dept

# Compare myfile file and emp file.
cmp myfile emp

# Append two more lines in emp file existing in TRIAL directory.
echo 'Extra lines \nYahallo~' >> ~/SAMPLE/TRIAL/emp

# Compare employee file with emp file in TRIAL directory.
cmp emp ~/SAMPLE/TRIAL/emp

# Find the difference between the above file.
diff emp ~/SAMPLE/TRIAL/emp

# Remove the files in the TRIAL directory.
rm -r ~/SAMPLE/TRIAL/*

# Remove a directory with files by using a single command?
# rm -r [dirname...]

# Is there any command available to get back a deleted file?
# extundelete is a possible choice for ext filesystems
# btrfs filesystems generally has periodic backup which can be used to restore
# Needs more research on other filesystems

# Rename TRIAL as DATA.
mv ~/SAMPLE/TRIAL ~/SAMPLE/DATA

# Copy DATA to another directory by name TRIAL.
cp ~/SAMPLE/DATA ~/SAMPLE/TRIAL

# Create a file called dummy in TRIAL and link it to another file by name star.
touch ~/SAMPLE/TRIAL/dummy
ln -T ~/SAMPLE/TRIAL/dummy ~/SAMPLE/TRIAL/star

# Print “Hello Welcome to OS Class” ?
echo 'Hello Welcome to OS Class'

# Get a value from the user and store it in a variable.
read RANDOM_VAR

# Print the value of the variable. 
echo  $RANDOM_VAR

# Make a variable as global
export RANDOM_VAR

# Write a command to perform numeric operation 11 + 11.
expr 11 + 11

# Print the result of 11 + 11 as ‘Result is 22’
echo "Result is $((11 + 11))"

# Read two integers into two variables and add them &amp; store it in a variable.
echo 'Enter the First Value: '
read FIRST
echo 'Enter the Second Value: '
read SECOND 
RESULT=$(($FIRST + $SECOND));

# Print the result as ‘Sum of &lt;first&gt; and &lt;second&gt; is &lt;result&gt;’
echo "Sum of $FIRST and $SECOND is $RESULT"

# Do all other arithmetic operations and print the result.
echo "Subtraction of $FIRST by $SECOND is $(($FIRST - $SECOND))"
echo "Multiplication of $FIRST and $SECOND is $(($FIRST * $SECOND))"
echo "Division of $FIRST by $SECOND is $(($FIRST / $SECOND))"
echo "Modulo of $FIRST by $SECOND is $(($FIRST % $SECOND))"
echo "Exponentiation of $FIRST by $SECOND is $(($FIRST ** $SECOND))"

# Try for floating point numbers.
echo 'Enter the First Value: '
read FIRST
echo 'Enter the Second Value: '
read SECOND 
echo "Addition of $FIRST with $SECOND is " $(echo "$FIRST + $SECOND" | bc -l)
echo "Subtraction of $FIRST by $SECOND is " $(echo "$FIRST - $SECOND" | bc -l)
echo "Multiplication of $FIRST and $SECOND is " $(echo "$FIRST * $SECOND" | bc -l)
echo "Division of $FIRST by $SECOND is " $(echo "$FIRST / $SECOND" | bc -l)
echo "Modulo of $FIRST by $SECOND is " $(echo "$FIRST % $SECOND" | bc -l)
echo "Exponentiation of $FIRST by $SECOND is " $(echo "$FIRST $SECOND" | awk '{print $1^$2;}')

# Login as root and create group as SS with id 501 &amp; DS with id 555
groupadd -g 501 ss
groupadd -g 555 ds

# Creating a list of users
useradd user1 -m -g 501 -s /bin/sh -G ds -c "user 1 user"
useradd user2 -m -u 502 -g 501 -s /bin/tcsh -c "user2 user"
useradd user3 -m -u 503 -g 501 -s /bin/bash -G ds -c "user3 user"
useradd user4 -m -u 504 -g 555 -s /bin/sh -c "user4 user"
useradd user5 -m -u 505 -g 555 -s /bin/bash -c "user5 user"

# Examine the content of the /etc/passwd file.
# user1:x:1002:501:user 1 user:/home/user1:/bin/sh
# user2:x:502:501:user2 user:/home/user2:/bin/tcsh
# user3:x:503:501:user3 user:/home/user3:/bin/bash
# user4:x:504:555:user4 user:/home/user4:/bin/sh
# user5:x:505:555:user5 user:/home/user5:/bin/bash

#Examine the content of the /etc/shadow file. Name the text that is found in the second
#field for the users created.
# The second field represents the password in a encrypted formant

# Set password for the users User1, User2, User3
passwd user1
passwd user2
passwd user3

# Select user2 from the list of users. Change the passwd aging information for user2
passwd -x 4 -i 2 user2

# Now change the system date increase by 5 days
date +%Y%m%d -s $(date -d "+5 days" +%Y%m%d)

# Logout of login session. Attempt to log as user2. What happens?
We receive a alert indicating that the password has expired and needs to be changed

# Change the shell for the user2 to Bourne shell.
chsh -s /bin/sh user2

# Delete user2 including his home directory and his comments.
userdel -r user2

# Lock the user1 with the help of a single command.
passwd -l user1 # or usermod -L user1

# Identify the available memory in the system.
free

# Display the list of devices connected to your system including the physical names and its
# instance number.
lspci
lsusb
lsblk

# Identify the number of hard disks connected to the system.
fdisk -l

# Login as a normal user
su user1

# Create file test
touch test

# Find the permissions of file test
ls -l

# Change the ownership of the file to user1
chown test user1

# Find the current umask setting
umask

# Change the umask setting
umask 0002

# Create file test1
touch test1

# Find out the difference
# The 0002 as the umask, the group memebers also get wite acces to the file

# Switch to Super User Account
su

# Change group of file test
chown :ds test

# Change ownership and group of file test1 with a single command
chown user4:ds test1

# Change the ownership of all the files in user1’s home directory with a single command
chown -R user3 /home/user1/*

# Create a file abc and turn the execute bit on
touch abc 
chmod +x abc

# Set setuid permission on the file abc
chmod u+s abc

# Determine if the setuid permission is enabled on the file abc
ls -l

# Create a directory testdir
mkdir testdir

# Set setgid permission on the testdir
chmod g+s -R testdir
chmod a+rw testdir # allow others to edit it

# Logout and login as user1
# Create a file testfile in testdir
touch testdir/testfile

# Verify the ownership and the group of the testfile
# The owner is the group of the parent dir due to setgid

# Switch to Superuser account
# Create a public directory dir1
mkdir /dir1
chmod a+rw /dir1

# Set stickybit (save text attribute) on dir1
chmod +t /dir1

# Logout and login as a normal user user1
# Create a file userfile1 in dir1
touch /dir1/userfile1

# Login as a different user user2
# Try to edit or remove the file
# Permission Denied

# Temporarily disable user logins
nano /etc/nologin

# List the processes for the current shell.
pstree $$ -g 

# Display information about processes.
top 

# Display the global priority of a process and find out the column that provides.
# The PR and NI columns of `top` displays the process priority

# Change the priority of a process with default arguments.
nice --15 ps

# Display Virtual Memory Statistics.
vmstat

# Display System Event Information.
journalctl # for Arch based distros

# Display Swapping Statistics.
# Check Buffer Activity statistics.
free

# Check Disk Activity statistics.
iotop # or iostat

# Check Inter process Communication statistics.
ipcs -a

# Check Unused Memory in the server.
# Check Swap Activities
free


#QUESTION 7

echo '123\n123\n234\n123\n234\n567\n' > dfile.txt

# I) Display the no of occurrence of the record
cat dfile.txt | sort | uniq -c

# II) Display only the duplicate records
cat dfile.txt | sort | uniq -d

# III) Display distinct records
cat dfile.txt | sort | uniq

# Create a file accounts.txt with the following contents
# ANU MANAGER
# KARTHIK ADMIN
# SHRIDAR HR
# BANU MANAGER
# VINOTH DIRECTOR
echo 'ANU MANAGER\nKARTHICK ADMIN\nSHRIDAR HR\NBANU MANAGER\nVINOTH DIRECTOR' > accounts.txt

# Find and replace the string ‘MANAGER’ with ‘ASSTMANAGER’ in the file accounts.txt
sed -e s/MANAGER/ASSTMANAGER/g accounts.txt

# The ls –i command displays a filename preceded by the inode number of the file
ls -i | sort
ls -i | sort -k 2


# List 5 last modified files
ls -lt | head -6

# QN 5
echo 'Balachander\nBrimstone\nSage\nKilljoy\nOmen\nBreach\nReyna\n' > somerandomfile
cut -c-2 somerandomfile | tr a-z A-Z | sort -r > anotherfile

# QN 6
echo "Balachander\nBrimstone\nSage\nKilljoy\nOmen\nBreach\nReyna\n" > name.txt
echo "1\n2\n3\n\4\n5\n6\n7\n" > reg.txt

paste reg.txt name.txt > anotherfile.txt

ls | grep .txt

# Display the common and distinct line of contents from a file(comm)
echo "Balachander\nBrimstone\nSage\nKilljoy\nOmen\nBreach\nReyna\n" > name01.txt
echo "Balachander\nBrimstone\nSage\nKilljoy\nOmen\nBreach\nReyna\n" > name02.txt

comm -12 name01.txt name02.txt
comm -3 name01.txt name02.txt

# QN 7
# Create two files with list of names in each file.
echo "Balachander\nBrimstone\nSage\nKilljoy\nOmen\nBreach\nReyna\n" > name01.txt
echo "Balachander\nBrimstone\nSage\nKilljoy\nOmen\nBreach\nReyna\n" > name02.txt

# Combine the two files without duplicate and store it in a new file.(sort,uniq)
cat name01.txt name02.txt | sort | uniq > newfile.txt

# To view only the files in a directory.(find)
find . -type f -maxdepth 1

# Concatenate 3 list files, sort them, remove duplicate lines and finally writes the result to an output file.
echo "Balachander\nBrimstone\nSage\nKilljoy\nOmen\nBreach\nReyna\n" > name01.txt
echo "Balachander\nBrimstone\nSage\nKilljoy\nOmen\nBreach\nReyna\n" > name02.txt
echo "Balachander\nBrimstone\nSage\nKilljoy\nOmen\nBreach\nReyna\n" > name03.txt
cat name01.txt name02.txt name03.txt | sort | uniq > newfile1.txt

# Print a file from the second line to the 10th line
sed -n 2,10p newfile1.txt

# Show the 15 most recent items in your command history
history | tail -n 15

# Store the history into file hfile. Merge the lines 11-15 from Hfile and lines 26-30 from the
# same file Hfile and save them both to another 
history > hfile
sed -n 11,15p hfile > newfile
sed -n 26,30p hfile >> newfile


# How to check for full word “is” in a file, not for sub-strings using grep
echo "grep -w is <file>"

# How to display N lines after match of the “is” word in the file
echo "grep -w is -A 10 <file>"

# Display N lines before match
echo "grep -w is -B 10 <file>"

# Display N lines around match
echo "grep -w is -C 10 file"

# Searching in all files recursively
echo "grep -r <regex> <folder path>"

# To display the lines which does not matches the given string/pattern,
echo "grep -v <regex> <file path>"

# Display the lines which does not matches all the given pattern.
echo "grep -v -e <regex1> -e <regex2> <file path>"

# Counting the number of matches to a word in a file using grep -c
echo "grep -c <regex> <file path>"

# Show line number while displaying the output using grep -n
echo "grep -n <regex> <file path>"

# Show the position of match in the line
echo "awk -v s=\"<string>\" 'i=index($0, s) {print NR, i}' <file path>"

# Search for the lines which starts with a number.
grep -e '[0-9].*' newfile

# Display the file names that do not contain the pattern.
echo "grep -L -r <regex> <folder path>"

# Write a sed command that deletes the first character in each line in a file.
sed 's/^.//' newfile

# Write a sed command that deletes the last character in each line in a file.
sed 's/.$//' newfile


#OUESTION 8

whereis bash

# Use the --version option to find out which version you are running.
whereis --version

# Create 3 variables, VAR1, VAR2 and VAR3; initialize them to hold the values
# thirteen, 13 and Happy Birthday respectively.
VAR1="thirteen"
VAR2=13
VAR3="Happy Birthday"

# Display the values of all three variables. Remove VAR3.
echo $VAR1 $VAR2 $VAR3
unset VAR3

# Can you see the two remaining variables in a new terminal window?
# No

# QN 6
ps -el
# Processes running with UID 0 can be considered 'system-wide' processes


# QN 7
# Can you use grep to see how many of your processes are running?
ps -U $UID
# The -U flag makes ps look for user specific processes with a list of UID which follows the -U flag
ps -el | grep $UID
# This is not same as -U flag as this also matches any line containing the same numbers as the UID


# QN 8
# Observation: you need read permission to list the files of a directory.
# You need write permission to create a file.

# QN 9
# Use a combination of cat (or more) and grep to display information in /etc/passwd about your own details
cat /etc/passwd | grep $UID

# What does this line mean?
# It represents the entry for my user account

# Which character is used to separate fields in the file?
# colon :

# How is your password stored?
# In a encrypted form

# If you try and access /etc/shadow what happens?
# Permission denied for normal user

# How many different shells can you find when looking at /etc/passwd file - which are they?
# 4
# /bin/bash
# /bin/zsh
# /usr/bin/nologin
# /usr/bin/git-shell

# QN 10
# I use zsh as my main shell, so my .zshrc has
alias rm='rm -r'
alias cl='clear'
alias ls='ls --color=auto'
alias zshconfig="nano ~/.zshrc"                                                                                                                                     
alias ohmyzsh="nano ~/.oh-my-zsh"                                                                                                                                   
alias dps="docker ps"                                                                                                                                               
alias dk="docker kill"                                                                                                                                              
alias dpsa="docker ps -a"                                                                                                                                           
alias drm="docker rm"

# QN 11
# Edit /etc/profile so that all users are greeted upon login (test this).
# Tested and verified by editing the file as root and using a command-line
# (non X session) to login

# QN 12
PS1="Danger!! root is doing stuff in \w > " >> ~/.bashrc # as root


# QN 13
ls -l | sort -k 5 --numeric-sort

# QN 14
# Display a list of all the users on your system who log in with the Bash shell as a default.
cat /etc/passwd | grep /bin/bash

# QN 15
# From the /etc/group directory, display all lines starting with the string &quot;daemon&quot;.
cat /etc/group | grep '^daemon'

# QN 16
# Print all the lines from the same file that don&#39;t contain the string.
cat /etc/group | grep -v '^daemon'

# QN 17
# Display localhost information from the /etc/hosts file, display the line number(s)
# matching the search string and count the number of occurrences of the string.
cat /etc/hosts | grep -n localhost
echo "Count : $(cat /etc/hosts | grep -c localhost)"

# QN 18
# Display a list of /usr/share/doc subdirectories containing information about shells.
find /usr/share/doc -name '*sh/README'

# QN 19
# How many README files do these subdirectories contain? Dont count anything in the form of README.a_string
find /usr/share/doc -wholename '*sh/README' | grep -v "README\..*"

# QN 20
# Make a list of files in your home directory that were changed less than 10 hours ago,
# using grep, but leave out directories.
find . -mmin -600

# QN 21
# Can you find an alternative for wc -l, using grep?
echo "grep -c '' <file>"

# QN 22
# Using the file system table (/etc/fstab for instance), list local disk devices.
cat /etc/fstab | grep -v "#"
# To actually list the devices connected to the system, 'fdisk -l' or gdisk might be a better choice

# QN 23
# Display configuration files in /etc that contain numbers in their names.
ls /etc | grep -e '[0-9]'

# QN 24
# The command top shows all processes (and other information about the system). Check it out.
# htop and glances other good morden alternatives to this.

# QN 25
sed -e '/^\s*$/d' -e '/^#/d' /etc/hosts

# QN 26
# setfacl and getfacl commands can be used to allow and modify Access Control Lists 
# which can leveraged to allow other users to access another user's home directory
