#include "PlayScene.h"
#include "Engine/Camera.h"

#include "Stage.h"
#include "Player.h"
#include "Enemy.h"

//�R���X�g���N�^
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

//������
void PlayScene::Initialize()
{
	Instantiate<Stage>(this);
	Instantiate<Player>(this);

	Camera::SetPosition(XMFLOAT3(0, 3, -10));
	Camera::SetTarget(XMFLOAT3(0, 3, 0));
}

//�X�V
void PlayScene::Update()
{
}

//�`��
void PlayScene::Draw()
{
}

//�J��
void PlayScene::Release()
{
}