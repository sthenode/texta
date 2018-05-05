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
 *   File: cfile.hxx
 *
 * Author: $author$
 *   Date: 3/5/2008, 5/3/2018
 **********************************************************************
 */
#ifndef _CFILE_HXX
#define _CFILE_HXX

#include "cattached.hxx"
#include "cstream.hxx"
#include "cdebug.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

typedef FILE* FILEAttached;

typedef cBase cFILEExtendBase;
typedef cImplementBase cFILEImplementBase;

typedef cAttachInterfaceT<FILEAttached, cFILEImplementBase> cFILEAttachInterface;
typedef cDetachInterfaceT<FILEAttached, cFILEImplementBase> cFILEDetachInterface;
typedef cAttachImplementT<FILEAttached, cFILEAttachInterface> cFILEAttachImplement;
typedef cDetachImplementT<FILEAttached, cFILEDetachInterface> cFILEDetachImplement;
typedef cDetachInterfaceT<FILEAttached, cImplementBase> cFILEDetachInterface;

typedef cAttachedInterfaceT
<FILEAttached, int, 0, cFILEImplementBase, 
 cFILEAttachInterface, cFILEDetachInterface> cFILEAttachedInterface;

typedef cAttachedImplementT
<FILEAttached, int, 0, cFILEImplementBase,
 cFILEAttachInterface, cFILEDetachInterface,
 cFILEAttachImplement, cFILEDetachImplement, 
 cFILEAttachedInterface> cFILEAttachedImplement;

typedef cAttachedT
<FILEAttached, int, 0, 
 cFILEImplementBase, cFILEExtendBase,
 cFILEAttachInterface, cFILEDetachInterface,
 cFILEAttachImplement, cFILEDetachImplement, 
 cFILEAttachedInterface, cFILEAttachedImplement> cFILEAttached;

/**
 **********************************************************************
 *  Class: cFILEStreamT
 *
 * Author: $author$
 *   Date: 3/5/2008
 **********************************************************************
 */
template 
<class TImplement = cStreamImplement, class TExtend = cStream,
 class TImplements = cAttachedImplementT
 <FILEAttached, int, 0, TImplement, 
  cFILEAttachInterface, cFILEDetachInterface, 
  cFILEAttachImplement, cFILEDetachImplement, cFILEAttachedInterface>,
 class TExtends = cAttachedT
 <FILEAttached, int, 0, 
  TImplement, TExtend,
  cFILEAttachInterface, cFILEDetachInterface,
  cFILEAttachImplement, cFILEDetachImplement, 
  cFILEAttachedInterface, TImplements> >
class cFILEStreamT: virtual public TImplements, public TExtends {
public:
    typedef TImplement cImplement;
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cFILEStreamT cDerives;

    typedef typename cImplement::tWhat tWhat;
    typedef typename cImplement::tSize tSize;
    typedef typename cImplement::tLength tLength;
    enum { vUndefinedLength = cImplement::vUndefinedLength };

    typedef typename cImplements::tAttached tAttached;
    typedef typename cImplements::tUnattached tUnattached;
    enum { vUnattached = cImplements::vUnattached};

    cFILEStreamT(FILE* attached): cExtends(attached) {
    }
    cFILEStreamT() {
    }
    virtual ~cFILEStreamT() {
    }

    virtual eError Open
    (const char* filename, const char* filemode="r", bool onlyClosed=false) {
        eError error = e_ERROR_FAILED;
        eError error2;
        FILE* attached;
        bool opened;

        if ((opened = (((tAttached)vUnattached) != (attached = this->Attached()))))
        if (onlyClosed)
            error = e_ERROR_ALREADY_ATTACHED;
        else
        if ((error2 = Close(opened)))
            return error2;

        if ((opened = (((tAttached)vUnattached) != (attached = FOpen(filename, filemode)))))
        if ((error = this->Attach(attached)))
            FClose(attached);
        return error;
    }
    virtual eError Close(bool onlyOpen=false) {
        eError error = e_ERROR_FAILED;
        FILE* attached;
        bool opened;
        int err;

        if (!(opened = (((tAttached)vUnattached) != (attached = this->Attached()))))
        if (onlyOpen)
            error = e_ERROR_NOT_ATTACHED;
        else
        return e_ERROR_NONE;

        if (!(err = FClose(attached)))
            error = this->Detach(attached);
        return error;
    }

    virtual tLength Write(const tWhat* what, tLength length = vUndefinedLength) {
        tLength count = 0;
        size_t amount;
        FILE* attached;

        if (((tAttached)vUnattached) == (attached = this->Attached()))
            count = -e_ERROR_NOT_ATTACHED;
        else
        if (0 > length)
            for (count = 0; *what != 0; what++, count += length)
            {
                if (0 > (length = Write(what, 1)))
                    return length;
            }
        else
        if (0 < (amount = (size_t)(length)))
        if (length <= (tLength)(amount = FWrite
            (what, sizeof(tWhat), amount, attached)))
            count = length;
        else count = -e_ERROR_WRITE;
        return count;
    }
    virtual tLength Read(tWhat* what, tSize size) {
        tLength count = 0;
        size_t amount;
        FILE* attached;

        if (((tAttached)vUnattached) == (attached = this->Attached()))
            count = -e_ERROR_NOT_ATTACHED;
        else
        if (0 < (amount = (size_t)(size)))
        if (size <= (tSize)(amount = FRead
            (what, sizeof(tWhat), amount, attached)))
            count = (tLength)(size);
        else count = -e_ERROR_READ;
        return count;
    }

    virtual tLength FWrite
    (const tWhat* what, tSize size, tSize length, tAttached attached) const {
        tLength count = 0;
        if ((what) && (size) && (length) && (((tAttached)vUnattached) !=attached)) {
            if (length > (count = ::fwrite(what, size, length, attached))) {
                DBE(("...failed on ::fwrite(what, size = %lu, length = %lu, attached)", size, length));
                count = -e_ERROR_READ;
            }
        }
        return count;
    }
    virtual tLength FRead
    (tWhat* what, tSize size, tSize length, tAttached attached) const {
        tLength count = 0;
        if ((what) && (size) && (length) && (((tAttached)vUnattached) != attached)) {
            if (length > (count = ::fread(what, size, length, attached))) {
                DBE(("...failed on ::fread(what, size = %lu, length = %lu, attached)", size, length));
                count = -e_ERROR_READ;
            }
        }
        return count;
    }

    virtual tAttached FOpen(const char* filename, const char* filemode) const {
        tAttached attached = 0;
        if ((filename) && (filemode)) {
            DBF(("::fopen(filename = \"%s\", filemode = \"%s\"...)", filename, filemode));
            if (!(attached = ::fopen(filename, filemode))) {
                DBE(("...failed on ::fopen(filename = \"%s\", filemode = \"%s\")", filename, filemode));
                attached = ((tAttached)vUnattached);
            }
        }
        return attached;
    }
    virtual tLength FClose(tAttached attached) const {
        tLength count = 0;
        if (((tAttached)vUnattached) != (attached)) {
            DBF(("::fclose(attached)..."));
            if (0 < (count = ::fclose(attached))) {
                DBE(("...failed on ::fclose(attached)"));
                count = -e_ERROR_CLOSE;
            }
        }
        return count;
    }
};

typedef cFILEStreamT
<cCHARStreamImplement, cCHARStream> 
cCHARFILEStream, cCharFILEStream, cFILEStream;

typedef cFILEStreamT
<cTCHARStreamImplement, cTCHARStream> 
cTCHARFILEStream, cTFILEStream;

typedef cFILEStreamT
<cWCHARStreamImplement, cWCHARStream> 
cWCHARFILEStream, cWFILEStream;

/**
 **********************************************************************
 *  Class: cFileT
 *
 * Author: $author$
 *   Date: 3/5/2008
 **********************************************************************
 */
template 
<class TImplements=cFILEStream::cImplements, class TExtends=cFILEStream>
 
class cFileT: public TExtends {
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cFileT cDerives;
    
    cFileT(FILE* attached): cExtends(attached) {
    }
    cFileT() {
    }
};

typedef cFileT
<cCHARFILEStream::cImplements, cCHARFILEStream> 
cCHARFile, cCharFile, cFile;

typedef cFileT
<cTCHARFILEStream::cImplements, cTCHARFILEStream> 
cTCHARFile, cTFile;

typedef cFileT
<cWCHARFILEStream::cImplements, cWCHARFILEStream> 
cWCHARFile, cWFile;

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _CFILE_HXX */
