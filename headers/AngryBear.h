class AngryBear : public Bear {
  private:
    void InitAngryBear();
  public:
    AngryBear();
    AngryBear(class BearChest *, const std::string &);
    virtual float GetMaximumDamageDistance();
    virtual float GetAggressionRadius();
    virtual int32_t GetMaxHealth();
    virtual int32_t GetAttackDamage();
    virtual const char * GetDisplayName();
    virtual std::string GetDeathMessage();
    virtual bool IsElite();
    virtual bool CanBeArmed();
}

class AngryBearSpawner : public BearSpawner {
  public:
    AngryBearSpawner(const struct Vector3 &, const struct Rotation &, class BearChest *);
    virtual class Actor * Spawn();
    virtual size_t GetMaxActors();
}

class TailMountainsBearSpawner : public Spawner {
  public:
    TailMountainsBearSpawner(const struct Vector3 &, const struct Rotation &);
    virtual class Actor * Spawn();
}
