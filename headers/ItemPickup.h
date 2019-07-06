class ItemPickup : public Actor {
  private:
    class IItem *m_item;
    std::string m_pickupName;

  public:
    ItemPickup(class IItem *, const std::string &, const std::string &);
    class IItem * GetItem() const;
    const std::string & GetPickupName() const;
    virtual bool CanUse(class IPlayer *);
    virtual void PerformUse(class IPlayer *);
}
