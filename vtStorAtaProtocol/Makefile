# Compiler, tools and options
CC            = gcc
CXX           = g++
CFLAGS        = -pipe -O2 -Wall -W -fPIC 
CXXFLAGS      = -pipe -std=c++14 -fpermissive -O2 -Wall -W -fPIC

# Define the directories.
RELEASE_INC_DIR                          = ../Release/vtStorAta/inc
RELEASE_VTSTOR_ATA_PROTOCOL_DIR          = $(RELEASE_INC_DIR)/vtStorAtaProtocol
RELEASE_VTSTOR_ATA_PROTOCOL_PF_LINUX_DIR = $(RELEASE_INC_DIR)/vtStorAtaProtocol/Platform/Linux
RELEASE_LIB_DIR                          = ../Release/vtStorAta/lib/

DEST_DIR                        = ../bin
OBJECTS_DIR                     = $(DEST_DIR)/vtStorAtaProtocol
EXTERN_DIR                      = ../Extern
COMMON_DIR                      = ../Common
COMMON_PF_X86X64_DIR            = ../Common/Platform/x86x64
COMMON_PF_X86X64_LINUX_DIR      = ../Common/Platform/x86x64/Linux
VTSTOR_DIR                      = ../vtStor
STORAGEUTILITY_DIR              = ../StorageUtility
STORAGEUTILITY_LINUX_DIR        = ../StorageUtility/Linux
VTSTORATAPROTOCOL_PF_LINUX_DIR  = ../vtStorAtaProtocol/Platform/Linux
 
INCPATH       = -I. -I$(EXTERN_DIR) -I$(COMMON_DIR) -I$(COMMON_PF_X86X64_DIR) -I$(COMMON_PF_X86X64_LINUX_DIR) -I$(STORAGEUTILITY_DIR) -I$(STORAGEUTILITY_LINUX_DIR) -I$(VTSTOR_DIR) -I$(DEST_DIR) \
                -I$(VTSTORATAPROTOCOL_PF_LINUX_DIR)
LINK          = g++
LFLAGS        = -Wl,-O1 -shared -Wl,-soname,libvtStorAtaProtocol.so
LIBS          = $(SUBLIBS) -L$(DEST_DIR)/ -lvtStor -ludev
DEL_FILE      = rm -f
DEL_DIR       = rmdir
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

# Files
VPATH         = SOURCES_DIR: $(VTSTORATAPROTOCOL_PF_LINUX_DIR)
SOURCES       = AtaProtocolEssense1.cpp \
		ProtocolAtaPassThrough.cpp 
OBJECTS       = $(patsubst %.cpp, $(OBJECTS_DIR)/%.o, ${SOURCES})

TARGET        = libvtStorAtaProtocol.so

all: directories compile Makefile  $(DEST_DIR)/$(TARGET)

# Create the target directory (if needed)	
directories:
	@$(CHK_DIR_EXISTS) $(OBJECTS_DIR) || $(MKDIR) $(OBJECTS_DIR)

compile: $(OBJECTS)

$(OBJECTS_DIR)/%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

# Build rules
$(DEST_DIR)/$(TARGET): $(OBJECTS) $(SUBLIBS) $(OBJCOMP)  
	-$(DEL_FILE) $(DEST_DIR)/$(TARGET)
	$(LINK) $(LFLAGS) -o $(DEST_DIR)/$(TARGET) $(OBJECTS) $(LIBS) $(OBJCOMP)

install:
	@$(CHK_DIR_EXISTS) $(RELEASE_LIB_DIR) || $(MKDIR) $(RELEASE_LIB_DIR)
	cp -f $(DEST_DIR)/$(TARGET) $(RELEASE_LIB_DIR)
	@$(CHK_DIR_EXISTS) $(RELEASE_VTSTOR_ATA_PROTOCOL_PF_LINUX_DIR) || $(MKDIR) $(RELEASE_VTSTOR_ATA_PROTOCOL_PF_LINUX_DIR)
	cp *.h $(RELEASE_VTSTOR_ATA_PROTOCOL_DIR)
	cp $(VTSTORATAPROTOCOL_PF_LINUX_DIR)/*.h $(RELEASE_VTSTOR_ATA_PROTOCOL_PF_LINUX_DIR)/

clean: 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core

.PHONY : all clean install