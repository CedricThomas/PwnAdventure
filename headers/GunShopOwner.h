class GunShopOwner : public NPC {
  public:
    GunShopOwner();
    virtual std::string GetInitialState(class IPlayer *);
    virtual class std::vector<IItem*, std::allocator<IItem*> > GetShopItems();
    virtual const char * GetDisplayName();
}
