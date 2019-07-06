class PvPKill : public Item {
  public:
    virtual uint32_t GetMaximumCount();
    virtual const char * GetName();
    virtual const char * GetDisplayName();
    virtual const char * GetItemTypeName();
    virtual const char * GetDescription();
    virtual const char * GetFlavorText();
    virtual enum ItemRarity GetItemRarity();
    virtual int32_t GetTradeValue();
    virtual bool ShowInInventory();
    virtual bool ShowNotificationOnPickup();
}
