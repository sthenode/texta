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
 *   File: cwriter.hxx
 *
 * Author: $author$
 *   Date: 1/13/2007, 5/2/2018
 **********************************************************************
 */
#ifndef _CWRITER_HXX
#define _CWRITER_HXX

#include "cinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cWriterInterfaceT
 *
 * Author: $author$
 *   Date: 1/13/2007
 **********************************************************************
 */
template
<class TWhat=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefined=UNDEFINED_LENGTH,
 class TImplements=cInterfaceBase>

class c_INTERFACE_CLASS cWriterInterfaceT: virtual public TImplements {
public:
    virtual TLength Write(const TWhat* what, TLength length = VUndefined) = 0;
    virtual TLength WriteL(const TWhat* what, ...) = 0;
    virtual TLength WriteV(TWhat*const* vwhat, TLength vlength = VUndefined) = 0;
    virtual TLength VWrite(va_list va, TLength vlength = VUndefined) = 0;
    virtual TLength Put(TWhat what) = 0;
};

typedef cWriterInterfaceT
<CHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, cInterfaceBase> 
cCHARWriterInterface,
cWriterInterface;

typedef cWriterInterfaceT
<TCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, cInterfaceBase> 
cTCHARWriterInterface,
cTWriterInterface;

typedef cWriterInterfaceT
<WCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, cInterfaceBase> 
cWCHARWriterInterface,
cWWriterInterface;

/**
 **********************************************************************
 *  Class: cWriterImplementT
 *
 * Author: $author$
 *   Date: 1/13/2007
 **********************************************************************
 */
template
<class TWhat=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefined=UNDEFINED_LENGTH,
 class TImplements=cWriterInterfaceT<TWhat, TSize, TLength, VUndefined>/*,
 class TExtends=cImplementBase*/>

class cWriterImplementT: virtual public TImplements/*, virtual public TExtends*/ {
public:
    virtual TLength Write(const TWhat* what, TLength length = VUndefined) {
        TLength count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
    virtual TLength WriteL(const TWhat* what, ...) {
        TLength length = 0;
        TLength count = 0;
        va_list va;

        va_start(va, what);
        if (0 <= (length = Write(what))) {
            if (0 > (count = VWrite(va)))
                length = count;
            else length += count;
        }
        va_end(va);
        return length;
    }
    virtual TLength WriteV(TWhat*const* vwhat, TLength vlength = VUndefined) {
        TLength count = -e_ERROR_NOT_IMPLEMENTED;
        return count;
    }
    virtual TLength VWrite(va_list va, TLength vlength = VUndefined) {
        TLength length = 0;
        TLength count = 0;
        const TWhat* what = 0;
        while ((what = va_arg(va, const TWhat*))) {
            if (0 <= (length = Write(what))) {
                count += length;
            }
        }
        return count;
    }
    virtual TLength Put(TWhat what) {
        TLength count = 0;
        count = Write(&what, 1);
        return count;
    }
};

typedef cWriterImplementT
<CHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
cCHARWriterInterface> cCHARWriterImplement, cWriterImplement;

typedef cWriterImplementT
<TCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
cTCHARWriterInterface> cTCHARWriterImplement, cTWriterImplement;

typedef cWriterImplementT
<WCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
cWCHARWriterInterface> cWCHARWriterImplement, cWWriterImplement;

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _CWRITER_HXX */
