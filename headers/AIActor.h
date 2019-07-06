class AIActor : public Actor {
  protected:
    class std::map<std::string, AIState*, std::less<std::string>, std::allocator<std::pair<std::string const, AIState*> > > m_states;
    class AIState *m_initialState;
    class AIState *m_currentState;
    class ActorRef<Actor> m_target;

    void AddInitialState(const std::string &, class AIState *);
    void AddState(const std::string &, class AIState *);
  public:
    AIActor(const std::string &);
    virtual ~AIActor();
    virtual bool IsCharacter();
    virtual bool ShouldSendPositionUpdates();
    virtual bool ShouldReceivePositionUpdates();
    class Actor * GetTarget() const;
    virtual bool ShouldTargetPlayer(class Player *);
    virtual bool ShouldAttackFromRange() const;
    virtual float GetRangedAttackDistance() const;
    virtual bool ShouldWander() const;
    virtual bool ShouldMove() const;
    virtual bool ShouldAttack() const;
    virtual bool ShouldAttackMultipleTargets() const;
    virtual void Tick(float);
    virtual void OnAIMoveComplete();
    class AIState * GetStateByName(const std::string &);
    void TransitionToState(const std::string &, class Actor *);
    virtual void TransitionToState(class AIState *, class Actor *);
}

class AIState {
  protected:
    class AIActor *m_owner;
    class TimerSet m_timers;

  public:
    AIState(class AIActor *);
    virtual ~AIState();
    class AIActor * GetOwner() const;
    class Actor * GetTarget() const;
    virtual void EnterState(class Actor *);
    virtual void LeaveState();
    virtual void Tick(float);
    virtual void OnAIMoveComplete();
    void AddTimer(const std::string &, float, const class std::function<void ()> &);
    void AddTimerWithContext(const std::string &, float, const class std::function<void (Actor *)> &);
    void AddRecurringTimer(const std::string &, float, const class std::function<void ()> &);
    void AddRecurringTimerWithContext(const std::string &, float, const class std::function<void (Actor *)> &);
    void CancelTimer(const std::string &);
    void CancelAllTimers();
}

class DeadState : public AIState {
  public:
    DeadState(class AIActor *);
}
