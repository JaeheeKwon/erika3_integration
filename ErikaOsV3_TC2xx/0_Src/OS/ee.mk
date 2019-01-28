###############################################################################
#                                                                             #
#        Copyright ? 2011 Infineon Technologies AG. All rights reserved.      #
#                                                                             #
#                                                                             #
#                              IMPORTANT NOTICE                               #
#                                                                             #
#                                                                             #
# Infineon Technologies AG (Infineon) is supplying this file for use          #
# exclusively with Infineon?s microcontroller products. This file can be      #
# freely distributed within development tools that are supporting such        #
# microcontroller products.                                                   #
#                                                                             #
# THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED #
# OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF          #
# MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.#
# INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,#
# OR CONSEQUENTIAL DAMAGES, FOR	ANY REASON WHATSOEVER.                        #
#                                                                             #
###############################################################################
# Subdir make file for ERIKA OS
# This make file is made specifically for ERIKA 3 !!!!
###############################################################################

# Function to test EEOPT, useful in conditionals and in or/and expressions
# Examples:
#   ifeq ($(call iseeopt,__MULTI__), yes)
#   ifeq ($(and $(call iseeopt,__MULTI__), $(call iseeopt,__IRQ_STACK_NEEDED__)), yes)
#   ifneq ($(call iseeopt,__MULTI__), yes)

-include 1_ToolEnv/0_Build/1_Config/Config.mk
OS_EE_RTD_GEN_VERSION:=12345
export	OS_EE_RTD_GEN_VERSION
OS_EE_OPT += OS_EE_RTD_BUILD_ENV_NATIVE
OS_EE_OPT += OS_EE_BUILD

#OS_EE_OPT += OSEE_TRICORE_ILLD

iseeopt = $(if $(filter $1,$(EEOPT)),yes,)

EE_PKG= 0_Src/OS

EE_IPATH= -I./0_Src/OS
EE_IPATH+= -I./0_Src/OS/erika
EE_IPATH+= -I./0_Src/OS/erika/inc
EE_IPATH+= -I./0_Src/OS/erika/src
EE_IPATH+= -I./0_Src/OS/out

include 0_Src/OS/erika/mk/ee_oscfg.mk
include 0_Src/OS/erika/mk/ee_dir.mk
include 0_Src/OS/erika/mk/ee_oo_cfg.mk
include 0_Src/OS/erika/mk/ee_path_helper.mk
include 0_Src/OS/erika/mk/ee_verbose.mk
include 0_Src/OS/erika/mk/ee_arch_cfg.mk
include 0_Src/OS/erika/mk/ee_std_kernel_cfg.mk
include 0_Src/OS/erika/mk/ee_utils_cfg.mk
include 0_Src/OS/erika/mk/ee_arch_compiler_gcc.mk


B_GEN_OUT_FOLDER= $(B_GEN_OUT_FOLDER_TRICORE)/$(B_GEN_TOOLCHAIN_PRIMARY_TRICORE)_Files

B_GEN_EXT_INCLUDE_PATHS+= -I0_Src/OS 
B_GEN_EXT_INCLUDE_PATHS+= -I0_Src/OS/erika/inc 
B_GEN_EXT_INCLUDE_PATHS+= -I0_Src/OS/erika/src 
B_GEN_EXT_INCLUDE_PATHS+= -I0_Src/OS/out

EE_SRCS+=0_Src/OS/out/ee_applcfg.c

EE_OBJS:= $(EE_SRCS:%.c=$(B_GEN_OUT_FOLDER)/%.o)
B_DEP_FILES_EE= $(EE_SRCS:%.c=$(B_GEN_OUT_FOLDER)/%.d)
B_GEN_CUSTOBJS_TRICORE_TC+=$(EE_OBJS)
B_GEN_CUSTOBJS_TRICORE_TC0+=$(EE_OBJS)
-include $(B_DEP_FILES_EE)

EE_VPATH += 0_Src/OS/erika/
EE_VPATH +=	0_Src/OS/erika/src

# ee_*.mk includes only file names of kernel files.
vpath %.c	$(EE_VPATH)
vpath %.s	$(EE_VPATH)
vpath %.S	$(EE_VPATH)

#@$(info $$EE_SRCS is [${EE_SRCS}])
#@$(info $$EE_VPATH is [${EE_VPATH}])
#@$(info $$OS_EE_BASE_DIR is [${OS_EE_BASE_DIR}])
#@$(info $$OS_EE_SRC_BASE_DIR is [${OS_EE_SRC_BASE_DIR}])

$(B_GEN_OUT_FOLDER)/%.o:%.c
	@mkdir -p $(@D)				
	@echo 'Building source file $(<F) for Tricore (OS Build)'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -D__TC161__ $(EE_IPATH) -c $< -o $@ -save-temps=obj -MMD
