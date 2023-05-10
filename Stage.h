#pragma once
#include "Engine/GameObject.h"

enum
{
    TYPE_NULL = 0,
    TYPE_AIR,
    TYPE_FLOOR,
    TYPE_HOLE,
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

    //当たり判定用のデータ取得関数
    bool IsFloor(int x, int y);
};