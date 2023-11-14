//+------------------------------------------------------------------+
//|                                         MetaTrader 5 API Server  |
//|                             Copyright 2000-2021, MetaQuotes Ltd. |
//|                                               www.metaquotes.net |
//+------------------------------------------------------------------+
#pragma once
//+------------------------------------------------------------------+
//| Dataset column interface                                         |
//+------------------------------------------------------------------+
class IMTDatasetColumn
  {
public:
   //--- column data types
   enum EnType
     {
      //--- base types
      TYPE_INT8               =0,                     // Integer (8 bits)
      TYPE_UINT8              =1,                     // Unsigned Integer (8 bits)
      TYPE_INT16              =2,                     // Integer (16 bits)
      TYPE_UINT16             =3,                     // Unsigned Integer (16 bits)
      TYPE_INT32              =4,                     // Integer (32 bits)
      TYPE_UINT32             =5,                     // Unsigned Integer (32 bits)
      TYPE_INT64              =6,                     // Integer (64 bits)
      TYPE_UINT64             =7,                     // Unsigned Integer (64 bits)
      TYPE_DOUBLE             =8,                     // Double
      TYPE_MONEY              =9,                     // Money (Double)
      TYPE_STRING             =10,                    // Unicode String
      TYPE_DATE               =11,                    // Date (Int64)
      TYPE_TIME               =12,                    // Time (Int64)
      TYPE_DATETIME           =13,                    // Datetime (Int64)
      TYPE_TIME_MSC           =14,                    // Time in milliseconds (Int64)
      TYPE_DATETIME_MSC       =15,                    // Datetime in milliseconds (Int64)
      //--- prices
      TYPE_PRICE              =100,                   // Price (Double)
      TYPE_PRICES             =101,                   // Bid/Ask (Double[2])
      TYPE_PRICE_POSITION     =102,                   // Price for positions (Double)
      //--- volumes
      TYPE_VOLUME             =200,                   // Volume (UInt64)
      TYPE_VOLUME_ORDER       =201,                   // Initial Volume/Current Volume (UInt64[2])
      TYPE_VOLUME_EXT         =202,                   // Volume with extended accuracy (UInt64)
      TYPE_VOLUME_ORDER_EXT   =203,                   // Initial Volume/Current Volume with extended accuracy (UInt64[2])
      //--- positions
      TYPE_POSITION_TYPE      =300,                   // Position Type (UInt)
      //--- orders
      TYPE_ORDER_TYPE         =400,                   // Order Type (UInt)
      TYPE_ORDER_TYPE_TIME    =401,                   // Order Type by Time (UInt)
      TYPE_ORDER_TYPE_REASON  =402,                   // Order Type by Reason (UInt)
      TYPE_ORDER_STATUS       =403,                   // Order Status (UInt)
      TYPE_ORDER_FILLING      =404,                   // Order Filling (UInt)
      //--- deals
      TYPE_DEAL_ACTION        =500,                   // Deal Action (UInt)
      TYPE_DEAL_ENTRY         =501,                   // Deal Entry (UInt)
      //--- accounts
      TYPE_USER_LOGIN         =600,                   // Account Login (UInt64)
      TYPE_USER_LEVERAGE      =601,                   // Account Leverage (UInt)
      //--- clients
      TYPE_CLIENT_ID          =700,                   // Client Id (UInt64)
      //--- enumeration borders
      TYPE_FIRST              =TYPE_INT8,
      TYPE_LAST               =TYPE_CLIENT_ID
     };
   //--- column flags
   enum EnFlags
     {
      FLAG_NONE               =0x00000000,            // none flags
      FLAG_PRIMARY            =0x00000001,            // primary integer column
      FLAG_HIDDEN_VIEW        =0x00000002,            // hidden in grid view
      FLAG_HIDDEN_SAVE        =0x00000004,            // hidden in saved file
      FLAG_HIDDEN             =FLAG_HIDDEN_VIEW|FLAG_HIDDEN_SAVE, // hidden in grid and file
      FLAG_LEFT               =0x00000008,            // force align left
      FLAG_RIGHT              =0x00000010,            // force align right
      FLAG_CENTER             =FLAG_LEFT|FLAG_RIGHT,  // force align center
      FLAG_SORT_DEFAULT       =0x00000100,            // deafult sort column
      //--- enumeration borders
      FLAG_ALL                =FLAG_PRIMARY|FLAG_HIDDEN|FLAG_CENTER|FLAG_SORT_DEFAULT
     };
   //--- color
   enum EnColumnColor
     {
      COLUMN_COLOR_AUTO       =0xFFFFFFFF,            // auto color
     };
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTDatasetColumn *column)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- name
   virtual LPCWSTR   Name(void) const=0;
   virtual MTAPIRES  Name(LPCWSTR name)=0;
   //--- column id
   virtual UINT      ColumnID(void) const=0;
   virtual MTAPIRES  ColumnID(const UINT column_id)=0;
   //--- type IMTDatasetColumn::EnType
   virtual UINT      Type(void) const=0;
   virtual MTAPIRES  Type(const UINT type)=0;
   //--- column relative width
   virtual UINT      Width(void) const=0;
   virtual MTAPIRES  Width(const UINT width)=0;
   //--- column max width in pixels
   virtual UINT      WidthMax(void) const=0;
   virtual MTAPIRES  WidthMax(const UINT width_max)=0;
   //--- default digits
   virtual UINT      Digits(void) const=0;
   virtual MTAPIRES  Digits(const UINT digits)=0;
   //--- column digits reference
   virtual UINT      DigitsColumn(void) const=0;
   virtual MTAPIRES  DigitsColumn(const UINT column_id)=0;
   //--- flags IMTDatasetColumn::EnFlags
   virtual UINT64    Flags(void) const=0;
   virtual MTAPIRES  Flags(const UINT64 flags)=0;
   //--- offset
   virtual UINT      Offset(void) const=0;
   virtual MTAPIRES  Offset(const UINT offset)=0;
   //--- size
   virtual UINT      Size(void) const=0;
   virtual MTAPIRES  Size(const UINT size)=0;
   //--- chart color
   virtual UINT      Color(void) const=0;
   virtual MTAPIRES  Color(const UINT color)=0;
   //--- explicit destructor is prohibited
protected:
                    ~IMTDatasetColumn(void) {}
  };
//+------------------------------------------------------------------+
//| Dataset summary interface                                        |
//+------------------------------------------------------------------+
class IMTDatasetSummary
  {
public:
   //--- summary data types
   enum EnType
     {
      //--- base types
      TYPE_INT                =0,                     // Integer (64 bits)
      TYPE_UINT               =1,                     // Unsigned Integer (64 bits)
      TYPE_DOUBLE             =2,                     // Double
      TYPE_MONEY              =3,                     // Money
      TYPE_STRING             =4,                     // Unicode String
      TYPE_DATE               =5,                     // Date
      TYPE_TIME               =6,                     // Time
      TYPE_DATETIME           =7,                     // Datetime
      //--- prices
      TYPE_PRICE              =100,                   // Price
      TYPE_PRICES             =101,                   // Bid/Ask
      //--- volumes
      TYPE_VOLUME             =200,                   // Volume
      TYPE_VOLUME_ORDER       =201,                   // Initial Volume/Current Volume (UInt64[2])
      TYPE_VOLUME_EXT         =202,                   // Volume with extended accuracy (UInt64)
      TYPE_VOLUME_ORDER_EXT   =203,                   // Initial Volume/Current Volume with extended accuracy (UInt64[2])
      //--- enumeration borders
      TYPE_FIRST              =TYPE_INT,
      TYPE_LAST               =TYPE_VOLUME_ORDER_EXT
     };
   //--- summary flags
   enum EnFlags
     {
      FLAG_NONE               =0x0,                   // none flag
     };
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTDatasetSummary *summary)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- column id
   virtual UINT      ColumnID(void) const=0;
   virtual MTAPIRES  ColumnID(UINT column_id)=0;
   //--- line index
   virtual UINT      Line(void) const=0;
   virtual MTAPIRES  Line(UINT line)=0;
   //--- column for merging (merging from ColumnID to MergeColumn)
   virtual UINT      MergeColumn(void) const=0;
   virtual MTAPIRES  MergeColumn(UINT column_id)=0;
   //--- text color
   virtual UINT      Color(void) const=0;
   virtual MTAPIRES  Color(UINT color)=0;
   //--- flags IMTDatasetSummary::EnFlags
   virtual UINT64    Flags(void) const=0;
   virtual MTAPIRES  Flags(UINT64 flags)=0;
   //--- type IMTDatasetSummary::EnType
   virtual UINT      Type(void) const=0;
   //--- digits
   virtual UINT      Digits(void) const=0;
   virtual MTAPIRES  Digits(UINT digits)=0;
   //--- integer
   virtual INT64     ValueInt(void) const=0;
   virtual MTAPIRES  ValueInt(INT64 value)=0;
   //--- unsigned integer
   virtual UINT64    ValueUInt(void) const=0;
   virtual MTAPIRES  ValueUInt(UINT64 value)=0;
   //--- double
   virtual double    ValueDouble(void) const=0;
   virtual MTAPIRES  ValueDouble(double value)=0;
   //--- money
   virtual double    ValueMoney(void) const=0;
   virtual MTAPIRES  ValueMoney(double value)=0;
   //--- string
   virtual LPCWSTR   ValueString(void) const=0;
   virtual MTAPIRES  ValueString(LPCWSTR value)=0;
   //--- date
   virtual INT64     ValueDate(void) const=0;
   virtual MTAPIRES  ValueDate(INT64 value)=0;
   //--- time
   virtual INT64     ValueTime(void) const=0;
   virtual MTAPIRES  ValueTime(INT64 value)=0;
   //--- datetime
   virtual INT64     ValueDateTime(void) const=0;
   virtual MTAPIRES  ValueDateTime(INT64 value)=0;
   //--- price
   virtual double    ValuePrice(void) const=0;
   virtual MTAPIRES  ValuePrice(double value)=0;
   //--- prices
   virtual double    ValuePricesBid(void) const=0;
   virtual double    ValuePricesAsk(void) const=0;
   virtual MTAPIRES  ValuePrices(double value_bid,double value_ask)=0;
   //--- volume
   virtual UINT64    ValueVolume(void) const=0;
   virtual MTAPIRES  ValueVolume(UINT64 value)=0;
   //--- order volume
   virtual UINT64    ValueVolumeInitial(void) const=0;
   virtual UINT64    ValueVolumeCurrent(void) const=0;
   virtual MTAPIRES  ValueVolume(UINT64 value_initial,UINT64 value_current)=0;
   //--- volume with extended accuracy
   virtual UINT64    ValueVolumeExt(void) const=0;
   virtual MTAPIRES  ValueVolumeExt(UINT64 value)=0;
   //--- order volume with extended accuracy
   virtual UINT64    ValueVolumeExtInitial(void) const=0;
   virtual UINT64    ValueVolumeExtCurrent(void) const=0;
   virtual MTAPIRES  ValueVolumeExt(UINT64 value_initial,UINT64 value_current)=0;
   //--- explicit destructor is prohibited
protected:
                    ~IMTDatasetSummary(void) {}
  };
//+------------------------------------------------------------------+
//| Dataset interface                                                |
//+------------------------------------------------------------------+
class IMTDataset
  {
public:
   //--- flags
   enum EnDataSetFlags
     {
      DATASET_FLAG_NONE     =0x0,    // no flags
     };

public:
   //--- common methods
   virtual MTAPIRES  Assign(const IMTDataset *data)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- flags
   virtual UINT64    Flags(void) const=0;
   virtual MTAPIRES  Flags(UINT64 flags)=0;
   //--- reserved properties methods
   virtual MTAPIRES  Reserved1(void)=0;
   virtual MTAPIRES  Reserved2(void)=0;
   virtual MTAPIRES  Reserved3(void)=0;
   virtual MTAPIRES  Reserved4(void)=0;
   //--- data set column management
   virtual IMTDatasetColumn* ColumnCreate(void)=0;
   virtual MTAPIRES  ColumnClear(void)=0;
   virtual MTAPIRES  ColumnAdd(const IMTDatasetColumn *column)=0;
   virtual MTAPIRES  ColumnDelete(UINT pos)=0;
   virtual UINT      ColumnTotal(void) const=0;
   virtual UINT      ColumnSize(void) const=0;
   virtual MTAPIRES  ColumnNext(UINT pos,IMTDatasetColumn *column)=0;
   virtual MTAPIRES  ColumnReserved1(void)=0;
   virtual MTAPIRES  ColumnReserved2(void)=0;
   //--- data set row management
   virtual MTAPIRES  RowClear(void)=0;
   virtual MTAPIRES  RowWrite(const void *data,UINT size)=0;
   virtual UINT      RowTotal(void) const=0;
   virtual MTAPIRES  RowRead(UINT pos,void *data,UINT size) const=0;
   virtual MTAPIRES  RowReserved2(void)=0;
   //--- data set summary management
   virtual IMTDatasetSummary* SummaryCreate(void)=0;
   virtual MTAPIRES  SummaryClear(void)=0;
   virtual MTAPIRES  SummaryAdd(const IMTDatasetSummary *summary)=0;
   virtual MTAPIRES  SummaryDelete(UINT pos)=0;
   virtual MTAPIRES  SummaryNext(UINT pos,IMTDatasetSummary *summary)=0;
   virtual UINT      SummaryTotal(void) const=0;
   virtual MTAPIRES  SummaryReserved1(void)=0;
   virtual MTAPIRES  SummaryReserved2(void)=0;
   //--- life control
   virtual void      Release(void)=0;
   //--- explicit destructor is prohibited
protected:
                    ~IMTDataset(void) {}
  };
//+------------------------------------------------------------------+
//| Datatset request field                                           |
//+------------------------------------------------------------------+
class IMTDatasetField
  {
public:
   //--- filed type
   enum EnFieldType
     {
      TYPE_NONE                              =0,            // none
      TYPE_INT                               =1,            // integer
      TYPE_UINT                              =2,            // unsigned integer
      TYPE_DOUBLE                            =3,            // double
      TYPE_STRING                            =4,            // string
      //--- enumeration borders
      TYPE_FIRST                             =TYPE_NONE,
      TYPE_LAST                              =TYPE_STRING
     };
   //--- Request fields id enumeration
   enum EnFieldId
     {
      //--- User fields enumeration
      FIELD_USER_LOGIN                       =1,            // UINT64      , login
      FIELD_USER_GROUP                       =2,            // wchar_t[64] , group
      FIELD_USER_CERT_SERIAL_NUMBER          =3,            // UINT64      , certificate serial number
      FIELD_USER_RIGHTS                      =4,            // UINT64      , EnUsersRights
      FIELD_USER_REGISTRATION                =5,            // INT64       , registration datetime (filled by MT5)
      FIELD_USER_LAST_ACCESS                 =6,            // INT64       , last access datetime (filled by MT5)
      FIELD_USER_NAME                        =7,            // wchar_t[256], name
      FIELD_USER_COMPANY                     =8,            // wchar_t[32] , company
      FIELD_USER_ACCOUNT                     =9,            // wchar_t[64] , external system account (exchange, ECN, etc)
      FIELD_USER_COUNTRY                     =10,           // wchar_t[32] , country
      FIELD_USER_LANGUAGE                    =11,           // UINT        , client language (WinAPI LANGID)
      FIELD_USER_CITY                        =12,           // wchar_t[32] , city
      FIELD_USER_STATE                       =13,           // wchar_t[32] , state
      FIELD_USER_ZIP_CODE                    =14,           // wchar_t[16] , ZIP code
      FIELD_USER_ADDRESS                     =15,           // wchar_t[128], address
      FIELD_USER_PHONE                       =16,           // wchar_t[32] , phone
      FIELD_USER_EMAIL                       =17,           // wchar_t[64] , email
      FIELD_USER_ID                          =18,           // wchar_t[32] , additional ID
      FIELD_USER_STATUS                      =19,           // wchar_t[16] , additional status
      FIELD_USER_COMMENT                     =20,           // wchar_t[64] , comment
      FIELD_USER_COLOR                       =21,           // UINT        , color (WinAPI COLORREF)
      FIELD_USER_PHONE_PASSWORD              =22,           // wchar_t[32] , phone password
      FIELD_USER_LEVERAGE                    =23,           // UINT        , leverage
      FIELD_USER_AGENT                       =24,           // UINT64      , agent account
      FIELD_USER_BALANCE                     =25,           // double      , balance
      FIELD_USER_CREDIT                      =26,           // double      , credit
      FIELD_USER_INTEREST_RATE               =27,           // double      , accumulated interest rate
      FIELD_USER_COMMISSION_DAILY            =28,           // double      , accumulated daily commissions
      FIELD_USER_COMMISSION_MONTHLY          =29,           // double      , accumulated monthly commissions
      FIELD_USER_COMMISSION_AGENT_DAILY      =30,           // double      , accumulated daily agent commissions
      FIELD_USER_COMMISSION_AGENT_MONTHLY    =31,           // double      , accumulated monthly agent commissions
      FIELD_USER_BALANCE_PREV_DAY            =32,           // double      , previous day balance state
      FIELD_USER_BALANCE_PREV_MONTH          =33,           // double      , previous month balance state
      FIELD_USER_EQUITY_PREV_DAY             =34,           // double      , previous day equity state
      FIELD_USER_EQUITY_PREV_MONTH           =35,           // double      , previous month equity state
      FIELD_USER_LAST_PASS_CHANGE            =36,           // INT64       , last password change datetime (filled by MT5)
      FIELD_USER_MQID                        =37,           // UINT        , client's MetaQuotes ID
      FIELD_USER_LEAD_CAMPAIGN               =38,           // wchar_t[32] , lead campaign
      FIELD_USER_LEAD_SOURCE                 =39,           // wchar_t[32] , lead source
      FIELD_USER_CLIENT_ID                   =40,           // UINT64      , client id
      FIELD_USER_FIRST_NAME                  =41,           // wchar_t[128], first name
      FIELD_USER_LAST_NAME                   =42,           // wchar_t[64] , last name
      FIELD_USER_MIDDLE_NAME                 =43,           // wchar_t[64] , middle name
      //--- User fields enumeration borders
      FIELD_USER_FIRST                       =FIELD_USER_LOGIN,
      FIELD_USER_LAST                        =FIELD_USER_MIDDLE_NAME,
      //--- Client fields enumeration
      FIELD_CLIENT_ID                        =1001,         // UINT64      , client id
      FIELD_CLIENT_CREATED_TIME              =1002,         // INT64       , creation date and time
      FIELD_CLIENT_CREATED_BY                =1003,         // UINT64      , login of manager who created the client
      FIELD_CLIENT_MODIFIED_TIME             =1004,         // INT64       , modification date
      FIELD_CLIENT_MODIFIED_BY               =1005,         // UINT64      , login of manager who modified the client
      FIELD_CLIENT_TYPE                      =1006,         // UINT        , client type (EnClientType)
      FIELD_CLIENT_STATUS                    =1007,         // UINT        , client status (EnClientStatus)
      FIELD_CLIENT_ASSIGNED_MANAGER          =1008,         // UINT64      , assigned manager login
      FIELD_CLIENT_COMMENT                   =1009,         // wchar_t[128], comment
      FIELD_CLIENT_COMPLIANCE_APPROVED_BY    =1010,         // UINT64      , login of manager who approved the client
      FIELD_CLIENT_COMPLIANCE_CLIENT_CATEGORY=1011,         // wchar_t[64] , customer classification according to the rules of the local regulator
      FIELD_CLIENT_COMPLIANCE_TIME_APPROVAL  =1012,         // INT64       , approval date and time
      FIELD_CLIENT_COMPLIANCE_TIME_TERMINATION=1013,        // INT64       , agreement termination date and time
      FIELD_CLIENT_LEAD_CAMPAIGN             =1014,         // wchar_t[64] , lead campaign
      FIELD_CLIENT_LEAD_SOURCE               =1015,         // wchar_t[64] , lead source
      FIELD_CLIENT_INTRODUCER                =1016,         // wchar_t[32] , IB or Referal
      FIELD_CLIENT_PERSON_TITLE              =1017,         // wchar_t[16] , title
      FIELD_CLIENT_PERSON_NAME               =1018,         // wchar_t[32] , first name
      FIELD_CLIENT_PERSON_MIDDLE_NAME        =1019,         // wchar_t[32] , middle name
      FIELD_CLIENT_PERSON_LAST_NAME          =1020,         // wchar_t[32] , second name
      FIELD_CLIENT_PERSON_BIRTH_DATE         =1021,         // INT64       , date of birth (file time, number of 100-nanosecond since 12:00 A.M. January 1, 1601 UTC)
      FIELD_CLIENT_PERSON_CITIZENSHIP        =1022,         // wchar_t[64] , citizenship
      FIELD_CLIENT_PERSON_GENDER             =1023,         // UINT        , gender (EnGender)
      FIELD_CLIENT_PERSON_TAX_ID             =1024,         // wchar_t[64] , tax id
      FIELD_CLIENT_PERSON_DOCUMENT_TYPE      =1025,         // wchar_t[16] , document type
      FIELD_CLIENT_PERSON_DOCUMENT_NUMBER    =1026,         // wchar_t[32] , document number
      FIELD_CLIENT_PERSON_DOCUMENT_DATE      =1027,         // INT64       , document issue or expiration date
      FIELD_CLIENT_PERSON_DOCUMENT_EXTRA     =1028,         // wchar_t[64] , document extra data
      FIELD_CLIENT_PERSON_EMPLOYMENT         =1029,         // UINT        , employment status (EnEmployment)
      FIELD_CLIENT_PERSON_INDUSTRY           =1030,         // UINT        , employment industry (EnEmploymentIndustry)
      FIELD_CLIENT_PERSON_EDUCATION          =1031,         // UINT        , education level (EnEducationLevel)
      FIELD_CLIENT_PERSON_WEALTH_SOURCE      =1032,         // UINT        , wealth source (EnWealthSource)
      FIELD_CLIENT_PERSON_ANNUAL_INCOME      =1033,         // double      , annual income, USD
      FIELD_CLIENT_PERSON_NET_WORTH          =1034,         // double      , net worth, USD
      FIELD_CLIENT_PERSON_ANNUAL_DEPOSIT     =1035,         // double      , annual deposit, USD
      FIELD_CLIENT_COMPANY_NAME              =1036,         // wchar_t[64] , company name
      FIELD_CLIENT_COMPANY_REG_NUMBER        =1037,         // wchar_t[64] , company registration number
      FIELD_CLIENT_COMPANY_REG_DATE          =1038,         // INT64       , company registration date
      FIELD_CLIENT_COMPANY_REG_AUTHORITY     =1039,         // wchar_t[64] , company registration authority
      FIELD_CLIENT_COMPANY_VAT               =1040,         // wchar_t[64] , VAT registration number
      FIELD_CLIENT_COMPANY_LEI               =1041,         // wchar_t[64] , EI number for EMIR reports
      FIELD_CLIENT_COMPANY_LICENSE_NUMBER    =1042,         // wchar_t[64] , license number
      FIELD_CLIENT_COMPANY_LICENSE_AUTHORITY =1043,         // wchar_t[64] , license issuer authority
      FIELD_CLIENT_COMPANY_COUNTRY           =1044,         // wchar_t[64] , company registration country
      FIELD_CLIENT_COMPANY_ADDRESS           =1045,         // wchar_t[64] , company registration address
      FIELD_CLIENT_COMPANY_WEBSITE           =1046,         // wchar_t[64] , company website
      FIELD_CLIENT_CONTACT_PREFERRED         =1047,         // UINT        , preferred communication type
      FIELD_CLIENT_CONTACT_LANGUAGE          =1048,         // wchar_t[64] , communication language
      FIELD_CLIENT_CONTACT_EMAIL             =1049,         // wchar_t[64] , email (or multiple comma-separated emails)
      FIELD_CLIENT_CONTACT_PHONE             =1050,         // wchar_t[128], phone numbers (or multiple comma-separated phone numbers)
      FIELD_CLIENT_CONTACT_MESSENGERS        =1051,         // wchar_t[128], messengers in format: "skype:username, qq:5454535454"
      FIELD_CLIENT_CONTACT_SOCIALNETWORKS    =1052,         // wchar_t[128], social networks ids: "fb:user_id, vk:user_id"
      FIELD_CLIENT_CONTACT_LAST_DATE         =1053,         // INT64       , date and time of the last contact
      FIELD_CLIENT_ADDRESS_COUNTRY           =1054,         // wchar_t[64] , address - country
      FIELD_CLIENT_ADDRESS_POSTCODE          =1055,         // wchar_t[16] , address - zip code
      FIELD_CLIENT_ADDRESS_STREET            =1056,         // wchar_t[128], address - street address
      FIELD_CLIENT_ADDRESS_STATE             =1057,         // wchar_t[64] , address - state, province or district
      FIELD_CLIENT_ADDRESS_CITY              =1058,         // wchar_t[64] , address - city or town
      FIELD_CLIENT_EXPERIENCE_FX             =1059,         // UINT        , Forex trading experience (EnTradingExperience)
      FIELD_CLIENT_EXPERIENCE_CFD            =1060,         // UINT        , CFD trading experience (EnTradingExperience)
      FIELD_CLIENT_EXPERIENCE_FUTURES        =1061,         // UINT        , futures trading experience (EnTradingExperience)
      FIELD_CLIENT_EXPERIENCE_STOCKS         =1062,         // UINT        , stocks trading experience (EnTradingExperience)
      //--- Client fields enumeration borders
      FIELD_CLIENT_FIRST                     =FIELD_CLIENT_ID,
      FIELD_CLIENT_LAST                      =FIELD_CLIENT_EXPERIENCE_STOCKS,
      //--- Deal fields enumeration
      FIELD_DEAL_DEAL                        =2001,         // UINT64      , deal ticket
      FIELD_DEAL_EXTERNAL_ID                 =2002,         // wchar_t[32] , deal ticket in external system (exchange, ECN, etc)
      FIELD_DEAL_LOGIN                       =2003,         // UINT64      , client login
      FIELD_DEAL_DEALER                      =2004,         // UINT64      , processed dealer login (0-means auto)
      FIELD_DEAL_ORDER                       =2005,         // UINT64      , deal order ticket
      FIELD_DEAL_ACTION                      =2006,         // UINT        , IMTDeal::EnDealAction
      FIELD_DEAL_ENTRY                       =2007,         // UINT        , IMTDeal::EnDealEntry
      FIELD_DEAL_DIGITS                      =2008,         // UINT        , price digits
      FIELD_DEAL_DIGITS_CURRENCY             =2009,         // UINT        , currency digits
      FIELD_DEAL_CONTRACT_SIZE               =2010,         // double      , symbol contract size
      FIELD_DEAL_TIME                        =2011,         // INT64       , deal creation datetime in seconds
      FIELD_DEAL_SYMBOL                      =2012,         // wchar_t[32] , deal symbol
      FIELD_DEAL_PRICE                       =2013,         // double      , deal price
      FIELD_DEAL_VOLUME_EXT                  =2014,         // UINT64      , deal volume with extended accuracy
      FIELD_DEAL_PROFIT                      =2015,         // double      , deal profit
      FIELD_DEAL_STORAGE                     =2016,         // double      , deal collected swaps
      FIELD_DEAL_COMMISSION                  =2017,         // double      , deal commission
      FIELD_DEAL_RATE_PROFIT                 =2018,         // double      , profit conversion rate (from symbol profit currency to deposit currency)
      FIELD_DEAL_RATE_MARGIN                 =2019,         // double      , margin conversion rate (from symbol margin currency to deposit currency)
      FIELD_DEAL_EXPERT_ID                   =2020,         // UINT64      , expert id (filled by expert advisor)
      FIELD_DEAL_POSITION_ID                 =2021,         // UINT64      , position id
      FIELD_DEAL_COMMENT                     =2022,         // wchar_t[32] , deal comment
      FIELD_DEAL_PROFIT_RAW                  =2023,         // double      , deal profit in symbol's profit currency
      FIELD_DEAL_PRICE_POSITION              =2024,         // double      , closed position  price
      FIELD_DEAL_VOLUME_CLOSED_EXT           =2025,         // UINT64      , closed volume with extended accuracy
      FIELD_DEAL_TICK_VALUE                  =2026,         // double      , tick value
      FIELD_DEAL_TICK_SIZE                   =2027,         // double      , tick size
      FIELD_DEAL_FLAGS                       =2028,         // UINT64      , flags
      FIELD_DEAL_TIME_MSC                    =2029,         // INT64       , deal creation datetime in msc since 1970.01.01
      FIELD_DEAL_REASON                      =2030,         // UINT        , EnDealReason
      FIELD_DEAL_GATEWAY                     =2031,         // wchar_t[16] , source gateway name
      FIELD_DEAL_PRICE_GATEWAY               =2032,         // double      , deal price on gateway
      FIELD_DEAL_MODIFICATION_FLAGS          =2033,         // UINT        , modification flags
      FIELD_DEAL_PRICE_SL                    =2034,         // double      , order SL
      FIELD_DEAL_PRICE_TP                    =2035,         // double      , order TP
      FIELD_DEAL_FEE                         =2036,         // double      , fee
      FIELD_DEAL_VALUE                       =2037,         // double      , value
      //--- Deal fields enumeration borders
      FIELD_DEAL_FIRST                       =FIELD_DEAL_DEAL,
      FIELD_DEAL_LAST                        =FIELD_DEAL_VALUE,
      //--- Order fields enumeration
      FIELD_ORDER_ORDER                      =3001,        // UINT64      , order ticket
      FIELD_ORDER_EXTERNAL_ID                =3002,        // wchar_t[32] , order ticket in external system (exchange, ECN, etc)
      FIELD_ORDER_LOGIN                      =3003,        // UINT64      , client login
      FIELD_ORDER_DEALER                     =3004,        // UINT64      , processed dealer login (0-means auto)
      FIELD_ORDER_SYMBOL                     =3005,        // wchar_t[32] , order symbol
      FIELD_ORDER_TIME_SETUP                 =3006,        // INT64       , time of order reception from a client into the system
      FIELD_ORDER_TIME_EXPIRATION            =3007,        // INT64       , order expiration time
      FIELD_ORDER_TIME_DONE                  =3008,        // INT64       , order cancellation time
      FIELD_ORDER_TYPE                       =3009,        // UINT        , order type
      FIELD_ORDER_TYPE_FILL                  =3010,        // UINT        , order type by filling
      FIELD_ORDER_TYPE_TIME                  =3011,        // UINT        , order type by time
      FIELD_ORDER_TYPE_REASON                =3012,        // UINT        , order creation reason
      FIELD_ORDER_PRICE_ORDER                =3013,        // double      , order price
      FIELD_ORDER_PRICE_TRIGGER              =3014,        // double      , order execution price
      FIELD_ORDER_PRICE_CURRENT              =3015,        // double      , current order price
      FIELD_ORDER_PRICE_SL                   =3016,        // double      , stop-loss price
      FIELD_ORDER_PRICE_TP                   =3017,        // double      , take-profit price
      FIELD_ORDER_VOLUME_INITIAL             =3018,        // UINT64      , starting order volume
      FIELD_ORDER_VOLUME_CURRENT             =3019,        // UINT64      , current order volume
      FIELD_ORDER_STATE                      =3020,        // UINT        , actual order state
      FIELD_ORDER_EXPERT_ID                  =3021,        // UINT64      , expert ID
      FIELD_ORDER_POSITION_ID                =3022,        // UINT64      , position ID which the order opens or closes
      FIELD_ORDER_COMMENT                    =3023,        // wchar_t[32] , order comment
      FIELD_ORDER_CONTRACT_SIZE              =3024,        // double      , order contract size
      FIELD_ORDER_DIGITS                     =3025,        // UINT        , number of digits of order symbol
      FIELD_ORDER_DIGITS_CURRENCY            =3026,        // UINT        , number of digits of order currency
      FIELD_ORDER_POSITION_BY_ID             =3027,        // UINT64      , counter Position ID for Close-By orders
      FIELD_ORDER_MARGIN_RATE                =3028,        // double      , margin conversion rate at the creation time
      FIELD_ORDER_TIME_SETUP_MSC             =3029,        // INT64       , order reception from a client into the system in milliseconds
      FIELD_ORDER_TIME_DONE_MSC              =3030,        // INT64       , order cancellation time in milliseconds
      FIELD_ORDER_MODIFICATION_FLAGS         =3031,        // UINT        , order modification flags
      FIELD_ORDER_ACTIVATION_MODE            =3032,        // UINT        , order activation mode (for manager)
      FIELD_ORDER_ACTIVATION_TIME            =3033,        // INT64       , order activation time (for manager)
      FIELD_ORDER_ACTIVATION_PRICE           =3034,        // double      , order activation price (for manager)
      FIELD_ORDER_ACTIVATION_FLAGS           =3035,        // UINT        , order activation flags
      FIELD_ORDER_GROUP                      =3036,        // wchar_t[64] , group (only for open orders)
      //--- Order fields enumeration borders
      FIELD_ORDER_FIRST                      =FIELD_ORDER_ORDER,
      FIELD_ORDER_LAST                       =FIELD_ORDER_GROUP,
      //--- Daily report fields enumeration
      FIELD_DAILY_DATE_TIME                  =4001,        // INT64       , report generation date and time
      FIELD_DAILY_DATE_TIME_PREV             =4002,        // INT64       , date and time of previous report generation
      FIELD_DAILY_LOGIN                      =4003,        // UINT64      , login
      FIELD_DAILY_NAME                       =4004,        // wchar_t[128], name
      FIELD_DAILY_GROUP                      =4005,        // wchar_t[64] , group
      FIELD_DAILY_CURRENCY                   =4006,        // wchar_t[32] , currency
      FIELD_DAILY_DIGITS_CURRENCY            =4007,        // UINT        , number of digits of report currency
      FIELD_DAILY_COMPANY                    =4008,        // wchar_t[64] , company
      FIELD_DAILY_EMAIL                      =4009,        // wchar_t[64] , e-mail
      FIELD_DAILY_BALANCE                    =4010,        // double      , balance
      FIELD_DAILY_CREDIT                     =4011,        // double      , credit
      FIELD_DAILY_INTEREST_RATE              =4012,        // double      , interest rate
      FIELD_DAILY_COMMISSION_DAILY           =4013,        // double      , commission daily
      FIELD_DAILY_COMMISSION_MONTHLY         =4014,        // double      , commission monthly
      FIELD_DAILY_AGENT_DAILY                =4015,        // double      , commission daily
      FIELD_DAILY_AGENT_MONTHLY              =4016,        // double      , commission monthly
      FIELD_DAILY_BALANCE_PREV_DAY           =4017,        // double      , last day balance
      FIELD_DAILY_BALANCE_PREV_MONTH         =4018,        // double      , last month balance
      FIELD_DAILY_EQUITY_PREV_DAY            =4019,        // double      , last day equity
      FIELD_DAILY_EQUITY_PREV_MONTH          =4020,        // double      , last month equity
      FIELD_DAILY_MARGIN                     =4021,        // double      , margin
      FIELD_DAILY_MARGIN_FREE                =4022,        // double      , free margin 
      FIELD_DAILY_MARGIN_LEVEL               =4023,        // double      , margin level
      FIELD_DAILY_MARGIN_LEVERAGE            =4024,        // UINT        , margin leverage
      FIELD_DAILY_PROFIT                     =4025,        // double      , floating profit
      FIELD_DAILY_PROFIT_STORAGE             =4026,        // double      , storage
      FIELD_DAILY_PROFIT_COMMISSION          =4027,        // double      , commission
      FIELD_DAILY_PROFIT_EQUITY              =4028,        // double      , equity
      FIELD_DAILY_DAILY_PROFIT               =4029,        // double      , daily fixed profit details
      FIELD_DAILY_DAILY_BALANCE              =4030,        // double      , daily balance operations
      FIELD_DAILY_DAILY_CREDIT               =4031,        // double      , daily credit operations
      FIELD_DAILY_DAILY_CHARGE               =4032,        // double      , fees per day
      FIELD_DAILY_DAILY_CORRECTION           =4033,        // double      , correction for the day
      FIELD_DAILY_DAILY_BONUS                =4034,        // double      , bonuses per day
      FIELD_DAILY_DAILY_STORAGE              =4035,        // double      , closed positions swap
      FIELD_DAILY_DAILY_COMM_INSTANT         =4036,        // double      , commission charged immediately
      FIELD_DAILY_DAILY_COMM_ROUND           =4037,        // double      , deferred commission
      FIELD_DAILY_DAILY_AGENT                =4038,        // double      , agency commissions per day
      FIELD_DAILY_DAILY_INTEREST             =4039,        // double      , interest per day
      FIELD_DAILY_PROFIT_ASSETS              =4040,        // double      , assets
      FIELD_DAILY_PROFIT_LIABILITIES         =4041,        // double      , liabilities
      //--- Daily report fields enumeration borders
      FIELD_DAILY_FIRST                      =FIELD_DAILY_DATE_TIME,
      FIELD_DAILY_LAST                       =FIELD_DAILY_PROFIT_LIABILITIES,
      //--- Position fields enumeration
      FIELD_POSITION_LOGIN                   =5001,        // UINT64      , owner client login
      FIELD_POSITION_SYMBOL                  =5002,        // wchar_t[32] , position symbol
      FIELD_POSITION_ACTION                  =5003,        // UINT        , EnPositionAction
      FIELD_POSITION_DIGITS                  =5004,        // UINT        , number of digits of order symbol
      FIELD_POSITION_DIGITS_CURRENCY         =5005,        // UINT        , number of digits of order currency
      FIELD_POSITION_CONTRACT_SIZE           =5006,        // double      , symbol contract size
      FIELD_POSITION_TIME_CREATE             =5007,        // INT64       , position create time
      FIELD_POSITION_TIME_UPDATE             =5008,        // INT64       , position last update time
      FIELD_POSITION_PRICE_OPEN              =5009,        // double      , position weighted average open price
      FIELD_POSITION_PRICE_CURRENT           =5010,        // double      , position current price
      FIELD_POSITION_PRICE_SL                =5011,        // double      , position SL price
      FIELD_POSITION_PRICE_TP                =5012,        // double      , position TP price
      FIELD_POSITION_VOLUME                  =5013,        // UINT64      , position volume
      FIELD_POSITION_PROFIT                  =5014,        // double      , position floating profit
      FIELD_POSITION_STORAGE                 =5015,        // double      , position accumulated swaps
      FIELD_POSITION_RATE_PROFIT             =5016,        // double      , profit conversion rate (from symbol profit currency to deposit currency)
      FIELD_POSITION_RATE_MARGIN             =5017,        // double      , margin conversion rate (from symbol margin currency to deposit currency)
      FIELD_POSITION_EXPERT_ID               =5018,        // UINT64      , expert id (filled by expert advisor)
      FIELD_POSITION_EXPERT_POSITION_ID      =5019,        // UINT64      , expert position id
      FIELD_POSITION_COMMENT                 =5020,        // wchar_t[32] , comment
      FIELD_POSITION_ACTIVATION_MODE         =5021,        // UINT        , order activation state, time and price
      FIELD_POSITION_ACTIVATION_TIME         =5022,        // INT64       , activation mode
      FIELD_POSITION_ACTIVATION_PRICE        =5023,        // double      , activation time
      FIELD_POSITION_ACTIVATION_FLAGS        =5024,        // UINT        , activation flags
      FIELD_POSITION_TIME_CREATE_MSC         =5025,        // INT64       , position create time in msc since 1970.01.01
      FIELD_POSITION_TIME_UPDATE_MSC         =5026,        // INT64       , position last update time in msc since 1970.01.01
      FIELD_POSITION_DEALER                  =5027,        // UINT64      , processed dealer login (0-means auto) (first position deal dealer)
      FIELD_POSITION_POSITION                =5028,        // UINT64      , position ticket
      FIELD_POSITION_EXTERNAL_ID             =5029,        // wchar_t[32] , position ticket in external system (exchange, ECN, etc)
      FIELD_POSITION_MODIFICATION_FLAGS      =5030,        // UINT        , modification flags
      FIELD_POSITION_REASON                  =5031,        // UINT        , position reason - EnPositionReason
      FIELD_POSITION_VOLUME_EXT              =5032,        // UINT64      , position volume
      FIELD_POSITION_GROUP                   =5033,        // wchar_t[64] , group
      //--- Position fields enumeration borders
      FIELD_POSITION_FIRST                   =FIELD_POSITION_LOGIN,
      FIELD_POSITION_LAST                    =FIELD_POSITION_GROUP,
      //--- Trade account fields enumeration
      FIELD_ACCOUNT_LOGIN                    =6001,        // UINT64      , login
      FIELD_ACCOUNT_GROUP                    =6002,        // wchar_t[64] , group
      FIELD_ACCOUNT_CURRENCY_DIGITS          =6003,        // UINT        , currency digits
      FIELD_ACCOUNT_BALANCE                  =6004,        // double      , balance
      FIELD_ACCOUNT_CREDIT                   =6005,        // double      , credit
      FIELD_ACCOUNT_MARGIN                   =6006,        // double      , margin
      FIELD_ACCOUNT_MARGIN_FREE              =6007,        // double      , free margin
      FIELD_ACCOUNT_MARGIN_LEVEL             =6008,        // double      , margin level
      FIELD_ACCOUNT_MARGIN_LEVERAGE          =6009,        // UINT        , margin leverage
      FIELD_ACCOUNT_MARGIN_INITIAL           =6010,        // double      , account initial margin
      FIELD_ACCOUNT_MARGIN_MAINTENANCE       =6011,        // double      , account maintenance margin 
      FIELD_ACCOUNT_PROFIT                   =6012,        // double      , floating profit
      FIELD_ACCOUNT_STORAGE                  =6013,        // double      , storage
      FIELD_ACCOUNT_COMMISSION               =6014,        // double      , commission
      FIELD_ACCOUNT_FLOATING                 =6015,        // double      , cumulative floating
      FIELD_ACCOUNT_EQUITY                   =6016,        // double      , equity
      FIELD_ACCOUNT_BLOCKED_COMMISSION       =6017,        // double      , blocked daily & monthly commission
      FIELD_ACCOUNT_BLOCKED_PROFIT           =6018,        // double      , blocked fixed profit
      FIELD_ACCOUNT_ASSETS                   =6019,        // double      , account assets
      FIELD_ACCOUNT_LIABILITIES              =6020,        // double      , account liabilities
      FIELD_ACCOUNT_STOP_OUT_ACTIVATION      =6021,        // UINT        , stop-out activation mode
      FIELD_ACCOUNT_STOP_OUT_TIME            =6022,        // INT64       , stop-out activation time
      FIELD_ACCOUNT_STOP_OUT_LEVEL           =6023,        // double      , margin level on stop-out 
      FIELD_ACCOUNT_STOP_OUT_EQUITY          =6024,        // double      , equity on stop-out
      FIELD_ACCOUNT_STOP_OUT_MARGIN          =6025,        // double      , margin on stop-out
      //--- Trade account fields enumeration borders
      FIELD_ACCOUNT_FIRST                    =FIELD_ACCOUNT_LOGIN,
      FIELD_ACCOUNT_LAST                     =FIELD_ACCOUNT_LIABILITIES,
      //--- enumeration borders
      FIELD_FIRST                            =FIELD_USER_FIRST,
      FIELD_LAST                             =FIELD_ACCOUNT_LAST
     };
   //--- flags
   enum EnFieldFlags
     {
      FLAG_NONE                              =0x0000000,    // none
      FLAG_SELECT                            =0x0000001,    // select field
      //--- enumeration borders
      FLAG_DEFAULT                           =FLAG_SELECT,
      FLAG_ALL                               =FLAG_SELECT
     };
   //--- gender enumeration
   enum EnGender
     {
      GENDER_UNSPECIFIED                     =0,            // unspecified
      GENDER_MALE                            =1,            // male
      GENDER_FEMALE                          =2,            // female
      //--- enumeration borders
      GENDER_FIRST                           =GENDER_UNSPECIFIED,
      GENDER_LAST                            =GENDER_FEMALE
     };
   //--- client type enumeration
   enum EnClientType
     {
      CLIENT_TYPE_UNDEFINED                  =0,            // undefined
      CLIENT_TYPE_INDIVIDUAL                 =1,            // individual
      CLIENT_TYPE_CORPORATE                  =2,            // corporate
      CLIENT_TYPE_FUND                       =3,            // fund
      //--- enumeration borders
      CLIENT_TYPE_FIRST                      =CLIENT_TYPE_UNDEFINED,
      CLIENT_TYPE_LAST                       =CLIENT_TYPE_FUND
     };
   //--- client status enumeration
   enum EnClientStatus
     {
      //--- Not a client yet - Demo accounts
      CLIENT_STATUS_UNREGISTERED             =0,            // Anonymous user (demo account without data)
      CLIENT_STATUS_REGISTERED               =100,          // The user who opened a demo account and left contact information (lead)
      CLIENT_STATUS_NOTINTERESTED            =200,          // The user who left the contact information, but does not want to open an account
      //--- Not a client yet - Preliminary
      CLIENT_STATUS_APPLICATION_INCOMPLETED  =300,          // The user who filled out the form to open a real account
      CLIENT_STATUS_APPLICATION_COMPLETED    =400,          // The user who filled out the questionnaire to open a real account and provided all the documents
      CLIENT_STATUS_APPLICATION_INFORMATION  =500,          // User to open an account that requires additional information
      CLIENT_STATUS_APPLICATION_REJECTED     =600,          // The user who filled out the questionnaire to open a real account but to whom the account was not opened according to the results of the verification of documents
      //--- Client
      CLIENT_STATUS_APPROVED                 =700,          // The client who opened a real account
      CLIENT_STATUS_FUNDED                   =800,          // Customer with a real account refilled
      CLIENT_STATUS_ACTIVE                   =900,          // A client with a real account with money that made at least one transaction in the last 90 days
      CLIENT_STATUS_INACTIVE                 =1000,         // A client with a real money account that has not been traded in the past 90 days
      CLIENT_STATUS_SUSPENDED                =1100,         // Client with a real account, trading on which is suspended at the initiative of the company
      //--- No longer client
      CLIENT_STATUS_CLOSED                   =1200,         // Client who had a real account (s) and who closed them on his own initiative
      CLIENT_STATUS_TERMINATED               =1300,         // The client who had a real account (s), with which the contract was terminated at the initiative of the company
      //--- enumeration borders
      CLIENT_STATUS_FIRST                    =CLIENT_STATUS_UNREGISTERED,
      CLIENT_STATUS_LAST                     =CLIENT_STATUS_TERMINATED
     };
   //--- employment status enumeration
   enum EnEmployment
     {
      EMPLOY_UNEMPLOYED                      =0,            // unemployed
      EMPLOY_EMPLOYED                        =1,            // employed
      EMPLOY_SELF_EMPLOYED                   =2,            // self employed
      EMPLOY_RETIRED                         =3,            // retired
      EMPLOY_STUDENT                         =4,            // student
      EMPLOY_OTHER                           =5,            // other
      //--- enumeration borders
      EMPLOY_FIRST                           =EMPLOY_UNEMPLOYED,
      EMPLOY_LAST                            =EMPLOY_OTHER
     };
   //--- employment industry enumeration
   enum EnEmploymentIndustry
     {
      INDUSTRY_NONE                          =0,            // none
      INDUSTRY_AGRICULTURE                   =1,            // agriculture
      INDUSTRY_CONSTRUCTION                  =2,            // construction
      INDUSTRY_MANAGEMENT                    =3,            // management
      INDUSTRY_COMMUNICATION                 =4,            // communication
      INDUSTRY_EDUCATION                     =5,            // education
      INDUSTRY_GOVERNMENT                    =6,            // government
      INDUSTRY_HEALTHCARE                    =7,            // healthcare
      INDUSTRY_TOURISM                       =8,            // tourism
      INDUSTRY_IT                            =9,            // IT
      INDUSTRY_SECURITY                      =10,           // security
      INDUSTRY_MANUFACTURING                 =11,           // manufacturing
      INDUSTRY_MARKETING                     =12,           // marketing
      INDUSTRY_SCIENCE                       =13,           // science
      INDUSTRY_ENGINEERING                   =14,           // engineering
      INDUSTRY_TRANSPORT                     =15,           // transport
      INDUSTRY_OTHER                         =16,           // other
      //--- enumeration borders
      INDUSTRY_FIRST                         =INDUSTRY_AGRICULTURE,
      INDUSTRY_LAST                          =INDUSTRY_OTHER
     };
   //--- education level enumeration
   enum EnEducationLevel
     {
      EDUCATION_LEVEL_NONE                   =0,            // none
      EDUCATION_LEVEL_HIGH_SCHOOL            =1,            // high school
      EDUCATION_LEVEL_BACHELOR               =2,            // bachelor
      EDUCATION_LEVEL_MASTER                 =3,            // master
      EDUCATION_LEVEL_PHD                    =4,            // PhD
      EDUCATION_LEVEL_OTHER                  =5,            // other
      //--- enumeration borders
      EDUCATION_LEVEL_FIRST                  =EDUCATION_LEVEL_NONE,
      EDUCATION_LEVEL_LAST                   =EDUCATION_LEVEL_OTHER
     };
   //--- wealth source enumeration
   enum EnWealthSource
     {
      WEALTH_SOURCE_EMPLOYMENT               =0,            // employment
      WEALTH_SOURCE_SAVINGS                  =1,            // savings
      WEALTH_SOURCE_INHERITANCE              =2,            // inheritance
      WEALTH_SOURCE_OTHER                    =3,            // other
      //--- enumeration borders
      WEALTH_SOURCE_FIRST                    =WEALTH_SOURCE_EMPLOYMENT,
      WEALTH_SOURCE_LAST                     =WEALTH_SOURCE_OTHER
     };
   //--- preferred communication enumeration
   enum EnPreferredCommunication
     {
      PREFERRED_COMMUNICATION_UNDEFINED      =0,            // undefined
      PREFERRED_COMMUNICATION_EMAIL          =1,            // email
      PREFERRED_COMMUNICATION_PHONE          =2,            // phone
      PREFERRED_COMMUNICATION_PHONE_SMS      =3,            // phone SMS
      PREFERRED_COMMUNICATION_MESSENGER      =4,            // messenger
      //--- enumeration borders
      PREFERRED_COMMUNICATION_FIRST          =PREFERRED_COMMUNICATION_UNDEFINED,
      PREFERRED_COMMUNICATION_LAST           =PREFERRED_COMMUNICATION_MESSENGER
     };
   //--- trading experience enumeration
   enum EnTradingExperience
     {
      EXPERIENCE_LESS_1_YEAR                 =0,            // less than 1 year
      EXPERIENCE_1_3_YEAR                    =1,            // 1 to 3 years
      EXPERIENCE_ABOVE_3_YEAR                =2,            // above 3 years
      //--- enumeration borders
      EXPERIENCE_FIRST                       =EXPERIENCE_LESS_1_YEAR,
      EXPERIENCE_LAST                        =EXPERIENCE_ABOVE_3_YEAR
     };

public:
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTDatasetField *field)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- field id, EnFieldId
   virtual UINT      Id(void) const=0;
   virtual MTAPIRES  Id(UINT id)=0;
   //--- type, EnFieldType
   virtual UINT      Type(void) const=0;
   //--- offset in bytes
   virtual UINT      Offset(void) const=0;
   virtual MTAPIRES  Offset(UINT offset)=0;
   //--- size in bytes
   virtual UINT      Size(void) const=0;
   virtual MTAPIRES  Size(UINT size)=0;
   //--- flags, EnFieldFlags
   virtual UINT64    Flags(void) const=0;
   virtual MTAPIRES  Flags(UINT64 flags)=0;
   //--- reserved properties methods
   virtual MTAPIRES  Reserved1(void)=0;
   virtual MTAPIRES  Reserved2(void)=0;
   virtual MTAPIRES  Reserved3(void)=0;
   virtual MTAPIRES  Reserved4(void)=0;
   //--- add where value(s)
   virtual MTAPIRES  WhereAddInt(INT64 value)=0;
   virtual MTAPIRES  WhereAddIntArray(const INT64 *values,UINT values_total)=0;
   virtual MTAPIRES  WhereAddUInt(UINT64 value)=0;
   virtual MTAPIRES  WhereAddUIntArray(const UINT64 *values,UINT values_total)=0;
   virtual MTAPIRES  WhereAddDouble(double value)=0;
   virtual MTAPIRES  WhereAddDoubleArray(const double *values,UINT values_total)=0;
   virtual MTAPIRES  WhereAddString(LPCWSTR value)=0;
   virtual MTAPIRES  WhereAddStringArray(LPCWSTR *values,UINT values_total)=0;
   //--- set pointer to descending sorted array with where values
   virtual MTAPIRES  WhereUIntSet(const UINT64 *values,UINT values_total)=0;
   //--- reserved where methods
   virtual MTAPIRES  WhereReserved1(void)=0;
   virtual MTAPIRES  WhereReserved2(void)=0;
   virtual MTAPIRES  WhereReserved3(void)=0;
   //--- between values int
   virtual MTAPIRES  BetweenInt(INT64 from,INT64 to)=0;
   virtual MTAPIRES  BetweenUInt(UINT64 from,UINT64 to)=0;
   virtual MTAPIRES  BetweenDouble(double from,double to)=0;
   //--- reserved between methods
   virtual MTAPIRES  BetweenReserved1(void)=0;
   virtual MTAPIRES  BetweenReserved2(void)=0;
   virtual MTAPIRES  BetweenReserved3(void)=0;
   virtual MTAPIRES  BetweenReserved4(void)=0;
   //--- explicit destructor is prohibited
protected:
                    ~IMTDatasetField(void) {}
  };
//+------------------------------------------------------------------+
//| Report request interface                                         |
//+------------------------------------------------------------------+
class IMTDatasetRequest
  {
public:
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTDatasetRequest *request)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- reserved properties methods
   virtual MTAPIRES  Reserved1(void)=0;
   virtual MTAPIRES  Reserved2(void)=0;
   virtual MTAPIRES  Reserved3(void)=0;
   virtual MTAPIRES  Reserved4(void)=0;
   //--- fields
   virtual IMTDatasetField* FieldCreate(void)=0;
   virtual MTAPIRES  FieldAdd(const IMTDatasetField *field)=0;
   virtual MTAPIRES  FieldUpdate(UINT pos,const IMTDatasetField *field)=0;
   virtual MTAPIRES  FieldDelete(UINT pos)=0;
   virtual MTAPIRES  FieldClear(void)=0;
   virtual MTAPIRES  FieldShift(UINT pos,int shift)=0;
   virtual UINT      FieldTotal(void) const=0;
   virtual MTAPIRES  FieldNext(UINT pos,IMTDatasetField *field) const=0;
   virtual IMTDatasetField* FieldCreateReference(UINT pos)=0;
   //--- reserved fields methods
   virtual MTAPIRES  FieldReserved1(void)=0;
   virtual MTAPIRES  FieldReserved2(void)=0;
   virtual MTAPIRES  FieldReserved3(void)=0;
   //--- limit the number of rows of the resulting dataset
   virtual UINT      RowLimit(void) const=0;
   virtual MTAPIRES  RowLimit(UINT rows)=0;
   //--- explicit destructor is prohibited
protected:
                    ~IMTDatasetRequest(void) {}
  };
//+------------------------------------------------------------------+
