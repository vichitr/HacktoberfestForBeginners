class LRUCache : public Cache
{
public:
    LRUCache(int capacity)
    {
        cp = capacity;
    }
    void set(int key, int value)
    {
        Node *node;
        if (mp.empty())
        {
            node = new Node(key, value);
            tail = head = node;
            mp[key] = node;
            return;
        }
        auto it = mp.find(key);
        if (it != mp.end())
        {
            it->second->value = value;
            if (head == it->second)
            {
                return;
            }
            it->second->prev->next = it->second->next;
            if (tail == it->second)
            {
                tail = tail->prev;
            }
            else
            {
                it->second->next->prev = it->second->prev;
            }
            it->second->next = head;
            it->second->prev = nullptr;
            head->prev = it->second;
            head = it->second;
        }
        else
        {
            node = new Node(head->prev, head, key, value);
            head->prev = node;
            head = node;
            mp[key] = node;
            if (mp.size() > cp)
            {
                tail = tail->prev;
                mp.erase(tail->next->key);
                delete tail->next;
                tail->next = nullptr;
            }
        }
    }
    int get(int key)
    {
        auto it = mp.find(key);
        if (it != mp.end())
        {
            return it->second->value;
        }
        return -1;
    }
};