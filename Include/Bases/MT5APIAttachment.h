//+------------------------------------------------------------------+
//|                                                 MetaTrader 5 API |
//|                             Copyright 2000-2021, MetaQuotes Ltd. |
//|                                               www.metaquotes.net |
//+------------------------------------------------------------------+
#pragma once
//+------------------------------------------------------------------+
//| Attachment record interface                                      |
//+------------------------------------------------------------------+
class IMTAttachment
  {
public:
   //--- file types
   enum EnFileType
     {
      FILE_TYPE_OTHER                       =0,          // other
      FILE_TYPE_TXT                         =1,          // txt
      FILE_TYPE_DOC                         =2,          // doc
      FILE_TYPE_PDF                         =3,          // pdf
      FILE_TYPE_JPG                         =4,          // jpg
      FILE_TYPE_PNG                         =5,          // png
      FILE_TYPE_BMP                         =6,          // bmp
      FILE_TYPE_ZIP                         =7,          // zip
      //--- enumeration borders
      FILE_TYPE_FIRST                       =FILE_TYPE_OTHER,
      FILE_TYPE_LAST                        =FILE_TYPE_ZIP,
     };
   //--- file flags
   enum EnFileFlags
     {
      FILE_FLAG_EMBEDDED                    =0x1,        // embedded for content (images in HTML)
      //--- enumeration borders
      FILE_FLAG_NONE                        =0,
      FILE_FLAG_ALL                         =FILE_FLAG_EMBEDDED,
     };
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTAttachment* file)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- record id
   virtual UINT64    RecordID(void) const=0;
   virtual MTAPIRES  RecordID(const UINT64 record_id)=0;
   //--- related client
   virtual UINT64    RelatedClient(void) const=0;
   virtual MTAPIRES  RelatedClient(const UINT64 record_id)=0;
   //--- file type
   virtual UINT      FileType(void) const=0;
   virtual MTAPIRES  FileType(const UINT type)=0;
   //--- file name
   virtual LPCWSTR   FileName(void) const=0;
   virtual MTAPIRES  FileName(LPCWSTR name)=0;
   //--- file content
   virtual const void* FileContent(UINT& content_size) const=0;
   virtual MTAPIRES  FileContent(const void* content,const UINT content_size)=0;
   //--- file size
   virtual UINT      FileSize(void)=0;
   //--- file flags
   virtual UINT      FileFlags(void) const=0;
   virtual MTAPIRES  FileFlags(const UINT flags)=0;
   //--- explicit destructor is prohibited
protected:
                    ~IMTAttachment(void) {}
  };
//+------------------------------------------------------------------+
//| Comment array interface                                          |
//+------------------------------------------------------------------+
class IMTAttachmentArray
  {
public:
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTAttachmentArray* array)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- add
   virtual MTAPIRES  Add(IMTAttachment* attachment)=0;
   virtual MTAPIRES  AddCopy(const IMTAttachment* attachment)=0;
   virtual MTAPIRES  Add(IMTAttachmentArray* array)=0;
   virtual MTAPIRES  AddCopy(const IMTAttachmentArray* array)=0;
   //--- delete & detach
   virtual MTAPIRES  Delete(const UINT pos)=0;
   virtual IMTAttachment *Detach(const UINT pos)=0;
   //--- update
   virtual MTAPIRES  Update(const UINT pos,IMTAttachment* attachment)=0;
   virtual MTAPIRES  UpdateCopy(const UINT pos,const IMTAttachment* attachment)=0;
   virtual MTAPIRES  Shift(const UINT pos,const int shift)=0;
   //--- data access
   virtual UINT      Total(void) const=0;
   virtual IMTAttachment *Next(const UINT index) const=0;
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
                    ~IMTAttachmentArray(void) {}
  };
//+------------------------------------------------------------------+
