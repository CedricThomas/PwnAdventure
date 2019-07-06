class Bear : public Enemy {
  protected:
    int32_t m_attacksLeftInPosition;
    class ActorRef<BearChest> m_chest;

    void Init();
    virtual void OnKilled(class IActor *, class IItem *);
    virtual void OnTargetKilled(class IActor *, class IItem *);
  public:
    Bear();
    Bear(class BearChest *, const std::string &);
    virtual ~Bear();
    virtual float GetMaximumDamageDistance();
    virtual float GetAggressionRadius();
    virtual int32_t GetAttackDamage();
    virtual bool CanBeArmed();
    virtual void OnPrepareAttack(class Actor *);
    virtual void OnEndAttack();
    void AttackForChest(class IPlayer *);
    void EndChestDefense();
    virtual int32_t GetMaxHealth();
    virtual const char * GetDisplayName();
    virtual std::string GetDeathMessage();
}

class BearDefendChestState : public AIState {
  private:
    class ActorRef<BearChest> m_chest;
    struct Vector3 m_lastKnownLocation;
    int32_t m_timeSinceKnown;
    bool m_lostTarget;

  public:
    BearDefendChestState(class AIActor *, class BearChest *);
    virtual void EnterState(class Actor *);
    virtual void OnAIMoveComplete();
}

class BearShootState : public AIState {
  private:
    int32_t m_shotsWithoutVisibility;

  public:
    BearShootState(class AIActor *);
    virtual void EnterState(class Actor *);
    virtual void LeaveState();
}

class BearSkin : public Item {
  private:
    virtual const char * GetName();
    virtual const char * GetDisplayName();
    virtual const char * GetItemTypeName();
    virtual const char * GetDescription();
    virtual const char * GetFlavorText();
    virtual enum ItemRarity GetItemRarity();
    virtual int32_t GetTradeValue();
}

class BearSpawner : public Spawner {
  protected:
    class ActorRef<BearChest> m_chest;

  public:
    BearSpawner(const struct Vector3 &, const struct Rotation &, class BearChest *);
    virtual class Actor * Spawn();
    virtual size_t GetMaxActors();
}

class TownBearSpawner : public Spawner {
  public:
    TownBearSpawner(const struct Vector3 &, const struct Rotation &);
    virtual class Actor * Spawn();
}
