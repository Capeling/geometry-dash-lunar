#pragma once
#include "../defs/all.h"

class CreditNode : public CCNode {
protected:
    $override
    bool init(const char* name, const char* reason, int iconID, int color1, int color2, int color3, bool glow, int accountID);
public:
    static CreditNode* create(const char* name, const char* reason, int iconID, int color1, int color2, int color3, bool glow, int accountID);
    void onUser(CCObject* sender);
};