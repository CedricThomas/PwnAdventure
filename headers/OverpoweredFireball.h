class OPFireballProjectile : public Projectile {
  public:
    OPFireballProjectile(class IActor *);
    virtual int32_t GetDirectDamage();
    virtual enum DamageType GetDamageType();
    virtual bool HasSplashDamage();
    virtual float GetSplashRadius();
    virtual int32_t GetSplashDamage();
}

class OverpoweredFireball : public GreatBallsOfFire {
  public:
    virtual const char * GetName();
    virtual const char * GetDisplayName();
    virtual const char * GetDescription();
    virtual const char * GetFlavorText();
    virtual uint32_t GetMaximumCount();
    virtual float GetCooldownTime();
    virtual int32_t GetDamage();
    virtual enum DamageType GetDamageType();
    virtual int32_t GetManaCost();
    virtual enum ItemRarity GetItemRarity();
    virtual void SpawnProjectile(class Player *);
    virtual int32_t GetTradeValue();
}
