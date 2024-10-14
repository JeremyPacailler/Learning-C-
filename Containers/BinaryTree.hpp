#pragma once

#include <iostream>

namespace JPContainer {
	template<typename T>
	struct Node {
		T data;
		Node* left;
		Node* right;
		Node(T val) : data(val), left(nullptr), right(nullptr) {}
		
		void inorderTraversal(Node<T> * root)
		{
			if (root == nullptr)
				return;

			inorderTraversal(root->left);

			std::cout << root->data << " ";

			inorderTraversal(root->right);
		}
	};
}
