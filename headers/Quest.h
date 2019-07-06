class IQuest {
  public:
    virtual const char * GetName();
    virtual const char * GetDescription();
    virtual class IQuestState * GetStartingState();
    virtual class IQuestState * GetStateByName(const char *);
}

class IQuestState {
  public:
    virtual const char * GetName();
    virtual const char * GetDescription();
    virtual void CheckForEarlyCompletion(class IPlayer *);
    virtual void OnItemAcquired(class IPlayer *, class IItem *);
    virtual void OnItemPickupUsed(class IPlayer *, const char *);
}

class ItemQuestState : public QuestState {
  private:
    class IItem *m_item;
    std::string m_nextState;

  public:
    ItemQuestState(class Quest *, const std::string &, const std::string &, class IItem *, const std::string &);
    virtual void CheckForEarlyCompletion(class IPlayer *);
    virtual void OnItemAcquired(class IPlayer *, class IItem *);
}

class PickupQuestState : public QuestState {
  private:
    std::string m_pickupName;
    std::string m_nextState;

  public:
    PickupQuestState(class Quest *, const std::string &, const std::string &, const std::string &, const std::string &);
    virtual void CheckForEarlyCompletion(class IPlayer *);
    virtual void OnItemPickupUsed(class IPlayer *, const char *);
}

class Quest : public IQuest {
  protected:
    std::string m_name;
    std::string m_description;
    class std::map<std::basic_string<char>, IQuestState*, std::less<std::basic_string<char> >, std::allocator<std::pair<std::basic_string<char> const, IQuestState*> > > m_states;
    class IQuestState *m_startState;

  public:
    Quest(const std::string &, const std::string &);
    void AddState(class IQuestState *);
    void AddStartingState(class IQuestState *);
    virtual const char * GetName();
    virtual const char * GetDescription();
    virtual class IQuestState * GetStartingState();
    virtual class IQuestState * GetStateByName(const char *);
}

class QuestState : public IQuestState {
  protected:
    class Quest *m_quest;
    std::string m_name;
    std::string m_description;

    void AdvanceToState(class IPlayer *, const std::string &);
  public:
    QuestState(class Quest *, const std::string &, const std::string &);
    virtual const char * GetName();
    virtual const char * GetDescription();
    virtual void CheckForEarlyCompletion(class IPlayer *);
    virtual void OnItemAcquired(class IPlayer *, class IItem *);
    virtual void OnItemPickupUsed(class IPlayer *, const char *);
}
