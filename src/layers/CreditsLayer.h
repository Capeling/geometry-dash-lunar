#pragma once
#include "../defs/all.h"

class CreditsLayer : public Popup<std::string const&> {
protected:
    bool setup(std::string const& value) override;
public:
    static CreditsLayer* create(std::string const& title);
    CCMenu* createCreditUser(const char* name, const char* reason, int iconID, int color1, int color2, int color3, bool glow, int accountID);
    void onUser(CCObject* sender);
};