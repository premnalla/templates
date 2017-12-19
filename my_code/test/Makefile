include ../../../../../../object/env.mk


TARGET_1 = test_app


CXX_BINNAMES = $(TARGET_1)


$(TARGET_1)_OBJS = \
	main.o \
#


$(TARGET_1)_INSTDIR = $(AXSBIN_INSTDIR)


ifdef DEBUG
CXXFLAGS += -g
endif


ifdef SUNOS
CXXFLAGS += -D_REENTRANT
endif


ifdef LYNX
CXXFLAGS += -D_POSIX_C_SOURCE=199506L -D__LYNXOS__
endif


INCLUDES += \
-I$(VOBROOT)/nm/common/cpp/lib/libaxcppgen/include \
#


ALL_TARGET_LIBS = \
$(VOBROOT)/nm/common/cpp/lib/libaxcppgen/libaxcppgen \
#

$(TARGET_1)_LIBS = $(ALL_TARGET_LIBS)


ifdef LYNX
LDFLAGS += -L$(ENV_PREFIX)/lib/thread -lbsd -mthreads -lm \
#
endif


ifdef SUNOS
LDFLAGS += -lxnet -lresolv -lrt -lsocket -lpthread -lm -lc \
#
endif

include ../../../../../../object/master.mk
