/*
 * Copyright (C) 2021-2023 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "ims_test.h"

#define private public
#define protected public
#include "cellular_call_config.h"
#include "cellular_call_handler.h"
#include "cellular_call_proxy.h"
#include "cellular_call_register.h"
#include "cellular_call_service.h"
#include "tel_ril_call_parcel.h"
#include "ims_call_callback_proxy.h"
#include "ims_call_callback_stub.h"
#include "ims_call_client.h"
#include "ims_control.h"
#include "ims_error.h"
#include "securec.h"

namespace OHOS {
namespace Telephony {
using namespace testing::ext;
const int32_t SIM1_SLOTID = 0;
const int32_t SIM2_SLOTID = 1;
const int32_t SLOT_COUNT = 2;
const int32_t INVALID_SLOTID = -1;
const int32_t INVALID_HANG_UP_TYPE = -1;
const int32_t RESULT = 1;
const std::string PHONE_NUMBER = "0000000";
const std::string PHONE_NUMBER_SECOND = "1111111";
const std::string PHONE_NUMBER_THIRD = "2222222";
const std::string PHONE_NUMBER_FOUR = "3333333";

/**
 * @tc.number   cellular_call_SetVoNRState_0002
 * @tc.name     Test for SetVoNRState function
 * @tc.desc     Function test
 */
HWTEST_F(ImsTest, cellular_call_SetVoNRState_0002, Function | MediumTest | Level2)
{
    AccessToken token;
    if (!HasSimCard(SIM1_SLOTID) && !HasSimCard(SIM2_SLOTID)) {
        return;
    }
    auto systemAbilityMgr = SystemAbilityManagerClient::GetInstance().GetSystemAbilityManager();
    ASSERT_TRUE(systemAbilityMgr != nullptr);
    auto setVoNRRemote = systemAbilityMgr->CheckSystemAbility(TELEPHONY_CELLULAR_CALL_SYS_ABILITY_ID);
    ASSERT_TRUE(setVoNRRemote != nullptr);
    auto telephonyService = iface_cast<CellularCallInterface>(setVoNRRemote);
    ASSERT_TRUE(telephonyService != nullptr);
    if (HasSimCard(SIM1_SLOTID)) {
        int32_t ret = telephonyService->SetVoNRState(SIM1_SLOTID, 0);
        EXPECT_EQ(ret, TELEPHONY_SUCCESS);
    }
    if (HasSimCard(SIM2_SLOTID)) {
        int32_t ret = telephonyService->SetVoNRState(SIM2_SLOTID, 0);
        EXPECT_EQ(ret, TELEPHONY_SUCCESS);
    }
}

/**
 * @tc.number   cellular_call_GetVoNRState_0001
 * @tc.name     Test for GetVoNRState function
 * @tc.desc     Function test
 */
HWTEST_F(ImsTest, cellular_call_GetVoNRState_0001, Function | MediumTest | Level2)
{
    AccessToken token;
    auto systemAbilityMgr = SystemAbilityManagerClient::GetInstance().GetSystemAbilityManager();
    ASSERT_TRUE(systemAbilityMgr != nullptr);
    auto getVoNRRemote = systemAbilityMgr->CheckSystemAbility(TELEPHONY_CELLULAR_CALL_SYS_ABILITY_ID);
    ASSERT_TRUE(getVoNRRemote != nullptr);
    auto telephonyService = iface_cast<CellularCallInterface>(getVoNRRemote);
    ASSERT_TRUE(telephonyService != nullptr);
    if (!HasSimCard(SIM1_SLOTID) && !HasSimCard(SIM2_SLOTID)) {
        return;
    }
    if (HasSimCard(SIM1_SLOTID)) {
        int32_t result;
        int32_t ret = telephonyService->GetVoNRState(SIM1_SLOTID, result);
        EXPECT_EQ(ret, TELEPHONY_SUCCESS);
    }
    if (HasSimCard(SIM2_SLOTID)) {
        int32_t result;
        int32_t ret = telephonyService->GetVoNRState(SIM2_SLOTID, result);
        EXPECT_EQ(ret, TELEPHONY_SUCCESS);
    }
}

/**
 * @tc.number   cellular_call_StartRtt_0001
 * @tc.name     Test for StartRtt function
 * @tc.desc     Function test
 */
HWTEST_F(ImsTest, cellular_call_StartRtt_0001, Function | MediumTest | Level2)
{
    AccessToken token;
    auto systemAbilityMgr = SystemAbilityManagerClient::GetInstance().GetSystemAbilityManager();
    ASSERT_TRUE(systemAbilityMgr != nullptr);
    auto startRttRemote = systemAbilityMgr->CheckSystemAbility(TELEPHONY_CELLULAR_CALL_SYS_ABILITY_ID);
    ASSERT_TRUE(startRttRemote != nullptr);
    auto telephonyService = iface_cast<CellularCallInterface>(startRttRemote);
    ASSERT_TRUE(telephonyService != nullptr);
    if (!HasSimCard(SIM1_SLOTID) && !HasSimCard(SIM2_SLOTID)) {
        return;
    }
    if (HasSimCard(SIM1_SLOTID) && CanUseImsService(SIM2_SLOTID, ImsServiceType::TYPE_VOICE)) {
        int32_t ret = telephonyService->StartRtt(SIM1_SLOTID, PHONE_NUMBER);
        EXPECT_EQ(ret, TELEPHONY_SUCCESS);
    }
    if (HasSimCard(SIM2_SLOTID) && CanUseImsService(SIM2_SLOTID, ImsServiceType::TYPE_VOICE)) {
        int32_t ret = telephonyService->StartRtt(SIM2_SLOTID, PHONE_NUMBER);
        EXPECT_EQ(ret, TELEPHONY_SUCCESS);
    }
}

/**
 * @tc.number   cellular_call_StopRtt_0001
 * @tc.name     Test for StopRtt function
 * @tc.desc     Function test
 */
HWTEST_F(ImsTest, cellular_call_StopRtt_0001, Function | MediumTest | Level2)
{
    AccessToken token;
    auto systemAbilityMgr = SystemAbilityManagerClient::GetInstance().GetSystemAbilityManager();
    ASSERT_TRUE(systemAbilityMgr != nullptr);
    auto stopRttRemote = systemAbilityMgr->CheckSystemAbility(TELEPHONY_CELLULAR_CALL_SYS_ABILITY_ID);
    ASSERT_TRUE(stopRttRemote != nullptr);
    auto telephonyService = iface_cast<CellularCallInterface>(stopRttRemote);
    ASSERT_TRUE(telephonyService != nullptr);
    if (!HasSimCard(SIM1_SLOTID) && !HasSimCard(SIM2_SLOTID)) {
        return;
    }
    if (HasSimCard(SIM1_SLOTID) && CanUseImsService(SIM2_SLOTID, ImsServiceType::TYPE_VOICE)) {
        int32_t ret = telephonyService->StopRtt(SIM1_SLOTID);
        EXPECT_EQ(ret, TELEPHONY_SUCCESS);
    }
    if (HasSimCard(SIM2_SLOTID) && CanUseImsService(SIM2_SLOTID, ImsServiceType::TYPE_VOICE)) {
        int32_t ret = telephonyService->StopRtt(SIM2_SLOTID);
        EXPECT_EQ(ret, TELEPHONY_SUCCESS);
    }
}

/**
 * @tc.number   cellular_call_SetDomainPreferenceMode_0001
 * @tc.name     Test for SetDomainPreferenceMode function
 * @tc.desc     Function test
 */
HWTEST_F(ImsTest, cellular_call_SetDomainPreferenceMode_0001, Function | MediumTest | Level2)
{
    AccessToken token;
    auto systemAbilityMgr = SystemAbilityManagerClient::GetInstance().GetSystemAbilityManager();
    ASSERT_TRUE(systemAbilityMgr != nullptr);
    auto domainPrefModeRemote = systemAbilityMgr->CheckSystemAbility(TELEPHONY_CELLULAR_CALL_SYS_ABILITY_ID);
    ASSERT_TRUE(domainPrefModeRemote != nullptr);
    auto telephonyService = iface_cast<CellularCallInterface>(domainPrefModeRemote);
    ASSERT_TRUE(telephonyService != nullptr);
    if (!HasSimCard(SIM1_SLOTID) && !HasSimCard(SIM2_SLOTID)) {
        return;
    }
    if (HasSimCard(SIM1_SLOTID) && CanUseImsService(SIM2_SLOTID, ImsServiceType::TYPE_VOICE)) {
        int32_t mode = -1;
        int32_t ret = telephonyService->SetDomainPreferenceMode(SIM1_SLOTID, mode);
        EXPECT_EQ(ret, CALL_ERR_PARAMETER_OUT_OF_RANGE);
    }
    if (HasSimCard(SIM2_SLOTID) && CanUseImsService(SIM2_SLOTID, ImsServiceType::TYPE_VOICE)) {
        int32_t mode = -1;
        int32_t ret = telephonyService->SetDomainPreferenceMode(SIM2_SLOTID, mode);
        EXPECT_EQ(ret, CALL_ERR_PARAMETER_OUT_OF_RANGE);
    }
}

/**
 * @tc.number   cellular_call_GetImsConfig_0001
 * @tc.name     Test for GetImsConfig function
 * @tc.desc     Function test
 */
HWTEST_F(ImsTest, cellular_call_GetImsConfig_0001, Function | MediumTest | Level2)
{
    AccessToken token;
    auto systemAbilityMgr = SystemAbilityManagerClient::GetInstance().GetSystemAbilityManager();
    ASSERT_TRUE(systemAbilityMgr != nullptr);
    auto getImsConfigRemote = systemAbilityMgr->CheckSystemAbility(TELEPHONY_CELLULAR_CALL_SYS_ABILITY_ID);
    ASSERT_TRUE(getImsConfigRemote != nullptr);
    auto telephonyService = iface_cast<CellularCallInterface>(getImsConfigRemote);
    ASSERT_TRUE(telephonyService != nullptr);
    if (!HasSimCard(SIM1_SLOTID) && !HasSimCard(SIM2_SLOTID)) {
        return;
    }
    if (HasSimCard(SIM1_SLOTID) && CanUseImsService(SIM2_SLOTID, ImsServiceType::TYPE_VOICE)) {
        ImsConfigItem mode = ITEM_IMS_SWITCH_STATUS;
        int32_t ret = telephonyService->GetImsConfig(SIM1_SLOTID, mode);
        EXPECT_EQ(ret, TELEPHONY_SUCCESS);
    }
    if (HasSimCard(SIM2_SLOTID) && CanUseImsService(SIM2_SLOTID, ImsServiceType::TYPE_VOICE)) {
        ImsConfigItem mode = ITEM_IMS_SWITCH_STATUS;
        int32_t ret = telephonyService->GetImsConfig(SIM2_SLOTID, mode);
        EXPECT_EQ(ret, TELEPHONY_SUCCESS);
    }
}

/**
 * @tc.number   cellular_call_GetImsFeatureValue_0001
 * @tc.name     Test for GetImsFeatureValue function
 * @tc.desc     Function test
 */
HWTEST_F(ImsTest, cellular_call_GetImsFeatureValue_0001, Function | MediumTest | Level2)
{
    AccessToken token;
    auto systemAbilityMgr = SystemAbilityManagerClient::GetInstance().GetSystemAbilityManager();
    ASSERT_TRUE(systemAbilityMgr != nullptr);
    auto getImsFeatureRemote = systemAbilityMgr->CheckSystemAbility(TELEPHONY_CELLULAR_CALL_SYS_ABILITY_ID);
    ASSERT_TRUE(getImsFeatureRemote != nullptr);
    auto telephonyService = iface_cast<CellularCallInterface>(getImsFeatureRemote);
    ASSERT_TRUE(telephonyService != nullptr);
    if (!HasSimCard(SIM1_SLOTID) && !HasSimCard(SIM2_SLOTID)) {
        return;
    }
    if (HasSimCard(SIM1_SLOTID) && CanUseImsService(SIM2_SLOTID, ImsServiceType::TYPE_VOICE)) {
        FeatureType mode = TYPE_VOICE_OVER_LTE;
        int32_t ret = telephonyService->GetImsFeatureValue(SIM1_SLOTID, mode);
        EXPECT_EQ(ret, TELEPHONY_SUCCESS);
    }
    if (HasSimCard(SIM2_SLOTID) && CanUseImsService(SIM2_SLOTID, ImsServiceType::TYPE_VOICE)) {
        FeatureType mode = TYPE_VOICE_OVER_LTE;
        int32_t ret = telephonyService->GetImsFeatureValue(SIM2_SLOTID, mode);
        EXPECT_EQ(ret, TELEPHONY_SUCCESS);
    }
}

/**
 * @tc.number   cellular_call_SetMute_0001
 * @tc.name     Test for SetMute function
 * @tc.desc     Function test
 */
HWTEST_F(ImsTest, cellular_call_SetMute_0001, Function | MediumTest | Level2)
{
    AccessToken token;
    auto systemAbilityMgr = SystemAbilityManagerClient::GetInstance().GetSystemAbilityManager();
    ASSERT_TRUE(systemAbilityMgr != nullptr);
    auto setMuteRemote = systemAbilityMgr->CheckSystemAbility(TELEPHONY_CELLULAR_CALL_SYS_ABILITY_ID);
    ASSERT_TRUE(setMuteRemote != nullptr);
    auto telephonyService = iface_cast<CellularCallInterface>(setMuteRemote);
    ASSERT_TRUE(telephonyService != nullptr);
    if (!HasSimCard(SIM1_SLOTID) && !HasSimCard(SIM2_SLOTID)) {
        return;
    }
    if (HasSimCard(SIM1_SLOTID) && CanUseImsService(SIM2_SLOTID, ImsServiceType::TYPE_VOICE)) {
        int32_t mode = 0;
        int32_t ret = telephonyService->SetMute(SIM1_SLOTID, mode);
        EXPECT_EQ(ret, TELEPHONY_SUCCESS);
    }
    if (HasSimCard(SIM2_SLOTID) && CanUseImsService(SIM2_SLOTID, ImsServiceType::TYPE_VOICE)) {
        int32_t mode = 0;
        int32_t ret = telephonyService->SetMute(SIM2_SLOTID, mode);
        EXPECT_EQ(ret, TELEPHONY_SUCCESS);
    }
}

/**
 * @tc.number   cellular_call_SetCallWaiting_0001
 * @tc.name     Test for SetCallWaiting function
 * @tc.desc     Function test
 */
HWTEST_F(ImsTest, cellular_call_SetCallWaiting_0001, Function | MediumTest | Level2)
{
    AccessToken token;
    auto systemAbilityMgr = SystemAbilityManagerClient::GetInstance().GetSystemAbilityManager();
    ASSERT_TRUE(systemAbilityMgr != nullptr);
    auto SetCWRemote = systemAbilityMgr->CheckSystemAbility(TELEPHONY_CELLULAR_CALL_SYS_ABILITY_ID);
    ASSERT_TRUE(SetCWRemote != nullptr);
    auto telephonyService = iface_cast<CellularCallInterface>(SetCWRemote);
    ASSERT_TRUE(telephonyService != nullptr);
    if (!HasSimCard(SIM1_SLOTID) && !HasSimCard(SIM2_SLOTID)) {
        return;
    }
    if (HasSimCard(SIM1_SLOTID) && CanUseImsService(SIM2_SLOTID, ImsServiceType::TYPE_UT)) {
        bool act = true;
        int32_t ret = telephonyService->SetCallWaiting(SIM1_SLOTID, act);
        EXPECT_EQ(ret, TELEPHONY_SUCCESS);
    }
    if (HasSimCard(SIM2_SLOTID) && CanUseImsService(SIM2_SLOTID, ImsServiceType::TYPE_UT)) {
        bool act = true;
        int32_t ret = telephonyService->SetCallWaiting(SIM2_SLOTID, act);
        EXPECT_EQ(ret, TELEPHONY_SUCCESS);
    }
}

/**
 * @tc.number   cellular_call_GetCallWaiting_0001
 * @tc.name     Test for GetCallWaiting function
 * @tc.desc     Function test
 */
HWTEST_F(ImsTest, cellular_call_GetCallWaiting_0001, Function | MediumTest | Level2)
{
    AccessToken token;
    auto systemAbilityMgr = SystemAbilityManagerClient::GetInstance().GetSystemAbilityManager();
    ASSERT_TRUE(systemAbilityMgr != nullptr);
    auto getCWRemote = systemAbilityMgr->CheckSystemAbility(TELEPHONY_CELLULAR_CALL_SYS_ABILITY_ID);
    ASSERT_TRUE(getCWRemote != nullptr);
    auto telephonyService = iface_cast<CellularCallInterface>(getCWRemote);
    ASSERT_TRUE(telephonyService != nullptr);
    if (!HasSimCard(SIM1_SLOTID) && !HasSimCard(SIM2_SLOTID)) {
        return;
    }
    if (HasSimCard(SIM1_SLOTID) && CanUseImsService(SIM2_SLOTID, ImsServiceType::TYPE_UT)) {
        int32_t ret = telephonyService->GetCallWaiting(SIM1_SLOTID);
        EXPECT_EQ(ret, TELEPHONY_SUCCESS);
    }
    if (HasSimCard(SIM2_SLOTID) && CanUseImsService(SIM2_SLOTID, ImsServiceType::TYPE_UT)) {
        int32_t ret = telephonyService->GetCallWaiting(SIM2_SLOTID);
        EXPECT_EQ(ret, TELEPHONY_SUCCESS);
    }
}

/**
 * @tc.number   cellular_call_SetCallRestriction_0001
 * @tc.name     Test for SetCallRestriction function
 * @tc.desc     Function test
 */
HWTEST_F(ImsTest, cellular_call_SetCallRestriction_0001, Function | MediumTest | Level2)
{
    AccessToken token;
    auto systemAbilityMgr = SystemAbilityManagerClient::GetInstance().GetSystemAbilityManager();
    ASSERT_TRUE(systemAbilityMgr != nullptr);
    auto setCRRemote = systemAbilityMgr->CheckSystemAbility(TELEPHONY_CELLULAR_CALL_SYS_ABILITY_ID);
    ASSERT_TRUE(setCRRemote != nullptr);
    auto telephonyService = iface_cast<CellularCallInterface>(setCRRemote);
    ASSERT_TRUE(telephonyService != nullptr);
    if (!HasSimCard(SIM1_SLOTID) && !HasSimCard(SIM2_SLOTID)) {
        return;
    }
    if (HasSimCard(SIM1_SLOTID) && CanUseImsService(SIM2_SLOTID, ImsServiceType::TYPE_UT)) {
        CallRestrictionInfo crInfo;
        int32_t ret = telephonyService->SetCallRestriction(SIM1_SLOTID, crInfo);
        EXPECT_NE(ret, TELEPHONY_SUCCESS);
    }
    if (HasSimCard(SIM2_SLOTID) && CanUseImsService(SIM2_SLOTID, ImsServiceType::TYPE_UT)) {
        CallRestrictionInfo crInfo;
        int32_t ret = telephonyService->SetCallRestriction(SIM2_SLOTID, crInfo);
        EXPECT_NE(ret, TELEPHONY_SUCCESS);
    }
}

/**
 * @tc.number   cellular_call_GetCallRestriction_0001
 * @tc.name     Test for GetCallRestriction function
 * @tc.desc     Function test
 */
HWTEST_F(ImsTest, cellular_call_GetCallRestriction_0001, Function | MediumTest | Level2)
{
    AccessToken token;
    auto systemAbilityMgr = SystemAbilityManagerClient::GetInstance().GetSystemAbilityManager();
    ASSERT_TRUE(systemAbilityMgr != nullptr);
    auto getCRRemote = systemAbilityMgr->CheckSystemAbility(TELEPHONY_CELLULAR_CALL_SYS_ABILITY_ID);
    ASSERT_TRUE(getCRRemote != nullptr);
    auto telephonyService = iface_cast<CellularCallInterface>(getCRRemote);
    ASSERT_TRUE(telephonyService != nullptr);
    if (!HasSimCard(SIM1_SLOTID) && !HasSimCard(SIM2_SLOTID)) {
        return;
    }
    if (HasSimCard(SIM1_SLOTID) && CanUseImsService(SIM2_SLOTID, ImsServiceType::TYPE_UT)) {
        CallRestrictionType facType = CallRestrictionType::RESTRICTION_TYPE_ALL_INCOMING;
        int32_t ret = telephonyService->GetCallRestriction(SIM1_SLOTID, facType);
        EXPECT_NE(ret, TELEPHONY_SUCCESS);
    }
    if (HasSimCard(SIM2_SLOTID) && CanUseImsService(SIM2_SLOTID, ImsServiceType::TYPE_UT)) {
        CallRestrictionType facType = CallRestrictionType::RESTRICTION_TYPE_ALL_INCOMING;
        int32_t ret = telephonyService->GetCallRestriction(SIM2_SLOTID, facType);
        EXPECT_NE(ret, TELEPHONY_SUCCESS);
    }
}

/**
 * @tc.number   cellular_call_SetCallTransferInfo_0001
 * @tc.name     Test for SetCallTransferInfo function
 * @tc.desc     Function test
 */
HWTEST_F(ImsTest, cellular_call_SetCallTransferInfo_0001, Function | MediumTest | Level2)
{
    AccessToken token;
    auto systemAbilityMgr = SystemAbilityManagerClient::GetInstance().GetSystemAbilityManager();
    ASSERT_TRUE(systemAbilityMgr != nullptr);
    auto setTransferRemote = systemAbilityMgr->CheckSystemAbility(TELEPHONY_CELLULAR_CALL_SYS_ABILITY_ID);
    ASSERT_TRUE(setTransferRemote != nullptr);
    auto telephonyService = iface_cast<CellularCallInterface>(setTransferRemote);
    ASSERT_TRUE(telephonyService != nullptr);
    if (!HasSimCard(SIM1_SLOTID) && !HasSimCard(SIM2_SLOTID)) {
        return;
    }
    if (HasSimCard(SIM1_SLOTID) && CanUseImsService(SIM2_SLOTID, ImsServiceType::TYPE_UT)) {
        CallTransferInfo ctInfo;
        int32_t ret = telephonyService->SetCallTransferInfo(SIM1_SLOTID, ctInfo);
        EXPECT_NE(ret, TELEPHONY_SUCCESS);
    }
    if (HasSimCard(SIM2_SLOTID) && CanUseImsService(SIM2_SLOTID, ImsServiceType::TYPE_UT)) {
        CallTransferInfo ctInfo;
        int32_t ret = telephonyService->SetCallTransferInfo(SIM2_SLOTID, ctInfo);
        EXPECT_NE(ret, TELEPHONY_SUCCESS);
    }
}

/**
 * @tc.number   cellular_call_GetCallTransferInfo_0001
 * @tc.name     Test for GetCallTransferInfo function
 * @tc.desc     Function test
 */
HWTEST_F(ImsTest, cellular_call_GetCallTransferInfo_0001, Function | MediumTest | Level2)
{
    AccessToken token;
    auto systemAbilityMgr = SystemAbilityManagerClient::GetInstance().GetSystemAbilityManager();
    ASSERT_TRUE(systemAbilityMgr != nullptr);
    auto getTransferRemote = systemAbilityMgr->CheckSystemAbility(TELEPHONY_CELLULAR_CALL_SYS_ABILITY_ID);
    ASSERT_TRUE(getTransferRemote != nullptr);
    auto telephonyService = iface_cast<CellularCallInterface>(getTransferRemote);
    ASSERT_TRUE(telephonyService != nullptr);
    if (!HasSimCard(SIM1_SLOTID) && !HasSimCard(SIM2_SLOTID)) {
        return;
    }
    if (HasSimCard(SIM1_SLOTID) && CanUseImsService(SIM2_SLOTID, ImsServiceType::TYPE_UT)) {
        CallTransferType type = CallTransferType::TRANSFER_TYPE_UNCONDITIONAL;
        int32_t ret = telephonyService->GetCallTransferInfo(SIM1_SLOTID, type);
        EXPECT_NE(ret, TELEPHONY_SUCCESS);
    }
    if (HasSimCard(SIM2_SLOTID) && CanUseImsService(SIM2_SLOTID, ImsServiceType::TYPE_UT)) {
        CallTransferType type = CallTransferType::TRANSFER_TYPE_UNCONDITIONAL;
        int32_t ret = telephonyService->GetCallTransferInfo(SIM2_SLOTID, type);
        EXPECT_NE(ret, TELEPHONY_SUCCESS);
    }
}

/**
 * @tc.number   cellular_call_ImsControl_0001
 * @tc.name     Test for ImsControl
 * @tc.desc     Function test
 */
HWTEST_F(ImsTest, cellular_call_ImsControl_0001, Function | MediumTest | Level3)
{
    AccessToken token;
    auto systemAbilityMgr = SystemAbilityManagerClient::GetInstance().GetSystemAbilityManager();
    ASSERT_TRUE(systemAbilityMgr != nullptr);
    auto imsControlRemote = systemAbilityMgr->CheckSystemAbility(TELEPHONY_CELLULAR_CALL_SYS_ABILITY_ID);
    ASSERT_TRUE(imsControlRemote != nullptr);
    if (!HasSimCard(SIM1_SLOTID) && !HasSimCard(SIM2_SLOTID)) {
        return;
    }
    auto imsControl = std::make_shared<IMSControl>();
    CellularCallInfo cellularCallInfo;
    for (int32_t slotId = 0; slotId < SIM_SLOT_COUNT; slotId++) {
        if (!HasSimCard(slotId) || !CanUseImsService(slotId, ImsServiceType::TYPE_VOICE)) {
            continue;
        }
        EXPECT_NE(imsControl->Answer(cellularCallInfo), TELEPHONY_SUCCESS);
        EXPECT_NE(imsControl->Reject(cellularCallInfo), TELEPHONY_SUCCESS);
        EXPECT_EQ(InitCellularCallInfo(slotId, PHONE_NUMBER, cellularCallInfo), TELEPHONY_SUCCESS);
        bool enabled = false;
        EXPECT_EQ(imsControl->Dial(cellularCallInfo, enabled), CALL_ERR_GET_RADIO_STATE_FAILED);
        CLIRMode mode = CLIRMode::DEFAULT;
        EXPECT_EQ(imsControl->DialJudgment(slotId, PHONE_NUMBER_SECOND, mode, 0), TELEPHONY_SUCCESS);
        EXPECT_EQ(imsControl->DialJudgment(slotId, PHONE_NUMBER_THIRD, mode, 0), TELEPHONY_SUCCESS);
        EXPECT_EQ(InitCellularCallInfo(slotId, PHONE_NUMBER_SECOND, cellularCallInfo), TELEPHONY_SUCCESS);
        EXPECT_NE(imsControl->Answer(cellularCallInfo), TELEPHONY_SUCCESS);
        EXPECT_EQ(InitCellularCallInfo(slotId, PHONE_NUMBER_THIRD, cellularCallInfo), TELEPHONY_SUCCESS);
        EXPECT_NE(imsControl->Answer(cellularCallInfo), TELEPHONY_SUCCESS);
        EXPECT_EQ(InitCellularCallInfo(slotId, PHONE_NUMBER_FOUR, cellularCallInfo), TELEPHONY_SUCCESS);
        EXPECT_NE(imsControl->Answer(cellularCallInfo), TELEPHONY_SUCCESS);
        EXPECT_NE(imsControl->Reject(cellularCallInfo), TELEPHONY_SUCCESS);
        EXPECT_EQ(imsControl->HoldCall(slotId), TELEPHONY_SUCCESS);
        std::vector<std::string> numberList;
        EXPECT_EQ(imsControl->KickOutFromConference(slotId, PHONE_NUMBER, cellularCallInfo.index), TELEPHONY_SUCCESS);
        EXPECT_EQ(imsControl->InviteToConference(slotId, numberList), TELEPHONY_SUCCESS);
        EXPECT_EQ(imsControl->StartRtt(slotId, PHONE_NUMBER), TELEPHONY_SUCCESS);
        EXPECT_EQ(imsControl->StopRtt(slotId), TELEPHONY_SUCCESS);
        EXPECT_NE(imsControl->HangUp(cellularCallInfo, CallSupplementType::TYPE_DEFAULT), TELEPHONY_SUCCESS);
        EXPECT_EQ(imsControl->HangUp(cellularCallInfo, CallSupplementType::TYPE_HANG_UP_ACTIVE),
            CALL_ERR_RESOURCE_UNAVAILABLE);
        EXPECT_EQ(imsControl->HangUp(cellularCallInfo, CallSupplementType::TYPE_HANG_UP_ALL), TELEPHONY_SUCCESS);
        EXPECT_EQ(imsControl->HangUp(cellularCallInfo, static_cast<CallSupplementType>(INVALID_HANG_UP_TYPE)),
            TELEPHONY_ERR_ARGUMENT_INVALID);
    }
}

/**
 * @tc.number   cellular_call_ImsControl_0002
 * @tc.name     Test for ImsControl
 * @tc.desc     Function test
 */
HWTEST_F(ImsTest, cellular_call_ImsControl_0002, Function | MediumTest | Level3)
{
    AccessToken token;
    auto imsControl = std::make_shared<IMSControl>();
    for (int32_t slotId = 0; slotId < SIM_SLOT_COUNT; slotId++) {
        if (!HasSimCard(slotId) || !CanUseImsService(slotId, ImsServiceType::TYPE_VOICE)) {
            continue;
        }
        ImsCurrentCallList callList;
        callList.callSize = 0;
        CallInfoList callInfoList;
        EXPECT_EQ(imsControl->ReportCallsData(slotId, callInfoList), TELEPHONY_ERROR);
        EXPECT_EQ(imsControl->ReportImsCallsData(slotId, callList), TELEPHONY_ERROR);
        EXPECT_NE(imsControl->ReportUpdateInfo(slotId, callList), TELEPHONY_SUCCESS);
        ImsCurrentCall callInfo;
        callList.callSize = 1;
        callInfo.number = PHONE_NUMBER;
        callInfo.index = 1;
        callInfo.state = static_cast<int32_t>(TelCallState::CALL_STATUS_INCOMING);
        callList.calls.push_back(callInfo);
        EXPECT_EQ(imsControl->ReportImsCallsData(slotId, callList), TELEPHONY_SUCCESS);
        EXPECT_EQ(imsControl->HangUpAllConnection(slotId), TELEPHONY_SUCCESS);
        callList.callSize = 2;
        callInfo.index = 2;
        callInfo.state = static_cast<int32_t>(TelCallState::CALL_STATUS_ACTIVE);
        callInfo.number = PHONE_NUMBER_SECOND;
        callList.calls.push_back(callInfo);
        callList.callSize = 3;
        callInfo.index = 3;
        callInfo.state = static_cast<int32_t>(TelCallState::CALL_STATUS_WAITING);
        callInfo.number = PHONE_NUMBER_THIRD;
        callList.calls.push_back(callInfo);
        callList.callSize = 4;
        callInfo.index = 4;
        callInfo.state = static_cast<int32_t>(TelCallState::CALL_STATUS_DISCONNECTED);
        callInfo.number = PHONE_NUMBER_FOUR;
        callList.calls.push_back(callInfo);
        EXPECT_EQ(imsControl->ReportImsCallsData(slotId, callList), TELEPHONY_SUCCESS);
        callList.callSize = 0;
        EXPECT_EQ(imsControl->ReportImsCallsData(slotId, callList), TELEPHONY_SUCCESS);
    }
}

/**
 * @tc.number   cellular_call_CellularCallConnectionIMS_0001
 * @tc.name     Test for CellularCallConnectionIMS
 * @tc.desc     Function test
 */
HWTEST_F(ImsTest, cellular_call_CellularCallConnectionIMS_0001, Function | MediumTest | Level3)
{
    AccessToken token;
    auto systemAbilityMgr = SystemAbilityManagerClient::GetInstance().GetSystemAbilityManager();
    ASSERT_TRUE(systemAbilityMgr != nullptr);
    auto remote = systemAbilityMgr->CheckSystemAbility(TELEPHONY_CELLULAR_CALL_SYS_ABILITY_ID);
    ASSERT_TRUE(remote != nullptr);
    if (!HasSimCard(SIM1_SLOTID) && !HasSimCard(SIM2_SLOTID)) {
        return;
    }
    for (int32_t slotId = 0; slotId < SIM_SLOT_COUNT; slotId++) {
        if (!HasSimCard(slotId) || !CanUseImsService(slotId, ImsServiceType::TYPE_VOICE)) {
            continue;
        }
        CellularCallConnectionIMS imsConnection;
        EXPECT_EQ(imsConnection.SendDtmfRequest(slotId, '1', 1), TELEPHONY_SUCCESS);
        EXPECT_EQ(imsConnection.StartDtmfRequest(slotId, '1', 1), TELEPHONY_SUCCESS);
        EXPECT_EQ(imsConnection.StopDtmfRequest(slotId, 1), TELEPHONY_SUCCESS);
        EXPECT_EQ(imsConnection.GetImsCallsDataRequest(slotId, 1), TELEPHONY_SUCCESS);
        EXPECT_EQ(imsConnection.GetCallFailReasonRequest(slotId), TELEPHONY_SUCCESS);
        EXPECT_EQ(imsConnection.AnswerRequest(slotId, PHONE_NUMBER, 0, slotId), TELEPHONY_SUCCESS);
        ImsDialInfoStruct imsDialInfo;
        imsDialInfo.phoneNum = PHONE_NUMBER_SECOND;
        EXPECT_EQ(imsConnection.DialRequest(slotId, imsDialInfo), TELEPHONY_SUCCESS);
        EXPECT_EQ(imsConnection.HangUpRequest(slotId, PHONE_NUMBER_SECOND, slotId), TELEPHONY_SUCCESS);
        EXPECT_EQ(imsConnection.StartRttRequest(slotId, PHONE_NUMBER_THIRD), TELEPHONY_SUCCESS);
        EXPECT_EQ(imsConnection.StopRttRequest(slotId), TELEPHONY_SUCCESS);
    }
}

/**
 * @tc.number   cellular_call_CellularCallRegister_0001
 * @tc.name     Test for CellularCallRegister
 * @tc.desc     Function test
 */
HWTEST_F(ImsTest, cellular_call_CellularCallRegister_0001, Function | MediumTest | Level3)
{
    auto systemAbilityMgr = SystemAbilityManagerClient::GetInstance().GetSystemAbilityManager();
    ASSERT_TRUE(systemAbilityMgr != nullptr);
    auto registerRemote = systemAbilityMgr->CheckSystemAbility(TELEPHONY_CELLULAR_CALL_SYS_ABILITY_ID);
    ASSERT_TRUE(registerRemote != nullptr);
    if (!HasSimCard(SIM1_SLOTID) && !HasSimCard(SIM2_SLOTID)) {
        return;
    }
    auto callRegister = DelayedSingleton<CellularCallRegister>::GetInstance();
    ASSERT_TRUE(callRegister != nullptr);
    GetImsConfigResponse imsConfigResponse;
    callRegister->ReportGetImsConfigResult(imsConfigResponse);
    callRegister->ReportSetImsConfigResult(RESULT);
    GetImsFeatureValueResponse imsFeatureValueResponse;
    callRegister->ReportGetImsFeatureResult(imsFeatureValueResponse);
    callRegister->ReportSetImsFeatureResult(RESULT);
    ImsCallModeReceiveInfo callModeInfo;
    callRegister->ReceiveUpdateCallMediaModeRequest(-1, callModeInfo);
    callRegister->ReceiveUpdateCallMediaModeResponse(-1, callModeInfo);
    ImsCallSessionEventInfo callSessionEventInfo;
    callRegister->HandleCallSessionEventChanged(callSessionEventInfo);
    ImsCallPeerDimensionsInfo callPeerDimensionsInfo;
    callRegister->HandlePeerDimensionsChanged(callPeerDimensionsInfo);
    ImsCallDataUsageInfo callDataUsageInfo;
    callRegister->HandleCallDataUsageChanged(callDataUsageInfo);
    CameraCapabilitiesInfo cameraCapabilitiesInfo;
    callRegister->HandleCameraCapabilitiesChanged(cameraCapabilitiesInfo);
}

/**
 * @tc.number   cellular_call_CellularCallRegister_0002
 * @tc.name     Test for CellularCallRegister
 * @tc.desc     Function test
 */
HWTEST_F(ImsTest, cellular_call_CellularCallRegister_0002, Function | MediumTest | Level3)
{
    auto systemAbilityMgr = SystemAbilityManagerClient::GetInstance().GetSystemAbilityManager();
    ASSERT_TRUE(systemAbilityMgr != nullptr);
    auto registerRemote = systemAbilityMgr->CheckSystemAbility(TELEPHONY_CELLULAR_CALL_SYS_ABILITY_ID);
    ASSERT_TRUE(registerRemote != nullptr);
    auto callRegister = DelayedSingleton<CellularCallRegister>::GetInstance();
    ASSERT_TRUE(callRegister != nullptr);
    GetImsConfigResponse imsConfigResponse;
    callRegister->ReportGetImsConfigResult(imsConfigResponse);
    callRegister->ReportSetImsConfigResult(RESULT);
    GetImsFeatureValueResponse imsFeatureValueResponse;
    callRegister->ReportGetImsFeatureResult(imsFeatureValueResponse);
    callRegister->ReportSetImsFeatureResult(RESULT);
    ImsCallModeReceiveInfo callModeInfo;
    callRegister->ReceiveUpdateCallMediaModeRequest(-1, callModeInfo);
    callRegister->ReceiveUpdateCallMediaModeResponse(-1, callModeInfo);
    ImsCallSessionEventInfo callSessionEventInfo;
    callRegister->HandleCallSessionEventChanged(callSessionEventInfo);
    ImsCallPeerDimensionsInfo callPeerDimensionsInfo;
    callRegister->HandlePeerDimensionsChanged(callPeerDimensionsInfo);
    ImsCallDataUsageInfo callDataUsageInfo;
    callRegister->HandleCallDataUsageChanged(callDataUsageInfo);
    CameraCapabilitiesInfo cameraCapabilitiesInfo;
    callRegister->HandleCameraCapabilitiesChanged(cameraCapabilitiesInfo);
}

/**
 * @tc.number   cellular_call_CellularCallConfig_0001
 * @tc.name     Test for CellularCallConfig
 * @tc.desc     Function test
 */
HWTEST_F(ImsTest, cellular_call_CellularCallConfig_0001, Function | MediumTest | Level3)
{
    if (!HasSimCard(SIM1_SLOTID) && !HasSimCard(SIM2_SLOTID)) {
        return;
    }

    for (int32_t slotId = 0; slotId < SIM_SLOT_COUNT; slotId++) {
        if (!HasSimCard(slotId)) {
            continue;
        }
        CellularCallConfig cellularCallConfig;
        ASSERT_TRUE(cellularCallConfig.GetImsSwitchOnByDefaultConfig(INVALID_SLOTID));
        ASSERT_TRUE(cellularCallConfig.GetImsSwitchOnByDefaultConfig(slotId));
        ASSERT_FALSE(cellularCallConfig.GethideImsSwitchConfig(INVALID_SLOTID));
        ASSERT_FALSE(cellularCallConfig.GethideImsSwitchConfig(slotId));
        ASSERT_FALSE(cellularCallConfig.GetvolteSupportedConfig(INVALID_SLOTID));
        ASSERT_FALSE(cellularCallConfig.GetvolteSupportedConfig(slotId));
        cellularCallConfig.GetNrModeSupportedListConfig(INVALID_SLOTID);
        cellularCallConfig.GetNrModeSupportedListConfig(slotId);
        ASSERT_FALSE(cellularCallConfig.GetVolteProvisioningSupportedConfig(INVALID_SLOTID));
        ASSERT_FALSE(cellularCallConfig.GetVolteProvisioningSupportedConfig(slotId));
        ASSERT_FALSE(cellularCallConfig.GetSsOverUtSupportedConfig(INVALID_SLOTID));
        ASSERT_FALSE(cellularCallConfig.GetSsOverUtSupportedConfig(slotId));
        ASSERT_FALSE(cellularCallConfig.GetImsGbaRequiredConfig(INVALID_SLOTID));
        ASSERT_FALSE(cellularCallConfig.GetImsGbaRequiredConfig(slotId));
        ASSERT_FALSE(cellularCallConfig.GetUtProvisioningSupportedConfig(INVALID_SLOTID));
        ASSERT_FALSE(cellularCallConfig.GetUtProvisioningSupportedConfig(slotId));
        ASSERT_TRUE(cellularCallConfig.GetImsPreferForEmergencyConfig(INVALID_SLOTID));
        ASSERT_TRUE(cellularCallConfig.GetImsPreferForEmergencyConfig(slotId));
        cellularCallConfig.GetCallWaitingServiceClassConfig(INVALID_SLOTID);
        cellularCallConfig.GetCallWaitingServiceClassConfig(slotId);
        cellularCallConfig.GetImsCallDisconnectResoninfoMappingConfig(INVALID_SLOTID);
        cellularCallConfig.GetImsCallDisconnectResoninfoMappingConfig(slotId);
        ASSERT_FALSE(cellularCallConfig.GetForceVolteSwitchOnConfig(INVALID_SLOTID));
        ASSERT_FALSE(cellularCallConfig.GetForceVolteSwitchOnConfig(slotId));
    }
}

/**
 * @tc.number   cellular_call_CellularCallConfig_0002
 * @tc.name     Test for CellularCallConfig
 * @tc.desc     Function test
 */
HWTEST_F(ImsTest, cellular_call_CellularCallConfig_0002, Function | MediumTest | Level3)
{
    for (int32_t slotId = 0; slotId < SIM_SLOT_COUNT; slotId++) {
        CellularCallConfig cellularCallConfig;
        ASSERT_TRUE(cellularCallConfig.GetImsSwitchOnByDefaultConfig(INVALID_SLOTID));
        ASSERT_TRUE(cellularCallConfig.GetImsSwitchOnByDefaultConfig(slotId));
        ASSERT_FALSE(cellularCallConfig.GethideImsSwitchConfig(INVALID_SLOTID));
        ASSERT_FALSE(cellularCallConfig.GethideImsSwitchConfig(slotId));
        ASSERT_FALSE(cellularCallConfig.GetvolteSupportedConfig(INVALID_SLOTID));
        ASSERT_FALSE(cellularCallConfig.GetvolteSupportedConfig(slotId));
        cellularCallConfig.GetNrModeSupportedListConfig(INVALID_SLOTID);
        cellularCallConfig.GetNrModeSupportedListConfig(slotId);
        ASSERT_FALSE(cellularCallConfig.GetVolteProvisioningSupportedConfig(INVALID_SLOTID));
        ASSERT_FALSE(cellularCallConfig.GetVolteProvisioningSupportedConfig(slotId));
        ASSERT_FALSE(cellularCallConfig.GetSsOverUtSupportedConfig(INVALID_SLOTID));
        ASSERT_FALSE(cellularCallConfig.GetSsOverUtSupportedConfig(slotId));
        ASSERT_FALSE(cellularCallConfig.GetImsGbaRequiredConfig(INVALID_SLOTID));
        ASSERT_FALSE(cellularCallConfig.GetImsGbaRequiredConfig(slotId));
        ASSERT_FALSE(cellularCallConfig.GetUtProvisioningSupportedConfig(INVALID_SLOTID));
        ASSERT_FALSE(cellularCallConfig.GetUtProvisioningSupportedConfig(slotId));
        ASSERT_TRUE(cellularCallConfig.GetImsPreferForEmergencyConfig(INVALID_SLOTID));
        ASSERT_TRUE(cellularCallConfig.GetImsPreferForEmergencyConfig(slotId));
        cellularCallConfig.GetCallWaitingServiceClassConfig(INVALID_SLOTID);
        cellularCallConfig.GetCallWaitingServiceClassConfig(slotId);
        cellularCallConfig.GetImsCallDisconnectResoninfoMappingConfig(INVALID_SLOTID);
        cellularCallConfig.GetImsCallDisconnectResoninfoMappingConfig(slotId);
        ASSERT_FALSE(cellularCallConfig.GetForceVolteSwitchOnConfig(INVALID_SLOTID));
        ASSERT_FALSE(cellularCallConfig.GetForceVolteSwitchOnConfig(slotId));
    }
}

/**
 * @tc.number   cellular_call_CellularCallHandler_0001
 * @tc.name     Test for CellularCallHandler
 * @tc.desc     Function test
 */
HWTEST_F(ImsTest, cellular_call_CellularCallHandler_0001, Function | MediumTest | Level3)
{
    EventFwk::MatchingSkills matchingSkills;
    matchingSkills.AddEvent(EventFwk::CommonEventSupport::COMMON_EVENT_OPERATOR_CONFIG_CHANGED);
    EventFwk::CommonEventSubscribeInfo subscriberInfo(matchingSkills);
    CellularCallHandler handler { subscriberInfo };
    if (!HasSimCard(SIM1_SLOTID) && !HasSimCard(SIM2_SLOTID)) {
        return;
    }
    for (int32_t slotId = 0; slotId < SIM_SLOT_COUNT; slotId++) {
        if (!HasSimCard(slotId)) {
            continue;
        }
        handler.SetSlotId(slotId);
        auto event = AppExecFwk::InnerEvent::Get(0);
        handler.GetImsCallsDataResponse(event);
        handler.GetImsCallsDataRequest(event);
        auto rilRadioResponse = std::make_shared<RadioResponseInfo>();
        rilRadioResponse->error = ErrType::ERR_GENERIC_FAILURE;
        auto responseEvent = AppExecFwk::InnerEvent::Get(0, rilRadioResponse);
        handler.SetDomainPreferenceModeResponse(responseEvent);
        handler.GetDomainPreferenceModeResponse(event);
        handler.SetDomainPreferenceModeResponse(event);
        handler.SetVoNRSwitchStatusResponse(responseEvent);
        ASSERT_EQ(handler.GetSlotId(), slotId);
        handler.OnRilAdapterHostDied(event);
        auto serviceInstance = DelayedSingleton<CellularCallService>::GetInstance();
        if (serviceInstance != nullptr) {
            std::shared_ptr<CSControl> csControl;
            serviceInstance->SetCsControl(slotId, csControl);
            std::shared_ptr<IMSControl> imsControl;
            serviceInstance->SetImsControl(slotId, imsControl);
            handler.OnRilAdapterHostDied(event);
            ASSERT_TRUE(serviceInstance->GetCsControl(slotId) == nullptr);
            ASSERT_TRUE(serviceInstance->GetCsControl(slotId) == nullptr);
        }
    }
}

/**
 * @tc.number   cellular_call_CellularCallHandler_0002
 * @tc.name     Test for CellularCallHandler
 * @tc.desc     Function test
 */
HWTEST_F(ImsTest, cellular_call_CellularCallHandler_0002, Function | MediumTest | Level3)
{
    EventFwk::MatchingSkills matchingSkills;
    matchingSkills.AddEvent(EventFwk::CommonEventSupport::COMMON_EVENT_OPERATOR_CONFIG_CHANGED);
    EventFwk::CommonEventSubscribeInfo subscriberInfo(matchingSkills);
    CellularCallHandler handler { subscriberInfo };
    if (!HasSimCard(SIM1_SLOTID) && !HasSimCard(SIM2_SLOTID)) {
        return;
    }
    for (int32_t slotId = 0; slotId < SIM_SLOT_COUNT; slotId++) {
        if (!HasSimCard(slotId)) {
            continue;
        }
        handler.SetSlotId(slotId);
        auto event = AppExecFwk::InnerEvent::Get(0);
        handler.ReceiveUpdateCallMediaModeRequest(event);
        handler.ReceiveUpdateCallMediaModeResponse(event);
        handler.HandleCallSessionEventChanged(event);
        handler.HandlePeerDimensionsChanged(event);
        handler.HandleCallDataUsageChanged(event);
        handler.HandleCameraCapabilitiesChanged(event);
    }
}

/**
 * @tc.number   cellular_call_CellularCallHandler_0003
 * @tc.name     Test for CellularCallHandler
 * @tc.desc     Function test
 */
HWTEST_F(ImsTest, cellular_call_CellularCallHandler_0003, Function | MediumTest | Level3)
{
    EventFwk::MatchingSkills matchingSkills;
    matchingSkills.AddEvent(EventFwk::CommonEventSupport::COMMON_EVENT_OPERATOR_CONFIG_CHANGED);
    EventFwk::CommonEventSubscribeInfo subscriberInfo(matchingSkills);
    CellularCallHandler handler { subscriberInfo };
    for (int32_t slotId = 0; slotId < SLOT_COUNT; slotId++) {
        handler.SetSlotId(slotId);
        auto event = AppExecFwk::InnerEvent::Get(0);
        handler.GetImsCallsDataResponse(event);
        handler.GetImsCallsDataRequest(event);
        auto rilRadioResponse = std::make_shared<RadioResponseInfo>();
        rilRadioResponse->error = ErrType::ERR_GENERIC_FAILURE;
        auto responseEvent = AppExecFwk::InnerEvent::Get(0, rilRadioResponse);
        handler.SetDomainPreferenceModeResponse(responseEvent);
        handler.GetDomainPreferenceModeResponse(event);
        handler.SetDomainPreferenceModeResponse(event);
        handler.SetVoNRSwitchStatusResponse(responseEvent);
        ASSERT_EQ(handler.GetSlotId(), slotId);
        handler.OnRilAdapterHostDied(event);
        auto serviceInstance = DelayedSingleton<CellularCallService>::GetInstance();
        if (serviceInstance != nullptr) {
            std::shared_ptr<CSControl> csControl;
            serviceInstance->SetCsControl(slotId, csControl);
            std::shared_ptr<IMSControl> imsControl;
            serviceInstance->SetImsControl(slotId, imsControl);
            handler.OnRilAdapterHostDied(event);
            ASSERT_TRUE(serviceInstance->GetCsControl(slotId) == nullptr);
            ASSERT_TRUE(serviceInstance->GetCsControl(slotId) == nullptr);
        }
    }
}

/**
 * @tc.number   cellular_call_CellularCallHandler_0004
 * @tc.name     Test for CellularCallHandler
 * @tc.desc     Function test
 */
HWTEST_F(ImsTest, cellular_call_CellularCallHandler_0004, Function | MediumTest | Level3)
{
    EventFwk::MatchingSkills matchingSkills;
    matchingSkills.AddEvent(EventFwk::CommonEventSupport::COMMON_EVENT_OPERATOR_CONFIG_CHANGED);
    EventFwk::CommonEventSubscribeInfo subscriberInfo(matchingSkills);
    CellularCallHandler handler { subscriberInfo };
    for (int32_t slotId = 0; slotId < SLOT_COUNT; slotId++) {
        handler.SetSlotId(slotId);
        auto event = AppExecFwk::InnerEvent::Get(0);
        handler.ReceiveUpdateCallMediaModeRequest(event);
        handler.ReceiveUpdateCallMediaModeResponse(event);
        handler.HandleCallSessionEventChanged(event);
        handler.HandlePeerDimensionsChanged(event);
        handler.HandleCallDataUsageChanged(event);
        handler.HandleCameraCapabilitiesChanged(event);
        ASSERT_EQ(handler.GetSlotId(), slotId);
    }
}

/**
 * @tc.number   cellular_call_ImsCallClient_0001
 * @tc.name     test for ImsCallClient
 * @tc.desc     Function test
 */
HWTEST_F(ImsTest, cellular_call_ImsCallClient_0001, Function | MediumTest | Level3)
{
    ImsCallClient::SystemAbilityListener listen;
    int32_t systemAbilityId = 1;
    std::string deviceId = "123";
    listen.OnAddSystemAbility(systemAbilityId, deviceId);
    listen.OnRemoveSystemAbility(systemAbilityId, deviceId);
    listen.OnAddSystemAbility(COMMON_EVENT_SERVICE_ID, deviceId);
    listen.OnRemoveSystemAbility(COMMON_EVENT_SERVICE_ID, deviceId);
}
} // namespace Telephony
} // namespace OHOS