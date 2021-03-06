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
 * - Christophe Riccio <christophe@lunarg.com>
 */

#include "platform.h"
#include "util.h"

const char* GetToken(StatusType type) {
    static const char* table[] = {
        "STABLE",  // STATUS_STABLE
        "BETA",    // STATUS_BETA
        "ALPHA"    // STATUS_ALPHA
    };
    static_assert(countof(table) == STATUS_COUNT, "The tranlation table size doesn't match the enum number of elements");

    return table[type];
}

StatusType GetStatusType(const char* token) {
    for (std::size_t i = 0, n = STATUS_COUNT; i < n; ++i) {
        const StatusType status_type = static_cast<StatusType>(i);
        if (strcmp(GetToken(status_type), token) == 0) return status_type;
    }

    assert(0);
    return static_cast<StatusType>(-1);
}

const char* GetPlatformString(PlatformString platform_string) {
    static const char* table[][PLATFORM_COUNT] = {
        {
            // PLATFORM_STRING_OS
            "windows",  // PLATFORM_WINDOWS
            "linux",    // PLATFORM_LINUX
            "mac"       // PLATFORM_MACOS
        },
        {
            // PLATFORM_STRING_APP_SUFFIX
            ".exe",  // PLATFORM_WINDOWS
            "",      // PLATFORM_LINUX
            ".app"   // PLATFORM_MACOS
        },
        {
            // PLATFORM_STRING_EXE_SUFFIX
            ".exe",  // PLATFORM_WINDOWS
            "",      // PLATFORM_LINUX
            ""       // PLATFORM_MACOS
        },
        {
            // PLATFORM_STRING_SEPARATOR
            ";",  // PLATFORM_WINDOWS
            ":",  // PLATFORM_LINUX
            ":"   // PLATFORM_MACOS
        },
        {
            // PLATFORM_STRING_FILTER
            "Applications (*.exe)",    // PLATFORM_WINDOWS
            "Applications (*)",        // PLATFORM_LINUX
            "Applications (*.app, *)"  // PLATFORM_MACOS
        },
        {
            // PLATFORM_STRING_VULKAN_INFO
            "vulkaninfoSDK",              // PLATFORM_WINDOWS
            "vulkaninfo",                 // PLATFORM_LINUX
            "/usr/local/bin/vulkaninfo",  // PLATFORM_MACOS
        },
        {
            // PLATFORM_STRING_VULKAN_LIBRARY
            "vulkan-1.dll",              // PLATFORM_WINDOWS
            "libvulkan",                 // PLATFORM_LINUX
            "/usr/local/lib/libvulkan",  // PLATFORM_MACOS
        },
        {
            // PLATFORM_STRING_PATH_CONFIGURATION
            "/AppData/Local/LunarG/vkconfig",         // PLATFORM_WINDOWS
            "/.local/share/vulkan/lunarg-vkconfig/",  // PLATFORM_LINUX
            "/.local/share/vulkan/lunarg-vkconfig/"   // PLATFORM_MACOS
        },
        {
            // PLATFORM_STRING_PATH_OVERRIDE_LAYERS
            "/AppData/Local/LunarG/vkconfig/override",  // PLATFORM_WINDOWS
            "/.local/share/vulkan/implicit_layer.d",    // PLATFORM_LINUX
            "/.local/share/vulkan/implicit_layer.d"     // PLATFORM_MACOS
        },
        {
            // PLATFORM_STRING_PATH_OVERRIDE_SETTINGS
            "/AppData/Local/LunarG/vkconfig/override",  // PLATFORM_WINDOWS
            "/.local/share/vulkan/settings.d",          // PLATFORM_LINUX
            "/.local/share/vulkan/settings.d"           // PLATFORM_MACOS
        },
    };
    static_assert(countof(table) == PLATFORM_STRING_COUNT, "The tranlation table size doesn't match the enum number of elements");

    return table[platform_string][VKC_PLATFORM];
}
