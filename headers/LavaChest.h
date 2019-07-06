class LavaChest : public Actor {
  public:
    LavaChest();
    virtual bool CanUse(class IPlayer *);
    virtual void PerformUse(class IPlayer *);
}
