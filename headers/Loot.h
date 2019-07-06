struct LootEntry {
    class IItem *item;
    uint32_t minCount;
    uint32_t maxCount;
    float weight;
}

class LootTable {
  private:
    float m_dropChance;
    class std::vector<LootTable::TableEntry, std::allocator<LootTable::TableEntry> > m_tiers;
    class std::vector<LootTable::TableEntry, std::allocator<LootTable::TableEntry> > m_counts;
    float m_totalTierWeight;
    float m_totalCountWeight;
    class std::vector<LootEntry, std::allocator<LootEntry> > m_additionalItems;

    uint32_t GetRandomCount();
    struct LootEntry GetRandomItem();
  public:
    LootTable();
    void SetDropChance(float);
    void SetTiers(uint32_t, uint32_t, float);
    void SetCounts(uint32_t, uint32_t, float);
    void AddAdditionalItem(class IItem *, uint32_t, uint32_t, float);
    class std::map<IItem*, unsigned int, std::less<IItem*>, std::allocator<std::pair<IItem* const, unsigned int> > > GetItems();
}

struct LootTable::TableEntry {
    uint32_t value;
    float weight;
}

class LootTier {
  private:
    class std::vector<LootEntry, std::allocator<LootEntry> > m_loot;
    float m_totalWeight;

  public:
    LootTier();
    void SetEmptyWeight(float);
    void AddItem(class IItem *, uint32_t, uint32_t, float);
    struct LootEntry GetItem();
}
