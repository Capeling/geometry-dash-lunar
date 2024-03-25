#include "HookedLoadingLayer.h"

void HookedLoadingLayer::loadingFinished() {
    LoadingLayer::loadingFinished();
}

bool HookedLoadingLayer::init(bool fromReload) {
    // new BG
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x276452), {0x6a, 0x19});
    Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x27645b), {0x6a, 0x19});

    GameManager::get()->loadGround(9);
    return LoadingLayer::init(fromReload);
}