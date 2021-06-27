#include <iostream>

using std::string;


class AbstractEmployee
{
    virtual void AskForPromotion() = 0; //abstract function or pure virtual function
};



class Employee : AbstractEmployee
{
protected:
    string Name;
private:
    
    string Company;
    int Age;
  
public:
    void setName(string name){
        Name = name;
    }
    string getName(){return Name;}

     void setCompany(string company){
        Company = company;
    }
    string getCompany(){return Company;}

     void setAge(int age){
        Age = age;
    }
    int getAge(){return Age;}

    void IntroduceYourself(){
        std::cout <<"my name is : " << Name << std::endl;
        std::cout <<"I work at : " << Company << std::endl;
        std::cout <<"and my age is : " << Age << std::endl;
    }
    Employee(){};
    Employee(string name,string company, int age){
        Name = name;
        Company = company;
        Age =age;
    };
    void AskForPromotion(){
        if( Age > 30 )
            std::cout << Name << " get promoted !! \n";
        else
            std::cout << Name << " sorry  !! \n";
        
    }

    ~Employee(){};
// to check if there is an other implementation of this methode in the derived class 
   virtual void Work(){
        std::cout << Name << " is cheking mail and tasks " << std::endl;

    }
};

class Developer : public Employee // to get all public methode 
{
public:
    string FavProgLanguage;
    Developer(){};
    Developer (string name,string company, int age , string FavProgLang): Employee(name, company, age)
    {
        FavProgLanguage = FavProgLang;
    };
    void FixBug(){
        std :: cout << getName() << " fixed bug using " << FavProgLanguage << std :: endl;
    }
    //polymoph
     void Work(){
        std::cout << Name << " is coding " << std::endl;

    }
};
 class Teacher : public Employee 
 {
public:
     string Subject;
     void PrepareLesson(){
         std::cout << Name << " is preparing " << Subject << " lesson" << std::endl;
     }
    Teacher(string name,string company, int age , string subject ): Employee(name, company, age) {
        Subject = subject;  
    };
    Teacher(){};
     //polymoph
     void Work(){
        std::cout << Name << " is preparing tasks " << std::endl;

    }

 };
int main ()
{
    // Employee employee1 = Employee("Achraf","CustHome",25);
    //employee1.IntroduceYourself();
    //employee1.setAge(39);
    //std::cout << employee1.getName() << " work for " << employee1.getCompany() << "  and he is " << employee1.getAge() << " years old \n" ;
    //employee1.AskForPromotion();

     Developer d = Developer("Achraf", "Custhome", 25, "C/C++");
    // d.FixBug();
    // d.AskForPromotion();
  
    
    Teacher t = Teacher("3ezdine" , "Polytech" , 42 , " OOP C ++ ") ;
    //t.AskForPromotion();
    //t.PrepareLesson();
//Polymophism

/* the most common use of polymorphism is when a parent
class reference is used to refer to a child class object*/

Employee* e1 = &d;
Employee* e2 = &t;
   // d.Work();
   // t.Work();
    e1->Work();
    e2->Work();
    return 0 ;

}