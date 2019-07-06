class Grenade : public Item {
  public:
    virtual const char * GetCustomCostDescription();
    virtual bool CanEquip();
    virtual void PerformActivate(class IPlayer *);
    virtual bool ShowEventOnPickup();
    virtual void SpawnProjectile(class Player *);
}

class GrenadeProjectile : public Projectile {
  public:
    GrenadeProjectile(class IActor *, class IItem *, const std::string &);
    virtual bool DamagesOnHit();
    virtual void OnLifetimeEnded();
}
