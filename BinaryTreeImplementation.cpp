#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int data;
	Node*left;
	Node*right;
	Node(int data)
	{
		this->data = data;
		this->left = nullptr;
		this->right = nullptr;
	}
};

struct Tree {
	Node*root;

	Tree()
	{
		this->root = nullptr;
	}

	void insertData(int data, Node*leaf)
	{
		if (data < leaf->data)
		{
			if (leaf->left != nullptr)
			{
				insertData(data, leaf->left);
			}
			else {
				leaf->left = new Node(data);
			}
		}
		else if (data >= leaf->data)
		{
			if (leaf->right != nullptr)
			{
				insertData(data, leaf->right);
			}
			else {
				leaf->right = new Node(data);
			}
		}
	}
	void insert(int data)
	{
		if (this->root != nullptr)
		{
			insertData(data, this->root);
		}
		else {
			this->root = new Node(data);
		}
	}

};
void inOrder(Node *root)
{
	if (root != nullptr)
	{
		inOrder(root->left);
		cout << root->data << endl;
		inOrder(root->right);
	}
}
void preOrder(Node*root)
{
	if (root != nullptr)
	{
		cout << root->data << endl;
		preOrder(root->left);
		preOrder(root->right);
	}
}
void postOrder(Node*root)
{
	if (root != nullptr)
	{
		postOrder(root->left);
		postOrder(root->right);
		cout << root->data << endl;
	}
}
int height(Node*root)
{
	if (root != nullptr)
	{
		int left = height(root->left);
		int right = height(root->right);

		if (left > right) return left + 1;
		else return right + 1;
	}
	else {
		return -1;
	}
}
void levelOrderTraversal(Node*root)
{
	if (root != nullptr)
	{
		queue<Node*>q;
		q.push(root);

		while (!q.empty())
		{
			Node*node = q.front();
			cout << node->data << endl;
			q.pop();

			if (node->left)
			{
				q.push(node->left);
			}
			if (node->right) {
				q.push(node->right);
			}
			
		}
	}
}
int getNodesCountOnLevel(Node*root, int current, int desired)
{
	if (root == nullptr)return 0;
	else if (current == desired) return 1;

	else {
		return getNodesCountOnLevel(root->left, current + 1, desired) 
			+ getNodesCountOnLevel(root->right, current + 1, desired);
	}
}
int traverse(Node*root, int depth, int level)
{
	int sum = 0;
	if (root == nullptr || depth > level)return 0;
	if (depth == level)sum+=root->data;
	else {
		if (root->left!=nullptr)
		{
			sum += traverse(root->left, depth + 1, level);
		}
		if (root->right != nullptr)
		{
			sum += traverse(root->right, depth + 1, level);
		}
	}
	return sum;
}
int sumNodesInLevel(Node*root,int level)
{
	return traverse(root, 0, level);
}
bool checkBST(Node*root)
{
	static int lastVisited = -2;
	if (root == nullptr)return true;
	if (checkBST(root->left) == false)return false;
	if (root->data <= lastVisited)return false;
	lastVisited = root->data;
	if (checkBST(root->right) == false)return false;

	return true;
};
int getLevelofNode(Node*root, int data)
{
	queue<Node*>q;
	int level = 0;
	q.push(root);
	q.push(nullptr);

	while (!q.empty())
	{
		Node*node = q.front();
		q.pop();

		if (node == nullptr) {
			if (q.front() != nullptr)
			{
				level++;
				q.push(nullptr);
			}
		}
		else {
			if (node->data == data)return level;
			if (node->left) q.push(node->left);
			if (node->right)q.push(node->right);
		}
	
	}
	return -1;
}
int countAll(Node*root)
{
	int count = 0;
	if (root != nullptr)
	{
		count++;
		if (root->left != nullptr) {
			count += countAll(root->left);
		}
		if (root->right != nullptr) {
			count += countAll(root->right);
		}
	}
	return count;
}
int countLeaves(Node*root)
{
	if (root == nullptr)return 0;
	int count = 0;
	if (root->left == nullptr &&root->right == nullptr)count++;
	
	count+=countLeaves(root->left) + countLeaves(root->right);
	return count;
}
int countInternal(Node*root)
{
	if (root == nullptr)return 0;
	int count = 0;
	if (root->left != nullptr || root->right != nullptr)count++;
	
	count+= countInternal(root->left) + countInternal(root->right);
	return count;
}
int sumAllNodes(Node*root)
{
	int sum = 0;
	if (root == nullptr)return 0;
	else {
		sum += root->data;
		if (root->left) {
			sum += sumAllNodes(root->left);
		}
		if (root->right)
		{
			sum += sumAllNodes(root->right);
		}
	}
	return sum;
}
int sumAllLeaves(Node*root)
{
	int sum = 0;
	if (root == nullptr)return 0;
	if (root->left == nullptr&&root->right == nullptr)
	{
		sum += root->data;
	}
	else {
		if (root->left)
		{
			sum += sumAllLeaves(root->left);
		}
		if (root->right)
		{
			sum += sumAllLeaves(root->right);
		}
	}
	return sum;
}
int main()
{
	Tree *tree = new Tree();
	tree->insert(10);
	tree->insert(4);
	tree->insert(11);
	tree->insert(3);

	tree->insert(5);
	tree->insert(16);
	tree->insert(1);
	tree->insert(6);


	inOrder(tree->root);
	preOrder(tree->root);
	postOrder(tree->root);
	cout << height(tree->root) << endl;
	cout << getNodesCountOnLevel(tree->root, 1, 3) << endl;
	cout << sumNodesInLevel(tree->root, 2)<<endl;
	cout << getLevelofNode(tree->root, 1) << endl;
	levelOrderTraversal(tree->root);
	
	cout << countAll(tree->root) << endl;
	cout << countInternal(tree->root) << endl;
	cout << countLeaves(tree->root) << endl;
	cout << sumAllNodes(tree->root) << endl;
	cout << sumAllLeaves(tree->root) << endl;
	system("pause");
	return 0;
}