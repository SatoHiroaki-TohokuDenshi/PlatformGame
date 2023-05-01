#include "PlayScene.h"
#include "Engine/Camera.h"

#include "Stage.h"
#include "Player.h"
#include "Enemy.h"

//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene"), camPos_(XMFLOAT3(0.0f, 0.0f, 0.0f))
{
}

//初期化
void PlayScene::Initialize()
{
	Instantiate<Stage>(this);
	Instantiate<Player>(this);

	Player* pPlayer = (Player*)FindObject("Player");
	camPos_ = pPlayer->GetPosition();
	camPos_.y = 3;
	Camera::SetTarget(camPos_);
	camPos_.z = -10;
	Camera::SetPosition(XMFLOAT3(0, 3, -10));
}

//更新
void PlayScene::Update()
{
	Player* pPlayer = (Player*)FindObject("Player");
	camPos_ = pPlayer->GetPosition();

	camPos_.y = 3;
	Camera::SetTarget(camPos_);
	camPos_.z = -10;
	Camera::SetPosition(camPos_);

}

//描画
void PlayScene::Draw()
{
}

//開放
void PlayScene::Release()
{
}