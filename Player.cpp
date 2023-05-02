#include "Player.h"

#include "Engine/Input.h"
#include "Engine/Model.h"

//コンストラクタ
Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), hModel_(-1), jumpflag_(true), jump_(0.0f)
{
}

//デストラクタ
Player::~Player()
{
}

//初期化
void Player::Initialize()
{
    //モデルデータのロード
    hModel_ = Model::Load("Player.fbx");
    assert(hModel_ >= 0);
}

//更新
void Player::Update()
{
    //Dキーが押されていたら
    if (Input::IsKey(DIK_D))
    {
        transform_.position_.x += 0.1f;
    }
    //Aキーが押されていたら
    if (Input::IsKey(DIK_A))
    {
        transform_.position_.x -= 0.1f;
    }

    if (transform_.position_.y < 0) {
        jump_ = 0.0f;
        transform_.position_.y = 0;
        jumpflag_ = true;
    }
    if (Input::IsKeyDown(DIK_SPACE) && jumpflag_) {
        jump_ = 0.8f;
        if (transform_.position_.y != 0)
            jumpflag_ = false;
    }
    if (jump_ != 0) {
        transform_.position_.y += jump_;
        jump_ -= 0.1f;
    }
}

//描画
void Player::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//開放
void Player::Release()
{
}