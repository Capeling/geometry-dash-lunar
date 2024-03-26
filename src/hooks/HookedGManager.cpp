#include "HookedGManager.h"
#include "HookedLocalLevelManager.h"

void HookedGManager::setup() {

    //m_fileName = "CCGameManagerLunar.dat";
    GManager::setup();
}

void HookedGManager::saveGMTo(gd::string file) {
    log::info("file: {}", file);
    if(file == "CCLocalLevels.dat") return GManager::saveGMTo("CCLocalLevelsLunar.dat"); //people having issues with saves being deleted? this works ig
    GManager::saveGMTo("CCGameManagerLunar.dat");
}

void HookedGManager::loadDataFromFile(gd::string const& file) {
    log::info("file load: {}", file);
    if(file == "CCLocalLevels.dat") return GManager::loadDataFromFile("CCLocalLevelsLunar.dat"); //same thing
    GManager::loadDataFromFile("CCGameManagerLunar.dat");
}