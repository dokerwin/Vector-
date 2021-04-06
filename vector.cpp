#include <memory.h> 
#include <string.h>
#include<iostream>
using namespace std;

template<class T>
class vector
{
	T* arr;
	size_t capacity;
	size_t size;

public:

	vector(size_t n = 1){

		init();
		capacity = n;
	}


	vector(const T * arr,size_t size){
	
		init();
		capacity = size;
		arr = new T[size];
		for (int i = 0; i < size;i++){
			pushBack(arr[i]);
		}

	}
	
	
	
	void init() {
        arr = nullptr;
		capacity, size = 0;
	}
	void clear() {
		capacity, size = 0;
		delete[]arr;
	}


	






	bool resize(size_t n=2) {

	
		this->capacity = this->capacity* n;

		T* newdata = nullptr;
		newdata =new T[this->capacity];

		if (newdata == nullptr) {
	    	throw std::runtime_error("Allocate Error");
		}

		for (int i = 0; i < this->size; i++)
		{
			newdata[i] = this->arr[i];
		}
		delete[]this->arr;
		this->arr = newdata;

		return true;



	}



	void pushBack(const T & a) noexcept(false) {

		if (arr == nullptr) {
			arr = new T[capacity];
			arr[0] = a;
			size++;
		}

		else {
			
			if (size >= capacity) {
				
				if (resize() == false) {

					throw std::runtime_error("Resize error");
			      	
				}

			}
  			arr[size] = a;
			
			size++;
		}
	
	}

	const T& operator[](size_t index)const   noexcept(false) {

		if (index >= size || index < 0)
			throw std::runtime_error("Incorrect index");
		
		return arr[index];
	}

	




	void shrink_to_fit() noexcept(false) {

		T* new_arr = nullptr;
			
		new_arr = new T[this->size]{};
		if (new_arr == nullptr) {
			throw std::runtime_error("Allocate Eror");
		}

		for (int i = 0; i < this->size ; i++)
		{
			new_arr[i] = this->arr[i];
		}


		delete[] this->arr;

		this->arr = new_arr;
		this->capacity = this->size;

	}

	void push_front(const T& a) noexcept  {

		if (this->size == 0) {

			    this->arr[0] = a;
		}
		
		if (this->size == this->capacity) {

				resize();
		}
		for (int i = this->size; i > 0; i--)
		{
				this->arr[i] = this->arr[i - 1];
		}

		        this->arr[0] = a;
		
		        this->size++;
			
	}


	bool empty() noexcept {


		if (this->arr == nullptr || this->capacity==0) {
			
			return true;

		}
		    return false;

	}


	bool popFront() noexcept(false) {


		if (!empty()) {

			T* newdata = nullptr;

			newdata = new T[this->size - 1];

			if (newdata == nullptr) {
				throw std::runtime_error("Allocate Eror");
			
			}


			for (int i = 0; i < this->size-1; i++)
			{
				newdata[i] = this->arr[i+1];
			}
			delete[] this->arr;
			this->arr = newdata;
			--size;
			return true;
		}

		
		return false;
	}


	bool popBack() noexcept(false){

		if (!empty()) {

			T* newdata = nullptr;

			newdata= new T[this->size - 1];

			if (newdata == nullptr) {
			  throw std::runtime_error("Allocate Eror");
			}


			for (int i = 0; i < this->size - 1; i++)
			{
				newdata[i] = this->arr[i];
			}
			delete[] this->arr;
			this->arr = newdata;
			--size;
			return true;
		}
		return false;

	}

 ~vector() { clear(); }


};






int main (){

	try {




		vector<int>n;

		
		n.pushBack(11);
		n.pushBack(12);
		n.pushBack(13);
		n.pushBack(14);
		n.pushBack(15);
		n.push_front(33);
		n.popBack();
		n.popFront();
		n.shrink_to_fit();

		cout << n[0]<<endl;
		cout << n[1]<<endl;
		cout << n[2]<<endl;
		cout << n[3]<<endl;
		cout << n[4]<<endl;
		cout << n[5] << endl;
	

	}
	catch (const std::runtime_error& ex) {
		cout << "Fatal error: " << ex.what() << endl;
	}
	return 1;
}