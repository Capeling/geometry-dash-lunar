#include "defs/all.h"
#include "defs/utils.h"
#include <Geode/modify/SongCell.hpp>

#define MEMBERBYOFFSET(type, class, offset) *reinterpret_cast<type*>(reinterpret_cast<uintptr_t>(class) + offset)
#define MBO MEMBERBYOFFSET //lol

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

	// Replace default songs with Lunar songs in SongsLayer
	// Active
	PatchTool::patch(0x38c141, {0xc7, 0x40, 0x34, 0x28});
	// Thunderzone
	PatchTool::patch(0x38c18f, {0xc7, 0x40, 0x34, 0x29});
	// Earthsplitter
	PatchTool::patch(0x38c1de, {0xc7, 0x40, 0x34, 0x2a});
	// Space Battle
	PatchTool::patch(0x38c22d, {0xc7, 0x40, 0x34, 0x2b});

	// Get rid of the other default songs
	// Base After Base *
	PatchTool::patch(0x38c28c, {0x90, 0x90, 0x90, 0x90, 0x90, 0x90});
	// Cant Let Go *
	PatchTool::patch(0x38c2db, {0x90, 0x90, 0x90, 0x90, 0x90, 0x90});
	// Jumper *
	PatchTool::patch(0x38c32a, {0x90, 0x90, 0x90, 0x90, 0x90, 0x90});
	// Time Machine *
	PatchTool::patch(0x38c379, {0x90, 0x90, 0x90, 0x90, 0x90, 0x90});
	// Cycles *
	PatchTool::patch(0x38c3c8, {0x90, 0x90, 0x90, 0x90, 0x90, 0x90});
	// xStep *
	PatchTool::patch(0x38c417, {0x90, 0x90, 0x90, 0x90, 0x90, 0x90});
	// Clutterfunk *
	PatchTool::patch(0x38c466, {0x90, 0x90, 0x90, 0x90, 0x90, 0x90});
	// TOE *
	PatchTool::patch(0x38c4b5, {0x90, 0x90, 0x90, 0x90, 0x90, 0x90});
	// Electroman *
	PatchTool::patch(0x38c504, {0x90, 0x90, 0x90, 0x90, 0x90, 0x90});
	// Clubstep *
	PatchTool::patch(0x38c553, {0x90, 0x90, 0x90, 0x90, 0x90, 0x90});
	// Electrodynamix *
	PatchTool::patch(0x38c5a2, {0x90, 0x90, 0x90, 0x90, 0x90, 0x90});
	// Hexagon Force *
	PatchTool::patch(0x38c5f1, {0x90, 0x90, 0x90, 0x90, 0x90, 0x90});
	// Blast Processing *
	PatchTool::patch(0x38c640, {0x90, 0x90, 0x90, 0x90, 0x90, 0x90});
	// TOE2 *
	PatchTool::patch(0x38c68f, {0x90, 0x90, 0x90, 0x90, 0x90, 0x90});
	// Geometrical *
	PatchTool::patch(0x38c6de, {0x90, 0x90, 0x90, 0x90, 0x90, 0x90});
	// Deadlocked *
	PatchTool::patch(0x38c72d, {0x90, 0x90, 0x90, 0x90, 0x90, 0x90});
	// Fingerdash *
	PatchTool::patch(0x38c77c, {0x90, 0x90, 0x90, 0x90, 0x90, 0x90});
	// Dash *
	PatchTool::patch(0x38c7cb, {0x90, 0x90, 0x90, 0x90, 0x90, 0x90});
}

class $modify(SongCell) { //why is this in main? because i cant be fucked making new files for this small shit
	void loadFromObject(SongObject* object) {
		SongCell::loadFromObject(object);

		int audioID = MBO(int, object, 0x34);
		auto songLabel = getChildOfType<CCLabelBMFont>(m_mainLayer, 0);

		songLabel->setString(LevelTools::getAudioTitle(audioID).c_str()); //for some fucking reason hooking artistForAudio breaks this so i have to manually fix it.
		if(audioID == -1)
			songLabel->setScale(0.573);
	}
};

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