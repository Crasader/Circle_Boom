#pragma once

#include "cocos2d.h"

class Circle
{
public:
	Circle();
	~Circle();
	cocos2d::Sprite* sprite;
	cocos2d::Vec2 movePosition; // �̵�����
	cocos2d::MotionStreak *streak; // �ܻ�
	int color;
	int timer;

	float moveSpeed; // �̵� �ӵ�

	void fliping();
	void move();

private:
	
};