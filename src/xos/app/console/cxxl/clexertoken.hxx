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
 *   File: clexertoken.hxx
 *
 * Author: $author$
 *   Date: 5/2/2008, 5/4/2018
 **********************************************************************
 */
#ifndef _CLEXERTOKEN_HXX
#define _CLEXERTOKEN_HXX

#include "clist.hxx"
#include "cstring.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cLexerToken
 *
 * Author: $author$
 *   Date: 8/25/2003
 **********************************************************************
 */
class cLexerToken;
typedef cDynamicListItemT<cLexerToken> cLexerTokenExtends;
class cLexerToken: public cLexerTokenExtends {
public:
    typedef cLexerTokenExtends cExtends;

    cCharString m_buffer;

    cLexerToken(const char *token=0,int len=-1) {
        if (token)
            Set(token,len);
    }

    int Set(const char *token,int len=-1) {
        return m_buffer.Assign(token,len);
    }
    int SetUpper(const char *token,int len=-1) {
        return m_buffer.AssignUpper(token,len);
    }
    int SetLower(const char *token,int len=-1) {
        return m_buffer.AssignLower(token,len);
    }
    int SetEscaped(const char *token,int len=-1) {
        return m_buffer.Assign(token,len);
    }

    int Add(const char *token,int len=-1) {
        return m_buffer.Write(token,len);
    }
    int AddUpper(const char *token,int len=-1) {
        return m_buffer.AppendUpper(token,len);
    }
    int AddLower(const char *token,int len=-1) {
        return m_buffer.AppendLower(token,len);
    }
    int AddEscaped(const char *token,int len=-1) {
        return m_buffer.Write(token,len);
    }

    inline const char *Get() {
        TLENGTH length = 0;
        return m_buffer.Chars(length);
    }
    inline cCharStreamInterface& GetStream() {
        return m_buffer;
    }
};

/**
 **********************************************************************
 *  Class: cEscapedLexerToken
 *
 * Author: $author$
 *   Date: 8/25/2003
 **********************************************************************
 */
class cEscapedLexerToken: public cLexerToken {
public:
    typedef cLexerToken cExtends;

    cEscapedLexerToken(const char *token,int len=-1)  {
        if (token) SetEscaped(token,len);
    }
};

/**
 **********************************************************************
 *  Class: cUpperLexerToken
 *
 * Author: $author$
 *   Date: 8/1/2008
 **********************************************************************
 */
class cUpperLexerToken: public cLexerToken {
public:
    typedef cLexerToken cExtends;
    typedef cUpperLexerToken cDerives;

    cUpperLexerToken(const char *token, int len=-1) {
        if(token) SetUpper(token,len);
    }
};

/**
 **********************************************************************
 *  Class: cLowerLexerToken
 *
 * Author: $author$
 *   Date: 8/1/2008
 **********************************************************************
 */
class cLowerLexerToken: public cLexerToken {
public:
    typedef cLexerToken cExtends;
    typedef cLowerLexerToken cDerives;

    cLowerLexerToken(const char *token, int len=-1) {
        if(token) SetLower(token,len);
    }
};

/**
 **********************************************************************
 *  Class: cLexerTokens
 *
 * Author: $author$
 *   Date: 8/25/2003
 **********************************************************************
 */
class cLexerTokens;
typedef cDynamicListT<cLexerToken> cLexerTokensExtends;
class cLexerTokens: public cLexerTokensExtends {
public:
    typedef cLexerTokensExtends cExtends;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _CLEXERTOKEN_HXX */
