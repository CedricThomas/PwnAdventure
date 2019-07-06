class LostCaveBush : public Actor {
  public:
    LostCaveBush();
    virtual bool CanUse(class IPlayer *);
    virtual void OnUse(class IPlayer *);
    virtual void PerformUse(class IPlayer *);
    virtual void Damage(class IActor *, class IItem *, int32_t, enum DamageType);
    virtual void Tick(float);
}
