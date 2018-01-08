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