class HandCannon : public Item {
  public:
    virtual const char * GetName();
    virtual const char * GetDisplayName();
    virtual const char * GetItemTypeName();
    virtual const char * GetDescription();
    virtual const char * GetFlavorText();
    virtual bool CanEquip();
    virtual bool ShowEventOnPickup();
    virtual float GetCooldownTime();
    virtual int32_t GetDamage();
    virtual enum ItemRarity GetItemRarity();
    virtual bool CanActivate(class IPlayer *);
    virtual void PerformActivate(class IPlayer *);
    virtual void SpawnProjectile(class Player *);
    virtual class IItem * GetAmmoType();
}

class HandCannonProjectile : public Projectile {
  public:
    HandCannonProjectile(class IActor *);
    virtual int32_t GetDirectDamage();
    virtual enum DamageType GetDamageType();
    virtual bool HasSplashDamage();
    virtual float GetSplashRadius();
    virtual int32_t GetSplashDamage();
}
