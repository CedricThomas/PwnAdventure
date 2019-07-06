class HolyHandGrenade : public Grenade {
  public:
    virtual const char * GetName();
    virtual const char * GetDisplayName();
    virtual const char * GetItemTypeName();
    virtual const char * GetDescription();
    virtual const char * GetFlavorText();
    virtual float GetCooldownTime();
    virtual int32_t GetDamage();
    virtual enum DamageType GetDamageType();
    virtual enum ItemRarity GetItemRarity();
    virtual int32_t GetTradeValue();
    virtual void SpawnProjectile(class Player *);
}

class HolyHandGrenadeProjectile : public GrenadeProjectile {
  public:
    HolyHandGrenadeProjectile(class IActor *);
    virtual int32_t GetDirectDamage();
    virtual enum DamageType GetDamageType();
    virtual bool HasSplashDamage();
    virtual float GetSplashRadius();
    virtual int32_t GetSplashDamage();
}
