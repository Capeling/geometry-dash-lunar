#include "HookedGameManager.h"

CCTexture2D* HookedGameManager::loadIcon(int p0, int p1, int p2) {
    //log::info("loadIcon({}, {}, {})", p0, p1, p2);
    return GameManager::loadIcon(p0, p1, p2);
}

gd::string HookedGameManager::sheetNameForIcon(int iconID, int iconType) {
    //log::info("sheet: {}, {}; result: {}", iconID, iconType, GameManager::sheetNameForIcon(iconID, iconType));
    auto result = GameManager::sheetNameForIcon(iconID, iconType);
    bool isReplaced = iconID == 7 || iconID == 5 || iconID == 6;
    if(isReplaced && iconType == 0) {
        result = fmt::format("player_05");
        result = Mod::get()->expandSpriteName(result.c_str());
    }
    //log::info("result: {}", result);
    return GameManager::sheetNameForIcon(iconID, iconType);
}

