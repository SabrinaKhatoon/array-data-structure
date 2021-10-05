#include<iostream>
#include<string.h>
using namespace std;

class Exception{
	char *s;
	public:
	Exception(char x[]){
		s = new char[strlen(x) + 1];
		strcpy(s, x);
	}
	
	friend ostream &operator<<(ostream &abc, Exception x){
		abc << x.s;
		return abc;
	}
};

class Array{
	int *a, length, size;
	public:
	Array(int n){
		a = new int[n];
		length = n;
		size = 0;
	}
	bool isEmpty();
	int getSize();
	void insert(int x, int index);
	int del(int index);
	int indexOf(int x);
	int get(int index);
	void display();
};

bool Array::isEmpty(){
	if(size == 0)
		return true;
	else return false;
}

int Array::getSize(){
	return size;
}

void Array::insert(int x, int index){
	if(size == length) throw Exception("Array is full");
	if(index<0 || index > size) throw Exception("Invalid index. insertion failed!");
	for(int i = size - 1; i >= index; i--)
		a[i+1] = a[i];
	a[index] = x;
	size++;
}

int Array::del(int index){
	if(size == 0) throw Exception("Array is empty");
	if(index<0 || index>=size) throw Exception("Invalid index. deletion failed!");
	int x = a[index];
	for(int i = index+1; i<size; i++)
		a[i-1] = a[i];
	size--;
}
int Array::indexOf(int x){
	int index = -1;
	for(int i=0; i<size; i++){
		if(a[i] == x){
			index = i;
			break;
		}
	}
	return index;
}

int Array::get(int index){
	if(index<0 || index>=size) throw Exception("Invalid index, get failed.");
	return a[index];
}

void Array::display(){
	cout<<"[";
	for(int i=0; i<size; i++)
		cout<<a[i]<<", ";
	cout<<"\b\b]";
}

int main(){
	Array a(5);
	try{
		a.insert(10, 0);
		a.insert(20, 0);
		a.insert(30, 2);
    }catch(Exception x){ 
    	cout << x;
	}
	a.display();
	cout << "\nHuda";
	return 0;
}


