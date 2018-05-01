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
#   File: tflex.pri
#
# Author: $author$
#   Date: 5/1/2018
#
# QtCreator .pri file for texta executable tflex
########################################################################

########################################################################
# tflex

TFLEX_SRC = $${TEXTA_SRC}/xos/app/console/tflex

# tflex TARGET
#
tflex_TARGET = tflex

# tflex INCLUDEPATH
#
tflex_INCLUDEPATH += \
$${texta_INCLUDEPATH} \

# tflex DEFINES
#
tflex_DEFINES += \
$${texta_DEFINES} \

########################################################################
# tflex OBJECTIVE_HEADERS
#
#tflex_OBJECTIVE_HEADERS += \
#$${TEXTA_SRC}/texta/base/Base.hh \

# tflex OBJECTIVE_SOURCES
#
#tflex_OBJECTIVE_SOURCES += \
#$${TEXTA_SRC}/texta/base/Base.mm \

########################################################################
# tflex HEADERS
#
tflex_HEADERS += \

# tflex SOURCES
#
tflex_SOURCES += \
$${TFLEX_SRC}/ccl.c \
$${TFLEX_SRC}/dfa.c \
$${TFLEX_SRC}/ecs.c \
$${TFLEX_SRC}/gen.c \
$${TFLEX_SRC}/misc.c \
$${TFLEX_SRC}/nfa.c \
$${TFLEX_SRC}/parse.c \
$${TFLEX_SRC}/scan.c \
$${TFLEX_SRC}/skel.c \
$${TFLEX_SRC}/sym.c \
$${TFLEX_SRC}/tblcmp.c \
$${TFLEX_SRC}/yylex.c \
$${TFLEX_SRC}/main.c \

########################################################################
# tflex FRAMEWORKS
#
tflex_FRAMEWORKS += \
$${texta_FRAMEWORKS} \

# tflex LIBS
#
tflex_LIBS += \
$${texta_LIBS} \


