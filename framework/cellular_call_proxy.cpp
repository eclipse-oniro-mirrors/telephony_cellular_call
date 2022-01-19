/*
 * Copyright (C) 2021 Huawei Device Co., Ltd.
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

#include "cellular_call_proxy.h"

namespace OHOS {
namespace Telephony {
int32_t CellularCallProxy::Dial(const CellularCallInfo &callInfo)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteRawData((const void *)&callInfo, sizeof(CellularCallInfo))) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error = Remote()->SendRequest(static_cast<uint32_t>(OperationType::DIAL), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::HangUp(const CellularCallInfo &callInfo, CallSupplementType type)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteRawData((const void *)&callInfo, sizeof(CellularCallInfo))) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32((int32_t)type)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }

    int32_t error = Remote()->SendRequest(static_cast<uint32_t>(OperationType::HANG_UP), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::Reject(const CellularCallInfo &callInfo)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteRawData((const void *)&callInfo, sizeof(CellularCallInfo))) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error = Remote()->SendRequest(static_cast<uint32_t>(OperationType::REJECT), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::Answer(const CellularCallInfo &callInfo)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteRawData((const void *)&callInfo, sizeof(CellularCallInfo))) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error = Remote()->SendRequest(static_cast<uint32_t>(OperationType::ANSWER), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::HoldCall(const CellularCallInfo &callInfo)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteRawData((const void *)&callInfo, sizeof(CellularCallInfo))) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error = Remote()->SendRequest(static_cast<uint32_t>(OperationType::HOLD_CALL), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::UnHoldCall(const CellularCallInfo &callInfo)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteRawData((const void *)&callInfo, sizeof(CellularCallInfo))) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error = Remote()->SendRequest(static_cast<uint32_t>(OperationType::UN_HOLD_CALL), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::SwitchCall(const CellularCallInfo &callInfo)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteRawData((const void *)&callInfo, sizeof(CellularCallInfo))) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error = Remote()->SendRequest(static_cast<uint32_t>(OperationType::SWITCH_CALL), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::RegisterCallManagerCallBack(const sptr<ICallStatusCallback> &callback)
{
    if (callback == nullptr) {
        return TELEPHONY_ERR_ARGUMENT_INVALID;
    }

    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteRemoteObject(callback->AsObject().GetRefPtr())) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }

    int32_t error = Remote()->SendRequest(static_cast<uint32_t>(OperationType::REGISTER_CALLBACK), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::UnRegisterCallManagerCallBack()
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error = Remote()->SendRequest(static_cast<uint32_t>(OperationType::UNREGISTER_CALLBACK), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::IsEmergencyPhoneNumber(int32_t slotId, const std::string &phoneNum, int32_t &errorCode)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(slotId)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteString(phoneNum)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(errorCode)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t ret = Remote()->SendRequest(static_cast<uint32_t>(OperationType::EMERGENCY_CALL), in, out, option);
    if (ret == ERR_NONE) {
        ret = out.ReadInt32();
        errorCode = out.ReadInt32();
    }
    return ret;
}

int32_t CellularCallProxy::CombineConference(const CellularCallInfo &callInfo)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteRawData((const void *)&callInfo, sizeof(CellularCallInfo))) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error = Remote()->SendRequest(static_cast<uint32_t>(OperationType::COMBINE_CONFERENCE), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::SeparateConference(const CellularCallInfo &callInfo)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteRawData((const void *)&callInfo, sizeof(CellularCallInfo))) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error = Remote()->SendRequest(static_cast<uint32_t>(OperationType::SEPARATE_CONFERENCE), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::InviteToConference(int32_t slotId, const std::vector<std::string> &numberList)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(slotId)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteStringVector(numberList)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error = Remote()->SendRequest(static_cast<uint32_t>(OperationType::INVITE_TO_CONFERENCE), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::KickOutFromConference(int32_t slotId, const std::vector<std::string> &numberList)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(slotId)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteStringVector(numberList)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error = Remote()->SendRequest(static_cast<uint32_t>(OperationType::KICK_OUT_CONFERENCE), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::HangUpAllConnection()
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error =
        Remote()->SendRequest(static_cast<uint32_t>(OperationType::HANG_UP_ALL_CONNECTION), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::UpdateImsCallMode(const CellularCallInfo &callInfo, ImsCallMode mode)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteRawData((const void *)&callInfo, sizeof(CellularCallInfo))) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32((int32_t)mode)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error =
        Remote()->SendRequest(static_cast<uint32_t>(OperationType::UPDATE_CALL_MEDIA_MODE), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::StartDtmf(char cDtmfCode, const CellularCallInfo &callInfo)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteCString(&cDtmfCode)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteRawData((const void *)&callInfo, sizeof(CellularCallInfo))) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error = Remote()->SendRequest(static_cast<uint32_t>(OperationType::START_DTMF), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::StopDtmf(const CellularCallInfo &callInfo)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteRawData((const void *)&callInfo, sizeof(CellularCallInfo))) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error = Remote()->SendRequest(static_cast<uint32_t>(OperationType::STOP_DTMF), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::SendDtmf(char cDtmfCode, const CellularCallInfo &callInfo)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteCString(&cDtmfCode)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteRawData((const void *)&callInfo, sizeof(CellularCallInfo))) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error = Remote()->SendRequest(static_cast<uint32_t>(OperationType::SEND_DTMF), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::StartRtt(int32_t slotId, const std::string &msg)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(slotId)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteString(msg)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error = Remote()->SendRequest(static_cast<uint32_t>(OperationType::START_RTT), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::StopRtt(int32_t slotId)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(slotId)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error = Remote()->SendRequest(static_cast<uint32_t>(OperationType::STOP_RTT), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::SetCallTransferInfo(int32_t slotId, const CallTransferInfo &ctInfo)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(slotId)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteRawData((const void *)&ctInfo, sizeof(CallTransferInfo))) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error = Remote()->SendRequest(static_cast<uint32_t>(OperationType::SET_CALL_TRANSFER), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::GetCallTransferInfo(int32_t slotId, CallTransferType type)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(slotId)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32((int32_t)type)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error = Remote()->SendRequest(static_cast<uint32_t>(OperationType::GET_CALL_TRANSFER), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::SetCallWaiting(int32_t slotId, bool activate)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(slotId)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteBool(activate)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error = Remote()->SendRequest(static_cast<uint32_t>(OperationType::SET_CALL_WAITING), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::GetCallWaiting(int32_t slotId)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(slotId)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error = Remote()->SendRequest(static_cast<uint32_t>(OperationType::GET_CALL_WAITING), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::SetCallRestriction(int32_t slotId, const CallRestrictionInfo &crInfo)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(slotId)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteRawData((const void *)&crInfo, sizeof(CallRestrictionInfo))) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error = Remote()->SendRequest(static_cast<uint32_t>(OperationType::SET_CALL_RESTRICTION), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::GetCallRestriction(int32_t slotId, CallRestrictionType facType)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(slotId)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32((int32_t)facType)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error = Remote()->SendRequest(static_cast<uint32_t>(OperationType::GET_CALL_RESTRICTION), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::SetDomainPreferenceMode(int32_t slotId, int32_t mode)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(slotId)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(mode)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error =
        Remote()->SendRequest(static_cast<uint32_t>(OperationType::SET_DOMAIN_PREFERENCE_MODE), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::GetDomainPreferenceMode(int32_t slotId)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(slotId)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error =
        Remote()->SendRequest(static_cast<uint32_t>(OperationType::GET_DOMAIN_PREFERENCE_MODE), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::SetLteImsSwitchStatus(int32_t slotId, bool active)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(slotId)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteBool(active)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error =
        Remote()->SendRequest(static_cast<uint32_t>(OperationType::SET_LTE_IMS_SWITCH_STATUS), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::GetLteImsSwitchStatus(int32_t slotId)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(slotId)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error =
        Remote()->SendRequest(static_cast<uint32_t>(OperationType::GET_LTE_IMS_SWITCH_STATUS), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::SetImsConfig(int32_t slotId, ImsConfigItem item, const std::string &value)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(slotId)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(item)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteString(value)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error =
        Remote()->SendRequest(static_cast<uint32_t>(OperationType::SET_IMS_CONFIG_STRING), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::SetImsConfig(int32_t slotId, ImsConfigItem item, int32_t value)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(slotId)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(item)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(value)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error = Remote()->SendRequest(static_cast<uint32_t>(OperationType::SET_IMS_CONFIG_INT), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::GetImsConfig(int32_t slotId, ImsConfigItem item)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(slotId)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(item)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error = Remote()->SendRequest(static_cast<uint32_t>(OperationType::GET_IMS_CONFIG), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::SetImsFeatureValue(int32_t slotId, FeatureType type, int32_t value)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(slotId)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(type)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(value)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error = Remote()->SendRequest(static_cast<uint32_t>(OperationType::SET_IMS_FEATURE), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::GetImsFeatureValue(int32_t slotId, FeatureType type)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(slotId)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(type)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error = Remote()->SendRequest(static_cast<uint32_t>(OperationType::GET_IMS_FEATURE), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::SetImsSwitchEnhanceMode(int32_t slotId, bool value)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(slotId)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteBool(value)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error =
        Remote()->SendRequest(static_cast<uint32_t>(OperationType::SET_IMS_SWITCH_ENHANCE_MODE), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::GetImsSwitchEnhanceMode(int32_t slotId)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(slotId)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error =
        Remote()->SendRequest(static_cast<uint32_t>(OperationType::GET_IMS_SWITCH_ENHANCE_MODE), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::CtrlCamera(const std::u16string &cameraId, int32_t callingUid, int32_t callingPid)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteString16(cameraId)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(callingUid)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(callingPid)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error = Remote()->SendRequest(static_cast<uint32_t>(OperationType::CTRL_CAMERA), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::SetPreviewWindow(int32_t x, int32_t y, int32_t z, int32_t width, int32_t height)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(x)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(y)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(z)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(width)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(height)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error = Remote()->SendRequest(static_cast<uint32_t>(OperationType::SET_PREVIEW_WINDOW), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::SetDisplayWindow(int32_t x, int32_t y, int32_t z, int32_t width, int32_t height)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(x)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(y)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(z)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(width)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(height)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error = Remote()->SendRequest(static_cast<uint32_t>(OperationType::SET_DISPLAY_WINDOW), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::SetCameraZoom(float zoomRatio)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteFloat(zoomRatio)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error = Remote()->SendRequest(static_cast<uint32_t>(OperationType::SET_CAMERA_ZOOM), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::SetPauseImage(const std::u16string &path)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteString16(path)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error = Remote()->SendRequest(static_cast<uint32_t>(OperationType::SET_PAUSE_IMAGE), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::SetDeviceDirection(int32_t rotation)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(rotation)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error = Remote()->SendRequest(static_cast<uint32_t>(OperationType::SET_DEVICE_DIRECTION), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::SetMute(int32_t slotId, int32_t mute)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(slotId)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(mute)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error = Remote()->SendRequest(static_cast<uint32_t>(OperationType::SET_MUTE), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}

int32_t CellularCallProxy::GetMute(int32_t slotId)
{
    MessageOption option;
    MessageParcel in;
    MessageParcel out;
    if (!in.WriteInterfaceToken(CellularCallProxy::GetDescriptor())) {
        return TELEPHONY_ERR_WRITE_DESCRIPTOR_TOKEN_FAIL;
    }
    if (!in.WriteInt32(MAX_SIZE)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    if (!in.WriteInt32(slotId)) {
        return TELEPHONY_ERR_WRITE_DATA_FAIL;
    }
    int32_t error = Remote()->SendRequest(static_cast<uint32_t>(OperationType::GET_MUTE), in, out, option);
    if (error == ERR_NONE) {
        return out.ReadInt32();
    }
    return error;
}
} // namespace Telephony
} // namespace OHOS