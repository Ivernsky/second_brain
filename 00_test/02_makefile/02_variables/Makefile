files := file1 file2
some_file: $(files)
	echo "Look at this variable: " $(files)
	touch some_file

file1:
	touch file1
file2:
	touch file2

clean:
	rm -f file1 file2 some_file

##############################################
a := one two # a is assigned to the string "one two"
b := 'one two' # Not recommended. b is assigned to the string "'one two'"
cmd1:
	printf '$a'
	printf $b

##############################################
x := dude
cmd2:
	echo $(x)
	echo ${x}

	# Bad practice, but works
	echo $x 
