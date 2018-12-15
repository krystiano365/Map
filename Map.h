//
// Created by krystian on 15.12.18.
//

#ifndef MAP_MAP_H
#define MAP_MAP_H

template<class key_t, class val_t> class Map{

private:
	struct Pair{
	private:
		key_t key;
		val_t value;
	public:
		Pair(key_t k, val_t v){
			key = k;
			value = v;
		}
		~Pair()=default;
		key_t getKey(){
			return key;
		}
		val_t getVal(){
			return value;
		}
	};

	Pair *array;

public:
	Map(key_t key, val_t val){
		array = new Pair(key, val);

	}
};




#endif //MAP_MAP_H
