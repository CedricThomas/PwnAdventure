class BlueDrop : public Drop {
  public:
    BlueDrop();
    BlueDrop(const class std::map<IItem*, unsigned int, std::less<IItem*>, std::allocator<std::pair<IItem* const, unsigned int> > > &);
}

class Drop : public Actor {
  private:
    class std::map<IItem*, unsigned int, std::less<IItem*>, std::allocator<std::pair<IItem* const, unsigned int> > > m_items;
    bool m_used;

  public:
    Drop(const class std::map<IItem*, unsigned int, std::less<IItem*>, std::allocator<std::pair<IItem* const, unsigned int> > > &, const std::string &);
    virtual bool CanUse(class IPlayer *);
    virtual void PerformUse(class IPlayer *);
    virtual bool ShouldSendPositionUpdates();
    static class Drop * SpawnDrop(const class std::map<IItem*, unsigned int, std::less<IItem*>, std::allocator<std::pair<IItem* const, unsigned int> > > &, const struct Vector3 &);
}

class GreenDrop : public Drop {
  public:
    GreenDrop();
    GreenDrop(const class std::map<IItem*, unsigned int, std::less<IItem*>, std::allocator<std::pair<IItem* const, unsigned int> > > &);
}

class PurpleDrop : public Drop {
  public:
    PurpleDrop();
    PurpleDrop(const class std::map<IItem*, unsigned int, std::less<IItem*>, std::allocator<std::pair<IItem* const, unsigned int> > > &);
}

class WhiteDrop : public Drop {
  public:
    WhiteDrop();
    WhiteDrop(const class std::map<IItem*, unsigned int, std::less<IItem*>, std::allocator<std::pair<IItem* const, unsigned int> > > &);
}
