class IceSpiderQueen : public Enemy {
  public:
    IceSpiderQueen();
    virtual float GetMaximumDamageDistance();
    virtual float GetAggressionRadius();
    virtual bool ShouldWander() const;
    virtual bool ShouldAttackFromRange() const;
    virtual float GetRangedAttackDistance() const;
    virtual float GetAttackTime();
    virtual int32_t GetMaxHealth();
    virtual const char * GetDisplayName();
    virtual std::string GetDeathMessage();
    virtual bool IsElite();
    virtual void OnPrepareAttack(class Actor *);
}

class IceSpiderQueenProjectile : public Projectile {
  public:
    IceSpiderQueenProjectile(class IActor *);
    virtual int32_t GetDirectDamage();
    virtual enum DamageType GetDamageType();
}

class IceSpiderQueenSpawner : public Spawner {
  public:
    IceSpiderQueenSpawner(const struct Vector3 &, const struct Rotation &);
    virtual class Actor * Spawn();
    virtual size_t GetMaxActors();
    virtual float GetSpawnTimer();
}
