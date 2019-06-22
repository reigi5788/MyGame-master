/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    // add "HelloWorld" splash screen"
    //auto sprite = Sprite::create("HelloWorld.png");
    //if (sprite == nullptr)
    //{
    //    problemLoading("'HelloWorld.png'");
    //}
    //else
    //{
    //    // position the sprite on the center of the screen
    //    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    //    // add the sprite as a child to this layer
    //    this->addChild(sprite, 0);
    //}
    //return true;
	/////////////////////テキストファイル名を指定して、スプライトを作成
	//スプライト（ノードの一種の作成）
	sprite = Sprite::create("kabocha.png");
	sprite2 = Sprite::create("SPBall.png");
	
	//シーングラフにつなぐ
	this->addChild(sprite);
	this->addChild(sprite2);


	
	/////////アクションの作成
	//Actionの内容を決めてaction1をどう動かすかを決定
	//(1秒かけて、座標300,100に向かって動く)
	//MoveTo* action2 = MoveTo::create(1.0f, Vec2(300, 100));
	MoveTo* action3 = MoveTo::create(1.0f, Vec2(300, 100));

	//1秒かけて5倍の大きさになる
	//ScaleTo* action1 = ScaleTo::create(1.0f, 5.0f);

	//特定の座標まで何回ジャンプして到着する
	//JumpTo*action1 = JumpTo::create(1.5f, Vec2(200, 100), 500.0f, 2);

	//特定の座標からコントロールポイントを巡ってエンドポジションに移動
	//ノードをベジエ曲線に沿って移動させる
	/*ccBezierConfig conf;
	conf.controlPoint_1 = Vec2(500, 500);
	conf.controlPoint_2 = Vec2(300, 100);
	conf.endPosition = Vec2(200, 100);
	BezierTo* action1 = BezierTo::create(3.0f,conf);
	*/

	//何秒間に何回点滅させるか
	//Blink* action1 = Blink::create(1.0f, 9);

	//Actionの作成
	MoveBy* action1 = MoveBy::create(2.0f, Vec2(600, 300));
	//Actionに対していーじんぐ（緩急）をつけたアクションを生成
	//だんだん加速していって止まる
	//上で目的地を設定しているので急に加速しても停止する
	//EaseIn* action2 = EaseIn::create(action1, 1.0f);

	//逆方向に小刻み（？）しながら移動する
	//EaseElasticIn* action2 = EaseElasticIn::create(action1, 2.0f);



	///////Actionの実行
	//同じActionを2つのスプライトに使いまわすと先に表示されてる方が実行されない
	//ノードに対してアクションを実行する
	//sprite->runAction(action3);
	//sprite2->runAction(action3->clone());
	//cloneメソッドを入れるとActionを複製して実行できる
	//イージング付きアクションの実行
	//sprite->runAction(action2);


	sprite->setPosition(Vec2(200,200));
	sprite2->setPosition(Vec2(500,500));
	/*sprite->setRotation(45.0f);*/
	/*sprite->setScale(3.0f, 4.0f);*/
	//sprite->setFlippedX(true);
	//sprite->setFlippedY(true);
	sprite->setColor(Color3B(255,255,255));
	sprite2->setColor(Color3B(255, 255, 255));
	
	/*sprite->setOpacity(255);*/
	//画像の左下が（0,0）
	//画像の右上が(1,0)の座標系で
	//基準点を指定する。
	sprite->setRotation(45.0f);
	/*sprite->setAnchorPoint(Vec2(1.0f, 0.0f));*/
	
	
	
	//counter = 0;
	state = 0;
	this->scheduleUpdate();
	return true;

}



void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}

void HelloWorld::update(float delta)
{
	//青色から赤色へ変化していく
	/*float b = sprite->getColor().b;
	float r = sprite->getColor().r;
	float g = sprite->getColor().g;
	b-= 1.0f;
	r += 1.0f;

	sprite->setColor(Color3B( r, g, b));*/

	//画像を左右に移動させ、移動方向に画像を反転
	/*Vec2 pos;
	switch (state)
	{
	case 0:
		pos = sprite->getPosition();
		pos += Vec2(-5.0f, 0.0f);
		sprite->setPosition(pos);
		if (pos.x < 0)
		{
			state = 1;
			sprite->setFlippedX(false);
		}
		break;

	case 1:
		state = 2;
		break;

	case 2:
		pos = sprite->getPosition();
		pos += Vec2(5.0f, 0.0f);
		sprite->setPosition(pos);
		if (pos.x>1280)
		{
			state = 3;
			sprite->setFlippedX(true);
		}
		break;
	case 3:
		state = 0;
		break;*/
//}

	

	


	//switch (state)
	//{
	//case 0:
	//	pos = sprite->getPosition();
	//	pos += Vec2(-5.0f, 0.0f);
	//	sprite->setPosition(pos);
	//	if (pos.x <= -120)
	//	{
	//		state = 1;
	//	}
	//	break;
	//case 1:
	//	pos = sprite->getPosition();
	//	pos += Vec2(5.0f, 0.0f);
	//	sprite->setPosition(pos);
	//	if (pos.y <= 700)
	//	{
	//		state = 2;
	//	}
	//	break;
	//case 2:
	//	pos = sprite->getPosition();
	//	pos += Vec2(-5.0f, 0.0f);
	//	sprite->setPosition(pos);
	//	if (pos.x <=1200)
	//	{
	//		state = 3;
	//	}
	//	break;
	//case 3:
	//	pos = sprite->getPosition();
	//	pos += Vec2(0.0f, 5.0f);
	//	sprite->setPosition(pos);
	//	if (pos.y >= -100)
	//	{
	//		state = 0;
	//	}
	//	
	//	break;
	//
	//	
	//}
	///*Vec2 pos = sprite->getPosition();*/

	///*pos += Vec2(-1.0f, 0.0f);*/

	//sprite->setPosition(pos);
	//
	///*counter++;*/
	////float opacity = 255- (counter / 300.0f * 255.0f);
	////sprite->setOpacity(opacity);




}