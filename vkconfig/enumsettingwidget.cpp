/*
 * Copyright (c) 2020 Valve Corporation
 * Copyright (c) 2020 LunarG, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Authors:
 * - Richard S. Wright Jr.
 * - Christophe Riccio
 */

#include "enumsettingwidget.h"

#include <cassert>

EnumSettingWidget::EnumSettingWidget(QTreeWidgetItem* item, LayerSetting& layer_setting) : _layer_setting(layer_setting) {
    assert(item);
    assert(&layer_setting);

    item->setText(0, layer_setting.label);
    item->setToolTip(0, layer_setting.description);

    int selection = 0;
    for (int i = 0; i < layer_setting.exclusive_labels.size(); i++) {
        this->addItem(layer_setting.exclusive_labels[i]);
        if (layer_setting.exclusive_values[i] == layer_setting.value) selection = i;
    }

    setCurrentIndex(selection);

    connect(this, SIGNAL(currentIndexChanged(int)), this, SLOT(indexChanged(int)));
}

void EnumSettingWidget::indexChanged(int index) {
    _layer_setting.value = _layer_setting.exclusive_values[index];
    emit itemChanged();
}
