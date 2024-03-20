#include "HookedLocalLevelManager.h"

gd::string HookedLocalLevelManager::getMainLevelString(int id) {

    auto file = CCString::createWithFormat("%i.txt"_spr, id);
    if(file == nullptr) return "";
    auto content = CCString::createWithContentsOfFile(file->getCString());
    if(content == nullptr) return "";

    return gd::string(content->getCString());
    return LocalLevelManager::getMainLevelString(id);
}