#include<iostream>
#include <string>k
using namespace std;

class BinaryTree
{
private:
	struct TreeNode
	{
		int employeeID;
		string name;
		int startsWith = 0;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int employeeID1,
			string name1,
			TreeNode* left1 = nullptr,
			TreeNode* right1 = nullptr)
		{
			employeeID = employeeID1;
			name = name1;
			left = left1;
			right = right1;
		}
	};

	TreeNode* root;

	int startWith(TreeNode*&, char);
	void insert(TreeNode*&, int, string);

public:
	BinaryTree()
	{
		root = nullptr;
	}
	int startsWith(char start)
	{
		startWith(root, start);
	}
	void insert(int id, string name)
	{
		insert(root, id, name);
	}
	
};

int BinaryTree::startWith(TreeNode*& tree, char start)
{
	int num = 0;
	if (tree == nullptr)
		return 0;
	else if (tree->name.at(0) == start)
		return 1;
	else
	{
		num += startWith(tree->left, start);
		num += startWith(tree->right, start);
		return num;
	}
}

void BinaryTree::insert(TreeNode*& tree, int id, string name)
{
	if (!tree)
	{
		tree = new TreeNode(id, name);
		return;
	}

	if (tree->employeeID == id)
		return;

	if (id < tree->employeeID)
	{
		insert(tree->left, id, name);
	}
	else
	{
		insert(tree->right, id, name);
	}
}


int main()
{
	BinaryTree employeeList;
	employeeList.insert(1021, "John Williams");
	employeeList.insert(1057, "Bill Witherspoon");
	employeeList.insert(2487, "Jennifer Twain");
	employeeList.insert(3769, "Sophia Lancaster");
	employeeList.insert(1017, "Debbie Reece");
	employeeList.insert(1275, "George McMullen");
	employeeList.insert(1899, "Ashley Smith");
	employeeList.insert(4218, "Josh Plemmons");

	int a = employeeList.startsWith('A');
	cout << a;
}