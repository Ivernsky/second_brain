#$(function args)

#string function: subst,patsubst
files= main.cpp     block.cpp main.o block.o 
result1 = $(subst .cpp,.o,$(files))
result2 = $(patsubst %.cpp,%.h,$(files))
result3 = $(strip $(files))#strip the 
result4 = $(findstring cpp,$(files))
result5 = $(filter %.cpp,$(files))
result6 = $(filter-out %.o,$(files))
result7 = $(sort $(files))
result8 = $(word 3,$(files))
result9 = $(wordlist 2,3,$(files))
#words
#firstwords
#lastwords

file_fun = $(dir $files)
#suffix
#basename
#addsuffix

.PHONY:all

all:test1 test2 test3 test4 test5 test6 test7 test8 test9 

test1:
	@echo test1: $(result1)

test2:
	@echo test2: $(result2)

test3:
	@echo test3: $(result3)

test4:
	@echo test4: $(result4)

test5:
	@echo test5: $(result5)

test6:
	@echo test6: $(result6)
test7:
	@echo test7: $(result7)
test8:
	@echo test8: $(result8)
test9:
	@echo test9: $(result9)

test10:
	@echo test10: $(file_fun)
