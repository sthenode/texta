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
# build QtCreator .pri file for texta
########################################################################

########################################################################
# rostra
#
# pkg-config --cflags --libs rostra
#

# build rostra INCLUDEPATH
#
build_rostra_INCLUDEPATH += \

# build rostra DEFINES
#
build_rostra_DEFINES += \

# build rostra LIBS
#
build_rostra_LIBS += \

########################################################################
# nadir
#
# pkg-config --cflags --libs nadir
#

# build nadir INCLUDEPATH
#
build_nadir_INCLUDEPATH += \

# build nadir DEFINES
#
build_nadir_DEFINES += \

# build nadir LIBS
#
build_nadir_LIBS += \

########################################################################
# arbora
#
# pkg-config --cflags --libs arbora
#

# build arbora INCLUDEPATH
#
build_arbora_INCLUDEPATH += \

# build arbora DEFINES
#
build_arbora_DEFINES += \

# build arbora LIBS
#
build_arbora_LIBS += \

########################################################################
# crono
#
# pkg-config --cflags --libs crono
#

# build crono INCLUDEPATH
#
build_crono_INCLUDEPATH += \

# build crono DEFINES
#
build_crono_DEFINES += \

# build crono LIBS
#
build_crono_LIBS += \

########################################################################
# fila
#
# pkg-config --cflags --libs fila
#

# build fila INCLUDEPATH
#
build_fila_INCLUDEPATH += \

# build fila DEFINES
#
build_fila_DEFINES += \

# build fila LIBS
#
build_fila_LIBS += \

########################################################################
# archa
#
# pkg-config --cflags --libs archa
#

# build archa INCLUDEPATH
#
build_archa_INCLUDEPATH += \

# build archa DEFINES
#
build_archa_DEFINES += \

# build archa LIBS
#
build_archa_LIBS += \

########################################################################
# texta

# build texta INCLUDEPATH
#
build_texta_INCLUDEPATH += \
$${build_archa_INCLUDEPATH} \
$${build_fila_INCLUDEPATH} \
$${build_crono_INCLUDEPATH} \
$${build_arbora_INCLUDEPATH} \
$${build_nadir_INCLUDEPATH} \
$${build_rostra_INCLUDEPATH} \


# build texta DEFINES
#
build_texta_DEFINES += \
$${build_rostra_DEFINES} \
$${build_nadir_DEFINES} \
$${build_arbora_DEFINES} \
$${build_crono_DEFINES} \
$${build_fila_DEFINES} \
$${build_archa_DEFINES} \


# build texta LIBS
#
build_texta_LIBS += \
$${build_archa_LIBS} \
$${build_fila_LIBS} \
$${build_crono_LIBS} \
$${build_arbora_LIBS} \
$${build_nadir_LIBS} \
$${build_rostra_LIBS} \


