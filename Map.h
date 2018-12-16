//
// Created by krystian on 15.12.18.
//

#ifndef MAP_MAP_H
#define MAP_MAP_H

#define SIZE 2

template<class key_t, class val_t> class Map{
	struct Pair{
		key_t key;
		val_t value;
		Pair *nextPair;
		Pair(key_t k, val_t v){
			key = k;
			value = v;
			nextPair = nullptr;
		}
		~Pair()=default;
	};
private:
	unsigned int elements, length;
	Pair **array;
public:
	Map(){
		array = new Pair*[1];
		*array = nullptr;
		elements = 0;
		length = 1;
	}
	~Map(){
		for(int i = 0; i < length; ++i){
			Pair *curr = array[i];
			while(curr != nullptr){
				Pair *temp = curr->nextPair;
				delete curr;
				curr = temp;
			}
		}
		delete[]array;
	}
	void add();
};



#endif //MAP_MAP_H
