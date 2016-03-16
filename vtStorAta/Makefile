# Compiler, tools and options
CC            = gcc
CXX           = g++
CFLAGS        = -pipe -O2 -Wall -W -fPIC 
CXXFLAGS      = -pipe -std=c++14 -fpermissive -O2 -Wall -W -fPIC 

# Define the directories.
RELEASE_INC_DIR                 = ../Release/vtStorAta/inc
RELEASE_VTSTOR_ATA_DIR          = $(RELEASE_INC_DIR)/vtStorAta
RELEASE_LIB_DIR                 = ../Release/vtStorAta/lib/

DEST_DIR                        = ../bin
OBJECTS_DIR                     = $(DEST_DIR)/vtStorAta
EXTERN_DIR                      = ../Extern
COMMON_DIR                      = ../Common
COMMON_PF_X86X64_DIR            = ../Common/Platform/x86x64
COMMON_PF_X86X64_LINUX_DIR      = ../Common/Platform/x86x64/Linux
VTSTOR_DIR                      = ../vtStor
STORAGEUTILITY_DIR              = ../StorageUtility
STORAGEUTILITY_LINUX_DIR        = ../StorageUtility/Linux
VTSTORATAPROTOCOL_DIR           = ../vtStorAtaProtocol
VTSTORATAPROTOCOL_PF_LINUX_DIR  = ../vtStorAtaProtocol/Platform/Linux

INCPATH       = -I. -I$(EXTERN_DIR) -I$(COMMON_DIR) -I$(COMMON_PF_X86X64_DIR) -I$(COMMON_PF_X86X64_LINUX_DIR) -I$(STORAGEUTILITY_DIR) -I$(STORAGEUTILITY_LINUX_DIR) -I$(VTSTOR_DIR) -I$(DEST_DIR) \
                -I$(VTSTORATAPROTOCOL_DIR) -I$(VTSTORATAPROTOCOL_PF_LINUX_DIR) 
LINK          = g++
LFLAGS        = -Wl,-O1 -shared -Wl,-soname,libvtStorAta.so
LIBS          = $(SUBLIBS) -L$(DEST_DIR)/ -lvtStor -lvtStorAtaProtocol -ludev 
DEL_FILE      = rm -f
DEL_DIR       = rmdir
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

# Files
VPATH         = SOURCES_DIR: .
SOURCES       = DriveEnumeratorAta.cpp \
		DriveAta.cpp \
		CommandHandlerAta.cpp \
		CommandDescriptorAta.cpp \
		AtaCommandExtensions.cpp \
		TrimBufferFormatter.cpp 

OBJECTS       = $(patsubst %.cpp, $(OBJECTS_DIR)/%.o, ${SOURCES})
        
TARGET        = libvtStorAta.so

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
	@$(CHK_DIR_EXISTS) $(RELEASE_VTSTOR_ATA_DIR) || $(MKDIR) $(RELEASE_VTSTOR_ATA_DIR)
	cp *.h $(RELEASE_VTSTOR_ATA_DIR)

clean: 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core
	$(CCADMIN)
	-$(DEL_DIR) $(OBJECTS_DIR)

.PHONY : all clean install