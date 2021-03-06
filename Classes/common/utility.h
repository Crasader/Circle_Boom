#pragma once

#include "json/rapidjson.h"
#include "json/document.h"
#include "json/filereadstream.h"
#include "cocos2d.h"

class Utility {

public:
	Utility();
	~Utility();
	static rapidjson::Document loadJson(char* fileName);
	static bool inpoly(std::list<cocos2d::Vec2> poly, cocos2d::Vec2 checkPoint);

private:
};