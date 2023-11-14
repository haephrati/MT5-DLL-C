//+------------------------------------------------------------------+
//|                                         MetaTrader 5 API Gateway |
//|                             Copyright 2000-2021, MetaQuotes Ltd. |
//|                                               www.metaquotes.net |
//+------------------------------------------------------------------+
#pragma once
#include <wincrypt.h>
#include "MT5APIConstants.h"
#include "MT5APITools.h"
#include "MT5APILogger.h"
#include "MT5APIPublicKey.h"
#include "Config\MT5APIConfigFeeder.h"
#include "Config\MT5APIConfigGateway.h"
#include "Config\MT5APIConfigSymbol.h"
#include "Config\MT5APIConfigGroup.h"
#include "Config\MT5APIConfigNetwork.h"
#include "Config\MT5APIConfigTime.h"
#include "Config\MT5APIConfigSpread.h"
#include "Bases\MT5APIAccount.h"
#include "Bases\MT5APIBook.h"
#include "Bases\MT5APIConfirm.h"
#include "Bases\MT5APIExecution.h"
#include "Bases\MT5APIMail.h"
#include "Bases\MT5APIOrder.h"
#include "Bases\MT5APIPosition.h"
#include "Bases\MT5APIRequest.h"
#include "Bases\MT5APITick.h"
#include "Bases\MT5APIUser.h"
#include "Bases\MT5APIChart.h"
//+------------------------------------------------------------------+
//| Include necessary library                                        |
//+------------------------------------------------------------------+
#pragma comment(lib,"advapi32.lib")
//+------------------------------------------------------------------+
//| Gateway API version                                              |
//+------------------------------------------------------------------+
#define MTGatewayAPIVersion  2940
#define MTGatewayAPIDate     L"21 May 2021"
//+------------------------------------------------------------------+
//| Gateway description info                                         |
//+------------------------------------------------------------------+
#pragma pack(push,1)
struct MTGatewayInfo
  {
   //--- gateway modes flags
   enum EnModes
     {
      GATEWAY_MODE_QUOTES     =1,                           // receive quotes
      GATEWAY_MODE_NEWS       =2,                           // receive news
      GATEWAY_MODE_POSITIONS  =4,                           // gateway can process requests of trade positions
      //--- enumeration borders
      GATEWAY_MODE_NONE       =0,
      GATEWAY_MODE_ALL        =GATEWAY_MODE_QUOTES|GATEWAY_MODE_NEWS|GATEWAY_MODE_POSITIONS
     };
   //--- necessary fields flags
   enum EnFields
     {
      GATEWAY_FIELD_SERVER    =1,                           // server field
      GATEWAY_FIELD_LOGIN     =2,                           // login field
      GATEWAY_FIELD_PASSWORD  =4,                           // password field
      GATEWAY_FIELD_PARAMS    =8,                           // parameters
      //--- enumeration borders
      GATEWAY_FIELD_NONE      =0,
      GATEWAY_FIELD_ALL       =GATEWAY_FIELD_SERVER|GATEWAY_FIELD_LOGIN|GATEWAY_FIELD_PASSWORD|GATEWAY_FIELD_PARAMS
     };
   //--- data
   UINT              version;                               // gateway version
   UINT              version_api;                           // gateway API version
   wchar_t           name_default[128];                     // gateway default name
   wchar_t           copyright[128];                        // copyright
   wchar_t           server_default[128];                   // default dataserver address:port
   wchar_t           login_default[64];                     // gateway default login
   wchar_t           password_default[64];                  // gateway default password
   wchar_t           parameters_default[512];               // additional parameters
   UINT              mode;                                  // EnModes
   UINT              fields;                                // EnFields
   wchar_t           description[512];                      // description
   wchar_t           module_id[16];                         // gateway module id
   wchar_t           build_date[16];                        // datafeed\gateway build date
   wchar_t           build_api_date[16];                    // Gateway API build date
   UINT              reserved[32];                          // reserved
  };
#pragma pack(pop)
//+------------------------------------------------------------------+
//| News structure                                                   |
//+------------------------------------------------------------------+
#pragma pack(push,1)
struct MTNews
  {
   //--- constants
   enum constants
     {
      MAX_NEWS_BODY_LEN=15*1024*1024                        // max. body len
     };
   //--- news topic flags
   enum EnNewsFlags
     {
      FLAG_PRIORITY    =1,                                  // priority flag
      FLAG_CALENDAR    =2,                                  // calendar item flag
      FLAG_MIME        =4,                                  // MIME content flag
      FLAG_ALLOW_DEMO  =8                                   // allow news body for 'topic only' accounts
     };
   UINT              language;                              // news language (WinAPI LANGID)
   wchar_t           subject[256];                          // news subject
   wchar_t           category[256];                         // news category
   UINT              flags;                                 // EnNewsFlags
   wchar_t          *body;                                  // body
   UINT              body_len;                              // body length
   UINT              languages_list[32];                    // list of languages available for news
   INT64             datetime;                              // datetime
   UINT              reserved[30];                          // reserved
  };
#pragma pack(pop)
//+------------------------------------------------------------------+
//| Economic event structure                                         |
//+------------------------------------------------------------------+
#pragma pack(push,1)
struct MTEconomicEvent
  {
   //--- news topic flags
   enum EnEconomicEventPriority
     {
      PRIORITY_LOW     =0,                                  // low priority of event
      PRIORITY_NORMAL  =1,                                  // normal priority of event
      PRIORITY_HIGH    =2                                   // high priority of event
     };
   INT64             eventtime;                             // event time
   wchar_t           name[128];                             // event name
   wchar_t           currency[32];                          // event currency
   UINT              priority;                              // event priority
   wchar_t           period[128];                           // event period
   wchar_t           val_previous[32];                      // event previous value
   wchar_t           val_forecast[32];                      // event forecast value
   wchar_t           val_actual[32];                        // event actual value
   UINT              language;                              // news language (WinAPI LANGID)
   UINT              languages_list[32];                    // list of languages available for news
   UINT              reserved[31];                          // reserved
  };
#pragma pack(pop)
//+------------------------------------------------------------------+
//| Gateway events notification interface                            |
//+------------------------------------------------------------------+
class IMTGatewaySink
  {

public:
   //--- connection type
   enum EnConnectType
     {
      CONNECT_TYPE_TRADE   =1,   // Trade server
      CONNECT_TYPE_HISTORY =2,   // History server
      CONNECT_TYPE_ECN     =3,   // ECN
      CONNECT_TYPE_BACKUP  =4,   // Backup server
     };

public:
   //--- MetaTrader Server's connection events and hooks
   virtual MTAPIRES  HookServerConnect(LPCWSTR       /*address*/,
                                       const UINT    /*type*/,
                                       const UINT64  /*login*/)        { return(MT_RET_OK);               }
   virtual void      OnServerDisconnect(LPCWSTR      /*address*/,
                                        const UINT   /*type*/,
                                        const UINT64 /*login*/)        {  }
   //--- gateway events
   virtual void      OnGatewayConfig(const UINT64 /*login*/,const IMTConGateway* /*config*/) {  }
   virtual void      OnGatewayConfig(const UINT64 /*login*/,const IMTConFeeder*  /*config*/) {  }
   virtual void      OnGatewayStart(void)                              {  }
   virtual void      OnGatewayStop(void)                               {  }
   virtual void      OnGatewayShutdown(const UINT64 /*login*/)         {  }
   //--- asynchronous methods notifications
   //--- DealerLock result notification
   virtual void      OnDealerLock(const MTAPIRES     /*retcode*/,
                                  const IMTRequest*  /*request*/,
                                  const IMTUser*     /*user*/,
                                  const IMTAccount*  /*account*/,
                                  const IMTOrder*    /*order*/,
                                  const IMTPosition* /*position*/)     {  }
   //--- DealerAnswer result notification
   virtual void      OnDealerAnswer(const MTAPIRES      /*retcode*/,
                                    const IMTConfirm*   /*confirm*/)   {  }
   virtual void      OnDealerAnswer(const UINT64        /*login*/,
                                    const MTAPIRES      /*retcode*/,
                                    const IMTExecution* /*execution*/) {  }
   //--- external trading system positions control hooks
   virtual MTAPIRES  HookGatewayPositionsRequest(void)                              { return(MT_RET_ERR_NOTIMPLEMENT); }
   virtual MTAPIRES  HookGatewayPositionsCheck(void)                                { return(MT_RET_ERR_NOTIMPLEMENT); }
   virtual MTAPIRES  HookGatewayOrdersRequest(void)                                 { return(MT_RET_ERR_NOTIMPLEMENT); }
   virtual MTAPIRES  HookGatewayAccountRequest(UINT64 /*login*/,
                                               LPCWSTR      /*account_id*/)         { return(MT_RET_ERR_NOTIMPLEMENT); }
   virtual void      OnGatewayAccountAnswer(const MTAPIRES           /*retcode*/,
                                            const INT64              /*request_id*/,
                                            const IMTUser*           /*user*/,
                                            const IMTAccount*        /*account*/,
                                            const IMTOrderArray*     /*orders*/,
                                            const IMTPositionArray*  /*positions*/) {  }
   virtual void      OnGatewayAccountSet(const MTAPIRES           /*retcode*/,
                                         const INT64              /*request_id*/,
                                         const IMTUser*           /*user*/,
                                         const IMTAccount*        /*account*/,
                                         const IMTOrderArray*     /*orders*/,
                                         const IMTPositionArray*  /*positions*/) {  }
   //--- quotes symbols changes
   virtual void      OnServerSymbolAdd(LPCWSTR /*symbol*/)     {  }
   virtual void      OnServerSymbolDelete(LPCWSTR /*symbol*/)  {  }
   //--- MetaTrader Server's synchronization event
   virtual void      OnServerSynchronized(LPCWSTR      /*address*/,
                                          const UINT   /*type*/,
                                          const UINT64 /*id*/) {  }
  };
//+------------------------------------------------------------------+
//| Gateway API interface                                            |
//+------------------------------------------------------------------+
class IMTGatewayAPI
  {
public:
   //--- dealer flags
   enum EnDealerRequestFlags
     {
      DEALER_FLAG_NONE                 =0x00000000,                    // zero flags
      DEALER_FLAG_AUTOLOCK             =0x00000001,                    // automatically lock new requests from request queue
      DEALER_FLAG_USER                 =0x00000002,                    // get IMTUser data on each request
      DEALER_FLAG_ACCOUNT              =0x00000004,                    // get IMTAccount data on each request
      DEALER_FLAG_ORDER                =0x00000008,                    // get IMTOrder data on each request
      DEALER_FLAG_POSITION             =0x00000010,                    // get IMTPosition data on each request
      DEALER_FLAG_EXTERNAL_ACC         =0x00000020,                    // fill ExternalAccount field on each request
      DEALER_FLAG_MARKUP_TRADES        =0x00000040                     // allow modify trading prices according to markup settings
     };
   //--- interface release
   virtual void      Release(void)=0;
   //--- gateway license check
   virtual MTAPIRES  LicenseCheck(MTLicenseCheck &check)=0;
   //--- gateway server start-stop
   virtual MTAPIRES  Start(IMTGatewaySink *sink,LPCWSTR address=NULL)=0;
   virtual MTAPIRES  Stop(void)=0;
   //--- gateway external connection state
   virtual MTAPIRES  StateConnect(const UINT state)=0;
   virtual MTAPIRES  StateTraffic(const UINT received_bytes,const UINT sent_bytes)=0;
   virtual MTAPIRES  StateReserved1(void)=0;
   virtual MTAPIRES  StateReserved2(void)=0;
   virtual MTAPIRES  StateReserved3(void)=0;
   virtual MTAPIRES  StateReserved4(void)=0;
   //--- client connection management
   virtual MTAPIRES  ClientAdd(const UINT64 login,LPCWSTR password)=0;
   virtual MTAPIRES  ClientAllowIP(LPCWSTR address)=0;
   virtual MTAPIRES  ClientReserved1(void)=0;
   virtual MTAPIRES  ClientReserved2(void)=0;
   virtual MTAPIRES  ClientReserved3(void)=0;
   virtual MTAPIRES  ClientReserved4(void)=0;
   //--- gateway server data access
   virtual MTAPIRES  ServerIP(MTAPISTR &ip)=0;
   virtual UINT      ServerPort(void)=0;
   virtual UINT      ServerConnections(void)=0;
   virtual MTAPIRES  ServerReserved1(void)=0;
   virtual MTAPIRES  ServerReserved2(void)=0;
   virtual MTAPIRES  ServerReserved3(void)=0;
   virtual MTAPIRES  ServerReserved4(void)=0;
   //--- log functions
   virtual MTAPIRES  LoggerOut(const UINT code,LPCWSTR format,...)=0;
   virtual void      LoggerFlush(void)=0;
   virtual LPCWSTR   LoggerPath(MTAPISTR& ip)=0;
   virtual MTAPIRES  LoggerReserved2(void)=0;
   virtual MTAPIRES  LoggerReserved3(void)=0;
   virtual MTAPIRES  LoggerReserved4(void)=0;
   //--- send data functions
   virtual MTAPIRES  SendTickStats(MTTickStat *stats,const UINT stats_total)=0;
   virtual MTAPIRES  SendTicks(MTTick *ticks,const UINT ticks_total)=0;
   virtual MTAPIRES  SendBookDiffs(MTBookDiff *bookdiffs,const UINT bookdiffs_total)=0;
   virtual MTAPIRES  SendNews(MTNews *news,const UINT news_total)=0;
   virtual MTAPIRES  SendEconomicEvents(MTEconomicEvent *events,const UINT events_total)=0;
   virtual MTAPIRES  SendBooks(MTBook *books,const UINT books_total)=0;
   virtual MTAPIRES  SendReserved1(void)=0;
   virtual MTAPIRES  SendReserved2(void)=0;
   //--- feeder configuration
   virtual IMTConFeeder* FeederCreate(void)=0;
   virtual IMTConParam* FeederParamCreate(void)=0;
   virtual IMTConFeederTranslate* FeederTranslateCreate(void)=0;
   //--- gateway configuration
   virtual IMTConGateway* GatewayCreate(void)=0;
   virtual IMTConParam* GatewayParamCreate(void)=0;
   virtual IMTConGatewayTranslate* GatewayTranslateCreate(void)=0;
   //--- clients group configuration
   virtual IMTConGroup* GroupCreate(void)=0;
   virtual IMTConGroupSymbol* GroupSymbolCreate(void)=0;
   virtual IMTConCommission* GroupCommissionCreate(void)=0;
   virtual IMTConCommTier* GroupTierCreate(void)=0;
   virtual MTAPIRES  GroupSubscribe(IMTConGroupSink *sink)=0;
   virtual MTAPIRES  GroupUnsubscribe(IMTConGroupSink *sink)=0;
   virtual UINT      GroupTotal(void)=0;
   virtual MTAPIRES  GroupNext(const UINT pos,IMTConGroup *group)=0;
   virtual MTAPIRES  GroupGet(LPCWSTR name,IMTConGroup *group)=0;
   virtual MTAPIRES  GroupReserved1(void)=0;
   virtual MTAPIRES  GroupReserved2(void)=0;
   virtual MTAPIRES  GroupReserved3(void)=0;
   virtual MTAPIRES  GroupReserved4(void)=0;
   //--- trade server symbol configuration access
   virtual IMTConSymbol* SymbolCreate(void)=0;
   virtual IMTConSymbolSession* SymbolSessionCreate(void)=0;
   virtual MTAPIRES  SymbolSubscribe(IMTConSymbolSink *sink)=0;
   virtual MTAPIRES  SymbolUnsubscribe(IMTConSymbolSink *sink)=0;
   virtual MTAPIRES  SymbolAddPreliminary(IMTConSymbol *symbol)=0;
   virtual UINT      SymbolTotal(void)=0;
   virtual MTAPIRES  SymbolNext(const UINT pos,IMTConSymbol *symbol)=0;
   virtual MTAPIRES  SymbolGet(LPCWSTR name,IMTConSymbol *symbol)=0;
   virtual MTAPIRES  SymbolGet(LPCWSTR name,LPCWSTR name_group,IMTConSymbol *symbol)=0;
   virtual MTAPIRES  SymbolUpdate(IMTConSymbol *symbol)=0;
   virtual MTAPIRES  SymbolDelete(LPCWSTR name)=0;
   virtual MTAPIRES  SymbolReserved1(void)=0;
   //--- time config
   virtual IMTConTime* TimeCreate(void)=0;
   virtual MTAPIRES  TimeSubscribe(IMTConTimeSink *sink)=0;
   virtual MTAPIRES  TimeUnsubscribe(IMTConTimeSink *sink)=0;
   virtual INT64     TimeCurrent(void)=0;
   virtual MTAPIRES  TimeGet(IMTConTime *common)=0;
   virtual MTAPIRES  TimeReserved1(void)=0;
   virtual MTAPIRES  TimeReserved2(void)=0;
   virtual MTAPIRES  TimeReserved3(void)=0;
   virtual MTAPIRES  TimeReserved4(void)=0;
   //--- requests
   virtual IMTRequest* RequestCreate(void)=0;
   virtual IMTRequestArray* RequestArrayCreate(void)=0;
   virtual MTAPIRES  RequestSubscribe(IMTRequestSink *sink)=0;
   virtual MTAPIRES  RequestUnsubscribe(IMTRequestSink *sink)=0;
   virtual UINT      RequestTotal(void)=0;
   virtual MTAPIRES  RequestNext(const UINT pos,IMTRequest *request,IMTUser *user,IMTAccount *account,IMTOrder *order,IMTPosition *position)=0;
   virtual MTAPIRES  RequestGet(const UINT id,IMTRequest *request,IMTUser *user,IMTAccount *account,IMTOrder *order,IMTPosition *position)=0;
   virtual MTAPIRES  RequestGetAll(IMTRequestArray *requests)=0;
   virtual MTAPIRES  RequestReserved1(void)=0;
   virtual MTAPIRES  RequestReserved2(void)=0;
   virtual MTAPIRES  RequestReserved3(void)=0;
   virtual MTAPIRES  RequestReserved4(void)=0;
   //--- dealing
   virtual IMTConfirm* DealerConfirmCreate(void)=0;
   virtual IMTExecution* DealerExecutionCreate(void)=0;
   virtual MTAPIRES  DealerStart(const UINT flags)=0;
   virtual MTAPIRES  DealerStop(void)=0;
   virtual MTAPIRES  DealerGetAsync(void)=0;
   virtual MTAPIRES  DealerLockAsync(const UINT id)=0;
   virtual MTAPIRES  DealerAnswerAsync(IMTConfirm *confirm)=0;
   virtual MTAPIRES  DealerExecuteAsync(IMTExecution *execution)=0;
   virtual MTAPIRES  DealerReserved1(void)=0;
   virtual MTAPIRES  DealerReserved2(void)=0;
   virtual MTAPIRES  DealerReserved3(void)=0;
   virtual MTAPIRES  DealerReserved4(void)=0;
   //--- internal email
   virtual IMTMail*  MailCreate(void)=0;
   virtual MTAPIRES  MailSend(IMTMail *mail)=0;
   virtual MTAPIRES  MailReserved1(void)=0;
   virtual MTAPIRES  MailReserved2(void)=0;
   virtual MTAPIRES  MailReserved3(void)=0;
   virtual MTAPIRES  MailReserved4(void)=0;
   //--- clients database
   virtual IMTUser*  UserCreate(void)=0;
   virtual IMTAccount* UserCreateAccount(void)=0;
   //--- open orders database
   virtual IMTOrder* OrderCreate(void)=0;
   //--- trade positions database
   virtual IMTPosition* PositionCreate(void)=0;
   //--- custom settings control
   virtual MTAPIRES  SettingsAdd(const IMTConParam *param)=0;
   virtual MTAPIRES  SettingsUpdate(const UINT pos,const IMTConParam *param)=0;
   virtual MTAPIRES  SettingsUpdate(const IMTConParam *param)=0;
   virtual MTAPIRES  SettingsDelete(const UINT pos)=0;
   virtual MTAPIRES  SettingsDelete(LPCWSTR name)=0;
   virtual MTAPIRES  SettingsClear(void)=0;
   virtual UINT      SettingsTotal(void)=0;
   virtual MTAPIRES  SettingsNext(const UINT pos,IMTConParam *param)=0;
   virtual MTAPIRES  SettingsGet(LPCWSTR name,IMTConParam *param)=0;
   virtual MTAPIRES  SettingsReserved1(void)=0;
   virtual MTAPIRES  SettingsReserved2(void)=0;
   virtual MTAPIRES  SettingsReserved3(void)=0;
   virtual MTAPIRES  SettingsReserved4(void)=0;
   //--- external trading system positions control
   virtual IMTConParamArray* GatewayParamArrayCreate(void)=0;
   virtual IMTPositionArray* GatewayPositionArrayCreate(void)=0;
   virtual MTAPIRES  GatewayPositionsAnswer(const MTAPIRES result,const INT64 positions_time,const IMTPositionArray *positions)=0;
   virtual MTAPIRES  GatewayPositionsCheck(const MTAPIRES result,const INT64 positions_time,const IMTPositionArray *positions)=0;
   virtual MTAPIRES  GatewayPositionsReserved1(void)=0;
   virtual MTAPIRES  GatewayPositionsReserved2(void)=0;
   virtual MTAPIRES  GatewayPositionsReserved3(void)=0;
   virtual MTAPIRES  GatewayPositionsReserved4(void)=0;
   //--- chart data
   virtual MTAPIRES  ChartRequest(LPCWSTR symbol,const INT64 from,const INT64 to,MTChartBar *&bars,UINT &bars_total)=0;
   virtual MTAPIRES  ChartDelete(LPCWSTR symbol,const INT64 *bars_dates,const UINT bars_total)=0;
   virtual MTAPIRES  ChartUpdate(LPCWSTR symbol,const MTChartBar *bars,const UINT bars_total)=0;
   virtual MTAPIRES  ChartReplace(LPCWSTR symbol,const INT64 from,const INT64 to,const MTChartBar *bars,const UINT bars_total)=0;
   virtual MTAPIRES  ChartReserved1(void)=0;
   virtual MTAPIRES  ChartReserved2(void)=0;
   virtual MTAPIRES  ChartReserved3(void)=0;
   virtual MTAPIRES  ChartReserved4(void)=0;
   //--- memory management
   virtual void*     Allocate(const UINT bytes)=0;
   virtual void      Free(void *ptr)=0;
   //--- spreads configuration
   virtual IMTConSpread* SpreadCreate(void)=0;
   virtual IMTConSpreadLeg* SpreadLegCreate(void)=0;
   virtual MTAPIRES  SpreadSubscribe(IMTConSpreadSink *sink)=0;
   virtual MTAPIRES  SpreadUnsubscribe(IMTConSpreadSink *sink)=0;
   virtual MTAPIRES  SpreadAdd(IMTConSpread *spread)=0;
   virtual MTAPIRES  SpreadDelete(const UINT pos)=0;
   virtual MTAPIRES  SpreadShift(const UINT pos,const int shift)=0;
   virtual UINT      SpreadTotal(void)=0;
   virtual MTAPIRES  SpreadNext(const UINT pos,IMTConSpread *spread)=0;
   virtual MTAPIRES  SpreadGet(const UINT id,IMTConSpread *spread)=0;
   virtual MTAPIRES  SpreadReserved1(void)=0;
   virtual MTAPIRES  SpreadReserved2(void)=0;
   virtual MTAPIRES  SpreadReserved3(void)=0;
   virtual MTAPIRES  SpreadReserved4(void)=0;
   //--- external trading system pending orders control
   virtual IMTOrderArray* GatewayOrderArrayCreate(void)=0;
   virtual MTAPIRES  GatewayOrdersAnswer(const MTAPIRES result,const INT64 orders_time,const IMTOrderArray *orders)=0;
   virtual MTAPIRES  GatewayOrdersReserved1(void)=0;
   virtual MTAPIRES  GatewayOrdersReserved2(void)=0;
   virtual MTAPIRES  GatewayOrdersReserved3(void)=0;
   virtual MTAPIRES  GatewayOrdersReserved4(void)=0;
   //--- external trading system trading accounts control
   virtual MTAPIRES  GatewayAccountAnswer(const MTAPIRES result,
                                          const INT64 accounts_time,
                                          const IMTUser *user,
                                          const IMTAccount *account,
                                          const IMTOrderArray *orders,
                                          const IMTPositionArray *positions)=0;
   virtual MTAPIRES  GatewayAccountRequest(const INT64 request_id,
                                           const IMTUser *user)=0;
   virtual MTAPIRES  GatewayAccountSet(const INT64 request_id,
                                       const IMTUser *user,
                                       const IMTAccount *account,
                                       const IMTOrderArray *orders,
                                       const IMTPositionArray *positions)=0;
   virtual MTAPIRES  GatewayAccountsReserved1(void)=0;
   virtual MTAPIRES  GatewayAccountsReserved2(void)=0;
   //--- platform server config
   virtual IMTConServer* NetServerCreate(void)=0;
   virtual IMTConServerRange* NetServerRangeCreate(void)=0;
   virtual MTAPIRES  NetServerSubscribe(IMTConServerSink* sink)=0;
   virtual MTAPIRES  NetServerUnsubscribe(IMTConServerSink* sink)=0;
   virtual UINT      NetServerTotal(void)=0;
   virtual MTAPIRES  NetServerNext(const UINT pos,IMTConServer* config)=0;
   virtual MTAPIRES  NetServerGet(const UINT64 id,IMTConServer* config)=0;
   virtual MTAPIRES  NetServerReserved1(void)=0;
   virtual MTAPIRES  NetServerReserved2(void)=0;
   virtual MTAPIRES  NetServerReserved3(void)=0;
   virtual MTAPIRES  NetServerReserved4(void)=0;
   //--- clients database
   virtual MTAPIRES  UserSubscribe(IMTUserSink* sink)=0;
   virtual MTAPIRES  UserUnsubscribe(IMTUserSink* sink)=0;
   virtual UINT      UserTotal(void)=0;
   virtual MTAPIRES  UserGet(const UINT64 login,IMTUser* user)=0;
   virtual MTAPIRES  UserGroup(const UINT64 login,MTAPISTR& group)=0;
   virtual MTAPIRES  UserLogins(UINT64*& logins,UINT& logins_total)=0;
   virtual MTAPIRES  UserGetByAccount(LPCWSTR account,IMTUser* user)=0;
   virtual MTAPIRES  UserReserved1(void)=0;
   virtual MTAPIRES  UserReserved2(void)=0;
   virtual MTAPIRES  UserReserved3(void)=0;
   virtual MTAPIRES  UserReserved4(void)=0;
   virtual MTAPIRES  UserReserved5(void)=0;
   virtual MTAPIRES  UserReserved6(void)=0;
   virtual MTAPIRES  UserReserved7(void)=0;
   //--- gateway symbol configuration access
   virtual MTAPIRES  GatewaySymbolAdd(IMTConSymbol *symbol)=0;
   virtual UINT      GatewaySymbolTotal(void)=0;
   virtual MTAPIRES  GatewaySymbolNext(const UINT pos,IMTConSymbol *symbol)=0;
   virtual MTAPIRES  GatewaySymbolGet(LPCWSTR name,IMTConSymbol *symbol)=0;
   virtual MTAPIRES  GatewaySymbolDelete(LPCWSTR name)=0;
   virtual MTAPIRES  GatewaySymbolClear(void)=0;
   virtual MTAPIRES  GatewaySymbolReserver1(void)=0;
   virtual MTAPIRES  GatewaySymbolReserver2(void)=0;
   virtual MTAPIRES  GatewaySymbolReserver3(void)=0;
   virtual MTAPIRES  GatewaySymbolReserver4(void)=0;
   //--- ticks history
   virtual MTAPIRES  TickHistoryRequest(LPCWSTR symbol,const INT64 from,const INT64 to,MTTickRate*& ticks,UINT& ticks_total)=0;
   virtual MTAPIRES  TickHistoryRequestRaw(LPCWSTR symbol,const INT64 from,const INT64 to,MTTickRate*& ticks,UINT& ticks_total)=0;
   virtual MTAPIRES  TickHistoryAdd(LPCWSTR symbol,const MTTickRate* ticks,const UINT ticks_total)=0;
   virtual MTAPIRES  TickHistoryReplace(LPCWSTR symbol,const INT64 from_msc,const INT64 to_msc,const MTTickRate* ticks,const UINT ticks_total)=0;
   virtual MTAPIRES  TickHistoryReserver1(void)=0;
   virtual MTAPIRES  TickHistoryReserver2(void)=0;
   virtual MTAPIRES  TickHistoryReserver3(void)=0;
   virtual MTAPIRES  TickHistoryReserver4(void)=0;
   //--- explicit destructor is prohibited
protected:
                    ~IMTGatewayAPI(void) {}
  };
//+------------------------------------------------------------------+
//| Entry point functions declarations                               |
//+------------------------------------------------------------------+
typedef /*__declspec(dllexport)*/ MTAPIRES(*MTGatewayVersion_t)     (UINT &version);
typedef /*__declspec(dllexport)*/ MTAPIRES(*MTGatewayCreate_t)      (MTGatewayInfo &info,IMTGatewayAPI **gateway);
typedef /*__declspec(dllexport)*/ MTAPIRES(*MTGatewayCreateLocal_t) (MTGatewayInfo &info,IMTGatewayAPI **gateway,int argc,wchar_t** argv);
//+------------------------------------------------------------------+
//| Entry point functions names                                      |
//+------------------------------------------------------------------+
static const LPCSTR s_MTGatewayVersion             ="MTGatewayVersion";
static const LPCSTR s_MTGatewayCreate              ="MTGatewayCreate";
static const LPCSTR s_MTGatewayCreateLocal         ="MTGatewayCreateLocal";
//+------------------------------------------------------------------+
//| Gateway factory                                                  |
//+------------------------------------------------------------------+
class CMTGatewayAPIFactory
  {
   HMODULE           m_hmodule;
   MTGatewayVersion_t m_mtversion;
   MTGatewayCreate_t m_mtcreate;
   MTGatewayCreateLocal_t m_mtcreate_local;

public:
                     CMTGatewayAPIFactory() : m_hmodule(NULL),m_mtversion(NULL),m_mtcreate(NULL),m_mtcreate_local(NULL) {}
   //--- initialize & shutdown
   MTAPIRES          Initialize(void);
   MTAPIRES          Shutdown(void);
   //--- gateway creation
   MTAPIRES          Create(MTGatewayInfo &info,IMTGatewayAPI **gateway,int argc=0,wchar_t** argv=NULL) const;
   //--- check license sign
   static MTAPIRES   LicenseCheck(IMTGatewayAPI *gateway,LPCWSTR name);
   //--- version info
   MTAPIRES          Version(UINT &version) const;

private:
   bool              FindLibrary(wchar_t *path,const size_t path_maxlen);
  };
//+------------------------------------------------------------------+
//| Library initialization                                           |
//+------------------------------------------------------------------+
inline MTAPIRES CMTGatewayAPIFactory::Initialize(void)
  {
   wchar_t  path[MAX_PATH]={};
//--- find the Gateway API DLL
   if(!FindLibrary(path,_countof(path)-1))
      return(MT_RET_ERR_NOTFOUND);
//--- try to load Gateway API DLL from current folder
   if((m_hmodule=::LoadLibrary(path))==NULL)
      return(MT_RET_ERR_NOTFOUND);
//--- find entry point addresses
   m_mtversion     =reinterpret_cast<MTGatewayVersion_t>(::GetProcAddress(m_hmodule,s_MTGatewayVersion));
   m_mtcreate      =reinterpret_cast<MTGatewayCreate_t>(::GetProcAddress(m_hmodule,s_MTGatewayCreate));
   m_mtcreate_local=reinterpret_cast<MTGatewayCreateLocal_t>(::GetProcAddress(m_hmodule,s_MTGatewayCreateLocal));
//--- check results
   if(!m_mtversion || !m_mtcreate || !m_mtcreate_local)
     {
      Shutdown();
      //--- not found
      return(MT_RET_ERR_NOTFOUND);
     }
//--- ok
   return(MT_RET_OK);
  }
//+------------------------------------------------------------------+
//| Library shutdown                                                 |
//+------------------------------------------------------------------+
inline MTAPIRES CMTGatewayAPIFactory::Shutdown(void)
  {
//--- check & free
   if(m_hmodule)
     {
      ::FreeLibrary((HMODULE)m_hmodule);
      m_hmodule=NULL;
     }
//--- zero members
   m_mtversion     =NULL;
   m_mtcreate      =NULL;
   m_mtcreate_local=NULL;
//--- ok
   return(MT_RET_OK);
  }
//+------------------------------------------------------------------+
//| Find the library                                                 |
//+------------------------------------------------------------------+
inline bool CMTGatewayAPIFactory::FindLibrary(wchar_t *path,const size_t path_maxlen)
  {
   wchar_t  folder[MAX_PATH]={};
   wchar_t *ptr;
//--- find the folder
   ::GetModuleFileNameW(NULL,folder,_countof(folder)-1);
//--- check for 5 levels
   for(int i=0;i<5;i++)
     {
      //--- remove level
      if((ptr=wcsrchr(folder,L'\\'))==NULL)
         break;

      *ptr=L'\0';
      //--- check the file
      if(sizeof(void*)==4)
         swprintf_s(path,path_maxlen,L"%s\\MT5APIGateway.dll",folder);
      else
         swprintf_s(path,path_maxlen,L"%s\\MT5APIGateway64.dll",folder);

      if(GetFileAttributesW(path)!=INVALID_FILE_ATTRIBUTES)
         return(true);
      //--- check /libs folder
      if(sizeof(void*)==4)
         swprintf_s(path,path_maxlen,L"%s\\libs\\MT5APIGateway.dll",folder);
      else
         swprintf_s(path,path_maxlen,L"%s\\libs\\MT5APIGateway64.dll",folder);

      if(GetFileAttributesW(path)!=INVALID_FILE_ATTRIBUTES)
         return(true);
     }
//--- try to find library in PATH
   if(sizeof(void*)==4)
      wcscpy_s(path,path_maxlen,L"MT5APIGateway.dll");
   else
      wcscpy_s(path,path_maxlen,L"MT5APIGateway64.dll");
   return(true);
  }
//+------------------------------------------------------------------+
//| Gateway interface creation                                       |
//+------------------------------------------------------------------+
inline MTAPIRES CMTGatewayAPIFactory::Create(MTGatewayInfo& info,IMTGatewayAPI **gateway,int argc/*=0*/,wchar_t** argv/*=NULL*/) const
  {
   MTAPIRES res=MT_RET_ERROR;
//--- check members & parameters
   if(!m_hmodule || !m_mtcreate || !m_mtcreate_local || !gateway)
      return(MT_RET_ERROR);
//--- call common or local-mode creation
   if(!argc || !argv)
      res=m_mtcreate(info,gateway);
   else
      res=m_mtcreate_local(info,gateway,argc,argv);
//--- result
   return(res);
  }
//+------------------------------------------------------------------+
//| Gateway license sign check                                       |
//+------------------------------------------------------------------+
inline MTAPIRES CMTGatewayAPIFactory::LicenseCheck(IMTGatewayAPI *gateway,LPCWSTR name)
  {
//--- checking
   if(!gateway || !name || name[0]==L'\0')
      return(MT_RET_ERROR);
//--- fill license information, copy name
   MTLicenseCheck license={},license_check={};
   HCRYPTPROV     prov=NULL;
   HCRYPTHASH     hash=NULL;
   HCRYPTKEY      key =NULL;
   MTAPIRES       res=MT_RET_ERROR;

   wcscpy_s(license.name,_countof(license.name),name);
   CMTStr::Terminate(license.name);
//--- initialize random generator
   srand((unsigned int)GetTickCount());
//--- generate sequence of random numbers
   for(license.random_size=0;license.random_size<sizeof(license.random);license.random_size++)
      license.random[license.random_size]=char(rand()&0xFF);
//--- make copy
   memcpy(&license_check,&license,sizeof(license));
//--- check license
   gateway->LicenseCheck(license_check);
//--- check retcode
   if(license_check.retcode!=MT_RET_OK)
      return(license_check.retcode);
//--- check license sign, initialize provider
   if(CryptAcquireContext(&prov,NULL,MS_DEF_PROV,PROV_RSA_FULL,CRYPT_VERIFYCONTEXT)==FALSE)
      return(MT_RET_ERROR);
//--- import public key
   if(CryptImportKey(prov,(const BYTE*)MT5APIPublicKey,sizeof(MT5APIPublicKey),0,0,&key)!=FALSE)
     {
      //--- initialize hash object
      if(CryptCreateHash(prov,CALG_MD5,0,0,&hash)!=FALSE)
        {
         //--- set hash from original data
         if(CryptHashData(hash,(BYTE*)&license,(DWORD)offsetof(MTLicenseCheck,retcode),0)!=FALSE)
           {
            //--- verify hash sign, using public key
            if(CryptVerifySignature(hash,(BYTE*)license_check.sign,(DWORD)license_check.sign_size,key,NULL,0)!=FALSE)
               res=license_check.retcode;
            else
               res=MT_RET_ERR_DATA;
           }
        }
     }
//--- destroy hash
   if(hash)
      CryptDestroyHash(hash);
//--- destroy key
   if(key)
      CryptDestroyKey(key);
//--- release provider
   if(prov)
      CryptReleaseContext(prov,0);
//--- return result
   return(res);
  }
//+------------------------------------------------------------------+
//| Version                                                          |
//+------------------------------------------------------------------+
inline MTAPIRES CMTGatewayAPIFactory::Version(UINT &version) const
  {
//--- check members & parameters
   if(!m_hmodule || !m_mtversion)
      return(MT_RET_ERROR);
//--- result
   return(m_mtversion(version));
  }
//+------------------------------------------------------------------+
