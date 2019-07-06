class StaticLink : public Item {
  public:
    virtual const char * GetName();
    virtual const char * GetDisplayName();
    virtual const char * GetItemTypeName();
    virtual const char * GetDescription();
    virtual const char * GetFlavorText();
    virtual uint32_t GetMaximumCount();
    virtual bool CanEquip();
    virtual bool CanActivate(class IPlayer *);
    virtual void PerformActivate(class IPlayer *);
    virtual bool ShowEventOnPickup();
    virtual float GetCooldownTime();
    virtual int32_t GetDamage();
    virtual enum DamageType GetDamageType();
    virtual int32_t GetManaCost();
    virtual float GetRange();
    virtual enum ItemRarity GetItemRarity();
    virtual bool IsAutoFire();
}
