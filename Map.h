//
// Map implementation created by krystian on 15.12.18.
//

#ifndef MAP_MAP_H
#define MAP_MAP_H

#include <iostream>

using namespace std;

template<class key_t, class val_t>
class Map {

	struct Pair {
		key_t key;
		val_t value;
		Pair *nextPair;

		Pair(key_t k, val_t v) {
			key = k;
			value = v;
			nextPair = nullptr;
		}

		~Pair() {
//			std::cout << "Destroying element with value: " << value << std::endl;
//			std::cout << "It was pointing to: " << nextPair << std::endl;
		}
	};

private:
	Pair *begin, *end;
public:
	Map();
	Map(const Map &m);
	~Map();
	val_t* find(key_t key);
	bool checkExistance(key_t key);
	void add(key_t key, val_t value);
	Map<key_t, val_t>& operator= (const Map& m);
	friend ostream& operator<<(ostream& os, const Map &m){
		Pair *temp = m.begin;
		while(temp != nullptr){
			os << "(" << temp->key << " | " << temp->value << ")" << endl;
			temp = temp->nextPair;
		}
		return os;
	}
};

//class NoSuchKeyException : public exception {
//	key_t k;
//public:
//	NoSuchKeyException(key_t key){
//		k = key;
//	}
//	ostream& what() {
//		ostream &msg = what();
//		msg <<  "ERR: THIS MAP DOES NOT CONTAIN GIVEN KEY" << k;
//		return msg;
//	}
//};

class NoSuchKeyException : public exception {
public:
	const char* what() const noexcept override {
		return "ERR: THIS MAP DOES NOT CONTAIN GIVEN KEY";
	}
};

class KeyAlreadyExistsException : public exception {
public:
	const char* what() const noexcept override {
		return "ERR: THE FOLLOWING KEY ALREADY EXISTS AND CANNOT BE ADDED MORE THAN ONCE";
	}
};

template<class key_t, class val_t>
Map<key_t, val_t>::Map() {
	begin = end = nullptr;
}

template<class key_t, class val_t>
Map<key_t, val_t>::Map(const Map<key_t, val_t> &m) {
	begin = end = nullptr;
	Pair *src, **dst;
	src = m.begin;
	dst = &begin;
	while (src) {
		*dst = new Pair(src->key, src->value);
		src = src->nextPair;
		end = *dst;
		dst = &((*dst)->nextPair);
	}
}

template<class key_t, class val_t>
Map<key_t, val_t>::~Map() {

	while (begin) {
		Pair *temp = begin->nextPair;
		delete begin;
		begin = temp;
	}
}

template<typename key_t, typename val_t>
void Map<key_t, val_t>::add(key_t key, val_t value) {

	if(checkExistance(key) == false){
		Pair *p = new Pair(key, value);
		if (begin == nullptr) {
			begin = end = p;
		} else {
			end = end->nextPair = p;
		}
	} else {
		throw KeyAlreadyExistsException();
	}
}

template<class key_t, class val_t>
bool Map<key_t, val_t>::checkExistance(key_t searchKey) {				//use when you need a marker that the key exists
	Pair *temp = begin;
	while(temp != nullptr){
		if(temp->key == searchKey){
			return true;
		}
		temp = temp->nextPair;
	}
	return false;
}


template<class key_t, class val_t>
val_t* Map<key_t, val_t>::find(key_t searchKey) {						//use when you want the pointer to the value object you want to find
	Pair *temp = begin;
	while(temp != nullptr){
		if(temp->key == searchKey){
			return &temp->value;
		}
		temp = temp->nextPair;
	}
	throw NoSuchKeyException();
}

template<class key_t, class val_t>
Map<key_t, val_t> &Map<key_t, val_t>::operator=(const Map &m) {
	while (begin) {
		Pair *temp = begin->nextPair;
		delete begin;													//cleaning the Map
		begin = temp;
	}

	begin = end = nullptr;												//refreshing properties of the Map

	Pair *src, **dst;
	src = m.begin;
	dst = &begin;
	while (src) {
		*dst = new Pair(src->key, src->value);
		src = src->nextPair;
		end = *dst;
		dst = &((*dst)->nextPair);
	}

}


#endif //MAP_MAP_H
