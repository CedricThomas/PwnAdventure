class IItem {
  public:
    virtual ~IItem();
    virtual const char * GetName();
    virtual const char * GetDisplayName();
    virtual const char * GetItemTypeName();
    virtual const char * GetDescription();
    virtual const char * GetFlavorText();
    virtual bool CanEquip();
    virtual uint32_t GetMaximumCount();
    virtual bool CanActivate(class IPlayer *);
    virtual bool CanActivateInInventory();
    virtual void Activate(class IPlayer *);
    virtual bool ShowInInventory();
    virtual bool ShowEventOnPickup();
    virtual bool ShowEventOnDuplicatePickup();
    virtual bool ShowNotificationOnPickup();
    virtual float GetCooldownTime();
    virtual enum ItemRarity GetItemRarity();
    virtual class IItem * GetAmmoType();
    virtual uint32_t GetClipSize();
    virtual int32_t GetDamage();
    virtual int32_t GetDamagePerSecond();
    virtual enum DamageType GetDamageType();
    virtual int32_t GetManaCost();
    virtual const char * GetCustomCostDescription();
    virtual bool IsAutoFire();
    virtual uint32_t GetNumberOfProjectiles();
    virtual float GetReloadTime(int32_t);
    virtual bool HasPartialReload();
    virtual float GetRange();
    virtual int32_t GetTradeValue();
    virtual bool IsDynamic();
    virtual bool IsUpdating();
}

class Item : public IItem {
  public:
    Item();
    virtual ~Item();
    virtual bool CanEquip();
    virtual uint32_t GetMaximumCount();
    virtual bool CanActivate(class IPlayer *);
    virtual void Activate(class IPlayer *);
    virtual void PerformActivate(class IPlayer *);
    virtual void LocalActivate(class IPlayer *);
    virtual bool CanActivateInInventory();
    virtual bool ShowInInventory();
    virtual bool ShowEventOnPickup();
    virtual bool ShowEventOnDuplicatePickup();
    virtual bool ShowNotificationOnPickup();
    virtual float GetCooldownTime();
    virtual enum ItemRarity GetItemRarity();
    virtual class IItem * GetAmmoType();
    virtual uint32_t GetClipSize();
    virtual int32_t GetDamage();
    virtual int32_t GetDamagePerSecond();
    virtual enum DamageType GetDamageType();
    virtual int32_t GetManaCost();
    virtual const char * GetCustomCostDescription();
    virtual bool IsAutoFire();
    virtual uint32_t GetNumberOfProjectiles();
    virtual float GetReloadTime(int32_t);
    virtual bool HasPartialReload();
    virtual float GetRange();
    virtual int32_t GetTradeValue();
    virtual void Reset();
    virtual void Update();
    virtual bool IsDynamic();
    virtual bool IsUpdating();
}

enum ItemRarity {ResourceItem, NormalItem, RareItem, LegendaryItem, LeetItem}
