#pragma once
#include "../GameEngine/Vec.h"
#include "../GameEngine/Render.h"

struct HitBox
{
	shu::vec2f pos;			// λ��
	shu::vec2f size;		// ��С
	shu::vec2f speed;		// �ٶ�
	shu::vec2f acceleration;// ���ٶ�
	bool isWorks = true;	// �Ƿ���Ч
};

class HitboxComponent
{
public:
	HitboxComponent();
	HitboxComponent(HitBox hitbox);
	~HitboxComponent();

	void Init(HitBox hitbox);

	void Render(shu::Direct2dRender& rt);
	
	void SetPos(const shu::vec2f& pos);
	void SetSize(const shu::vec2f& size);
	void SetSpeed(const shu::vec2f& speed);
	void SetAccele(const shu::vec2f& acc);

	shu::vec2f& GetPos();
	shu::vec2f& GetSize();
	shu::vec2f& GetSpeed();
	shu::vec2f& GetAccele();

	HitBox& GetHitbox();

	/**
	 * @brief �����κ��߶ε���ײ
	 * @param[in] rect Ҫ���ľ���
	 * @param[in] lineBegin �߶ε����
	 * @param[in] lineEnd �߶ε��յ�
	 * @param[out] collPos �����߶��������ײ��λ��
	 * @param[out] normal �����߶��������ײλ�õķ���
	 * @param[out] coll_time �����߶��������ײ��λ�ã�ռ�����߶γ��ȵİٷֱ�
	 * @return ��ײtrue������ײfalse����Щ��ײ���Ĵ��붼�ο��� @javidx9 ����Ƶ���ǳ���л�� https://www.youtube.com/watch?v=8JJ-4JgR7Dg&t=2828s��
	*/
	static bool CollideRectVsLine(HitBox& rect, shu::vec2f& lineBegin, shu::vec2f& lineEnd, shu::vec2f& collPos, shu::vec2f& normal, float& coll_time);

	/**
	 * @brief ����������ε���ײ
	 * @param[in] in �������
	 * @param[in] target Ŀ�����
	 * @param[out] collPos ������ײλ��
	 * @param[out] normal ������ײλ�õķ���
	 * @param[out] coll_time ������ײ��λ�ã�ռ�����߶γ��ȵİٷֱ�
	 * @param[in] dt ֡ʱ����
	 * @return ��ײtrue������ײfalse����Щ��ײ���Ĵ��붼�ο��� @javidx9 ����Ƶ���ǳ���л�� https://www.youtube.com/watch?v=8JJ-4JgR7Dg&t=2828s��
	*/
	static bool CollideRectVsRect(const HitBox& in, const HitBox& target, shu::vec2f& collPos, shu::vec2f& normal, float& coll_time, const float dt);

	/**
	 * @brief ��������ƶ����ε���ײ
	 * @param in ������Σ��þ���������ײ���Ǹ�
	 * @param target Ŀ����Σ��þ���Ӧ�ò��ܵ���ײ�����˶�
	 * @param collPos ������ײλ��
	 * @param normal ������ײ�ķ�����
	 * @param collTime ������ײ��ʱ��
	 * @param dt ����֡���ʱ��
	 * @return ��ײtrue������ײfalse����Щ��ײ���Ĵ��붼�ο��� @javidx9 ����Ƶ���ǳ���л�� https://www.youtube.com/watch?v=8JJ-4JgR7Dg&t=2828s��
	*/
	static bool CollideRectVsMoveRect(HitBox& in, HitBox& target, shu::vec2f& collPos, shu::vec2f& normal, float& collTime, const float dt);

	static bool RectVsRect(HitBox& b1, HitBox& b2);

	static bool isShowHitbox;

private:
	HitBox m_hitbox;

};

