#OS = linux
.PHONY:all

var1= 200
var2= 200
all:
	@echo print all

ifdef var1
	$(info var1 def $(var1))
else ifdef var2
	$(info var2 def ${var2})
else 
	$(info var1 or var2 not def)
endif

ifeq (${var1},${var2})
	$(info var1 eq var2)
else
	$(info var1 not eq var2)
endif
