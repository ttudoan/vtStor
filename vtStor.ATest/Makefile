# Compiler, tools and options

CC            = gcc
CXX           = g++
CFLAGS        = -pipe -O2 -Wall -W 
CXXFLAGS      = -pipe -std=c++14 -fpermissive -O2 -Wall -W 

# Define the directories.
DEST_DIR                        = ../Release
OBJECTS_DIR                     = $(DEST_DIR)/vtStorATest
LIBRARY_DIR			= ../Release
HEADER_DIR                      = ../_dependency/vtStor_Release/Source
EXTERN_DIR                      = $(HEADER_DIR)/Extern
COMMON_DIR                      = $(HEADER_DIR)/Common
COMMON_PF_X86X64_DIR            = $(HEADER_DIR)/Common/Platform/x86x64
COMMON_PF_X86X64_LINUX_DIR      = $(HEADER_DIR)/Common/Platform/x86x64/Linux
VTSTOR_DIR                      = $(HEADER_DIR)/vtStor
VTSTOR_PF_LINUX_DIR             = $(HEADER_DIR)/vtStor/Platform/Linux
STORAGEUTILITY_DIR              = $(HEADER_DIR)/StorageUtility
STORAGEUTILITY_LINUX_DIR        = $(HEADER_DIR)/StorageUtility/Linux 
VTSTORATA_DIR                   = $(HEADER_DIR)/vtStorAta
VTSTORATA_PF_LINUX_DIR          = $(HEADER_DIR)/vtStorAta/Platform/Linux
VTSTORATAPROTOCOL_DIR           = $(HEADER_DIR)/vtStorAtaProtocol
VTSTORATAPROTOCOL_PF_LINUX_DIR  = $(HEADER_DIR)/vtStorAtaProtocol/Platform/Linux  
VTSTORSCSI_DIR                  = $(HEADER_DIR)/vtStorScsi 
VTSTORSCSI_PF_LINUX_DIR         = $(HEADER_DIR)/vtStorScsi/Platform/Linux  
VTSTORSCSIPROTOCOL_DIR          = $(HEADER_DIR)/vtStorScsiProtocol
VTSTORSCSIPROTOCOL_PF_LINUX_DIR = $(HEADER_DIR)/vtStorScsiProtocol/Platform/Linux 

INCPATH       = -I. -I$(EXTERN_DIR) -I$(COMMON_DIR) -I$(COMMON_PF_X86X64_DIR) -I$(COMMON_PF_X86X64_LINUX_DIR) -I$(STORAGEUTILITY_DIR) -I$(STORAGEUTILITY_LINUX_DIR) -I$(VTSTOR_DIR) -I$(VTSTOR_PF_LINUX_DIR) -I$(DEST_DIR) \
                -I$(VTSTORATA_DIR) -I$(VTSTORATA_PF_LINUX_DIR) -I$(VTSTORATAPROTOCOL_DIR) -I$(VTSTORATAPROTOCOL_PF_LINUX_DIR) -I$(VTSTORSCSI_DIR) -I$(VTSTORSCSI_PF_LINUX_DIR) -I$(VTSTORSCSIPROTOCOL_DIR) -I$(VTSTORSCSIPROTOCOL_PF_LINUX_DIR)
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS) -L$(LIBRARY_DIR)/ -lStorageUtility -lvtStor -lvtStorAtaProtocol -lvtStorAta -lvtStorScsiProtocol -lvtStorScsi -ludev
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

# Files
VPATH         = SOURCES_DIR: .
SOURCES       = main.cpp
OBJECTS       = $(patsubst %.cpp, $(OBJECTS_DIR)/%.o, ${SOURCES})

TARGET        = $(DEST_DIR)/vtStor.ATest

all: directories compile Makefile  $(TARGET)

# Create the target directory (if needed)	
directories:
	@$(CHK_DIR_EXISTS) $(OBJECTS_DIR) || $(MKDIR) $(OBJECTS_DIR)
	
compile: $(OBJECTS)

$(OBJECTS_DIR)/%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

# Build rules
$(TARGET): $(LIBRARY_DIR)/libStorageUtility.a $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)
	
clean: 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core
