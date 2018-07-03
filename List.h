#ifndef LIST
#define LIST 

template <typename T>
class List{

public:
	List();
	~List();
	void insertion(const T& value);
	void insert_at(int pos, const T& value);
	void deletion(int pos);
	int search(const T& elem);
	void print();
	
private:
	struct Node {
		T value;	
		Node * next;
	};

	Node* m_head;
};

template <typename T>
List<T>::List() {
	this->m_head = nullptr;
}

template <typename T>
List<T>::~List() {
	std::cout << "List is deleted";
}

template <typename T>
void List<T>::insertion(const T& value) {
	Node* node = new Node();
	node->value = value;	
	node->next = this->m_head;
	this->m_head = node;
}

template <typename T>
void List<T>::insert_at(int pos, const T& value) {
	Node* newNode = new Node();
	Node* current = new Node();
	Node * prev = new Node();

	current = this->m_head;
	if(this->m_head != nullptr) {
		int ix;
		for(ix = 0; current->next != nullptr && ix != pos; ++ix) {
			prev = current;
			current = current->next;
		}
		if(pos == 0) {
			newNode->next = this->m_head;
			this->m_head = newNode;	
		} else if(current->next == nullptr && pos == ix + 1) {
			newNode->next == nullptr;
			current->next = newNode;
		} else if(pos > ix + 1) {
			std::cout << "Insert_at argument pos is out of bounds" << std::endl;
			return;
		} else {
			prev->next = newNode;
			newNode->next = current;
		}
	} else {
		this->m_head = newNode;
		newNode->next = nullptr;
	}
	newNode->value = value;
}

template <typename T>
void List<T>::deletion(int pos) {	

	Node* current;
	Node * prev;

	current = this->m_head;
	int ix = 0;
	if(this->m_head != nullptr) {
		for(ix = 0; current->next != nullptr && ix != pos; ++ix) {
			prev = current;
			current = current->next;
		}
		if(ix == 0) {
			this->m_head = current->next;
			delete current;
		} else if(current->next == nullptr && pos == ix + 1) {
			prev->next = nullptr;
			delete current;
		} else if(pos > ix + 1) {
			std::cout << "Delete argument pos is out of bounds" << std::endl;
			return;
		} else {
			prev->next = current->next;
			delete current;
		}
	} else {
		std::cout << "your list is free";
		return;
	}
}

template <typename T>
void List<T>::print() {
	Node* current = this->m_head;
	for(int ix = 1; current != nullptr; ++ix) {
		std::cout << ix <<" : " << current->value << std::endl;
		current = current->next;
	}	
}

template <typename T>
int List<T>::search(const T& value) {
	Node * current = this->m_head;
	int ix;
	for(ix = 0; current != nullptr; ++ix) {
		if(value == current->value)
			return ++ix;
		current = current->next;
	}
	return 0;
}
	
#endif
