#ifndef __GTEST_SCENE_H__
#define __GTEST_SCENE_H__

#include "cocos2d.h"

#include "SimpleAudioEngine.h"

/* �׽�Ʈ������ ���õ� ���Դϴ� ���� ���ӿ��� ������ �ʽ��ϴ�.*/
class TestScene: public cocos2d::LayerColor
{
    
public:
    virtual bool init();
	static cocos2d::Scene* scene();
	CREATE_FUNC(TestScene);
};

#endif