#
# Copyright (C) 2008 Frank Cervenka
#
# This is free software, licensed under the GNU General Public License v2.
#
PROJECT(hellocmakeapp)

#SET(CMAKE_VERBOSE_MAKEFILE ON)

SET(IN_OPENWRT $ENV{IN_OPENWRT})

ADD_EXECUTABLE(hellocmakeapp Main.cpp Hello.cpp)

IF (IN_OPENWRT)
  ADD_DEFINITIONS("$ENV{TARGET_LDFLAGS}" "$ENV{TARGET_CPPFLAGS}" "$ENV{TARGET_CFLAGS}")
  INCLUDE_DIRECTORIES(/usr/include/libhellocmakemm "$ENV{TARGET_LDFLAGS}" "$ENV{TARGET_CPPFLAGS}" "$ENV{TARGET_CFLAGS}")
  TARGET_LINK_LIBRARIES(hellocmakeapp uClibc++ hellocmakemm "$ENV{TARGET_LDFLAGS}")
  SET_TARGET_PROPERTIES(hellocmakeapp PROPERTIES LINK_FLAGS "-nodefaultlibs -fno-builtin -fno-rtti -nostdinc++")
  SET_TARGET_PROPERTIES(hellocmakeapp PROPERTIES COMPILE_FLAGS "-I $ENV{STAGING_DIR}/usr/include/uClibc++")
ELSE (IN_OPENWRT)
  ADD_DEFINITIONS("-Wall -g")
  INCLUDE_DIRECTORIES(/usr/local/include/libhellocmakemm)
  TARGET_LINK_LIBRARIES(hellocmakeapp hellocmakemm)
  INSTALL(PROGRAMS hellocmakeapp DESTINATION /usr/local/bin)
  ADD_CUSTOM_TARGET(uninstall
  COMMAND "rm" -f "/usr/local/bin/hellocmakeapp"
  )
ENDIF(IN_OPENWRT)
