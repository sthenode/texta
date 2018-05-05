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
 *   File: clexersource.hxx
 *
 * Author: $author$
 *   Date: 5/2/2008, 5/4/2018
 **********************************************************************
 */
#ifndef _CLEXERSOURCE_HXX
#define _CLEXERSOURCE_HXX

#include "clist.hxx"
#include "cfile.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cLexerSource
 *
 * Author: $author$
 *   Date: 3/3/2004
 **********************************************************************
 */
class cLexerSource {
public:
    virtual cCharStreamInterface* OpenFile(eError &error, const char *filename) {
        error=e_ERROR_NOT_IMPLEMENTED;
        return 0;
    }
    virtual cCharStreamInterface* OpenURI(eError &error, const char *uri) {
        error=e_ERROR_NOT_IMPLEMENTED;
        return 0;
    }
    virtual eError Close(cCharStreamInterface& stream) {
        eError error=e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cLexerInclude
 *
 * Author: $author$
 *   Date: 8/25/2003
 **********************************************************************
 */
class cLexerInclude;
typedef cDynamicListItemT<cLexerInclude> cLexerIncludeExtend;
class cLexerInclude: public cLexerIncludeExtend {
public:
    typedef cLexerIncludeExtend cExtends;

    cLexerSource &m_source;
    cCharStreamInterface& m_stream;
    void *m_state;

    cLexerInclude(cLexerSource &source, cCharStreamInterface& stream)
    : m_source(source), m_stream(stream) {
    }
    virtual ~cLexerInclude() {
        eError error = e_ERROR_FAILED;
        if ((error = m_source.Close(m_stream))) {
            DBE(("...failed on m_source.Close(m_stream) throw (error = %d)...", error));
            throw (error);
        }
    }
};

/**
 **********************************************************************
 *  Class: cLexerIncludes
 *
 * Author: $author$
 *   Date: 8/25/2003
 **********************************************************************
 */
typedef cDynamicListT<cLexerInclude> cLexerIncludesExtend;
class cLexerIncludes: public cLexerIncludesExtend {
public:
    typedef cLexerIncludesExtend cExtends;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _CLEXERSOURCE_HXX */
