#include "Player.h"

#include "Engine/Input.h"
#include "Engine/Model.h"

//コンストラクタ
Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), hModel_(-1), frame_(1), jumpflag_(true), jump_(0.0f)
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
    // 右移動（Dキー）
    if (Input::IsKey(DIK_D))
    {
        transform_.position_.x += 0.1f;
    }
    // 左移動（Aキー）
    if (Input::IsKey(DIK_A))
    {
        transform_.position_.x -= 0.1f;
    }


    // ジャンプの入力処理
    if (Input::IsKeyDown(DIK_SPACE) && jumpflag_) {
        jump_ = 0.8f;
        if (transform_.position_.y != 0)
            jumpflag_ = false;
    }
    // ジャンプの移動処理
    if (frame_ % 2 == 0) {
        if (jump_ != 0) {
            transform_.position_.y += jump_;
            jump_ -= 0.1f;
        }
    }
    // ジャンプの着地処理
    if (transform_.position_.y < 0) {
        jump_ = 0.0f;
        transform_.position_.y = 0;
        jumpflag_ = true;
    }
    // ジャンプの各種処理のディレイ
    if (frame_ == 10000) {
        frame_ = 1;
    }
    else {
        frame_++;
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