NAME=sems

.DEFAULT_GOAL:=all

.PHONY: all
all: modules

COREPATH=core
include Makefile.defs

subdirs = core apps tools

.PHONY: clean
clean:
	-@rm -f *.so
	-@for r in $(subdirs) doc "" ; do \
		if [ -n "$$r" ]; then \
			echo "" ; \
			echo "making $$r" ; \
			$(MAKE) -C $$r clean ; \
		fi ; \
	done

.PHONY: modules
modules:
	-@for r in $(subdirs) "" ; do \
		if [ -n "$$r" ]; then \
			echo  "" ; \
			echo  "making $$r" ; \
			$(MAKE) -C $$r all; \
		fi ; \
	done 

.PHONY: remove
remove:
	rm -f /usr/local/bin/sems
	rm -rf $(PREFIX)

.PHONY: install
install:
	-@for r in $(subdirs) "" ; do \
		if [ -n "$$r" ]; then \
			echo "" ; \
			echo "" ; \
			$(MAKE) -C $$r install; \
		fi ; \
	done
	@echo ""
	@echo ""
	if [ -f "/usr/local/bin/sems" ]; then \
    rm -f /usr/local/bin/sems; \
  fi
	ln -s $(bin-target)sems /usr/local/bin
	mkdir -p /var/local/run
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo "##########################################################################"
	@echo "####"
	@echo "#### SIP Express Media Server"
	@echo "#### INSTALL OK !"
	@echo "####"
	@echo "#### Run SEMS with "
	@echo "#### $(bin-target)sems -f $(cfg-target)sems.conf"
	@echo "####"
	@echo "#### Debug : "
	@echo "#### $(bin-target)sems -f $(cfg-target)sems.conf -E -D 3"
	@echo "####"
	@echo "##########################################################################"
	@echo ""

.PHONY: dist
dist: tar

.PHONY: tar
tar: 
	$(TAR) -C .. \
		--exclude=$(notdir $(CURDIR))/tmp \
		--exclude=core/$(notdir $(CURDIR))/tmp \
		--exclude=.svn* \
		--exclude=.git* \
		--exclude=.\#* \
		--exclude=*.[do] \
		--exclude=*.la \
		--exclude=*.lo \
		--exclude=*.so \
		--exclude=*.il \
		--exclude=*.gz \
		--exclude=*.bz2 \
		--exclude=*.tar \
		--exclude=*~ \
		-cf - $(notdir $(CURDIR)) | \
			(mkdir -p tmp/_tar1; mkdir -p tmp/_tar2 ; \
			    cd tmp/_tar1; $(TAR) -xf - ) && \
			    mv tmp/_tar1/$(notdir $(CURDIR)) \
			       tmp/_tar2/"$(NAME)-$(RELEASE)" && \
			    (cd tmp/_tar2 && $(TAR) \
			                    -zcf ../../"$(NAME)-$(RELEASE)".tar.gz \
			                               "$(NAME)-$(RELEASE)" ) ; \
			    rm -rf tmp

.PHONY: doc
doc:
	make -C doc/ doc

.PHONY: fulldoc
fulldoc:
	make -C doc/ fulldoc
