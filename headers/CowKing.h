class CowKing : public Enemy {
  protected:
    virtual void OnKilled(class IActor *, class IItem *);
  public:
    CowKing();
    virtual float GetMaximumDamageDistance();
    virtual float GetAggressionRadius();
    virtual bool ShouldWander() const;
    virtual bool ShouldAttackFromRange() const;
    virtual float GetRangedAttackDistance() const;
    virtual int32_t GetAttackDamage();
    virtual class IItem * GetAttackItem();
    virtual int32_t GetMaxHealth();
    virtual const char * GetDisplayName();
    virtual std::string GetDeathMessage();
    virtual bool IsElite();
    virtual void Damage(class IActor *, class IItem *, int32_t, enum DamageType);
    virtual bool ShouldTargetPlayer(class Player *);
}

class CowKingSpawner : public Spawner {
  public:
    CowKingSpawner(const struct Vector3 &, const struct Rotation &);
    virtual class Actor * Spawn();
    virtual size_t GetMaxActors();
    virtual float GetSpawnTimer();
}
