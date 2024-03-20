#pragma once
#include "../defs/all.h"
#include <Geode/modify/LevelTools.hpp>

class $modify(HookedLevelTools, LevelTools) {
    $override
    static bool verifyLevelIntegrity(gd::string levelString, int levelID);

    $override
    static gd::string getAudioTitle(int audioID);

    $override
    static gd::string getAudioFileName(int audioID);

    $override
    static gd::string getAudioString(int audioID);

    $override
    static GJGameLevel* getLevel(int levelID, bool _save);

    static void setDifficulty(GJGameLevel* level, int stars, GJDifficulty difficulty);
};