class Gun : public Item {
  public:
    virtual bool CanEquip();
    virtual bool ShowEventOnPickup();
    virtual bool CanActivate(class IPlayer *);
    virtual void PerformActivate(class IPlayer *);
    virtual void LocalActivate(class IPlayer *);
    virtual enum DamageType GetDamageType();
    virtual float GetRange();
    virtual float GetSpreadAngle();
    virtual float GetReloadTime(int32_t);
    float GetMaximumReloadTime();
    float GetMinimumReloadTime();
    virtual int32_t GetDamagePerSecond();
}

class PistolAmmo : public Item {
  private:
    virtual const char * GetName();
    virtual const char * GetItemTypeName();
    virtual const char * GetDisplayName();
    virtual const char * GetDescription();
    virtual const char * GetFlavorText();
    virtual enum ItemRarity GetItemRarity();
    virtual int32_t GetTradeValue();
}

class RevolverAmmo : public Item {
  private:
    virtual const char * GetName();
    virtual const char * GetItemTypeName();
    virtual const char * GetDisplayName();
    virtual const char * GetDescription();
    virtual const char * GetFlavorText();
    virtual enum ItemRarity GetItemRarity();
    virtual int32_t GetTradeValue();
}

class RifleAmmo : public Item {
  private:
    virtual const char * GetName();
    virtual const char * GetItemTypeName();
    virtual const char * GetDisplayName();
    virtual const char * GetDescription();
    virtual const char * GetFlavorText();
    virtual enum ItemRarity GetItemRarity();
    virtual int32_t GetTradeValue();
}

class ShotgunAmmo : public Item {
  private:
    virtual const char * GetName();
    virtual const char * GetItemTypeName();
    virtual const char * GetDisplayName();
    virtual const char * GetDescription();
    virtual const char * GetFlavorText();
    virtual enum ItemRarity GetItemRarity();
    virtual int32_t GetTradeValue();
}

class SniperAmmo : public Item {
  private:
    virtual const char * GetName();
    virtual const char * GetItemTypeName();
    virtual const char * GetDisplayName();
    virtual const char * GetDescription();
    virtual const char * GetFlavorText();
    virtual enum ItemRarity GetItemRarity();
    virtual int32_t GetTradeValue();
}
