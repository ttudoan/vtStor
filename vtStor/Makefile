# Compiler, tools and options
CC            = gcc
CXX           = g++
CFLAGS        = -pipe -O2 -Wall -W -fPIC 
CXXFLAGS      = -pipe -std=c++14 -fpermissive -O2 -Wall -W -fPIC

# Define the directories.
RELEASE_INC_DIR                         = ../Release/vtStor/inc
RELEASE_EXTERN_DIR                      = $(RELEASE_INC_DIR)/Extern
RELEASE_COMMON_DIR                      = $(RELEASE_INC_DIR)/Common
RELEASE_COMMON_PF_X86X64_DIR            = $(RELEASE_INC_DIR)/Common/Platform/x86x64
RELEASE_COMMON_PF_X86X64_LINUX_DIR      = $(RELEASE_INC_DIR)/Common/Platform/x86x64/Linux
RELEASE_VTSTOR_DIR                      = $(RELEASE_INC_DIR)/vtStor
RELEASE_STORAGEUTILITY_DIR              = $(RELEASE_INC_DIR)/StorageUtility
RELEASE_STORAGEUTILITY_LINUX_DIR        = $(RELEASE_INC_DIR)/StorageUtility/Linux
RELEASE_LIB_DIR                         = ../Release/vtStor/lib/

DEST_DIR                        = ../bin
OBJECTS_DIR                     = $(DEST_DIR)/vtStor
EXTERN_DIR                      = ../Extern
COMMON_DIR                      = ../Common
COMMON_PF_X86X64_DIR            = ../Common/Platform/x86x64
COMMON_PF_X86X64_LINUX_DIR      = ../Common/Platform/x86x64/Linux
STORAGEUTILITY_DIR              = ../StorageUtility
STORAGEUTILITY_LINUX_DIR        = ../StorageUtility/Linux
GENERATEFILES_DIR               = ../GenerateFiles
 
INCPATH       = -I. -I$(EXTERN_DIR) -I$(COMMON_DIR) -I$(COMMON_PF_X86X64_DIR) -I$(COMMON_PF_X86X64_LINUX_DIR) -I$(STORAGEUTILITY_DIR) -I$(STORAGEUTILITY_LINUX_DIR) -I$(DEST_DIR)
LINK          = g++
LFLAGS        = -Wl,-O1 -shared -Wl,-soname,libvtStor.so
LIBS          = $(SUBLIBS) -ludev
DEL_FILE      = rm -f
DEL_DIR       = rmdir
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

# Files
VPATH         = SOURCES_DIR: . $(STORAGEUTILITY_DIR) $(STORAGEUTILITY_LINUX_DIR)
SOURCES       = ProtocolEssense.cpp \
    DriveManager.cpp \
    Drive.cpp \
    CommandDescriptor.cpp \
    BufferFormatter.cpp \
    Buffer.cpp \
    Scsi.cpp \
    Ata.cpp \
    Device.cpp \
    StorageUtility.cpp
OBJECTS       = $(patsubst %.cpp, $(OBJECTS_DIR)/%.o, ${SOURCES})

TARGET        = libvtStor.so

all: generateFiles directories compile Makefile  $(DEST_DIR)/$(TARGET) 

generateFiles:
	# output file                                                                           Templated file                                          xml file
	python $(GENERATEFILES_DIR)/GenerateFiles.py $(COMMON_DIR)/ErrorCodes.h                 $(GENERATEFILES_DIR)/ErrorCodesTemplate.h               $(GENERATEFILES_DIR)/ErrorCodes.xml
	python $(GENERATEFILES_DIR)/GenerateFiles.py $(COMMON_DIR)/ScanForHardwareChanges.h     $(GENERATEFILES_DIR)/ScanForHardwareChangesTemplate.h 	$(GENERATEFILES_DIR)/ScanForHardwareChanges.xml
	python $(GENERATEFILES_DIR)/GenerateFiles.py $(COMMON_DIR)/BusType.h                    $(GENERATEFILES_DIR)/BusTypeTemplate.h                  $(GENERATEFILES_DIR)/BusType.xml
	python $(GENERATEFILES_DIR)/GenerateFiles.py $(COMMON_DIR)/DeviceDataType.h             $(GENERATEFILES_DIR)/DeviceDataTypeTemplate.h           $(GENERATEFILES_DIR)/DeviceDataType.xml

# Create the target directory (if needed)	
directories:
	@$(CHK_DIR_EXISTS) $(DEST_DIR) || $(MKDIR) $(DEST_DIR)
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
	@$(CHK_DIR_EXISTS) $(RELEASE_EXTERN_DIR) || $(MKDIR) $(RELEASE_EXTERN_DIR)
	@$(CHK_DIR_EXISTS) $(RELEASE_COMMON_PF_X86X64_LINUX_DIR) || $(MKDIR) $(RELEASE_COMMON_PF_X86X64_LINUX_DIR)
	@$(CHK_DIR_EXISTS) $(RELEASE_VTSTOR_DIR) || $(MKDIR) $(RELEASE_VTSTOR_DIR)
	@$(CHK_DIR_EXISTS) $(RELEASE_STORAGEUTILITY_LINUX_DIR) || $(MKDIR) $(RELEASE_STORAGEUTILITY_LINUX_DIR)
	cp $(EXTERN_DIR)/*.h $(RELEASE_EXTERN_DIR)
	cp $(COMMON_DIR)/*.h $(RELEASE_COMMON_DIR)
	cp $(COMMON_PF_X86X64_DIR)/*.h $(RELEASE_COMMON_PF_X86X64_DIR)
	cp $(COMMON_PF_X86X64_LINUX_DIR)/*.h $(RELEASE_COMMON_PF_X86X64_LINUX_DIR)
	cp *.h $(RELEASE_VTSTOR_DIR)
	cp $(STORAGEUTILITY_DIR)/*.h $(RELEASE_STORAGEUTILITY_DIR)
	cp $(STORAGEUTILITY_LINUX_DIR)/*.h $(RELEASE_STORAGEUTILITY_LINUX_DIR)

clean: 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core
	$(CCADMIN)
	-$(DEL_DIR) $(OBJECTS_DIR)

.PHONY : all clean install