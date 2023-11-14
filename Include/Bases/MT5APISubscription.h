//+------------------------------------------------------------------+
//|                                                 MetaTrader 5 API |
//|                             Copyright 2000-2021, MetaQuotes Ltd. |
//|                                               www.metaquotes.net |
//+------------------------------------------------------------------+
#pragma once
//+------------------------------------------------------------------+
//| Active subscription interface                                    |
//+------------------------------------------------------------------+
class IMTSubscription
  {
public:
   //---- subscription status
   enum EnStatus
     {
      STATUS_ACTIVE            =0,          // subscription is active
      STATUS_SUSPENDED         =1,          // suspended due "no money"
      STATUS_CANCELED          =2,          // canceled by client
      //---
      STATUS_FIRST             =STATUS_ACTIVE,
      STATUS_LAST              =STATUS_CANCELED
     };
   //---- subscription flags
   enum EnFlags
     {
      FLAG_FREE_PERIOD         =0x01,        // subscription is activated with free period
      //---
      FLAG_NONE                =0x00,
      FLAG_ALL                 =FLAG_FREE_PERIOD
     };

   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTSubscription* obj)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- id
   virtual UINT64    ID(void) const=0;
   //--- client login
   virtual UINT64    Login(void) const=0;
   virtual MTAPIRES  Login(const UINT64 login)=0;
   //--- subscription id
   virtual UINT64    Subscription(void) const=0;
   virtual MTAPIRES  Subscription(const UINT64 subscription_id)=0;
   //--- EnStatus
   virtual UINT      Status(void) const=0;
   virtual MTAPIRES  Status(const UINT status)=0;
   //--- subscribe time
   virtual INT64     TimeSubscribe(void) const=0;
   virtual MTAPIRES  TimeSubscribe(const INT64 time)=0;
   //--- last renewal time
   virtual INT64     TimeRenewal(void) const=0;
   virtual MTAPIRES  TimeRenewal(const INT64 time)=0;
   //--- expire time
   virtual INT64     TimeExpire(void) const=0;
   virtual MTAPIRES  TimeExpire(const INT64 time)=0;
   //--- flags
   virtual UINT      Flags(void) const=0;
   virtual MTAPIRES  Flags(const UINT flags)=0;
   //--- explicit destructor is prohibited
protected:
                    ~IMTSubscription(void) {}
  };
//+------------------------------------------------------------------+
//| Active subscriptions array interface                             |
//+------------------------------------------------------------------+
class IMTSubscriptionArray
  {
public:
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTSubscriptionArray* array)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- add
   virtual MTAPIRES  Add(IMTSubscription* record)=0;
   virtual MTAPIRES  AddCopy(const IMTSubscription* record)=0;
   virtual MTAPIRES  Add(IMTSubscriptionArray* array)=0;
   virtual MTAPIRES  AddCopy(const IMTSubscriptionArray* array)=0;
   //--- delete & detach
   virtual MTAPIRES  Delete(const UINT pos)=0;
   virtual IMTSubscription* Detach(const UINT pos)=0;
   //--- update
   virtual MTAPIRES  Update(const UINT pos,IMTSubscription* record)=0;
   virtual MTAPIRES  UpdateCopy(const UINT pos,const IMTSubscription* record)=0;
   virtual MTAPIRES  Shift(const UINT pos,const int shift)=0;
   //--- data access
   virtual UINT      Total(void) const=0;
   virtual IMTSubscription*  Next(const UINT index) const=0;
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
                    ~IMTSubscriptionArray(void) {}
  };
//+------------------------------------------------------------------+
//| Subscription history action interface                            |
//+------------------------------------------------------------------+
class IMTSubscriptionHistory
  {
public:
   //---- actions
   enum EnAction
     {
      ACTION_SUBSCRIBE         =0,          // subscription
      ACTION_RENEWAL           =1,          // renewal
      ACTION_SUSPEND           =2,          // suspend
      ACTION_CANCEL            =3,          // cancel
      ACTION_DELETED           =4,          // delete
      //--- enumeration borders
      ACTION_FIRST             =ACTION_SUBSCRIBE,
      ACTION_LAST              =ACTION_DELETED
     };
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTSubscriptionHistory* obj)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- id
   virtual UINT64    ID(void) const=0;
   //--- client login
   virtual UINT64    Login(void) const=0;
   virtual MTAPIRES  Login(const UINT64 login)=0;
   //--- subscription config id
   virtual UINT64    Subscription(void) const=0;
   virtual MTAPIRES  Subscription(const UINT64 subscription_id)=0;
   //--- subscription record id
   virtual UINT64    Record(void) const=0;
   virtual MTAPIRES  Record(const UINT64 record_id)=0;
   //--- EnStatus
   virtual UINT      Action(void) const=0;
   virtual MTAPIRES  Action(const UINT status)=0;
   //--- subscribe time
   virtual INT64     Time(void) const=0;
   virtual MTAPIRES  Time(const INT64 time)=0;
   //--- ammount
   virtual double    Amount(void) const=0;
   virtual MTAPIRES  Amount(const double ammount)=0;
   //--- digits
   virtual UINT      AmountDigits(void) const=0;
   virtual MTAPIRES  AmountDigits(const UINT digits)=0;
   //--- ammount deal
   virtual UINT64    AmountDeal(void) const=0;
   virtual MTAPIRES  AmountDeal(const UINT64 deal)=0;
   //--- explicit destructor is prohibited
protected:
                    ~IMTSubscriptionHistory(void) {}
  };
//+------------------------------------------------------------------+
//| Subscription history action array interface                      |
//+------------------------------------------------------------------+
class IMTSubscriptionHistoryArray
  {
public:
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTSubscriptionHistoryArray* array)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- add
   virtual MTAPIRES  Add(IMTSubscriptionHistory* record)=0;
   virtual MTAPIRES  AddCopy(const IMTSubscriptionHistory* record)=0;
   virtual MTAPIRES  Add(IMTSubscriptionHistoryArray* array)=0;
   virtual MTAPIRES  AddCopy(const IMTSubscriptionHistoryArray* array)=0;
   //--- delete & detach
   virtual MTAPIRES  Delete(const UINT pos)=0;
   virtual IMTSubscriptionHistory* Detach(const UINT pos)=0;
   //--- update
   virtual MTAPIRES  Update(const UINT pos,IMTSubscriptionHistory* record)=0;
   virtual MTAPIRES  UpdateCopy(const UINT pos,const IMTSubscriptionHistory* record)=0;
   virtual MTAPIRES  Shift(const UINT pos,const int shift)=0;
   //--- data access
   virtual UINT      Total(void) const=0;
   virtual IMTSubscriptionHistory*  Next(const UINT index) const=0;
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
                    ~IMTSubscriptionHistoryArray(void) {}
  };
//+------------------------------------------------------------------+
//| Subscription events notification interface                       |
//+------------------------------------------------------------------+
class IMTSubscriptionSink
  {
public:
   //--- events
   virtual void      OnSubscriptionAdd(const IMTSubscription*    /*subscription*/) {  }
   virtual void      OnSubscriptionUpdate(const IMTSubscription* /*subscription*/) {  }
   virtual void      OnSubscriptionDelete(const IMTSubscription* /*subscription*/) {  }
   virtual void      OnSubscriptionJoin(const UINT64 manager,const UINT64 login,const IMTConSubscription* config,IMTSubscription* record,IMTSubscriptionHistory* history) { }
   virtual void      OnSubscriptionCancel(const UINT64 manager,const UINT64 login,const IMTConSubscription* config,IMTSubscription* record,IMTSubscriptionHistory* history) { }
  };
//+------------------------------------------------------------------+
//| Subscription history events notification interface               |
//+------------------------------------------------------------------+
class IMTSubscriptionHistorySink
  {
public:
   //--- events
   virtual void      OnSubscriptionHistoryAdd(const IMTSubscriptionHistory*    /*subscription*/) {  }
   virtual void      OnSubscriptionHistoryUpdate(const IMTSubscriptionHistory* /*subscription*/) {  }
   virtual void      OnSubscriptionHistoryDelete(const IMTSubscriptionHistory* /*subscription*/) {  }
  };
//+------------------------------------------------------------------+
