
using namespace std;
struct Node
{
    int data;
    char val;
    Node *left,*right;
    Node(int a,char b)
    {
        left=NULL;
        right=NULL;
        this->val=b;
        this->data=a;
    }
    
};
struct compare
{
bool operator()(Node *a,Node *b)
{
    return(a->data>b->data);
}};
void printme(Node *root,string s)
{
    if(root==NULL)return;
    if(root->val!='%')
    {
        cout<<s<<" ";
    }
    printme(root->left,s+'0');
    printme(root->right,s+'1');
}
void func(int arr[],int len,string s)
{
    priority_queue<Node*,vector<Node*>,compare>que;
    for(int j=0;j<len;j++)
    {
        que.push(new Node(arr[j],s[j]));
    }
    Node *left,*right,*top;
    while(que.size()>1)
    {
        left=que.top();
        que.pop();
        right=que.top();
        que.pop();
        top=new Node(left->data+right->data,'%');
        que.push(top);
        top->left=left;
        top->right=right;
    }
    printme(top,"");
}
int main() {
	//code
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	    string s;
	    cin>>s;
	    int arr[s.length()];
	    for(int j=0;j<s.length();j++)
	    {
	        cin>>arr[j];
	    }
	    func(arr,s.length(),s);
	    cout<<'\n';
	}
	return 0;
}
