#include "HookedLevelTools.h"

bool HookedLevelTools::verifyLevelIntegrity(gd::string verifyString, int levelID) {
    bool isValid = false;
    log::info("size: {}", verifyString.size());
    switch(levelID) {
        case 1:
            if(verifyString.size() == 1021811) isValid = true;
            break;
        case 2:
            if(verifyString.size() == 2161581) isValid = true;
            break;
        case 3:
            if(verifyString.size() == 3858465) isValid = true;
            break;
        case 4:
            if(verifyString.size() == 4413382) isValid = true;
            break;
        default:
            break;
    }
    return isValid;
}

gd::string HookedLevelTools::getAudioTitle(int audioID) {
    log::info("audioID: {}", audioID);
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
    gd::string spaceBattle = noCopyright ? "SpaceBattleRemix.mp3"_spr : "SpaceBattle.mp3"_spr;
    switch(audioID) {
        case 40: return active;
        case 41: return thunderZone;
        case 42: return "Earthsplitter.mp3"_spr;
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
    GJGameLevel* level = LevelTools::getLevel(levelID, _save);

    level->m_audioTrack += 40;
    level->m_levelName = HookedLevelTools::getAudioTitle(39 + levelID);

    switch(levelID) {
        case 1: 
            setDifficulty(level, 2, GJDifficulty::Normal);
            break;
        case 2:
            setDifficulty(level, 3, GJDifficulty::Hard);
            break;
        case 3:
            setDifficulty(level, 4, GJDifficulty::Harder);
            break;
        case 4:
            setDifficulty(level, 6, GJDifficulty::Harder);
            break;
    }
    return level;
}

void HookedLevelTools::setDifficulty(GJGameLevel* level, int stars, GJDifficulty difficulty) {
    level->m_stars = stars;
    level->m_difficulty = difficulty;
}