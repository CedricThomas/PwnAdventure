class CowboyCoder : public Gun {
  public:
    virtual const char * GetName();
    virtual const char * GetDisplayName();
    virtual const char * GetItemTypeName();
    virtual const char * GetDescription();
    virtual const char * GetFlavorText();
    virtual float GetCooldownTime();
    virtual int32_t GetDamage();
    virtual float GetSpreadAngle();
    virtual float GetReloadTime(int32_t);
    virtual enum ItemRarity GetItemRarity();
    virtual class IItem * GetAmmoType();
    virtual uint32_t GetClipSize();
    virtual int32_t GetTradeValue();
}
