#include "defs/all.h"
#include "defs/utils.h"

std::string compareIcon(int iconID, std::string pszName, bool extra, bool doubleDigit) {
	std::string compare1 = "";
	std::string compare2 = "";
	std::string compare3 = "";
	std::string compare4 = "";
	if(doubleDigit) {
		compare1 = fmt::format("player_{}_001.png", iconID);
		compare2 = fmt::format("player_{}_2_001.png", iconID);
		compare3 = fmt::format("player_{}_extra_001.png", iconID);
		compare4 = fmt::format("player_{}_glow_001.png", iconID);	
	} else {
		compare1 = fmt::format("player_0{}_001.png", iconID);
		compare2 = fmt::format("player_0{}_2_001.png", iconID);
		compare3 = fmt::format("player_0{}_extra_001.png", iconID);
		compare4 = fmt::format("player_0{}_glow_001.png", iconID);
	}
	if(pszName == compare1) pszName = std::string(Mod::get()->expandSpriteName(pszName.c_str()));
	if(pszName == compare2) pszName = std::string(Mod::get()->expandSpriteName(pszName.c_str()));
	if (extra) if(pszName == compare3) pszName = std::string(Mod::get()->expandSpriteName(pszName.c_str()));
	if(pszName == compare4) pszName = std::string(Mod::get()->expandSpriteName(pszName.c_str()));
	return pszName;
}

$on_mod(Loaded) {
	int levelStart = 1;
	int levels = 4;
	std::vector<unsigned char> levelsBytes = PatchTool::intToBytes(levelStart + levels);
	std::vector<unsigned char> levelStartByte = PatchTool::intToBytes(levelStart);
	std::vector<unsigned char> songBytes = PatchTool::intToBytes(39 + levels);
	PatchTool::patch(0x2680bf, {0xbe, levelStartByte[0], 0x00, 0x00, 0x00});
	PatchTool::patch(0x26812e, {levelsBytes[0]});
	PatchTool::patch(0x268386, {0x83, 0xfe, levelsBytes[0]});
	PatchTool::patch(0x26838b, {0x6a, PatchTool::intToBytes((levelStart + levels) - 1)[0]});
	PatchTool::patch(0x268398, {0x6a, levelsBytes[0]});

	PatchTool::patch(0x92283, {0xba, songBytes[0], 0x00, 0x00, 0x00});
    PatchTool::patch(0x92276, {0x83, 0xf8, songBytes[0]});
    PatchTool::patch(0x922c2, {0xba, songBytes[0], 0x00, 0x00, 0x00});
}

CCSpriteFrame* mySpriteFrameByName(CCSpriteFrameCache* self, const char *pszName) {
	auto compare = std::string(pszName);
	std::string aReturn = pszName;
	aReturn = compareIcon(5, aReturn, true, false);
	aReturn = compareIcon(6, aReturn, true, false);
	aReturn = compareIcon(7, aReturn, true, false);
	aReturn = compareIcon(8, aReturn, false, false);
	aReturn = compareIcon(9, aReturn, false, false);
	aReturn = compareIcon(10, aReturn, false, true);
	aReturn = compareIcon(11, aReturn, true, true);
	aReturn = compareIcon(12, aReturn, false, true);

	return self->spriteFrameByName(aReturn.c_str());
}

$execute {
	Mod::get()->hook(
		reinterpret_cast<void*>(
			geode::addresser::getNonVirtual(&CCSpriteFrameCache::spriteFrameByName)
		),
		&mySpriteFrameByName,
		"cocos2d::CCSpriteFrameCache::spriteFrameByName",
		tulip::hook::TulipConvention::Thiscall
	);
}