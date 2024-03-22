#include "HookedLevelSelectLayer.h"

bool HookedLevelSelectLayer::init(int pageID) {
    return LevelSelectLayer::init(pageID);
}

ccColor3B HookedLevelSelectLayer::colorForPage(int pageID) {
    auto GM = GameManager::sharedState();
	int colIDs[6] = { 5 ,7, 8, 9, 94, 11 };
    if(colIDs[pageID % 6] == 94)
        return {37, 44, 52}; // The Tower

    return GM->colorForIdx(colIDs[pageID % 6]);
    
    //return LevelSelectLayer::colorForPage(pageID);
}