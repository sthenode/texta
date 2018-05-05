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
$${TEXTA_SRC}/xos/app/console/cxxl/cdebug.hxx \
$${TEXTA_SRC}/xos/app/console/cxxl/cbase.hxx \
$${TEXTA_SRC}/xos/app/console/cxxl/cinterface.hxx \
$${TEXTA_SRC}/xos/app/console/cxxl/clist.hxx \
$${TEXTA_SRC}/xos/app/console/cxxl/ccounter.hxx \
$${TEXTA_SRC}/xos/app/console/cxxl/creader.hxx \
$${TEXTA_SRC}/xos/app/console/cxxl/cwriter.hxx \
$${TEXTA_SRC}/xos/app/console/cxxl/cstream.hxx \
$${TEXTA_SRC}/xos/app/console/cxxl/cstring.hxx \
$${TEXTA_SRC}/xos/app/console/cxxl/cerror.hxx \
$${TEXTA_SRC}/xos/app/console/cxxl/cattached.hxx \
$${TEXTA_SRC}/xos/app/console/cxxl/cfile.hxx \
$${TEXTA_SRC}/xos/app/console/cxxl/clexerdelegate.hxx \
$${TEXTA_SRC}/xos/app/console/cxxl/clexertoken.hxx \
$${TEXTA_SRC}/xos/app/console/cxxl/clexersource.hxx \
$${TEXTA_SRC}/xos/app/console/cxxl/yylexer.hxx \
$${TEXTA_SRC}/xos/app/console/cxxl/cyylexer.hxx \
$${TEXTA_SRC}/xos/app/console/cxxl/clexer.hxx \
$${TEXTA_SRC}/xos/app/console/cxxl/ccxxlexer.hxx \
$${TEXTA_SRC}/xos/app/console/cxxl/ccxxlex.hxx \
$${TEXTA_SRC}/xos/app/console/cxxl/cmain.hxx \
$${CRONO_SRC}/xos/console/logger.hpp \
$${FILA_SRC}/xos/console/main_main.hpp \

# cxxl SOURCES
#
cxxl_SOURCES += \
$${TEXTA_SRC}/xos/app/console/cxxl/cdebug.cxx \
$${TEXTA_SRC}/xos/app/console/cxxl/cbase.cxx \
$${TEXTA_SRC}/xos/app/console/cxxl/cinterface.cxx \
$${TEXTA_SRC}/xos/app/console/cxxl/clist.cxx \
$${TEXTA_SRC}/xos/app/console/cxxl/ccounter.cxx \
$${TEXTA_SRC}/xos/app/console/cxxl/creader.cxx \
$${TEXTA_SRC}/xos/app/console/cxxl/cwriter.cxx \
$${TEXTA_SRC}/xos/app/console/cxxl/cstream.cxx \
$${TEXTA_SRC}/xos/app/console/cxxl/cstring.cxx \
$${TEXTA_SRC}/xos/app/console/cxxl/cerror.cxx \
$${TEXTA_SRC}/xos/app/console/cxxl/cattached.cxx \
$${TEXTA_SRC}/xos/app/console/cxxl/cfile.cxx \
$${TEXTA_SRC}/xos/app/console/cxxl/clexerdelegate.cxx \
$${TEXTA_SRC}/xos/app/console/cxxl/clexertoken.cxx \
$${TEXTA_SRC}/xos/app/console/cxxl/clexersource.cxx \
$${TEXTA_SRC}/xos/app/console/cxxl/yylexer.cxx \
$${TEXTA_SRC}/xos/app/console/cxxl/cyylexer.cxx \
$${TEXTA_SRC}/xos/app/console/cxxl/clexer.cxx \
$${TEXTA_SRC}/xos/app/console/cxxl/ccxxlexer.cxx \
$${TEXTA_SRC}/xos/app/console/cxxl/ccxxlex.cxx \
$${TEXTA_SRC}/xos/app/console/cxxl/cmain.cxx \
$${CRONO_SRC}/xos/console/logger.cpp \
$${FILA_SRC}/xos/console/main_main.cpp \

########################################################################
# cxxl FRAMEWORKS
#
cxxl_FRAMEWORKS += \
$${texta_FRAMEWORKS} \

# cxxl LIBS
#
cxxl_LIBS += \
$${texta_LIBS} \
