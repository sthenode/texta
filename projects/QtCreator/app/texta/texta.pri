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
# QtCreator .pri file for texta executable texta
########################################################################

########################################################################
# texta

# texta_exe TARGET
#
texta_exe_TARGET = texta

# texta_exe INCLUDEPATH
#
texta_exe_INCLUDEPATH += \
$${texta_INCLUDEPATH} \

# texta_exe DEFINES
#
texta_exe_DEFINES += \
$${texta_DEFINES} \

########################################################################
# texta_exe OBJECTIVE_HEADERS
#
#texta_exe_OBJECTIVE_HEADERS += \
#$${TEXTA_SRC}/texta/base/Base.hh \

# texta_exe OBJECTIVE_SOURCES
#
#texta_exe_OBJECTIVE_SOURCES += \
#$${TEXTA_SRC}/texta/base/Base.mm \

########################################################################
# texta_exe HEADERS
#
#texta_exe_HEADERS += \
#$${TEXTA_SRC}/texta/base/Base.hpp \

# texta_exe SOURCES
#
#texta_exe_SOURCES += \
#$${TEXTA_SRC}/texta/base/Base.cpp \

########################################################################
# texta_exe FRAMEWORKS
#
texta_exe_FRAMEWORKS += \
$${texta_FRAMEWORKS} \

# texta_exe LIBS
#
texta_exe_LIBS += \
$${texta_LIBS} \


