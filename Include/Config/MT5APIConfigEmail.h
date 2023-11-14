//+------------------------------------------------------------------+
//|                                                 MetaTrader 5 API |
//|                             Copyright 2000-2021, MetaQuotes Ltd. |
//|                                               www.metaquotes.net |
//+------------------------------------------------------------------+
#pragma once
//+------------------------------------------------------------------+
//| Email server config                                              |
//+------------------------------------------------------------------+
class IMTConEmail
  {
public:
   //--- allowed flags
   enum EnFlags
     {
      FLAG_NONE               =0, // none
      FLAG_ENABLED            =1, // mail server is enabled
      FLAG_DEFAULT            =2, // mail server is default
      //--- flags borders
      FLAG_FIRST              =FLAG_ENABLED,
      FLAG_ALL                =FLAG_ENABLED|FLAG_DEFAULT
     };
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTConEmail* email)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- name
   virtual LPCWSTR   Name(void) const=0;
   virtual MTAPIRES  Name(LPCWSTR name)=0;
   //--- sender email
   virtual LPCWSTR   SenderMail(void) const=0;
   virtual MTAPIRES  SenderMail(LPCWSTR mail)=0;
   //--- sender name
   virtual LPCWSTR   SenderName(void) const=0;
   virtual MTAPIRES  SenderName(LPCWSTR name)=0;
   //--- server
   virtual LPCWSTR   Server(void) const=0;
   virtual MTAPIRES  Server(LPCWSTR server)=0;
   //--- login
   virtual LPCWSTR   Login(void) const=0;
   virtual MTAPIRES  Login(LPCWSTR login)=0;
   //--- password
   virtual LPCWSTR   Password(void) const=0;
   virtual MTAPIRES  Password(LPCWSTR password)=0;
   //--- EnFlags
   virtual UINT64    Flags(void) const=0;
   virtual MTAPIRES  Flags(const UINT64 flags)=0;
   //--- explicit destructor is prohibited
protected:
                    ~IMTConEmail(void) {}
  };
//+------------------------------------------------------------------+
//| Mail config events notification interface                        |
//+------------------------------------------------------------------+
class IMTConEmailSink
  {
public:
   virtual void      OnEmailAdd(const IMTConEmail*    /*config*/) {  }
   virtual void      OnEmailUpdate(const IMTConEmail* /*config*/) {  }
   virtual void      OnEmailDelete(const IMTConEmail* /*config*/) {  }
   virtual void      OnEmailSync(void)                            {  }
  };
//+------------------------------------------------------------------+
