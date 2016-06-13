# Copyright 2001-2007 The MathWorks, Inc.
#
# File    : Simplest_With_For_Iterator.mk   $Revision: 1.23.4.28 $
# $Date: 2009/02/23 16:22:26 $
# Abstract:
#	Real-Time Workshop template makefile for building
#	stand-alone embedded real-time version of Simulink model using
#	generated C code Freescale MPC5xx

MAKECMD         = "%MATLAB%\bin\win32\gmake.exe"
SHELL           = cmd
HOST            = PC
BUILD           = yes
SYS_TARGET_FILE = mpc555rt.tlc
BUILD_SUCCESS   = Completed MPC5xx make phase
MAKEFILE_FILESEP= /			


MODEL                   = Simplest_With_For_Iterator
MODULES                 = Simplest_With_For_Iterator_data.c mpc555_main.c 
MAKEFILE                = Simplest_With_For_Iterator.mk
MATLAB_ROOT             = $(subst \,/,C:/Program Files/MATLAB/R2009b)
ALT_MATLAB_ROOT         = $(subst \,/,C:/PROGRA~1/MATLAB/R2009b)
S_FUNCTIONS             = 
S_FUNCTIONS_LIB         = 
NUMST                   = 1
NCSTATES                = 0
COMPUTER                = PCWIN
BUILDARGS               =  GENERATE_REPORT=0 PORTABLE_WORDSIZES=0 GENERATE_ASAP2=0 TMW_EXTMODE_TESTING=0 MPC555_OPTIMIZATION_SWITCH="speed" EXECUTION_PROFILING_ENABLED=0 EXECUTION_PROFILING_NUM_SAMPLES=500 RELATIVE_PATH_TO_ANCHOR=..
MULTITASKING            = 0
INTEGER_CODE            = 0
MAT_FILE                = 0
ONESTEPFCN              = 1
TERMFCN                 = 0
B_ERTSFCN               = 0
MEXEXT                  = mexw32
EXT_MODE                = 0
EXTMODE_TRANSPORT       = 0
EXTMODE_STATIC          = 0
EXTMODE_STATIC_SIZE     = 1000000
MULTI_INSTANCE_CODE     = 0
STATIC_RTWLIB           = 1
BASE_RATE_MAX_OVERRUNS  = 5
SUB_RATE_MAX_OVERRUNS   = 0

MODELREFS               = 
MODELLIB                = Simplest_With_For_Iteratorlib.a
MODELREF_LINK_LIBS      = 
MODELREF_INC_PATH       = 
MODELREF_TARGET_TYPE    = NONE

SHARED_BIN_DIR          = $(subst \,/,)
SHARED_LIB              = $(subst \,/,)
SHARED_SRC              = $(subst \,/,)
SHARED_SRC_DIR          = $(subst \,/,)

ifneq ("$(MATLAB_ROOT)","$(ALT_MATLAB_ROOT)")
MATLAB_ROOT = $(ALT_MATLAB_ROOT)
endif
ifneq ("$(MATLAB_BIN)","$(ALT_MATLAB_BIN)")
MATLAB_BIN = $(ALT_MATLAB_BIN)
endif

#-----------------------------------------------------
# Include the make variables defined from TLC file
#-----------------------------------------------------
include $(MODEL)_makevars.mk

include $(MATLAB_ROOT)/toolbox/rtw/targets/mpc555dk/rt_makevars.mk

#-------------------------------- C Flags --------------------------------------
PROFILE_SRCS = profile.c
ifeq ($(EXECUTION_PROFILING_ENABLED),1)
   PROFILING_OPTS = -DPROFILING_ENABLED  -DPROFILING_NUM_SAMPLES=$(EXECUTION_PROFILING_NUM_SAMPLES)
endif
#----------------------------- External mode -----------------------------------
# Uncomment -DVERBOSE to have information printed to stdout (or specify
# OPTS=-DVERBOSE).
ifeq ($(EXT_MODE),1)
   $(error It is not possible to build the model with external mode enabled. \
           External mode is supported on this target using the ASAP2 interface \
           and the CAN Calibration Protocol (CCP) block. If external mode is \
           required the model can be configured using the External Mode Switch \
           Configuration block which can be found in the Utilities sub-library \
           of the Target driver library. To configure the model for a build \
           double click on the block and select 'Building an executable'. \
           Once the build is complete double click on the block and select \
           'External Mode' to configure the model for external mode execution.)
endif

# Determine if we are generating an s-function
SFCN = 0
ifeq ($(GEN_MDLREF_SFCN),1)
  SFCN = 1
endif
ifeq ($(B_ERTSFCN),1)
  SFCN = 1
endif
#------------------------------ Include Path -----------------------------------

MATLAB_INCLUDES = \
	-I$(MATLAB_ROOT)/rtw/c/ert \
	-I$(MATLAB_ROOT)/extern/include \
	-I$(MATLAB_ROOT)/simulink/include \
	-I$(MATLAB_ROOT)/rtw/c/src \
	-I$(MATLAB_ROOT)/toolbox/rtw/targets/common/profile/execution

# Additional includes 
ADD_INCLUDES = \
	-IC:/DOCUME~1/AUTOPI~1/Desktop/-_DEMO~1/Simplest_With_For_Iterator_mpc555rt \
	-IC:/DOCUME~1/AUTOPI~1/Desktop/-_DEMO~1 \
	-IC:/DOCUME~1/AUTOPI~1/Desktop/-_DEMO~1/TECH_SUPPORT \
	-I$(MATLAB_ROOT)/toolbox/shared/can/src/scanutil \
	-I$(MATLAB_ROOT)/toolbox/rtw/targets/mpc555dk/drivers/src/libsrc/standard/include \
	-I$(MATLAB_ROOT)/toolbox/rtw/targets/mpc555dk/rt/blockset/tlc_c \


SHARED_INCLUDES = 
ifneq ($(SHARED_SRC_DIR),)
SHARED_INCLUDES = -I$(SHARED_SRC_DIR)
endif

INCLUDES += -I. -I.. $(MATLAB_INCLUDES) $(ADD_INCLUDES) $(USER_INCLUDES) \
	$(INSTRUMENT_INCLUDES) $(SHARED_INCLUDES) $(MODELREF_INC_PATH) \
        -I$(RELATIVE_PATH_TO_ANCHOR)


#-------------------------------- C Flags --------------------------------------

#####################################################################
# Select between RAM and FLASH targets
#####################################################################

# Optimization Options
MPC555_OPTIMIZATION_FLAGS := $(OPT_OPTS)
MPC555_DEBUG_FLAGS := $(DEBUG_OPTS)

ifeq ($(MODELREF_TARGET_TYPE), NONE)
 # Top-level model for RTW
	ifeq (FLASH,RAM)
   MPC555_COMPONENT=external_ram
   PRODUCT_SUFFIX=_ram.s19
 else
   MPC555_COMPONENT=internal_flash
   PRODUCT_SUFFIX=_flash.s19
 endif
else
 # sub-model for RTW
 # no target memory model
 MPC555_COMPONENT=mpc555_build_rules
endif

.PHONY : default
default : all 

include $(MPC555DK_ROOT)/drivers/make_plugins/component_manager.mk

# General User Options
OPTS =

# Compiler options, etc: 
CC_OPTS = $(OPTS) $(ANSI_OPTS) $(PROFILING_OPTS)

CPP_REQ_DEFINES = -DMODEL=$(MODEL) -DNUMST=$(NUMST) \
		  -DUNIX -DMT=$(MULTITASKING) -DNCSTATES=$(NCSTATES) \
		  -DMAT_FILE=$(MAT_FILE) -DINTEGER_CODE=$(INTEGER_CODE) \
		  -DONESTEPFCN=$(ONESTEPFCN) -DTERMFCN=$(TERMFCN) \
		  -DMULTI_INSTANCE_CODE=$(MULTI_INSTANCE_CODE)\
		  -DBASE_RATE_MAX_OVERRUNS=$(BASE_RATE_MAX_OVERRUNS)\
		  -DSUB_RATE_MAX_OVERRUNS=$(SUB_RATE_MAX_OVERRUNS)

# The MPC5xx does not require STDIO
# CPP_REQ_DEFINES += -DHAVESTDIO 

CFLAGS += $(CC_OPTS) $(CPP_REQ_DEFINES) 

LDFLAGS +=

#-------------------------- Additional Libraries ------------------------------
# Expand any possibly precompiled libraries - eg. custom lib with rtwmakecfg.m
#
# We handle precompiled libraries specially depending on the
# static rtwlib option in the rtwoptions gui. 


# These libraries will be built in the build directory. There
# are no precompiled sources. These library types can be 
# triggered by setting the 
# 	Precompile flag = 0
# in the rtwmakecfg.m files 

LIBS += $(S_FUNCTIONS_LIB) $(INSTRUMENT_LIBS) $(SHARED_LIB_TARGET)

#----------------------------- Source Files ------------------------------------

SRCS  = $(MODULES) $(S_FUNCTIONS) 

ifeq ($(MODELREF_TARGET_TYPE), NONE)
   # Top-level model for RTW
   PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/$(MODEL)$(PRODUCT_SUFFIX)
   define BIN_SETTING
      $(build-srec-file)
   endef
   BUILD_PRODUCT_TYPE = "executable"
   SRCS += $(MODEL).c $(EXT_SRC) $(PROFILE_SRCS)
else
   # sub-model for RTW
   PRODUCT = $(MODELLIB)
   BUILD_PRODUCT_TYPE = "library"
endif

# wildcard expand shared src files
SHARED_SRC := $(wildcard $(SHARED_SRC))
# derive object names
SHARED_OBJECTS = $(addsuffix .o, $(basename $(notdir $(SHARED_SRC))))

USER_OBJECTS       = $(addsuffix .o, $(basename $(USER_SRCS)))
LOCAL_USER_OBJECTS = $(notdir $(USER_OBJECTS))

OBJECTS      += $(addsuffix .o, $(basename $(SRCS))) $(LOCAL_USER_OBJECTS)

#--------------------------------- Rules ---------------------------------------

.PHONY : all
all : setup $(PRODUCT)

ifeq ($(MODELREF_TARGET_TYPE),NONE)
# Top-level model for RTW
LIBS += $(MODELREF_LINK_LIBS)
$(PRODUCT) : $(OBJECT_TARGETS) $(LIBS) $(LINKER_COMMAND_FILE)
	@echo "-------------------------------------"
	@echo "LIBS = $(LIBS)"
	@echo "SHARED_LIB = $(SHARED_LIB)"
	@echo "SHARED_LIB_TARGET = $(SHARED_LIB_TARGET)"
	@echo "-------------------------------------"
	$(BIN_SETTING)
	@echo \#\#\# $(BUILD_SUCCESS)
else
# sub-model for RTW
$(PRODUCT) : $(OBJECT_TARGETS) $(SHARED_OBJECT_TARGETS)
	@echo "-------------------------------------"
	@echo "OBJECT_TARGETS = $(OBJECT_TARGETS)"
	@echo "SHARED_OBJECT_TARGETS = $(SHARED_OBJECT_TARGETS)"
	@echo "-------------------------------------"
	$(RM) $(MODELLIB)
	$(LIBCMD) $(MODELLIB) $(OBJECT_TARGETS)
	@echo "### $(MODELLIB) Created"
	@echo "### Created $(BUILD_PRODUCT_TYPE): $@"
	@echo "### $(BUILD_SUCCESS)"
endif

#################################################
# Shared Utilities Library                      #
#                                               #
# SHARED_LIB_TARGET is a modified version of    #
# SHARED_LIB that adds in toolchain and variant	#
# dirs to the library path                      #
#                                               #
#################################################
$(SHARED_LIB_TARGET) : $(SHARED_OBJECT_TARGETS)
	@echo
	@echo --------------------------------------
	@echo "### Creating $@ from $(SHARED_OBJECT_TARGETS)"
	$(LIBCMD) $@ $(SHARED_OBJECT_TARGETS)
	@echo "### Created $@"
	@echo --------------------------------------
	@echo

vpath %.c  .. \
           $(MATLAB_ROOT)/rtw/c/ert \
           $(MATLAB_ROOT)/rtw/c/src \
           $(MATLAB_ROOT)/simulink/src \
           $(MPC555DK_ROOT)/mpc555dk \
           $(MPC555DK_ROOT)/../common/profile/execution \
           $(SHARED_SRC_DIR) \
	$(MATLAB_ROOT)/rtw/c/src \
	$(MATLAB_ROOT)/toolbox/rtw/targets/common/configuration/resource \
	$(MATLAB_ROOT)/toolbox/rtw/targets/mpc555dk/rt/blockset/tlc_c \


#------------------------------- Libraries -------------------------------------



#------------------------------- PRECOMP Libraries -------------------------------------



#----------------------------- Dependencies ------------------------------------

$(OBJECT_TARGETS) $(LINKER_COMMAND_FILE) : $(MAKEFILE) rtw_proj.tmw

#--------- Miscellaneous rules to purge, clean and lint (sol2 only) ------------

purge : clean
	@echo "### Deleting the generated source code for $(MODEL)"
	@$(RM) -f $(MODEL).c $(MODEL).h $(MODEL)_types.h $(MODEL)_data.c \
		$(MODEL)_private.h $(MODEL).rtw $(MODULES) rtw_proj.tmw $(MAKEFILE)

clean :
	@echo "### Deleting the $(PRODUCT)"
	@$(RM) $(PRODUCT)



