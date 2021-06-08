#pragma once

#include <string>
#include <iostream>

/* ---------------- Node ---------------- */

/**
 * template of struct representing doubly linked list element * 
 * */
template <typename T>
struct Node {

	/** element value */
	T m_value;

	/** pointer to element */
	Node<T>* m_next;

	/** pointer to previous element */
	Node<T>* m_previous;

	/** constructor */
	Node(T value, Node* next = nullptr, Node* previous = nullptr);
};

/* - - - - - - - - - - - - - - - - - - - - */

template <typename T>
Node<T>::Node(T value, Node* next, Node* previous) 
	: m_value(value), m_next(next), m_previous(previous) {}

/* ---------------- Iterator ---------------- */

/**
 * template of struct representing list iterator
 * */
template <typename T>
struct Iterator {

	/** element at which it currently points */
	Node<T>* m_currentElement;

	/** is reverse */
	bool m_reverse;

	/** two-argument constructor */
	Iterator(Node<T>* currentElement = nullptr, bool reverse = false);

	/**
	 * overloaded * operator
	 * @return T
	 * */
	T operator*() const;

	/**
	 * overloaded -> operator
	 * @return T*
	 * */
	T* operator->() const;

	/**
	 * overloaded == operator
	 * @return bool
	 * */
	bool operator!=(const Iterator& other) const;

	/**
	 * overloaded pre++ operator
	 * @return T
	 * */
	Iterator& operator++();

	/**
	 * overloaded post++ operator
	 * @return T
	 * */
	Iterator operator++(int);

};

/* - - - - - - - - - - - - - - - - - - - - */

template <typename T>
Iterator<T>::Iterator(Node<T>* currentElement, bool reverse) {
	m_currentElement = currentElement;
	m_reverse = reverse;
}

template <typename T>
T* Iterator<T>::operator->() const {
	return &m_currentElement->m_value;
}

template <typename T>
T Iterator<T>::operator*() const {
	return m_currentElement->m_value;
}

template <typename T>
bool Iterator<T>::operator!=(const Iterator& other) const {
	return m_currentElement != other.m_currentElement;
}

template <typename T>
Iterator<T>& Iterator<T>::operator++() {
	if (m_reverse) {
		m_currentElement = m_currentElement->m_previous;
	} else {
		m_currentElement = m_currentElement->m_next;
	}
	return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator++(int) {
	Iterator<T> result(m_currentElement);
	if (m_reverse) {
		m_currentElement = m_currentElement->m_previous;
	} else {
		m_currentElement = m_currentElement->m_next;
	}
	return result;
}

/* ---------------- List ---------------- */

template <typename T> class List;

template <typename T>
std::ostream& operator<< (std::ostream& os, const List<T>& list);

/**
 * template of class representing doubly linked list
 * */
template <typename T>
class List {

/**
 * template of function printing list on std::out
 * @param std::ostream&
 * @param const List<T>&
 * @return std::ostream&
 * */
friend std::ostream& operator<<<> (std::ostream& os, const List<T>& list);

private:

	/** pointer to first element */
	Node<T>* m_head = nullptr;

	/** pointer to first last */
	Node<T>* m_tail = nullptr;

public:

	/** default constructor */
	List() = default;

	/** two-argument constructor */
	List(unsigned elements, const T* array);

	/** copy constructor */
	List(const List& other);

	/** destructor */
	~List();

	/**
	 * method adding element ot the end of the list
	 * @param T
	 * */
	void push_back(T element);

	/**
	 * method returning last element of the list (removes element from list)
	 * @param T
	 * */
	T pop_back();

	/**
	 * method giving access to first element of list
	 * @param T
	 * */
	T& front();

	/**
	 * method returning begin iterator
	 * @param T
	 * */
	Iterator<T> begin();

	/**
	 * method returning reversed begin iterator
	 * @param T
	 * */
	Iterator<T> rbegin();

	/**
	 * method returning end iterator
	 * @param T
	 * */
	Iterator<T> end();

	/**
	 * method returning reversed end iterator
	 * @param T
	 * */
	Iterator<T> rend();

};

/* - - - - - - - - - - - - - - - - - - - - */

template <typename T>
List<T>::List(unsigned elements, const T* array) {
	for (unsigned i = 0; i < elements; i++) {
		push_back(array[i]);
	}
}

template <typename T>
List<T>::List(const List& other) {
	Node<T>* current = other.m_head;
	while(current != nullptr) {
		push_back(current->m_value);
		current = current->m_next;
	}
}

template <typename T>
List<T>::~List() {
	Node<T>* current = m_head;
	Node<T>* next = m_head;
	while (next != nullptr) {
		next = current->m_next;
		delete current;
		current = next;
	}
}

template <typename T>
void List<T>::push_back(T element) {
	if (m_head == nullptr) {
		m_head = m_tail = new Node<T>(element);
	} else {
		Node<T>* newEl = new Node<T>(element, nullptr, m_tail);
		m_tail->m_next = newEl;
		m_tail = newEl;
	}

}

template <typename T>
T List<T>::pop_back() {
	if (m_tail == nullptr) {
		return T();
	} else {
		T result = m_tail->m_value;
		m_tail = m_tail->m_previous;
		delete m_tail->m_next;
		m_tail->m_next = nullptr;
		return result;
	}
}

template <typename T>
T& List<T>::front() {
	return m_head->m_value;
}

template <typename T>
Iterator<T> List<T>::begin() {
	return Iterator<T>(m_head);
}

template <typename T>
Iterator<T> List<T>::rbegin() {
	return Iterator<T>(m_tail, true);
}

template <typename T>
Iterator<T> List<T>::end() {
	return Iterator<T>(nullptr);
}

template <typename T>
Iterator<T> List<T>::rend() {
	return Iterator<T>(nullptr, true);
}

template <typename T>
std::ostream& operator<< (std::ostream& os, const List<T>& list) {
	os << "{";
	if (list.m_head != nullptr) {
		os << "\"" << list.m_head->m_value << "\"";
		Node<T>* current = list.m_head->m_next;
		while (current != nullptr) {
			os << ", \"" << current->m_value << "\"";
			current = current->m_next;
		}
	}
	return os << "}" << std::endl;
}
