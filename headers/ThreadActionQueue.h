class ThreadActionQueue {
  private:
    class std::mutex m_mutex;
    class std::vector<std::function<void ()>, std::allocator<std::function<void ()> > > m_actions;

    class std::vector<std::function<void ()>, std::allocator<std::function<void ()> > > GetActionsForThisTick();
  public:
    void Enqueue(const class std::function<void ()> &);
    void Process();
    void Clear();
}
