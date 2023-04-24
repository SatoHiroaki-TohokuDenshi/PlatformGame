#include "Player.h"

#include "Engine/Input.h"
#include "Engine/Model.h"

//�R���X�g���N�^
Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), hModel_(-1)
{
}

//�f�X�g���N�^
Player::~Player()
{
}

//������
void Player::Initialize()
{
    //���f���f�[�^�̃��[�h
    hModel_ = Model::Load("Player.fbx");
    assert(hModel_ >= 0);
}

//�X�V
void Player::Update()
{
    //D�L�[��������Ă�����
    if (Input::IsKey(DIK_D))
    {
        transform_.position_.x += 0.1f;
    }
    //A�L�[��������Ă�����
    if (Input::IsKey(DIK_A))
    {
        transform_.position_.x -= 0.1f;
    }
}

//�`��
void Player::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//�J��
void Player::Release()
{
}