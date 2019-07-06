class CaveSpider : public Enemy {
  public:
    CaveSpider();
    virtual int32_t GetMaxHealth();
    virtual int32_t GetAttackDamage();
    virtual const char * GetDisplayName();
    virtual std::string GetDeathMessage();
    virtual float GetMaximumDamageDistance();
}

class CaveSpiderSpawner : public Spawner {
  public:
    CaveSpiderSpawner(const struct Vector3 &, const struct Rotation &);
    virtual class Actor * Spawn();
}

class TailMountainsSpiderSpawner : public Spawner {
  public:
    TailMountainsSpiderSpawner(const struct Vector3 &, const struct Rotation &);
    virtual class Actor * Spawn();
}
