class BearChest : public Actor {
  private:
    class std::vector<ActorRef<Bear>, std::allocator<ActorRef<Bear> > > m_bears;
    class std::map<ActorRef<IPlayer>, float, std::less<ActorRef<IPlayer> >, std::allocator<std::pair<ActorRef<IPlayer> const, float> > > m_playerTimeLeft;

    void UpdatePlayerAttacks();
    float GetMinimumTimeRemaining();
  public:
    BearChest();
    virtual bool CanUse(class IPlayer *);
    virtual void PerformUse(class IPlayer *);
    void AddBear(class Bear *);
    void RemoveBear(class Bear *);
    virtual void Tick(float);
    bool IsEliteStage();
    bool IsArmedStage();
    size_t GetQuestPlayerCount() const;
}
