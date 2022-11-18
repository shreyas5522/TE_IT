#!/bin/sh
# Assignment no 1 in the SL-II syllabus

create ()
{
	echo "Enter Address book name"
	read ab 
	#checking whether the given name already exists or not with -e
	if [ -e $ab ]
	then 
		echo "ERROR: File already exists: Delete existing file \n"
		echo "Enter 1 to delete existing file & Create new AddressBook"
		read dexf
		if [ $dexf = 1 ]
		then 
			rm $ab
			touch $ab
		fi
	else
		touch $ab
	fi
}

view()
{
	echo "Enter file name to display"
	read vfile
	if [ -e $ab ]
	then
		echo "==================================="
		cat  $vfile
		echo "=================================== \n"
	fi
}

insert()
{
	echo "Enter Address Book Name: To Insert Records"
	read ab
	res=`ls | grep $ab | wc -w`
	
	if [ $res -gt 0 ]
	then
		echo "Enter Email"
		read emaill
		
		#Checking if email already exists or not.
		lens=`cat $ab | grep $emaill | wc -w`
		if [ $lens -gt 0 ]
		then
			echo "Error: Email already exists"
		else
			echo "Enter First Name"
			read fname
			echo "Enter Last Name"
			read lname
			echo "Enter Address"
			read address
			echo "Enter Mobile Number"
			read mob
			record=`echo $fname $lname $emaill $address $mob`
			echo $record >> $ab
			echo "Records Successfully Inserted"
		fi
	else
		echo "ERROR: Adress Book Not Found"
	fi
			
}

modify()
{
	echo "Enter Address Book Name: To Insert Records"
	read ab
	#Checking if address book there or not
	res=`ls | grep $ab | wc -w`
	
	if [ $res -gt 0 ]
	then
		echo "Enter Email"
		read emaill
		
		#Checking if email already exists or not.
		lens=`cat $ab | grep $emaill | wc -w`
		if [ $lens -gt 0 ]
		then
			echo "Email Found"
			old=`cat $ab | grep $emaill `
			echo "Existing Values: $old"
			echo "Enter the New Values \n"
			echo "Enter First Name"
			read fname
			echo "Enter Last Name"
			read lname
			echo "Enter Address"
			read address
			echo "Enter Mobile Number"
			read mob
			new=`echo $fname $lname $emaill $address $mob`
			echo "Old Record: $old"
			echo "New Record: $new"
			
			sed -i s/"$old"/"$new"/ g $ab
			echo "Record Modified"
		else
			echo "Error: Email not found"
		fi
	else
		echo "Error: Adress Book Not Found"
	fi
}

delete()
{
	echo "ENTER Address Book Name"
	read ab
	res=`ls | grep $ab | wc -w`
	if [ $res -gt  0 ]
	then
		echo " >>Address Book selected: $ab"
		echo "Enter the Email Address: For Deleting Record"
		read emaill
		lens=`cat $ab | grep $emaill | wc -w `
		old=`cat $ab | grep $emaill `
		if [ $lens -gt 0 ]
		then 
			echo ">>This Record: $old"
			sed -i s/"$old"//g $ab
			sed -i s/^$/d $ab
			echo "Recorded Deleted"
		
		fi
	else
		echo "ERROR: ADDRESS BOOK Not Found! "
	fi
}

while [ true ]
do
	echo "******MENU******"
	echo "1. Create"
	echo "2. View"
	echo "3. Insert"
	echo "4. Modify"
	echo "5. Delete"
	echo "7. Exit"
	
	echo "Enter Choice"
	read choice
	
	case $choice in
		1) create ;;
		
		2) view ;;
		
		3) insert ;;
		
		4) modify ;;
		
		5) delete ;;
		
		7) exit ;;
		
		*) echo "wrong choice" ;;
	esac
done
