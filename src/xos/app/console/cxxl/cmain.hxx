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
 *   File: cmain.hxx
 *
 * Author: $author$
 *   Date: 5/4/2018
 **********************************************************************
 */
#ifndef _CMAIN_HXX
#define _CMAIN_HXX

#include "xos/console/getopt/main.hpp"
#include "ccxxlexer.hxx"
#include "cstream.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cMain
 *
 * Author: $author$
 *   Date: 5/4/2018
 **********************************************************************
 */
typedef xos::console::getopt::main::implements cMainImplements;
typedef xos::console::getopt::main cMainExtends;
class c_EXPORT_CLASS cMain
: virtual public cCharStream, 
  virtual public cLexerSource, 
  virtual public cCXXLexerDelegate, 
  virtual public cMainImplements, public cMainExtends {
public:
    typedef cMainImplements cImplements;
    typedef cMainExtends cExtends;

    cMain()
    : _lexerOut(*this), _lexerIn(*this), 
      _lexerSource(*this), _lexerDelegate(*this), 
      _lexer(_lexerDelegate, _lexerOut, _lexerIn, _lexerSource) {
    }
    virtual ~cMain() {
    }
    
protected:
    int run(int argc, char_t **argv, char_t **env) {
        int err = 0;
        OnBeforeAll();
        _lexer.yylex();
        OnAfterAll();
        return err;
    }
    
    virtual eError OnBeforeAll() {
        eError error = e_ERROR_NONE;
        this->out
        ("<html><head><style type=\"text/css\">"
         "body { background-color: #ffffee; }"
         "a.include {color: maroon; text-decoration: underline; }"
         "font.include {color: maroon; }"
         "font.comment {color: green; font-style:italic; }"
         "font.commenteol {color: teal; font-style:italic; }"
         "font.processor {color: purple; font-weight: bolder; }"
         "font.keyword {color: blue; font-weight: bolder; }"
         "font.keywordx {color: purple; font-weight: bolder; }"
         "font.keywordy {color: purple; font-weight: bolder; }"
         "font.string {color: maroon; }"
         "font.char {color: red; }"
         "</style>"
         "<script type=\"text/JavaScript\">"
         "</script>"
         "</head><body><pre>");
        return error;
    }
    virtual eError OnAfterAll() {
        eError error = e_ERROR_NONE;
        this->out("</pre></body></html>");
        return error;
    }

    virtual eError OnBeginComment
    (const char* text, int token=-1) {
        eError error = e_ERROR_NONE;
        this->out("<font class=\"comment\">");
        this->out(text);
        return error;
    }
    virtual eError OnEndComment
    (const char* text, int token=-1) {
        eError error = e_ERROR_NONE;
        this->out(text);
        this->out("</font>");
        return error;
    }
    virtual eError OnReserved
    (const char* text, int token=-1) {
        eError error = e_ERROR_NONE;
        this->out("<font class=\"keyword\">");
        this->out(text);
        this->out("</font>");
        return error;
    }
    virtual eError OnString
    (const char* text, int token=-1) {
        eError error = e_ERROR_NONE;
        this->out("<font class=\"string\">");
        this->out(text);
        this->out("</font>");
        return error;
    }
    virtual eError OnChar
    (const char* text, int token=-1) {
        eError error = e_ERROR_NONE;
        this->out("<font class=\"char\">");
        this->out(text);
        this->out("</font>");
        return error;
    }
    virtual eError OnProcessor
    (const char* text, int token=-1) {
        eError error = e_ERROR_NONE;
        this->out("<font class=\"processor\">");
        this->out(text);
        this->out("</font>");
        return error;
    }
    virtual eError OnIncludeL
    (const char* text, int token=-1) {
        eError error = e_ERROR_NONE;
        this->out("<font class=\"include\">");
        this->out(text);
        this->out("</font>");
        return error;
    }
    virtual eError OnText(const char* text, int token=-1) {
        eError error = e_ERROR_NONE;
        this->out(text);
        return error;
    }

    virtual eError OnLT(const char* text, int token=-1) {
        eError error = e_ERROR_NONE;
        error = OnText("&lt;", token);
        return error;
    }
    virtual eError OnGT(const char* text, int token=-1) {
        eError error = e_ERROR_NONE;
        error = OnText("&gt;", token);
        return error;
    }
    virtual eError OnAMP(const char* text, int token=-1) {
        eError error = e_ERROR_NONE;
        error = OnText("&amp;", token);
        return error;
    }

    virtual cCharStreamInterface* OpenFile(eError &error, const char *filename) {
        error = e_ERROR_NOT_IMPLEMENTED;
        return 0;
    }
    virtual cCharStreamInterface* OpenURI(eError &error, const char *uri) {
        error = e_ERROR_NOT_IMPLEMENTED;
        return 0;
    }
    virtual eError Close(cCharStreamInterface& stream) {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }

    virtual tLength Read(tWhat* what, tSize size) {
        tLength length = 0;
        length = this->in(what, size);
        return length;
    }
    virtual tLength Write(const tWhat* what, tLength length) {
        tLength count = 0;
        if (0 < (length)) {
            count = this->out(what, length);
        } else {
            if (0 > (length)) {
                count = this->out(what);
            } else {
            }
        }
        return count;
    }

protected:
    cCharStream &_lexerOut, &_lexerIn;
    cLexerSource &_lexerSource;
    cCXXLexerDelegate &_lexerDelegate;
    cCXXLexer _lexer;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _CMAIN_HXX */
