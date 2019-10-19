
#include <string>
#include <utility>
using namespace std;

template <class TYPE>
class Table{
public:
	Table(){}
	virtual bool update(const string& key, const TYPE& value)=0;
	virtual bool remove(const string& key)=0;
	virtual bool find(const string& key, TYPE& value)=0;
	virtual int numRecords() const = 0;
	virtual bool isEmpty() const = 0;
	virtual ~Table(){}
};

template <class TYPE>
class SimpleTable:public Table<TYPE>{

	struct Record{
		TYPE data_;
		string key_;
		Record(const string& key, const TYPE& data){
			key_=key;
			data_=data;
		}

	};

	Record** records_;   //the table
	int max_;           //capacity of the array
	int size_;          //current number of records held
	int search(const string& key);

public:
	SimpleTable(int capacity);
	SimpleTable(const SimpleTable& other);
	SimpleTable(SimpleTable&& other);
	virtual bool update(const string& key, const TYPE& value);
	virtual bool remove(const string& key);
	virtual bool find(const string& key, TYPE& value);
	virtual const SimpleTable& operator=(const SimpleTable& other);
	virtual const SimpleTable& operator=(SimpleTable&& other);
	virtual ~SimpleTable();
	virtual bool isEmpty() const{return size_==0;}
	virtual int numRecords() const{return size_;}
};


//returns index of where key is found.
template <class TYPE>
int SimpleTable<TYPE>::search(const string& key){
	int rc=-1;
	for(int i=0;i<size_;i++){
		if(records_[i]->key_==key){
			rc=i;
		}
	}
	return rc;
}


template <class TYPE>
SimpleTable<TYPE>::SimpleTable(int capacity): Table<TYPE>(){
	records_=new Record*[capacity];
	max_=capacity;
	size_=0;
}

template <class TYPE>
SimpleTable<TYPE>::SimpleTable(const SimpleTable<TYPE>& other){
	records_=new Record*[other.max_];
	max_=other.max_;
	size_=0;
	for(int i=0;i<other.size_;i++){
		update(other.records_[i]->key_,other.records_[i]->data_);
	}
}
template <class TYPE>
SimpleTable<TYPE>::SimpleTable(SimpleTable<TYPE>&& other){
	size_=other.size_;
	max_=other.max_;
	records_=other.records_;
	other.records_=nullptr;
	other.size_=0;
	other.max_=0;
}

template <class TYPE>
bool SimpleTable<TYPE>::update(const string& key, const TYPE& value){
	int idx=search(key);
	if(idx==-1){
		if(size_ < max_){
			records_[size_++]=new Record(key,value);
			for(int i=0;i<size_-1;i++){
				for(int j=0;j<size_-1-i;j++){
					if(records_[j] > records_[j+1]){
						TYPE tmp=records_[j];
						records_[j]=records_[j+1];
						records_[j+1]=tmp;
					}
				}
			}
		}
	}
	else{
		records_[idx]->data_=value;
	}
	return true;
}

template <class TYPE>
bool SimpleTable<TYPE>::remove(const string& key){
	int idx=search(key);
	if(idx!=-1){
		delete records_[idx];
		for(int i=idx;i<size_-1;i++){
			records_[i]=records_[i+1];
		}
		size_--;
		return true;
	}
	else{
		return false;
	}
}

template <class TYPE>
bool SimpleTable<TYPE>::find(const string& key, TYPE& value){
	int idx=search(key);
	if(idx==-1)
		return false;
	else{
		value=records_[idx]->data_;
		return true;
	}
}

template <class TYPE>
const SimpleTable<TYPE>& SimpleTable<TYPE>::operator=(const SimpleTable<TYPE>& other){
	if(this!=&other){
		if(records_){
			int sz=size_;
			for(int i=0;i<sz;i++){
				remove(records_[0]->key_);
			}
			delete [] records_;
		}
		records_=new Record*[other.max_];
		max_=other.max_;
		size_=0;
		for(int i=0;i<other.size_;i++){
			update(other.records_[i]->key_,other.records_[i]->data_);
		}

	}
	return *this;
}

template <class TYPE>
const SimpleTable<TYPE>& SimpleTable<TYPE>::operator=(SimpleTable<TYPE>&& other){
	swap(records_,other.records_);
	swap(size_,other.size_);
	swap(max_,other.max_);
	return *this;
}

template <class TYPE>
SimpleTable<TYPE>::~SimpleTable(){
	if(records_){
		int sz=size_;
		for(int i=0;i<sz;i++){
			remove(records_[0]->key_);
		}
		delete [] records_;
	}
}

template <class TYPE>
class LPTable:public Table<TYPE>{
	struct Record {
		TYPE data_;
		string key_;
		//creating a new variable to keep track incase there is a collision
		size_t colind_;

		Record(const string& key, const TYPE& data, const size_t colind =0) {
			key_ = key;
			data_ = data;
			colind_ = colind;
		}

	};

	Record** records_;		//the table
	int maxLP_;				//capacity of the array
	int sizeLP_;			//current number of records held
	double loadLP_;         //Load Factor for LP table represented as percentage (0.6 = 60%)
	
	
public:
	LPTable(int capacity,double maxLoadFactor);
	LPTable(const LPTable& other);
	LPTable(LPTable&& other);
	virtual bool update(const string& key, const TYPE& value);
	virtual bool remove(const string& key);
	virtual bool find(const string& key, TYPE& value);
	virtual const LPTable& operator=(const LPTable& other);
	virtual const LPTable& operator=(LPTable&& other);
	virtual ~LPTable();
	virtual bool isEmpty() const { return sizeLP_ == 0; };
	virtual int numRecords() const { return sizeLP_; };

};

//Constructor that initializes records array and sizeLP_ to safe empty state! While others to their respective values
template <class TYPE>
LPTable<TYPE>::LPTable(int capacity,double maxLoadFactor): Table<TYPE>(){
	
	records_ = new Record*[capacity];
	
	//going through the records array and ensuring that everything is empty
	for (int i = 0; i < capacity; i++)
	{
		records_[i] = nullptr;
	}

	maxLP_ = capacity;
	sizeLP_ = 0;
	loadLP_ = maxLoadFactor;
}

//Copy Constructor
template <class TYPE>
LPTable<TYPE>::LPTable(const LPTable<TYPE>& other){
	
	records_ = new Record*[other.maxLP_];
	//shallow coppy the variables
	this->maxLP_ = other.maxLP_;
	this->loadLP_ = other.loadLP_;
	this->sizeLP_ = other.sizeLP_;

	for (int i = 0; i < other.maxLP_; i++)
	{
		//make sure that each record is a nullptr
		records_[i] = nullptr;
		
		//doesn't copy nullptrs, but covers other nullptrs with actual values
		if (other.records_[i] != nullptr)
		{
			records_[i] = new Record(other.records_[i]->key_, other.records_[i]->data_, other.records_[i]->colind_);
		}
	}
}

//Move Constructor
template <class TYPE>
LPTable<TYPE>::LPTable(LPTable<TYPE>&& other){
	records_ = new Record*[other.maxLP_];

	this->maxLP_ = other.maxLP_;
	this->loadLP_ = other.loadLP_;
	this->sizeLP_ = other.sizeLP_;
	

	for (int i = 0; i < other.maxLP_; i++)
	{
		records_[i] = other.records_[i];
		other.records_[i] = nullptr;
	}

	other.maxLP_ = 0;
	other.loadLP_ = 0;
	other.sizeLP_ = 0;
	delete[] other.records_; //delete the whole table
	other.records_ = nullptr; //ensure that destructor doesn't try to delete a nullptr;
}

template <class TYPE>
bool LPTable<TYPE>::update(const string& key, const TYPE& value){
	std::hash<std::string> hashFunction; //. 
	
	size_t hash = hashFunction(key); //
	
	int index = hash % maxLP_; //holds the actual place that it needs to store value
	
	int colind = 0; //keeps track of steps after original index 

	for (;records_[index] != nullptr; index= ++index % maxLP_)
	{
		//you start at the hashed index and check to see if the key's match 
		if (records_[index]->key_ == key)
		{
			records_[index]->data_ = value;
			return true; //value replaced
		}
		colind++;
	}

	//if a nullptr has been encountered then we place the new value there.
	if ((double)sizeLP_ / (double)maxLP_ < loadLP_)
	{
		records_[index] = new Record(key, value, colind);
		sizeLP_++;
		return true;
	}

	return false;
}

template <class TYPE>
bool LPTable<TYPE>::remove(const string& key){
	std::hash<std::string> hashFunction; //. 

	size_t hash = hashFunction(key); //

	int index = hash % maxLP_; //holds the actual place that it needs to store value 

	for (; records_[index] != nullptr; index = ++index % maxLP_)
	{
		//you start at the hashed index and check to see if the key's match 
		if (records_[index]->key_ == key)
		{
			delete records_[index];
			records_[index] = nullptr;
			sizeLP_--;
			int circular = (index+1) % maxLP_; //ensuring the hash table goes in circle - R-value add
			int counter = 1; //because we moved 1 forward from the deletion point

			while (records_[circular] != nullptr)
			{
				//shifting values to proper place inside the table
				if (records_[circular]->colind_ >= counter)
				{
					records_[circular]->colind_ -= counter; //subtracting a step
					records_[index] = records_[circular];
					records_[circular] = nullptr;
					index = circular;
					counter = 1; //reseting counter
				}
				else
					counter++; //add counter if nothing has to be moved 

				circular = ++circular % maxLP_;
			}
			return true; //value found return true;
		}
	}
	return false;
}



template <class TYPE>
bool LPTable<TYPE>::find(const string& key, TYPE& value) {
	std::hash<std::string> hashFunction; //. 

	size_t hash = hashFunction(key); //

	int index = hash % maxLP_; //holds the actual place that it needs to store value 

	for (; records_[index] != nullptr; index = ++index % maxLP_)
	{
		//you start at the hashed index and check to see if the key's match 
		if (records_[index]->key_ == key)
		{
			value = records_[index]->data_; //changing the reference to value
			return true; //value found return true;
		}
	}
	return false;
}



//copy assignment operator that copies the records from other to the current object
//this function also checks for self-assignment and empty tables
template <class TYPE>
const LPTable<TYPE>& LPTable<TYPE>::operator=(const LPTable<TYPE>& other){
	if (&other != this)
	{
		for (int i = 0; i < maxLP_; i++)
		{
			delete records_[i];
			records_[i] = nullptr;
		}
		delete[] records_;
		records_ = nullptr;

		records_ = new Record*[other.maxLP_];
		//shallow coppy the variables 
		this->maxLP_ = other.maxLP_;
		this->loadLP_ = other.loadLP_;
		this->sizeLP_ = other.sizeLP_;

		for (int i = 0; i < other.maxLP_; i++)
		{
			//make sure that each record is a nullptr
			records_[i] = nullptr;

			//doesn't copy nullptrs, but covers other nullptrs with actual values
			if (other.records_[i] != nullptr)
			{
				records_[i] = new Record(other.records_[i]->key_, other.records_[i]->data_, other.records_[i]->colind_);
			}
		}
	}
	return *this;
}

//Move assignment operator that moves the records from other to the current object
template <class TYPE>
const LPTable<TYPE>& LPTable<TYPE>::operator=(LPTable<TYPE>&& other){
	if (&other != this)
	{
		//ensuring that records_ is completely empty;
		for (int i = 0; i < maxLP_; i++)
		{
			delete records_[i];
			records_[i] = nullptr;
		}
		delete[] records_;
		records_ = nullptr;

		records_ = new Record*[other.maxLP_];

		this->maxLP_ = other.maxLP_;
		this->loadLP_ = other.loadLP_;
		this->sizeLP_ = other.sizeLP_;


		for (int i = 0; i < other.maxLP_; i++)
		{
			records_[i] = other.records_[i];
			other.records_[i] = nullptr;
		}

		other.maxLP_ = 0;
		other.loadLP_ = 0;
		other.sizeLP_ = 0;
		delete[] other.records_; //delete the whole table
		other.records_ = nullptr; //ensures that destructor doesn't try to delete a nullptr;
	}
	return *this;
}

//destructor that goes checks for full records and empties it one index at a time.
template <class TYPE>
LPTable<TYPE>::~LPTable(){
	if (records_)
	{	
		for (int i = 0; i < maxLP_; i++)
		{
			delete records_[i];
			records_[i] = nullptr;
		}
		delete[] records_;
		records_ = nullptr;
	}
}


