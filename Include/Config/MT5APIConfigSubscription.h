//+------------------------------------------------------------------+
//|                                                 MetaTrader 5 API |
//|                             Copyright 2000-2021, MetaQuotes Ltd. |
//|                                               www.metaquotes.net |
//+------------------------------------------------------------------+
#pragma once
//+------------------------------------------------------------------+
//| Automation symbols config                                        |
//+------------------------------------------------------------------+
class IMTConSubscriptionSymbol
  {
public:
   //--- subscription level
   enum EnLevel
     {
      LEVEL_DELAYED            =0,      // delayed
      LEVEL_REALTIME_LEVEL_1   =1,      // Level 1 realtime, best Bid/Ask
      LEVEL_REALTIME_LEVEL_2   =2,      // Level 2 realtime
      //--- enumeration borders
      LEVEL_FIRST              =LEVEL_DELAYED,
      LEVEL_LAST               =LEVEL_REALTIME_LEVEL_2,
     };
   //--- available tick history
   enum EnTickHistory
     {
      TICK_HISTORY_NONE        =0,
      TICK_HISTORY_LAST_DAY    =1,
      TICK_HISTORY_LAST_WEEK   =2,
      TICK_HISTORY_LAST_MONTH  =3,
      TICK_HISTORY_LAST_3MONTHS=4,
      TICK_HISTORY_LAST_6MONTHS=5,
      TICK_HISTORY_LAST_YEAR   =6,
      TICK_HISTORY_LAST_2YEARS =7,
      TICK_HISTORY_LAST_3YEARS =8,
      TICK_HISTORY_LAST_5YEARS =9,
      TICK_HISTORY_ALL         =10,
      //--- enumeration borders
      TICK_HISTORY_FIRST       =TICK_HISTORY_NONE,
      TICK_HISTORY_LAST        =TICK_HISTORY_ALL,
     };
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTConSubscriptionSymbol* symbol)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- symbols mask
   virtual LPCWSTR   Symbol(void) const=0;
   virtual MTAPIRES  Symbol(LPCWSTR symbols)=0;
   //--- ticks level
   virtual UINT      Level(void) const=0;
   virtual MTAPIRES  Level(const UINT level)=0;
   //--- ticks history mode
   virtual UINT      TickHistory(void) const=0;
   virtual MTAPIRES  TickHistory(const UINT mode)=0;
   //--- explicit destructor is prohibited
protected:
                    ~IMTConSubscriptionSymbol(void) {}
  };
//+------------------------------------------------------------------+
//| Automation config                                                |
//+------------------------------------------------------------------+
class IMTConSubscriptionNews
  {
public:
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTConSubscriptionNews* news)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- symbols mask
   virtual LPCWSTR   Category(void) const=0;
   virtual MTAPIRES  Category(LPCWSTR category)=0;
   //--- language
   virtual UINT      Language(void) const=0;
   virtual MTAPIRES  Language(const UINT language)=0;
   //--- explicit destructor is prohibited
protected:
                    ~IMTConSubscriptionNews(void) {}
  };
//+------------------------------------------------------------------+
//| Subscription config                                              |
//+------------------------------------------------------------------+
class IMTConSubscription
  {
public:
   //--- type
   enum EnType
     {
      TYPE_SUBSCRIPTION          =0,
      TYPE_FOLDER                =1,
      //--- enumeration borders
      TYPE_FIRST                 =TYPE_SUBSCRIPTION,
      TYPE_LAST                  =TYPE_FOLDER
     };
   //--- period
   enum EnPeriod
     {
      PERIOD_ONCE                =0,
      PERIOD_DAILY               =1,
      PERIOD_WEEKLY              =2,
      PERIOD_MONTHLY             =3,
      PERIOD_QUARTERLY           =4,
      PERIOD_ANNUAL              =5,
      PERIOD_CUSTOM              =100,
      //--- enumeration borders
      PERIOD_FIRST               =PERIOD_ONCE,
      PERIOD_LAST                =PERIOD_CUSTOM
     };
   //--- free subscription period
   enum EnFreePeriod
     {
      FREE_PERIOD_NONE           =0,
      FREE_PERIOD_DAY            =1,
      FREE_PERIOD_WEEK           =2,
      FREE_PERIOD_MONTH          =3,
      FREE_PERIOD_QUARTER        =4,
      FREE_PERIOD_YEAR           =5,
      FREE_PERIOD_CUSTOM         =100,
      //--- enumeration borders
      FREE_PERIOD_FIRST          =FREE_PERIOD_NONE,
      FREE_PERIOD_LAST           =FREE_PERIOD_CUSTOM
     };
   //--- flags
   enum EnFlags
     {
      FLAG_NONE                  =0x00000000,  // none
      FLAG_ENABLE                =0x00000001,  // enabled
      FLAG_AUTO_PROLONG          =0x00000002,  // auto prolong enabled
      //--- enumeration borders
      FLAG_ALL                   =FLAG_ENABLE|FLAG_AUTO_PROLONG
     };
   //--- client control modes
   enum EnControlMode
     {
      CONTROL_FULL               =0,            // full
      CONTROL_UNSUBCRIBE         =1,            // only unsubscribe
      CONTROL_VIEW               =2,            // only view
      CONTROL_HIDDEN             =3,            // hidden
      //--- enumeration borders
      CONTROL_FIRST              =CONTROL_FULL,
      CONTROL_LAST               =CONTROL_HIDDEN,
     };
   //--- available pictures enumeration
   enum EnImageType
     {
      IMAGE_CUSTOM                      =0,
      IMAGE_DEFAULT                     =1,
      IMAGE_STOCK_EXCHANGE              =2,
      IMAGE_AUDIT                       =3,
      IMAGE_REPORT                      =4,
      IMAGE_PERSONAL_MANAGER            =5,
      IMAGE_DOCUMENTS_DELIVERY          =6,
      IMAGE_DOCUMENTS_STORING           =7,
      IMAGE_TRANSFER                    =8,
      IMAGE_CONVERSION                  =9,
      //---
      IMAGE_NASDAQ                      =1000,
      IMAGE_TMX_GROUP                   =1001,
      IMAGE_CANADIAN_SECURITIES_EXCHANGE=1002,
      IMAGE_CBOE                        =1003,
      IMAGE_CBOE_FUTURES_EXCHANGE       =1004,
      IMAGE_MEXICAN_DERIVATIVES         =1005,
      IMAGE_FUND_SERV                   =1006,
      IMAGE_CME_CBOT                    =1007,
      IMAGE_CME                         =1008,
      IMAGE_GLOBAL_OTC                  =1009,
      IMAGE_ICE_FUTURES                 =1010,
      IMAGE_IEX_GROUP                   =1011,
      IMAGE_ISE_OPTIONS                 =1012,
      IMAGE_NYSE                        =1013,
      IMAGE_ONE_CHICAGO                 =1014,
      IMAGE_OTC_MARKETS                 =1015,
      IMAGE_BOND_RATINGS                =1016,
      IMAGE_US_REG_NMS                  =1017,
      IMAGE_BOVESPA                     =1018,
      IMAGE_VIENNA_STOCK_EXCHANGE       =1019,
      IMAGE_EURONEXT                    =1020,
      IMAGE_GERMAN_ETFS                 =1021,
      IMAGE_BOLSA_DE_MADRID             =1022,
      IMAGE_STOXX                       =1023,
      IMAGE_MEFF                        =1024,
      IMAGE_BORSA_ITALIANA              =1025,
      IMAGE_EUREX                       =1026,
      IMAGE_MOSCOW_EXCHANGE             =1027,
      IMAGE_NORDIC_DERIVATIVES_EXCHANGE =1028,
      IMAGE_OSLO_STOCK_EXCHANGE         =1029,
      IMAGE_PRAGUE_STOCK_EXCHANGE       =1030,
      IMAGE_SIX_GROUP                   =1031,
      IMAGE_XETRA                       =1032,
      IMAGE_BOERSE_STUTTGART            =1033,
      IMAGE_TURQUOISE                   =1034,
      IMAGE_LONDON_STOCK_EXCHANGE       =1035,
      IMAGE_WARSAW_STOCK_EXCHANGE       =1036,
      IMAGE_BUDAPEST_STOCK_EXCHANGE     =1037,
      IMAGE_BATS_CHI_X_EUROPE           =1038,
      IMAGE_LONDON_METAL_EXCHANGE       =1039,
      IMAGE_EUROPEAN_MUTUAL_FUNDS       =1040,
      IMAGE_TEL_AVIV_STOCK_EXCHANGE     =1041,
      IMAGE_JOHANNESBURG_STOCK_EXCHANGE =1042,
      IMAGE_HANG_SENG_BANK              =1043,
      IMAGE_CHI_X_AUSTRALIA             =1044,
      IMAGE_HKEX                        =1045,
      IMAGE_JPX                         =1046,
      IMAGE_SHANGHAI_STOCK_EXCHANGE     =1047,
      IMAGE_SHENZHEN_STOCK_EXCHANGE     =1048,
      IMAGE_SINGAPORE_EXCHANGE          =1049,
      IMAGE_AUSTRALIAN_STOCK_EXCHANGE   =1050,
      IMAGE_KOREA_STOCK_EXCHANGE        =1051,
      IMAGE_A2X_MARKETS                 =1052,
      IMAGE_ASCE                        =1053,  // Abuja Securities and Commodities Exchange
      IMAGE_ALTX_EAST_AFRICA_EXCHANGE   =1054,
      IMAGE_AMMAN_STOCK_EXCHANGE        =1055,
      IMAGE_ARMENIA_SECURITIES_EXCHANGE =1056,
      IMAGE_ATHENS_STOCK_EXCHANGE       =1057,
      IMAGE_BAKU_STOCK_EXCHANGE         =1058,
      IMAGE_BANJA_LUKA_STOCK_EXCHANGE   =1059,
      IMAGE_BERMUDA_STOCK_EXCHANGE      =1060,
      IMAGE_BOLIVIA_STOCK_EXCHANGE      =1061,
      IMAGE_BVRD                        =1062, // Bolsa de Valores Republica Dominicana
      IMAGE_BOLSAS_Y_MERCADOS_ESPANOLES =1063,
      IMAGE_BOMBAY_STOCK_EXCHANGE       =1064,
      IMAGE_BORSA_ISTANBUL              =1065,
      IMAGE_BOTSWANA_STOCK_EXCHANGE     =1067,
      IMAGE_BOURSA_KUWAIT               =1068,
      IMAGE_BVMAC                       =1069, // Bourse des Valeurs Mobilieres de l Afrique Centrale
      IMAGE_BOURSE_DE_TUNIS             =1070,
      IMAGE_BRVM                        =1071, // Bourse Regionale des Valeurs Mobilieres SA
      IMAGE_BRAZIL_STOCK_EXCHANGE       =1072,
      IMAGE_BUCHAREST_STOCK_EXCHANGE    =1073,
      IMAGE_BUENOS_AIRES_STOCK_EXCHANGE =1074,
      IMAGE_BULGARIAN_STOCK_EXCHANGE    =1075,
      IMAGE_BURSA_MALAYSIA              =1076,
      IMAGE_CALCUTTA_STOCK_EXCHANGE     =1077,
      IMAGE_CARACAS_STOCK_EXCHANGE      =1078,
      IMAGE_CASABLANCA_STOCK_EXCHANGE   =1079,
      IMAGE_COLOMBIA_STOCK_EXCHANGE     =1080,
      IMAGE_COLOMBO_STOCK_EXCHANGE      =1081,
      IMAGE_CYPRUS_STOCK_EXCHANGE       =1082,
      IMAGE_DALIAN_COMMODITY_EXCHANGE   =1083,
      IMAGE_DAMASCUS_SECURITIES_EXCHANGE=1084,
      IMAGE_DAR_ES_SALAAM_STOCK_EXCHANGE=1085,
      IMAGE_DEUTSCHE_BOERSE             =1086,
      IMAGE_DHAKA_STOCK_EXCHANGE        =1087,
      IMAGE_DOHA_SECURITIES_MARKET      =1088,
      IMAGE_DOUALA_STOCK_EXCHANGE       =1089,
      IMAGE_DUBAI_FINANCIAL_MARKET      =1090,
      IMAGE_DUTCH_CARIBBEAN_SECURITIES_EXCHANGE=1091,
      IMAGE_EGYPTIAN_EXCHANGE           =1092,
      IMAGE_ESWATINI_STOCK_MARKET       =1093,
      IMAGE_FRANKFURT_STOCK_EXCHANGE    =1094,
      IMAGE_GEORGIAN_STOCK_EXCHANGE     =1095,
      IMAGE_GHANA_STOCK_EXCHANGE        =1096,
      IMAGE_INDONESIA_STOCK_EXCHANGE    =1097,
      IMAGE_IRAN_FARA_BOURSE            =1098,
      IMAGE_IRAN_MERCANTILE_EXCHANGE    =1099,
      IMAGE_ISLAMABAD_STOCK_EXCHANGE    =1100,
      IMAGE_JAMAICA_STOCK_EXCHANGE      =1101,
      IMAGE_KAZAKHSTAN_STOCK_EXCHANGE   =1102,
      IMAGE_KHARTOUM_STOCK_EXCHANGE     =1103,
      IMAGE_LAHORE_STOCK_EXCHANGE       =1104,
      IMAGE_LIBYAN_STOCK_MARKET         =1105,
      IMAGE_LJUBLJANA_STOCK_EXCHANGE    =1106,
      IMAGE_LUSAKA_STOCK_EXCHANGE       =1107,
      IMAGE_LUXEMBOURG_STOCK_EXCHANGE   =1108,
      IMAGE_MALAWI_STOCK_EXCHANGE       =1109,
      IMAGE_MIAMI_INTERNATIONAL_SECURITIES_EXCHANGE=1110,
      IMAGE_MONGOLIAN_STOCK_EXCHANGE    =1111,
      IMAGE_MULTI_COMMODITY_EXCHANGE    =1112,
      IMAGE_MUSCAT_SECURITIES_MARKET    =1113,
      IMAGE_NAIROBI_SECURITIES_EXCHANGE =1114,
      IMAGE_NCDEX                       =1115, // National Commodity and Derivatives Exchange
      IMAGE_NATIONAL_STOCK_EXCHANGE     =1116,
      IMAGE_NEO_EXCHANGE                =1117,
      IMAGE_NEPAL_STOCK_EXCHANGE        =1118,
      IMAGE_NEW_ZEALAND_EXCHANGE        =1119,
      IMAGE_NIGERIAN_STOCK_EXCHANGE     =1120,
      IMAGE_NXCHANGE                    =1121,
      IMAGE_PAKISTAN_STOCK_EXCHANGE     =1122,
      IMAGE_PALESTINE_SECURITIES_EXCHANGE=1123,
      IMAGE_PFTS_UKRAINE_STOCK_EXCHANGE =1124,
      IMAGE_PHILIPPINE_DEALING_EXCHANGE =1125,
      IMAGE_PHILIPPINE_STOCK_EXCHANGE   =1126,
      IMAGE_SAINT_PETERSBURG_STOCK_EXCHANGE=1127,
      IMAGE_SVGEX                       =1128, // Saint Vincent and the Grenadines Securities Exchange
      IMAGE_SANTIAGO_STOCK_EXCHANGE_MILA=1129,
      IMAGE_STOCK_EXCHANGE_OF_MAURITIUS =1130,
      IMAGE_STOCK_EXCHANGE_OF_THAILAND  =1131,
      IMAGE_TADAWUL                     =1132,
      IMAGE_TAIWAN_STOCK_EXCHANGE       =1133,
      IMAGE_TEHRAN_STOCK_EXCHANGE       =1134,
      IMAGE_TIRANA_STOCK_EXCHANGE       =1135,
      IMAGE_TOKYO_STOCK_EXCHANGE        =1136,
      IMAGE_UGANDA_SECURITIES_EXCHANGE  =1137,
      IMAGE_UKRAINIAN_EXCHANGE          =1138,
      IMAGE_ZAGREB_STOCK_EXCHANGE       =1139,
      IMAGE_ZIMBABWE_STOCK_EXCHANGE     =1140,
      IMAGE_BALTIC_EXCHANGE             =1141,
      //--- enumeration borders
      IMAGE_FIRST                       =IMAGE_CUSTOM,
      IMAGE_LAST                        =IMAGE_BALTIC_EXCHANGE,
     };
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTConSubscription* iface)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- uniq ids
   virtual UINT64    ID(void) const=0;
   virtual UINT64    ParentID(void) const=0;
   //--- id of the subscription that the current one depends on
   virtual UINT64    DependsID(void) const=0;
   virtual MTAPIRES  DependsID(const UINT64 depends_id)=0;
   //--- name
   virtual LPCWSTR   Name(void) const=0;
   virtual MTAPIRES  Name(LPCWSTR name)=0;
   //--- type
   virtual UINT      Type(void) const=0;
   virtual MTAPIRES  Type(const UINT type)=0;
   //--- image
   virtual UINT      Image(void) const=0;
   virtual MTAPIRES  Image(const UINT image)=0;
   //--- description
   virtual LPCWSTR   Description(void) const=0;
   virtual MTAPIRES  Description(LPCWSTR description)=0;
   //--- description URL
   virtual LPCWSTR   URLDescription(void) const=0;
   virtual MTAPIRES  URLDescription(const LPCWSTR url)=0;
   //--- agreement URL
   virtual LPCWSTR   URLAgreement(void) const=0;
   virtual MTAPIRES  URLAgreement(const LPCWSTR url)=0;
   //--- control mode
   virtual UINT      ControlMode(void) const=0;
   virtual MTAPIRES  ControlMode(const UINT mode)=0;
   //--- period mode
   virtual UINT      PeriodMode(void) const=0;
   virtual MTAPIRES  PeriodMode(const UINT mode)=0;
   //--- custom period in days
   virtual UINT      PeriodCustom(void) const=0;
   virtual MTAPIRES  PeriodCustom(const UINT days)=0;
   //--- free period mode
   virtual UINT      PeriodFreeMode(void) const=0;
   virtual MTAPIRES  PeriodFreeMode(const UINT mode)=0;
   //--- free custom period in days
   virtual UINT      PeriodFreeCustom(void) const=0;
   virtual MTAPIRES  PeriodFreeCustom(const UINT days)=0;
   //--- flags
   virtual UINT      Flags(void) const=0;
   virtual MTAPIRES  Flags(const UINT flags)=0;
   //--- price
   virtual double    Price(void) const=0;
   virtual MTAPIRES  Price(const double price)=0;
   //--- price professional
   virtual double    PricePro(void) const=0;
   virtual MTAPIRES  PricePro(const double price)=0;
   //--- real cost
   virtual double    PriceCost(void) const=0;
   virtual MTAPIRES  PriceCost(const double price)=0;
   //--- currency
   virtual LPCWSTR   PriceCurrency(void) const=0;
   virtual MTAPIRES  PriceCurrency(LPCWSTR currency)=0;
   //--- allowed country list
   virtual MTAPIRES  CountryAdd(LPCWSTR path)=0;
   virtual MTAPIRES  CountryUpdate(const UINT pos,LPCWSTR path)=0;
   virtual MTAPIRES  CountryShift(const UINT pos,const int shift)=0;
   virtual MTAPIRES  CountryDelete(const UINT pos)=0;
   virtual MTAPIRES  CountryClear(void)=0;
   virtual UINT      CountryTotal(void) const=0;
   virtual LPCWSTR   CountryNext(const UINT pos) const=0;
   //--- allowed groups list
   virtual MTAPIRES  GroupAdd(LPCWSTR path)=0;
   virtual MTAPIRES  GroupUpdate(const UINT pos,LPCWSTR path)=0;
   virtual MTAPIRES  GroupDelete(const UINT pos)=0;
   virtual MTAPIRES  GroupClear(void)=0;
   virtual MTAPIRES  GroupShift(const UINT pos,const int shift)=0;
   virtual UINT      GroupTotal(void) const=0;
   virtual LPCWSTR   GroupNext(const UINT pos) const=0;
   //--- symbols settings
   virtual MTAPIRES  SymbolAdd(IMTConSubscriptionSymbol* symbol)=0;
   virtual MTAPIRES  SymbolUpdate(const UINT pos,const IMTConSubscriptionSymbol* symbol)=0;
   virtual MTAPIRES  SymbolDelete(const UINT pos)=0;
   virtual MTAPIRES  SymbolClear(void)=0;
   virtual MTAPIRES  SymbolShift(const UINT pos,const int shift)=0;
   virtual UINT      SymbolTotal(void) const=0;
   virtual MTAPIRES  SymbolNext(const UINT pos,IMTConSubscriptionSymbol* symbol) const=0;
   //--- symbols settings
   virtual MTAPIRES  NewsAdd(IMTConSubscriptionNews* news)=0;
   virtual MTAPIRES  NewsUpdate(const UINT pos,const IMTConSubscriptionNews* news)=0;
   virtual MTAPIRES  NewsDelete(const UINT pos)=0;
   virtual MTAPIRES  NewsClear(void)=0;
   virtual MTAPIRES  NewsShift(const UINT pos,const int shift)=0;
   virtual UINT      NewsTotal(void) const=0;
   virtual MTAPIRES  NewsNext(const UINT pos,IMTConSubscriptionNews* news) const=0;
   //--- explicit destructor is prohibited
protected:
                    ~IMTConSubscription(void) {}
  };
//+------------------------------------------------------------------+
//| Automation config events notification interface                  |
//+------------------------------------------------------------------+
class IMTConSubscriptionSink
  {
public:
   virtual void      OnSubscriptionCfgAdd(const IMTConSubscription*    /*config*/) {  }
   virtual void      OnSubscriptionCfgUpdate(const IMTConSubscription* /*config*/) {  }
   virtual void      OnSubscriptionCfgDelete(const IMTConSubscription* /*config*/) {  }
   virtual void      OnSubscriptionCfgSync(void)                                   {  }
  };
//+------------------------------------------------------------------+
