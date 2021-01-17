#!/bin/bash

#Qn1

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

#Qn2

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

#Qn3

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


#Qn 5

#5.1
touch File1.txt mypersonaldetails.txt myfrienddetails.txt file2.txt file3.txt

#5.2
echo "Name : Balachander" > File1.txt
echo "Age : 20" >> File1.txt
echo "Course : Software Systems" >> File1.txt
echo "College : PSG" >> File1.txt
echo "City : Palakkad" >> File1.txt

cat mypersonaldetails.txt

#5.3
cp File1.txt mypersonaldetails.txt

#5.4
echo "Name : Yasar" > file2.txt
echo "Age : 20" >> file2.txt
echo "Course : FSE" >> file2.txt
echo "College: CUSAT" >> file2.txt
echo "City : Kochi" >> file2.txt

cp file2.txt myfrienddetails.txt

#5.5
cat mypersonaldetails.txt myfrienddetails.txt > details.txt

#5.6
date >> details.txt

#5.7
mkdir Dir1 Dir2 Dir3 Dir4

#5.8
mv /home/madman/OS/details.txt /home/madman/Dir1

#5.9
rm File1.txt

#5.10
cd ..
cd Dir1

#5.11
pwd

#5.12
cd ~

#5.13
cp details.txt /home/madman/Dir2
cp details.txt /home/madman/Dir3
cp details.txt /home/madman/Dir4

#5.14
mkdir Dir5

#5.15
cd Dir5

#5.16
ls -a /home/madman/

#5.17
cp /home/madman/OS/mypersonaldetails.txt /home/madman/Dir2

#5.18
ls -a /home/madman/

#5.19
rm -rf /home/madman/Dir3




