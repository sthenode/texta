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
 *   File: cattached.hxx
 *
 * Author: $author$
 *   Date: 3/13/2007, 5/3/2018
 **********************************************************************
 */
#ifndef _CATTACHED_HXX
#define _CATTACHED_HXX

#include "cinterface.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cAttachInterfaceT
 *
 * Author: $author$
 *   Date: 3/13/2007
 **********************************************************************
 */
template
<class TAttached=HANDLE, class TImplements=cInterfaceBase>

class c_INTERFACE_CLASS cAttachInterfaceT: virtual public TImplements {
public:
    virtual eError Attach
    (TAttached attached, bool onlyUnattached=false) = 0;
};
typedef cAttachInterfaceT<HANDLE,cInterfaceBase> cAttachInterface;

/**
 **********************************************************************
 *  Class: cAttachImplementT
 *
 * Author: $author$
 *   Date: 3/13/2007
 **********************************************************************
 */
template
<class TAttached=HANDLE, 
 class TImplement = cInterfaceBase,
 class TImplements=cAttachInterfaceT<TAttached, TImplement> >

class cAttachImplementT: virtual public TImplements {
public:
    virtual eError Attach
    (TAttached attached, bool onlyUnattached=false) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cDetachInterfaceT
 *
 * Author: $author$
 *   Date: 3/13/2007
 **********************************************************************
 */
template
<class TAttached=HANDLE, class TImplements=cInterfaceBase>

class c_INTERFACE_CLASS cDetachInterfaceT: virtual public TImplements {
public:
    virtual eError Detach
    (TAttached& attached, bool onlyAttached=false) = 0;
};
typedef cDetachInterfaceT<HANDLE,cInterfaceBase> cDetachInterface;

/**
 **********************************************************************
 *  Class: cDetachImplementT
 *
 * Author: $author$
 *   Date: 3/13/2007
 **********************************************************************
 */
template
<class TAttached=HANDLE, 
 class TImplement = cInterfaceBase,
 class TImplements=cDetachInterfaceT<TAttached, TImplement> >

class cDetachImplementT: virtual public TImplements {
public:
    virtual eError Detach
    (TAttached& attached, bool onlyAttached=false) 
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        return error;
    }
};

/**
 **********************************************************************
 *  Class: cAttachedInterfaceT
 *
 * Author: $author$
 *   Date: 3/26/2007
 **********************************************************************
 */
template
<class TAttached=HANDLE,
 class TUnAttached=INVALID_HANDLE_T,
 TUnAttached VUnattached=V_INVALID_HANDLE,
 class TImplement = cInterfaceBase,
 class TAttachImplements=cAttachInterfaceT<TAttached, TImplement>,
 class TDetachImplements=cDetachInterfaceT<TAttached, TImplement> >

class c_INTERFACE_CLASS cAttachedInterfaceT
: virtual public TAttachImplements, virtual public TDetachImplements {
public:
    typedef TAttached tAttached;
    typedef TUnAttached tUnattached;
    enum { vUnattached = VUnattached};
    
    virtual TAttached GetAttached() const = 0;
    virtual TAttached Attached() const = 0;
};

/**
 **********************************************************************
 *  Class: cAttachedImplementT
 *
 * Author: $author$
 *   Date: 3/5/2018
 **********************************************************************
 */
template
<class TAttached=HANDLE,
 class TUnAttached=INVALID_HANDLE_T,
 TUnAttached VUnattached=V_INVALID_HANDLE,
 class TImplement = cInterfaceBase,
 class TAttachInterface=cAttachInterfaceT<TAttached, TImplement>,
 class TDetachInterface=cDetachInterfaceT<TAttached, TImplement>,
 class TAttachImplements=cAttachImplementT<TAttached, TAttachInterface>,
 class TDetachImplements=cDetachImplementT<TAttached, TDetachInterface>,
 class TImplements=cAttachedInterfaceT
 <TAttached, TUnAttached, VUnattached, 
  TImplement, TAttachInterface, TDetachInterface> >

class c_INTERFACE_CLASS cAttachedImplementT
: virtual public TImplements, 
  virtual public TAttachImplements, 
  virtual public TDetachImplements {
public:
    virtual TAttached GetAttached() const 
    {
        return ((TAttached)VUnattached);
    }
    virtual TAttached Attached() const 
    {
        return ((TAttached)VUnattached);
    }
};

/**
 **********************************************************************
 *  Class: cAttachedT
 *
 * Author: $author$
 *   Date: 3/24/2007
 **********************************************************************
 */
template
<class TAttached=HANDLE,
 class TUnAttached=INVALID_HANDLE_T,
 TUnAttached VUnattached=V_INVALID_HANDLE,
 class TImplement = cInterfaceBase, class TExtend=cBase,
 class TAttachInterface=cAttachInterfaceT<TAttached, TImplement>,
 class TDetachInterface=cDetachInterfaceT<TAttached, TImplement>,
 class TAttachImplement=cAttachImplementT<TAttached, TAttachInterface>,
 class TDetachImplement=cDetachImplementT<TAttached, TDetachInterface>,
 class TAttachedInterface=cAttachedInterfaceT
 <TAttached, TUnAttached, VUnattached, 
  TImplement, TAttachInterface, TDetachInterface>,
 class TImplements=cAttachedImplementT
 <TAttached, TUnAttached, VUnattached, 
  TImplement, TAttachInterface, TDetachInterface, 
  TAttachImplement, TDetachImplement, TAttachedInterface>,
 class TExtends=TExtend>

class cAttachedT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef TAttached tAttached;

    TAttached m_attached;

    cAttachedT(TAttached attached=(TAttached)(VUnattached)) 
    : m_attached((TAttached)(VUnattached))
    {
        eError error;

        if ((TAttached)(VUnattached) != attached)
        if ((error = Attach(attached, true)))
            throw(error);
    }
    virtual ~cAttachedT()
    {
        eError error;
        TAttached attached;

        if ((TAttached)(VUnattached) != m_attached)
        if ((error = Detach(attached, true)))
            throw(error);
    }

    virtual eError Attach
    (TAttached attached, bool onlyUnattached=false) 
    {
        eError error = e_ERROR_NONE;

        if (onlyUnattached)
        if ((TAttached)(VUnattached) != m_attached)
            return e_ERROR_ALREADY_ATTACHED;

        m_attached = attached;
        return error;
    }
    virtual eError Detach
    (TAttached& attached, bool onlyAttached=false) 
    {
        eError error = e_ERROR_NONE;

        if (onlyAttached)
        if ((TAttached)(VUnattached) == m_attached)
            return e_ERROR_NOT_ATTACHED;

        attached = m_attached;
        m_attached = (TAttached)(VUnattached);
        return error;
    }

    virtual TAttached GetAttached() const 
    {
        return m_attached;
    }
    virtual TAttached Attached() const 
    {
        return m_attached;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _CATTACHED_HXX */
