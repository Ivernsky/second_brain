all: one two three

one:
	touch one
two:
	touch two
three:
	touch three

clean:
	rm -f one two three

#####################################3

all2: f1.o f2.o

#$@ is the target name
f1.o f2.o:
	echo $@
# Equivalent to:
# f1.o:
#	 echo f1.o
# f2.o:
#	 echo f2.o
