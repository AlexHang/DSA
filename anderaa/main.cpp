#include <iostream>

using namespace std;

void deleteElement(int Array[], int position);

int main() {

    int Array[5] = {1, 2, 3, 4, 5};
    deleteElement(Array, 3);
    for (int i = 0; i<sizeof(Array)/sizeof(Array[0])-1; i++)
        cout<<Array[i]<<"  ";
}


void deleteElement(int Array[], int position) {
    for (int i = 0; i<4; i++) {
        if ( i >= position ) {
            Array[i]=Array[i+1];

        }
/*
for (int i = 0; i<sizeof(Array)/sizeof(Array[0]); i++)
        cout<<Array[i]<<"  ";*/
    }

}
