#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>
using namespace std;
class TNode
{
public:
	int keyno;
	int password;
	string userName;
	int symptoms;
	int immuneLevel;
	int severity;
	string cityName;
	TNode* left;
	TNode* right;
	TNode()
	{
		keyno = 0;
		password = 0;
		userName = " ";
		cityName = " ";
		symptoms = 0;
		immuneLevel = 0;
		severity = 0;
		left = right = NULL;
	}

	TNode(int dkeyno,int pp,string uu,string ct,int sy,int ul,int sv)
	{
		keyno = dkeyno;
		password = pp;
		userName = uu;
		cityName = ct;
		symptoms = sy;
		immuneLevel = ul;
		severity = sv;
		
		left = right = NULL;
	}
};

class BST
{
public:
	TNode* root;
	BST()
	{
		root = NULL;
	}

	void insert(TNode* T, int dkeyno, int pp, string uu, string ct, int sy, int ul, int sv) //to insert a node of given value
	{
		TNode* p = NULL;
		while (T != NULL)
		{
			p = T;
			if (sv < T->severity)
				T = T->left;
			else if (dkeyno >= T->severity)
				T = T->right;
			
		}
		TNode* temp = new TNode;
		temp->keyno = dkeyno;
		temp->password = pp;
		temp->userName = uu;
		temp->cityName = ct;
		temp->symptoms = sy;
		temp->immuneLevel = ul;
		temp->severity = sv;
		temp->left = NULL;
		temp->right = NULL;

		if (p == 0)
			root = temp;
		else if (sv < p->severity)
			p->left = temp;
		else if (sv > p->severity)
			p->right = temp;
		cout << "severity " << sv << " Inserted\n";
	}

	bool search(TNode* T, int i) //to search a node of given value
	{
		if (T == NULL)
			return false;
		else if (T->severity == i)
			return true;
		else if (T->severity < i)
			return search(T->right, i);
		else if (T->severity > i)
			return search(T->left, i);
	}

	TNode* getParent(TNode* T, int i) //to return the parent of a given node
	{
		if ((T->left->severity == i) || (T->right->severity == i))
			return T;
		else if (i < T->severity)
			return getParent(T->left, i);
		else if (i > T->severity)
			return getParent(T->right, i);
	}

	TNode* findmin(TNode* T) //to find the minimum value of the given BST or subtree 
	{
		if (T->left == NULL)
			return T;
		else
			return findmin(T->left);
	}

	TNode* delete_node(TNode* T, int i) //to search and delete a node of given value 
	{
		if (T == NULL)
		{
			cout << "\nEmpty Tree\n";
			return T;
		}
		else if (i < T->severity)
			T->left = delete_node(T->left, i);
		else if (i > T->severity)
			T->right = delete_node(T->right, i);
		else {
			// No child
			if (T->left == NULL && T->right == NULL)
			{
				delete T;
				T = NULL;
			}
			//One child 
			else if (T->left == NULL)
			{
				TNode* temp = T;
				T = T->right;
				delete temp;
			}
			else if (T->right == NULL)
			{
				TNode* temp = T;
				T = T->left;
				delete temp;
			}
			// 2 children
			else
			{
				class TNode* temp = findmin(T->right);
				T->severity = temp->severity;
				T->right = delete_node(T->right, temp->severity);
			}
		}
		return T;
	}

	bool isEmpty() //to check if the BST is empty
	{
		if (root == NULL)
			return true;
		else
			return false;
	}

	void in_orderTraverse(TNode* T) //to display the values of BST in ascending order 
	{
		if (T == NULL)
		{
			return;
		}
		else
		{


			in_orderTraverse(T->left);
			cout << "Severity Level: " << T->severity << endl;
			cout << "Patien Acc Key no: " << T->keyno << endl;
			cout << "Patient name: " << T->userName << endl;
			cout << "Patient password: " <<T->password << endl;
			cout << "Patient city_name: " << T->cityName << endl;
			if (T->symptoms == 1)
			{
				cout << "Symptom is Cough\n";
			}
			if (T->symptoms == 2)
			{
				cout << "Symtom is Fever\n";
			}
			if (T->symptoms == 3)
			{
				cout << "Symptom is Tiredness\n";
			}
			cout << "Immune Level: " << T->immuneLevel << endl<<endl;
			in_orderTraverse(T->right);
		}
	}

	bool isPresent(TNode* T, int i)
	{
		bool found = false;
		for (;;)
		{
			if (T == NULL)
				break;
			if (i < T->keyno)
				T = T->left;
			else if (i > T->keyno)
				T = T->right;
			else if (i == T->keyno)
			{
				found = true;
				break;
			}
		}
		return found;
	}
};
