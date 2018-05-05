/**
 **********************************************************************
 * Copyright (c) 1988-2018 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: cdebug.hxx
 *
 * Author: $author$
 *   Date: 11/13/2007, 5/2/2018
 **********************************************************************
 */
#ifndef _CDEBUG_HXX
#define _CDEBUG_HXX

#include "xos/io/logger.hpp"

#define DBE(args) LOG_ERRORF args
#define DBW(args) LOG_WARNF args
#define DBI(args) LOG_INFOF args
#define DBF(args) LOG_DEBUGF args
#define DBT(args) LOG_TRACEF args

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _CDEBUG_HXX */
