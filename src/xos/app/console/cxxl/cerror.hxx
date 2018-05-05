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
 *   File: cerror.hxx
 *
 * Author: $author$
 *   Date: 1/13/2007, 5/2/2018
 **********************************************************************
 */
#ifndef _CERROR_HXX
#define _CERROR_HXX

#include "cstring.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cErrorT
 *
 * Author: $author$
 *   Date: 8/25/2003
 **********************************************************************
 */
template 
<class TChar=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 class TString=cStringT<TChar, TSize, TLength>,
 class TExtends=cBase>

class cErrorT: public TExtends {
public:
    typedef TExtends cIs;

    eError m_error;
    TString m_errorDescription;

    cErrorT
    (eError error=e_ERROR_NONE, 
     const TChar* description=0,
     TLength descriptionLength=-1)
    : m_error(error) 
    {
        TLength length;

        if (description)
        if (0 > (length = m_errorDescription.Assign
            (description, descriptionLength)))
            throw(error = -length);
    }

    virtual eError SetLastError
    (eError error, const TChar* description=0,
     TLength descriptionLength=-1)
    {
        TLength length;

        if (description)
        {
            if (0 > (length = m_errorDescription.Assign
                (description, descriptionLength)))
                return -error;
        }
        else if (0 < (length = m_errorDescription.Length()))
        {
            if (0 > (length = m_errorDescription.Clear()))
                return -error;
        }
        return m_error = error;
    }
    virtual eError GetLastError
    (const TChar*& description) const
    {
        static TChar nullChar = 0;
        eError error;
        TLength length;
        const TChar* errorDescription;

        description = &nullChar;

        if ((error = m_error))
        if ((errorDescription = m_errorDescription.Chars(length)))
            description = errorDescription;
        return error;
    }
};

typedef cErrorT<CHAR, TSIZE, TLENGTH, cCHARString> cCHARError, cError;
typedef cErrorT<TCHAR, TSIZE, TLENGTH, cTCHARString> cTCHARError, cTError;
typedef cErrorT<WCHAR, TSIZE, TLENGTH, cWCHARString> cWCHARError, cWError;

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _CERROR_HXX */
