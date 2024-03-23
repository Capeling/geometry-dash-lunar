#include "CreditsLayer.h"

bool CreditsLayer::setup(std::string const& title) {
    setID("credits-layer"_spr);
    setTitle(title, "bigFont.fnt", 0.8f);

    CCMenu* creditMenu = CCMenu::create();
    creditMenu->addChild(createCreditUser("Capeling", "Mod Developer", 475, 41, 52, 52, true, 18226543));
    creditMenu->addChild(createCreditUser("GenaMorphosis", "Levels (1-4)", 5, 6, 3, 1, true, 10026833));
    creditMenu->addChild(createCreditUser("FatzFries", "Icons", 235, 18, 12, 12, true, 14007342));

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

void CreditsLayer::onUser(CCObject* sender) {
    ProfilePage::create(sender->getTag(), false)->show();
}

CCMenu* CreditsLayer::createCreditUser(const char* name, const char* reason, int iconID, int color1, int color2, int color3, bool glow, int accountID) {
    auto GM = GameManager::get();

    CCLabelBMFont* userLabel = CCLabelBMFont::create(name, "goldFont.fnt");
    userLabel->setScale(0.6f);

    CCMenuItemSpriteExtra* userBtn = CCMenuItemSpriteExtra::create(userLabel, this, menu_selector(CreditsLayer::onUser));
    userBtn->setPosition({0, 30});
    userBtn->setTag(accountID);

    SimplePlayer* userPlayer = SimplePlayer::create(iconID);

    userPlayer->setColor(GM->colorForIdx(color1));
    userPlayer->setSecondColor(GM->colorForIdx(color2));
    if(glow) {
        userPlayer->setGlowOutline(GM->colorForIdx(color3));
        userPlayer->enableCustomGlowColor(GM->colorForIdx(color3));
    }

    userPlayer->setPosition({0, 0});
    userPlayer->setScale(1.2f);

    CCLabelBMFont* userReason = CCLabelBMFont::create(reason, "chatFont.fnt");
    userReason->setPosition({0, -27});
    userReason->setScale(0.7f);

    CCMenu* userMenu = CCMenu::create();
    userMenu->addChild(userBtn);
    userMenu->addChild(userPlayer);
    userMenu->addChild(userReason);

    return userMenu;
}