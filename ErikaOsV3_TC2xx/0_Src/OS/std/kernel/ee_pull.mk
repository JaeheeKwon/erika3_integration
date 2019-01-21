# ###*B*###
# Erika Enterprise, version 3
# 
# Copyright (C) 2017 - 2018 Evidence s.r.l.
# 
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or (at
# your option) any later version.
# 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# General Public License, version 2, for more details.
# 
# You should have received a copy of the GNU General Public License,
# version 2, along with this program; if not, see
# < www.gnu.org/licenses/old-licenses/gpl-2.0.html >.
# 
# This program is distributed to you subject to the following
# clarifications and special exceptions to the GNU General Public
# License, version 2.
# 
# THIRD PARTIES' MATERIALS
# 
# Certain materials included in this library are provided by third
# parties under licenses other than the GNU General Public License. You
# may only use, copy, link to, modify and redistribute this library
# following the terms of license indicated below for third parties'
# materials.
# 
# In case you make modified versions of this library which still include
# said third parties' materials, you are obligated to grant this special
# exception.
# 
# The complete list of Third party materials allowed with ERIKA
# Enterprise version 3, together with the terms and conditions of each
# license, is present in the file THIRDPARTY.TXT in the root of the
# project.
# ###*E*###

## \file	ee_pull.mk
## \brief	Pull file for Standard Internals Module.
##
## This makefile contains the list of files to be pulled into Erika Enterprise
## project to support Standard Internals Module.
##
## \note	Not used in FP!
##
## \author	Giuseppe Serano
## \date	2016

ifneq	($(call iseeopt, OS_EE_2), yes)

OS_EE_PULL_MK_FILES += $(ERIKA_FILES)/pkg/std/kernel/ee_std_kernel_cfg.mk

OS_EE_PULL_SRC_FILES += $(ERIKA_FILES)/pkg/std/kernel/ee_std_change_context.h
OS_EE_PULL_SRC_FILES += $(ERIKA_FILES)/pkg/std/kernel/ee_std_change_context.c

endif	# OS_EE_2
