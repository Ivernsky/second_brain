
#
# gcc compiler setup
#
CC     =  g++
CFLAGS = -Wall -g
LD     =  $(CC)
RM     =  rm

#
# directory setup for NPI include files and shared library (libNPI.so)
#

#NOVAS_INST_DIR = /slowfs/sp_qa/mfg/prod/Verdi3_2012/verdi3_2012.07
#NPI_PLATFORM   = LINUX64_GNU_346

NPI_INC        = $(NOVAS_INST_DIR)/share/NPI/inc
NPI_LIB        = $(NOVAS_INST_DIR)/share/NPI/lib/$(NPI_PLATFORM)
NPI_SO         = $(NPI_LIB)/libNPI.so

NPI_L1_DIR     = $(NOVAS_INST_DIR)/share/NPI/L1/C
NPI_L1_INC     = $(NPI_L1_DIR)/inc
NPI_L1_SRC     = $(NPI_L1_DIR)/src
NPI_L1_SO      = $(NPI_LIB)/libnpiL1.so

#
# program setup
#
SHLIB_NAME = demo
SRCS       = demo.cpp 
OBJS       = ${SRCS:.cpp=.o}

#
# compiling and linking
#
.SUFFIXES: .o .cpp
.cpp.o :
	$(CC) $(CFLAGS) -c -fPIC $< -I$(NPI_INC) -I$(NPI_L1_INC)

all: $(OBJS)
	$(LD) -shared -o $(SHLIB_NAME).so $(OBJS) 
	@echo make $(SHLIB_NAME) successful...

clean:
	-$(RM) -f $(SHLIB_NAME).so $(OBJS)
