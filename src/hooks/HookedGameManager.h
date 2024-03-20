#pragma once
#include "../defs/all.h"
#include <Geode/modify/GameManager.hpp>

class $modify(HookedGameManager, GameManager) {
    $override
    CCTexture2D* loadIcon(int p0, int p1, int p2);

    $override
    gd::string sheetNameForIcon(int p0, int p1);
};