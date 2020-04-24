 #
# Inc make which define build variable
 #

# Norm arch particular macro
export TGTMACRO			:=	@config
export TGTMACRO_BUILD	:=	$(BUILDIR)/config

# Norm Libraries
export TGTSHARED_PLTLIB	:=	$(BUILDIR)/$(TARGET)

export BUILDTYPE_NOLINK		:=	BUILDTYPE_NOLINK
export BUILDTYPE_PLTLIB		:=	BUILDTYPE_PLTLIB
export BUILDTYPE_BINARY		:=	BUILDTYPE_BINARY