//+------------------------------------------------------------------+
//|                                                 MetaTrader 5 API |
//|                             Copyright 2000-2021, MetaQuotes Ltd. |
//|                                               www.metaquotes.net |
//+------------------------------------------------------------------+
#pragma once
//+------------------------------------------------------------------+
//| Thread synchronization class                                     |
//+------------------------------------------------------------------+
class CMTSync
  {
private:
   CRITICAL_SECTION  m_cs;

public:
                     CMTSync(void)      { ZeroMemory(&m_cs,sizeof(m_cs)); InitializeCriticalSection(&m_cs); }
                    ~CMTSync(void)      { DeleteCriticalSection(&m_cs);                  }

   inline void       Lock(void)         { EnterCriticalSection(&m_cs);                   }
   inline void       Unlock(void)       { LeaveCriticalSection(&m_cs);                   }
   inline bool       TryLock(void)      { return(TryEnterCriticalSection(&m_cs)!=FALSE); }
  };
//+------------------------------------------------------------------+
