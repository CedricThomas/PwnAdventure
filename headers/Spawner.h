class Spawner : public AIZoneListener {
  protected:
    class std::vector<ActorRef<Actor>, std::allocator<ActorRef<Actor> > > m_actors;
    struct Vector3 m_position;
    struct Rotation m_rotation;
    size_t m_maxActors;
    float m_maxSpawnTimer;
    float m_currentSpawnTimer;

  public:
    Spawner(const std::string &, const struct Vector3 &, const struct Rotation &, size_t, float);
    virtual void OnAIZoneActivated();
    virtual void OnAIZoneDeactivated();
    virtual void Tick(float);
    virtual class Actor * Spawn();
    void RemoveActor(class Actor *);
    virtual size_t GetMaxActors();
    virtual float GetSpawnTimer();
}
