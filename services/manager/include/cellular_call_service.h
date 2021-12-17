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

#ifndef CELLULAR_CALL_SERVICE_H
#define CELLULAR_CALL_SERVICE_H

#include <memory>

#include "singleton.h"
#include "event_runner.h"
#include "iremote_broker.h"
#include "system_ability.h"

#include "cellular_call_handler.h"
#include "cellular_call_stub.h"

namespace OHOS {
namespace Telephony {
enum class ServiceRunningState { STATE_STOPPED, STATE_RUNNING };

class CellularCallService : public SystemAbility,
                            public CellularCallStub,
                            public std::enable_shared_from_this<CellularCallService> {
    DECLARE_DELAYED_SINGLETON(CellularCallService)
    DECLEAR_SYSTEM_ABILITY(CellularCallService)

public:
    /**
     * service OnStart
     */
    void OnStart() override;

    /**
     * service OnStop
     */
    void OnStop() override;

    /**
     * service dump
     *
     * @param fd
     * @param args
     * @return
     */
    int32_t Dump(std::int32_t fd, const std::vector<std::u16string> &args) override;

    /**
     * RegisterHandler
     */
    void RegisterHandler();

    /**
     * Get Handler
     * @return CellularCallHandler
     */
    std::shared_ptr<CellularCallHandler> GetHandler(int32_t slot);

    /**
     * Get bindTime_
     * @return int64_t
     */
    std::string GetBindTime();

    /**
     * Get GetEndTime
     * @return int64_t
     */
    std::string GetEndTime();

    /**
     * Get GetSpendTime
     * @return int64_t
     */
    std::string GetSpendTime();

private:
    /**
     * Init service
     * @return whether init success
     */
    bool Init();

    /**
     * Register Handler
     */
    void RegisterCoreServiceHandler();

    /**
     * Create Handler
     */
    void CreateHandler();

    /**
     * Handler Reset UnRegister
     */
    void HandlerResetUnRegister();

    /**
     * SendEventRegisterHandler
     */
    void SendEventRegisterHandler();

private:
    const uint32_t CONNECT_MAX_TRY_COUNT = 20;
    const uint32_t CONNECT_SERVICE_WAIT_TIME = 2000; // ms
    int64_t bindTime_ = 0L;
    int64_t endTime_ = 0L;
    int64_t spendTime_ = 0L;
    ServiceRunningState state_;
    std::shared_ptr<AppExecFwk::EventRunner> eventLoop_;
    static constexpr HiviewDFX::HiLogLabel LOG_LABEL = {LOG_CORE, LOG_DOMAIN, "CellularCallService"};
};
} // namespace Telephony
} // namespace OHOS

#endif // CELLULAR_CALL_SERVICE_H
