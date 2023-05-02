
#
# RUN time:
#   setenv LD_LIBRARY_PATH $VERDI_HOME/share/NPI/lib/LINUX64:$LD_LIBRARY_PATH
#

#
# gcc compiler setup
#
CXX      = /depot/gcc-4.8.2/bin/g++
#CXX     = g++4.8.3

CXXFLAGS = -Wall -std=c++11
LD       =  $(CXX)
RM       =  rm

#
# directory setup for NPI include files and shared library (libNPI.so)
#

NOVAS_INST_DIR = /global/apps3/verdi_2015.09-SP2
NPI_PLATFORM   = LINUX64

NPI_LIB        = $(NOVAS_INST_DIR)/share/NPI/lib/$(NPI_PLATFORM)
NPI_SO         = $(NPI_LIB)/libNPI.so
NPI_L1_SO      = $(NPI_LIB)/libnpiL1.so

NPI_INC        = $(NOVAS_INST_DIR)/share/NPI/inc
NPI_L1_INC     = $(NOVAS_INST_DIR)/share/NPI/L1/C/inc

#
# program setup
#
EXE  = demo.exe
SRCS = demo.cpp
OBJS = ${SRCS:.cpp=.o}

#
# compiling and linking
#
.SUFFIXES: .o .cpp
.cpp.o :
	$(CXX) $(CXXFLAGS) -c $< -I$(NPI_INC) -I$(NPI_L1_INC)

all: $(EXE)

$(EXE): $(OBJS)
	$(LD) -o $@ $(OBJS) -L$(NPI_LIB) -lNPI -lnpiL1 -ldl -lrt -lz
	@echo make $(EXE) successful...

clean:
	rm -fr *Log $(EXE) *.o
