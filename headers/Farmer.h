class Farmer : public NPC {
  public:
    Farmer();
    virtual void OnTransitionTaken(class IPlayer *, const std::string &, const std::string &);
    virtual std::string GetInitialState(class IPlayer *);
    virtual const char * GetDisplayName();
}
