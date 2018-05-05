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
 *   File: clist.hxx
 *
 * Author: $author$
 *   Date: 1/26/2007, 5/3/2018
 **********************************************************************
 */
#ifndef _CLIST_HXX
#define _CLIST_HXX

#include "cbase.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cListItemT
 *
 * Author: $author$
 *   Date: 2/1/2007
 **********************************************************************
 */
template
<class TDerives, class TExtends=cBase>

class cListItemT: public TExtends {
public:
    typedef TExtends cExtends;
    typedef TDerives cDerives;

    TDerives *m_prevItem, *m_nextItem;

    cListItemT(TDerives *prevItem=0, TDerives *nextItem=0)
    :m_prevItem(prevItem),
     m_nextItem(nextItem) 
    {
    }
    virtual ~cListItemT()
    {
    }

    TDerives *GetPrevItem() const
    {
        return m_prevItem;
    }
    TDerives *GetNextItem() const
    {
        return m_nextItem;
    }
};

/**
 **********************************************************************
 *  Class: cListT
 *
 * Author: $author$
 *   Date: 1/26/2007
 **********************************************************************
 */
template
<class TItem,  class TExtends=cBase>

class cListT: public TExtends {
public:
    typedef TExtends cExtends;

	TItem *m_firstItem, *m_lastItem;

    cListT(TItem* firstItem=0, TItem* lastItem=0)
    : m_firstItem(firstItem),
      m_lastItem(lastItem) 
    {
    }
    virtual ~cListT()
    {
    }

#include "clist_members.hxx"
};

/**
 **********************************************************************
 *  Class: cStaticListT
 *
 * Author: $author$
 *   Date: 1/26/2007
 **********************************************************************
 */
template
<class TItem,  class TExtends=cBase>

class cStaticListT: public TExtends {
public:
    typedef TExtends cExtends;

	static TItem *m_firstItem, *m_lastItem;

    cStaticListT() 
    {
    }
    virtual ~cStaticListT()
    {
    }

#include "clist_members.hxx"
};

/**
 **********************************************************************
 *  Class: cDynamicListItemT
 *
 * Author: $author$
 *   Date: 7/13/2003
 **********************************************************************
 */
template 
<class TDerives, class TExtend=cBase, 
 class TExtends=cListItemT<TDerives, TExtend> >

class cDynamicListItemT: public TExtends {
public:
    typedef TExtends cExtends;

    bool m_is_static, m_is_persistant;

    cDynamicListItemT
    (bool is_static=false, bool is_persistant=false, 
     TDerives *previous=0, TDerives *next=0)
    : cExtends(previous, next),
      m_is_static(is_static),
      m_is_persistant(is_persistant)
    {
    }

    bool SetIsStatic(bool is_static=true)
    {
        m_is_static=is_static;
        return m_is_static;
    }
    bool GetIsStatic() const
    {
        return m_is_static;
    }

    bool SetIsPersistant(bool is_persistant=true)
    {
        m_is_persistant=is_persistant;
        return m_is_persistant;
    }
    bool GetIsPersistant() const
    {
        return m_is_persistant;
    }
};

/**
 **********************************************************************
 *  Class: cDynamicListT
 *
 * Author: $author$
 *   Date: 7/13/2003
 **********************************************************************
 */
template 
<class TItem, class TExtend=cBase, 
 class TExtends=cListT<TItem, TExtend> >

class cDynamicListT: public TExtends {
public:
    typedef TExtends cExtends;

    bool m_is_static;

    cDynamicListT
    (bool is_static=false,
     TItem *first=0,TItem *last=0)
    : cExtends(first,last),
      m_is_static(is_static) 
    {
    }
    virtual ~cDynamicListT()
    {
        Destruct();
    }
    virtual void Destruct()
    {
        eError error;

        if ((error=Clear()))
            throw(error);
    }

    virtual eError Clear()
    {
        eError error;
        TItem *item,*previous;

        if (m_is_static)
            CTHIS m_firstItem = CTHIS m_lastItem = 0;

        else for (item = CTHIS m_lastItem; item; item=previous)
        {
            previous=item->m_prevItem;

            if (!item->m_is_persistant)
            {
                CTHIS DeleteItem(*item);

                if (!item->m_is_static)
                if ((error=FreeItem(*item)))
                    return e_ERROR_FREE;
            }
        }
        return e_ERROR_NONE;
    }
    virtual eError FreeItem(TItem& item)
    {
        delete &item;
        return e_ERROR_NONE;
    }

    inline bool SetIsStatic(bool is_static=true)
    {
        m_is_static=is_static;
        return m_is_static;
    }
    inline bool GetIsStatic() const
    {
        return m_is_static;
    }
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _CLIST_HXX */
