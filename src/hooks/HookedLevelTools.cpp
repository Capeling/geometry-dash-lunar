#include "HookedLevelTools.h"

bool HookedLevelTools::verifyLevelIntegrity(gd::string verifyString, int levelID) {
    bool isValid = false;
    switch(levelID) {
        case 1:
            if(verifyString.size() == 1029093) isValid = true;
            break;
        case 2:
            if(verifyString.size() == 2161744) isValid = true;
            break;
        case 3:
            if(verifyString.size() == 3873233) isValid = true;
            break;
        case 4:
            if(verifyString.size() == 4414142) isValid = true;
            break;
        default:
            break;
    }
    return isValid;
}

gd::string HookedLevelTools::getAudioTitle(int audioID) {
    switch(audioID) {
        case 40: return "Active";
        case 41: return "ThunderZone";
        case 42: return "Earthsplitter";
        case 43: return "Space Battle";
        default: return LevelTools::getAudioTitle(audioID);
    }
}

gd::string HookedLevelTools::getAudioFileName(int audioID) {
    bool noCopyright = Mod::get()->getSettingValue<bool>("nocopyright");
    gd::string active = noCopyright ? "ActiveRemix.mp3"_spr : "Active.mp3"_spr;
    gd::string thunderZone = noCopyright ? "ThunderZoneRemix.mp3"_spr : "ThunderZone.mp3"_spr;
    gd::string earthSplitter = noCopyright ? "EarthSplitterRemix.mp3"_spr : "EarthSplitter.mp3"_spr;
    gd::string spaceBattle = noCopyright ? "SpaceBattleRemix.mp3"_spr : "SpaceBattle.mp3"_spr;
    switch(audioID) {
        case 40: return active;
        case 41: return thunderZone;
        case 42: return earthSplitter;
        case 43: return spaceBattle;
        default: return LevelTools::getAudioFileName(audioID);
    }
}

gd::string HookedLevelTools::getAudioString(int audioID) {
    log::info("audioID: {}", audioID);
    return LevelTools::getAudioString(audioID);
}

gd::string HookedLevelTools::nameForArtist(int artistID) {
    switch(artistID) {
        case 12: return "Xtrullor";
        default: return LevelTools::nameForArtist(artistID);
    }
}

gd::string HookedLevelTools::urlForAudio(int audioID) {
    switch(audioID) {
        case 40: return "https://www.youtube.com/watch?v=_8cfes15DIk";
        case 41: return "https://www.youtube.com/watch?v=oIu1o536GmI";
        case 42: return "https://www.youtube.com/watch?v=sGF4mH4MeDo";
        case 43: return "https://www.youtube.com/watch?v=aZ5rMQIu1gc";
        default: return LevelTools::urlForAudio(audioID);
    }
}

gd::string HookedLevelTools::ngURLForArtist(int artistID) {
    switch(artistID) {
        case 12: return "https://xtrullor.newgrounds.com/";
        default: return LevelTools::ngURLForArtist(artistID);
    }
}

gd::string HookedLevelTools::ytURLForArtist(int artistID) {
    switch(artistID) {
        case 12: return "https://www.youtube.com/@xtrullor";
        default: return LevelTools::ytURLForArtist(artistID);
    }
}

gd::string HookedLevelTools::fbURLForArtist(int artistID) {
    switch(artistID) {
        case 12: return "https://www.facebook.com/xtrullorofficial/";
        default: return LevelTools::fbURLForArtist(artistID);
    }
}

int HookedLevelTools::artistForAudio(int audioID) {
    switch(audioID) {
        case 40: return 0;
        case 41: return 1;
        case 42: return 12;
        case 43: return 6;
        default: return LevelTools::artistForAudio(audioID);
    }
}

GJGameLevel* HookedLevelTools::getLevel(int levelID, bool _save) {
    GJGameLevel* level = GJGameLevel::create();

    switch(levelID) {
        case 1: 
            setLevelInfo(level, 2, GJDifficulty::Hard, 0, 16328); //active
            level->m_levelName = getAudioTitle(40);
            level->m_audioTrack = 40;
            level->m_coins = 3;
            break;
        case 2:
            setLevelInfo(level, 3, GJDifficulty::Hard, 0, 16965); //thunderzone
            level->m_levelName = getAudioTitle(41);
            level->m_audioTrack = 41;
            level->m_coins = 3;
            break;
        case 3:
            setLevelInfo(level, 4, GJDifficulty::Harder, 0, 19858); //earthsplitter
            level->m_levelName = getAudioTitle(42);
            level->m_audioTrack = 42;
            level->m_coins = 3;
            break;
        case 4:
            setLevelInfo(level, 6, GJDifficulty::Insane, 0, 18787); //space battle
            level->m_levelName = getAudioTitle(43);
            level->m_audioTrack = 43;
            level->m_coins = 3;
            break;
    }
    level->m_levelID = levelID;
    return level;
}

void HookedLevelTools::setLevelInfo(GJGameLevel* level, int stars, GJDifficulty difficulty, int coinsRequired, int frameTime) {
    level->m_stars = stars;
    level->m_difficulty = difficulty;
    level->m_requiredCoins = coinsRequired;
    level->m_levelType = GJLevelType::Local;
    #ifdef GEODE_IS_WINDOWS
    MBO(int, level, 0x414) = frameTime;
    #endif
    #ifdef GEODE_IS_ANDROID64
    MBO(int, level, 0x390) = frameTime;
    #endif
    #ifdef GEODE_IS_ANDROID32
    MBO(int, level, 0x310) = frameTime;
    #endif
}