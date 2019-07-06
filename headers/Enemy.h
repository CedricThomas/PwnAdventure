class Enemy : public AIActor {
  protected:
    class LootTable m_loot;

    virtual void OnKilled(class IActor *, class IItem *);
  public:
    Enemy(const std::string &);
    virtual bool CanBeDamaged(class IActor *);
    virtual float GetMaximumDamageDistance();
    virtual int32_t GetAttackDamage();
    virtual enum DamageType GetAttackDamageType();
    virtual class IItem * GetAttackItem();
    virtual float GetAggressionRadius();
    virtual float GetAttackTime();
    virtual float GetAttackHitTime();
    virtual void OnPrepareAttack(class Actor *);
    virtual void OnEndAttack();
    virtual void Attack(class Actor *);
    virtual enum EnemyRank GetRank() const;
    virtual struct Rotation GetLookRotation();
    virtual void Damage(class IActor *, class IItem *, int32_t, enum DamageType);
}

class EnemyAttackState : public AIState {
  private:
    float m_timeLeftOnTarget;

  public:
    EnemyAttackState(class AIActor *);
    virtual void EnterState(class Actor *);
    virtual void LeaveState();
}

class EnemyChaseState : public AIState {
  protected:
    bool m_lostTarget;
    struct Vector3 m_lastKnownLocation;
    uint32_t m_missedChecks;

    void CheckForTargetVisibility();
  public:
    EnemyChaseState(class AIActor *);
    virtual void EnterState(class Actor *);
    virtual void OnAIMoveComplete();
}

class EnemyIdleState : public AIState {
  protected:
    void StartIdleMovement();
    void LookForPlayers();
  public:
    EnemyIdleState(class AIActor *);
    virtual void EnterState(class Actor *);
    virtual void OnAIMoveComplete();
}

enum EnemyRank {NormalEnemy, EliteEnemy, LegendaryEnemy}
