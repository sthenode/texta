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
 *   File: cstream.hxx
 *
 * Author: $author$
 *   Date: 12/24/2008, 5/2/2018
 **********************************************************************
 */
#ifndef _CSTREAM_HXX
#define _CSTREAM_HXX

#include "creader.hxx"
#include "cwriter.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cStreamInterfaceT
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
template
<class TWhat=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TImplementsReader=cReaderInterfaceT<TWhat, TSize, TLength, VUndefinedLength>,
 class TImplementsWriter=cWriterInterfaceT<TWhat, TSize, TLength, VUndefinedLength> >

class c_INTERFACE_CLASS cStreamInterfaceT
: virtual public TImplementsReader, virtual public TImplementsWriter {
public:
    typedef TImplementsReader cImplementsReader;
    typedef TImplementsWriter cImplementsWriter;

    typedef TWhat tWhat;
    typedef TSize tSize;
    typedef TLength tLength;
    enum { vUndefinedLength = VUndefinedLength };

    virtual TLength WriteReader
    (TImplementsReader& reader,
     TLength length=VUndefinedLength) = 0;
    virtual TImplementsReader& GetReader() const = 0;
    virtual TImplementsWriter& GetWriter() const = 0;
};

typedef cStreamInterfaceT
<CHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 cCHARReaderInterface, cCHARWriterInterface>
cCHARStreamInterface,
cStreamInterface;

typedef cStreamInterfaceT
<TCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 cTCHARReaderInterface, cTCHARWriterInterface>
cTCHARStreamInterface,
cTStreamInterface;

typedef cStreamInterfaceT
<WCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH,
 cWCHARReaderInterface, cWCHARWriterInterface>
cWCHARStreamInterface,
cWStreamInterface;

class cCharStreamInterface: virtual public cCHARStreamInterface {
public:
    typedef cCHARStreamInterface cImplements;
};

/**
 **********************************************************************
 *  Class: cStreamImplementT
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
template
<class TWhat=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TImplementsReader=cReaderInterfaceT<TWhat, TSize, TLength, VUndefinedLength>,
 class TImplementsWriter=cWriterInterfaceT<TWhat, TSize, TLength, VUndefinedLength>,
 class TImplements=cStreamInterfaceT
 <TWhat, TSize, TLength, VUndefinedLength, TImplementsReader, TImplementsWriter>, 
 class TReaderImplement=cReaderImplementT
 <TWhat, TSize, TLength, VUndefinedLength, TImplementsReader>,
 class TWriterImplement=cWriterImplementT
 <TWhat, TSize, TLength, VUndefinedLength, TImplementsWriter> >

class cStreamImplementT
: virtual public TReaderImplement,
  virtual public TWriterImplement,
  virtual public TImplements {
public:
    typedef TImplements cImplements;

    virtual TLength WriteReader
    (TImplementsReader& reader,
     TLength length=VUndefinedLength) {
        TLength count = 0;
        TLength count2;
        TWhat what;

        if ((0 <= length) && (length != VUndefinedLength))
        while (count < length)
        {
            if (0 > (count2 = reader.Read(&what, 1)))
                break;
            else
            if (0 > (count2 = this->Write(&what, 1)))
                return count2;
            else
            count += count2;
        }
        else
        while (0 < (count2 = reader.Read(&what, 1)))
        {
            if (0 > (count2 = this->Write(&what, 1)))
                return count2;
            else
            count += count2;
        }
        return count;
    }
    virtual TImplementsReader& GetReader() const {
        return *(TImplementsReader*)(this);
    }
    virtual TImplementsWriter& GetWriter() const {
        return *(TImplementsWriter*)(this);
    }
};

typedef cStreamImplementT
<CHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
 cCHARReaderInterface, cCHARWriterInterface, 
 cCHARStreamInterface, cCHARReaderImplement, cCHARWriterImplement>
cCHARStreamImplement,
cStreamImplement;

typedef cStreamImplementT
<TCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
 cTCHARReaderInterface, cTCHARWriterInterface, 
 cTCHARStreamInterface, cTCHARReaderImplement, cTCHARWriterImplement>
cTCHARStreamImplement,
cTStreamImplement;

typedef cStreamImplementT
<WCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
 cWCHARReaderInterface, cWCHARWriterInterface, 
 cWCHARStreamInterface, cWCHARReaderImplement, cWCHARWriterImplement>
cWCHARStreamImplement,
cWStreamImplement;

typedef cStreamImplementT
<CHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
 cCHARReaderInterface, cCHARWriterInterface, 
 cCharStreamInterface, cCHARReaderImplement, cCHARWriterImplement>
cCharStreamImplementImplement;

class cCharStreamImplement: virtual public cCharStreamImplementImplement {
public:
    typedef cCharStreamImplementImplement cImplements;
};

/**
 **********************************************************************
 *  Class: cStreamT
 *
 * Author: $author$
 *   Date: 1/16/2008
 **********************************************************************
 */
template
<class TWhat=CHAR,
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 class TImplements=cStreamImplement,
 class TExtends=cBase>
 
class cStreamT
: virtual public TImplements, public TExtends {
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cStreamT cDerives;

    cStreamT() {
    }
    virtual ~cStreamT() {
    }
};

typedef cStreamT
<CHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
 cCHARStreamImplement, cBase>
cCHARStream, cStream;

typedef cStreamT
<TCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
 cTCHARStreamImplement, cBase>
cTCHARStream, cTStream;

typedef cStreamT
<WCHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
 cWCHARStreamImplement, cBase>
cWCHARStream, cWStream;

typedef cStreamT
<CHAR, TSIZE, TLENGTH, UNDEFINED_LENGTH, 
 cCharStreamImplement, cBase>
cCharStreamExtend;

class cCharStream: public cCharStreamExtend {
public:
    typedef cCharStreamExtend cExtends;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _CSTREAM_HXX */
