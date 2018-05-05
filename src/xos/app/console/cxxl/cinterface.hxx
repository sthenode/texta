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
 *   File: cinterface.hxx
 *
 * Author: $author$
 *   Date: 11/13/2007, 5/2/2018
 **********************************************************************
 */
#ifndef _CINTERFACE_HXX
#define _CINTERFACE_HXX

#include "cbase.hxx"

#define c_INTERFACE_VERSION(major,minor) ((major)<<8)|(minor)
#define c_INTERFACE_VERSION_MAJOR(version) ((version)>>8)
#define c_INTERFACE_VERSION_MINOR(version) ((version)&255)

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cInterfaceBase
 *
 * Author: $author$
 *   Date: 1/9/2007
 **********************************************************************
 */
class c_INTERFACE_CLASS cInterfaceBase {
public:
    virtual ~cInterfaceBase() {
    }
};

/**
 **********************************************************************
 *  Class: cImplementBase
 *
 * Author: $author$
 *   Date: 3/22/2007
 **********************************************************************
 */
class cImplementBase: virtual public cInterfaceBase {
public:
    typedef cInterfaceBase cImplements;
    typedef cImplementBase cDerives;
};

/**
 **********************************************************************
 *  Class: cInstanceBase
 *
 * Author: $author$
 *   Date: 12/10/2017
 **********************************************************************
 */
class cInstanceBase: virtual public cImplementBase {
public:
    typedef cImplementBase cImplements;
    cInstanceBase() {
    }
    virtual ~cInstanceBase() {
    }
};

/**
 **********************************************************************
 *  Class: cInterface
 *
 * Author: $author$
 *   Date: 7/5/2003
 **********************************************************************
 */
class c_INTERFACE_CLASS cInterface: virtual public cInterfaceBase {
public:
    typedef cInterfaceBase cImplements;
    typedef cInterface cDerives;

    virtual eError HoldInstance()=0;
    virtual eError FreeInstance()=0;
    virtual eError DeleteInstance()=0;

    virtual eError SetLastError
    (eError error, const CHAR* description=0, TLENGTH length=-1)=0;
    virtual eError GetLastError
    (const CHAR*& description, TLENGTH &length) const=0;
};

/**
 **********************************************************************
 *  Class: cImplement
 *
 * Author: $author$
 *   Date: 7/5/2003
 **********************************************************************
 */
class cImplement: virtual public cInterface {
public:
    virtual eError HoldInstance() {
        return e_ERROR_NOT_ALLOWED;
    }
    virtual eError FreeInstance() {
        return e_ERROR_NOT_ALLOWED;
    }
    virtual eError DeleteInstance() {
        return e_ERROR_NOT_ALLOWED;
    }
    virtual eError SetLastError
    (eError error, const CHAR* description=0, TLENGTH length=-1) {
        return -e_ERROR_NOT_ALLOWED;
    }
    virtual eError GetLastError
    (const CHAR*& description, TLENGTH& length) const {
        return -e_ERROR_NOT_ALLOWED;
    }
};

/**
 **********************************************************************
 *  Class: cInterfaceInstance
 *
 * Author: $author$
 *   Date: 11/4/2008
 **********************************************************************
 */
class cInterfaceInstance: virtual public cImplement,  public cBase {
public:
    typedef cImplement cImplements;
    typedef cBase cExtends;
    typedef cInterfaceInstance cDerives;

    int m_holdInstance;

    cInterfaceInstance(int holdInstance=-1) 
    : m_holdInstance(holdInstance) {
    }
    virtual ~cInterfaceInstance()
    {
    }

    virtual eError HoldInstance() {
        if (0 <= m_holdInstance)
            m_holdInstance++;
        return e_ERROR_NONE;
    }
    virtual eError FreeInstance() {
        if (0 < m_holdInstance)
            --m_holdInstance;
        else
        if (!m_holdInstance)
            return DeleteInstance();
        return e_ERROR_NONE;
    }
    virtual eError DeleteInstance() {
        if (m_holdInstance)
            return e_ERROR_NOT_ALLOWED;
        return DeleteThis();
    }
    virtual eError DeleteThis() {
        return e_ERROR_NOT_ALLOWED;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _CINTERFACE_HXX */
