class TimerSet {
  private:
    class std::map<std::string, TimerSet::TimerEvent, std::less<std::string>, std::allocator<std::pair<std::string const, TimerSet::TimerEvent> > > m_timers;

  public:
    void Add(const std::string &, float, const class std::function<void ()> &);
    void AddWithContext(const std::string &, float, const class std::function<void (Actor *)> &);
    void AddRecurring(const std::string &, float, const class std::function<void ()> &);
    void AddRecurringWithContext(const std::string &, float, const class std::function<void (Actor *)> &);
    void Cancel(const std::string &);
    void Clear();
    void Tick(class Actor *, float);
}

void (struct TimerSet::TimerEvent * const, const struct TimerSet::TimerEvent &)
