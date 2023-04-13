#include "PlayScene.h"
#include "Engine/Camera.h"

#include "Stage.h"
#include "Player.h"
#include "Enemy.h"

//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

//初期化
void PlayScene::Initialize()
{
	Instantiate<Stage>(this);
	Instantiate<Player>(this);

	Camera::SetPosition(XMFLOAT3(0, 3, -10));
	Camera::SetTarget(XMFLOAT3(0, 3, 0));
}

//更新
void PlayScene::Update()
{
}

//描画
void PlayScene::Draw()
{
}

//開放
void PlayScene::Release()
{
}