class cNode
{
	int data;
	int priority;
public:
	cNode *next;
	cNode();
	cNode(int d);
	cNode(int d, int p);
	int getData();
	cNode* setData(int data);
	void print()const;
    int getPriority() const;
	void setPriority(int prior);
	~cNode();
};

