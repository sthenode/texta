########################################################################
# Copyright (c) 1988-2019 $organization$
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
#   File: cxxlcgi.pri
#
# Author: $author$
#   Date: 9/11/2019
#
# QtCreator .pri file for texta executable cxxlcgi
########################################################################

########################################################################
# cxxlcgi

# cxxlcgi TARGET
#
cxxlcgi_TARGET = cxxlcgi

# cxxlcgi INCLUDEPATH
#
cxxlcgi_INCLUDEPATH += \
$${texta_INCLUDEPATH} \

# cxxlcgi DEFINES
#
cxxlcgi_DEFINES += \
$${texta_DEFINES} \

########################################################################
# cxxlcgi OBJECTIVE_HEADERS
#
#cxxlcgi_OBJECTIVE_HEADERS += \
#$${TEXTA_SRC}/texta/base/Base.hh \

# cxxlcgi OBJECTIVE_SOURCES
#
#cxxlcgi_OBJECTIVE_SOURCES += \
#$${TEXTA_SRC}/texta/base/Base.mm \

########################################################################
# cxxlcgi HEADERS
#
cxxlcgi_HEADERS += \
$${CRONO_SRC}/xos/console/logger.hpp \
$${FILA_SRC}/xos/console/main_main.hpp \
\
$${libcxxl_HEADERS} \
$${TEXTA_SRC}/xos/app/console/cxxl/ccgimain.hxx \

# cxxlcgi SOURCES
#
cxxlcgi_SOURCES += \
$${CRONO_SRC}/xos/console/logger.cpp \
$${FILA_SRC}/xos/console/main_main.cpp \
\
$${libcxxl_SOURCES} \
$${TEXTA_SRC}/xos/app/console/cxxl/ccgimain.cxx \

########################################################################
# cxxlcgi FRAMEWORKS
#
cxxlcgi_FRAMEWORKS += \
$${texta_FRAMEWORKS} \

# cxxlcgi LIBS
#
cxxlcgi_LIBS += \
$${texta_LIBS} \


