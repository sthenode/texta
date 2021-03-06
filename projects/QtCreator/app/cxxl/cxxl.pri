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
#   File: cxxl.pri
#
# Author: $author$
#   Date: 5/2/2018
#
# QtCreator .pri file for texta executable cxxl
########################################################################

########################################################################
# cxxl

# cxxl TARGET
#
cxxl_TARGET = cxxl

# cxxl INCLUDEPATH
#
cxxl_INCLUDEPATH += \
$${texta_INCLUDEPATH} \

# cxxl DEFINES
#
cxxl_DEFINES += \
$${texta_DEFINES} \

########################################################################
# cxxl OBJECTIVE_HEADERS
#
#cxxl_OBJECTIVE_HEADERS += \
#$${TEXTA_SRC}/texta/base/Base.hh \

# cxxl OBJECTIVE_SOURCES
#
#cxxl_OBJECTIVE_SOURCES += \
#$${TEXTA_SRC}/texta/base/Base.mm \

########################################################################
# cxxl HEADERS
#
cxxl_HEADERS += \
$${CRONO_SRC}/xos/console/logger.hpp \
$${FILA_SRC}/xos/console/main_main.hpp \
\
$${libcxxl_HEADERS} \
$${TEXTA_SRC}/xos/app/console/cxxl/cmain.hxx \

# cxxl SOURCES
#
cxxl_SOURCES += \
$${CRONO_SRC}/xos/console/logger.cpp \
$${FILA_SRC}/xos/console/main_main.cpp \
\
$${libcxxl_SOURCES} \
$${TEXTA_SRC}/xos/app/console/cxxl/cmain.cxx \

########################################################################
# cxxl FRAMEWORKS
#
cxxl_FRAMEWORKS += \
$${texta_FRAMEWORKS} \

# cxxl LIBS
#
cxxl_LIBS += \
$${texta_LIBS} \
