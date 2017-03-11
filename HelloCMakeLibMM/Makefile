# 
# Copyright (C) 2006 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
#
# Copyright (C) 2008 Frank Cervenka
#
# This is free software, licensed under the GNU General Public License v2.
#
include $(TOPDIR)/rules.mk

PKG_NAME:=libhellocmakemm
PKG_VERSION:=0.0.1
PKG_RELEASE:=1

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/libhellocmakemm
	SECTION:=libs
	CATEGORY:=Libraries
	TITLE:=CMake OpenWrt cross compile example for shared and static libs
	DEPENDS:=+uclibcxx
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
	rm -f $(PKG_BUILD_DIR)/CMakeCache.txt
	rm -fR $(PKG_BUILD_DIR)/CMakeFiles
	rm -f $(PKG_BUILD_DIR)/Makefile ]
	rm -f $(PKG_BUILD_DIR)/cmake_install.cmake
	rm -f $(PKG_BUILD_DIR)/progress.make
	rm -f $(PKG_BUILD_DIR)/shared-lib/CMakeCache.txt
	rm -fR $(PKG_BUILD_DIR)/shared-lib/CMakeFiles
	rm -f $(PKG_BUILD_DIR)/shared-lib/Makefile ]
	rm -f $(PKG_BUILD_DIR)/shared-lib/cmake_install.cmake
	rm -f $(PKG_BUILD_DIR)/shared-lib/progress.make
	rm -f $(PKG_BUILD_DIR)/static-lib/CMakeCache.txt
	rm -fR $(PKG_BUILD_DIR)/static-lib/CMakeFiles
	rm -f $(PKG_BUILD_DIR)/static-lib/Makefile ]
	rm -f $(PKG_BUILD_DIR)/static-lib/cmake_install.cmake
	rm -f $(PKG_BUILD_DIR)/static-lib/progress.make
endef

define Build/Configure
	IN_OPENWRT=1 \
	AR="$(TOOLCHAIN_DIR)/bin/$(TARGET_CROSS)ar" \
	AS="$(TOOLCHAIN_DIR)/bin/$(TARGET_CC) -c $(TARGET_CFLAGS)" \
	LD="$(TOOLCHAIN_DIR)/bin/$(TARGET_CROSS)ld" \
	NM="$(TOOLCHAIN_DIR)/bin/$(TARGET_CROSS)nm" \
	CC="$(TOOLCHAIN_DIR)/bin/$(TARGET_CC)" \
	GCC="$(TOOLCHAIN_DIR)/bin/$(TARGET_CC)" \
	CXX="$(TOOLCHAIN_DIR)/bin/$(TARGET_CROSS)g++" \
	RANLIB="$(TOOLCHAIN_DIR)/bin/$(TARGET_CROSS)ranlib" \
	STRIP="$(TOOLCHAIN_DIR)/bin/$(TARGET_CROSS)strip" \
	OBJCOPY="$(TOOLCHAIN_DIR)/bin/$(TARGET_CROSS)objcopy" \
	OBJDUMP="$(TOOLCHAIN_DIR)/bin/$(TARGET_CROSS)objdump" \
	TARGET_CPPFLAGS="$(TARGET_CPPFLAGS)" \
	TARGET_CFLAGS="$(TARGET_CFLAGS)" \
	TARGET_LDFLAGS="$(TARGET_LDFLAGS)" \
	cmake $(PKG_BUILD_DIR)/CMakeLists.txt
endef

define Build/InstallDev
	$(INSTALL_DIR) $(STAGING_DIR)/usr/include/libhellocmakemm
	$(CP) $(PKG_BUILD_DIR)/*.hpp $(STAGING_DIR)/usr/include/libhellocmakemm/
	$(INSTALL_DIR) $(STAGING_DIR)/usr/lib
	$(CP) $(PKG_BUILD_DIR)/shared-lib/libhellocmakemm.so $(STAGING_DIR)/usr/lib/
	$(CP) $(PKG_BUILD_DIR)/static-lib/libhellocmakemm.a $(STAGING_DIR)/usr/lib/
endef

define Build/UninstallDev
	rm -rf \
	$(STAGING_DIR)/usr/include/libhellocmakemm \
	$(STAGING_DIR)/usr/lib/libhellocmakemm.so \
	$(STAGING_DIR)/usr/lib/libhellocmakemm.a
endef

define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR)
endef

define Package/libhellocmakemm/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/shared-lib/libhellocmakemm.so $(1)/usr/lib/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/static-lib/libhellocmakemm.a $(1)/usr/lib/
endef

$(eval $(call BuildPackage,libhellocmakemm))
