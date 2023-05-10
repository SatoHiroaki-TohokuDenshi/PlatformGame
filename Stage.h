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


//�X�e�[�W���Ǘ�����N���X
class Stage : public GameObject
{
    int hModel_[TYPE_MAX];    //���f���ԍ�
    int** table_;             //�}�b�v�f�[�^
    int mapWidth_;            //�}�b�v�̕�
    int mapHeight_;           //�}�b�v�̍���
public:
    //�R���X�g���N�^
    Stage(GameObject* parent);

    //�f�X�g���N�^
    ~Stage();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //�����蔻��p�̃f�[�^�擾�֐�
    bool IsFloor(int x, int y);
};