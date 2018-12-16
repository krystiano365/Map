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

		Pair* clone(Pair* other){
			Pair* p = new Pair(other->key, other->value);
			return p;
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

	void add(key_t key, val_t value);


};

template<class key_t, class val_t>
Map<key_t, val_t>::Map() {
	begin = end = nullptr;
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
		begin = end = p;
	} else {
		end = end->nextPair = p;
//		Pair *temp = begin;
//		while (temp != nullptr) {
//			if (temp->nextPair == nullptr) {
//				temp->nextPair = p;
//				break;
//			}
//			temp = temp->nextPair;
//		}
	}
}

template<class key_t, class val_t>
val_t* Map<key_t, val_t>::find(key_t searchKey) {
	Pair *temp = begin;
	while(temp != nullptr){
		if(temp->key == searchKey){
			return &temp->value;
		}
		if(temp->nextPair != nullptr){
			temp = temp->nextPair;
		}
	}
	return nullptr;

}

template<class key_t, class val_t>
Map<key_t, val_t>::Map(const Map &m) {
	begin = end = nullptr;
	Pair *src, **dst;
	src = m.begin;
	dst = &begin;
	while (src) {
		*dst = new Pair;
		(*dst)->value = src->value;
		(*dst)->key = src->key;
		src = src->nextPair;
		dst = &((*dst)->nextPair);
	}





//	Pair *temp_outer = m.begin;
//	Pair *temp = begin;
//	while(temp_outer != nullptr){
//		*temp = *temp_outer;
//		temp = temp->nextPair;
//
//	}

}

//template<class key_t, class val_t>
//Map<key_t, val_t>::Map(const ) {
//
//	begin = end = nullptr;
//
//	Pair *temp = p->begin;
//	while(temp != nullptr){
//		this->add(temp->key, temp->value);
//		if(temp->nextPair != nullptr) {
//			temp = temp->nextPair;
//		}
//	}
//}


#endif //MAP_MAP_H
