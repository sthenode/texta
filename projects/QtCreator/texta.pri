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
# QtCreator .pri file for texta
########################################################################

OTHER_PKG = ../../../../../../..
OTHER_PRJ = ../../../../../..
OTHER_BLD = ..

THIRDPARTY_NAME = thirdparty
THIRDPARTY_PKG = $${OTHER_PKG}/$${THIRDPARTY_NAME}
THIRDPARTY_PRJ = $${OTHER_PRJ}/$${THIRDPARTY_NAME}
THIRDPARTY_SRC = $${OTHER_PRJ}/src/$${THIRDPARTY_NAME}

########################################################################
# rostra
ROSTRA_VERSION_MAJOR = 0
ROSTRA_VERSION_MINOR = 0
ROSTRA_VERSION_RELEASE = 0
ROSTRA_VERSION = $${ROSTRA_VERSION_MAJOR}.$${ROSTRA_VERSION_MINOR}.$${ROSTRA_VERSION_RELEASE}
ROSTRA_NAME = rostra
ROSTRA_GROUP = $${ROSTRA_NAME}
ROSTRA_SOURCE = src
ROSTRA_DIR = $${ROSTRA_GROUP}/$${ROSTRA_NAME}-$${ROSTRA_VERSION}
ROSTRA_PKG_DIR = $${ROSTRA_NAME}
ROSTRA_HOME_BUILD = $${HOME}/build/$${ROSTRA_NAME}
ROSTRA_HOME_BUILD_INCLUDE = $${ROSTRA_HOME_BUILD}/include
ROSTRA_HOME_BUILD_LIB = $${ROSTRA_HOME_BUILD}/lib
ROSTRA_THIRDPARTY_PKG = $${THIRDPARTY_PKG}/$${ROSTRA_DIR}
ROSTRA_THIRDPARTY_PRJ = $${THIRDPARTY_PRJ}/$${ROSTRA_DIR}
ROSTRA_THIRDPARTY_SRC = $${THIRDPARTY_SRC}/$${ROSTRA_PKG_DIR}
ROSTRA_THIRDPARTY_SRC_GROUP = $${ROSTRA_NAME}
ROSTRA_THIRDPARTY_SRC_NAME = $${ROSTRA_NAME}
ROSTRA_THIRDPARTY_SRC_DIR = $${THIRDPARTY_SRC}/$${ROSTRA_THIRDPARTY_SRC_GROUP}/$${ROSTRA_THIRDPARTY_SRC_NAME} 
ROSTRA_PKG = $${OTHER_PKG}/$${ROSTRA_PKG_DIR}
ROSTRA_PRJ = $${OTHER_PRJ}/$${ROSTRA_PKG_DIR}
#ROSTRA_SRC = $${ROSTRA_THIRDPARTY_SRC_DIR}
#ROSTRA_SRC = $${ROSTRA_THIRDPARTY_PKG}/$${ROSTRA_SOURCE}
#ROSTRA_SRC = $${ROSTRA_THIRDPARTY_PRJ}/$${ROSTRA_SOURCE}
#ROSTRA_SRC = $${ROSTRA_PKG}/$${ROSTRA_SOURCE}
ROSTRA_SRC = $${ROSTRA_PRJ}/$${ROSTRA_SOURCE}

# rostra INCLUDEPATH
#
#rostra_INCLUDEPATH += \
#$${ROSTRA_HOME_BUILD_INCLUDE} \

rostra_INCLUDEPATH += \
$${ROSTRA_SRC} \

# rostra DEFINES
#
rostra_DEFINES += \

########################################################################
# nadir
NADIR_VERSION_MAJOR = 0
NADIR_VERSION_MINOR = 0
NADIR_VERSION_RELEASE = 0
NADIR_VERSION = $${NADIR_VERSION_MAJOR}.$${NADIR_VERSION_MINOR}.$${NADIR_VERSION_RELEASE}
NADIR_NAME = nadir
NADIR_GROUP = $${NADIR_NAME}
NADIR_SOURCE = src
NADIR_DIR = $${NADIR_GROUP}/$${NADIR_NAME}-$${NADIR_VERSION}
NADIR_PKG_DIR = $${NADIR_NAME}
NADIR_HOME_BUILD = $${HOME}/build/$${NADIR_NAME}
NADIR_HOME_BUILD_INCLUDE = $${NADIR_HOME_BUILD}/include
NADIR_HOME_BUILD_LIB = $${NADIR_HOME_BUILD}/lib
NADIR_THIRDPARTY_PKG = $${THIRDPARTY_PKG}/$${NADIR_DIR}
NADIR_THIRDPARTY_PRJ = $${THIRDPARTY_PRJ}/$${NADIR_DIR}
NADIR_THIRDPARTY_SRC = $${THIRDPARTY_SRC}/$${NADIR_PKG_DIR}
NADIR_THIRDPARTY_SRC_GROUP = $${NADIR_NAME}
NADIR_THIRDPARTY_SRC_NAME = $${NADIR_NAME}
NADIR_THIRDPARTY_SRC_DIR = $${THIRDPARTY_SRC}/$${NADIR_THIRDPARTY_SRC_GROUP}/$${NADIR_THIRDPARTY_SRC_NAME} 
NADIR_PKG = $${OTHER_PKG}/$${NADIR_PKG_DIR}
NADIR_PRJ = $${OTHER_PRJ}/$${NADIR_PKG_DIR}
#NADIR_SRC = $${NADIR_THIRDPARTY_SRC_DIR}
#NADIR_SRC = $${NADIR_THIRDPARTY_PKG}/$${NADIR_SOURCE}
#NADIR_SRC = $${NADIR_THIRDPARTY_PRJ}/$${NADIR_SOURCE}
#NADIR_SRC = $${NADIR_PKG}/$${NADIR_SOURCE}
NADIR_SRC = $${NADIR_PRJ}/$${NADIR_SOURCE}

# nadir INCLUDEPATH
#
#nadir_INCLUDEPATH += \
#$${NADIR_HOME_BUILD_INCLUDE} \

nadir_INCLUDEPATH += \
$${NADIR_SRC} \

# nadir DEFINES
#
nadir_DEFINES += \

########################################################################
# arbora
ARBORA_VERSION_MAJOR = 0
ARBORA_VERSION_MINOR = 0
ARBORA_VERSION_RELEASE = 0
ARBORA_VERSION = $${ARBORA_VERSION_MAJOR}.$${ARBORA_VERSION_MINOR}.$${ARBORA_VERSION_RELEASE}
ARBORA_NAME = arbora
ARBORA_GROUP = $${ARBORA_NAME}
ARBORA_SOURCE = src
ARBORA_DIR = $${ARBORA_GROUP}/$${ARBORA_NAME}-$${ARBORA_VERSION}
ARBORA_PKG_DIR = $${ARBORA_NAME}
ARBORA_HOME_BUILD = $${HOME}/build/$${ARBORA_NAME}
ARBORA_HOME_BUILD_INCLUDE = $${ARBORA_HOME_BUILD}/include
ARBORA_HOME_BUILD_LIB = $${ARBORA_HOME_BUILD}/lib
ARBORA_THIRDPARTY_PKG = $${THIRDPARTY_PKG}/$${ARBORA_DIR}
ARBORA_THIRDPARTY_PRJ = $${THIRDPARTY_PRJ}/$${ARBORA_DIR}
ARBORA_THIRDPARTY_SRC = $${THIRDPARTY_SRC}/$${ARBORA_PKG_DIR}
ARBORA_THIRDPARTY_SRC_GROUP = $${ARBORA_NAME}
ARBORA_THIRDPARTY_SRC_NAME = $${ARBORA_NAME}
ARBORA_THIRDPARTY_SRC_DIR = $${THIRDPARTY_SRC}/$${ARBORA_THIRDPARTY_SRC_GROUP}/$${ARBORA_THIRDPARTY_SRC_NAME} 
ARBORA_PKG = $${OTHER_PKG}/$${ARBORA_PKG_DIR}
ARBORA_PRJ = $${OTHER_PRJ}/$${ARBORA_PKG_DIR}
#ARBORA_SRC = $${ARBORA_THIRDPARTY_SRC_DIR}
#ARBORA_SRC = $${ARBORA_THIRDPARTY_PKG}/$${ARBORA_SOURCE}
#ARBORA_SRC = $${ARBORA_THIRDPARTY_PRJ}/$${ARBORA_SOURCE}
#ARBORA_SRC = $${ARBORA_PKG}/$${ARBORA_SOURCE}
ARBORA_SRC = $${ARBORA_PRJ}/$${ARBORA_SOURCE}

# arbora INCLUDEPATH
#
#arbora_INCLUDEPATH += \
#$${ARBORA_HOME_BUILD_INCLUDE} \

arbora_INCLUDEPATH += \
$${ARBORA_SRC} \

# arbora DEFINES
#
arbora_DEFINES += \

########################################################################
# crono
CRONO_VERSION_MAJOR = 0
CRONO_VERSION_MINOR = 0
CRONO_VERSION_RELEASE = 0
CRONO_VERSION = $${CRONO_VERSION_MAJOR}.$${CRONO_VERSION_MINOR}.$${CRONO_VERSION_RELEASE}
CRONO_NAME = crono
CRONO_GROUP = $${CRONO_NAME}
CRONO_SOURCE = src
CRONO_DIR = $${CRONO_GROUP}/$${CRONO_NAME}-$${CRONO_VERSION}
CRONO_PKG_DIR = $${CRONO_NAME}
CRONO_HOME_BUILD = $${HOME}/build/$${CRONO_NAME}
CRONO_HOME_BUILD_INCLUDE = $${CRONO_HOME_BUILD}/include
CRONO_HOME_BUILD_LIB = $${CRONO_HOME_BUILD}/lib
CRONO_THIRDPARTY_PKG = $${THIRDPARTY_PKG}/$${CRONO_DIR}
CRONO_THIRDPARTY_PRJ = $${THIRDPARTY_PRJ}/$${CRONO_DIR}
CRONO_THIRDPARTY_SRC = $${THIRDPARTY_SRC}/$${CRONO_PKG_DIR}
CRONO_THIRDPARTY_SRC_GROUP = $${CRONO_NAME}
CRONO_THIRDPARTY_SRC_NAME = $${CRONO_NAME}
CRONO_THIRDPARTY_SRC_DIR = $${THIRDPARTY_SRC}/$${CRONO_THIRDPARTY_SRC_GROUP}/$${CRONO_THIRDPARTY_SRC_NAME} 
CRONO_PKG = $${OTHER_PKG}/$${CRONO_PKG_DIR}
CRONO_PRJ = $${OTHER_PRJ}/$${CRONO_PKG_DIR}
#CRONO_SRC = $${CRONO_THIRDPARTY_SRC_DIR}
#CRONO_SRC = $${CRONO_THIRDPARTY_PKG}/$${CRONO_SOURCE}
#CRONO_SRC = $${CRONO_THIRDPARTY_PRJ}/$${CRONO_SOURCE}
#CRONO_SRC = $${CRONO_PKG}/$${CRONO_SOURCE}
CRONO_SRC = $${CRONO_PRJ}/$${CRONO_SOURCE}

# crono INCLUDEPATH
#
#crono_INCLUDEPATH += \
#$${CRONO_HOME_BUILD_INCLUDE} \

crono_INCLUDEPATH += \
$${CRONO_SRC} \

# crono DEFINES
#
crono_DEFINES += \

########################################################################
# fila
FILA_VERSION_MAJOR = 0
FILA_VERSION_MINOR = 0
FILA_VERSION_RELEASE = 0
FILA_VERSION = $${FILA_VERSION_MAJOR}.$${FILA_VERSION_MINOR}.$${FILA_VERSION_RELEASE}
FILA_NAME = fila
FILA_GROUP = $${FILA_NAME}
FILA_SOURCE = src
FILA_DIR = $${FILA_GROUP}/$${FILA_NAME}-$${FILA_VERSION}
FILA_PKG_DIR = $${FILA_NAME}
FILA_HOME_BUILD = $${HOME}/build/$${FILA_NAME}
FILA_HOME_BUILD_INCLUDE = $${FILA_HOME_BUILD}/include
FILA_HOME_BUILD_LIB = $${FILA_HOME_BUILD}/lib
FILA_THIRDPARTY_PKG = $${THIRDPARTY_PKG}/$${FILA_DIR}
FILA_THIRDPARTY_PRJ = $${THIRDPARTY_PRJ}/$${FILA_DIR}
FILA_THIRDPARTY_SRC = $${THIRDPARTY_SRC}/$${FILA_PKG_DIR}
FILA_THIRDPARTY_SRC_GROUP = $${FILA_NAME}
FILA_THIRDPARTY_SRC_NAME = $${FILA_NAME}
FILA_THIRDPARTY_SRC_DIR = $${THIRDPARTY_SRC}/$${FILA_THIRDPARTY_SRC_GROUP}/$${FILA_THIRDPARTY_SRC_NAME} 
FILA_PKG = $${OTHER_PKG}/$${FILA_PKG_DIR}
FILA_PRJ = $${OTHER_PRJ}/$${FILA_PKG_DIR}
#FILA_SRC = $${FILA_THIRDPARTY_SRC_DIR}
#FILA_SRC = $${FILA_THIRDPARTY_PKG}/$${FILA_SOURCE}
#FILA_SRC = $${FILA_THIRDPARTY_PRJ}/$${FILA_SOURCE}
#FILA_SRC = $${FILA_PKG}/$${FILA_SOURCE}
FILA_SRC = $${FILA_PRJ}/$${FILA_SOURCE}

# fila INCLUDEPATH
#
#fila_INCLUDEPATH += \
#$${FILA_HOME_BUILD_INCLUDE} \

fila_INCLUDEPATH += \
$${FILA_SRC} \

# fila DEFINES
#
fila_DEFINES += \

########################################################################
# stara
STARA_VERSION_MAJOR = 0
STARA_VERSION_MINOR = 0
STARA_VERSION_RELEASE = 0
STARA_VERSION = $${STARA_VERSION_MAJOR}.$${STARA_VERSION_MINOR}.$${STARA_VERSION_RELEASE}
STARA_NAME = stara
STARA_GROUP = $${STARA_NAME}
STARA_SOURCE = src
STARA_DIR = $${STARA_GROUP}/$${STARA_NAME}-$${STARA_VERSION}
STARA_PKG_DIR = $${STARA_NAME}
STARA_HOME_BUILD = $${HOME}/build/$${STARA_NAME}
STARA_HOME_BUILD_INCLUDE = $${STARA_HOME_BUILD}/include
STARA_HOME_BUILD_LIB = $${STARA_HOME_BUILD}/lib
STARA_THIRDPARTY_PKG = $${THIRDPARTY_PKG}/$${STARA_DIR}
STARA_THIRDPARTY_PRJ = $${THIRDPARTY_PRJ}/$${STARA_DIR}
STARA_THIRDPARTY_SRC = $${THIRDPARTY_SRC}/$${STARA_PKG_DIR}
STARA_THIRDPARTY_SRC_GROUP = $${STARA_NAME}
STARA_THIRDPARTY_SRC_NAME = $${STARA_NAME}
STARA_THIRDPARTY_SRC_DIR = $${THIRDPARTY_SRC}/$${STARA_THIRDPARTY_SRC_GROUP}/$${STARA_THIRDPARTY_SRC_NAME} 
STARA_PKG = $${OTHER_PKG}/$${STARA_PKG_DIR}
STARA_PRJ = $${OTHER_PRJ}/$${STARA_PKG_DIR}
#STARA_SRC = $${STARA_THIRDPARTY_SRC_DIR}
#STARA_SRC = $${STARA_THIRDPARTY_PKG}/$${STARA_SOURCE}
#STARA_SRC = $${STARA_THIRDPARTY_PRJ}/$${STARA_SOURCE}
#STARA_SRC = $${STARA_PKG}/$${STARA_SOURCE}
STARA_SRC = $${STARA_PRJ}/$${STARA_SOURCE}

# stara INCLUDEPATH
#
stara_INCLUDEPATH += \
$${STARA_SRC} \

# stara DEFINES
#
stara_DEFINES += \

########################################################################
# porta
PORTA_VERSION_MAJOR = 0
PORTA_VERSION_MINOR = 0
PORTA_VERSION_RELEASE = 0
PORTA_VERSION = $${PORTA_VERSION_MAJOR}.$${PORTA_VERSION_MINOR}.$${PORTA_VERSION_RELEASE}
PORTA_NAME = porta
PORTA_GROUP = $${PORTA_NAME}
PORTA_SOURCE = src
PORTA_DIR = $${PORTA_GROUP}/$${PORTA_NAME}-$${PORTA_VERSION}
PORTA_PKG_DIR = $${PORTA_NAME}
PORTA_HOME_BUILD = $${HOME}/build/$${PORTA_NAME}
PORTA_HOME_BUILD_INCLUDE = $${PORTA_HOME_BUILD}/include
PORTA_HOME_BUILD_LIB = $${PORTA_HOME_BUILD}/lib
PORTA_THIRDPARTY_PKG = $${THIRDPARTY_PKG}/$${PORTA_DIR}
PORTA_THIRDPARTY_PRJ = $${THIRDPARTY_PRJ}/$${PORTA_DIR}
PORTA_THIRDPARTY_SRC = $${THIRDPARTY_SRC}/$${PORTA_PKG_DIR}
PORTA_THIRDPARTY_SRC_GROUP = $${PORTA_NAME}
PORTA_THIRDPARTY_SRC_NAME = $${PORTA_NAME}
PORTA_THIRDPARTY_SRC_DIR = $${THIRDPARTY_SRC}/$${PORTA_THIRDPARTY_SRC_GROUP}/$${PORTA_THIRDPARTY_SRC_NAME} 
PORTA_PKG = $${OTHER_PKG}/$${PORTA_PKG_DIR}
PORTA_PRJ = $${OTHER_PRJ}/$${PORTA_PKG_DIR}
#PORTA_SRC = $${PORTA_THIRDPARTY_SRC_DIR}
#PORTA_SRC = $${PORTA_THIRDPARTY_PKG}/$${PORTA_SOURCE}
#PORTA_SRC = $${PORTA_THIRDPARTY_PRJ}/$${PORTA_SOURCE}
#PORTA_SRC = $${PORTA_PKG}/$${PORTA_SOURCE}
PORTA_SRC = $${PORTA_PRJ}/$${PORTA_SOURCE}

# porta INCLUDEPATH
#
porta_INCLUDEPATH += \
$${PORTA_SRC} \

# porta DEFINES
#
porta_DEFINES += \

########################################################################
# archa
ARCHA_VERSION_MAJOR = 0
ARCHA_VERSION_MINOR = 0
ARCHA_VERSION_RELEASE = 0
ARCHA_VERSION = $${ARCHA_VERSION_MAJOR}.$${ARCHA_VERSION_MINOR}.$${ARCHA_VERSION_RELEASE}
ARCHA_NAME = archa
ARCHA_GROUP = $${ARCHA_NAME}
ARCHA_SOURCE = src
ARCHA_DIR = $${ARCHA_GROUP}/$${ARCHA_NAME}-$${ARCHA_VERSION}
ARCHA_PKG_DIR = $${ARCHA_NAME}
ARCHA_HOME_BUILD = $${HOME}/build/$${ARCHA_NAME}
ARCHA_HOME_BUILD_INCLUDE = $${ARCHA_HOME_BUILD}/include
ARCHA_HOME_BUILD_LIB = $${ARCHA_HOME_BUILD}/lib
ARCHA_THIRDPARTY_PKG = $${THIRDPARTY_PKG}/$${ARCHA_DIR}
ARCHA_THIRDPARTY_PRJ = $${THIRDPARTY_PRJ}/$${ARCHA_DIR}
ARCHA_THIRDPARTY_SRC = $${THIRDPARTY_SRC}/$${ARCHA_PKG_DIR}
ARCHA_THIRDPARTY_SRC_GROUP = $${ARCHA_NAME}
ARCHA_THIRDPARTY_SRC_NAME = $${ARCHA_NAME}
ARCHA_THIRDPARTY_SRC_DIR = $${THIRDPARTY_SRC}/$${ARCHA_THIRDPARTY_SRC_GROUP}/$${ARCHA_THIRDPARTY_SRC_NAME} 
ARCHA_PKG = $${OTHER_PKG}/$${ARCHA_PKG_DIR}
ARCHA_PRJ = $${OTHER_PRJ}/$${ARCHA_PKG_DIR}
#ARCHA_SRC = $${ARCHA_THIRDPARTY_SRC_DIR}
#ARCHA_SRC = $${ARCHA_THIRDPARTY_PKG}/$${ARCHA_SOURCE}
#ARCHA_SRC = $${ARCHA_THIRDPARTY_PRJ}/$${ARCHA_SOURCE}
#ARCHA_SRC = $${ARCHA_PKG}/$${ARCHA_SOURCE}
ARCHA_SRC = $${ARCHA_PRJ}/$${ARCHA_SOURCE}

# archa INCLUDEPATH
#
#archa_INCLUDEPATH += \
#$${ARCHA_HOME_BUILD_INCLUDE} \

archa_INCLUDEPATH += \
$${ARCHA_SRC} \

# archa DEFINES
#
archa_DEFINES += \



########################################################################
# texta
FRAMEWORK_NAME = texta
FRAMEWORK_SOURCE = src

TEXTA_PKG = ../../../../..
TEXTA_BLD = ../..

TEXTA_PRJ = $${TEXTA_PKG}
TEXTA_BIN = $${TEXTA_BLD}/bin
TEXTA_LIB = $${TEXTA_BLD}/lib
TEXTA_SRC = $${TEXTA_PKG}/$${FRAMEWORK_SOURCE}

# texta BUILD_CONFIG
#
CONFIG(debug, debug|release) {
BUILD_CONFIG = Debug
texta_DEFINES += DEBUG_BUILD
} else {
BUILD_CONFIG = Release
texta_DEFINES += RELEASE_BUILD
}

# texta INCLUDEPATH
#
texta_INCLUDEPATH += \
$${TEXTA_SRC} \
$${archa_INCLUDEPATH} \
$${porta_INCLUDEPATH} \
$${stara_INCLUDEPATH} \
$${fila_INCLUDEPATH} \
$${crono_INCLUDEPATH} \
$${arbora_INCLUDEPATH} \
$${nadir_INCLUDEPATH} \
$${rostra_INCLUDEPATH} \
$${build_texta_INCLUDEPATH} \

# texta DEFINES
#
texta_DEFINES += \
$${rostra_DEFINES} \
$${nadir_DEFINES} \
$${arbora_DEFINES} \
$${crono_DEFINES} \
$${fila_DEFINES} \
$${stara_DEFINES} \
$${porta_DEFINES} \
$${archa_DEFINES} \
$${build_texta_DEFINES} \

# texta LIBS
#
texta_LIBS += \
-L$${TEXTA_LIB}/lib$${FRAMEWORK_NAME} \
-l$${FRAMEWORK_NAME} \
