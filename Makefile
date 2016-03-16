# Directory of projects
vtStor_DIR              = ./vtStor
vtStorAtaProtocol_DIR   = ./vtStorAtaProtocol
vtStorScsiProtocol_DIR  = ./vtStorScsiProtocol
vtStorAta_DIR           = ./vtStorAta
vtStorScsi_DIR          = ./vtStorScsi

# Project names
vtStor                  = vtStor
vtStorAtaProtocol       = vtStorAtaProtocol
vtStorScsiProtocol      = vtStorScsiProtocol
vtStorAta               = vtStorAta
vtStorScsi              = vtStorScsi

ALL_PROJECTS = $(vtStor) $(vtStorAtaProtocol) $(vtStorScsiProtocol) $(vtStorAta) $(vtStorScsi)

# Build all projects
all: $(ALL_PROJECTS)

$(vtStor):
	cd $(vtStor_DIR); make all
        
$(vtStorAtaProtocol): $(vtStor)
	cd $(vtStorAtaProtocol_DIR); make all
        
$(vtStorScsiProtocol): $(vtStor)
	cd $(vtStorScsiProtocol_DIR); make all
        
$(vtStorAta): $(vtStor) $(vtStorAtaProtocol)
	cd $(vtStorAta_DIR); make all
        
$(vtStorScsi): $(vtStor) $(vtStorScsiProtocol)
	cd $(vtStorScsi_DIR); make all
        
install: 
	cd $(vtStor_DIR); make install
	cd $(vtStorAtaProtocol_DIR); make install
	cd $(vtStorScsiProtocol_DIR); make install
	cd $(vtStorAta_DIR); make install
	cd $(vtStorScsi_DIR); make install
	
clean: 
	cd $(vtStor_DIR); make clean
	cd $(vtStorAtaProtocol_DIR); make clean
	cd $(vtStorScsiProtocol_DIR); make clean
	cd $(vtStorAta_DIR); make clean
	cd $(vtStorScsi_DIR); make clean

.PHONY: all clean install $(ALL_PROJECTS)