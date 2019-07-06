class CowChest : public Actor {
  public:
    CowChest();
    virtual bool CanUse(class IPlayer *);
    virtual void PerformUse(class IPlayer *);
}
