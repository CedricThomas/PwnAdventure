class HeapSpray : public Gun {
  public:
    virtual const char * GetName();
    virtual const char * GetDisplayName();
    virtual const char * GetItemTypeName();
    virtual const char * GetDescription();
    virtual const char * GetFlavorText();
    virtual float GetCooldownTime();
    virtual int32_t GetDamage();
    virtual float GetSpreadAngle();
    virtual uint32_t GetNumberOfProjectiles();
    virtual float GetReloadTime(int32_t);
    virtual bool HasPartialReload();
    virtual enum ItemRarity GetItemRarity();
    virtual class IItem * GetAmmoType();
    virtual uint32_t GetClipSize();
}
