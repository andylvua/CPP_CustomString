class my_str_t{
private:
    char* data_m;
    size_t capacity_m;
    size_t size_m;
public:
    my_str_t(size_t size, char initial);

    my_str_t(const char* cstr);

    my_str_t(const std::string& str);

    my_str_t(const my_str_t& mystr);

    my_str_t& operator=(const my_str_t& mystr);

    void swap(my_str_t& other) noexcept;

    char& operator[](size_t idx);

    const char& operator[](size_t idx) const;

    char& at(size_t idx);

    const char& at(size_t idx) const;

    void reserve(size_t new_capacity);

    void shrink_to_fit();

    void resize(size_t new_size, char new_char = ' ');

    void clear();

    void insert(size_t idx, const my_str_t& str);

    void insert(size_t idx, const char* cstr);

    void append(const my_str_t& str);

    void append(char c);

    void append(const char* cstr);

    void erase(size_t begin, size_t size);

    size_t size() const noexcept;

    size_t capacity() const noexcept;

    const char* c_str() const {return 0;};

    static constexpr size_t not_found = -1;

    size_t find(char c, size_t idx = 0);

    size_t find(const std::string& str, size_t idx = 0);
    size_t find(const char& cstr, size_t idx = 0);

    my_str_t substr(size_t gegin, size_t size);

    ~my_str_t();
};
