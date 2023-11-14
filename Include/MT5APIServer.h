//+------------------------------------------------------------------+
//|                                                 MetaTrader 5 API |
//|                             Copyright 2000-2021, MetaQuotes Ltd. |
//|                                               www.metaquotes.net |
//+------------------------------------------------------------------+
#pragma once
#include <in6addr.h>
#include "MT5APIConstants.h"
#include "MT5APILogger.h"
#include "MT5APITools.h"
#include "Config\MT5APIConfigPlugin.h"
#include "Config\MT5APIConfigCommon.h"
#include "Config\MT5APIConfigTime.h"
#include "Config\MT5APIConfigFirewall.h"
#include "Config\MT5APIConfigSymbol.h"
#include "Config\MT5APIConfigSpread.h"
#include "Config\MT5APIConfigGroup.h"
#include "Config\MT5APIConfigHoliday.h"
#include "Config\MT5APIConfigFeeder.h"
#include "Config\MT5APIConfigGateway.h"
#include "Config\MT5APIConfigReport.h"
#include "Config\MT5APIConfigManager.h"
#include "Config\MT5APIConfigHistory.h"
#include "Config\MT5APIConfigNetwork.h"
#include "Config\MT5APIConfigRoute.h"
#include "Config\MT5APIConfigEmail.h"
#include "Config\MT5APIConfigMessenger.h"
#include "Config\MT5APIConfigAutomation.h"
#include "Config\MT5APIConfigSubscription.h"
#include "Bases\MT5APIUser.h"
#include "Bases\MT5APIAccount.h"
#include "Bases\MT5APIBook.h"
#include "Bases\MT5APIChart.h"
#include "Bases\MT5APIDeal.h"
#include "Bases\MT5APIOrder.h"
#include "Bases\MT5APIPosition.h"
#include "Bases\MT5APIExecution.h"
#include "Bases\MT5APITick.h"
#include "Bases\MT5APIMail.h"
#include "Bases\MT5APINews.h"
#include "Bases\MT5APIDaily.h"
#include "Bases\MT5APIRequest.h"
#include "Bases\MT5APIConfirm.h"
#include "Bases\MT5APIByteStream.h"
#include "Bases\MT5APICertificate.h"
#include "Bases\MT5APIExecution.h"
#include "Bases\MT5APIOnline.h"
#include "Bases\MT5APIDataset.h"
#include "Bases\MT5APIClient.h"
#include "Bases\MT5APIDocument.h"
#include "Bases\MT5APIComment.h"
#include "Bases\MT5APIAttachment.h"
#include "Bases\MT5APISubscription.h"
//+------------------------------------------------------------------+
//| Server API version                                               |
//+------------------------------------------------------------------+
#define MTServerAPIVersion             2940
#define MTServerAPIDate                L"21 May 2021"
//+------------------------------------------------------------------+
//| Structures                                                       |
//+------------------------------------------------------------------+
//+------------------------------------------------------------------+
//| Plugin parameter structure                                       |
//+------------------------------------------------------------------+
#pragma pack(push,1)
struct MTPluginParam
  {
   //--- parameter types
   enum EnParamType
     {
      TYPE_STRING    =0,   // string
      TYPE_INT       =1,   // integer
      TYPE_FLOAT     =2,   // floating
      TYPE_TIME      =3,   // time only
      TYPE_DATE      =4,   // date only
      TYPE_DATETIME  =5,   // date & time
      TYPE_GROUPS    =6,   // groups list
      TYPE_SYMBOLS   =7,   // symbols list
      //---
      TYPE_FIRST     =TYPE_STRING,
      TYPE_LAST      =TYPE_SYMBOLS
     };
   //---
   UINT              type;                                 // parameter type (EnParamType)
   wchar_t           name[64];                             // parameter name
   wchar_t           value[256];                           // parameter value
   UINT              reserved[16];                         // reserved
  };
#pragma pack(pop)
//+------------------------------------------------------------------+
//| Plugin about structure                                           |
//+------------------------------------------------------------------+
#pragma pack(push,1)
struct MTPluginInfo
  {
   UINT              version;                               // plugin version
   UINT              version_api;                           // server API version
   wchar_t           name[64];                              // plugin Name
   wchar_t           copyright[128];                        // copyright
   wchar_t           description[256];                      // description
   MTPluginParam     defaults[128];                         // default parameters
   UINT              defaults_total;                        // default parameters total
   UINT              reserved[128];                         // reserved
  };
#pragma pack(pop)
//+------------------------------------------------------------------+
//| Server description structure                                     |
//+------------------------------------------------------------------+
#pragma pack(push,1)
struct MTServerInfo
  {
   wchar_t           platform_name[64];                     // platform name
   wchar_t           platform_owner[128];                   // platform owner
   UINT              server_version;                        // server version
   UINT              server_build;                          // server build
   UINT              server_type;                           // server type
   UINT64            server_id;                             // server id
   UINT              reserved[32];                          // reserved
  };
#pragma pack(pop)
//+------------------------------------------------------------------+
//| Custom commands notification interface                           |
//+------------------------------------------------------------------+
class IMTCustomSink
  {
public:
   //--- manager API command
   virtual MTAPIRES  HookManagerCommand(LPCWSTR              /*ip*/,
                                        const IMTConManager* /*manager*/,
                                        LPCVOID              /*indata*/,
                                        const UINT           /*indata_len*/,
                                        LPVOID&              /*outdata*/,
                                        UINT&                /*outdata_len*/) { return(MT_RET_OK_NONE); }
   //--- manager API command
   virtual MTAPIRES  HookManagerCommand(const UINT64         /*session*/,
                                        LPCWSTR              /*ip*/,
                                        const IMTConManager* /*manager*/,
                                        IMTByteStream*       /*indata*/,
                                        IMTByteStream*       /*outdata*/)     { return(MT_RET_OK_NONE); }
   //--- Web API command
   virtual MTAPIRES  HookWebAPICommand(const UINT64          /*session*/,
                                       LPCWSTR               /*ip*/,
                                       const IMTConManager*  /*manager*/,
                                       LPCWSTR               /*command*/,
                                       IMTByteStream*        /*indata*/,
                                       IMTByteStream*        /*outdata*/)     { return(MT_RET_OK_NONE); }
  };
//+------------------------------------------------------------------+
//| Trades notification interface                                    |
//+------------------------------------------------------------------+
class IMTTradeSink
  {
public:
   //--- trade request event
   virtual void      OnTradeRequestAdd(const IMTRequest*   /*request*/,
                                       const IMTConGroup*  /*group*/,
                                       const IMTConSymbol* /*symbol*/,
                                       const IMTPosition*  /*position*/,
                                       const IMTOrder*     /*order*/)    {  }
   //--- trade request process event
   virtual void      OnTradeRequestUpdate(const IMTRequest* /*request*/) {  }
   //--- trade request process event
   virtual void      OnTradeRequestDelete(const IMTRequest* /*request*/) {  }
   //--- trade request process event
   virtual void      OnTradeRequestProcess(const IMTRequest*   /*request*/,
                                           const IMTConfirm*   /*confirm*/,
                                           const IMTConGroup*  /*group*/,
                                           const IMTConSymbol* /*symbol*/,
                                           const IMTPosition*  /*position*/,
                                           const IMTOrder*     /*order*/,
                                           const IMTDeal*      /*deal*/) {   }
   //--- trade request add hook
   virtual MTAPIRES  HookTradeRequestAdd(IMTRequest*         /*request*/,
                                         const IMTConGroup*  /*group*/,
                                         const IMTConSymbol* /*symbol*/,
                                         const IMTPosition*  /*position*/,
                                         const IMTOrder*     /*order*/,
                                         IMTOrder*           /*order_new*/) { return(MT_RET_OK); }
   //--- trade request route hook
   virtual MTAPIRES  HookTradeRequestRoute(IMTRequest*         /*request*/,
                                           IMTConfirm*         /*confirm*/,
                                           const IMTConGroup*  /*group*/,
                                           const IMTConSymbol* /*symbol*/,
                                           const IMTPosition*  /*position*/,
                                           const IMTOrder*     /*order*/)   { return(MT_RET_OK); }
   //--- trade request deal hook
   virtual MTAPIRES  HookTradeRequestProcess(const IMTRequest*   /*request*/,
                                             const IMTConfirm*   /*confirm*/,
                                             const IMTConGroup*  /*group*/,
                                             const IMTConSymbol* /*symbol*/,
                                             IMTPosition*        /*position*/,
                                             IMTOrder*           /*order*/,
                                             IMTDeal*            /*deal*/)  { return(MT_RET_OK); }
   //--- rollover calculation hook
   virtual MTAPIRES HookTradeRollover(const INT64         /*datetime*/,
                                      const IMTConGroup*  /*group*/,
                                      const IMTConSymbol* /*symbol*/,
                                      const IMTPosition*  /*position*/,
                                      const double        /*original_value*/,
                                      double&             /*new_value*/)    { return(MT_RET_OK); }
   //--- interest calculation hook
   virtual MTAPIRES HookTradeInterest(const INT64         /*datetime*/,
                                      const IMTConGroup*  /*group*/,
                                      const IMTAccount*   /*account*/,
                                      const double        /*original_value*/,
                                      double&             /*new_value*/)    { return(MT_RET_OK); }
   //--- interest charge hook
   virtual MTAPIRES HookTradeInterestCharge(const INT64         /*datetime*/,
                                            const IMTConGroup*  /*group*/,
                                            const IMTUser*      /*user*/,
                                            const double        /*original_value*/,
                                            double&             /*new_value*/)    { return(MT_RET_OK); }
   //--- order commission calculation
   virtual MTAPIRES HookTradeCommissionOrder(const IMTConCommission*  /*commission*/,
                                             const IMTConGroup*       /*group*/,
                                             const IMTConSymbol*      /*symbol*/,
                                             const IMTOrder*          /*order*/,
                                             const double             /*original_value*/,
                                             double&                  /*new_value*/)  { return(MT_RET_OK); }
   //--- final commission calculation
   virtual MTAPIRES HookTradeCommissionCharge(const INT64             /*period_start*/,
                                              const INT64             /*period_end*/,
                                              const IMTConCommission* /*commission*/,
                                              const IMTConGroup*      /*group*/,
                                              const IMTUser*          /*user*/,
                                              const double            /*original_value*/,
                                              double&                 /*new_value*/)  { return(MT_RET_OK); }
   //--- order commission calculation
   virtual MTAPIRES HookTradeCommissionDeal(const IMTConCommission*   /*commission*/,
                                             const IMTConGroup*       /*group*/,
                                             const IMTConSymbol*      /*symbol*/,
                                             const IMTDeal*           /*deal*/,
                                             const double             /*original_value*/,
                                             double&                  /*new_value*/)  { return(MT_RET_OK); }
   //--- trade execution event
   virtual void      OnTradeExecution(const IMTConGateway* /*gateway*/,
                                      const IMTExecution*  /*execution*/,
                                      const IMTConGroup*   /*group*/,
                                      const IMTConSymbol*  /*symbol*/,
                                      const IMTPosition*   /*position*/,
                                      const IMTOrder*      /*order*/,
                                      const IMTDeal*       /*deal*/) {   }
   //--- trade execution hook
   virtual MTAPIRES  HookTradeExecution(const IMTConGateway* /*gateway*/,
                                        const IMTExecution*  /*execution*/,
                                        const IMTConGroup*   /*group*/,
                                        const IMTConSymbol*  /*symbol*/,
                                        IMTPosition*         /*position*/,
                                        IMTOrder*            /*order*/,
                                        IMTDeal*             /*deal*/)  { return(MT_RET_OK); }
   //--- trade request refused on pre-trade control event
   virtual void      OnTradeRequestRefuse(const IMTRequest* /*request*/) {  }
   //--- trade request process event
   virtual void      OnTradeRequestProcessCloseBy(const IMTRequest*   /*request*/,
                                           const IMTConfirm*   /*confirm*/,
                                           const IMTConGroup*  /*group*/,
                                           const IMTConSymbol* /*symbol*/,
                                           const IMTPosition*  /*position*/,
                                           const IMTOrder*     /*order*/,
                                           const IMTDeal*      /*deal*/,
                                           const IMTDeal*      /*deal_by*/) {   }
   //--- trade request deal hook
   virtual MTAPIRES  HookTradeRequestProcessCloseBy(const IMTRequest*   /*request*/,
                                                    const IMTConfirm*   /*confirm*/,
                                                    const IMTConGroup*  /*group*/,
                                                    const IMTConSymbol* /*symbol*/,
                                                    IMTPosition*        /*position*/,
                                                    IMTOrder*           /*order*/,
                                                    IMTDeal*            /*deal*/,
                                                    IMTDeal*            /*deal_by*/) { return(MT_RET_OK); }
   //--- interest charge hook
   virtual MTAPIRES HookTradeInterestChargeDeal(const INT64         /*datetime*/,
                                                const IMTConGroup*  /*group*/,
                                                const IMTUser*      /*user*/,
                                                IMTDeal*            /*deal*/)    { return(MT_RET_OK); }
   //--- trade request route hook
   virtual MTAPIRES  HookTradeRequestRuleFilter(IMTRequest*         /*request*/,
                                                IMTConRoute*        /*rule*/,
                                                const IMTConGroup*  /*group*/)   { return(MT_RET_OK_NONE); }
   //--- trade request route hook
   virtual MTAPIRES  HookTradeRequestRuleApply(IMTRequest*         /*request*/,
                                               IMTConRoute*        /*rule*/,
                                               const IMTConGroup*  /*group*/)    { return(MT_RET_OK_NONE); }

   //--- trade execution event for close by
   virtual void      OnTradeExecutionCloseBy(const IMTExecution* /*execution*/,
                                             const IMTConGroup*  /*group*/,
                                             const IMTConSymbol* /*symbol*/,
                                             const IMTPosition*  /*position*/,
                                             const IMTOrder*     /*order*/,
                                             const IMTDeal*      /*deal*/,
                                             const IMTDeal*      /*deal_by*/) {   }
   //--- trade execution hook for close by
   virtual MTAPIRES  HookTradeExecutionCloseBy(const IMTExecution* /*execution*/,
                                               const IMTConGroup*  /*group*/,
                                               const IMTConSymbol* /*symbol*/,
                                               IMTPosition*        /*position*/,
                                               IMTOrder*           /*order*/,
                                               IMTDeal*            /*deal*/,
                                               IMTDeal*            /*deal_by*/)      { return(MT_RET_OK); }
   //--- position split event
   virtual void      OnTradeSplit(const UINT /*shares_new*/,const UINT /*shares_old*/,
                                  const UINT /*round_prices*/,const UINT /*round_volumes*/,const UINT /*flags*/,
                                  const double /*adjustment*/,
                                  const IMTConGroup* /*group*/,const IMTConSymbol* /*symbol*/,
                                  const IMTPosition* /*position_old*/,const IMTPosition* /*position_new*/) {   }
   virtual MTAPIRES  HookTradeSplit(const UINT /*shares_new*/,const UINT /*shares_old*/,
                                    const UINT /*round_prices*/,const UINT /*round_volumes*/,const UINT /*flags*/,
                                    const double /*adjustment*/,
                                    const IMTConGroup* /*group*/,const IMTConSymbol* /*symbol*/,
                                    IMTPosition* /*position_old*/,IMTPosition* /*position_new*/) { return(MT_RET_OK); }
  };
//+------------------------------------------------------------------+
//| End of day notification interface                                |
//+------------------------------------------------------------------+
class IMTEndOfDaySink
  {
public:
   //--- end of day events
   virtual void      OnEODStart(const INT64 /*datetime*/,const INT64 /*prev_datetime*/)                                        { }
   virtual void      OnEODGroupStart(const INT64 /*datetime*/,const INT64 /*prev_datetime*/,const IMTConGroup* /*group*/)      { }
   virtual void      OnEODGroupCommissions(const INT64 /*datetime*/,const INT64 /*prev_datetime*/,const IMTConGroup* /*group*/){ }
   virtual void      OnEODGroupInterest(const INT64 /*datetime*/,const INT64 /*prev_datetime*/,const IMTConGroup* /*group*/)   { }
   virtual void      OnEODGroupStatements(const INT64 /*datetime*/,const INT64 /*prev_datetime*/,const IMTConGroup* /*group*/) { }
   virtual void      OnEODGroupRollovers(const INT64 /*datetime*/,const INT64 /*prev_datetime*/,const IMTConGroup* /*group*/)  { }
   virtual void      OnEODGroupFinish(const INT64 /*datetime*/,const INT64 /*prev_datetime*/,const IMTConGroup* /*group*/)     { }
   virtual void      OnEODFinish(const INT64 /*datetime*/,const INT64 /*prev_datetime*/)                                       { }
   //--- end of month events
   virtual void      OnEOMStart(const INT64 /*datetime*/,const INT64 /*prev_datetime*/)                                        { }
   virtual void      OnEOMGroupStart(const INT64 /*datetime*/,const INT64 /*prev_datetime*/,const IMTConGroup* /*group*/)      { }
   virtual void      OnEOMGroupCommissions(const INT64 /*datetime*/,const INT64 /*prev_datetime*/,const IMTConGroup* /*group*/){ }
   virtual void      OnEOMGroupInterest(const INT64 /*datetime*/,const INT64 /*prev_datetime*/,const IMTConGroup* /*group*/)   { }
   virtual void      OnEOMGroupStatements(const INT64 /*datetime*/,const INT64 /*prev_datetime*/,const IMTConGroup* /*group*/) { }
   virtual void      OnEOMGroupFinish(const INT64 /*datetime*/,const INT64 /*prev_datetime*/,const IMTConGroup* /*group*/)     { }
   virtual void      OnEOMFinish(const INT64 /*datetime*/,const INT64 /*prev_datetime*/)                                       { }
  };
//+------------------------------------------------------------------+
//| Server events notification interface                             |
//+------------------------------------------------------------------+
class IMTServerSink
  {
public:
   virtual void      OnServerLog(const INT /*code*/,const UINT /*type*/,const INT64 /*datetime_msc*/,LPCWSTR /*source*/,LPCWSTR /*message*/){}
  };
//+------------------------------------------------------------------+
//| Server API interface                                             |
//+------------------------------------------------------------------+
class IMTServerAPI
  {
public:
   //--- server description
   virtual MTAPIRES  About(MTServerInfo& info)=0;
   //--- license check
   virtual MTAPIRES  LicenseCheck(LPCWSTR license_name)=0;
   //--- memory management
   virtual void*     Allocate(const UINT bytes)=0;
   virtual void      Free(void* ptr)=0;
   //--- server management functions
   virtual MTAPIRES  ServerRestart(void)=0;
   virtual MTAPIRES  ServerSubscribe(IMTServerSink* sink)=0;
   virtual MTAPIRES  ServerUnsubscribe(IMTServerSink* sink)=0;
   virtual MTAPIRES  ServerReserved3(void)=0;
   virtual MTAPIRES  ServerReserved4(void)=0;
   //--- server log functions
   virtual MTAPIRES  LoggerOut(const UINT code,LPCWSTR msg,...)=0;
   virtual MTAPIRES  LoggerRequest(const UINT mode,const UINT type,const INT64 from,const INT64 to,LPCWSTR filter,MTLogRecord*& records,UINT& records_total)=0;
   virtual void      LoggerFlush(void)=0;
   virtual MTAPIRES  LoggerReserved1(void)=0;
   virtual MTAPIRES  LoggerReserved2(void)=0;
   virtual MTAPIRES  LoggerReserved3(void)=0;
   virtual MTAPIRES  LoggerReserved4(void)=0;
   //--- plugins configs
   virtual IMTConPlugin* PluginCreate(void)=0;
   virtual IMTConPluginModule* PluginModuleCreate(void)=0;
   virtual IMTConParam* PluginParamCreate(void)=0;
   virtual MTAPIRES  PluginSubscribe(IMTConPluginSink* sink)=0;
   virtual MTAPIRES  PluginUnsubscribe(IMTConPluginSink* sink)=0;
   virtual MTAPIRES  PluginCurrent(IMTConPlugin* plugin)=0;
   virtual MTAPIRES  PluginAdd(IMTConPlugin* plugin)=0;
   virtual MTAPIRES  PluginDelete(LPCWSTR name)=0;
   virtual MTAPIRES  PluginDelete(const UINT pos)=0;
   virtual MTAPIRES  PluginShift(const UINT pos,const int shift)=0;
   virtual UINT      PluginTotal(void)=0;
   virtual MTAPIRES  PluginNext(const UINT pos,IMTConPlugin* plugin)=0;
   virtual MTAPIRES  PluginGet(LPCWSTR name,IMTConPlugin* plugin)=0;
   virtual UINT      PluginModuleTotal(void)=0;
   virtual MTAPIRES  PluginModuleNext(const UINT pos,IMTConPluginModule* module)=0;
   virtual MTAPIRES  PluginModuleGet(LPCWSTR name,IMTConPluginModule* module)=0;
   virtual MTAPIRES  PluginDelete(const UINT64 server,LPCWSTR name)=0;
   virtual MTAPIRES  PluginGet(const UINT64 server,LPCWSTR name,IMTConPlugin* plugin)=0;
   virtual MTAPIRES  PluginModuleGet(const UINT64 server,LPCWSTR name,IMTConPluginModule* module)=0;
   virtual MTAPIRES  PluginReserved4(void)=0;
   //--- common config 
   virtual IMTConCommon* CommonCreate(void)=0;
   virtual MTAPIRES  CommonSubscribe(IMTConCommonSink* sink)=0;
   virtual MTAPIRES  CommonUnsubscribe(IMTConCommonSink* sink)=0;
   virtual MTAPIRES  CommonGet(IMTConCommon* common)=0;
   virtual MTAPIRES  CommonSet(const IMTConCommon* common)=0;
   virtual MTAPIRES  CommonReserved1(void)=0;
   virtual MTAPIRES  CommonReserved2(void)=0;
   virtual MTAPIRES  CommonReserved3(void)=0;
   virtual MTAPIRES  CommonReserved4(void)=0;
   //--- platform server config
   virtual IMTConServer* NetServerCreate(void)=0;
   virtual IMTConServerRange* NetServerRangeCreate(void)=0;
   virtual MTAPIRES  NetServerSubscribe(IMTConServerSink* sink)=0;
   virtual MTAPIRES  NetServerUnsubscribe(IMTConServerSink* sink)=0;
   virtual MTAPIRES  NetServerAdd(IMTConServer* config)=0;
   virtual MTAPIRES  NetServerDelete(const UINT pos)=0;
   virtual MTAPIRES  NetServerShift(const UINT pos,const int shift)=0;
   virtual UINT      NetServerTotal(void)=0;
   virtual MTAPIRES  NetServerNext(const UINT pos,IMTConServer* config)=0;
   virtual MTAPIRES  NetServerGet(const UINT64 id,IMTConServer* config)=0;
   virtual IMTConAddressRange* NetServerAddressRangeCreate(void)=0;
   virtual IMTConClusterState* NetServerClusterStateCreate(void)=0;
   virtual MTAPIRES  NetServerReserved3(void)=0;
   virtual MTAPIRES  NetServerReserved4(void)=0;
   //--- time config
   virtual IMTConTime* TimeCreate(void)=0;
   virtual MTAPIRES  TimeSubscribe(IMTConTimeSink* sink)=0;
   virtual MTAPIRES  TimeUnsubscribe(IMTConTimeSink* sink)=0;
   virtual INT64     TimeCurrent(void)=0;
   virtual MTAPIRES  TimeGet(IMTConTime* common)=0;
   virtual MTAPIRES  TimeSet(const IMTConTime* time)=0;
   virtual INT64     TimeCurrentMsc(void)=0;
   virtual MTAPIRES  TimeReserved2(void)=0;
   virtual MTAPIRES  TimeReserved3(void)=0;
   virtual MTAPIRES  TimeReserved4(void)=0;
   //--- holidays configuration
   virtual IMTConHoliday* HolidayCreate()=0;
   virtual MTAPIRES  HolidaySubscribe(IMTConHolidaySink* sink)=0;
   virtual MTAPIRES  HolidayUnsubscribe(IMTConHolidaySink* sink)=0;
   virtual MTAPIRES  HolidayAdd(IMTConHoliday* config)=0;
   virtual MTAPIRES  HolidayDelete(const UINT pos)=0;
   virtual MTAPIRES  HolidayShift(const UINT pos,const int shift)=0;
   virtual UINT      HolidayTotal(void)=0;
   virtual MTAPIRES  HolidayNext(const UINT pos,IMTConHoliday* config)=0;
   virtual MTAPIRES  HolidayReserved1(void)=0;
   virtual MTAPIRES  HolidayReserved2(void)=0;
   virtual MTAPIRES  HolidayReserved3(void)=0;
   virtual MTAPIRES  HolidayReserved4(void)=0;
   //--- server firewall configuration
   virtual IMTConFirewall* FirewallCreate()=0;
   virtual MTAPIRES  FirewallSubscribe(IMTConFirewallSink* sink)=0;
   virtual MTAPIRES  FirewallUnsubscribe(IMTConFirewallSink* sink)=0;
   virtual MTAPIRES  FirewallAdd(IMTConFirewall* config)=0;
   virtual MTAPIRES  FirewallDelete(const UINT pos)=0;
   virtual MTAPIRES  FirewallShift(const UINT pos,const int shift)=0;
   virtual UINT      FirewallTotal(void)=0;
   virtual MTAPIRES  FirewallNext(const UINT pos,IMTConFirewall* config)=0;
   virtual MTAPIRES  FirewallReserved1(void)=0;
   virtual MTAPIRES  FirewallReserved2(void)=0;
   virtual MTAPIRES  FirewallReserved3(void)=0;
   virtual MTAPIRES  FirewallReserved4(void)=0;
   //--- symbols configuration
   virtual IMTConSymbol* SymbolCreate(void)=0;
   virtual IMTConSymbolSession* SymbolSessionCreate(void)=0;
   virtual MTAPIRES  SymbolSubscribe(IMTConSymbolSink* sink)=0;
   virtual MTAPIRES  SymbolUnsubscribe(IMTConSymbolSink* sink)=0;
   virtual MTAPIRES  SymbolAdd(IMTConSymbol* symbol)=0;
   virtual MTAPIRES  SymbolDelete(LPCWSTR name)=0;
   virtual MTAPIRES  SymbolDelete(const UINT pos)=0;
   virtual MTAPIRES  SymbolShift(const UINT pos,const int shift)=0;
   virtual UINT      SymbolTotal(void)=0;
   virtual MTAPIRES  SymbolNext(const UINT pos,IMTConSymbol* symbol)=0;
   virtual MTAPIRES  SymbolGet(LPCWSTR name,IMTConSymbol* symbol)=0;
   virtual MTAPIRES  SymbolGet(LPCWSTR name,const IMTConGroup* group,IMTConSymbol* symbol)=0;
   virtual MTAPIRES  SymbolExist(const IMTConSymbol* symbol,const IMTConGroup* group)=0;
   virtual MTAPIRES  SymbolReserved1(void)=0;
   virtual MTAPIRES  SymbolReserved2(void)=0;
   virtual MTAPIRES  SymbolReserved3(void)=0;
   virtual MTAPIRES  SymbolReserved4(void)=0;
   //--- clients group configuration
   virtual IMTConGroup* GroupCreate(void)=0;
   virtual IMTConGroupSymbol* GroupSymbolCreate(void)=0;
   virtual IMTConCommission* GroupCommissionCreate(void)=0;
   virtual IMTConCommTier* GroupTierCreate(void)=0;
   virtual MTAPIRES  GroupSubscribe(IMTConGroupSink* sink)=0;
   virtual MTAPIRES  GroupUnsubscribe(IMTConGroupSink* sink)=0;
   virtual MTAPIRES  GroupAdd(IMTConGroup* group)=0;
   virtual MTAPIRES  GroupDelete(LPCWSTR name)=0;
   virtual MTAPIRES  GroupDelete(const UINT pos)=0;
   virtual MTAPIRES  GroupShift(const UINT pos,const int shift)=0;
   virtual UINT      GroupTotal(void)=0;
   virtual MTAPIRES  GroupNext(const UINT pos,IMTConGroup* group)=0;
   virtual MTAPIRES  GroupGet(LPCWSTR name,IMTConGroup* group)=0;
   virtual MTAPIRES  GroupReserved1(void)=0;
   virtual MTAPIRES  GroupReserved2(void)=0;
   virtual MTAPIRES  GroupReserved3(void)=0;
   virtual MTAPIRES  GroupReserved4(void)=0;
   //--- managers configuration
   virtual IMTConManager* ManagerCreate(void)=0;
   virtual IMTConManagerAccess* ManagerAccessCreate(void)=0;
   virtual MTAPIRES  ManagerSubscribe(IMTConManagerSink* sink)=0;
   virtual MTAPIRES  ManagerUnsubscribe(IMTConManagerSink* sink)=0;
   virtual MTAPIRES  ManagerAdd(IMTConManager* manager)=0;
   virtual MTAPIRES  ManagerDelete(const UINT pos)=0;
   virtual MTAPIRES  ManagerShift(const UINT pos,const int shift)=0;
   virtual UINT      ManagerTotal(void)=0;
   virtual MTAPIRES  ManagerNext(const UINT pos,IMTConManager* manager)=0;
   virtual MTAPIRES  ManagerGet(const UINT64 login,IMTConManager* manager)=0;
   virtual MTAPIRES  ManagerReserved1(void)=0;
   virtual MTAPIRES  ManagerReserved2(void)=0;
   virtual MTAPIRES  ManagerReserved3(void)=0;
   virtual MTAPIRES  ManagerReserved4(void)=0;
   //--- history synchronization configuration
   virtual IMTConHistorySync* HistorySyncCreate(void)=0;
   virtual MTAPIRES  HistorySyncSubscribe(IMTConHistorySyncSink* sink)=0;
   virtual MTAPIRES  HistorySyncUnsubscribe(IMTConHistorySyncSink* sink)=0;
   virtual MTAPIRES  HistorySyncAdd(IMTConHistorySync* config)=0;
   virtual MTAPIRES  HistorySyncDelete(const UINT pos)=0;
   virtual MTAPIRES  HistorySyncShift(const UINT pos,const int shift)=0;
   virtual UINT      HistorySyncTotal(void)=0;
   virtual MTAPIRES  HistorySyncNext(const UINT pos,IMTConHistorySync* config)=0;
   virtual MTAPIRES  HistorySyncReserved1(void)=0;
   virtual MTAPIRES  HistorySyncReserved2(void)=0;
   virtual MTAPIRES  HistorySyncReserved3(void)=0;
   virtual MTAPIRES  HistorySyncReserved4(void)=0;
   //--- datafeeds configuration
   virtual IMTConFeeder* FeederCreate(void)=0;
   virtual IMTConFeederModule* FeederModuleCreate(void)=0;
   virtual IMTConParam* FeederParamCreate(void)=0;
   virtual IMTConFeederTranslate* FeederTranslateCreate(void)=0;
   virtual MTAPIRES  FeederSubscribe(IMTConFeederSink* sink)=0;
   virtual MTAPIRES  FeederUnsubscribe(IMTConFeederSink* sink)=0;
   virtual MTAPIRES  FeederAdd(IMTConFeeder* feeder)=0;
   virtual MTAPIRES  FeederDelete(LPCWSTR name)=0;
   virtual MTAPIRES  FeederDelete(const UINT pos)=0;
   virtual MTAPIRES  FeederShift(const UINT pos,const int shift)=0;
   virtual UINT      FeederTotal(void)=0;
   virtual MTAPIRES  FeederNext(const UINT pos,IMTConFeeder* feeder)=0;
   virtual MTAPIRES  FeederGet(LPCWSTR name,IMTConFeeder* feeder)=0;
   virtual UINT      FeederModuleTotal(void)=0;
   virtual MTAPIRES  FeederModuleNext(const UINT pos,IMTConFeederModule* module)=0;
   virtual MTAPIRES  FeederModuleGet(LPCWSTR name,IMTConFeederModule* module)=0;
   virtual MTAPIRES  FeederRestart(LPCWSTR name)=0;
   virtual MTAPIRES  FeederReserved2(void)=0;
   virtual MTAPIRES  FeederReserved3(void)=0;
   virtual MTAPIRES  FeederReserved4(void)=0;
   //--- gateways configuration
   virtual IMTConGateway* GatewayCreate(void)=0;
   virtual IMTConGatewayModule* GatewayModuleCreate(void)=0;
   virtual IMTConParam* GatewayParamCreate(void)=0;
   virtual IMTConGatewayTranslate* GatewayTranslateCreate(void)=0;
   virtual MTAPIRES  GatewaySubscribe(IMTConGatewaySink* sink)=0;
   virtual MTAPIRES  GatewayUnsubscribe(IMTConGatewaySink* sink)=0;
   virtual MTAPIRES  GatewayAdd(IMTConGateway* gateway)=0;
   virtual MTAPIRES  GatewayDelete(LPCWSTR name)=0;
   virtual MTAPIRES  GatewayDelete(const UINT pos)=0;
   virtual MTAPIRES  GatewayShift(const UINT pos,const int shift)=0;
   virtual UINT      GatewayTotal(void)=0;
   virtual MTAPIRES  GatewayNext(const UINT pos,IMTConGateway* gateway)=0;
   virtual MTAPIRES  GatewayGet(LPCWSTR name,IMTConGateway* gateway)=0;
   virtual UINT      GatewayModuleTotal(void)=0;
   virtual MTAPIRES  GatewayModuleNext(const UINT pos,IMTConGatewayModule* module)=0;
   virtual MTAPIRES  GatewayModuleGet(LPCWSTR name,IMTConGatewayModule* module)=0;
   virtual MTAPIRES  GatewayRestart(LPCWSTR name)=0;
   virtual MTAPIRES  GatewayReserved2(void)=0;
   virtual MTAPIRES  GatewayReserved3(void)=0;
   virtual MTAPIRES  GatewayReserved4(void)=0;
   //--- report configuration
   virtual IMTConReport* ReportCreate(void)=0;
   virtual IMTConReportModule* ReportModuleCreate(void)=0;
   virtual IMTConParam* ReportParamCreate(void)=0;
   virtual MTAPIRES  ReportSubscribe(IMTConReportSink* sink)=0;
   virtual MTAPIRES  ReportUnsubscribe(IMTConReportSink* sink)=0;
   virtual MTAPIRES  ReportAdd(IMTConReport* report)=0;
   virtual MTAPIRES  ReportDelete(LPCWSTR name)=0;
   virtual MTAPIRES  ReportDelete(const UINT pos)=0;
   virtual MTAPIRES  ReportShift(const UINT pos,const int shift)=0;
   virtual UINT      ReportTotal(void)=0;
   virtual MTAPIRES  ReportNext(const UINT pos,IMTConReport* report)=0;
   virtual MTAPIRES  ReportGet(LPCWSTR name,IMTConReport* report)=0;
   virtual UINT      ReportModuleTotal(void)=0;
   virtual MTAPIRES  ReportModuleNext(const UINT pos,IMTConReportModule* module)=0;
   virtual MTAPIRES  ReportModuleGet(LPCWSTR name,IMTConReportModule* module)=0;
   virtual MTAPIRES  ReportDelete(const UINT64 server,LPCWSTR name)=0;
   virtual MTAPIRES  ReportGet(const UINT64 server,LPCWSTR name,IMTConReport* report)=0;
   virtual MTAPIRES  ReportModuleGet(const UINT64 server,LPCWSTR name,IMTConReportModule* module)=0;
   virtual MTAPIRES  ReportReserved4(void)=0;
   //--- routing configuration
   virtual IMTConRoute* RouteCreate(void)=0;
   virtual IMTConCondition* RouteConditionCreate(void)=0;
   virtual IMTConRouteDealer* RouteDealerCreate(void)=0;
   virtual MTAPIRES  RouteSubscribe(IMTConRouteSink* sink)=0;
   virtual MTAPIRES  RouteUnsubscribe(IMTConRouteSink* sink)=0;
   virtual MTAPIRES  RouteAdd(IMTConRoute* route)=0;
   virtual MTAPIRES  RouteDelete(LPCWSTR name)=0;
   virtual MTAPIRES  RouteDelete(const UINT pos)=0;
   virtual MTAPIRES  RouteShift(const UINT pos,const int shift)=0;
   virtual UINT      RouteTotal(void)=0;
   virtual MTAPIRES  RouteNext(const UINT pos,IMTConRoute* route)=0;
   virtual MTAPIRES  RouteGet(LPCWSTR name,IMTConRoute* route)=0;
   virtual MTAPIRES  RouteReserved1(void)=0;
   virtual MTAPIRES  RouteReserved2(void)=0;
   virtual MTAPIRES  RouteReserved3(void)=0;
   virtual MTAPIRES  RouteReserved4(void)=0;
   //--- clients database
   virtual IMTUser*  UserCreate(void)=0;
   virtual IMTAccount* UserCreateAccount(void)=0;
   virtual MTAPIRES  UserSubscribe(IMTUserSink* sink)=0;
   virtual MTAPIRES  UserUnsubscribe(IMTUserSink* sink)=0;
   virtual MTAPIRES  UserAdd(IMTUser* user,LPCWSTR master_pass,LPCWSTR investor_pass)=0;
   virtual MTAPIRES  UserDelete(const UINT64 login)=0;
   virtual MTAPIRES  UserUpdate(IMTUser* user)=0;
   virtual UINT      UserTotal(void)=0;
   virtual MTAPIRES  UserGet(const UINT64 login,IMTUser* user)=0;
   virtual MTAPIRES  UserGroup(const UINT64 login,MTAPISTR& group)=0;
   virtual MTAPIRES  UserLogins(LPCWSTR group,UINT64*& logins,UINT& logins_total)=0;
   virtual MTAPIRES  UserPasswordCheck(const UINT type,const UINT64 login,LPCWSTR password)=0;
   virtual MTAPIRES  UserPasswordChange(const UINT type,const UINT64 login,LPCWSTR password)=0;
   virtual MTAPIRES  UserCertDelete(const UINT64 login)=0;
   virtual MTAPIRES  UserCertConfirm(const UINT64 login)=0;
   virtual MTAPIRES  UserDepositChangeRaw(const UINT64 login,const double value,const UINT type,LPCWSTR comment,UINT64& deal_id)=0;
   virtual MTAPIRES  UserDepositChange(const UINT64 login,const double value,const UINT action,LPCWSTR comment,UINT64& deal_id)=0;
   virtual MTAPIRES  UserAccountGet(const UINT64 login,IMTAccount* account)=0;
   virtual MTAPIRES  UserArchive(const UINT64 login)=0;
   virtual MTAPIRES  UserArchiveGet(const UINT64 login,IMTUser* user)=0;
   virtual MTAPIRES  UserRestore(IMTUser* user)=0;
   virtual MTAPIRES  UserArchiveLogins(LPCWSTR group,UINT64*& logins,UINT& logins_total)=0;
   //--- deals database
   virtual IMTDeal*  DealCreate(void)=0;
   virtual IMTDealArray* DealCreateArray(void)=0;
   virtual MTAPIRES  DealSubscribe(IMTDealSink* sink)=0;
   virtual MTAPIRES  DealUnsubscribe(IMTDealSink* sink)=0;
   virtual MTAPIRES  DealDelete(const UINT64 ticket)=0;
   virtual MTAPIRES  DealUpdate(IMTDeal* deal)=0;
   virtual MTAPIRES  DealGet(const UINT64 ticket,IMTDeal* deal)=0;
   virtual MTAPIRES  DealGet(const INT64 from,const INT64 to,const UINT64 login,IMTDealArray* deals)=0;
   virtual MTAPIRES  DealAdd(IMTDeal* deal)=0;
   virtual MTAPIRES  DealPerform(IMTDeal* deal)=0;
   virtual MTAPIRES  DealPerformCloseBy(IMTDeal* deal,IMTDeal* dealby)=0;
   virtual MTAPIRES  DealDeleteBatch(const UINT64* tickets,const UINT tickets_total,MTAPIRES* results)=0;
   //--- trade positions database
   virtual IMTPosition* PositionCreate(void)=0;
   virtual IMTPositionArray* PositionCreateArray(void)=0;
   virtual MTAPIRES  PositionSubscribe(IMTPositionSink* sink)=0;
   virtual MTAPIRES  PositionUnsubscribe(IMTPositionSink* sink)=0;
   virtual MTAPIRES  PositionDelete(const UINT64 login,LPCWSTR symbol)=0;
   virtual MTAPIRES  PositionUpdate(IMTPosition* position)=0;
   virtual MTAPIRES  PositionGet(const UINT64 login,LPCWSTR symbol,IMTPosition* position)=0;
   virtual MTAPIRES  PositionGet(const UINT64 login,IMTPositionArray* position)=0;
   virtual MTAPIRES  PositionDeleteByTicket(const UINT64 ticket)=0;
   virtual MTAPIRES  PositionGetByTicket(const UINT64 ticket,IMTPosition* position)=0;
   virtual MTAPIRES  PositionCheck(const UINT64 login,IMTPositionArray* current,IMTPositionArray* invalid,IMTPositionArray* missed,IMTPositionArray* nonexist)=0;
   virtual MTAPIRES  PositionFix(const UINT64 login,IMTPositionArray* current)=0;
   //--- open orders database
   virtual IMTOrder* OrderCreate(void)=0;
   virtual IMTOrderArray* OrderCreateArray(void)=0;
   virtual MTAPIRES  OrderSubscribe(IMTOrderSink* sink)=0;
   virtual MTAPIRES  OrderUnsubscribe(IMTOrderSink* sink)=0;
   virtual MTAPIRES  OrderDelete(const UINT64 ticket)=0;
   virtual MTAPIRES  OrderUpdate(IMTOrder* order)=0;
   virtual MTAPIRES  OrderGet(const UINT64 ticket,IMTOrder* order)=0;
   virtual MTAPIRES  OrderGet(const UINT64 login,IMTOrderArray* orders)=0;
   virtual MTAPIRES  OrderAdd(IMTOrder* order)=0;
   virtual MTAPIRES  OrderDeleteBatch(const UINT64* tickets,const UINT tickets_total,MTAPIRES* results)=0;
   virtual MTAPIRES  OrderUpdateBatch(IMTOrderArray* orders,MTAPIRES* results)=0;
   virtual MTAPIRES  OrderUpdateBatchArray(IMTOrder** orders,const UINT orders_total,MTAPIRES* results)=0;
   //--- orders history database
   virtual MTAPIRES  HistorySubscribe(IMTHistorySink* sink)=0;
   virtual MTAPIRES  HistoryUnsubscribe(IMTHistorySink* sink)=0;
   virtual MTAPIRES  HistoryDelete(const UINT64 ticket)=0;
   virtual MTAPIRES  HistoryUpdate(IMTOrder* order)=0;
   virtual MTAPIRES  HistoryGet(const UINT64 ticket,IMTOrder* order)=0;
   virtual MTAPIRES  HistoryGet(const INT64 from,const INT64 to,const UINT64 login,IMTOrderArray* orders)=0;
   virtual MTAPIRES  HistoryReopen(const UINT64 ticket)=0;
   virtual MTAPIRES  HistoryAdd(IMTOrder* order)=0;
   virtual MTAPIRES  HistoryDeleteBatch(const UINT64* tickets,const UINT tickets_total,MTAPIRES* results)=0;
   virtual MTAPIRES  HistoryUpdateBatch(IMTOrderArray* orders,MTAPIRES* results)=0;
   //--- daily reports database
   virtual IMTDaily* DailyCreate(void)=0;
   virtual IMTDailyArray* DailyCreateArray(void)=0;
   virtual MTAPIRES  DailySubscribe(IMTDailySink* sink)=0;
   virtual MTAPIRES  DailyUnsubscribe(IMTDailySink* sink)=0;
   virtual MTAPIRES  DailyGet(const INT64 from,const INT64 to,const UINT64 login,IMTDailyArray* daily)=0;
   virtual MTAPIRES  DailyGetLight(const INT64 from,const INT64 to,const UINT64 login,IMTDailyArray* daily)=0;
   virtual MTAPIRES  DailySelectByGroup(LPCWSTR group,INT64 from,INT64 to,const IMTDatasetRequest *request,IMTDataset *dataset)=0;
   virtual MTAPIRES  DailySelectByLogins(const UINT64 *logins,UINT logins_total,INT64 from,INT64 to,const IMTDatasetRequest *request,IMTDataset *dataset)=0;
   virtual MTAPIRES  DailyReserved4(void)=0;
   //--- ticks data
   virtual MTAPIRES  TickSubscribe(IMTTickSink* sink)=0;
   virtual MTAPIRES  TickUnsubscribe(IMTTickSink* sink)=0;
   virtual MTAPIRES  TickAdd(MTTick& tick)=0;
   virtual MTAPIRES  TickAddStat(MTTick& tick,MTTickStat& stat)=0;
   virtual MTAPIRES  TickLast(LPCWSTR symbol,MTTickShort& tick)=0;
   virtual MTAPIRES  TickLast(const IMTConSymbol* symbol,MTTickShort& tick)=0;
   virtual MTAPIRES  TickStat(LPCWSTR symbol,MTTickStat& stat)=0;
   virtual MTAPIRES  TickGet(LPCWSTR symbol,const INT64 from,const INT64 to,MTTickShort*& ticks,UINT& ticks_total)=0;
   virtual MTAPIRES  TickGet(const IMTConSymbol* symbol,const INT64 from,const INT64 to,MTTickShort*& ticks,UINT& ticks_total)=0;
   virtual MTAPIRES  TickHistoryGetRaw(LPCWSTR symbol,const INT64 from,const INT64 to,MTTickShort*& ticks,UINT& ticks_total)=0;
   virtual MTAPIRES  TickHistoryGet(LPCWSTR symbol,const INT64 from,const INT64 to,MTTickShort*& ticks,UINT& ticks_total)=0;
   virtual MTAPIRES  TickReserved2(void)=0;
   virtual MTAPIRES  TickReserved3(void)=0;
   virtual MTAPIRES  TickReserved4(void)=0;
   //--- internal mail
   virtual IMTMail*  MailCreate(void)=0;
   virtual MTAPIRES  MailSubscribe(IMTMailSink* sink)=0;
   virtual MTAPIRES  MailUnsubscribe(IMTMailSink* sink)=0;
   virtual MTAPIRES  MailSend(IMTMail* mail)=0;
   virtual MTAPIRES  MailReserved1(void)=0;
   virtual MTAPIRES  MailReserved2(void)=0;
   virtual MTAPIRES  MailReserved3(void)=0;
   virtual MTAPIRES  MailReserved4(void)=0;
   //--- internal news
   virtual IMTNews*  NewsCreate(void)=0;
   virtual MTAPIRES  NewsSubscribe(IMTNewsSink* sink)=0;
   virtual MTAPIRES  NewsUnsubscribe(IMTNewsSink* sink)=0;
   virtual MTAPIRES  NewsSend(IMTNews* news)=0;
   virtual MTAPIRES  NewsReserved1(void)=0;
   virtual MTAPIRES  NewsReserved2(void)=0;
   virtual MTAPIRES  NewsReserved3(void)=0;
   virtual MTAPIRES  NewsReserved4(void)=0;
   //--- custom commands processing
   virtual MTAPIRES  CustomSubscribe(IMTCustomSink* sink)=0;
   virtual MTAPIRES  CustomUnsubscribe(IMTCustomSink* sink)=0;
   virtual IMTByteStream* CustomCreateStream(void)=0;
   virtual MTAPIRES  CustomReserved2(void)=0;
   virtual MTAPIRES  CustomReserved3(void)=0;
   virtual MTAPIRES  CustomReserved4(void)=0;
   //--- trade methods
   virtual IMTRequest* TradeRequestCreate(void)=0;
   virtual MTAPIRES  TradeSubscribe(IMTTradeSink* sink)=0;
   virtual MTAPIRES  TradeUnsubscribe(IMTTradeSink* sink)=0;
   virtual MTAPIRES  TradeRequest(IMTRequest* request)=0;
   virtual MTAPIRES  TradeProfit(LPCWSTR group,LPCWSTR symbol,const UINT type,const UINT64 volume,const double price_open,const double price_close,double& profit,double& profit_rate)=0;
   virtual MTAPIRES  TradeRateBuy(LPCWSTR base,LPCWSTR currency,double& rate,LPCWSTR group=NULL,LPCWSTR symbol=NULL,const double price=0)=0;
   virtual MTAPIRES  TradeRateSell(LPCWSTR base,LPCWSTR currency,double& rate,LPCWSTR group=NULL,LPCWSTR symbol=NULL,const double price=0)=0;
   virtual MTAPIRES  TradeMarginCheck(const UINT64 login,LPCWSTR symbol,const UINT type,const UINT64 volume,const double price,IMTAccount* account_new=NULL,IMTAccount* account_current=NULL)=0;
   virtual MTAPIRES  TradeMarginCheck(const IMTOrder* order,IMTAccount* account_new=NULL,IMTAccount* account_current=NULL)=0;
   virtual MTAPIRES  TradeBalanceCheckObsolete(const UINT64 login,const UINT fixflag,double& balance_user,double& balance_history)=0;
   virtual MTAPIRES  TradeSubscribeEOD(IMTEndOfDaySink* sink)=0;
   virtual MTAPIRES  TradeUnsubscribeEOD(IMTEndOfDaySink* sink)=0;
   virtual MTAPIRES  TradeBalanceCheck(const UINT64 login,const UINT fixflag,double& balance_user,double& balance_history,double& credit_user,double& credit_history)=0;
   virtual MTAPIRES  TradeAccountSet(const IMTUser *user,const IMTAccount *account,const IMTOrderArray *orders,const IMTPositionArray *positions)=0;
   virtual IMTConfirm* TradeConfirmCreate(void)=0;
   virtual IMTExecution* TradeExecutionCreate(void)=0;
   virtual IMTRequestArray* TradeRequestCreateArray(void)=0;
   virtual MTAPIRES  TradeProfitExt(LPCWSTR group,LPCWSTR symbol,const UINT type,const UINT64 volume,const double price_open,const double price_close,double& profit,double& profit_rate)=0;
   //--- books access
   virtual MTAPIRES  BookSubscribe(IMTBookSink* sink)=0;
   virtual MTAPIRES  BookUnsubscribe(IMTBookSink* sink)=0;
   virtual MTAPIRES  BookGet(LPCWSTR symbol,MTBook& book)=0;
   virtual MTAPIRES  BookReserved1(void)=0;
   virtual MTAPIRES  BookReserved2(void)=0;
   virtual MTAPIRES  BookReserved3(void)=0;
   virtual MTAPIRES  BookReserved4(void)=0;
   //--- chart methods
   virtual MTAPIRES  ChartGet(LPCWSTR symbol,const INT64 from,const INT64 to,MTChartBar*& bars,UINT& bars_total)=0;
   virtual MTAPIRES  ChartDelete(LPCWSTR symbol,const INT64* bars_dates,const UINT bars_dates_total)=0;
   virtual MTAPIRES  ChartUpdate(LPCWSTR symbol,const MTChartBar* bars,const UINT bars_total)=0;
   virtual MTAPIRES  ChartSplit(LPCWSTR symbol,const UINT new_shares,const UINT old_shares,const UINT rounding_rule,const INT64 datetime_from,const INT64 datetime_to)=0;
   virtual MTAPIRES  ChartReserved2(void)=0;
   virtual MTAPIRES  ChartReserved3(void)=0;
   virtual MTAPIRES  ChartReserved4(void)=0;
   //--- clients database
   virtual IMTCertificate *UserCertCreate(void)=0;
   virtual MTAPIRES  UserCertUpdate(const UINT64 login,const IMTCertificate *certificate)=0;
   virtual MTAPIRES  UserCertGet(const UINT64 login,IMTCertificate *certificate)=0;
   virtual MTAPIRES  UserCertReserved1(void)=0;
   virtual MTAPIRES  UserCertReserved2(void)=0;
   virtual MTAPIRES  UserCertReserved3(void)=0;
   virtual MTAPIRES  UserCertReserved4(void)=0;
   //--- spreads configuration
   virtual IMTConSpread* SpreadCreate(void)=0;
   virtual IMTConSpreadLeg* SpreadLegCreate(void)=0;
   virtual MTAPIRES  SpreadSubscribe(IMTConSpreadSink* sink)=0;
   virtual MTAPIRES  SpreadUnsubscribe(IMTConSpreadSink* sink)=0;
   virtual MTAPIRES  SpreadAdd(IMTConSpread* spread)=0;
   virtual MTAPIRES  SpreadDelete(const UINT pos)=0;
   virtual MTAPIRES  SpreadShift(const UINT pos,const int shift)=0;
   virtual UINT      SpreadTotal(void)=0;
   virtual MTAPIRES  SpreadNext(const UINT pos,IMTConSpread* spread)=0;
   virtual MTAPIRES  SpreadGet(const UINT id,IMTConSpread* spread)=0;
   virtual MTAPIRES  SpreadReserved1(void)=0;
   virtual MTAPIRES  SpreadReserved2(void)=0;
   virtual MTAPIRES  SpreadReserved3(void)=0;
   virtual MTAPIRES  SpreadReserved4(void)=0;
   //--- online connection data
   virtual IMTOnline* OnlineCreate(void)=0;
   virtual IMTOnlineArray* OnlineCreateArray(void)=0;
   virtual UINT      OnlineTotal(void)=0;
   virtual MTAPIRES  OnlineNext(const UINT pos,IMTOnline* online)=0;
   virtual MTAPIRES  OnlineGet(const UINT64 login,IMTOnlineArray* online)=0;
   virtual MTAPIRES  OnlineDisconnect(IMTOnline* online)=0;
   virtual MTAPIRES  OnlineDisconnectBatch(IMTOnlineArray* online,MTAPIRES* results)=0;
   virtual MTAPIRES  OnlineDisconnectBatchArray(IMTOnline** online,const UINT online_total,MTAPIRES* results)=0;
   virtual MTAPIRES  OnlineReserved4(void)=0;
   //--- notifications
   virtual MTAPIRES  NotificationsSend(LPCWSTR metaquotes_ids,LPCWSTR message)=0;
   virtual MTAPIRES  NotificationsSend(const UINT64* logins,const UINT logins_total,LPCWSTR message)=0;
   virtual MTAPIRES  NotificationsReserved1(void)=0;
   virtual MTAPIRES  NotificationsReserved2(void)=0;
   virtual MTAPIRES  NotificationsReserved3(void)=0;
   virtual MTAPIRES  NotificationsReserved4(void)=0;
   //--- deals
   virtual MTAPIRES  DealUpdateBatch(IMTDealArray* deals,MTAPIRES* results)=0;
   virtual MTAPIRES  DealUpdateBatchArray(IMTDeal** deals,const UINT deals_total,MTAPIRES* results)=0;
   virtual MTAPIRES  DealAddBatch(IMTDealArray* deals,MTAPIRES* results)=0;
   virtual MTAPIRES  DealAddBatchArray(IMTDeal** deals,const UINT deals_total,MTAPIRES* results)=0;
   virtual MTAPIRES  DealPerformBatch(IMTDealArray* deals,MTAPIRES* results)=0;
   virtual MTAPIRES  DealPerformBatchArray(IMTDeal** deals,const UINT deals_total,MTAPIRES* results)=0;
   virtual MTAPIRES  DealSelectByGroup(LPCWSTR group,INT64 from,INT64 to,const IMTDatasetRequest *request,IMTDataset *dataset)=0;
   virtual MTAPIRES  DealSelectByLogins(const UINT64 *logins,UINT logins_total,INT64 from,INT64 to,const IMTDatasetRequest *request,IMTDataset *dataset)=0;
   virtual MTAPIRES  DealGetByGroup(LPCWSTR group,INT64 from,INT64 to,IMTDealArray *deals)=0;
   virtual MTAPIRES  DealGetByLogins(const UINT64 *logins,UINT logins_total,INT64 from,INT64 to,IMTDealArray *deals)=0;
   //--- orders
   virtual MTAPIRES  OrderAddBatch(IMTOrderArray* orders,MTAPIRES* results)=0;
   virtual MTAPIRES  OrderAddBatchArray(IMTOrder** orders,const UINT orders_total,MTAPIRES* results)=0;
   virtual MTAPIRES  OrderSelectByGroup(LPCWSTR group,const IMTDatasetRequest *request,IMTDataset *dataset)=0;
   virtual MTAPIRES  OrderSelectByLogins(const UINT64 *logins,UINT logins_total,const IMTDatasetRequest *request,IMTDataset *dataset)=0;
   virtual MTAPIRES  OrderGetByGroup(LPCWSTR group,IMTOrderArray *orders)=0;
   virtual MTAPIRES  OrderGetByLogins(const UINT64 *logins,UINT logins_total,IMTOrderArray *orders)=0;
   //--- history
   virtual MTAPIRES  HistoryUpdateBatchArray(IMTOrder** orders,const UINT orders_total,MTAPIRES* results)=0;
   virtual MTAPIRES  HistoryAddBatch(IMTOrderArray* orders,MTAPIRES* results)=0;
   virtual MTAPIRES  HistoryAddBatchArray(IMTOrder** orders,const UINT orders_total,MTAPIRES* results)=0;
   virtual MTAPIRES  HistorySelectByGroup(LPCWSTR group,INT64 from,INT64 to,const IMTDatasetRequest *request,IMTDataset *dataset)=0;
   virtual MTAPIRES  HistorySelectByLogins(const UINT64 *logins,UINT logins_total,INT64 from,INT64 to,const IMTDatasetRequest *request,IMTDataset *dataset)=0;
   virtual MTAPIRES  HistoryGetByGroup(LPCWSTR group,INT64 from,INT64 to,IMTOrderArray *orders)=0;
   virtual MTAPIRES  HistoryGetByLogins(const UINT64 *logins,UINT logins_total,INT64 from,INT64 to,IMTOrderArray *orders)=0;
   //--- dealing
   virtual MTAPIRES  DealerStart(const UINT64 dealer,IMTRequestSink* sink)=0;
   virtual MTAPIRES  DealerStop(const UINT64 dealer,IMTRequestSink* sink)=0;
   virtual MTAPIRES  DealerGet(const UINT64 dealer,IMTRequest* request)=0;
   virtual MTAPIRES  DealerLock(const UINT64 dealer,const UINT id,IMTRequest* request)=0;
   virtual MTAPIRES  DealerAnswer(const UINT64 dealer,IMTConfirm* confirm)=0;
   virtual UINT      DealerRequestTotal(const UINT64 dealer)=0;
   virtual MTAPIRES  DealerRequestNext(const UINT64 dealer,const UINT pos,IMTRequest* request)=0;
   virtual MTAPIRES  DealerRequestGet(const UINT64 dealer,const UINT id,IMTRequest* request)=0;
   virtual MTAPIRES  DealerRequestGetAll(const UINT64 dealer,IMTRequestArray* requests)=0;
   virtual MTAPIRES  DealerExecution(LPCWSTR gateway_name,LPCWSTR gateway_type,IMTExecution *execution)=0;
   virtual MTAPIRES  DealerReserved2(void)=0;
   virtual MTAPIRES  DealerReserved3(void)=0;
   virtual MTAPIRES  DealerReserved4(void)=0;
   //--- trade methods
   virtual MTAPIRES  TradeMarginCheckExt(const UINT64 login,LPCWSTR symbol,const UINT type,const UINT64 volume,const double price,IMTAccount* account_new=NULL,IMTAccount* account_current=NULL)=0;
   virtual MTAPIRES  TradeReserved1(void)=0;
   virtual MTAPIRES  TradeReserved2(void)=0;
   virtual MTAPIRES  TradeReserved3(void)=0;
   virtual MTAPIRES  TradeReserved4(void)=0;
   virtual MTAPIRES  TradeReserved5(void)=0;
   virtual MTAPIRES  TradeReserved6(void)=0;
   //--- email servers configuration
   virtual IMTConEmail* EmailCreate()=0;
   virtual MTAPIRES  EmailSubscribe(IMTConEmailSink* sink)=0;
   virtual MTAPIRES  EmailUnsubscribe(IMTConEmailSink* sink)=0;
   virtual MTAPIRES  EmailAdd(IMTConEmail* config)=0;
   virtual MTAPIRES  EmailDelete(LPCWSTR name)=0;
   virtual MTAPIRES  EmailDelete(const UINT pos)=0;
   virtual MTAPIRES  EmailShift(const UINT pos,const int shift)=0;
   virtual UINT      EmailTotal(void)=0;
   virtual MTAPIRES  EmailNext(const UINT pos,IMTConEmail* email)=0;
   virtual MTAPIRES  EmailGet(LPCWSTR name,IMTConEmail* email)=0;
   virtual MTAPIRES  EmailSend(LPCWSTR account,LPCWSTR to,LPCWSTR to_name,LPCWSTR subject,LPCWSTR body)=0;
   virtual MTAPIRES  EmailReserved2(void)=0;
   virtual MTAPIRES  EmailReserved3(void)=0;
   virtual MTAPIRES  EmailReserved4(void)=0;
   //--- messengers configuration
   virtual IMTConMessenger* MessengerCreate()=0;
   virtual MTAPIRES  MessengerSubscribe(IMTConMessengerSink* sink)=0;
   virtual MTAPIRES  MessengerUnsubscribe(IMTConMessengerSink* sink)=0;
   virtual MTAPIRES  MessengerAdd(IMTConMessenger* config)=0;
   virtual MTAPIRES  MessengerDelete(LPCWSTR name)=0;
   virtual MTAPIRES  MessengerDelete(const UINT pos)=0;
   virtual MTAPIRES  MessengerShift(const UINT pos,const int shift)=0;
   virtual UINT      MessengerTotal(void)=0;
   virtual MTAPIRES  MessengerNext(const UINT pos,IMTConMessenger* messenger)=0;
   virtual MTAPIRES  MessengerGet(LPCWSTR name,IMTConMessenger* messenger)=0;
   virtual MTAPIRES  MessengerSend(LPCWSTR destination,LPCWSTR group,LPCWSTR sender,LPCWSTR text)=0;
   virtual MTAPIRES  MessengerVerifyPhone(LPCWSTR phone_number)=0;
   virtual IMTConMessengerCountry* MessengerCountryCreate()=0;
   virtual IMTConMessengerGroup* MessengerGroupCreate()=0;
   //--- trade positions database
   virtual MTAPIRES  PositionSelectByGroup(LPCWSTR group,INT64 from,INT64 to,const IMTDatasetRequest *request,IMTDataset *dataset)=0;
   virtual MTAPIRES  PositionSelectByLogins(const UINT64 *logins,UINT logins_total,INT64 from,INT64 to,const IMTDatasetRequest *request,IMTDataset *dataset)=0;
   virtual MTAPIRES  PositionGetByGroup(LPCWSTR group,IMTPositionArray *positions)=0;
   virtual MTAPIRES  PositionGetByLogins(const UINT64 *logins,UINT logins_total,IMTPositionArray *positions)=0;
   virtual MTAPIRES  PositionGetByTickets(const UINT64 *tickets,UINT tickets_total,IMTPositionArray *positions)=0;
   virtual MTAPIRES  PositionSplit(const UINT64* tickets,const UINT tickets_total,const double *adjustments,const UINT new_shares,const UINT old_shares,const UINT round_rule_price,const UINT round_rule_volume,const UINT flags,MTAPIRES* results)=0;
   virtual MTAPIRES  PositionReserved2(void)=0;
   virtual MTAPIRES  PositionReserved3(void)=0;
   virtual MTAPIRES  PositionReserved4(void)=0;
   //--- dataset management
   virtual IMTDatasetRequest* DatasetRequestCreate(void)=0;
   virtual IMTDataset* DatasetCreate(void)=0;
   virtual MTAPIRES  DatasetReserved1(void)=0;
   virtual MTAPIRES  DatasetReserved2(void)=0;
   virtual MTAPIRES  DatasetReserved3(void)=0;
   virtual MTAPIRES  DatasetReserved4(void)=0;
   //--- orders
   virtual MTAPIRES  OrderGetByTickets(const UINT64 *tickets,UINT tickets_total,IMTOrderArray *orders)=0;
   virtual MTAPIRES  OrderReserved1(void)=0;
   virtual MTAPIRES  OrderReserved2(void)=0;
   virtual MTAPIRES  OrderReserved3(void)=0;
   virtual MTAPIRES  OrderReserved4(void)=0;
   //--- history
   virtual MTAPIRES  HistoryGetByTickets(const UINT64 *tickets,UINT tickets_total,IMTOrderArray *orders)=0;
   virtual MTAPIRES  HistoryReserved1(void)=0;
   virtual MTAPIRES  HistoryReserved2(void)=0;
   virtual MTAPIRES  HistoryReserved3(void)=0;
   virtual MTAPIRES  HistoryReserved4(void)=0;
   //--- dealing
   virtual MTAPIRES  DealGetByTickets(const UINT64 *tickets,UINT tickets_total,IMTDealArray *deals)=0;
   virtual MTAPIRES  DealReserved1(void)=0;
   virtual MTAPIRES  DealReserved2(void)=0;
   virtual MTAPIRES  DealReserved3(void)=0;
   virtual MTAPIRES  DealReserved4(void)=0;
   //--- client management
   virtual IMTClient *ClientCreate(void)=0;
   virtual IMTClientArray *ClientCreateArray(void)=0;
   virtual MTAPIRES  ClientSubscribe(IMTClientSink* sink)=0;
   virtual MTAPIRES  ClientUnsubscribe(IMTClientSink* sink)=0;
   virtual MTAPIRES  ClientAdd(IMTClient *client,const UINT64 author)=0;
   virtual MTAPIRES  ClientUpdate(IMTClient *client,const UINT64 author)=0;
   virtual MTAPIRES  ClientDelete(const UINT64 client_id,const UINT64 author)=0;
   virtual MTAPIRES  ClientGet(const UINT64 client_id,IMTClient *client)=0;
   virtual MTAPIRES  ClientGetHistory(const UINT64 client_id,const UINT64 author,const INT64 from,const INT64 to,IMTClientArray *history)=0;
   virtual MTAPIRES  ClientIdsAll(UINT64*& ids,UINT& ids_total)=0;
   virtual MTAPIRES  ClientIdsByGroup(const LPCWSTR groups,UINT64*& ids,UINT& ids_total)=0;
   virtual MTAPIRES  ClientIdsByManager(const UINT64 manager,UINT64*& ids,UINT& ids_total)=0;
   virtual MTAPIRES  ClientUserAdd(const UINT64 client_id,const UINT64 login)=0;
   virtual MTAPIRES  ClientUserDelete(const UINT64 client_id,const UINT64 login)=0;
   virtual MTAPIRES  ClientUserLogins(const UINT64 client_id,UINT64*& logins,UINT& logins_total)=0;
   virtual MTAPIRES  ClientReserved1(void)=0;
   virtual MTAPIRES  ClientReserved2(void)=0;
   virtual MTAPIRES  ClientReserved3(void)=0;
   virtual MTAPIRES  ClientReserved4(void)=0;
   //--- document management
   virtual IMTDocument *DocumentCreate(void)=0;
   virtual IMTDocumentArray *DocumentCreateArray(void)=0;
   virtual MTAPIRES  DocumentSubscribe(IMTDocumentSink* sink)=0;
   virtual MTAPIRES  DocumentUnsubscribe(IMTDocumentSink* sink)=0;
   virtual MTAPIRES  DocumentAdd(IMTDocument *document,const UINT64 author)=0;
   virtual MTAPIRES  DocumentUpdate(IMTDocument *document,const UINT64 author)=0;
   virtual MTAPIRES  DocumentDelete(const UINT64 document_id,const UINT64 author)=0;
   virtual MTAPIRES  DocumentGet(const UINT64 document_id,IMTDocument *document)=0;
   virtual MTAPIRES  DocumentGetByClient(const UINT64 client_id,const UINT position,const UINT total,IMTDocumentArray *documents)=0;
   virtual MTAPIRES  DocumentGetHistory(const UINT64 document_id,const UINT64 author,const INT64 from,const INT64 to,IMTDocumentArray *history)=0;
   virtual MTAPIRES  DocumentReserved1(void)=0;
   virtual MTAPIRES  DocumentReserved2(void)=0;
   virtual MTAPIRES  DocumentReserved3(void)=0;
   virtual MTAPIRES  DocumentReserved4(void)=0;
   //--- comment management
   virtual IMTComment *CommentCreate(void)=0;
   virtual IMTCommentArray *CommentCreateArray(void)=0;
   virtual MTAPIRES  CommentSubscribe(IMTCommentSink* sink)=0;
   virtual MTAPIRES  CommentUnsubscribe(IMTCommentSink* sink)=0;
   virtual MTAPIRES  CommentAdd(IMTComment *comment,const UINT64 author)=0;
   virtual MTAPIRES  CommentUpdate(IMTComment *comment,const UINT64 author)=0;
   virtual MTAPIRES  CommentDelete(const UINT64 comment_id,const UINT64 author)=0;
   virtual MTAPIRES  CommentGet(const UINT64 comment_id,IMTComment *comment)=0;
   virtual MTAPIRES  CommentGetByClient(const UINT64 client_id,const UINT position,const UINT total,IMTCommentArray *comments)=0;
   virtual MTAPIRES  CommentGetByDocument(const UINT64 document_id,const UINT position,const UINT total,IMTCommentArray *comments)=0;
   virtual MTAPIRES  CommentReserved1(void)=0;
   virtual MTAPIRES  CommentReserved2(void)=0;
   virtual MTAPIRES  CommentReserved3(void)=0;
   virtual MTAPIRES  CommentReserved4(void)=0;
   //--- attachment management
   virtual IMTAttachment* AttachmentCreate(void)=0;
   virtual MTAPIRES  AttachmentAdd(IMTAttachment *attachment,const UINT64 author)=0;
   virtual MTAPIRES  AttachmentGet(const UINT64 attachment_id,IMTAttachment *attachment)=0;
   virtual MTAPIRES  AttachmentReserved1(void)=0;
   virtual MTAPIRES  AttachmentReserved2(void)=0;
   virtual MTAPIRES  AttachmentReserved3(void)=0;
   virtual MTAPIRES  AttachmentReserved4(void)=0;
   //--- TLS Certificates
   virtual MTAPIRES  TLSCertificateUpdate(const void* pfx_certificate,const UINT pfx_certificate_size,LPCWSTR password)=0;
   virtual MTAPIRES  TLSCertificateDelete(const UINT pos)=0;
   virtual MTAPIRES  TLSCertificateShift(const UINT pos,const int shift)=0;
   virtual UINT      TLSCertificateTotal(void)=0;
   virtual MTAPIRES  TLSCertificateNext(const UINT pos,MTAPISTR& name,MTAPISTR& thumbprint)=0;
   virtual void*     TLSCertificatePfx(const UINT pos,UINT& pfx_certificate_size)=0;
   virtual MTAPIRES  TLSCertificateReserved1(void)=0;
   virtual MTAPIRES  TLSCertificateReserved2(void)=0;
   virtual MTAPIRES  TLSCertificateReserved3(void)=0;
   virtual MTAPIRES  TLSCertificateReserved4(void)=0;
   //--- automation configuration
   virtual IMTConAutomation* AutomationCreate()=0;
   virtual IMTConAutoCondition* AutomationConditionCreate()=0;
   virtual IMTConAutoAction* AutomationActionCreate()=0;
   virtual IMTConAutoParam* AutomationParamCreate()=0;
   virtual MTAPIRES  AutomationSubscribe(IMTConAutomationSink* sink)=0;
   virtual MTAPIRES  AutomationUnsubscribe(IMTConAutomationSink* sink)=0;
   virtual MTAPIRES  AutomationAdd(IMTConAutomation* config)=0;
   virtual MTAPIRES  AutomationDelete(LPCWSTR name)=0;
   virtual MTAPIRES  AutomationDelete(const UINT pos)=0;
   virtual MTAPIRES  AutomationShift(const UINT pos,const int shift)=0;
   virtual UINT      AutomationTotal(void)=0;
   virtual MTAPIRES  AutomationNext(const UINT pos,IMTConAutomation* config)=0;
   virtual MTAPIRES  AutomationGet(LPCWSTR name,IMTConAutomation* config)=0;
   virtual MTAPIRES  AutomationTrigger(LPCWSTR name,const IMTUser* user,const IMTAccount* account,const IMTDeal* deal,const IMTOrder* order,const IMTPosition* position)=0;
   virtual MTAPIRES  AutomationReserved2(void)=0;
   virtual MTAPIRES  AutomationReserved3(void)=0;
   virtual MTAPIRES  AutomationReserved4(void)=0;
   //--- subscription configuration
   virtual IMTConSubscription* SubscriptionCfgCreate()=0;
   virtual IMTConSubscriptionSymbol* SubscriptionCfgSymbolCreate()=0;
   virtual IMTConSubscriptionNews* SubscriptionCfgNewsCreate()=0;
   virtual MTAPIRES  SubscriptionCfgSubscribe(IMTConSubscriptionSink* sink)=0;
   virtual MTAPIRES  SubscriptionCfgUnsubscribe(IMTConSubscriptionSink* sink)=0;
   virtual MTAPIRES  SubscriptionCfgAdd(IMTConSubscription* config)=0;
   virtual MTAPIRES  SubscriptionCfgDelete(LPCWSTR name)=0;
   virtual MTAPIRES  SubscriptionCfgDelete(const UINT pos)=0;
   virtual MTAPIRES  SubscriptionCfgDeleteByID(const UINT64 id)=0;
   virtual MTAPIRES  SubscriptionCfgShift(const UINT pos,const int shift)=0;
   virtual UINT      SubscriptionCfgTotal(void)=0;
   virtual MTAPIRES  SubscriptionCfgNext(const UINT pos,IMTConSubscription* config)=0;
   virtual MTAPIRES  SubscriptionCfgGet(LPCWSTR name,IMTConSubscription* config)=0;
   virtual MTAPIRES  SubscriptionCfgGetByID(const UINT64 id,IMTConSubscription* config)=0;
   virtual MTAPIRES  SubscriptionCfgReserved1(void)=0;
   virtual MTAPIRES  SubscriptionCfgReserved2(void)=0;
   virtual MTAPIRES  SubscriptionCfgReserved3(void)=0;
   virtual MTAPIRES  SubscriptionCfgReserved4(void)=0;
   //--- subscription records
   virtual IMTSubscription* SubscriptionCreate()=0;
   virtual IMTSubscriptionArray* SubscriptionCreateArray(void)=0;
   virtual MTAPIRES  SubscriptionSubscribe(IMTSubscriptionSink* sink)=0;
   virtual MTAPIRES  SubscriptionUnsubscribe(IMTSubscriptionSink* sink)=0;
   virtual MTAPIRES  SubscriptionJoin(const UINT64 manager,const UINT64 login,const UINT64 subscription,IMTSubscription* record,IMTSubscriptionHistory* history)=0;
   virtual MTAPIRES  SubscriptionCancel(const UINT64 manager,const UINT64 login,const UINT64 subscription,IMTSubscription* record,IMTSubscriptionHistory* history)=0;
   virtual bool      SubscriptionExist(const UINT64 login,const UINT64 subscription)=0;
   virtual MTAPIRES  SubscriptionAdd(IMTSubscription* record)=0;
   virtual MTAPIRES  SubscriptionUpdate(IMTSubscription* record)=0;
   virtual MTAPIRES  SubscriptionDelete(const UINT64 id)=0;
   virtual MTAPIRES  SubscriptionGet(const UINT64 login,IMTSubscriptionArray* records)=0;
   virtual MTAPIRES  SubscriptionGetBySubscription(const UINT64 login,const UINT64 subscription,IMTSubscription* record)=0;
   virtual MTAPIRES  SubscriptionGetByID(const UINT64 id,IMTSubscription* record)=0;
   virtual MTAPIRES  SubscriptionGetByLogins(const UINT64 *logins,UINT logins_total,IMTSubscriptionArray* records)=0;
   virtual MTAPIRES  SubscriptionReserved1(void)=0;
   virtual MTAPIRES  SubscriptionReserved2(void)=0;
   virtual MTAPIRES  SubscriptionReserved3(void)=0;
   virtual MTAPIRES  SubscriptionReserved4(void)=0;
   //--- subscription history records
   virtual IMTSubscriptionHistory* SubscriptionHistoryCreate()=0;
   virtual IMTSubscriptionHistoryArray* SubscriptionHistoryCreateArray(void)=0;
   virtual MTAPIRES  SubscriptionHistorySubscribe(IMTSubscriptionHistorySink* sink)=0;
   virtual MTAPIRES  SubscriptionHistoryUnsubscribe(IMTSubscriptionHistorySink* sink)=0;
   virtual MTAPIRES  SubscriptionHistoryAdd(IMTSubscriptionHistory* record)=0;
   virtual MTAPIRES  SubscriptionHistoryUpdate(IMTSubscriptionHistory* record)=0;
   virtual MTAPIRES  SubscriptionHistoryDelete(const UINT64 id)=0;
   virtual MTAPIRES  SubscriptionHistoryGet(const INT64 from,const INT64 to,const UINT64 login,IMTSubscriptionHistoryArray* records)=0;
   virtual MTAPIRES  SubscriptionHistoryGetByID(const UINT64 id,IMTSubscriptionHistory* record)=0;
   virtual MTAPIRES  SubscriptionHistoryGetByLogins(const INT64 from,const INT64 to,const UINT64 *logins,UINT logins_total,IMTSubscriptionHistoryArray* records)=0;
   virtual MTAPIRES  SubscriptionHistoryReserved1(void)=0;
   virtual MTAPIRES  SubscriptionHistoryReserved2(void)=0;
   virtual MTAPIRES  SubscriptionHistoryReserved3(void)=0;
   virtual MTAPIRES  SubscriptionHistoryReserved4(void)=0;
   //--- геобазы
   virtual MTAPIRES  GeoResolveAny(LPCWSTR ip_list,LPWSTR result,const UINT result_len,const UINT flags)=0;
   virtual MTAPIRES  GeoResolveIPv4(const ULONG ip,LPWSTR result,const UINT result_len,const UINT flags) =0;
   virtual MTAPIRES  GeoResolveIPv4Bulk(const ULONG *ip_list,const UINT ip_list_len,LPWSTR result,const UINT result_len,const UINT flags)=0;
   virtual MTAPIRES  GeoResolveIPv6(const IN6_ADDR &ip,LPWSTR result,const UINT result_len,const UINT flags)=0;
   virtual MTAPIRES  GeoResolveIPv6Bulk(const IN6_ADDR *ip_list,const UINT ip_list_len,LPWSTR result,const UINT result_len,const UINT flags)=0;
   virtual MTAPIRES  GeoResolveReserved1(void)=0;
   virtual MTAPIRES  GeoResolveReserved2(void)=0;
   virtual MTAPIRES  GeoResolveReserved3(void)=0;
   virtual MTAPIRES  GeoResolveReserved4(void)=0;
  };
//+------------------------------------------------------------------+
//| Server plugin interface                                          |
//+------------------------------------------------------------------+
class IMTServerPlugin
  {
public:
   virtual void      Release(void)=0;
   //--- plugin start & stop notification
   virtual MTAPIRES  Start(IMTServerAPI* server)=0;
   virtual MTAPIRES  Stop(void)=0;
  };
//+------------------------------------------------------------------+
//| Plugin DLL entry points                                          |
//+------------------------------------------------------------------+
MTAPIENTRY MTAPIRES  MTServerAbout(MTPluginInfo& info);
MTAPIENTRY MTAPIRES  MTServerCreate(UINT apiversion,IMTServerPlugin** plugin);
//+------------------------------------------------------------------+

