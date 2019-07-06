class ZeroCool : public Item {
  public:
    virtual const char * GetName();
    virtual const char * GetDisplayName();
    virtual const char * GetItemTypeName();
    virtual const char * GetDescription();
    virtual const char * GetFlavorText();
    virtual bool CanEquip();
    virtual bool CanActivate(class IPlayer *);
    virtual void PerformActivate(class IPlayer *);
    virtual bool ShowEventOnPickup();
    virtual float GetCooldownTime();
    virtual int32_t GetDamage();
    virtual enum DamageType GetDamageType();
    virtual int32_t GetManaCost();
    virtual enum ItemRarity GetItemRarity();
    virtual void SpawnProjectile(class Player *);
    virtual int32_t GetTradeValue();
}

class ZeroCoolProjectile : public Projectile {
  public:
    ZeroCoolProjectile(class IActor *);
    virtual int32_t GetDirectDamage();
    virtual enum DamageType GetDamageType();
}
