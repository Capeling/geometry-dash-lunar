#include "HookedAchievementManager.h"

void HookedAchievementManager::addManualAchievements() {
    patchOutPrevious();

    //Active
    AchievementManager::addAchievement("geometry.ach.level01a", "Turned Off", "Completed \'Active\' in Practice mode", "Complete \'Active\' in Practice mode", "icon_09", 1);
    AchievementManager::addAchievement("geometry.ach.level01b", "Active!", "Completed \'Active\' in Normal mode", "Complete \'Active\' in Normal mode", "icon_05", 1);

    //Thunderzone
    AchievementManager::addAchievement("geometry.ach.level02a", "Thunderbolt", "Completed \'Thunderzone\' in Practice mode", "Complete \'Thunderzone\' in Practice mode", "icon_10", 1);
    AchievementManager::addAchievement("geometry.ach.level02b", "Thunderzone!", "Completed \'Thunderzone\' in Normal mode", "Complete \'Thunderzone\' in Normal mode", "icon_06", 1);

    //Earthsplitter
    AchievementManager::addAchievement("geometry.ach.level03a", "Earthquake", "Completed \'Earthsplitter\' in Practice mode", "Complete \'Earthsplitter\' in Practice mode", "icon_11", 1);
    AchievementManager::addAchievement("geometry.ach.level03b", "Earthsplitter!", "Completed \'Earthsplitter\' in Normal mode", "Complete \'Earthsplitter\' in Normal mode", "icon_07", 1);

    //Space Battle
    AchievementManager::addAchievement("geometry.ach.level04a", "Game Over", "Completed \'Space Battle\' in Practice mode", "Complete \'Space Battle\' in Practice mode", "icon_12", 1);
    AchievementManager::addAchievement("geometry.ach.level04b", "Space Battle!", "Completed \'Space Battle\' in Normal mode", "Complete \'Space Battle\' in Normal mode", "icon_08", 1);

    AchievementManager::addManualAchievements();
}

//CCDictionary* HookedAchievementManager::addAchievement(gd::string achID, gd::string title, gd::string descUnlock, gd::string descLock, gd::string reward, int idk) {
//    return AchievementManager::addAchievement(achID, title, descUnlock, descLock, reward, idk);
//}

void HookedAchievementManager::reportAchievementWithID(char const* p0, int p1, bool p2) {
    AchievementManager::reportAchievementWithID(p0, p1, p2);
}

void HookedAchievementManager::patchOutPrevious() {
    //Stereo Madness *
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0a90b), {0x90, 0x90, 0x90, 0x90, 0x90});
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0a985), {0x90, 0x90, 0x90, 0x90, 0x90});
    
    //Back On Track *
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0a9ff), {0x90, 0x90, 0x90, 0x90, 0x90});
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0aa79), {0x90, 0x90, 0x90, 0x90, 0x90});

    //Polargeist *
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0aaf3), {0x90, 0x90, 0x90, 0x90, 0x90});
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0ab6d), {0x90, 0x90, 0x90, 0x90, 0x90});

    //Dry Out *
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0abe7), {0x90, 0x90, 0x90, 0x90, 0x90});
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0ac61), {0x90, 0x90, 0x90, 0x90, 0x90});

    //Base After Base *
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0acdb), {0x90, 0x90, 0x90, 0x90, 0x90});
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0ad55), {0x90, 0x90, 0x90, 0x90, 0x90});
    
    //Cant Let Go *
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0adcf), {0x90, 0x90, 0x90, 0x90, 0x90});
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0ae49), {0x90, 0x90, 0x90, 0x90, 0x90});

    //Jumper *
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0aec3), {0x90, 0x90, 0x90, 0x90, 0x90});
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0af3d), {0x90, 0x90, 0x90, 0x90, 0x90});

    //Time Machine *
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0afb7), {0x90, 0x90, 0x90, 0x90, 0x90});
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0b031), {0x90, 0x90, 0x90, 0x90, 0x90});

    //Cycles *
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0b0ab), {0x90, 0x90, 0x90, 0x90, 0x90});
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0b125), {0x90, 0x90, 0x90, 0x90, 0x90});
    
    //xStep *
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0b19f), {0x90, 0x90, 0x90, 0x90, 0x90});
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0b219), {0x90, 0x90, 0x90, 0x90, 0x90});

    //Clutterfunk *
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0b293), {0x90, 0x90, 0x90, 0x90, 0x90});
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0b30d), {0x90, 0x90, 0x90, 0x90, 0x90});

    //Theory of Everything *
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0b387), {0x90, 0x90, 0x90, 0x90, 0x90});
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0b401), {0x90, 0x90, 0x90, 0x90, 0x90});

    //Electroman Adventures *
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0b47b), {0x90, 0x90, 0x90, 0x90, 0x90});
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0b4f5), {0x90, 0x90, 0x90, 0x90, 0x90});
    
    //Clubstep *
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0b56f), {0x90, 0x90, 0x90, 0x90, 0x90});
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0b5e9), {0x90, 0x90, 0x90, 0x90, 0x90});
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0d01f), {0x90, 0x90, 0x90, 0x90, 0x90});

    //Electrodynamix *
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0b663), {0x90, 0x90, 0x90, 0x90, 0x90});
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0b6dd), {0x90, 0x90, 0x90, 0x90, 0x90});

    //Hexagon Force *
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0b757), {0x90, 0x90, 0x90, 0x90, 0x90});
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0b7d1), {0x90, 0x90, 0x90, 0x90, 0x90});

    //Blast Processing *
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0b84b), {0x90, 0x90, 0x90, 0x90, 0x90});
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0b8c5), {0x90, 0x90, 0x90, 0x90, 0x90});
    
    //Theory Of Everything 2 *
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0b93f), {0x90, 0x90, 0x90, 0x90, 0x90});
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0b9b9), {0x90, 0x90, 0x90, 0x90, 0x90});
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0d099), {0x90, 0x90, 0x90, 0x90, 0x90});

    //Geometrical Dominator *
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0ba33), {0x90, 0x90, 0x90, 0x90, 0x90});
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0baad), {0x90, 0x90, 0x90, 0x90, 0x90});

    //Deadlocked *
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0bb27), {0x90, 0x90, 0x90, 0x90, 0x90});
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0bba1), {0x90, 0x90, 0x90, 0x90, 0x90});
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0d113), {0x90, 0x90, 0x90, 0x90, 0x90});

    //Fingerdash *
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0bc1b), {0x90, 0x90, 0x90, 0x90, 0x90});
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0bc95), {0x90, 0x90, 0x90, 0x90, 0x90});
    
    //Dash *
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0bd0f), {0x90, 0x90, 0x90, 0x90, 0x90});
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0bd89), {0x90, 0x90, 0x90, 0x90, 0x90});

    //Tower 1
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0be03), {0x90, 0x90, 0x90, 0x90, 0x90});
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0bfeb), {0x90, 0x90, 0x90, 0x90, 0x90});

    //Tower 2
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0be7d), {0x90, 0x90, 0x90, 0x90, 0x90});
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0c065), {0x90, 0x90, 0x90, 0x90, 0x90});

    //Tower 3
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0bef7), {0x90, 0x90, 0x90, 0x90, 0x90});
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0c0df), {0x90, 0x90, 0x90, 0x90, 0x90});

    //Tower 4
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0bf71), {0x90, 0x90, 0x90, 0x90, 0x90});
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x0c159), {0x90, 0x90, 0x90, 0x90, 0x90});

    // Complete 10 User Levels
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x12479), {0x90, 0x90, 0x90, 0x90, 0x90});
}