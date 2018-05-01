########################################################################
# Copyright (c) 1988-2018 $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: texta.pri
#
# Author: $author$
#   Date: 5/1/2018
#
# Os QtCreator .pri file for texta
########################################################################
UNAME = $$system(uname)

contains(UNAME,Darwin) {
TEXTA_OS = macosx
} else {
TEXTA_OS = linux
}

#CONFIG += c++11
#CONFIG += c++0x

########################################################################
# rostra
ROSTRA_THIRDPARTY_PKG_MAKE_BLD = $${ROSTRA_THIRDPARTY_PKG}/build/$${TEXTA_OS}/$${BUILD_CONFIG}
ROSTRA_THIRDPARTY_PRJ_MAKE_BLD = $${ROSTRA_THIRDPARTY_PRJ}/build/$${TEXTA_OS}/$${BUILD_CONFIG}
ROSTRA_THIRDPARTY_PKG_BLD = $${ROSTRA_THIRDPARTY_PKG}/build/$${TEXTA_OS}/QtCreator/$${BUILD_CONFIG}
ROSTRA_THIRDPARTY_PRJ_BLD = $${ROSTRA_THIRDPARTY_PRJ}/build/$${TEXTA_OS}/QtCreator/$${BUILD_CONFIG}
ROSTRA_PKG_BLD = $${OTHER_BLD}/$${ROSTRA_PKG}/build/$${TEXTA_OS}/QtCreator/$${BUILD_CONFIG}
ROSTRA_PRJ_BLD = $${OTHER_BLD}/$${ROSTRA_PRJ}/build/$${TEXTA_OS}/QtCreator/$${BUILD_CONFIG}
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PKG_MAKE_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PKG_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PRJ_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_PKG_BLD}/lib
ROSTRA_LIB = $${ROSTRA_PRJ_BLD}/lib
#ROSTRA_LIB = $${TEXTA_LIB}

# rostra LIBS
#
rostra_LIBS += \
-L$${ROSTRA_LIB}/lib$${ROSTRA_NAME} \
-l$${ROSTRA_NAME} \

########################################################################
# nadir
NADIR_THIRDPARTY_PKG_MAKE_BLD = $${NADIR_THIRDPARTY_PKG}/build/$${TEXTA_OS}/$${BUILD_CONFIG}
NADIR_THIRDPARTY_PRJ_MAKE_BLD = $${NADIR_THIRDPARTY_PRJ}/build/$${TEXTA_OS}/$${BUILD_CONFIG}
NADIR_THIRDPARTY_PKG_BLD = $${NADIR_THIRDPARTY_PKG}/build/$${TEXTA_OS}/QtCreator/$${BUILD_CONFIG}
NADIR_THIRDPARTY_PRJ_BLD = $${NADIR_THIRDPARTY_PRJ}/build/$${TEXTA_OS}/QtCreator/$${BUILD_CONFIG}
NADIR_PKG_BLD = $${OTHER_BLD}/$${NADIR_PKG}/build/$${TEXTA_OS}/QtCreator/$${BUILD_CONFIG}
NADIR_PRJ_BLD = $${OTHER_BLD}/$${NADIR_PRJ}/build/$${TEXTA_OS}/QtCreator/$${BUILD_CONFIG}
#NADIR_LIB = $${NADIR_THIRDPARTY_PKG_MAKE_BLD}/lib
#NADIR_LIB = $${NADIR_THIRDPARTY_PRJ_MAKE_BLD}/lib
#NADIR_LIB = $${NADIR_THIRDPARTY_PKG_BLD}/lib
#NADIR_LIB = $${NADIR_THIRDPARTY_PRJ_BLD}/lib
#NADIR_LIB = $${NADIR_PKG_BLD}/lib
NADIR_LIB = $${NADIR_PRJ_BLD}/lib
#NADIR_LIB = $${TEXTA_LIB}

# nadir LIBS
#
nadir_LIBS += \
-L$${NADIR_LIB}/lib$${NADIR_NAME} \
-l$${NADIR_NAME} \

########################################################################
# arbora
ARBORA_THIRDPARTY_PKG_MAKE_BLD = $${ARBORA_THIRDPARTY_PKG}/build/$${TEXTA_OS}/$${BUILD_CONFIG}
ARBORA_THIRDPARTY_PRJ_MAKE_BLD = $${ARBORA_THIRDPARTY_PRJ}/build/$${TEXTA_OS}/$${BUILD_CONFIG}
ARBORA_THIRDPARTY_PKG_BLD = $${ARBORA_THIRDPARTY_PKG}/build/$${TEXTA_OS}/QtCreator/$${BUILD_CONFIG}
ARBORA_THIRDPARTY_PRJ_BLD = $${ARBORA_THIRDPARTY_PRJ}/build/$${TEXTA_OS}/QtCreator/$${BUILD_CONFIG}
ARBORA_PKG_BLD = $${OTHER_BLD}/$${ARBORA_PKG}/build/$${TEXTA_OS}/QtCreator/$${BUILD_CONFIG}
ARBORA_PRJ_BLD = $${OTHER_BLD}/$${ARBORA_PRJ}/build/$${TEXTA_OS}/QtCreator/$${BUILD_CONFIG}
#ARBORA_LIB = $${ARBORA_THIRDPARTY_PKG_MAKE_BLD}/lib
#ARBORA_LIB = $${ARBORA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#ARBORA_LIB = $${ARBORA_THIRDPARTY_PKG_BLD}/lib
#ARBORA_LIB = $${ARBORA_THIRDPARTY_PRJ_BLD}/lib
#ARBORA_LIB = $${ARBORA_PKG_BLD}/lib
ARBORA_LIB = $${ARBORA_PRJ_BLD}/lib
#ARBORA_LIB = $${TEXTA_LIB}

# arbora LIBS
#
arbora_LIBS += \
-L$${ARBORA_LIB}/lib$${ARBORA_NAME} \
-l$${ARBORA_NAME} \

########################################################################
# crono
CRONO_THIRDPARTY_PKG_MAKE_BLD = $${CRONO_THIRDPARTY_PKG}/build/$${TEXTA_OS}/$${BUILD_CONFIG}
CRONO_THIRDPARTY_PRJ_MAKE_BLD = $${CRONO_THIRDPARTY_PRJ}/build/$${TEXTA_OS}/$${BUILD_CONFIG}
CRONO_THIRDPARTY_PKG_BLD = $${CRONO_THIRDPARTY_PKG}/build/$${TEXTA_OS}/QtCreator/$${BUILD_CONFIG}
CRONO_THIRDPARTY_PRJ_BLD = $${CRONO_THIRDPARTY_PRJ}/build/$${TEXTA_OS}/QtCreator/$${BUILD_CONFIG}
CRONO_PKG_BLD = $${OTHER_BLD}/$${CRONO_PKG}/build/$${TEXTA_OS}/QtCreator/$${BUILD_CONFIG}
CRONO_PRJ_BLD = $${OTHER_BLD}/$${CRONO_PRJ}/build/$${TEXTA_OS}/QtCreator/$${BUILD_CONFIG}
#CRONO_LIB = $${CRONO_THIRDPARTY_PKG_MAKE_BLD}/lib
#CRONO_LIB = $${CRONO_THIRDPARTY_PRJ_MAKE_BLD}/lib
#CRONO_LIB = $${CRONO_THIRDPARTY_PKG_BLD}/lib
#CRONO_LIB = $${CRONO_THIRDPARTY_PRJ_BLD}/lib
#CRONO_LIB = $${CRONO_PKG_BLD}/lib
CRONO_LIB = $${CRONO_PRJ_BLD}/lib
#CRONO_LIB = $${TEXTA_LIB}

# crono LIBS
#
crono_LIBS += \
-L$${CRONO_LIB}/lib$${CRONO_NAME} \
-l$${CRONO_NAME} \

########################################################################
# fila
FILA_THIRDPARTY_PKG_MAKE_BLD = $${FILA_THIRDPARTY_PKG}/build/$${TEXTA_OS}/$${BUILD_CONFIG}
FILA_THIRDPARTY_PRJ_MAKE_BLD = $${FILA_THIRDPARTY_PRJ}/build/$${TEXTA_OS}/$${BUILD_CONFIG}
FILA_THIRDPARTY_PKG_BLD = $${FILA_THIRDPARTY_PKG}/build/$${TEXTA_OS}/QtCreator/$${BUILD_CONFIG}
FILA_THIRDPARTY_PRJ_BLD = $${FILA_THIRDPARTY_PRJ}/build/$${TEXTA_OS}/QtCreator/$${BUILD_CONFIG}
FILA_PKG_BLD = $${OTHER_BLD}/$${FILA_PKG}/build/$${TEXTA_OS}/QtCreator/$${BUILD_CONFIG}
FILA_PRJ_BLD = $${OTHER_BLD}/$${FILA_PRJ}/build/$${TEXTA_OS}/QtCreator/$${BUILD_CONFIG}
#FILA_LIB = $${FILA_THIRDPARTY_PKG_MAKE_BLD}/lib
#FILA_LIB = $${FILA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#FILA_LIB = $${FILA_THIRDPARTY_PKG_BLD}/lib
#FILA_LIB = $${FILA_THIRDPARTY_PRJ_BLD}/lib
#FILA_LIB = $${FILA_PKG_BLD}/lib
FILA_LIB = $${FILA_PRJ_BLD}/lib
#FILA_LIB = $${TEXTA_LIB}

# fila LIBS
#
fila_LIBS += \
-L$${FILA_LIB}/lib$${FILA_NAME} \
-l$${FILA_NAME} \

########################################################################
# archa
ARCHA_THIRDPARTY_PKG_MAKE_BLD = $${ARCHA_THIRDPARTY_PKG}/build/$${TEXTA_OS}/$${BUILD_CONFIG}
ARCHA_THIRDPARTY_PRJ_MAKE_BLD = $${ARCHA_THIRDPARTY_PRJ}/build/$${TEXTA_OS}/$${BUILD_CONFIG}
ARCHA_THIRDPARTY_PKG_BLD = $${ARCHA_THIRDPARTY_PKG}/build/$${TEXTA_OS}/QtCreator/$${BUILD_CONFIG}
ARCHA_THIRDPARTY_PRJ_BLD = $${ARCHA_THIRDPARTY_PRJ}/build/$${TEXTA_OS}/QtCreator/$${BUILD_CONFIG}
ARCHA_PKG_BLD = $${OTHER_BLD}/$${ARCHA_PKG}/build/$${TEXTA_OS}/QtCreator/$${BUILD_CONFIG}
ARCHA_PRJ_BLD = $${OTHER_BLD}/$${ARCHA_PRJ}/build/$${TEXTA_OS}/QtCreator/$${BUILD_CONFIG}
#ARCHA_LIB = $${ARCHA_THIRDPARTY_PKG_MAKE_BLD}/lib
#ARCHA_LIB = $${ARCHA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#ARCHA_LIB = $${ARCHA_THIRDPARTY_PKG_BLD}/lib
#ARCHA_LIB = $${ARCHA_THIRDPARTY_PRJ_BLD}/lib
#ARCHA_LIB = $${ARCHA_PKG_BLD}/lib
ARCHA_LIB = $${ARCHA_PRJ_BLD}/lib
#ARCHA_LIB = $${TEXTA_LIB}

# archa LIBS
#
archa_LIBS += \
-L$${ARCHA_LIB}/lib$${ARCHA_NAME} \
-l$${ARCHA_NAME} \

########################################################################
# texta

# texta INCLUDEPATH
#
texta_INCLUDEPATH += \

# texta DEFINES
#
texta_DEFINES += \

# texta LIBS
#
texta_LIBS += \
$${archa_LIBS} \
$${fila_LIBS} \
$${crono_LIBS} \
$${arbora_LIBS} \
$${nadir_LIBS} \
$${rostra_LIBS} \
$${build_texta_LIBS} \
-lpthread \
-ldl \

contains(TEXTA_OS,linux) {
texta_LIBS += \
-lrt
} else {
}

