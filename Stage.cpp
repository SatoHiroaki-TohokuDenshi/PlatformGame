#include "Stage.h"
#include "Engine/Model.h"
#include "Engine/CsvReader.h"

//コンストラクタ
Stage::Stage(GameObject* parent)
    :GameObject(parent, "Stage"), hModel_{ -1 },
    table_(nullptr), mapHeight_(0), mapWidth_(0)
{
    CsvReader csv;
    csv.Load("FloorData.csv");

    mapHeight_ = csv.GetHeight();
    mapWidth_ = csv.GetWidth();

    table_ = new int* [mapWidth_];
    for (int x = 0; x < mapHeight_; x++)
    {
        table_[x] = new int[mapHeight_];
    }

    for (int x = 0; x < mapHeight_; x++)
    {
        for (int y = 0; y < mapWidth_; y++)
        {
            table_[x][(mapWidth_ - 1) - y] = csv.GetValue(x, y);
        }
    }
}

//デストラクタ
Stage::~Stage()
{
}

//初期化
void Stage::Initialize()
{
    const char* fileName[] = {
        "NULL.fbx",
        "Air.fbx",
        "Floor.fbx" ,
        "Hole.fbx",
    };
    //モデルデータのロード
    for (int i = 0; i < TYPE_MAX; i++)
    {
        hModel_[i] = Model::Load(fileName[i]);
        assert(hModel_[i] >= 0);
    }
}

//更新
void Stage::Update()
{
}

//描画
void Stage::Draw()
{
    //Stageオブジェクトをずらさずに、ステージを配置するための変数
    Transform blockTrans;
    //表示するモデルを管理する変数
    int type = 0;

    for (int x = 0; x < mapHeight_; x++)
    {
        for (int y = 0; y < mapWidth_; y++)
        {
            blockTrans.position_.x = x;
            blockTrans.position_.y = y;

            type = table_[x][y];


            Model::SetTransform(hModel_[type], blockTrans);
            Model::Draw(hModel_[type]);

        }
    }
}

//開放
void Stage::Release()
{
    for (int x = 0; x < mapHeight_; x++)
    {
        delete[] table_[x];
    }
    delete[] table_;
}