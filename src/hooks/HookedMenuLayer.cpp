#include "HookedMenuLayer.h"
#include "../utils/WorkingDialogObject.h"

bool HookedMenuLayer::init() {
    if(!MenuLayer::init())
        return false;
    
    auto mainTitle = getChildByID("main-title");
    
    auto lunarTitle = CCSprite::createWithSpriteFrameName("GJL_lunarLogo_001.png"_spr);
    lunarTitle->setPosition({334, -18});
    mainTitle->addChild(lunarTitle);

    bool hasSeenSaveWarning = Mod::get()->getSavedValue<bool>("seen-saved-warning");
    if(!hasSeenSaveWarning) {
        auto alert = FLAlertLayer::create(nullptr, "Save Warning", "<cl>Geometry Dash: Lunar</c> uses a <co>different</c> save file to avoid <cr>stat modification</c>.\nYour <cg>save file</c> has not been <cr>deleted</c>, if you want to go back to your <cg>default</c> save file disable <cl>Geometry Dash: Lunar</c>.", "OK", nullptr, 400);
        alert->m_noElasticity = true;
        alert->m_scene = this;
        alert->show();
        Mod::get()->setSavedValue<bool>("seen-saved-warning", true);
    }
    return true;
}

void HookedMenuLayer::onCreator(CCObject*) {
    auto dl = DialogLayer::createDialogLayer(nullptr, getDialogArray(), 2);
    dl->animateIn(DialogAnimationType::FromLeft);
    CCScene::get()->addChild(dl);
}

CCArray* HookedMenuLayer::getDialogArray() {
    CCArray* array = CCArray::create();

    array->addObject(WorkingDialogObject::create("Scratch", "<cr>STOP!</c> <d040>You <co>can't</c> go there.<d030>.<d030>.", 11, 1, false, {255, 255, 255}));
    array->addObject(WorkingDialogObject::create("Scratch", "Not while <cl>he</c> is around.", 8, 1, false, {255, 255, 255}));
    array->addObject(WorkingDialogObject::create("Scratch", "Leave <cl>Lunar</c>, <d040>and I will let you <cg>pass</c>.<d030>.<d030>.", 13, 1, false, {255, 255, 255}));
    
    return array;
}