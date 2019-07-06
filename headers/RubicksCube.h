class RubicksCube : public Item {
  private:
    bool CanStealItem(class Player *, class IItem *);
  public:
    virtual const char * GetName();
    virtual const char * GetDisplayName();
    virtual const char * GetItemTypeName();
    virtual const char * GetDescription();
    virtual const char * GetFlavorText();
    virtual uint32_t GetMaximumCount();
    virtual enum ItemRarity GetItemRarity();
    virtual bool CanEquip();
    virtual bool ShowEventOnPickup();
    virtual float GetCooldownTime();
    virtual bool CanActivate(class IPlayer *);
    virtual void PerformActivate(class IPlayer *);
}
