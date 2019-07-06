class JustinTolerable : public NPC {
  public:
    JustinTolerable();
    virtual std::string GetInitialState(class IPlayer *);
    virtual void OnTransitionTaken(class IPlayer *, const std::string &, const std::string &);
    virtual int32_t GetSellPriceForItem(class IItem *);
    virtual const char * GetDisplayName();
}
