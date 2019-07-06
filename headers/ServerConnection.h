class ServerConnection {
  protected:
    bool m_running;
    bool m_valid;
    bool m_readyToDisconnect;
    class std::thread m_thread;
    class std::mutex m_mutex;
    class std::queue<std::function<void ()>, std::deque<std::function<void ()>, std::allocator<std::function<void ()> > > > m_serverQueue;
    class std::condition_variable m_serverQueueEvent;
    class ThreadActionQueue m_gameThreadActions;

    void ThreadProc();
    void StartConnectionThread();
    void ServerEnqueue(const class std::function<void ()> &);
    void ServerProcess(const class std::function<void ()> &);
    virtual const char * GetServerType();
  public:
    ServerConnection();
    virtual ~ServerConnection();
    bool IsValid() const;
    bool IsReadyToDisconnect() const;
    void ProcessGameThreadActions();
    void Disconnect();
}
