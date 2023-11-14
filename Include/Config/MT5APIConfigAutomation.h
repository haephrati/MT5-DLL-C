//+------------------------------------------------------------------+
//|                                                 MetaTrader 5 API |
//|                             Copyright 2000-2021, MetaQuotes Ltd. |
//|                                               www.metaquotes.net |
//+------------------------------------------------------------------+
#pragma once
//+------------------------------------------------------------------+
//| Automation action parameter config                               |
//+------------------------------------------------------------------+
class IMTConAutoParam
  {
public:
   //--- parameters
   enum EnParams
     {
      //--- 
      //--- ACTION_MESSAGE_PUSH
      //--- 
      PARAM_ACTION_MESSAGE_PUSH_TO_LOGINS        =0,
      PARAM_ACTION_MESSAGE_PUSH_TO_GROUPS        =1,
      PARAM_ACTION_MESSAGE_PUSH_TEXT             =2,
      //--- borders
      PARAM_ACTION_MESSAGE_PUSH_FIRST            =0,
      PARAM_ACTION_MESSAGE_PUSH_LAST             =50,
      //---
      //--- ACTION_MESSAGE_INTERNAL
      //---
      PARAM_ACTION_MESSAGE_INTERNAL_TO_LOGINS    =51,
      PARAM_ACTION_MESSAGE_INTERNAL_TO_GROUPS    =52,
      PARAM_ACTION_MESSAGE_INTERNAL_SUBJ         =53,
      PARAM_ACTION_MESSAGE_INTERNAL_TEXT         =54,
      PARAM_ACTION_MESSAGE_INTERNAL_FROM         =55,
      //--- borders
      PARAM_ACTION_MESSAGE_INTERNAL_FIRST        =51,
      PARAM_ACTION_MESSAGE_INTERNAL_LAST         =100,
      //---
      //--- ACTION_MESSAGE_SMS
      //---
      PARAM_ACTION_MESSAGE_SMS_TO_LOGINS         =101,
      PARAM_ACTION_MESSAGE_SMS_TO_GROUPS         =102,
      PARAM_ACTION_MESSAGE_SMS_TO_PHONES         =103,
      PARAM_ACTION_MESSAGE_SMS_TEXT              =104,
      //--- borders
      PARAM_ACTION_MESSAGE_SMS_FIRST             =101,
      PARAM_ACTION_MESSAGE_SMS_LAST              =150,
      //---
      //--- ACTION_MESSAGE_EMAIL
      //---
      PARAM_ACTION_MESSAGE_EMAIL_TO_LOGINS       =151,
      PARAM_ACTION_MESSAGE_EMAIL_TO_GROUPS       =152,
      PARAM_ACTION_MESSAGE_EMAIL_TO_EMAILS       =153,
      PARAM_ACTION_MESSAGE_EMAIL_SERVER          =154,
      PARAM_ACTION_MESSAGE_EMAIL_SUBJ            =155,
      PARAM_ACTION_MESSAGE_EMAIL_TEXT            =156,
      //--- borders
      PARAM_ACTION_MESSAGE_EMAIL_FIRST           =151,
      PARAM_ACTION_MESSAGE_EMAIL_LAST            =200,
      //---
      //--- ACTION_ACCOUNT_CHANGE_GROUP
      //---
      PARAM_ACTION_ACCOUNT_CHANGE_GROUP          =201,
      PARAM_ACTION_ACCOUNT_CHANGE_GROUP_LOGINS   =202,
      PARAM_ACTION_ACCOUNT_CHANGE_GROUP_GROUPS   =203,
      //--- borders
      PARAM_ACTION_ACCOUNT_CHANGE_GROUP_FIRST    =201,
      PARAM_ACTION_ACCOUNT_CHANGE_GROUP_LAST     =250,
      //--- 
      //--- ACTION_ACCOUNT_CHANGE_COLOR
      //--- 
      PARAM_ACTION_ACCOUNT_CHANGE_COLOR          =251,
      PARAM_ACTION_ACCOUNT_CHANGE_COLOR_LOGINS   =252,
      PARAM_ACTION_ACCOUNT_CHANGE_COLOR_GROUPS   =253,
      //--- borders
      PARAM_ACTION_ACCOUNT_CHANGE_COLOR_FIRST    =251,
      PARAM_ACTION_ACCOUNT_CHANGE_COLOR_LAST     =300,
      //--- 
      //--- ACTION_ACCOUNT_COMMENT
      //--- 
      PARAM_ACTION_ACCOUNT_COMMENT               =301,
      PARAM_ACTION_ACCOUNT_COMMENT_LOGINS        =302,
      PARAM_ACTION_ACCOUNT_COMMENT_GROUPS        =303,
      //--- borders
      PARAM_ACTION_ACCOUNT_COMMENT_FIRST         =301,
      PARAM_ACTION_ACCOUNT_COMMENT_LAST          =350,
      //--- 
      //--- ACTION_ACCOUNT_CLIENT_COMMENT
      //--- 
      PARAM_ACTION_ACCOUNT_CLIENT_COMMENT        =351,
      PARAM_ACTION_ACCOUNT_CLIENT_COMMENT_LOGINS =352,
      PARAM_ACTION_ACCOUNT_CLIENT_COMMENT_GROUPS =353,
      //--- borders
      PARAM_ACTION_CLIENT_COMMENT_FIRST          =351,
      PARAM_ACTION_CLIENT_COMMENT_LAST           =400,
      //--- 
      //--- ACTION_FINANCE_DEPOSIT
      //--- 
      PARAM_ACTION_FINANCE_DEPOSIT_AMOUNT        =401,
      PARAM_ACTION_FINANCE_DEPOSIT_COMMENT       =402,
      PARAM_ACTION_FINANCE_DEPOSIT_LOGINS        =403,
      PARAM_ACTION_FINANCE_DEPOSIT_GROUPS        =404,
      PARAM_ACTION_FINANCE_DEPOSIT_ACTION        =405,
      //--- borders
      PARAM_ACTION_FINANCE_DEPOSIT_FIRST         =401,
      PARAM_ACTION_FINANCE_DEPOSIT_LAST          =450,
      //--- 
      //--- ACTION_FINANCE_BONUS
      //--- 
      PARAM_ACTION_FINANCE_BONUS_AMOUNT          =451,
      PARAM_ACTION_FINANCE_BONUS_COMMENT         =452,
      PARAM_ACTION_FINANCE_BONUS_LOGINS          =453,
      PARAM_ACTION_FINANCE_BONUS_GROUPS          =454,
      //--- borders
      PARAM_ACTION_FINANCE_BONUS_FIRST           =451,
      PARAM_ACTION_FINANCE_BONUS_LAST            =500,
      //--- 
      //--- ACTION_FINANCE_CREDIT
      //--- 
      PARAM_ACTION_FINANCE_CREDIT_AMOUNT         =501,
      PARAM_ACTION_FINANCE_CREDIT_COMMENT        =502,
      PARAM_ACTION_FINANCE_CREDIT_LOGINS         =503,
      PARAM_ACTION_FINANCE_CREDIT_GROUPS         =504,
      //--- borders
      PARAM_ACTION_FINANCE_CREDIT_FIRST          =501,
      PARAM_ACTION_FINANCE_CREDIT_LAST           =550,
      //--- 
      //--- ACTION_TRADE_CLOSE_POSITIONS
      //--- 
      PARAM_ACTION_TRADE_CLOSE_POSITIONS_TYPES   =551,
      PARAM_ACTION_TRADE_CLOSE_POSITIONS_SYMBOLS =552,
      PARAM_ACTION_TRADE_CLOSE_POSITIONS_PRICE   =553,
      PARAM_ACTION_TRADE_CLOSE_POSITIONS_COMMENT =554,
      PARAM_ACTION_TRADE_CLOSE_POSITIONS_LOGINS  =555,
      PARAM_ACTION_TRADE_CLOSE_POSITIONS_GROUPS  =556,
      //--- borders
      PARAM_ACTION_TRADE_CLOSE_POSITIONS_FIRST   =551,
      PARAM_ACTION_TRADE_CLOSE_POSITIONS_LAST    =600,
      //--- 
      //--- ACTION_TRADE_CLOSE_ORDERS
      //--- 
      PARAM_ACTION_TRADE_CLOSE_ORDERS_TYPES      =601,
      PARAM_ACTION_TRADE_CLOSE_ORDERS_SYMBOLS    =602,
      PARAM_ACTION_TRADE_CLOSE_ORDERS_COMMENT    =603,
      PARAM_ACTION_TRADE_CLOSE_ORDERS_LOGINS     =604,
      PARAM_ACTION_TRADE_CLOSE_ORDERS_GROUPS     =605,
      //--- borders
      PARAM_ACTION_TRADE_CLOSE_ORDERS_FIRST      =601,
      PARAM_ACTION_TRADE_CLOSE_ORDERS_LAST       =650,
      //--- 
      //--- ACTION_CONFIG_SYMBOL_MOVE
      //--- 
      PARAM_ACTION_CONFIG_SYMBOL_MOVE_PATH       =651,
      //--- borders
      PARAM_ACTION_CONFIG_SYMBOL_MOVE_FIRST      =651,
      PARAM_ACTION_CONFIG_SYMBOL_MOVE_LAST       =700,
      //--- 
      //--- ACTION_PLATFORM_RESTART_SERVER
      //--- 
      PARAM_ACTION_PLATFORM_RESTART_SERVER_LOGIN =701,
      //--- borders
      PARAM_ACTION_PLATFORM_RESTART_SERVER_FIRST =701,
      PARAM_ACTION_PLATFORM_RESTART_SERVER_LAST  =750,
      //--- 
      //--- ACTION_PLATFORM_RESTART_FEED
      //--- 
      PARAM_ACTION_PLATFORM_RESTART_FEED_NAME    =751,
      //--- borders
      PARAM_ACTION_PLATFORM_RESTART_FEED_FIRST   =751,
      PARAM_ACTION_PLATFORM_RESTART_FEED_LAST    =800,
      //--- 
      //--- ACTION_PLATFORM_RESTART_GATEWAY
      //--- 
      PARAM_ACTION_PLATFORM_RESTART_GATEWAY_NAME =801,
      //--- borders
      PARAM_ACTION_PLATFORM_RESTART_GATEWAY_FIRST=801,
      PARAM_ACTION_PLATFORM_RESTART_GATEWAY_LAST =850,
      //--- 
      //--- ACTION_CONFIG_GROUP_UPDATE
      //--- 
      PARAM_ACTION_CONFIG_GROUP_UPDATE_JSON      =851,
      //--- borders
      PARAM_ACTION_CONFIG_GROUP_UPDATE_FIRST     =851,
      PARAM_ACTION_CONFIG_GROUP_UPDATE_LAST      =900,
      //--- 
      //--- ACTION_CONFIG_SYMBOL_UPDATE
      //--- 
      PARAM_ACTION_CONFIG_SYMBOL_UPDATE_JSON     =901,
      //--- borders
      PARAM_ACTION_CONFIG_SYMBOL_UPDATE_FIRST    =901,
      PARAM_ACTION_CONFIG_SYMBOL_UPDATE_LAST     =950,
      //--- 
      //--- ACTION_CONFIG_ROUTING_UPDATE
      //--- 
      PARAM_ACTION_CONFIG_ROUTING_UPDATE_JSON    =951,
      //--- borders
      PARAM_ACTION_CONFIG_ROUTING_UPDATE_FIRST   =951,
      PARAM_ACTION_CONFIG_ROUTING_UPDATE_LAST    =1000,
      //--- 
      //--- ACTION_ACCOUNT_DISABLE
      //--- 
      PARAM_ACTION_ACCOUNT_DISABLE_LOGINS        =1001,
      PARAM_ACTION_ACCOUNT_DISABLE_GROUPS        =1002,
      //--- borders
      PARAM_ACTION_ACCOUNT_DISABLE_FIRST         =1001,
      PARAM_ACTION_ACCOUNT_DISABLE_LAST          =1050,
      //--- 
      //--- ACTION_ACCOUNT_ENABLE
      //--- 
      PARAM_ACTION_ACCOUNT_ENABLE_LOGINS         =1051,
      PARAM_ACTION_ACCOUNT_ENABLE_GROUPS         =1052,
      //--- borders
      PARAM_ACTION_ACCOUNT_ENABLE_FIRST          =1051,
      PARAM_ACTION_ACCOUNT_ENABLE_LAST           =1110,
      //--- 
      //--- ACTION_ACCOUNT_DISABLE_TRADE
      //--- 
      PARAM_ACTION_ACCOUNT_DISABLE_TRADE_LOGINS  =1101,
      PARAM_ACTION_ACCOUNT_DISABLE_TRADE_GROUPS  =1102,
      //--- borders
      PARAM_ACTION_ACCOUNT_DISABLE_TRADE_FIRST   =1101,
      PARAM_ACTION_ACCOUNT_DISABLE_TRADE_LAST    =1150,
      //--- 
      //--- ACTION_ACCOUNT_ENABLE_TRADE
      //--- 
      PARAM_ACTION_ACCOUNT_ENABLE_TRADE_LOGINS   =1151,
      PARAM_ACTION_ACCOUNT_ENABLE_TRADE_GROUPS   =1152,
      //--- borders
      PARAM_ACTION_ACCOUNT_ENABLE_TRADE_FIRST    =1151,
      PARAM_ACTION_ACCOUNT_ENABLE_TRADE_LAST     =1200,
      //--- 
      //--- ACTION_ACCOUNT_DISABLE_EXPERT
      //--- 
      PARAM_ACTION_ACCOUNT_DISABLE_EXPERT_LOGINS =1201,
      PARAM_ACTION_ACCOUNT_DISABLE_EXPERT_GROUPS =1202,
      //--- borders
      PARAM_ACTION_ACCOUNT_DISABLE_EXPERT_FIRST  =1201,
      PARAM_ACTION_ACCOUNT_DISABLE_EXPERT_LAST   =1250,
      //--- 
      //--- ACTION_ACCOUNT_ENABLE_EXPERT
      //--- 
      PARAM_ACTION_ACCOUNT_ENABLE_EXPERT_LOGINS  =1251,
      PARAM_ACTION_ACCOUNT_ENABLE_EXPERT_GROUPS  =1252,
      //--- borders
      PARAM_ACTION_ACCOUNT_ENABLE_EXPERT_FIRST   =1251,
      PARAM_ACTION_ACCOUNT_ENABLE_EXPERT_LAST    =1300,
      //--- 
      //--- ACTION_ACCOUNT_DISABLE_TRAILING
      //--- 
      PARAM_ACTION_ACCOUNT_DISABLE_TRAILING_LOGINS=1301,
      PARAM_ACTION_ACCOUNT_DISABLE_TRAILING_GROUPS=1302,
      //--- borders
      PARAM_ACTION_ACCOUNT_DISABLE_TRAILING_FIRST=1301,
      PARAM_ACTION_ACCOUNT_DISABLE_TRAILING_LAST =1350,
      //--- 
      //--- ACTION_ACCOUNT_ENABLE_TRAILING
      //--- 
      PARAM_ACTION_ACCOUNT_ENABLE_TRAILING_LOGINS=1351,
      PARAM_ACTION_ACCOUNT_ENABLE_TRAILING_GROUPS=1352,
      //--- borders
      PARAM_ACTION_ACCOUNT_ENABLE_TRAILING_FIRST =1351,
      PARAM_ACTION_ACCOUNT_ENABLE_TRAILING_LAST  =1400,
      //--- 
      //--- ACTION_ACCOUNT_FORCE_CHANGE_PASS
      //--- 
      PARAM_ACTION_ACCOUNT_FORCE_CHANGE_PASS_LOGINS=1401,
      PARAM_ACTION_ACCOUNT_FORCE_CHANGE_PASS_GROUPS=1402,
      //--- borders
      PARAM_ACTION_ACCOUNT_FORCE_CHANGE_PASS_FIRST=1401,
      PARAM_ACTION_ACCOUNT_FORCE_CHANGE_PASS_LAST =1450,
      //--- 
      //--- ACTION_ACCOUNT_ARCHIVE
      //--- 
      PARAM_ACTION_ACCOUNT_ARCHIVE_LOGINS         =1451,
      PARAM_ACTION_ACCOUNT_ARCHIVE_GROUPS         =1452,
      //--- borders
      PARAM_ACTION_ACCOUNT_ARCHIVE_FIRST          =1451,
      PARAM_ACTION_ACCOUNT_ARCHIVE_LAST           =1500,
      //--- 
      //--- ACTION_ACCOUNT_LEVERAGE
      //--- 
      PARAM_ACTION_ACCOUNT_LEVERAGE               =1501,
      PARAM_ACTION_ACCOUNT_LEVERAGE_LOGINS        =1502,
      PARAM_ACTION_ACCOUNT_LEVERAGE_GROUPS        =1503,
      //--- borders
      PARAM_ACTION_ACCOUNT_LEVERAGE_FIRST         =1501,
      PARAM_ACTION_ACCOUNT_LEVERAGE_LAST          =1550,
      //--- 
      //--- ACTION_FINANCE_DEPOSIT_PAYOFF
      //--- 
      PARAM_ACTION_FINANCE_DEPOSIT_PAYOFF_LOGINS  =1551,
      PARAM_ACTION_FINANCE_DEPOSIT_PAYOFF_GROUPS  =1552,
      PARAM_ACTION_FINANCE_DEPOSIT_PAYOFF_COMMENT =1553,
      PARAM_ACTION_FINANCE_DEPOSIT_PAYOFF_ACTION  =1554,
      //--- borders
      PARAM_ACTION_FINANCE_DEPOSIT_PAYOFF_FIRST   =1551,
      PARAM_ACTION_FINANCE_DEPOSIT_PAYOFF_LAST    =1600,
      //--- 
      //--- ACTION_FINANCE_CREDIT_PAYOFF
      //--- 
      PARAM_ACTION_FINANCE_CREDIT_PAYOFF_LOGINS   =1601,
      PARAM_ACTION_FINANCE_CREDIT_PAYOFF_GROUPS   =1602,
      PARAM_ACTION_FINANCE_CREDIT_PAYOFF_COMMENT  =1603,
      //--- borders
      PARAM_ACTION_FINANCE_CREDIT_PAYOFF_FIRST    =1601,
      PARAM_ACTION_FINANCE_CREDIT_PAYOFF_LAST     =1650,
      //--- 
      //--- ACTION_EXTERNAL_HTTP_REQUEST
      //--- 
      PARAM_ACTION_EXTERNAL_HTTP_REQUEST_METHOD   =1651,
      PARAM_ACTION_EXTERNAL_HTTP_REQUEST_URL      =1652,
      PARAM_ACTION_EXTERNAL_HTTP_REQUEST_HEADERS  =1653,
      PARAM_ACTION_EXTERNAL_HTTP_REQUEST_DATA     =1654,
      //--- borders
      PARAM_ACTION_EXTERNAL_HTTP_REQUEST_FIRST    =1651,
      PARAM_ACTION_EXTERNAL_HTTP_REQUEST_LAST     =1700,
      //--- 
      //--- ACTION_EXTERNAL_FINTEZA_EVENT
      //--- 
      PARAM_ACTION_EXTERNAL_FINTEZA_EVENT_NAME    =1701,
      PARAM_ACTION_EXTERNAL_FINTEZA_EVENT_VALUE   =1702,
      PARAM_ACTION_EXTERNAL_FINTEZA_EVENT_UNIT    =1703,
      //--- borders
      PARAM_ACTION_EXTERNAL_FINTEZA_EVENT_FIRST   =1701,
      PARAM_ACTION_EXTERNAL_FINTEZA_EVENT_LAST    =1750,
      //--- 
      //--- ACTION_EXTERNAL_APPLICATION
      //--- 
      PARAM_ACTION_EXTERNAL_APPLICATION_PATH      =1751,
      PARAM_ACTION_EXTERNAL_APPLICATION_CMD       =1752,
      //--- borders
      PARAM_ACTION_EXTERNAL_APPLICATION_FIRST     =1751,
      PARAM_ACTION_EXTERNAL_APPLICATION_LAST      =1752,
      //--- borders
      PARAM_FIRST                                 =PARAM_ACTION_MESSAGE_PUSH_TO_LOGINS,
      PARAM_LAST                                  =PARAM_ACTION_EXTERNAL_APPLICATION_LAST
     };
   //--- parameters types
   enum EnParamType
     {
      TYPE_NONE                    =0,
      TYPE_STRING                  =1,
      TYPE_INT                     =2,
      TYPE_UINT                    =3,
      TYPE_FLOAT                   =4,
      TYPE_COLOR                   =5,
      TYPE_MONEY                   =6,
      TYPE_VOLUME                  =7,
      TYPE_DATETIME                =8,
      TYPE_LEVERAGE                =9,
      TYPE_BOOL                    =10,
      TYPE_TIME                    =11,
      TYPE_DATE                    =12,
      TYPE_PERCENT                 =13,
      TYPE_LANGUAGE                =14,
      TYPE_SERVER                  =15,
      TYPE_HTML                    =16,
      //--- borders
      TYPE_FIRST                   =TYPE_NONE,
      TYPE_LAST                    =TYPE_HTML
     };
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTConAutoParam* param)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- param type
   virtual UINT      Param(void) const=0;
   virtual MTAPIRES  Param(const UINT param)=0;
   //--- type
   virtual UINT      ValueType(void) const=0;
   //--- value int
   virtual INT64     ValueInt(void) const=0;
   virtual MTAPIRES  ValueInt(const INT64 value)=0;
   //--- value uint
   virtual UINT64    ValueUInt(void) const=0;
   virtual MTAPIRES  ValueUInt(const UINT64 value)=0;
   //--- value double
   virtual double    ValueDouble(void) const=0;
   virtual MTAPIRES  ValueDouble(const double value)=0;
   //--- value string
   virtual LPCWSTR   ValueString(void) const=0;
   virtual MTAPIRES  ValueString(LPCWSTR value)=0;
   //--- value color
   virtual COLORREF  ValueColor(void) const=0;
   virtual MTAPIRES  ValueColor(const COLORREF value)=0;
   //--- value money
   virtual double    ValueMoney(void) const=0;
   virtual MTAPIRES  ValueMoney(const double value)=0;
   //--- value volume
   virtual UINT64    ValueVolume(void) const=0;
   virtual MTAPIRES  ValueVolume(const UINT64 value)=0;
   //--- value datetime
   virtual INT64     ValueDatetime(void) const=0;
   virtual MTAPIRES  ValueDatetime(const INT64 value)=0;
   //--- value leverage
   virtual INT64     ValueLeverage(void) const=0;
   virtual MTAPIRES  ValueLeverage(const INT64 value)=0;
   //--- value bool
   virtual bool      ValueBool(void) const=0;
   virtual MTAPIRES  ValueBool(const bool value)=0;
   //--- value time
   virtual UINT      ValueTime(void) const=0;
   virtual MTAPIRES  ValueTime(const UINT value)=0;
   //--- value date
   virtual INT64     ValueDate(void) const=0;
   virtual MTAPIRES  ValueDate(const INT64 value)=0;
   //--- value percent
   virtual UINT      ValuePercent(void) const=0;
   virtual MTAPIRES  ValuePercent(const UINT value)=0;
   //--- value language
   virtual UINT      ValueLanguage(void) const=0;
   virtual MTAPIRES  ValueLanguage(const UINT value)=0;
   //--- value server
   virtual UINT64    ValueServer(void) const=0;
   virtual MTAPIRES  ValueServer(const UINT64 value)=0;
   //--- value html
   virtual LPCWSTR   ValueHTML(void) const=0;
   virtual MTAPIRES  ValueHTML(LPCWSTR value)=0;
   //--- explicit destructor is prohibited
protected:
                    ~IMTConAutoParam(void) {}
  };
//+------------------------------------------------------------------+
//| Automation action config                                         |
//+------------------------------------------------------------------+
class IMTConAutoAction
  {
public:
   //--- actions
   enum EnActions
     {
      //--- 
      //--- messages
      //--- 
      ACTION_MESSAGE_PUSH             =0,
      ACTION_MESSAGE_INTERNAL         =1,
      ACTION_MESSAGE_SMS              =2,
      ACTION_MESSAGE_EMAIL            =3,
      //--- messages borders
      ACTION_MESSAGE_FIRST            =0,
      ACTION_MESSAGE_LAST             =1000,
      //--- 
      //--- accounts
      //--- 
      ACTION_ACCOUNT_DISABLE          =1001,
      ACTION_ACCOUNT_ENABLE           =1002,
      ACTION_ACCOUNT_DISABLE_TRADE    =1003,
      ACTION_ACCOUNT_ENABLE_TRADE     =1004,
      ACTION_ACCOUNT_DISABLE_EXPERT   =1005,
      ACTION_ACCOUNT_ENABLE_EXPERT    =1006,
      ACTION_ACCOUNT_DISABLE_TRAILING =1007,
      ACTION_ACCOUNT_ENABLE_TRAILING  =1008,
      ACTION_ACCOUNT_FORCE_CHANGE_PASS=1009,
      ACTION_ACCOUNT_CHANGE_GROUP     =1010,
      ACTION_ACCOUNT_CHANGE_COLOR     =1011,
      ACTION_ACCOUNT_ARCHIVE          =1012,
      ACTION_ACCOUNT_COMMENT          =1013,
      ACTION_ACCOUNT_CLIENT_COMMENT   =1014,
      ACTION_ACCOUNT_LEVERAGE         =1015,
      //--- accounts borders
      ACTION_ACCOUNT_FIRST            =1001,
      ACTION_ACCOUNT_LAST             =2000,
      //--- 
      //--- finances
      //--- 
      ACTION_FINANCE_DEPOSIT          =2001,
      ACTION_FINANCE_BONUS            =2002,
      ACTION_FINANCE_CREDIT           =2003,
      ACTION_FINANCE_DEPOSIT_PAYOFF   =2004,
      ACTION_FINANCE_CREDIT_PAYOFF    =2005,
      //--- finances borders
      ACTION_FINANCE_FIRST            =2001,
      ACTION_FINANCE_LAST             =3000,
      //--- 
      //--- trade actions
      //--- 
      ACTION_TRADE_CLOSE_POSITIONS    =3001,
      ACTION_TRADE_CLOSE_ORDERS       =4000,
      //--- trade borders
      ACTION_TRADE_FIRST              =3001,
      ACTION_TRADE_LAST               =5000,
      //--- 
      //--- config modifications
      //--- 
      ACTION_CONFIG_GROUP_UPDATE      =5001,
      ACTION_CONFIG_SYMBOL_UPDATE     =5002,
      ACTION_CONFIG_SYMBOL_MOVE       =5003,
      ACTION_CONFIG_ROUTING_UPDATE    =5004,
      ACTION_CONFIG_SERVER_UPDATE     =5005,
      ACTION_CONFIG_GATEWAY_UPDATE    =5006,
      ACTION_CONFIG_DATAFEED_UPDATE   =5007,
      //--- config borders
      ACTION_CONFIG_FIRST             =5001,
      ACTION_CONFIG_LAST              =6000,
      //--- 
      //--- platform actions
      //--- 
      ACTION_PLATFORM_RESTART_SERVER  =6001,
      ACTION_PLATFORM_RESTART_FEED    =6002,
      ACTION_PLATFORM_RESTART_GATEWAY =6003,
      ACTION_PLATFORM_SYNC_HISTORY    =6004,
      //--- platform borders
      ACTION_PLATFORM_FIRST           =6001,
      ACTION_PLATFORM_LAST            =7000,
      //---
      //--- external actions
      //--- 
      ACTION_EXTERNAL_APPLICATION     =7001,
      ACTION_EXTERNAL_PLUGIN          =7002,
      ACTION_EXTERNAL_HTTP_REQUEST    =7003,
      ACTION_EXTERNAL_FINTEZA_EVENT   =7004,
      //--- external borders
      ACTION_EXTERNAL_FIRST           =7001,
      ACTION_EXTERNAL_LAST            =8000,
      //--- common borders
      ACTION_FIRST                    =ACTION_MESSAGE_FIRST,
      ACTION_LAST                     =ACTION_EXTERNAL_LAST
     };
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTConAutoAction* action)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- action type
   virtual UINT      Action(void) const=0;
   virtual MTAPIRES  Action(const UINT condition)=0;
   //--- name
   virtual LPCWSTR   Name(void) const=0;
   virtual MTAPIRES  Name(LPCWSTR name)=0;
   //--- accounts
   virtual MTAPIRES  ParamAdd(IMTConAutoParam* param)=0;
   virtual MTAPIRES  ParamUpdate(const UINT pos,const IMTConAutoParam* param)=0;
   virtual MTAPIRES  ParamDelete(const UINT pos)=0;
   virtual MTAPIRES  ParamClear(void)=0;
   virtual MTAPIRES  ParamShift(const UINT pos,const int shift)=0;
   virtual UINT      ParamTotal(void) const=0;
   virtual MTAPIRES  ParamNext(const UINT pos,IMTConAutoParam* param) const=0;
   //--- explicit destructor is prohibited
protected:
                    ~IMTConAutoAction(void) {}
  };
//+------------------------------------------------------------------+
//| Automation condition config                                      |
//+------------------------------------------------------------------+
class IMTConAutoCondition
  {
public:
   //--- condition types
   enum EnConditions
     {
      //--- time conditions
      CONDITION_DATETIME_DATETIME           =0,
      CONDITION_DATETIME_DATE               =1,
      CONDITION_DATETIME_TIME               =2,
      //--- time conditions borders
      CONDITION_DATETIME_FIRST              =0,
      CONDITION_DATETIME_LAST               =1000,
      //--- account conditions
      CONDITION_ACCOUNT_LOGIN               =1001,
      CONDITION_ACCOUNT_GROUP               =1002,
      CONDITION_ACCOUNT_COUNTRY             =1003,
      CONDITION_ACCOUNT_CITY                =1004,
      CONDITION_ACCOUNT_LANGUAGE            =1005,
      CONDITION_ACCOUNT_PHONE               =1006,
      CONDITION_ACCOUNT_EMAIL               =1007,
      CONDITION_ACCOUNT_COLOR               =1008,
      CONDITION_ACCOUNT_COMMENT             =1009,
      CONDITION_ACCOUNT_REGISTRATION        =1010,
      CONDITION_ACCOUNT_LASTTIME            =1011,
      CONDITION_ACCOUNT_LEVERAGE            =1012,
      CONDITION_ACCOUNT_BALANCE             =1013,
      CONDITION_ACCOUNT_CREDIT              =1014,
      CONDITION_ACCOUNT_POSITIONS           =1015,
      CONDITION_ACCOUNT_ORDERS              =1016,
      CONDITION_ACCOUNT_PROFIT              =1017,
      CONDITION_ACCOUNT_EQUITY              =1018,
      CONDITION_ACCOUNT_MARGIN              =1019,
      CONDITION_ACCOUNT_MARGIN_FREE         =1020,
      CONDITION_ACCOUNT_MARGIN_LEVEL        =1021,
      CONDITION_ACCOUNT_CURRENCY            =1022,
      CONDITION_ACCOUNT_REGISTRATION_ELAPSED=1023,
      CONDITION_ACCOUNT_LASTTIME_ELAPSED    =1024,
      CONDITION_ACCOUNT_LEAD_SOURCE         =1025,
      CONDITION_ACCOUNT_LEAD_CAMPAIGN       =1026,
      //--- account conditions borders
      CONDITION_ACCOUNT_FIRST               =1001,
      CONDITION_ACCOUNT_LAST                =2000,
      //--- monitoring conditions
      CONDITION_MONITOR_CPU                 =2001,
      CONDITION_MONITOR_CPU_PROCESS         =2002,
      CONDITION_MONITOR_CPU_PROCESS_THREADS =2003,
      CONDITION_MONITOR_MEMORY_FREE         =2004,
      CONDITION_MONITOR_MEMORY_PROCESS      =2005,
      CONDITION_MONITOR_DISK_FREE           =2006,
      CONDITION_MONITOR_DISK_SPEED_READ     =2007,
      CONDITION_MONITOR_DISK_SPEED_WRITE    =2008,
      CONDITION_MONITOR_DISK_QUEUE_LENGTH   =2009,
      CONDITION_MONITOR_NETWORK_CONNECTIONS =2010,
      CONDITION_MONITOR_NETWORK_BLOCKED     =2011,
      CONDITION_MONITOR_NETWORK_SOCKETS     =2012,
      CONDITION_MONITOR_NETWORK_TRAFFIC_IN  =2013,
      CONDITION_MONITOR_NETWORK_TRAFFIC_OUT =2014,
      CONDITION_MONITOR_NETWORK_RETRANSMIT  =2015,
      CONDITION_MONITOR_HANDLES_PROCESS     =2016,
      CONDITION_MONITOR_CPU_DPC             =2017,
      CONDITION_MONITOR_CPU_INTERRUPTS      =2018,
      //--- monitoring conditions borders
      CONDITION_MONITOR_FIRST               =2001,
      CONDITION_MONITOR_LAST                =3000,
      //--- platform server conditions borders
      CONDITION_SERVER_ID                   =3001,
      CONDITION_SERVER_TYPE                 =3002,
      CONDITION_SERVER_CONNECTED            =3003,
      //--- platform server conditions
      CONDITION_SERVER_FIRST                =3001,
      CONDITION_SERVER_LAST                 =4000,
      //--- finance operations conditions
      CONDITION_FINANCE_AMOUNT              =4001,
      CONDITION_FINANCE_CURRENCY            =4002,
      //--- finance operations borders
      CONDITION_FINANCE_FIRST               =4001,
      CONDITION_FINANCE_LAST                =5000,
      //--- prices conditions
      CONDITION_PRICES_SYMBOL               =5001,
      //--- prices conditions borders
      CONDITION_PRICES_FIRST                =5001,
      CONDITION_PRICES_LAST                 =6000,
      //--- trade position conditions
      CONDITION_POSITION_LOGIN              =6001,
      CONDITION_POSITION_TICKET             =6002,
      CONDITION_POSITION_SYMBOL             =6003,
      CONDITION_POSITION_VOLUME             =6004,
      CONDITION_POSITION_TYPE               =6005,
      CONDITION_POSITION_PRICE_OPEN         =6006,
      CONDITION_POSITION_PRICE_CURRENT      =6007,
      CONDITION_POSITION_PROFIT             =6008,
      CONDITION_POSITION_REASON             =6009,
      CONDITION_POSITION_TIME_CREATE        =6010,
      CONDITION_POSITION_TIME_UPDATE        =6011,
      CONDITION_POSITION_EXPERT             =6012,
      CONDITION_POSITION_TIME_CREATE_ELAPSED=6013,
      CONDITION_POSITION_TIME_UPDATE_ELAPSED=6014,
      //--- trade position condition borders
      CONDITION_POSITION_FIRST              =6001,
      CONDITION_POSITION_LAST               =7000,
      //--- trade deal conditions
      CONDITION_DEAL_LOGIN                  =7001,
      CONDITION_DEAL_TICKET                 =7002,
      CONDITION_DEAL_SYMBOL                 =7003,
      CONDITION_DEAL_VOLUME                 =7004,
      CONDITION_DEAL_TYPE                   =7005,
      CONDITION_DEAL_ENTRY                  =7006,
      CONDITION_DEAL_PRICE                  =7007,
      CONDITION_DEAL_PROFIT                 =7008,
      CONDITION_DEAL_REASON                 =7009,
      CONDITION_DEAL_TIME                   =7010,
      CONDITION_DEAL_EXPERT                 =7011,
      //--- trade deal condition borders
      CONDITION_DEAL_FIRST                  =7001,
      CONDITION_DEAL_LAST                   =8000,
      //--- internal message conditions
      CONDITION_MESSAGE_FROM                =8001,
      CONDITION_MESSAGE_FROM_NAME           =8002,
      CONDITION_MESSAGE_TO                  =8003,
      CONDITION_MESSAGE_TO_NAME             =8004,
      CONDITION_MESSAGE_SUBJECT             =8005,
      CONDITION_MESSAGE_BODY                =8006,
      //--- internal message conditions borders
      CONDITION_MESSAGE_FIRST               =8001,
      CONDITION_MESSAGE_LAST                =9000,
      //--- trade order condition
      CONDITION_ORDER_TICKET                =9001,
      CONDITION_ORDER_ORDER_ID              =9002,
      CONDITION_ORDER_LOGIN                 =9003,
      CONDITION_ORDER_SYMBOL                =9004,
      CONDITION_ORDER_TIME_SETUP            =9005,
      CONDITION_ORDER_TIME_SETUP_ELAPSED    =9006,
      CONDITION_ORDER_TIME_EXPIRATION       =9007,
      CONDITION_ORDER_TYPE                  =9008,
      CONDITION_ORDER_PRICE_ORDER           =9009,
      CONDITION_ORDER_PRICE_TRIGGER         =9010,
      CONDITION_ORDER_PRICE_CURRENT         =9011,
      CONDITION_ORDER_PRICE_SL              =9012,
      CONDITION_ORDER_PRICE_TP              =9013,
      CONDITION_ORDER_VOLUME_INITIAL        =9014,
      CONDITION_ORDER_VOLUME_CURRENT        =9015,
      CONDITION_ORDER_STATE                 =9016,
      CONDITION_ORDER_EXPERT                =9017,
      CONDITION_ORDER_POSITION_ID           =9018,
      CONDITION_ORDER_COMMENT               =9019,
      CONDITION_ORDER_CONTRACT_SIZE         =9020,
      CONDITION_ORDER_CURRENCY              =9021,
      //--- trade order conditions borders
      CONDITION_ORDER_FIRST                 =9001,
      CONDITION_ORDER_LAST                  =10000,
      //--- borders
      CONDITION_FIRST                       =CONDITION_DATETIME_FIRST,
      CONDITION_LAST                        =CONDITION_ORDER_LAST
     };
   //--- condition comparison method
   enum EnConditionRule
     {
      RULE_EQ                      =0,       // ==
      RULE_NOT_EQ                  =1,       // !=
      RULE_GREATER                 =2,       // >
      RULE_NOT_LESS                =3,       // >=
      RULE_LESS                    =4,       // <
      RULE_NOT_GREATER             =5,       // <=
      RULE_MATCH_MASK              =6,       // by mask
      //--- enumeration borders
      RULE_FIRST                   =RULE_EQ,
      RULE_LAST                    =RULE_MATCH_MASK
     };
   //--- condition types method
   enum EnConditionType
     {
      TYPE_NONE                    =0,
      TYPE_STRING                  =1,
      TYPE_INT                     =2,
      TYPE_UINT                    =3,
      TYPE_DOUBLE                  =4,
      TYPE_COLOR                   =5,
      TYPE_MONEY                   =6,
      TYPE_VOLUME                  =7,
      TYPE_DATETIME                =8,
      TYPE_LEVERAGE                =9,
      TYPE_BOOL                    =10,
      TYPE_TIME                    =11,
      TYPE_DATE                    =12,
      TYPE_PERCENT                 =13,
      TYPE_LANGUAGE                =14,
      TYPE_SERVER                  =15,
      TYPE_POSITION                =16,
      TYPE_REASON                  =17,
      TYPE_DEAL                    =18,
      TYPE_DEAL_ENTRY              =19,
      TYPE_ORDER                   =20,
      TYPE_ORDER_STATE             =21,
      //--- borders
      TYPE_FIRST                   =TYPE_NONE,
      TYPE_LAST                    =TYPE_ORDER_STATE
     };
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTConAutoCondition* condition)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- condition type
   virtual UINT      Condition(void) const=0;
   virtual MTAPIRES  Condition(const UINT condition)=0;
   //--- condition rule
   virtual UINT      Rule(void) const=0;
   virtual MTAPIRES  Rule(const UINT rule)=0;
   //--- type
   virtual UINT      ValueType(void) const=0;
   //--- value int
   virtual INT64     ValueInt(void) const=0;
   virtual MTAPIRES  ValueInt(const INT64 value)=0;
   //--- value uint
   virtual UINT64    ValueUInt(void) const=0;
   virtual MTAPIRES  ValueUInt(const UINT64 value)=0;
   //--- value double
   virtual double    ValueDouble(void) const=0;
   virtual MTAPIRES  ValueDouble(const double value)=0;
   //--- value string
   virtual LPCWSTR   ValueString(void) const=0;
   virtual MTAPIRES  ValueString(LPCWSTR value)=0;
   //--- value color
   virtual COLORREF  ValueColor(void) const=0;
   virtual MTAPIRES  ValueColor(const COLORREF value)=0;
   //--- value money
   virtual double    ValueMoney(void) const=0;
   virtual MTAPIRES  ValueMoney(const double value)=0;
   //--- value volume
   virtual UINT64    ValueVolume(void) const=0;
   virtual MTAPIRES  ValueVolume(const UINT64 value)=0;
   //--- value datetime
   virtual INT64     ValueDatetime(void) const=0;
   virtual MTAPIRES  ValueDatetime(const INT64 value)=0;
   //--- value leverage
   virtual INT64     ValueLeverage(void) const=0;
   virtual MTAPIRES  ValueLeverage(const INT64 value)=0;
   //--- value bool
   virtual bool      ValueBool(void) const=0;
   virtual MTAPIRES  ValueBool(const bool value)=0;
   //--- value time
   virtual UINT      ValueTime(void) const=0;
   virtual MTAPIRES  ValueTime(const UINT value)=0;
   //--- value date
   virtual INT64     ValueDate(void) const=0;
   virtual MTAPIRES  ValueDate(const INT64 value)=0;
   //--- value percent
   virtual UINT      ValuePercent(void) const=0;
   virtual MTAPIRES  ValuePercent(const UINT value)=0;
   //--- value language
   virtual UINT      ValueLanguage(void) const=0;
   virtual MTAPIRES  ValueLanguage(const UINT value)=0;
   //--- value server
   virtual UINT64    ValueServer(void) const=0;
   virtual MTAPIRES  ValueServer(const UINT64 value)=0;
   //--- value position
   virtual UINT      ValuePositionType(void) const=0;
   virtual MTAPIRES  ValuePositionType(const UINT value)=0;
   //--- value reason
   virtual UINT      ValueReason(void) const=0;
   virtual MTAPIRES  ValueReason(const UINT value)=0;
   //--- value deal type
   virtual UINT      ValueDealType(void) const=0;
   virtual MTAPIRES  ValueDealType(const UINT value)=0;
   //--- value deal entry
   virtual UINT      ValueDealEntry(void) const=0;
   virtual MTAPIRES  ValueDealEntry(const UINT value)=0;
   //--- value order type
   virtual UINT      ValueOrderType(void) const=0;
   virtual MTAPIRES  ValueOrderType(const UINT value)=0;
   //--- value order state
   virtual UINT      ValueOrderState(void) const=0;
   virtual MTAPIRES  ValueOrderState(const UINT value)=0;
   //--- explicit destructor is prohibited
protected:
                    ~IMTConAutoCondition(void) {}
  };
//+------------------------------------------------------------------+
//| Automation config                                                |
//+------------------------------------------------------------------+
class IMTConAutomation
  {
public:
   //--- flags
   enum EnFlags
     {
      FLAG_NONE                       =0x00000000,  // none
      FLAG_ENABLED                    =0x00000001,  // enabled
      FLAG_FOLDER                     =0x00000002,  // folder
      //--- borders
      FLAG_ALL                        =FLAG_ENABLED|FLAG_FOLDER
     };
   //--- automation trigger types
   enum EnTriggers
     {
      //--- 
      //--- time triggers
      //--- 
      TRIGGER_SCHEDULE_SCHEDULE        =0,      // on schedule
      TRIGGER_SCHEDULE_ACCOUNTS        =1,      // by trade accounts base
      TRIGGER_SCHEDULE_POSITIONS       =2,      // by trade positions base
      TRIGGER_SCHEDULE_ORDERS          =3,      // by trade orders base
      //---   SCHEDULE
      TRIGGER_SCHEDULE_FIRST           =0,
      TRIGGER_SCHEDULE_LAST            =1000,
      //--- 
      //--- connection triggers
      //--- 
      TRIGGER_CONNECTIONS_LOGIN        =1001,   // login
      TRIGGER_CONNECTIONS_LOGIN_FIRST  =1002,   // first login
      TRIGGER_CONNECTIONS_LOGOUT       =1003,   // logiut
      //--- connection triggers borders
      TRIGGER_CONNECTIONS_FIRST        =1001,
      TRIGGER_CONNECTIONS_LAST         =2000,
      //---                            
      //--- account triggers           
      //---                            
      TRIGGER_ACCOUNT_CREATE           =2001,   // creation
      //--- account triggers borders   
      TRIGGER_ACCOUNT_FIRST            =2001,
      TRIGGER_ACCOUNT_LAST             =3000,
      //--- 
      //--- finance triggers
      //--- 
      TRIGGER_FINANCE_DEPOSIT_IN       =3001,   // deposit in
      TRIGGER_FINANCE_DEPOSIT_IN_FIRST =3002,   // first deposit in
      TRIGGER_FINANCE_DEPOSIT_OUT      =3003,   // deposit out
      TRIGGER_FINANCE_DEPOSIT_OUT_FIRST=3004,   // first deposit out
      TRIGGER_FINANCE_CREDIT_IN        =3005,   // credit in
      TRIGGER_FINANCE_CREDIT_IN_FIRST  =3006,   // first credit in
      TRIGGER_FINANCE_CREDIT_OUT       =3007,   // credit out
      //--- finance triggers borders
      TRIGGER_FINANCE_FIRST            =3001,
      TRIGGER_FINANCE_LAST             =4000,
      //--- 
      //--- trade triggers
      //--- 
      TRIGGER_TRADE_MARGIN_CALL        =4001,
      TRIGGER_TRADE_STOP_OUT           =4002,
      TRIGGER_TRADE_POSITION_OPEN      =4003,
      TRIGGER_TRADE_POSITION_INCREASE  =4004,
      TRIGGER_TRADE_POSITION_DECREASE  =4005,
      TRIGGER_TRADE_POSITION_CLOSE     =4006,
      TRIGGER_TRADE_POSITION_REVERSE   =4007,
      //--- trade triggers borders     
      TRIGGER_TRADE_FIRST              =4001,
      TRIGGER_TRADE_LAST               =5000,
      //--- 
      //--- price triggers
      //--- 
      TRIGGER_PRICES_GAP_STARTED       =5001,
      TRIGGER_PRICES_GAP_FINISHED      =5002,
      //--- price triggers borders     
      TRIGGER_PRICES_FIRST             =5001,
      TRIGGER_PRICES_LAST              =6000,
      //--- 
      //--- platform triggers
      //--- 
      TRIGGER_PLATFORM_MONITOR         =6001, // server monitoring
      TRIGGER_PLATFORM_CONNECT         =6002, // server connect
      TRIGGER_PLATFORM_DISCONNECT      =6003, // server disconnect
      TRIGGER_PLATFORM_FAILOVER        =6004, // server failover
      //--- platform triggers borders  
      TRIGGER_PLATFORM_FIRST           =6001,
      TRIGGER_PLATFORM_LAST            =7000,
      //--- 
      //--- external triggers
      //--- 
      TRIGGER_EXTERNAL_API             =7001,
      TRIGGER_EXTERNAL_FIRST           =7001,
      TRIGGER_EXTERNAL_LAST            =8000,
      //---                            
      //--- internal mail tiggers      
      //---                            
      TRIGGER_MESSAGE_CLIENT_SEND      =8001,
      TRIGGER_MESSAGE_CLIENT_READ      =8002,
      //---                            
      TRIGGER_MESSAGE_FIRST            =8001,
      TRIGGER_MESSAGE_LAST             =9000,
      //--- external triggers borders  
      TRIGGER_FIRST                    =TRIGGER_SCHEDULE_FIRST,
      TRIGGER_LAST                     =TRIGGER_MESSAGE_LAST
     };
   //--- weekdays flags
   enum EnTriggerWeekdays
     {
      TRIGGER_WEEKDAY_SUN        =0x00000001,
      TRIGGER_WEEKDAY_MON        =0x00000002,
      TRIGGER_WEEKDAY_TUE        =0x00000004,
      TRIGGER_WEEKDAY_WED        =0x00000008,
      TRIGGER_WEEKDAY_THU        =0x00000010,
      TRIGGER_WEEKDAY_FRI        =0x00000020,
      TRIGGER_WEEKDAY_SAT        =0x00000040,
      //--- flag borders
      TRIGGER_WEEKDAY_NONE       =0,
      TRIGGER_WEEKDAY_ALL        =TRIGGER_WEEKDAY_SUN|TRIGGER_WEEKDAY_MON|TRIGGER_WEEKDAY_TUE|TRIGGER_WEEKDAY_WED|TRIGGER_WEEKDAY_THU|TRIGGER_WEEKDAY_FRI|TRIGGER_WEEKDAY_SAT,
      TRIGGER_WEEKDAY_FIRST      =TRIGGER_WEEKDAY_SUN,
      TRIGGER_WEEKDAY_LAST       =TRIGGER_WEEKDAY_SAT
     };
   //--- months flags
   enum EnTriggerMonths
     {
      TRIGGER_MONTHS_JAN      =0x00000001,
      TRIGGER_MONTHS_FEB      =0x00000002,
      TRIGGER_MONTHS_MAR      =0x00000004,
      TRIGGER_MONTHS_APR      =0x00000008,
      TRIGGER_MONTHS_MAY      =0x00000010,
      TRIGGER_MONTHS_JUN      =0x00000020,
      TRIGGER_MONTHS_JUL      =0x00000040,
      TRIGGER_MONTHS_AUG      =0x00000080,
      TRIGGER_MONTHS_SEP      =0x00000100,
      TRIGGER_MONTHS_OCT      =0x00000200,
      TRIGGER_MONTHS_NOV      =0x00000400,
      TRIGGER_MONTHS_DEC      =0x00000800,
      //--- flag borders
      TRIGGER_MONTHS_NONE     =0,
      TRIGGER_MONTHS_ALL      =TRIGGER_MONTHS_JAN |TRIGGER_MONTHS_FEB|TRIGGER_MONTHS_MAR|TRIGGER_MONTHS_APR|TRIGGER_MONTHS_MAY|TRIGGER_MONTHS_JUN|TRIGGER_MONTHS_JUL|
      TRIGGER_MONTHS_AUG |TRIGGER_MONTHS_SEP|TRIGGER_MONTHS_OCT|TRIGGER_MONTHS_NOV|TRIGGER_MONTHS_DEC,
      TRIGGER_MONTHS_FIRST    =TRIGGER_MONTHS_JAN,
      TRIGGER_MONTHS_LAST     =TRIGGER_MONTHS_DEC
     };
   //--- month days flags
   enum EnTriggerMonthDays : UINT
     {
      TRIGGER_MONTHDAY_1      =0x00000001,
      TRIGGER_MONTHDAY_2      =0x00000002,
      TRIGGER_MONTHDAY_3      =0x00000004,
      TRIGGER_MONTHDAY_4      =0x00000008,
      TRIGGER_MONTHDAY_5      =0x00000010,
      TRIGGER_MONTHDAY_6      =0x00000020,
      TRIGGER_MONTHDAY_7      =0x00000040,
      TRIGGER_MONTHDAY_8      =0x00000080,
      TRIGGER_MONTHDAY_9      =0x00000100,
      TRIGGER_MONTHDAY_10     =0x00000200,
      TRIGGER_MONTHDAY_11     =0x00000400,
      TRIGGER_MONTHDAY_12     =0x00000800,
      TRIGGER_MONTHDAY_13     =0x00001000,
      TRIGGER_MONTHDAY_14     =0x00002000,
      TRIGGER_MONTHDAY_15     =0x00004000,
      TRIGGER_MONTHDAY_16     =0x00008000,
      TRIGGER_MONTHDAY_17     =0x00010000,
      TRIGGER_MONTHDAY_18     =0x00020000,
      TRIGGER_MONTHDAY_19     =0x00040000,
      TRIGGER_MONTHDAY_20     =0x00080000,
      TRIGGER_MONTHDAY_21     =0x00100000,
      TRIGGER_MONTHDAY_22     =0x00200000,
      TRIGGER_MONTHDAY_23     =0x00400000,
      TRIGGER_MONTHDAY_24     =0x00800000,
      TRIGGER_MONTHDAY_25     =0x01000000,
      TRIGGER_MONTHDAY_26     =0x02000000,
      TRIGGER_MONTHDAY_27     =0x04000000,
      TRIGGER_MONTHDAY_28     =0x08000000,
      TRIGGER_MONTHDAY_29     =0x10000000,
      TRIGGER_MONTHDAY_30     =0x20000000,
      TRIGGER_MONTHDAY_31     =0x40000000,
      //--- flag borders
      TRIGGER_MONTHDAY_NONE   =0,
      TRIGGER_MONTHDAY_ALL    =0x7FFFFFFF,
      TRIGGER_MONTHDAY_FIRST  =TRIGGER_MONTHDAY_1,
      TRIGGER_MONTHDAY_LAST   =TRIGGER_MONTHDAY_31
     };
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTConAutomation* automation)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- uniq ids
   virtual UINT64    ID(void) const=0;
   virtual UINT64    ParentID(void) const=0;
   //--- name
   virtual LPCWSTR   Name(void) const=0;
   virtual MTAPIRES  Name(LPCWSTR name)=0;
   //--- trigger type
   virtual UINT      Trigger(void) const=0;
   virtual MTAPIRES  Trigger(const UINT trigger)=0;
   //--- trigger flags
   virtual UINT64    Flags(void) const=0;
   virtual MTAPIRES  Flags(const UINT64 flags)=0;
   //--- time start
   virtual INT64     TimeStart(void) const=0;
   virtual MTAPIRES  TimeStart(const INT64 start)=0;
   //--- time expire
   virtual INT64     TimeExpire(void) const=0;
   virtual MTAPIRES  TimeExpire(const INT64 expire)=0;
   //--- time weekdays flags
   virtual UINT      TimeWeekdays(void) const=0;
   virtual MTAPIRES  TimeWeekdays(const UINT weekdays)=0;
   //--- time months flags
   virtual UINT      TimeMonths(void) const=0;
   virtual MTAPIRES  TimeMonths(const UINT months)=0;
   //--- time monthdays flags
   virtual UINT      TimeMonthdays(void) const=0;
   virtual MTAPIRES  TimeMonthdays(const UINT monthdays)=0;
   //--- event pause - minutes part (0-59)
   virtual UINT      EventPauseMinutes(void) const=0;
   virtual MTAPIRES  EventPauseMinutes(const UINT minutes)=0;
   //--- event pause - hours part (0-23)
   virtual UINT      EventPauseHours(void) const=0;
   virtual MTAPIRES  EventPauseHours(const UINT hours)=0;
   //--- event pause - hours part (0-30)
   virtual UINT      EventPauseDays(void) const=0;
   virtual MTAPIRES  EventPauseDays(const UINT days)=0;
   //--- event repeats
   virtual UINT      EventRepeats(void) const=0;
   virtual MTAPIRES  EventRepeats(const UINT repeats)=0;
   //--- conditions
   virtual MTAPIRES  ConditionAdd(IMTConAutoCondition* condition)=0;
   virtual MTAPIRES  ConditionUpdate(const UINT pos,const IMTConAutoCondition* condition)=0;
   virtual MTAPIRES  ConditionDelete(const UINT pos)=0;
   virtual MTAPIRES  ConditionClear(void)=0;
   virtual MTAPIRES  ConditionShift(const UINT pos,const int shift)=0;
   virtual UINT      ConditionTotal(void) const=0;
   virtual MTAPIRES  ConditionNext(const UINT pos,IMTConAutoCondition* condition) const=0;
   //--- actions
   virtual MTAPIRES  ActionAdd(IMTConAutoAction* action)=0;
   virtual MTAPIRES  ActionUpdate(const UINT pos,const IMTConAutoAction* action)=0;
   virtual MTAPIRES  ActionDelete(const UINT pos)=0;
   virtual MTAPIRES  ActionClear(void)=0;
   virtual MTAPIRES  ActionShift(const UINT pos,const int shift)=0;
   virtual UINT      ActionTotal(void) const=0;
   virtual MTAPIRES  ActionNext(const UINT pos,IMTConAutoAction* action) const=0;
   //--- explicit destructor is prohibited
protected:
                    ~IMTConAutomation(void) {}
  };
//+------------------------------------------------------------------+
//| Automation config events notification interface                  |
//+------------------------------------------------------------------+
class IMTConAutomationSink
  {
public:
   virtual void      OnAutomationAdd(const IMTConAutomation*    /*config*/) {  }
   virtual void      OnAutomationUpdate(const IMTConAutomation* /*config*/) {  }
   virtual void      OnAutomationDelete(const IMTConAutomation* /*config*/) {  }
   virtual void      OnAutomationSync(void)                                 {  }
  };
//+------------------------------------------------------------------+
