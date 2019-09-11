/**
 **********************************************************************
 * Copyright (c) 1988-2019 $organization$
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
 *   File: ccgimain.hxx
 *
 * Author: $author$
 *   Date: 9/11/2019
 **********************************************************************
 */
#ifndef _CCGIMAIN_HXX
#define _CCGIMAIN_HXX

#include "xos/app/console/cgi/main.hpp"
#include "cmain.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cCGIMainT
 *
 * Author: $author$
 *   Date: 9/11/2019
 **********************************************************************
 */
template 
<class TVersion = xos::lib::texta::version,
 class TExtends = cMainT<TVersion, xos::app::console::cgi::maint<TVersion> >, 
 class TImplements = typename TExtends::implements>

class c_EXPORT_CLASS cCGIMainT: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef cCGIMainT derives;

    /**********************************************************************
     **********************************************************************/
    cCGIMainT() {
    }
    virtual ~cCGIMainT() {
    }
private:
    cCGIMainT(const cCGIMainT &copy) {
    }

    /**********************************************************************
     **********************************************************************/
    virtual int run(int argc, char_t **argv, char_t **env) {
        int err = 0;
        err = this->gateway_console_run(argc, argv, env);
        return err;
    }
    virtual int console_gateway_run(int argc, char_t **argv, char_t **env) {
        int err = 0, err2 = 0;
        if (!(err2 = this->before_lexer_run(argc, argv, env))) {
            err = this->lexer_run(argc, argv, env);
            if ((err2 = this->after_lexer_run(argc, argv, env))) {
                if (!err) err = err2;
            }
        }
        return err;
    }
    
    /**********************************************************************
     **********************************************************************/
    virtual int before_lexer_run(int argc, char_t **argv, char_t **env) {
        int err = 1;
        size_t length = 0;
        const char *chars = 0;
        xos::protocol::http::cgi::environment::variable::value* value = 0;

        if (value = (this->environment_values().value(xos::protocol::http::cgi::environment::variable::PATH_TRANSLATED))) {
            if ((chars = value->has_chars(length))) {
                if ((this->OpenReadFile(chars))) {
                    if (!(this->content_type())) {
                        this->set_content_type_html();
                    }
                    return 0;
                } else {
                    this->outlln("...failed to open file \"", chars, "\"", NULL);
                    return err;
                }
            } else {
                this->outlln("...environment variable PATH_TRANSLATED = \"\"", NULL);
            }
        } else {
            this->outlln("...environment variable PATH_TRANSLATED missing", NULL);
        }
        return err;
    }
    virtual int after_lexer_run(int argc, char_t **argv, char_t **env) {
        int err = 0;
        this->CloseReadFile();
        return err;
    }

    /**********************************************************************
     **********************************************************************/
}; /* class c_EXPORT_CLASS cCGIMainT */
typedef cCGIMainT<> cCGIMain;

#if defined(c_NAMESPACE)
} /* namespace c_NAMESPACE */
#endif /* defined(c_NAMESPACE) */

#endif /* _CCGIMAIN_HXX */
