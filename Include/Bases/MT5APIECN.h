//+------------------------------------------------------------------+
//|                                                 MetaTrader 5 API |
//|                             Copyright 2000-2021, MetaQuotes Ltd. |
//|                                               www.metaquotes.net |
//+------------------------------------------------------------------+
#pragma once
//+------------------------------------------------------------------+
//| ECN Matching Interface                                           |
//+------------------------------------------------------------------+
class IMTECNMatching
  {
public:
   //--- matching order states
   enum ENCMatchingState
     {
      ORDER_STATE_NONE        =0,         // initial state
      ORDER_STATE_TAKEN       =1,         // order taken for filling
      ORDER_STATE_PARTIAL     =2,         // order partially filled and returned to Depth Of Market
      ORDER_STATE_CANCELED    =3,         // order canceled
      ORDER_STATE_EXPIRED     =4,         // order expired
      ORDER_STATE_DONE        =5,         // order filled
      ORDER_STATE_DONE_PARTIAL=6,         // order partially filled and canceled
      //--- enumeration borders
      ORDER_STATE_FIRST       =ORDER_STATE_NONE,
      ORDER_STATE_LAST        =ORDER_STATE_DONE_PARTIAL
     };
   //--- флаги ордера
   enum EnECNMatchingOrderFlags
     {
      ORDER_FLAGS_NONE        =0x00000000, // none
      ORDER_FLAGS_MISSING     =0x00000001, // no client orders of trade server or trade server disconnected from ECN
      //--- enumeration borders
      ORDER_FLAGS_ALL         =ORDER_FLAGS_MISSING
     };
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTECNMatching* order)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- MT5 client order
   virtual UINT64    Order(void) const=0;
   virtual MTAPIRES  Order(const UINT64 order)=0;
   //--- MT5 client login
   virtual UINT64    Login(void) const=0;
   virtual MTAPIRES  Login(const UINT64 login)=0;
   //--- MT5 trade server id
   virtual UINT64    Server(void) const=0;
   virtual MTAPIRES  Server(const UINT64 server)=0;
   //--- client group name
   virtual LPCWSTR   Group(void) const=0;
   virtual MTAPIRES  Group(LPCWSTR group)=0;
   //--- order state ENCMatchingOrderState
   virtual UINT      State(void) const=0;
   virtual MTAPIRES  State(const UINT state)=0;
   //--- order flags EnECNMatchingOrderFlags
   virtual UINT64    Flags(void) const=0;
   virtual MTAPIRES  Flags(const UINT64 flags)=0;
   //--- order setup in ECN time in msc since 1970.01.01
   virtual INT64     TimeSetupMsc(void) const=0;
   virtual MTAPIRES  TimeSetupMsc(const INT64 time)=0;
   //--- order expiration
   virtual INT64     TimeExpiration(void) const=0;
   virtual MTAPIRES  TimeExpiration(const INT64 time)=0;
   //--- the name of the financial symbol for which the order in the ECN was placed
   virtual LPCWSTR   Symbol(void) const=0;
   virtual MTAPIRES  Symbol(LPCWSTR symbol)=0;
   //--- the name of the financial symbol for which the client order was placed
   virtual LPCWSTR   SymbolClient(void) const=0;
   virtual MTAPIRES  SymbolClient(LPCWSTR symbol)=0;
   //--- EnOrderType
   virtual UINT      Type(void) const=0;
   virtual MTAPIRES  Type(const UINT type)=0;
   //--- EnOrderFilling
   virtual UINT      TypeFill(void) const=0;
   virtual MTAPIRES  TypeFill(const UINT type)=0;
   //--- EnOrderTime
   virtual UINT      TypeTime(void) const=0;
   virtual MTAPIRES  TypeTime(const UINT type)=0;
   //--- the price of the order which was created in the ECN to execute the client order
   virtual double    Price(void) const=0;
   virtual MTAPIRES  Price(const double price)=0;
   //--- the price specified in the original client order
   virtual double    PriceClient(void) const=0;
   virtual MTAPIRES  PriceClient(const double price)=0;
   //--- price digits
   virtual UINT      Digits(void) const=0;
   virtual MTAPIRES  Digits(const UINT digits)=0;
   //--- client order price digits
   virtual UINT      DigitsClient(void) const=0;
   virtual MTAPIRES  DigitsClient(const UINT digits)=0;
   //--- the volume of the order which was created in the ECN to execute the client order: 
   //--- the initial operation volume requested by the client in the order and the current filled volume in the ECN.
   //--- with extended accuracy
   virtual UINT64    VolumeInitialExt(void) const=0;
   virtual MTAPIRES  VolumeInitialExt(const UINT64 volume)=0;
   //--- the volume of the order which was created in the ECN to execute the client order: 
   //--- order current volume
   //--- with extended accuracy
   virtual UINT64    VolumeCurrentExt(void) const=0;
   virtual MTAPIRES  VolumeCurrentExt(const UINT64 volume)=0;
   //--- the volume of the order which was created by the client: source volume and currently executed volume
   //--- the initial operation volume
   //--- with extended accuracy
   virtual UINT64    VolumeInitialClientExt(void) const=0;
   virtual MTAPIRES  VolumeInitialClientExt(const UINT64 volume)=0;
   //--- the volume of the order which was created by the client: source volume and currently executed volume
   //--- order current volume
   //--- with extended accuracy
   virtual UINT64    VolumeCurrentClientExt(void) const=0;
   virtual MTAPIRES  VolumeCurrentClientExt(const UINT64 volume)=0;
   //--- explicit destructor is prohibited
protected:
                    ~IMTECNMatching(void) {}
  };
//+------------------------------------------------------------------+
//| ECN Matching Order Array Interface                               |
//+------------------------------------------------------------------+
class IMTECNMatchingArray
  {
public:
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTECNMatchingArray* array)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- add
   virtual MTAPIRES  Add(IMTECNMatching* order)=0;
   virtual MTAPIRES  AddCopy(const IMTECNMatching* order)=0;
   virtual MTAPIRES  Add(IMTECNMatchingArray* array)=0;
   virtual MTAPIRES  AddCopy(const IMTECNMatchingArray* array)=0;
   //--- delete & detach
   virtual MTAPIRES  Delete(const UINT pos)=0;
   virtual IMTECNMatching* Detach(const UINT pos)=0;
   //--- update
   virtual MTAPIRES  Update(const UINT pos,IMTECNMatching* order)=0;
   virtual MTAPIRES  UpdateCopy(const UINT pos,const IMTECNMatching* order)=0;
   virtual MTAPIRES  Shift(const UINT pos,const int shift)=0;
   //--- data access
   virtual UINT      Total(void) const=0;
   virtual IMTECNMatching* Next(const UINT index) const=0;
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
                    ~IMTECNMatchingArray(void) {}
  };
//+------------------------------------------------------------------+
//| ECN Filling Order Interface                                      |
//+------------------------------------------------------------------+
class IMTECNFilling
  {
public:
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTECNFilling* order)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- MT5 client order login (initial order login)
   virtual UINT64    Login(void) const=0;
   virtual MTAPIRES  Login(const UINT64 login)=0;
   //--- MT5 client order (initial order)
   virtual UINT64    Order(void) const=0;
   virtual MTAPIRES  Order(const UINT64 order)=0;
   //--- MT5 trade server id
   virtual UINT64    Server(void) const=0;
   virtual MTAPIRES  Server(const UINT64 server)=0;
   //--- time of order creation in the ECN in msc since 1970.01.01
   virtual INT64     TimeSetupMsc(void) const=0;
   virtual MTAPIRES  TimeSetupMsc(const INT64 time)=0;
   //--- order ID in the external system. The ID is filled by the gateway through which the order is sent for execution
   virtual LPCWSTR   ExternalID(void) const=0;
   virtual MTAPIRES  ExternalID(LPCWSTR id)=0;
   //--- order state EnOrderState
   virtual UINT      State(void) const=0;
   virtual MTAPIRES  State(const UINT state)=0;
   //--- order symbol
   virtual LPCWSTR   Symbol(void) const=0;
   virtual MTAPIRES  Symbol(LPCWSTR symbol)=0;
   //--- EnOrderType - the type of the order which was created for sending to the external system: buy, sell, buy limit or sell limit
   virtual UINT      Type(void) const=0;
   virtual MTAPIRES  Type(const UINT type)=0;
   //--- EnOrderFilling - fill policy applicable to the order. It is determined by the original client order
   virtual UINT      TypeFill(void) const=0;
   virtual MTAPIRES  TypeFill(const UINT type)=0;
   //--- expiration mode of the filling order. It is determined by the original client order
   virtual UINT      TypeTime(void) const=0;
   virtual MTAPIRES  TypeTime(const UINT type)=0;
   //--- the volume of filling orders: the original volume created by the client
   //--- with extended accuracy
   virtual UINT64    VolumeInitialExt(void) const=0;
   virtual MTAPIRES  VolumeInitialExt(const UINT64 volume)=0;
   //---  the volume of filling orders: current filled volume
   //--- with extended accuracy
   virtual UINT64    VolumeCurrentExt(void) const=0;
   virtual MTAPIRES  VolumeCurrentExt(const UINT64 volume)=0;
   //--- the price of the order
   virtual double    Price(void) const=0;
   virtual MTAPIRES  Price(const double price)=0;
   //--- price digits
   virtual UINT      Digits(void) const=0;
   virtual MTAPIRES  Digits(const UINT digits)=0;
   //--- allowable deviation for order execution. It is specified in filling settings.
   virtual UINT      Deviation(void) const=0;
   virtual MTAPIRES  Deviation(const UINT deviation)=0;
   //--- the gateway which is used to forward the order to the external system
   virtual UINT64    Provider(void) const=0;
   virtual MTAPIRES  Provider(const UINT64 provider_id)=0;
   //--- order comment
   virtual LPCWSTR   Comment(void) const=0;
   virtual MTAPIRES  Comment(LPCWSTR comment)=0;
   //--- explicit destructor is prohibited
protected:
                    ~IMTECNFilling(void) {}
  };
//+------------------------------------------------------------------+
//| ECN Matching Order Array Interface                               |
//+------------------------------------------------------------------+
class IMTECNFillingArray
  {
public:
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTECNFillingArray* array)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- add
   virtual MTAPIRES  Add(IMTECNFilling* order)=0;
   virtual MTAPIRES  AddCopy(const IMTECNFilling* order)=0;
   virtual MTAPIRES  Add(IMTECNFillingArray* array)=0;
   virtual MTAPIRES  AddCopy(const IMTECNFillingArray* array)=0;
   //--- delete & detach
   virtual MTAPIRES  Delete(const UINT pos)=0;
   virtual IMTECNFilling* Detach(const UINT pos)=0;
   //--- update
   virtual MTAPIRES  Update(const UINT pos,IMTECNFilling* order)=0;
   virtual MTAPIRES  UpdateCopy(const UINT pos,const IMTECNFilling* order)=0;
   virtual MTAPIRES  Shift(const UINT pos,const int shift)=0;
   //--- data access
   virtual UINT      Total(void) const=0;
   virtual IMTECNFilling* Next(const UINT index) const=0;
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
                    ~IMTECNFillingArray(void) {}
  };
//+------------------------------------------------------------------+
//| ECN Filling Order Interface                                      |
//+------------------------------------------------------------------+
class IMTECNProvider
  {
public:
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTECNProvider* order)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- record id
   virtual UINT64    ID(void) const=0;
   //--- provider id
   virtual UINT64    ProviderID(void) const=0;
   //--- provider name
   virtual LPCWSTR   Name(void) const=0;
   //--- provider module name
   virtual LPCWSTR   Module(void) const=0;
   //--- provider version
   virtual UINT      Version(void) const=0;
   //--- explicit destructor is prohibited
protected:
                    ~IMTECNProvider(void) {}
  };
//+------------------------------------------------------------------+
//| ECN Matching Order Array Interface                               |
//+------------------------------------------------------------------+
class IMTECNProviderArray
  {
public:
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTECNProviderArray* array)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- add
   virtual MTAPIRES  Add(IMTECNProvider* provider)=0;
   virtual MTAPIRES  AddCopy(const IMTECNProvider* provider)=0;
   virtual MTAPIRES  Add(IMTECNProviderArray* array)=0;
   virtual MTAPIRES  AddCopy(const IMTECNProviderArray* array)=0;
   //--- delete & detach
   virtual MTAPIRES  Delete(const UINT pos)=0;
   virtual IMTECNProvider* Detach(const UINT pos)=0;
   //--- update
   virtual MTAPIRES  Update(const UINT pos,IMTECNProvider* provider)=0;
   virtual MTAPIRES  UpdateCopy(const UINT pos,const IMTECNProvider* provider)=0;
   virtual MTAPIRES  Shift(const UINT pos,const int shift)=0;
   //--- data access
   virtual UINT      Total(void) const=0;
   virtual IMTECNProvider* Next(const UINT index) const=0;
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
                    ~IMTECNProviderArray(void) {}
  };
//+------------------------------------------------------------------+
//| ECN History Matching Order Interface                             |
//+------------------------------------------------------------------+
class IMTECNHistoryMatching
  {
public:
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTECNHistoryMatching* order)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- MT5 client order
   virtual UINT64    Order(void) const=0;
   virtual MTAPIRES  Order(const UINT64 order)=0;
   //--- MT5 client login
   virtual UINT64    Login(void) const=0;
   virtual MTAPIRES  Login(const UINT64 login)=0;
   //--- MT5 trade server id
   virtual UINT64    Server(void) const=0;
   virtual MTAPIRES  Server(const UINT64 server)=0;
   //--- order state IMTECNMatching::ENCMatchingOrderState
   virtual UINT      State(void) const=0;
   virtual MTAPIRES  State(const UINT state)=0;
   //--- time of order placing by a client in msc since 1970.01.01
   virtual INT64     TimeSetupMsc(void) const=0;
   virtual MTAPIRES  TimeSetupMsc(const INT64 time)=0;
   //--- order execution time in the ECN
   virtual INT64     TimeDoneMsc(void) const=0;
   virtual MTAPIRES  TimeDoneMsc(const INT64 time)=0;
   //--- order expiration
   virtual INT64     TimeExpiration(void) const=0;
   virtual MTAPIRES  TimeExpiration(const INT64 time)=0;
   //--- the name of the financial symbol for which the order in the ECN was placed
   virtual LPCWSTR   Symbol(void) const=0;
   virtual MTAPIRES  Symbol(LPCWSTR symbol)=0;
   //--- the name of the financial symbol for which the client order was placed
   virtual LPCWSTR   SymbolClient(void) const=0;
   virtual MTAPIRES  SymbolClient(LPCWSTR symbol)=0;
   //--- EnOrderType -  the type of the order which was placed in the ECN: buy, sell, buy limit or sell limit
   virtual UINT      Type(void) const=0;
   virtual MTAPIRES  Type(const UINT type)=0;
   //--- EnOrderType -  the type of the order which was placed by the client: buy, sell, buy limit or sell limit
   virtual UINT      TypeClient(void) const=0;
   virtual MTAPIRES  TypeClient(const UINT type)=0;
   //--- EnOrderFilling - the fill policy of the order, which was created in the ECN
   virtual UINT      TypeFill(void) const=0;
   virtual MTAPIRES  TypeFill(const UINT type)=0;
   //--- EnOrderFilling - the fill policy of the order, specified in the original client order
   virtual UINT      TypeFillClient(void) const=0;
   virtual MTAPIRES  TypeFillClient(const UINT type)=0;
   //--- EnOrderTime - expiration mode of the order which was created in the ECN
   virtual UINT      TypeTime(void) const=0;
   virtual MTAPIRES  TypeTime(const UINT type)=0;
   //--- EnOrderTime - expiration mode of the order, which is specified in the original client order
   virtual UINT      TypeTimeClient(void) const=0;
   virtual MTAPIRES  TypeTimeClient(const UINT type)=0;
   //--- the price of the order which was created in the ECN to execute the client order
   virtual double    Price(void) const=0;
   virtual MTAPIRES  Price(const double price)=0;
   //--- the price specified in the original client order
   virtual double    PriceClient(void) const=0;
   virtual MTAPIRES  PriceClient(const double price)=0;
   //--- price digits
   virtual UINT      Digits(void) const=0;
   virtual MTAPIRES  Digits(const UINT digits)=0;
   //--- client order price digits
   virtual UINT      DigitsClient(void) const=0;
   virtual MTAPIRES  DigitsClient(const UINT digits)=0;
   //--- the volume of the order which was created in the ECN to execute the client order: 
   //--- the initial operation volume requested by the client in the order and the current filled volume in the ECN.
   //--- with extended accuracy
   virtual UINT64    VolumeInitialExt(void) const=0;
   virtual MTAPIRES  VolumeInitialExt(const UINT64 volume)=0;
   //--- the volume of the order which was created in the ECN to execute the client order: 
   //--- order current volume
   //--- with extended accuracy
   virtual UINT64    VolumeCurrentExt(void) const=0;
   virtual MTAPIRES  VolumeCurrentExt(const UINT64 volume)=0;
   //--- the volume of the order which was created by the client: source volume and currently executed volume
   //--- the initial operation volume
   //--- with extended accuracy
   virtual UINT64    VolumeInitialClientExt(void) const=0;
   virtual MTAPIRES  VolumeInitialClientExt(const UINT64 volume)=0;
   //--- the volume of the order which was created by the client: source volume and currently executed volume
   //--- order current volume
   //--- with extended accuracy
   virtual UINT64    VolumeCurrentClientExt(void) const=0;
   virtual MTAPIRES  VolumeCurrentClientExt(const UINT64 volume)=0;
   //--- explicit destructor is prohibited
protected:
                    ~IMTECNHistoryMatching(void) {}
  };
//+------------------------------------------------------------------+
//| ECN Matching History Order Array Interface                       |
//+------------------------------------------------------------------+
class IMTECNHistoryMatchingArray
  {
public:
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTECNHistoryMatchingArray* array)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- add
   virtual MTAPIRES  Add(IMTECNHistoryMatching* order)=0;
   virtual MTAPIRES  AddCopy(const IMTECNHistoryMatching* order)=0;
   virtual MTAPIRES  Add(IMTECNHistoryMatchingArray* array)=0;
   virtual MTAPIRES  AddCopy(const IMTECNHistoryMatchingArray* array)=0;
   //--- delete & detach
   virtual MTAPIRES  Delete(const UINT pos)=0;
   virtual IMTECNHistoryMatching* Detach(const UINT pos)=0;
   //--- update
   virtual MTAPIRES  Update(const UINT pos,IMTECNHistoryMatching* order)=0;
   virtual MTAPIRES  UpdateCopy(const UINT pos,const IMTECNHistoryMatching* order)=0;
   virtual MTAPIRES  Shift(const UINT pos,const int shift)=0;
   //--- data access
   virtual UINT      Total(void) const=0;
   virtual IMTECNHistoryMatching* Next(const UINT index) const=0;
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
                    ~IMTECNHistoryMatchingArray(void) {}
  };
//+------------------------------------------------------------------+
//| ECN History Filling Order Interface                              |
//+------------------------------------------------------------------+
class IMTECNHistoryFilling
  {
public:
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTECNHistoryFilling* order)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- MT5 client order
   virtual UINT64    Order(void) const=0;
   virtual MTAPIRES  Order(const UINT64 order)=0;
   //--- the ticket of an opposite order which is being used to fill the current order. 
   //--- it is filled in only if the order is matched within the cluster, with the counter order of another client in MetaTrader 5.
   virtual UINT64    OrderMatching(void) const=0;
   virtual MTAPIRES  OrderMatching(const UINT64 order)=0;
   //--- the internal ticket of the execution order sent to liquidity provider
   virtual UINT64    OrderGateway(void) const=0;
   virtual MTAPIRES  OrderGateway(const UINT64 order)=0;
   //--- MT5 client login
   virtual UINT64    Login(void) const=0;
   virtual MTAPIRES  Login(const UINT64 login)=0;
   //--- the login of the client, who placed an opposite order which is being used to fill the current order. 
   //--- it is filled in only if the order is matched within the cluster, with the counter order of another client in MetaTrader 5.
   virtual UINT64    LoginMatching(void) const=0;
   virtual MTAPIRES  LoginMatching(const UINT64 login)=0;
   //--- MT5 trade server id
   virtual UINT64    Server(void) const=0;
   virtual MTAPIRES  Server(const UINT64 server)=0;
   //--- time of order placing by a client in msc since 1970.01.01
   virtual INT64     TimeSetupMsc(void) const=0;
   virtual MTAPIRES  TimeSetupMsc(const INT64 time)=0;
   //--- order execution time in the ECN
   virtual INT64     TimeDoneMsc(void) const=0;
   virtual MTAPIRES  TimeDoneMsc(const INT64 time)=0;
   //--- order ID in the external system. the ID is filled by the gateway through which the order is sent for execution
   virtual LPCWSTR   ExternalID(void) const=0;
   virtual MTAPIRES  ExternalID(LPCWSTR id)=0;
   //--- order symbol in ECN
   virtual LPCWSTR   Symbol(void) const=0;
   virtual MTAPIRES  Symbol(LPCWSTR symbol)=0;
   //--- EnOrderType - the type of the order which was created for sending to the external system: buy, sell, buy limit or sell limit
   virtual UINT      Type(void) const=0;
   virtual MTAPIRES  Type(const UINT type)=0;
   //--- EnOrderFilling - fill policy applicable to the order. It is determined by the original client order
   virtual UINT      TypeFill(void) const=0;
   virtual MTAPIRES  TypeFill(const UINT type)=0;
   //--- expiration mode of the filling order. It is determined by the original client order
   virtual UINT      TypeTime(void) const=0;
   virtual MTAPIRES  TypeTime(const UINT type)=0;
   //---  the volume of filling orders: the original volume created by the client
   //--- with extended accuracy
   virtual UINT64    VolumeInitialExt(void) const=0;
   virtual MTAPIRES  VolumeInitialExt(const UINT64 volume)=0;
   //---  the volume of filling orders: current filled volume
   //--- with extended accuracy
   virtual UINT64    VolumeCurrentExt(void) const=0;
   virtual MTAPIRES  VolumeCurrentExt(const UINT64 volume)=0;
   //--- the price of the order which was created in the ECN to execute the client order
   virtual double    Price(void) const=0;
   virtual MTAPIRES  Price(const double price)=0;
   //--- price digits
   virtual UINT      Digits(void) const=0;
   virtual MTAPIRES  Digits(const UINT digits)=0;
   //--- allowable deviation for order execution. It is specified in filling settings.
   virtual UINT      Deviation(void) const=0;
   virtual MTAPIRES  Deviation(const UINT deviation)=0;
   //--- the gateway which is used to forward the order to the external system
   virtual UINT64    Provider(void) const=0;
   virtual MTAPIRES  Provider(const UINT64 provider_id)=0;
   //--- order comment
   virtual LPCWSTR   Comment(void) const=0;
   virtual MTAPIRES  Comment(LPCWSTR comment)=0;
   //--- explicit destructor is prohibited
protected:
                    ~IMTECNHistoryFilling(void) {}
  };
//+------------------------------------------------------------------+
//| ECN Filling History Order Array Interface                        |
//+------------------------------------------------------------------+
class IMTECNHistoryFillingArray
  {
public:
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTECNHistoryFillingArray* array)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- add
   virtual MTAPIRES  Add(IMTECNHistoryFilling* order)=0;
   virtual MTAPIRES  AddCopy(const IMTECNHistoryFilling* order)=0;
   virtual MTAPIRES  Add(IMTECNHistoryFillingArray* array)=0;
   virtual MTAPIRES  AddCopy(const IMTECNHistoryFillingArray* array)=0;
   //--- delete & detach
   virtual MTAPIRES  Delete(const UINT pos)=0;
   virtual IMTECNHistoryFilling* Detach(const UINT pos)=0;
   //--- update
   virtual MTAPIRES  Update(const UINT pos,IMTECNHistoryFilling* order)=0;
   virtual MTAPIRES  UpdateCopy(const UINT pos,const IMTECNHistoryFilling* order)=0;
   virtual MTAPIRES  Shift(const UINT pos,const int shift)=0;
   //--- data access
   virtual UINT      Total(void) const=0;
   virtual IMTECNHistoryFilling* Next(const UINT index) const=0;
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
                    ~IMTECNHistoryFillingArray(void) {}
  };
//+------------------------------------------------------------------+
//| ECN History Deal Interface                                       |
//+------------------------------------------------------------------+
class IMTECNHistoryDeal
  {
public:
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTECNHistoryDeal* deal)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- MT5 client order
   virtual UINT64    Order(void) const=0;
   virtual MTAPIRES  Order(const UINT64 order)=0;
   //--- the internal ticket of the execution order sent to liquidity provider
   virtual UINT64    OrderGateway(void) const=0;
   virtual MTAPIRES  OrderGateway(const UINT64 order)=0;
   //---  the internal ticket of the deal; it is only used in ECN for internal purposes.
   virtual UINT64    DealGateway(void) const=0;
   virtual MTAPIRES  DealGateway(const UINT64 deal)=0;
   //--- MT5 client login
   virtual UINT64    Login(void) const=0;
   virtual MTAPIRES  Login(const UINT64 login)=0;
   //--- MT5 trade server id
   virtual UINT64    Server(void) const=0;
   virtual MTAPIRES  Server(const UINT64 server)=0;
   //--- deal ticket in external system (exchange, ECN, etc)
   virtual LPCWSTR   ExternalID(void) const=0;
   virtual MTAPIRES  ExternalID(LPCWSTR id)=0;
   //--- deal creation datetime in msc since 1970.01.01
   virtual INT64     TimeMsc(void) const=0;
   virtual MTAPIRES  TimeMsc(const INT64 time)=0;
   //--- symbol
   virtual LPCWSTR   Symbol(void) const=0;
   virtual MTAPIRES  Symbol(LPCWSTR symbol)=0;
   //--- EnDealAction
   virtual UINT      Action(void) const=0;
   virtual MTAPIRES  Action(const UINT action)=0;
   //--- deal volume
   //--- with extended accuracy
   virtual UINT64    VolumeExt(void) const=0;
   virtual MTAPIRES  VolumeExt(const UINT64 volume)=0;
   //--- the price at which the deal was executed at the platform side, taking into account price translation settings
   virtual double    Price(void) const=0;
   virtual MTAPIRES  Price(const double price)=0;
   //--- the price at which the deal was actually executed at the external system side.
   virtual double    PriceGateway(void) const=0;
   virtual MTAPIRES  PriceGateway(const double price)=0;
   //--- price digits
   virtual UINT      Digits(void) const=0;
   virtual MTAPIRES  Digits(const UINT digits)=0;
   //--- gateway price digits
   virtual UINT      DigitsGateway(void) const=0;
   virtual MTAPIRES  DigitsGateway(const UINT digits)=0;
   //--- commission charged by the external system for the deal. The value is filled by gateways.
   virtual double    Commission(void) const=0;
   virtual MTAPIRES  Commission(const double price)=0;
   //--- the gateway which is used to forward the order to the external system
   virtual UINT64    Provider(void) const=0;
   virtual MTAPIRES  Provider(const UINT64 provider_id)=0;
   //--- explicit destructor is prohibited
protected:
                    ~IMTECNHistoryDeal(void) {}
  };
//+------------------------------------------------------------------+
//| ECN ECN History Deal Array Interface                             |
//+------------------------------------------------------------------+
class IMTECNHistoryDealArray
  {
public:
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTECNHistoryDealArray* array)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- add
   virtual MTAPIRES  Add(IMTECNHistoryDeal* deal)=0;
   virtual MTAPIRES  AddCopy(const IMTECNHistoryDeal* deal)=0;
   virtual MTAPIRES  Add(IMTECNHistoryDealArray* array)=0;
   virtual MTAPIRES  AddCopy(const IMTECNHistoryDealArray* array)=0;
   //--- delete & detach
   virtual MTAPIRES  Delete(const UINT pos)=0;
   virtual IMTECNHistoryDeal* Detach(const UINT pos)=0;
   //--- update
   virtual MTAPIRES  Update(const UINT pos,IMTECNHistoryDeal* deal)=0;
   virtual MTAPIRES  UpdateCopy(const UINT pos,const IMTECNHistoryDeal* deal)=0;
   virtual MTAPIRES  Shift(const UINT pos,const int shift)=0;
   //--- data access
   virtual UINT      Total(void) const=0;
   virtual IMTECNHistoryDeal* Next(const UINT index) const=0;
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
                    ~IMTECNHistoryDealArray(void) {}
  };
//+------------------------------------------------------------------+
