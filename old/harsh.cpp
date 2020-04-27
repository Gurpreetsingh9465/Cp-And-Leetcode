#include <bits/stdc++.h>
using namespace std;
typedef struct type
{
	int value;
	struct type* left;
	struct type* right;
	int status;
}Node;
class BST
{
	int num;
	Node * root, * start_ptr,*ptr,*pre_ptr;
	public:
		BST()
		{
			cout << "Enter first element \n";
			cin >> num;
			root = (Node *)malloc(sizeof(Node));
			root->left= NULL;
			root->right = NULL;
			root->status = 0;
			root->value = num;
			start_ptr = root;
		}
        void Inorder(Node * node,queue<Node*> &q)
        {
            if(node->left != NULL)
            {
                Inorder(node->left,q);
            }
            q.push(node);
            if(node->right!= NULL)
            {
                Inorder(node->right,q);
            }
        }
        void insert_node(int num,Node * temp)
		{
			if(temp == NULL)
			{
				root = (Node *)malloc(sizeof(Node));
				root->value =num;
				root->left = NULL;
				root->right= NULL;
                root->status = 0;
				if(num>pre_ptr->value)
				{
					pre_ptr -> right = root;
				}
				else if(num < pre_ptr->value)
				{
					pre_ptr->left = root;
				}
				return ;
			}
			else if(num > temp->value)
			{
				pre_ptr = temp;
				insert_node(num , temp->right);
			}
			else if(num < temp->value)
			{
				pre_ptr = temp;
				insert_node(num , temp->left);
			}
		}
		Node* get_start_ptr()
		{
			return start_ptr;
		}
		void display(Node *root)
		{
			if(root ->left != NULL)
			{
				display(root->left);
			}
			cout << endl<< root->status<< " -->"<<root->value;

			if(root->right!= NULL)
			{
				display(root->right);
			}
		}
};
int main()
{
    BST obj;
    int num;
    while(1)
    {
        cout<<"Enter the value(Enter -1 to exit)";
        cin >> num;
        if(num == -1)
        {
        	break;
		}
		else
			obj.insert_node(num,obj.get_start_ptr());
    }
    obj.display(obj.get_start_ptr());
    queue<Node*> q;
    obj.Inorder(obj.get_start_ptr(),q);
    queue<Node*> tmp_q = q;
    cout<<"HELLO I M HERE \n";
    cout<<"  --> " <<tmp_q.empty()<<endl;

    while(1)
    {
        cout<<"  --> "<<tmp_q.empty();
        cout<<"AND HERE also\n";
        Node * q_element = tmp_q.front();
        std::cout << q_element->value <<"\n";
        tmp_q.pop();
    }
    while(q.empty())
    {
        cout <<"IN WHILE LOOP \n";
        Node * temp;
        temp = q.front();
        cout<<"TEMP KI VALUE H "<< temp->value <<endl;
        q.pop();
        if(temp->right == NULL)
        {
            temp->status = 1;
            cout <<"iSKA RIGHT TO NULL H STatus 1 hona chahiye ->"<< temp->status << " --> " << temp->value <<endl;
            if(q.empty())
            {
                cout<<"maybe end "<<endl;
                temp->right = q.front();
                temp->status = -1;
            }
        }
    }
    cout <<"After the stuff" << endl ;
    obj.display(obj.get_start_ptr());
    return 0;
}