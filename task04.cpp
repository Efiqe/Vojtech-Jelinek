#include <cstdio>
#include <cstring>

struct Animal {
	const char* name;
	const char* sound;
	
	virtual const char* whatDoesItSay() {
		sprintf(buffer, "%s says %s", name, sound);
		return buffer;
	} 
	
	Animal(const char* name) {
		this -> name = name;
		this -> sound = sound;
	}
	
	protected: 
		char buffer[48];
};

struct Dog : Animal {
	Dog(const char* name, const char* sound):Animal(name) {
		this -> sound = sound;
	}	
};

struct Fox : Animal {
	Fox(const char* name, const char* sound):Animal(name) {
		this -> sound = sound;
	}
};

int main() {
	Animal* animals[] = {
		new Dog("dog", "woof"),
		new Fox("fox", "ringiding")
	}; 
	
	for(Animal* i : animals) {
		puts(i -> whatDoesItSay());	
	}
}




