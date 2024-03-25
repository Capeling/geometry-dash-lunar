#include "CreditNode.h"

CreditNode* CreditNode::create(const char* name, const char* reason, int iconID, int color1, int color2, int color3, bool glow, int accountID) {
    auto ret = new CreditNode();
    if(ret && ret->init(name, reason, iconID, color1, color2, color3, glow, accountID)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}

bool CreditNode::init(const char* name, const char* reason, int iconID, int color1, int color2, int color3, bool glow, int accountID) {
    if(!CCNode::init())
        return false;

    auto GM = GameManager::get();

    CCLabelBMFont* userLabel = CCLabelBMFont::create(name, "goldFont.fnt");
    userLabel->setScale(0.6f);

    CCMenuItemSpriteExtra* userBtn = CCMenuItemSpriteExtra::create(userLabel, this, menu_selector(CreditNode::onUser));
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
    userMenu->setPosition({0, 31});

    userMenu->addChild(userBtn);
    addChild(userMenu);
    addChild(userPlayer);
    addChild(userReason);

    return true;
}

void CreditNode::onUser(CCObject* sender) {
    ProfilePage::create(sender->getTag(), false)->show();
}