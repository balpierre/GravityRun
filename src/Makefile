.PHONY: all

all:	subbuild	hostbuilder

subbuild:
	@make -C graphic   --no-print-directory -s
	@make -C physic    --no-print-directory -s
	@make -C interface --no-print-directory -s

BUILDHEADER			=	$(BINARY)

BUILDTYPE			=	$(BUILDTYPE_BINARY)

BUILDTARGET			=	$(PROJECT_PATH)/$(BINARY)

TARGET_SOURCE_DIR	= .

include $(MKHELPER_DIR)/builder/builder_host.mk