//+------------------------------------------------------------------+
//|                                                 MetaTrader 5 API |
//|                             Copyright 2000-2021, MetaQuotes Ltd. |
//|                                               www.metaquotes.net |
//+------------------------------------------------------------------+
#pragma once
#include "MT5APIAttachment.h"
//+------------------------------------------------------------------+
//| Comment record interface                                         |
//+------------------------------------------------------------------+
class IMTComment
  {
public:
   //--- comment flags
   enum EnCommentFlags
     {
      COMMENT_FLAG_DELETED    =0x1,                   // deleted
      COMMENT_FLAG_IMPORTANT  =0x2,                   // important
      //--- enumeration borders
      COMMENT_FLAG_NONE       =0,
      COMMENT_FLAG_ALL        =COMMENT_FLAG_DELETED|COMMENT_FLAG_IMPORTANT,
     };
   //--- comment types
   enum EnCommentType
     {
      COMMENT_TYPE_UNDEFINED                =0,       // undefined
      COMMENT_TYPE_LOGRECORD                =1,       // log record
      COMMENT_TYPE_CALLRECORD               =2,       // call record
      COMMENT_TYPE_ROBOTRECORD              =3,       // robot record
      //--- enumeration borders
      COMMENT_TYPE_FIRST                    =COMMENT_TYPE_UNDEFINED,
      COMMENT_TYPE_LAST                     =COMMENT_TYPE_ROBOTRECORD,
     };
   //--- comment results
   enum EnCommentResult
     {
      COMMENT_RESULT_UNDEFINED              =0,       // undefined
      COMMENT_RESULT_CALL_NO_ANSWER         =1,       // call no answer
      COMMENT_RESULT_CALL_WRONG_NUMBER      =2,       // call wrong number
      COMMENT_RESULT_CALL_NOT_INTERESTED    =3,       // call not interested
      COMMENT_RESULT_CALL_SUCCESSFUL        =4,       // call successful
      //--- enumeration borders
      COMMENT_RESULT_FIRST                  =COMMENT_RESULT_UNDEFINED,
      COMMENT_RESULT_LAST                   =COMMENT_RESULT_CALL_SUCCESSFUL,
     };
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTComment* comment)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- record id
   virtual UINT64    RecordID(void) const=0;
   virtual MTAPIRES  RecordID(const UINT64 record_id)=0;
   //--- related client
   virtual UINT64    RelatedClient(void) const=0;
   virtual MTAPIRES  RelatedClient(const UINT64 record_id)=0;
   //--- related document
   virtual UINT64    RelatedDocument(void) const=0;
   virtual MTAPIRES  RelatedDocument(const UINT64 record_id)=0;
   //--- flags
   virtual UINT      Flags(void) const=0;
   virtual MTAPIRES  Flags(const UINT flags)=0;
   //--- extra
   virtual LPCWSTR   Extra(void) const=0;
   virtual MTAPIRES  Extra(LPCWSTR extra)=0;
   //--- text
   virtual LPCWSTR   Text(void) const=0;
   virtual MTAPIRES  Text(LPCWSTR text)=0;
   //--- comment type
   virtual UINT      CommentType(void) const=0;
   virtual MTAPIRES  CommentType(const UINT type)=0;
   //--- comment result
   virtual UINT      CommentResult(void) const=0;
   virtual MTAPIRES  CommentResult(const UINT result)=0;
   //--- attachments
   virtual MTAPIRES  AttachmentsAdd(const IMTAttachment *attachment)=0;
   virtual MTAPIRES  AttachmentsClear(void)=0;
   virtual UINT      AttachmentsTotal(void) const=0;
   virtual MTAPIRES  AttachmentsNext(const UINT pos,UINT64& attachment_id,MTAPISTR& attachment_name,UINT& attachment_size) const=0;
   //--- explicit destructor is prohibited
protected:
                    ~IMTComment(void) {}
  };
//+------------------------------------------------------------------+
//| Comment array interface                                          |
//+------------------------------------------------------------------+
class IMTCommentArray
  {
public:
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTCommentArray* array)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- add
   virtual MTAPIRES  Add(IMTComment* comment)=0;
   virtual MTAPIRES  AddCopy(const IMTComment* comment)=0;
   virtual MTAPIRES  Add(IMTCommentArray* array)=0;
   virtual MTAPIRES  AddCopy(const IMTCommentArray* array)=0;
   //--- delete & detach
   virtual MTAPIRES  Delete(const UINT pos)=0;
   virtual IMTComment *Detach(const UINT pos)=0;
   //--- update
   virtual MTAPIRES  Update(const UINT pos,IMTComment* comment)=0;
   virtual MTAPIRES  UpdateCopy(const UINT pos,const IMTComment* comment)=0;
   virtual MTAPIRES  Shift(const UINT pos,const int shift)=0;
   //--- data access
   virtual UINT      Total(void) const=0;
   virtual IMTComment*Next(const UINT index) const=0;
   //--- sorting and search
   virtual MTAPIRES  Sort(MTSortFunctionPtr sort_function)=0;
   virtual int       Search(const void *key,MTSortFunctionPtr sort_function) const=0;
   virtual int       SearchGreatOrEq(const void *key,MTSortFunctionPtr sort_function) const=0;
   virtual int       SearchGreater(const void *key,MTSortFunctionPtr sort_function) const=0;
   virtual int       SearchLessOrEq(const void *key,MTSortFunctionPtr sort_function) const=0;
   virtual int       SearchLess(const void *key,MTSortFunctionPtr sort_function) const=0;
   virtual int       SearchLeft(const void *key,MTSortFunctionPtr sort_function) const=0;
   virtual int       SearchRight(const void *key,MTSortFunctionPtr sort_function) const=0;
   //--- explicit destructor is prohibited
protected:
                    ~IMTCommentArray(void) {}
  };
//+------------------------------------------------------------------+
//| Comment records notification interface                           |
//+------------------------------------------------------------------+
class IMTCommentSink
  {
public:
   //--- events
   virtual void      OnCommentAdd(const IMTComment*    /*comment*/)           {  }
   virtual void      OnCommentUpdate(const IMTComment* /*comment*/)           {  }
   virtual void      OnCommentDelete(const IMTComment* /*comment*/)           {  }
  };
//+------------------------------------------------------------------+
