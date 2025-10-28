#pragma once

namespace mystd {

	template<typename TKey, typename TValue>
	class BTree
	{
	private:
		template<typename TKey, typename TValue>
		class Node
		{
		public:
			TKey key;
			TValue value;
			Node* pLeft = nullptr;
			Node* pRight = nullptr;

			Node(const TKey& key, const TValue& value) : key(key), value(value) {}

			void print()
			{
				if (pLeft != nullptr) pLeft->print();
				cout << value << " ";
				if (pRight != nullptr) pRight->print();
			}
			void del()
			{
				if (pLeft != nullptr) pLeft->del();
				if (pRight != nullptr) pRight->del();
				delete this;
			}
			TValue* getValue(const TKey& key)
			{
				if (key == this->key) return &value;
				else if (key < this->key && pLeft != nullptr) return pLeft->getValue(key);
				else if (key > this->key && pRight != nullptr) return pRight->getValue(key);
				else return nullptr;
			}
		};

		Node<TKey, TValue>* push_r(const TKey& key, const TValue& value, Node<TKey, TValue>*& node)
		{
			if (!node)
			{
				node = new Node<TKey, TValue>(key, value);
				return node;
			}

			if (key < node->key)
				node->pLeft = push_r(key, value, node->pLeft);
			else if (key > node->key)
				node->pRight = push_r(key, value, node->pRight);
			return node;
		}

		void traverseInOrder(Node<TKey, TValue>* node, void (*callback)(const TKey&, const TValue&)) const {
			if (!node) return;
			traverseInOrder(node->pLeft, callback);
			callback(node->key, node->value);
			traverseInOrder(node->pRight, callback);
		}

		void traverseRange(Node<TKey, TValue>* node, const TKey& minKey, const TKey& maxKey, void (*callback)(const TKey&, const TValue&)) const {
			if (!node) return;
			if (minKey < node->key)
				traverseRange(node->pLeft, minKey, maxKey, callback);
			if (node->key >= minKey && node->key <= maxKey)
				callback(node->key, node->value);
			if (maxKey > node->key)
				traverseRange(node->pRight, minKey, maxKey, callback);
		}

		Node<TKey, TValue>* root = nullptr;
	public:
		~BTree() { clear(); }
		void clear() { if (root) root->del(); }
		void print() { if (root) root->print(); }

		bool push(const TKey& key, const TValue& value);
		TValue* getValue(const TKey& key);

		void traverseInOrder(void (*callback)(const TKey&, const TValue&)) const;
		void traverseRange(const TKey& minKey, const TKey& maxKey, void (*callback)(const TKey&, const TValue&)) const;

		bool push_r(const TKey& key, const TValue& value);
	};

	template<typename TKey, typename TValue>
	inline bool BTree<TKey, TValue>::push(const TKey& key, const TValue& value)
	{
		if (!root) { root = new Node<TKey, TValue>(key, value); return true; }
		Node<TKey, TValue>* current = root;
		do
		{
			if (key < current->key)
			{
				if (current->pLeft)
				{
					current = current->pLeft;
				}
				else
				{
					current->pLeft = new Node<TKey, TValue>(key, value);
					return true;
				}
			}
			else if (key > current->key)
			{
				if (current->pRight)
				{
					current = current->pRight;
				}
				else
				{
					current->pRight = new Node<TKey, TValue>(key, value);
					return true;
				}
			}
			else {
				return false;
			}
		} while (true);
	}

	template<typename TKey, typename TValue>
	inline TValue* BTree<TKey, TValue>::getValue(const TKey& key)
	{
		if (root) return root->getValue(key);
		return nullptr;
	}

	template<typename TKey, typename TValue>
	inline void BTree<TKey, TValue>::traverseInOrder(void(*callback)(const TKey&, const TValue&)) const
	{
		this->traverseInOrder(root, callback);
	}

	template<typename TKey, typename TValue>
	inline void BTree<TKey, TValue>::traverseRange(const TKey& minKey, const TKey& maxKey, void(*callback)(const TKey&, const TValue&)) const
	{
		this->traverseRange(root, minKey, maxKey, callback);
	}

	template<typename TKey, typename TValue>
	inline bool BTree<TKey, TValue>::push_r(const TKey& key, const TValue& value)
	{
		return this->push_r(key, value, root);
	}
}