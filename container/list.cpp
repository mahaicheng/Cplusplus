template <typename T>
class list {
  struct Node {
    T _val;
    Node *_prev;
    Node *_next;
    Node(T val, prev = nullptr, next = nullptr)
        : _val(val), _prev(prev), _next(next) {}
  }

  public : list();
  explicit list(size_t n);
  ~list();

 private:
  size_t _size;
  Node *_head;
  Node *_tail;
};