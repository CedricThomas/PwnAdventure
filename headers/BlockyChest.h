class BlockyChest : public Actor {
  public:
    BlockyChest();
    virtual bool CanUse(class IPlayer *);
    virtual void PerformUse(class IPlayer *);
}
