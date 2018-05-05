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
 *   File: ccounter.hxx
 *
 * Author: $author$
 *   Date: 3/21/2008, 5/5/2018
 **********************************************************************
 */
#ifndef _CCOUNTER_HXX
#define _CCOUNTER_HXX

#include "cbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cCounterT
 *
 * Author: $author$
 *   Date: 3/21/2008
 **********************************************************************
 */
template
<class TWhat=CHAR, 
 class TLength=TLENGTH,
 class TNull=TWhat,
 TNull VNull=NULL_CHAR,
 class TExtends=cBase>
 
class cCounterT: public TExtends {
public:
    typedef TExtends cExtends;
    typedef cCounterT cDerives;

    virtual TLength LengthOf(const TWhat* what) const {
        TLength count = 0;
        if (what)
        while ((*what++) != VNull)
            count++;
        return count;
    }
};

typedef cCounterT
<CHAR,TLENGTH,CHAR,NULL_CHAR,cBase>
cCHARCounter, cCharCounter, cCounter;

typedef cCounterT
<TCHAR,TLENGTH,CHAR,NULL_CHAR,cBase>
cTCHARCounter, cTCharCounter, cTCounter;

typedef cCounterT
<WCHAR,TLENGTH,CHAR,NULL_CHAR,cBase>
cWCHARCounter, cWCharCounter, cWCounter;

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _CCOUNTER_HXX */
