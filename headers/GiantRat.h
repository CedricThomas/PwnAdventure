class CliffRatSpawner : public Spawner {
  public:
    CliffRatSpawner(const struct Vector3 &, const struct Rotation &);
    virtual class Actor * Spawn();
}

class GiantRat : public Enemy {
  public:
    GiantRat();
    virtual int32_t GetMaxHealth();
    virtual int32_t GetAttackDamage();
    virtual const char * GetDisplayName();
    virtual std::string GetDeathMessage();
}

class GiantRatSpawner : public Spawner {
  public:
    GiantRatSpawner(const struct Vector3 &, const struct Rotation &);
    virtual class Actor * Spawn();
}

class PirateRatSpawner : public Spawner {
  public:
    PirateRatSpawner(const struct Vector3 &, const struct Rotation &);
    virtual class Actor * Spawn();
}

class TownRatSpawner : public Spawner {
  public:
    TownRatSpawner(const struct Vector3 &, const struct Rotation &);
    virtual class Actor * Spawn();
}
