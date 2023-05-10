#include "Player.h"

#include "Stage.h"
#include "Engine/Input.h"
#include "Engine/Model.h"

//�R���X�g���N�^
Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), hModel_(-1), frame_(1), jumpflag_(true), jump_(0.0f)
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
    if (Input::IsKeyDown(DIK_R))
        transform_.position_ = XMFLOAT3(0, 0, 0);

    // �E�ړ��iD�L�[�j
    if (Input::IsKey(DIK_D))
    {
        transform_.position_.x += 0.1f;
    }
    // ���ړ��iA�L�[�j
    if (Input::IsKey(DIK_A))
    {
        transform_.position_.x -= 0.1f;
    }

    // �W�����v����
    {
        if (Input::IsKeyDown(DIK_SPACE)) {
            jump_ = 0.8f;
        }

        Stage* pStage = (Stage*)FindObject("Stage");
        if (pStage->IsFloor(transform_.position_.x, transform_.position_.y)) {
            jump_ = 0.0f;
        }

        if (frame_ % 2 == 0) {
            transform_.position_.y += jump_;
            jump_ -= 0.1f;
        }

        if (frame_ == 10000)
            frame_ = 1;
        else
            frame_++;
    }

#if 0
    // �W�����v�̓��͏���
    if (Input::IsKeyDown(DIK_SPACE) && jumpflag_) {
        jump_ = 0.8f;
        if (transform_.position_.y != 0)
            jumpflag_ = false;
    }
    // �W�����v�̈ړ�����
    if (frame_ % 2 == 0) {
        if (jump_ != 0) {
            transform_.position_.y += jump_;
            jump_ -= 0.1f;
        }
    }
    // �W�����v�̒��n����
    if (transform_.position_.y < 0) {
        jump_ = 0.0f;
        transform_.position_.y = 0;
        jumpflag_ = true;
    }
    // �W�����v�̊e�폈���̃f�B���C
    if (frame_ == 10000) {
        frame_ = 1;
    }
    else {
        frame_++;
    }
#endif // 0
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