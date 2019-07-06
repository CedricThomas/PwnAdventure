class CowLevelDestination : public FastTravelDestination {
  public:
    CowLevelDestination();
    virtual bool IsAvailable(class Player *);
}

class FastTravelDestination {
  private:
    std::string m_region;
    std::string m_displayName;

  public:
    FastTravelDestination(const std::string &, const std::string &);
    virtual bool IsAvailable(class Player *);
    void MarkAsVisited(class Player *);
    void AddToListIfValid(class std::vector<FastTravelInfo, std::allocator<FastTravelInfo> > &, class Player *, const std::string &);
}

class TownDestination : public FastTravelDestination {
  public:
    TownDestination();
    virtual bool IsAvailable(class Player *);
}
