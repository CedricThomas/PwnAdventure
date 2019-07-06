class MichaelAngelo : public NPC {
  public:
    MichaelAngelo();
    virtual std::string GetInitialState(class IPlayer *);
    virtual void OnTransitionTaken(class IPlayer *, const std::string &, const std::string &);
    virtual const char * GetDisplayName();
}
