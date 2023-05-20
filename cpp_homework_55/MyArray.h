#include <iostream>
using namespace std;

template<class T>
class MyArray {
private:
	T* arr;
	int count;
	unsigned int grow = 0;
	unsigned int extra = 0;

public:
	MyArray();
	MyArray(int size);
	MyArray(const MyArray<T>& ar);
	MyArray(const initializer_list<T>& list);

	void Input();
	void Print();
	void PrintDev();

	int GetUpperBound();
	bool IsEmpty();

	void FreeExtra();
	void RemoveAll();

	T GetAt(int index)const;

	void SetAt(T el, int index);
	void Add(T el);

	T Sum();

	void Append(const MyArray<T>& right);

	T* GetData()const;

	void InsertAt(T el, int pos);
	void InsertAt(T* elArr, const int SIZE, int pos);

	void RemoveAt(int pos);
	void RemoveAt(int posBegin, int posEnd);

	MyArray<T>& operator ++ ();
	MyArray<T>& operator -- ();

	MyArray<T> operator ++ (int);
	MyArray<T> operator -- (int);

	MyArray<T> operator + (int n);
	MyArray<T> operator + (const MyArray<T>& obj);

	MyArray<T> operator - (int n);

	MyArray<T>& operator = (const MyArray<T>& obj);

	T& operator [] (int index);
	T operator [] (int index)const;

	int GetSize()const;
	void SetSize(int size, int grow = 0);

	~MyArray();
};

template<class T>
MyArray<T>::MyArray() {
	arr = nullptr;
	count = 0;
}

template<class T>
MyArray<T>::MyArray(int size): count(size) { arr = new T[count + extra]; }

template<class T>
MyArray<T>::MyArray(const MyArray<T>& obj) {
	count = obj.count;
	extra = obj.extra;
	grow = obj.grow;

	arr = new T[count + extra];

	for (int i = 0; i < count; i++) arr[i] = obj.arr[i];
	for (int i = count; i < count + extra; i++) arr[i] = 0;
}

template<class T>
MyArray<T>::MyArray(const initializer_list<T>& list) : MyArray(list.size()) {
	int i = 0;
	for (auto element : list) {
		arr[i] = element;
		i++;
	}
}

template<class T>
void MyArray<T>::Input() { for (int i = 0; i < count; i++) arr[i] = rand() % 100; }

template<class T>
void MyArray<T>::Print() {
	for (int i = 0; i < count; i++) cout << arr[i] << " ";
	cout << "\n";
}

template<class T>
void MyArray<T>::PrintDev() {
	for (int i = 0; i < count; i++) cout << arr[i] << " ";
	cout << " | ";

	for (int i = count; i < count + extra; i++) cout << arr[i] << " ";
	cout << "\n";
}

template<class T>
int MyArray<T>::GetUpperBound() { return count - 1; }

template<class T>
bool MyArray<T>::IsEmpty() { return count == 0; }

template<class T>
void MyArray<T>::FreeExtra() {
	extra = 0;

	T* temp = new T[count];
	for (int i = 0; i < count; i++) temp[i] = arr[i];
	delete[] arr;

	arr = temp;
}

template<class T>
void MyArray<T>::RemoveAll() {
	if (arr != nullptr) {
		delete[] arr;
		arr = nullptr;
	}
	count = 0;
	grow = 0;
}

template<class T>
T MyArray<T>::GetAt(int index) const {
	if (index < 0) return arr[count + index];
	else if (index >= count || index <= -count) throw "Out of array";
	return arr[index];
}

template<class T>
void MyArray<T>::SetAt(T el, int index) {
	if (index >= count || index <= -count) throw "Invalid index";
	else if (index < 0) arr[count + index] = el;
	arr[index] = el;
}

template<class T>
void MyArray<T>::Add(T el) {
	if (grow == 0) {
		if (extra == 0) {
			count++;
			T* temp = new T[count];

			for (int i = 0; i < count - 1; i++) temp[i] = arr[i];
			temp[count - 1] = el;

			delete[] arr;
			arr = temp;
		}
		else {
			arr[count] = el;
			count++;
			extra--;
		}
	}
	else {
		if (extra == 0) {
			count++;
			T* tmp = new T[count + grow];

			for (int i = 0; i < count - 1; i++) tmp[i] = arr[i];
			tmp[count - 1] = el;

			for (int i = count; i < count + grow; i++) tmp[i] = 0;
			extra = grow;

			delete[] arr;

			arr = tmp;
		}
		else {
			arr[count] = el;
			count++;
			extra--;
		}
	}
}

template<class T>
T MyArray<T>::Sum() {
	T tmp{};
	for (int i = 0; i < count; i++) tmp += arr[i];
	return tmp;
}

template<class T>
void MyArray<T>::Append(const MyArray<T>& right) {
	MyArray<T> tmp(this->count + right.count);
	delete[] tmp.arr;

	tmp.arr = new T[this->count + right.count + this->extra + right.extra];

	for (int i = 0; i < this->count; i++) tmp.arr[i] = this->arr[i];
	for (int i = this->count, j = 0; i < tmp.count; i++, j++) tmp.arr[i] = right.arr[j];
	for (int i = tmp.count; i < this->extra + right.extra; i++) tmp.arr[i] = 0;

	tmp.extra = this->extra + right.extra;
	tmp.grow = this->grow >= right.grow ? this->grow : right.grow;

	*this = tmp;
}

template<class T>
T* MyArray<T>::GetData() const { return arr; }

template<class T>
void MyArray<T>::InsertAt(T el, int pos) {
	if (extra > 0) {
		for (int i = count; i > pos; i--) swap(arr[i], arr[i - 1]);
		arr[pos] = el;
		count++;
		extra--;
	}
	else {
		count++;
		T* tmp = new T[count];

		for (int i = 0, j = 0; i < count; i++) {
			if (i == pos) {
				tmp[i] = el;
				continue;
			}
			tmp[i] = arr[j];
			j++;
		}

		delete[] arr;
		arr = tmp;
	}
}

template<class T>
void MyArray<T>::InsertAt(T* elArr, const int SIZE, int pos) {
	if (extra >= SIZE) {
		extra -= SIZE;

		T* tmp = new T[count + SIZE + extra];

		for (int i = 0; i < pos; i++) tmp[i] = arr[i];
		for (int i = 0, j = pos; i < SIZE; i++, j++) tmp[j] = elArr[i];
		for (int i = pos + SIZE, j = pos; i < count + SIZE + extra; i++, j++) tmp[i] = arr[j];

		delete[] arr;

		arr = tmp;
		count += SIZE;
	}
	else {
		T* tmp = new T[count + SIZE + extra];

		for (int i = 0; i < pos; i++) tmp[i] = arr[i];
		for (int i = 0, j = pos; i < SIZE; i++, j++) tmp[j] = elArr[i];
		for (int i = pos + SIZE, j = pos; i < count + SIZE + extra; i++, j++) tmp[i] = arr[j];

		delete[] arr;

		arr = tmp;
		count += SIZE;
	}
}

template<class T>
void MyArray<T>::RemoveAt(int pos) {
	if (pos >= 0 && pos < count) {
		for (int i = pos; i < count; i++) {
			if (i == count - 1) {
				arr[i] = 0;
				break;
			}
			swap(arr[i], arr[i + 1]);
		}
		count--;
		extra++;
	}
	else throw "Invalid index";
}

template<class T>
void MyArray<T>::RemoveAt(int posBegin, int posEnd) {
	if (posBegin < posEnd && posBegin >= 0 && posBegin < count && posEnd >= 0 && posEnd < count) for (int i = 0; i <= posEnd - posBegin; i++) RemoveAt(posBegin);
	else if (posBegin == posEnd) RemoveAt(posBegin);
	else throw "Invalid index";
}

template<class T>
MyArray<T>& MyArray<T>::operator ++ () {
	T* tmp = new T[++count];
	for (int i = 0; i < count - 1; i++) tmp[i] = arr[i];
	tmp[count - 1] = 0;

	delete[] arr;
	arr = tmp;

	return *this;
}

template<class T>
MyArray<T>& MyArray<T>::operator -- () {
	T* tmp = new T[--count];
	for (int i = 0; i < count; i++) tmp[i] = arr[i];

	delete[] arr;
	arr = tmp;

	return *this;
}

template<class T>
MyArray<T> MyArray<T>::operator ++ (int) {
	MyArray obj(*this);

	T* tmp = new T[++count];
	for (int i = 0; i < count - 1; i++) tmp[i] = arr[i];
	tmp[count - 1] = 0;

	delete[] arr;
	arr = tmp;

	return obj;
}

template<class T>
MyArray<T> MyArray<T>::operator -- (int) {
	MyArray obj(*this);

	T* tmp = new T[--count];
	for (int i = 0; i < count; i++) tmp[i] = arr[i];

	delete[] arr;
	arr = tmp;

	return obj;
}

template<class T>
MyArray<T> MyArray<T>::operator + (int n) {
	MyArray<T> obj(count + n);

	for (int i = 0; i < count; i++) obj.arr[i] = arr[i];
	for (int i = count; i < obj.count; i++) obj.arr[i] = 0;

	return obj;
}

template<class T>
MyArray<T> MyArray<T>::operator + (const MyArray<T>& right) {
	MyArray<T> obj(count + right.count);

	for (int i = 0; i < count; i++) obj.arr[i] = arr[i];
	for (int i = count, j = 0; i < obj.count; i++, j++) obj.arr[i] = right.arr[j];

	return obj;
}

template<class T>
MyArray<T> MyArray<T>::operator - (int n) {
	if (count - n < 1) return MyArray<T>();
	MyArray<T> obj(count - n);
	for (int i = 0; i < obj.count; i++) obj.arr[i] = arr[i];

	return obj;
}

template<class T>
MyArray<T>& MyArray<T>::operator = (const MyArray<T>& obj) {
	if (&obj != this) {
		if (arr != nullptr) delete[] arr;

		count = obj.count;
		extra = obj.extra;
		grow = obj.grow;

		arr = new T[count + extra];

		for (int i = 0; i < count; i++) arr[i] = obj.arr[i];
		for (int i = count; i < count + extra; i++) arr[i] = 0;
		cout << "\n";
	}
	return *this;
}

template<class T>
T& MyArray<T>::operator [] (int index) {
	if (index < 0) return arr[count + index];
	else if (index >= count || index <= -count) throw "Out of array";
	return arr[index];
}

template<class T>
T MyArray<T>::operator [] (int index) const {
	if (index < 0) return arr[count + index];
	else if (index >= count || index <= -count) throw "Out of array";
	return arr[index];
}

template<class T>
int MyArray<T>::GetSize() const { return count; }

template<class T>
void MyArray<T>::SetSize(int size, int grow) {
	this->grow = grow;
	if (size > count) {
		MyArray<T> obj(size);

		for (int i = 0; i < count; i++) obj.arr[i] = arr[i];
		for (int i = count; i < obj.count; i++) {
			obj.arr[i] = 0;
			obj.extra++;
		}

		obj.count -= obj.extra;
		obj.grow = grow;

		*this = obj;
	}
	else if (size < count) {
		if (size < 1) {
			this->RemoveAll();
			return;
		}

		MyArray<T> obj(size);

		for (int i = 0; i < obj.count; i++) obj.arr[i] = arr[i];
		obj.grow = grow;

		*this = obj;
	}
}

template<class T>
MyArray<T>::~MyArray() { delete[] arr; }