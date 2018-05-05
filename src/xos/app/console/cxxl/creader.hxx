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
 *   File: creader.hxx
 *
 * Author: $author$
 *   Date: 1/10/2007, 5/2/2018
 **********************************************************************
 */
#ifndef _CREADER_HXX
#define _CREADER_HXX

#include "cinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cReaderInterfaceT
 *
 * Author: $author$
 *   Date: 1/10/2007
 **********************************************************************
 */
template
<class TWhat=CHAR, 
 class TSize=TSIZE, 
 class TLength=TLENGTH, 
 TLength VUndefined=UNDEFINED_LENGTH,
 class TImplements=cInterfaceBase>

class c_INTERFACE_CLASS cReaderInterfaceT: virtual public TImplements {
public:
    typedef TWhat tWhat;
    typedef TSize tSize;
    typedef TLength tLength;

    virtual TLength Look(TWhat* what, TSize size) = 0;
    virtual TLength Read(TWhat* what, TSize size) = 0;
    virtual TLength Peek(TWhat& what) = 0;
    virtual TLength Get(TWhat& what) = 0;
    virtual const TWhat* See(TLength& length) const = 0;
};

typedef cReaderInterfaceT
<CHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, cInterfaceBase> 
cCHARReaderInterface, cReaderInterface;

typedef cReaderInterfaceT
<TCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, cInterfaceBase> 
cTCHARReaderInterface, cTReaderInterface;

typedef cReaderInterfaceT
<WCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, cInterfaceBase> 
cWCHARReaderInterface, cWReaderInterface;

/**
 **********************************************************************
 *  Class: cReaderImplementT
 *
 * Author: $author$
 *   Date: 1/10/2007
 **********************************************************************
 */
template
<class TWhat=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefined=UNDEFINED_LENGTH,
 class TImplements=cReaderInterfaceT<TWhat, TSize, TLength, VUndefined>/*,
 class TExtends=cImplementBase*/>

class cReaderImplementT: virtual public TImplements/*, virtual public TExtends*/ {
public:
    virtual TLength Look
    (TWhat* what, TSize size) {
        TLength length = -e_ERROR_NOT_IMPLEMENTED;
        return length;
    }
    virtual TLength Read
    (TWhat* what, TSize size) {
        TLength length = -e_ERROR_NOT_IMPLEMENTED;
        return length;
    }
    virtual TLength Peek(TWhat& what) {
        TLength length = Look(&what, 1);
        return length;
    }
    virtual TLength Get(TWhat& what) {
        TLength length = Read(&what, 1);
        return length;
    }
    virtual const TWhat* See
    (TLength& length) const {
        const TWhat* what = 0;
        length = 0;
        return what;
    }
};

typedef cReaderImplementT
<CHAR, TSIZE, TLENGTH,  UNDEFINED_LENGTH, 
cCHARReaderInterface> cCHARReaderImplement, cReaderImplement;

typedef cReaderImplementT
<TCHAR, TSIZE, TLENGTH,  UNDEFINED_LENGTH, 
cTCHARReaderInterface> cTCHARReaderImplement, cTReaderImplement;

typedef cReaderImplementT
<WCHAR, TSIZE, TLENGTH,  UNDEFINED_LENGTH, 
cWCHARReaderInterface> cWCHARReaderImplement, cWReaderImplement;

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _CREADER_HXX */
