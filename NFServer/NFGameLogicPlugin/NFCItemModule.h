// -------------------------------------------------------------------------
//    @FileName      :    NFCMoveModule.h
//    @Author           :    LvSheng.Huang
//    @Date             :    2013-06-11
//    @Module           :    NFCMoveModule
//
// -------------------------------------------------------------------------

#ifndef NFC_ITEM_MODULE_H
#define NFC_ITEM_MODULE_H

#include "NFCPackModule.h"
#include "NFComm/NFPluginModule/NFIKernelModule.h"
#include "NFComm/NFPluginModule/NFIGameLogicModule.h"
#include "NFComm/NFPluginModule/NFIItemModule.h"
#include "NFComm/NFPluginModule/NFIClassModule.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFIPropertyModule.h"
#include "NFComm/NFPluginModule/NFIHeroModule.h"
#include "NFComm/NFPluginModule/NFICommonConfigModule.h"
#include "NFComm/NFPluginModule/NFIGameServerNet_ServerModule.h"
#include "NFComm/NFPluginModule/NFIEventModule.h"
#include "NFComm/NFPluginModule/NFIEventModule.h"

class NFCItemModule
    : public NFIItemModule
{
public:

    NFCItemModule( NFIPluginManager* p )
    {
        pPluginManager = p;
    }
    virtual ~NFCItemModule() {};

    virtual bool Init();
    virtual bool Shut();
    virtual bool Execute();
    virtual bool AfterInit();



protected:
	virtual bool CheckConfig();


	int OnClassObjectEvent( const NFGUID& self, const std::string& strClassNames, const CLASS_OBJECT_EVENT eClassEvent, const NFIDataList& var );
	int OnRequireUseItemPosEvent( const NFGUID& self, const NFEventDefine nEventID, const NFIDataList& var );
    int AddItemEffectDataProperty( const NFGUID& self, const NFGUID& xTarget, const std::string& strItemID);
    bool ConsumeDataItemProperty( const NFGUID& self, const std::string& strID);
	bool DoAwardPack( const NFGUID& self, const std::string& strAwardPack);

protected:
	void OnClienUseItem(const int nSockIndex, const int nMsgID, const char* msg, const uint32_t nLen);

private:
    NFIEventModule* m_pEventModule;
	NFIKernelModule* m_pKernelModule;
    NFIPackModule* m_pPackModule;
    NFIElementModule* m_pElementModule;
    NFIClassModule* m_pLogicClassModule;
    NFIPropertyModule* m_pPropertyModule;
	NFIHeroModule* m_pHeroModule;
	NFICommonConfigModule* m_pCommonConfigModule;
	NFIGameServerNet_ServerModule* m_pGameServerNet_ServerModule;
};


#endif
