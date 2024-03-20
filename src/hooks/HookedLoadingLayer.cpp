#include "HookedLoadingLayer.h"

void HookedLoadingLayer::loadingFinished() {
    //if(m_fromRefresh) return;
    LoadingLayer::loadingFinished();
}

bool HookedLoadingLayer::init(bool fromReload) {
    return LoadingLayer::init(fromReload);
}