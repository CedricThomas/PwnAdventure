class DisconnectException : public std::exception {
  private:
    std::string m_message;

  public:
    DisconnectException();
    DisconnectException(const std::string &);
    virtual const char * what() const;
}

class NetworkException : public std::exception {
  private:
    std::string m_message;

  public:
    NetworkException();
    NetworkException(const std::string &);
    virtual const char * what() const;
}

class SSLSocket : public Socket {
  private:
    SSL *m_ssl;

  public:
    SSLSocket(SSL *);
    virtual ~SSLSocket();
    virtual bool Read(void *, size_t);
    virtual bool Write(const void *, size_t);
}

class Socket {
  protected:
    std::string m_lastErrorMessage;

  public:
    virtual ~Socket();
    virtual bool Read(void *, size_t);
    virtual bool Write(const void *, size_t);
    void ReadChecked(void *, size_t);
    uint8_t Read8();
    uint16_t Read16();
    uint32_t Read32();
    uint64_t Read64();
    std::string ReadString();
    float ReadFloat();
    struct Vector3 ReadVector();
    struct Vector3 ReadVector16();
    struct Rotation ReadRotation();
    struct Rotation ReadPrecisionRotation();
    float ReadSignedFraction();
    const std::string & GetLastErrorMessage() const;
}

class TCPSocket : public Socket {
  private:
    int m_socket;

  public:
    TCPSocket(int);
    virtual ~TCPSocket();
    virtual bool Read(void *, size_t);
    virtual bool Write(const void *, size_t);
}
