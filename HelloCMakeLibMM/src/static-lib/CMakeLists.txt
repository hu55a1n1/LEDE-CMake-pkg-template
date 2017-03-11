#
# Copyright (C) 2008 Frank Cervenka
#
# This is free software, licensed under the GNU General Public License v2.
#
PROJECT(hellocmakemm)

#SET(CMAKE_VERBOSE_MAKEFILE ON)

INCLUDE(../CMakeSources.txt)

SET(IN_OPENWRT $ENV{IN_OPENWRT})

ADD_LIBRARY(hellocmakemm STATIC ${SRC})

IF (IN_OPENWRT)
  ADD_DEFINITIONS("$ENV{TARGET_LDFLAGS}" "$ENV{TARGET_CPPFLAGS}" "$ENV{TARGET_CFLAGS}")
  INCLUDE_DIRECTORIES("$ENV{TARGET_LDFLAGS}" "$ENV{TARGET_CPPFLAGS}" "$ENV{TARGET_CFLAGS}")
  SET_TARGET_PROPERTIES(hellocmakemm PROPERTIES LINK_FLAGS "-nodefaultlibs -fno-builtin -fno-rtti -nostdinc++")
  SET_TARGET_PROPERTIES(hellocmakemm PROPERTIES COMPILE_FLAGS "-I $ENV{STAGING_DIR}/usr/include/uClibc++")
ELSE (IN_OPENWRT)
  ADD_DEFINITIONS("-Wall -g")
ENDIF(IN_OPENWRT)
