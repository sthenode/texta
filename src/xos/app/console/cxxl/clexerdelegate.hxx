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
 *   File: clexerdelegate.hxx
 *
 * Author: $author$
 *   Date: 7/8/2008, 5/4/2018
 **********************************************************************
 */
#ifndef _CLEXERDELEGATE_HXX
#define _CLEXERDELEGATE_HXX

#include "cerror.hxx"
#include "cdebug.hxx"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif /* defined(c_NAMESPACE) */

/**
 **********************************************************************
 *  Class: cLexerDelegateT
 *
 * Author: $author$
 *   Date: 7/8/2008
 **********************************************************************
 */
template <class TDerives>
class cLexerDelegateT {
public:
    typedef TDerives cDelegate;

    virtual eError OnCharToken
    (const char* text, int token=-1,
     int beginchars=1, int endchars=1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCharToken
            (text, token, beginchars, endchars);
        else
        {
            if (0 > beginchars) beginchars = 1;
            if (0 > endchars) endchars = 1;
            error = OnToken
            (text, token, beginchars, endchars);
        }
        return error;
    }
    virtual eError OnStringToken
    (const char* text, int token=-1,
     int beginchars=1, int endchars=1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnStringToken
            (text, token, beginchars, endchars);
        else
        {
            if (0 > beginchars) beginchars = 1;
            if (0 > endchars) endchars = 1;
            error = OnToken
            (text, token, beginchars, endchars);
        }
        return error;
    }
    virtual eError OnIntegerToken
    (const char* text, int token=-1,
     int beginchars=0, int endchars=0) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnIntegerToken
            (text, token, beginchars, endchars);
        else
        {
            error = OnToken
            (text, token, beginchars, endchars);
        }
        return error;
    }
    virtual eError OnRealToken
    (const char* text, int token=-1,
     int beginchars=0, int endchars=0) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnRealToken
            (text, token, beginchars, endchars);
        else
        {
            error = OnToken
            (text, token, beginchars, endchars);
        }
        return error;
    }
    virtual eError OnIdentifierToken
    (const char* text, int token=-1,
     int beginchars=0, int endchars=0) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnIdentifierToken
            (text, token, beginchars, endchars);
        else
        {
            error = OnToken
            (text, token, beginchars, endchars);
        }
        return error;
    }
    virtual eError OnToken
    (const char* text, int token=-1,
     int beginchars=0, int endchars=0) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnToken
            (text, token, beginchars, endchars);
        return error;
    }

    virtual eError OnBeginRuleComment
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginRuleComment(text, token);
        return error;
    }
    virtual eError OnEndRuleComment
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndRuleComment(text, token);
        return error;
    }
    virtual eError OnRuleCommentText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnRuleCommentText(text, token);
        return error;
    }
    virtual eError OnBeginRuleT
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginRuleT(text, token);
        return error;
    }
    virtual eError OnEndRuleT
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndRuleT(text, token);
        return error;
    }
    virtual eError OnRuleT
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnRuleT(text, token);
        return error;
    }
    virtual eError OnBeginRuleL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginRuleL(text, token);
        return error;
    }
    virtual eError OnEndRuleL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndRuleL(text, token);
        return error;
    }
    virtual eError OnAndRuleL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnAndRuleL(text, token);
        return error;
    }
    virtual eError OnOrRuleL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnOrRuleL(text, token);
        return error;
    }
    virtual eError OnRuleL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnRuleL(text, token);
        return error;
    }

    virtual eError OnRuleLString
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnRuleLString(text, token);
        return error;
    }
    virtual eError OnRuleLChar
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnRuleLChar(text, token);
        return error;
    }
    virtual eError OnRuleText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnRuleText(text, token);
        return error;
    }

    virtual eError OnBeginComment
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginComment(text, token);
        else error = OnBegin(text, token);
        return error;
    }
    virtual eError OnEndComment
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndComment(text, token);
        else error = OnEnd(text, token);
        return error;
    }
    virtual eError OnBeginCommentX
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginCommentX(text, token);
        else error = OnBegin(text, token);
        return error;
    }
    virtual eError OnEndCommentX
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndCommentX(text, token);
        else error = OnEnd(text, token);
        return error;
    }
    virtual eError OnBeginCommentLN
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginCommentLN(text, token);
        else error = OnBegin(text, token);
        return error;
    }
    virtual eError OnEndCommentLN
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndCommentLN(text, token);
        else error = OnEnd(text, token);
        return error;
    }

    virtual eError OnBeginIncludeL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginIncludeL(text, token);
        return error;
    }
    virtual eError OnEndIncludeL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndIncludeL(text, token);
        else error = OnEndL(text, token);
        return error;
    }

    virtual eError OnBeginImportL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginImportL(text, token);
        return error;
    }
    virtual eError OnEndImportL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndImportL(text, token);
        else error = OnEndL(text, token);
        return error;
    }

    virtual eError OnBeginDefine
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginDefine(text, token);
        return error;
    }
    virtual eError OnEndDefine
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndDefine(text, token);
        else error = OnEnd(text, token);
        return error;
    }
    virtual eError OnBeginDefineX
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginDefineX(text, token);
        return error;
    }
    virtual eError OnEndDefineX
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndDefineX(text, token);
        else error = OnEnd(text, token);
        return error;
    }
    virtual eError OnBeginDefineL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginDefineL(text, token);
        return error;
    }
    virtual eError OnEndDefineL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndDefineL(text, token);
        else error = OnEndL(text, token);
        return error;
    }
    virtual eError OnBeginDefineT
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginDefineT(text, token);
        return error;
    }
    virtual eError OnEndDefineT
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndDefineT(text, token);
        else error = OnEndT(text, token);
        return error;
    }

    virtual eError OnBeginProcessor
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginProcessor(text, token);
        return error;
    }
    virtual eError OnEndProcessor
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndProcessor(text, token);
        else error = OnEnd(text, token);
        return error;
    }
    virtual eError OnBeginProcessorX
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginProcessorX(text, token);
        return error;
    }
    virtual eError OnEndProcessorX
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndProcessorX(text, token);
        else error = OnEnd(text, token);
        return error;
    }

    virtual eError OnBeginCode
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginCode(text, token);
        return error;
    }
    virtual eError OnEndCode
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndCode(text, token);
        else error = OnEnd(text, token);
        return error;
    }

    virtual eError OnBeginText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginText(text, token);
        return error;
    }
    virtual eError OnBeginTextAfter
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginTextAfter(text, token);
        return error;
    }
    virtual eError OnEndText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndText(text, token);
        else error = OnEnd(text, token);
        return error;
    }

    virtual eError OnBegin
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEnd(text, token);
        else error = OnText(text, token);
        return error;
    }
    virtual eError OnEnd
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEnd(text, token);
        else error = OnText(text, token);
        return error;
    }
    virtual eError OnEndT
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndT(text, token);
        return error;
    }
    virtual eError OnEndL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndL(text, token);
        return error;
    }
    virtual eError OnEndBefore
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndBefore(text, token);
        return error;
    }

    virtual eError OnComment
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnComment(text, token);
        return error;
    }
    virtual eError OnCommentX
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCommentX(text, token);
        return error;
    }
    virtual eError OnCommentLN
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCommentLN(text, token);
        return error;
    }
    virtual eError OnIncludeL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnIncludeL(text, token);
        return error;
    }
    virtual eError OnImportL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnImportL(text, token);
        return error;
    }
    virtual eError OnProcessor
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnProcessor(text, token);
        else error = OnText(text, token);
        return error;
    }
    virtual eError OnProcessorX
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnProcessorX(text, token);
        else error = OnText(text, token);
        return error;
    }
    virtual eError OnDefine
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnDefine(text, token);
        return error;
    }
    virtual eError OnDefineX
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnDefineX(text, token);
        return error;
    }
    virtual eError OnDefineT
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnDefineT(text, token);
        return error;
    }
    virtual eError OnDefineL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnDefineL(text, token);
        return error;
    }

    virtual eError OnReserved
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnReserved(text, token);
        else error = OnText(text, token);
        return error;
    }
    virtual eError OnReservedX
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnReservedX(text, token);
        else error = OnText(text, token);
        return error;
    }
    virtual eError OnReservedY
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnReservedY(text, token);
        else error = OnText(text, token);
        return error;
    }
    virtual eError OnString
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnString(text, token);
        else error = OnText(text, token);
        return error;
    }
    virtual eError OnChar
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnChar(text, token);
        else error = OnText(text, token);
        return error;
    }

    virtual eError OnLT
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnLT(text, token);
        else error = OnText(text, token);
        return error;
    }
    virtual eError OnGT
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnGT(text, token);
        else error = OnText(text, token);
        return error;
    }
    virtual eError OnAMP
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnAMP(text, token);
        else error = OnText(text, token);
        return error;
    }

    virtual eError OnCode
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCode(text, token);
        return error;
    }
    virtual eError OnText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnText(text, token);
        return error;
    }
    virtual eError OnSkip
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnSkip(text, token);
        return error;
    }

    virtual eError OnSwitch
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnSwitch(text, token);
        return error;
    }
    virtual eError OnPush
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnPush(text, token);
        return error;
    }
    virtual eError OnPop
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnPop(text, token);
        return error;
    }

    /*
     * CGI rules
     */

    virtual eError OnBeginCGIBeforeAny
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginCGIBeforeAny(text, token);
        return error;
    }
    virtual eError OnCGIBeforeComment
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIBeforeComment(text, token);
        return error;
    }
    virtual eError OnCGIBeforeCommentLN
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIBeforeCommentLN(text, token);
        return error;
    }
    virtual eError OnCGIBeforeProcessor
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIBeforeProcessor(text, token);
        return error;
    }
    virtual eError OnCGIBeforeDefine
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIBeforeDefine(text, token);
        return error;
    }
    virtual eError OnCGIBeforeDefineT
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIBeforeDefineT(text, token);
        return error;
    }
    virtual eError OnCGIBeforeDefineL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIBeforeDefineL(text, token);
        return error;
    }
    virtual eError OnCGIBeforeImportL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIBeforeImportL(text, token);
        return error;
    }
    virtual eError OnCGIBeforeIncludeL
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIBeforeIncludeL(text, token);
        return error;
    }
    virtual eError OnCGIBeforeKeyword
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIBeforeKeyword(text, token);
        return error;
    }
    virtual eError OnCGIBeforeKeywordX
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIBeforeKeywordX(text, token);
        return error;
    }
    virtual eError OnCGIBeforeKeywordY
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIBeforeKeywordY(text, token);
        return error;
    }
    virtual eError OnCGIBeforeString
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIBeforeString(text, token);
        return error;
    }
    virtual eError OnCGIBeforeChar
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIBeforeChar(text, token);
        return error;
    }
    virtual eError OnCGIBeforeAny
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIBeforeAny(text, token);
        return error;
    }

    virtual eError OnEndCGIBetweenAny
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndCGIBetweenAny(text, token);
        return error;
    }
    virtual eError OnEndCGIAfterAny
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndCGIAfterAny(text, token);
        return error;
    }
    virtual eError OnCGIBeforeAnyText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIBeforeAnyText(text, token);
        return error;
    }
    virtual eError OnCGIBetweenAnyText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIBetweenAnyText(text, token);
        return error;
    }
    virtual eError OnCGIAfterAnyText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIAfterAnyText(text, token);
        return error;
    }

    virtual eError OnEndCGIBefore
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndCGIBefore(text, token);
        return error;
    }
    virtual eError OnCGIBeforeText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIBeforeText(text, token);
        return error;
    }
    virtual eError OnCGIAfterText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIAfterText(text, token);
        return error;
    }

    virtual eError OnBeginCGIText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginCGIText(text, token);
        return error;
    }
    virtual eError OnEndCGIText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndCGIText(text, token);
        return error;
    }
    virtual eError OnCGIText
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIText(text, token);
        return error;
    }

    virtual eError OnBeginCGIPath
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginCGIPath(text, token);
        return error;
    }
    virtual eError OnEndCGIPath
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndCGIPath(text, token);
        return error;
    }
    virtual eError OnCGIPath
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIPath(text, token);
        return error;
    }

    virtual eError OnBeginCGIExtension
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnBeginCGIExtension(text, token);
        return error;
    }
    virtual eError OnEndCGIExtension
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnEndCGIExtension(text, token);
        return error;
    }
    virtual eError OnCGIExtension
    (const char* text,
     int token=-1) 
    {
        eError error = e_ERROR_NONE;
        cDelegate* m_delegate = 0; DBT(("..."));
        if ((m_delegate = GetDelegate()))
            error = m_delegate->OnCGIExtension(text, token);
        return error;
    }

    virtual cDelegate* GetDelegate() 
    { return 0; }
};

class cLexerDelegate;
typedef cLexerDelegateT<cLexerDelegate> cLexerDelegateImplements;
class cLexerDelegate: virtual public cLexerDelegateImplements {
public:
    typedef cLexerDelegateImplements cImplements;
};

#if defined(c_NAMESPACE)
}
#endif /* defined(c_NAMESPACE) */

#endif /* _CLEXERDELEGATE_HXX */
