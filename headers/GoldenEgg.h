class BallmerPeakEgg : public ItemPickup {
  public:
    BallmerPeakEgg();
    virtual bool CanUse(class IPlayer *);
}

class GoldenEgg : public Item {
  public:
    virtual bool ShowEventOnPickup();
    virtual bool ShowEventOnDuplicatePickup();
    virtual const char * GetName();
    virtual const char * GetDisplayName();
    virtual const char * GetItemTypeName();
    virtual const char * GetDescription();
    virtual const char * GetFlavorText();
    virtual enum ItemRarity GetItemRarity();
}

class GoldenEggPickup<1> : public ItemPickup {
  private:
    static std::string GetNameForEgg(int);
  public:
    GoldenEggPickup();
}

class GoldenEggPickup<2> : public ItemPickup {
  private:
    static std::string GetNameForEgg(int);
  public:
    GoldenEggPickup();
}

class GoldenEggPickup<3> : public ItemPickup {
  private:
    static std::string GetNameForEgg(int);
  public:
    GoldenEggPickup();
}

class GoldenEggPickup<4> : public ItemPickup {
  private:
    static std::string GetNameForEgg(int);
  public:
    GoldenEggPickup();
}

class GoldenEggPickup<5> : public ItemPickup {
  private:
    static std::string GetNameForEgg(int);
  public:
    GoldenEggPickup();
}

class GoldenEggPickup<6> : public ItemPickup {
  private:
    static std::string GetNameForEgg(int);
  public:
    GoldenEggPickup();
}

class GoldenEggPickup<7> : public ItemPickup {
  private:
    static std::string GetNameForEgg(int);
  public:
    GoldenEggPickup();
}

class GoldenEggPickup<8> : public ItemPickup {
  private:
    static std::string GetNameForEgg(int);
  public:
    GoldenEggPickup();
}

class GoldenEggPickup<9> : public ItemPickup {
  private:
    static std::string GetNameForEgg(int);
  public:
    GoldenEggPickup();
}
