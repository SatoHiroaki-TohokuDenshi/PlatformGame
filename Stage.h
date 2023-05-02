#pragma once
#include "Engine/GameObject.h"

enum
{
    TYPE_HOLE = 0,
    TYPE_FLOOR,
    TYPE_MAX,
};


//ステージを管理するクラス
class Stage : public GameObject
{
    int hModel_[TYPE_MAX];    //モデル番号
    int** table_;             //マップデータ
    int mapWidth_;            //マップの幅
    int mapHeight_;           //マップの高さ
public:
    //コンストラクタ
    Stage(GameObject* parent);

    //デストラクタ
    ~Stage();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};