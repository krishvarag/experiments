VER=1.22.3
DL_FILE=go$(VER).linux-amd64.tar.gz
all:
	@echo install GO version $(VER) from https://go.dev/dl/
	@echo ------ Single Target
	@echo make -f inst.mak VER=$(VER) INSTALL -n
	@echo ------- Multiple Targets
	@echo make -f inst.mak VER=$(VER) DLOAD -n
	@echo make -f inst.mak VER=$(VER) SET_IN_PATH -n
DLOAD:
	rm -f $(DL_FILE)
	wget https://go.dev/dl/$(DL_FILE)
	sudo tar -xzvf $(DL_FILE) -C /usr/local
	rm -f $(DL_FILE)
SET_IN_PATH:	
	echo 'export PATH=$$HOME/go/bin:/usr/local/go/bin:$$PATH' >> ~/.bash_profile
INSTALL:DLOAD SET_IN_PATH	


