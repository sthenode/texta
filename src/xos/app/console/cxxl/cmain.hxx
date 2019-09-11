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

#include "xos/app/console/main.hpp"
#include "xos/io/crt/file/reader.hpp"
#include "xos/io/crt/file/writer.hpp"
#include "xos/lib/texta/version.hpp"
#include "ccxxlexer.hxx"
#include "cstream.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cMainT
 *
 * Author: $author$
 *   Date: 5/4/2018
 **********************************************************************
 */
template 
<class TVersion = xos::lib::texta::version,
 class TExtends = xos::app::console::maint<TVersion>, 
 class TImplements = typename TExtends::implements>

class c_EXPORT_CLASS cMainT
: virtual public cCharStream, 
  virtual public cLexerSource, 
  virtual public cCXXLexerDelegate, 
  virtual public TImplements, public TExtends {
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cMainT cDerives;

    /**********************************************************************
     **********************************************************************/
    cMainT()
    : _lexerOut(*this), _lexerIn(*this), 
      _lexerSource(*this), _lexerDelegate(*this), 
      _lexer(_lexerDelegate, _lexerOut, _lexerIn, _lexerSource) {
    }
    virtual ~cMainT() {
    }
private:
    cMainT(const cMainT& copy)
    : _lexerOut(*this), _lexerIn(*this), 
      _lexerSource(*this), _lexerDelegate(*this), 
      _lexer(_lexerDelegate, _lexerOut, _lexerIn, _lexerSource) {
    }
    
protected:
    /**********************************************************************
     **********************************************************************/
    virtual int run(int argc, char_t **argv, char_t **env) {
        int err = 0;
        if (!(err = before_lexer_run(argc, argv, env))) {
            int err2 = 0;
            err = lexer_run(argc, argv, env);
            if ((err2 = after_lexer_run(argc, argv, env))) {
                if (!err) err = err2;
            }
        }
        return err;
    }
    virtual int lexer_run(int argc, char_t **argv, char_t **env) {
        int err = 0;
        OnBeforeAll();
        _lexer.yylex();
        OnAfterAll();
        return err;
    }
    virtual int before_lexer_run(int argc, char_t **argv, char_t **env) {
        int err = 0;
        if ((argc) && (optind < (argc)) && (argv)) {
            char_t *arg = 0;
            if ((arg = (argv[optind])) && (arg[0])) {
                if ((_fileReader.open(arg, _fileReader.text_mode()))) {
                    _read = &cDerives::FileRead;
                } else {
                    return 1;
                }
                if ((++optind < (argc)) && (arg = (argv[optind])) && (arg[0])) {
                    if ((_fileWriter.open_safe(arg, BeforeAll(), _fileWriter.text_mode()))) {
                        _write = &cDerives::FileWrite;
                    } else {
                        _fileReader.close();
                        return 1;
                    }
                }
            }
        }
        return err;
    }
    virtual int after_lexer_run(int argc, char_t **argv, char_t **env) {
        int err = 0;
        if ((_write == &cDerives::FileWrite)) {
            _fileWriter.close();
        }
        CloseReadFile();
        return err;
    }
    
    /**********************************************************************
     **********************************************************************/
    virtual bool OpenReadFile(const char *name) {
        if ((name) && (name[0])) {
            if ((_fileReader.open(name, _fileReader.text_mode()))) {
                _read = &cDerives::FileRead;
                return true;
            }
        }
        return false;
    }
    virtual bool CloseReadFile() {
        if ((_read == &cDerives::FileRead)) {
            _fileReader.close();
        }
        return true;
    }
    
    /**********************************************************************
     **********************************************************************/
    virtual eError OnBeforeAll() {
        eError error = e_ERROR_NONE;
        Out(BeforeAll());
        return error;
    }
    virtual eError OnAfterAll() {
        eError error = e_ERROR_NONE;
        Out(AfterAll());
        return error;
    }
    virtual const char* BeforeAll() const {
        const char* chars 
            = "<html><head><style type=\"text/css\">\n"
              "body { background-color: #ffffee; }\n"
              "a.include { color: maroon; text-decoration: underline; }\n"
              "font.include { color: maroon; }\n"
              "font.comment { color: green; font-style:italic; }\n"
              "font.commenteol { color: teal; font-style:italic; }\n"
              "font.processor { color: purple; font-weight: bolder; }\n"
              "font.keyword { color: blue; font-weight: bolder; }\n"
              "font.keywordx { color: purple; font-weight: bolder; }\n"
              "font.keywordy { color: purple; font-weight: bolder; }\n"
              "font.string { color: maroon; }\n"
              "font.char { color: red; }\n"
              "</style>\n"
              "<script type=\"text/JavaScript\">\n"
              "</script>\n"
              "</head><body><pre>";
        return chars;
    }
    virtual const char* AfterAll() const {
        const char* chars 
            = "</pre></body></html>\n";
        return chars;
    }

    /**********************************************************************
     **********************************************************************/
    virtual eError OnBeginComment
    (const char* text, int token=-1) {
        eError error = e_ERROR_NONE;
        Out("<font class=\"comment\">");
        Out(text);
        return error;
    }
    virtual eError OnEndComment
    (const char* text, int token=-1) {
        eError error = e_ERROR_NONE;
        Out(text);
        Out("</font>");
        return error;
    }

    /**********************************************************************
     **********************************************************************/
    virtual eError OnReserved
    (const char* text, int token=-1) {
        eError error = e_ERROR_NONE;
        Out("<font class=\"keyword\">");
        Out(text);
        Out("</font>");
        return error;
    }
    virtual eError OnReservedX
    (const char* text, int token=-1) {
        eError error = e_ERROR_NONE;
        Out("<font class=\"keywordx\">");
        Out(text);
        Out("</font>");
        return error;
    }
    virtual eError OnReservedY
    (const char* text, int token=-1) {
        eError error = e_ERROR_NONE;
        Out("<font class=\"keywordy\">");
        Out(text);
        Out("</font>");
        return error;
    }
    virtual eError OnString
    (const char* text, int token=-1) {
        eError error = e_ERROR_NONE;
        Out("<font class=\"string\">");
        OutString(text);
        Out("</font>");
        return error;
    }
    virtual eError OnChar
    (const char* text, int token=-1) {
        eError error = e_ERROR_NONE;
        Out("<font class=\"char\">");
        OutString(text);
        Out("</font>");
        return error;
    }
    virtual eError OnProcessor
    (const char* text, int token=-1) {
        eError error = e_ERROR_NONE;
        Out("<font class=\"processor\">");
        Out(text);
        Out("</font>");
        return error;
    }
    virtual eError OnIncludeL
    (const char* text, int token=-1) {
        eError error = e_ERROR_NONE;
        Out("<font class=\"include\">");
        Out(text);
        Out("</font>");
        return error;
    }
    virtual eError OnText(const char* text, int token=-1) {
        eError error = e_ERROR_NONE;
        Out(text);
        return error;
    }

    /**********************************************************************
     **********************************************************************/
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

    /**********************************************************************
     **********************************************************************/
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

    /**********************************************************************
     **********************************************************************/
    tLength (cDerives::*_read)(tWhat* what, tSize size);
    virtual tLength Read(tWhat* what, tSize size) {
        tLength length = 0;
        if ((this->_read)) {
            length = (this->*_read)(what, size);
        } else {
            length = InRead(what, size);
        }
        return length;
    }
    virtual tLength InRead(tWhat* what, tSize size) {
        tLength length = this->in(what, size);
        return length;
    }
    virtual tLength FileRead(tWhat* what, tSize size) {
        tLength length = _fileReader.read(what, size);
        return length;
    }

    /**********************************************************************
     **********************************************************************/
    tLength (cDerives::*_write)(const tWhat* what, tLength length);
    virtual tLength Write(const tWhat* what, tLength length) {
        tLength count = 0;
        if (this->_write) {
            count = (this->*_write)(what, length);
        } else {
            count = OutWrite(what, length);
        }
        return count;
    }
    virtual tLength OutWrite(const tWhat* what, tLength length) {
        tLength count = 0;
        if (0 < (length)) {
            count = this->out(what, length);
        } else {
            if (0 > (length)) {
                count = this->out(what);
            }
        }
        this->out_flush();
        return count;
    }
    virtual tLength FileWrite(const tWhat* what, tLength length) {
        tLength count = 0;
        if (0 < (length)) {
            count = _fileWriter.write(what, length);
        } else {
            if (0 > (length)) {
                count = _fileWriter.write(what);
            }
        }
        return count;
    }
    virtual tLength Out(const tWhat* what) {
        tLength count = Write(what, vUndefinedLength);
        return count;
    }
    virtual tLength OutString(const tWhat* what) {
        tLength count = 0, amount = 0;
        tWhat w[2];
        for (w[1] = 0, w[0] = *what; w[0]; w[0] = *(++what)) {
            switch (w[0]) {
            case '<':
                if (0 < (amount = Out("&lt;"))) {
                    count += amount;
                }
                break;
            case '>':
                if (0 < (amount = Out("&gt;"))) {
                    count += amount;
                }
                break;
            case '&':
                if (0 < (amount = Out("&amp;"))) {
                    count += amount;
                }
                break;
            default:
                if (0 < (amount = Out(w))) {
                    count += amount;
                }
            }
        }
        return count;
    }

    /**********************************************************************
     **********************************************************************/
protected:
    cCharStream &_lexerOut, &_lexerIn;
    cLexerSource &_lexerSource;
    cCXXLexerDelegate &_lexerDelegate;
    cCXXLexer _lexer;
    xos::io::crt::file::char_reader _fileReader;
    xos::io::crt::file::char_writer _fileWriter;
}; /* class c_EXPORT_CLASS cMainT */

typedef cMainT<> cMain;

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _CMAIN_HXX */
