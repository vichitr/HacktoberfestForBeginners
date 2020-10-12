class Person
{    public:
    int age;
 string name;
   
    virtual void getdata(){};
    virtual void putdata(){};
};
class Professor:public Person{

public:
int publications,id1;
 static int cur_id1;
 
 void getdata()
 { cur_id1++;
  cin>>name>>age>>publications;
   id1=cur_id1; 
 }
    void putdata(){
        cout<<name<<" "<<age<<" "<<publications<<" "<<id1<<"\n";
    }
}; int Professor :: cur_id1=0;

class Student : public Person{
   public:
    int marks[6];
    int sum=0;
      int i,id;
    static int cur_id;
    
    void getdata()
    {cur_id++;
        cin>>name>>age;
        for( i=0;i<6;i++)
        { cin>>marks[i];
        sum+=marks[i];}
        
        id=cur_id;
    }
    void putdata()
    {
        cout<<name<<" "<<age<<" "<<sum<<" "<<id<<"\n";
    }
};int Student :: cur_id=0;