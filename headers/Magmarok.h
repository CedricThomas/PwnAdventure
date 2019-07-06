class Magmarok : public Enemy {
  private:
    bool m_healingActive;
    float m_healingTimeLeft;
    float m_advanceQuestTimer;

  protected:
    virtual void OnKilled(class IActor *, class IItem *);
  public:
    Magmarok();
    virtual float GetMaximumDamageDistance();
    virtual float GetAggressionRadius();
    virtual bool ShouldWander() const;
    virtual bool ShouldAttackFromRange() const;
    virtual bool ShouldMove() const;
    virtual bool ShouldAttack() const;
    virtual bool ShouldAttackMultipleTargets() const;
    virtual float GetRangedAttackDistance() const;
    virtual float GetAttackTime();
    virtual int32_t GetMaxHealth();
    virtual const char * GetDisplayName();
    virtual std::string GetDeathMessage();
    virtual bool IsElite();
    virtual void Damage(class IActor *, class IItem *, int32_t, enum DamageType);
    virtual void Tick(float);
    virtual void OnPrepareAttack(class Actor *);
}

class MagmarokFireball : public Projectile {
  public:
    MagmarokFireball(class IActor *);
    virtual int32_t GetDirectDamage();
    virtual enum DamageType GetDamageType();
}

class MagmarokSpawner : public Spawner {
  public:
    MagmarokSpawner(const struct Vector3 &, const struct Rotation &);
    virtual class Actor * Spawn();
    virtual size_t GetMaxActors();
    virtual float GetSpawnTimer();
}
