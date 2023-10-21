/*
 * Copyright (C) 2023 Huawei Device Co., Ltd.
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

#ifndef CELLULAR_CALL_RDB_HELPER_H
#define CELLULAR_CALL_RDB_HELPER_H

#include <memory>
#include <singleton.h>
#include <utility>

#include "datashare_helper.h"
#include "datashare_predicates.h"
#include "datashare_result_set.h"
#include "datashare_values_bucket.h"
#include "iservice_registry.h"
#include "refbase.h"
#include "system_ability_definition.h"
#include "uri.h"

#include "global_params_data.h"

namespace OHOS {
namespace Telephony {
class CellularCallRdbHelper : public DelayedSingleton<CellularCallRdbHelper> {
    DECLARE_DELAYED_SINGLETON(CellularCallRdbHelper);

public:
    int32_t QueryEccList(const std::string &numeric, std::vector<EccNum> &eccVec);

private:
    std::shared_ptr<DataShare::DataShareHelper> CreateDataAbilityHelper();

private:
    Uri globalEccUri_;
};
} // namespace Telephony
} // namespace OHOS
#endif // CELLULAR_DATA_RDB_HELPER_H
