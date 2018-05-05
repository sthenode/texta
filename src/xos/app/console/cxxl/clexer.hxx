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
 *   File: clexer.hxx
 *
 * Author: $author$
 *   Date: 7/8/2008, 5/2/2018
 **********************************************************************
 */
#ifndef _CLEXER_HXX
#define _CLEXER_HXX

#include "clexersource.hxx"
#include "clexerdelegate.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cLexerT
 *
 * Author: $author$
 *   Date: 7/8/2008
 **********************************************************************
 */
template
<class TDelegate,
 class TExtends,
 class TSource=cLexerSource,
 class TStream=cCharStreamInterface>
 
class cLexerT: virtual public TDelegate, public TExtends {
public:
    typedef TExtends cExtends;
    typedef TDelegate cDelegate;

    TDelegate& m_delegate;

    cLexerT
    (TDelegate& delegate, TStream& out, TStream& in, TSource& source) 
    : cExtends(out, in, source), m_delegate(delegate) {
    }
    virtual ~cLexerT() {
    }

    virtual eError OnCharToken
    (const char* text, int token=-1,
     int beginchars=1, int endchars=1) {
        eError error = e_ERROR_NONE;
        TDelegate* m_delegate = 0;

        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCharToken
            (text, token, beginchars, endchars);

        if (0 > beginchars) beginchars = 1;
        if (0 > endchars) endchars = 1;

        this->OnEscapedTokenText
        (text, token, beginchars, endchars);
        return error;
    }
    virtual eError OnStringToken
    (const char* text, int token=-1,
     int beginchars=1, int endchars=1) {
        eError error = e_ERROR_NONE;
        TDelegate* m_delegate = 0;

        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnStringToken
            (text, token, beginchars, endchars);

        if (0 > beginchars) beginchars = 1;
        if (0 > endchars) endchars = 1;

        this->OnEscapedTokenText
        (text, token, beginchars, endchars);
        return error;
    }
    virtual eError OnIdentifierToken
    (const char* text, int token=-1,
     int beginchars=0, int endchars=0) {
        eError error = e_ERROR_NONE;
        TDelegate* m_delegate = 0;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnIdentifierToken
            (text, token, beginchars, endchars);
        this->OnTokenText
        (text, token, beginchars, endchars);
        return error;
    }
    virtual eError OnSwitch(const char* text, int token=-1) {
        eError error = e_ERROR_NONE;
        TDelegate* m_delegate = 0;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnSwitch(text, token);
        this->OnSwitchState(text, token);
        return error;
    }

    virtual eError OnPush(const char* text, int token=-1) {
        eError error = e_ERROR_NONE;
        TDelegate* m_delegate = 0;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnPush(text, token);
        this->OnPushState(text, token);
        return error;
    }
    virtual eError OnPop(const char* text, int token=-1) {
        eError error = e_ERROR_NONE;
        TDelegate* m_delegate = 0;
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnPop(text, token);
        this->OnPopState(text, token);
        return error;
    }

    virtual TDelegate* GetDelegate() {
        return &m_delegate;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _CLEXER_HXX */
