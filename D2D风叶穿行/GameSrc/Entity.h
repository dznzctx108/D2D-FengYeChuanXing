#pragma once
#include "HitboxComponent.h"
#include "AnimationComponent.h"
#include "GameData.h"
#include "../GameEngine/GameEngine.h"

// �¼�֪ͨ
enum class Event { StepOn/*���ȵ�*/, Grab/*��ץס*/, Jump/*��Ծ*/, BeginPlay33Animation, EndPlay33Animation };

// Ҷ�ӵ�����
enum class Type { Normal/*����*/, Trap/*����*/, Lucky/*����*/ };

// ��ҵ�״̬
enum class Player_Status { Ground/*�ڵ���*/, Air/*����*/, Lock/*��ס*/, Climb/*ץ��*/ };

// ����Ҷ��״̬
enum class Lucky_Status { Idle/*��̬*/, Move/*�ƶ�*/ };

// ����Ҷ��״̬
enum class Trap_Status { Idle/*��̬*/, Timeing/*��ʱ*/, Goneing/*��ʧ��*/, Gone/*������ʧ*/ };


/////////////////////////////////////////////////////////////////////////////////////////

// ������
class Entity
{
public:
	Entity() {};
	virtual ~Entity() {};

	virtual bool Init() { return true; };
	virtual void Updata(float dt) = 0;
	virtual void Render(shu::Direct2dRender& rt) = 0;
	virtual void OnEvent(Event event) = 0;

	bool isDelete = false;	// �Ƿ�����
	float m_all_time = 0.0f;
};


/////////////////////////////////////////////////////////////////////////////////////////

// ������Ҷ��
class LeaveObject : public Entity
{
public:

	LeaveObject() {};
	virtual ~LeaveObject();

	virtual void Updata(float dt) = 0;
	virtual void Render(shu::Direct2dRender& rt) = 0;
	virtual void OnEvent(Event event) = 0;

	void SetPlayerPtr(Entity* ptr);

	HitBox& GetHitbox();
	HitBox& GetHitbox2();
	HitboxComponent* GetHitboxComponent();
	HitboxComponent* GetHitboxComponent2();
	AnimationComponent* GetAnimationComponent();
	Type GetType();

protected:
	bool InitHitboxComponent(HitBox hitbox);
	bool InitHitboxComponent2(HitBox hitbox);
	bool InitAnimationComponent(const std::wstring& bitmapFile, const std::wstring& jsonFile, float duration);

	float rand_num = 0.0f;

	Entity* m_player = nullptr;	// ָ����ҵ�ָ��

	HitboxComponent* m_hitbox = nullptr;
	HitboxComponent* m_hitbox2 = nullptr;
	AnimationComponent* m_animation = nullptr;
	ID2D1Bitmap1* m_bitmap = nullptr;

	Type m_type = Type::Normal;
};


/////////////////////////////////////////////////////////////////////////////////////////

// ���������
class PlayerObject : public Entity
{
public:
	PlayerObject() {};
	virtual ~PlayerObject();

	virtual void Updata(float dt) = 0;
	virtual void Render(shu::Direct2dRender& rt) = 0;
	virtual void OnEvent(Event event) = 0;

	void SetStatus(Player_Status status);

	HitBox& GetHitbox();
	HitBox& GetHitbox2();
	HitboxComponent* GetHitboxComponent();
	HitboxComponent* GetHitboxComponent2();
	AnimationComponent* GetAnimationComponent();

protected:
	bool InitHitboxComponent(HitBox hitbox);
	bool InitHitboxComponent2(HitBox hitbox);
	bool InitAnimationComponent(const std::wstring& bitmapFile, const std::wstring& jsonFile, float duration);

	HitboxComponent* m_hitbox = nullptr;
	HitboxComponent* m_hitbox2 = nullptr;
	AnimationComponent* m_animation = nullptr;
	ID2D1Bitmap1* m_bitmap = nullptr;

	Player_Status m_status = Player_Status::Air;
	Player_Status m_last_status = Player_Status::Air;
};


