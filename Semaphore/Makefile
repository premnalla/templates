
include makeinclude.mk

PROGRAM = SemaphoreApp

PROGRAMS = $(PROGRAM)

INCLUDES = \
	-Iinclude

LIB_DIR = \
	-Llib

DEBUG = -g

OTHER = 

CPPFLAGS = $(INCLUDES) $(DEBUG) $(OTHER)

SRC = \
	main.cpp \
#

OBJ = $(SRC:%.cpp=%.o)

LDFLAGS = \
	-lpthread \
	-lposix4 \
	-lsocket \
	-lnsl \
#	-lxnet \
#	-lm \
#

all: $(PROGRAMS)

$(PROGRAM) : $(OBJ)
	@echo "linking $(SRVR_PROGRAM) ..."
	$(CCC) -o $(PROGRAM) $(CPPFLAGS) $(LDFLAGS) $(OBJ)

.cpp.o :
	$(CCC) $(CPPFLAGS) -c -o $(@:%.c=%.o) $<

clean:
	rm *.o

