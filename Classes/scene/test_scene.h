#ifndef __TEST_SCENE_H__
#define __TEST_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "object\circle_manager.h"
#include <list>

class TestScene: public cocos2d::Scene
{
// �ΰ��� ���� Scene�Դϴ�.
public:
	TestScene();
	~TestScene();
	static cocos2d::Scene* scene();

private:
	// Touch Event
	virtual bool init();
	virtual bool onTouchesBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onTouchesMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onTouchesEnded(cocos2d::Touch* touch, cocos2d::Event* event);

	// game set constant
	const std::string kLabelFont = "fonts/NanumGothic.otf";
	const int kLabelFontSIze = 40;
	const int kLabelDepth = 1;
	const int kMaxiumCircleCount = 20; // ���� ���� ����
	const int kStartCircleCount = 12; // ���� ��ü ����
	const int kBoomCount = 3; // ����� �ϴ� ��ü ����
	const int kDefaultPlusScore = 100; // �⺻ �߰� ����
	const int kClearScore = 120; // ��ü ��� ��Ʈ���� ��� �߰�����
	const int kComboScore = 10; // �޺� ���� ����
	const int kUImargin = 40;
	const float kCreateInterval = 3.0f; // ��ü���� �ð�
	const float kComboDuration = 3.0f; // �޺����� �ð�

	enum class kSceneStatus:int {Normal, Pause};

	// UI
	cocos2d::Vec2 scoreUIPosition_;

	// flag
	bool dangerF_;
	int status_;

	// Scheduler
	void update(float dt);
	void gameTimer(float dt);
	void gameRunCounter(float dt);
	void comboTimer(float dt);
	void circleInnerVisual(float dt);
	void circleCreating(float dt);

	void gameRun(); // ���� ��Ÿ�� ����
	void gameResume(); // �����簳 �� ����
	void circleBoom(); // ��ü ����
	void pause(); // ���� ����
	void gameOver();
	void danger();

	void plusScoreAction(cocos2d::Vec2 startPoint, int plusScore);

	CircleManager* circles_;

	int score_;
	int combo_;
	int counter_;
	int playTime_; // �� �÷����� �ð�
	int maxCombo_; // �ִ� �޺�

	cocos2d::Label* scoreLabel_;
	cocos2d::Label* circleCountLabel_;
	cocos2d::Sprite* touchMovePointSpr_;

	cocos2d::Vec2 prevTouchPoint_;

	std::list<cocos2d::Vec2> touchMovePoints_;

	CREATE_FUNC(TestScene);
};

#endif