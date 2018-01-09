#include "utility.h"

using namespace rapidjson;
using namespace std;

USING_NS_CC;

Utility::Utility() {

}

Utility::~Utility() {

}

Document Utility::loadJson(char* fileName) {
	Document document;
	string json;

	Data fileData = FileUtils::getInstance()->getDataFromFile(fileName);
	size_t fileSize = fileData.getSize();
	unsigned char* bytes = fileData.getBytes();

	json = string((char*)bytes, 0, fileSize);

	StringStream stream = StringStream(json.c_str());

	document.ParseStream<kArrayType>(stream);

	bool error = document.HasParseError();

	if (error) {
		CCLOG("Parse error [%d - %d]", error, document.GetParseError());
		document.Parse("{\"text\":\"������ ������ �����ϴ�.\"}");
		return document;
	}

	//issue - ���� �ҷ����� ���н� ����ó��(������ ���α׷� �����)

	return document;
}

bool Utility::inpoly(list<Vec2> poly, Vec2 checkPoint)
{
	Vec2 oldPoint, newPoint;
	Vec2 point1, point2;
	bool inside = false;

	if (poly.size() < 3) {
		return false;
	}

	oldPoint = *(poly.begin());

	for (auto point : poly) {
		newPoint = point;

		if (newPoint.x > oldPoint.x) {
			point1 = oldPoint;
			point2 = newPoint;
		} else {
			point1 = newPoint;
			point2 = newPoint;
		}
		if ((newPoint.x < checkPoint.x) == (checkPoint.x <= oldPoint.x)
			&& ((long)checkPoint.y - (long)point1.y)*(long)(point2.x - point1.x)
			< ((long)point2.y - (long)point1.y)*(long)(checkPoint.x - point1.x)) {
			inside = !inside;
		}
		oldPoint = newPoint;
	}

	return inside;
}//�ٰ��� ���� �� �Ǵ�(Crossing Count Algorithm)