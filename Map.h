//
// Hash Map implementation created by krystian on 15.12.18.
//

#ifndef MAP_MAP_H
#define MAP_MAP_H

#include <iostream>

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
			std::cout << "Destroying element with value: " << value << std::endl;
			std::cout << "It was pointing to: " << nextPair << std::endl;
		}
	};

private:
	unsigned int length;
	Pair *begin, current, end;
public:
	Map();

	~Map();

	void advance();

	val_t find(key_t key);

	void add(key_t key, val_t value);
};

template<class key_t, class val_t>
Map<key_t, val_t>::Map() {
	begin = nullptr;
	length = 0;
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

	Pair *p = new Pair(key, value);
	if (begin == nullptr) {
		begin = p;
	} else {
		Pair *temp = begin;
		while (temp != nullptr) {
			if (temp->nextPair == nullptr) {
				temp->nextPair = p;
				break;
			}
			temp = temp->nextPair;
		}
	}
	++length;
}

template<class key_t, class val_t>
val_t Map<key_t, val_t>::find(key_t searchKey) {

	while()
}

template<class key_t, class val_t>
void Map<key_t, val_t>::advance() {


}

#endif //MAP_MAP_H
