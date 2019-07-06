class Achievement : public IAchievement {
  private:
    std::string m_name;
    std::string m_displayName;
    std::string m_description;

  public:
    Achievement(const std::string &, const std::string &, const std::string &);
    virtual const char * GetName();
    virtual const char * GetDisplayName();
    virtual const char * GetDescription();
}

class AchievementList : public IAchievementList {
  private:
    class std::vector<IAchievement*, std::allocator<IAchievement*> > m_list;

  public:
    AchievementList(const class std::vector<IAchievement*, std::allocator<IAchievement*> > &);
    virtual size_t GetCount();
    virtual class IAchievement * GetAchievement(size_t);
    virtual void Destroy();
}

class IAchievement {
  public:
    virtual const char * GetName();
    virtual const char * GetDisplayName();
    virtual const char * GetDescription();
}

class IAchievementList {
  public:
    virtual ~IAchievementList();
    virtual size_t GetCount();
    virtual class IAchievement * GetAchievement(size_t);
    virtual void Destroy();
}
