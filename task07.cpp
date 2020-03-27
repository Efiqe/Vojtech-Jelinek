#include <iostream>
// #include <windows.h>
#include <cstdio>
#include <vector>

using namespace std;


/*
Mohli bychom si vztvořit fuknci na vypisování vektoru
void print(vector<int> result) {
    for(int i = 0; i < result.size(); i++) {
        cout << result.at(i) << ' ';
    }
}*/

/*
Snažil jsem se použít funkci GetKeyState na to abych zjistil, kdy je stisknuta
klávesa Q a mohl ukončit svůj while loop ale nefungovalo mi to

while(true) {
    cin >> num;
    if(GetKeyState('q') & 0x8000) {
        break;
    }
}

*/

int main() {
    vector<int> result;
    vector<int>::iterator it;
    int num;
    
    cin >> num;
    result.insert(it, num);

    for(int i = 0; i < result.size(); i++) {
        cout << result.at(i) << ' ';
    }
}
