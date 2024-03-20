#pragma once
#include "../defs/all.h"
#include <Geode/modify/LocalLevelManager.hpp>

class $modify(HookedLocalLevelManager, LocalLevelManager) {
protected:
    CCDictionary* m_lunarLevels;
public:
    $override
    gd::string getMainLevelString(int id);
};