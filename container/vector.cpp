namespace hchma
{
    template<typename T>
    class vector
    {
    typedef T* iterator;
    typedef T const* const_iterator;
    
    public:
    vector()
    {
        _capacity = 16;
        _size = 0;
        _array = new T[_capacity];
    }
    explicit vector(size_t n)
    {
        _capacity = n * 2;
        _array = new T[n];
    }
    vector(const vector &rhs)
    {
        _size = rhs._size;
        _capacity = rhs._capacity;
        _array = new T[_size];
        for (size_t i = 0; i < _size; ++i)
        {
            _array[i] = rhs._array[i];
        }
    }
    ~vector()
    {
        if (_array != nullptr)
        {
            delete []_array;
            _array = nullptr;
        }
    }
    const vector& operator=(const vector &rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }

        _size = rhs._size;
        _capacity = rhs._capacity;
        T *oldPtr = _array;
        T *tmp = new T[_capacity];
        for (size_t i = 0; i < _size; ++i)
        {
            tmp[i] = rhs._array[i];
        }

        _array = tmp;
        if (oldPtr != nullptr)
        {
            delete []oldPtr;
            oldPtr = nullptr;
        }
        return *this;
    }

    T& operator[](size_t pos)
    {
        return _array[pos];
    }

    const T& operator[](size_t pos) const
    {
        return _array[pos];
    }

    size_t size() const
    {
        return _size;
    }
    size_t empty() const
    {
        return _size == 0;
    }

    void push_back(const T &element)
    {
        if (_size == _capacity)
        {
            reserve();
        }
        _array[_size] = element;
        ++_size;
    }
    T pop_back()
    {
        T result = _array[_size];
        --_size;
        return result;
    }
    const T& front() const
    {
        return _array[0];
    }
    T& front()
    {
        return _array[0];
    }
    const T& back() const
    {
        return _array[_size-1];
    }

    T& back()
    {
        return _array[_size-1];
    }

    iteator begin()
    {
        return &_array[0];
    }
    const_iteator begin() const
    {
        return &_array[0];
    }
    iterator end()
    {
        return &_array[_size];
    }
    const_iterator end() const
    {
        return &_array[_size];
    }
    private:
    int _size;
    int _capacity;
    T *_array;
    };
}