#include "CreditsLayer.h"
#include "../nodes/CreditNode.h"

bool CreditsLayer::setup(std::string const& title) {
    setID("credits-layer"_spr);
    setTitle(title, "bigFont.fnt", 0.8f);

    auto capeUser = CreditNode::create("Capeling", "Mod Developer", 475, 41, 52, 52, true, 18226543);
    auto genaUser = CreditNode::create("GenaMorphosis", "Levels (1-4)", 467, 6, 3, 1, true, 10026833);
    auto fatzUser = CreditNode::create("FatzFries", "Icons", 235, 18, 12, 12, true, 14007342);

    CCMenu* creditMenu = CCMenu::create();
    creditMenu->addChild(capeUser);
    creditMenu->addChild(genaUser);
    creditMenu->addChild(fatzUser);

    GameToolbox::alignItemsHorisontally(creditMenu->getChildren(), 120.f, {0, 0}, true);

    m_mainLayer->addChildAtPosition(creditMenu, Anchor::Center, ccp(0, -10));

    return true;
}

CreditsLayer* CreditsLayer::create(std::string const& title) {
    auto ret = new CreditsLayer();
    if(ret && ret->initAnchored(360.f, 150.f, title, "GJ_square01.png")) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}