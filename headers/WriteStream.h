class WriteStream {
  private:
    class Socket *m_sock;
    std::vector<unsigned char> m_buffer;

  public:
    WriteStream(class Socket *);
    void SetSocket(class Socket *);
    void Write8(uint8_t);
    void Write16(uint16_t);
    void Write32(uint32_t);
    void Write64(uint64_t);
    void WriteSaturated16(float);
    void WriteString(const std::string &);
    void WriteFloat(float);
    void WriteVector(const struct Vector3 &);
    void WriteVector16(const struct Vector3 &);
    void WriteRotation(const struct Rotation &);
    void WritePrecisionRotation(const struct Rotation &);
    void WriteSignedFraction(float);
    void Write(const class WriteStream &);
    void Write(const void *, size_t);
    void Flush();
    void Clear();
}
