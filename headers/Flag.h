class Flag : public Item {
  private:
    bool m_updating;
    bool m_submitted;
    std::string m_description;
    std::string m_submitMessage;

  public:
    Flag();
    virtual bool ShowEventOnPickup();
    virtual uint32_t GetMaximumCount();
    virtual const char * GetItemTypeName();
    virtual const char * GetDescription();
    virtual const char * GetFlavorText();
    virtual enum ItemRarity GetItemRarity();
    virtual bool CanActivate(class IPlayer *);
    virtual void Activate(class IPlayer *);
    virtual bool CanActivateInInventory();
    virtual void Reset();
    virtual void Update();
    virtual bool IsDynamic();
    virtual bool IsUpdating();
}

class FlagOfTheBear : public Flag {
  public:
    virtual const char * GetName();
    virtual const char * GetDisplayName();
}

class FlagOfTheBlock : public Flag {
  public:
    virtual const char * GetName();
    virtual const char * GetDisplayName();
}

class FlagOfTheCow : public Flag {
  public:
    virtual const char * GetName();
    virtual const char * GetDisplayName();
}

class FlagOfTheEggHunter : public Flag {
  public:
    virtual const char * GetName();
    virtual const char * GetDisplayName();
}

class FlagOfTheLava : public Flag {
  public:
    virtual const char * GetName();
    virtual const char * GetDisplayName();
}

class FlagOfTheOverachiever : public Flag {
  public:
    virtual const char * GetName();
    virtual const char * GetDisplayName();
}

class FlagOfThePirate : public Flag {
  public:
    virtual const char * GetName();
    virtual const char * GetDisplayName();
}
