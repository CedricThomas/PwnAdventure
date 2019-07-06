class MadCow : public Enemy {
  public:
    MadCow();
    virtual float GetMaximumDamageDistance();
    virtual float GetAggressionRadius();
    virtual int32_t GetAttackDamage();
    virtual int32_t GetMaxHealth();
    virtual const char * GetDisplayName();
    virtual std::string GetDeathMessage();
}

class MadCowSpawner : public Spawner {
  private:
    float m_checkForCompleteTimer;

  public:
    MadCowSpawner(const struct Vector3 &, const struct Rotation &);
    virtual class Actor * Spawn();
    virtual void Tick(float);
}
