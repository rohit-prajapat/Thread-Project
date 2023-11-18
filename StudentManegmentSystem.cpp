#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

//----------------------------------
// for colours
#define RED_TEXT "\033[1;31m"
#define GREEN_TEXT "\033[1;32m"
#define YELLOW_TEXT "\033[1;33m"
#define BOLD_TEXT "\033[1m"
#define RESET_TEXT "\033[0m"
//----------------------------------

//=============================================================
// starting of Valid class
//=============================================================
class Valid
{
    public :
    bool isValidName(const string name)
    {
        int size = name.size();
        for(int i=0; i<size; i++)
        {
            if((name[i]<'A' || name[i]>'Z') && (name[i]<'a' || name[i]>'z'))
            {
                return false;
            }
        }
        return true;
    }
    //----------------------------------------------------
    int isValidPhoneNumber(const string pno)
    {
        int size = pno.size();
        if(size!=10)
        {
            cout<<"Invalid Phone Number :";
            cout<<"\nPhone number should be of 10 digit\n";
            return 0;
        }
        for(int i=0; i<size; i++)
        {
            if(pno[i]<'0' || pno[i]>'9')
            {
                cout<<"\nInvalid Phone Number :";
                cout<<"\nPhone number only contain digits from 0 to 9\n";
                return 0;
            }
        }
        return 1;
    }
    //-----------------------------------------------------
    bool isValidYear(const string year) 
    {
        if(year.size()>0) return 0;
        if(stoi(year)>0 && stoi(year)<5) return 1;
        cout<<"Invalid Year :\n\n";
        return 0;
    }

   int isValidAdmissionYear(const string& year,int currentYear) {
    if (year.empty()) {
        cout<<"Invalid year : \n";
        return 0; // Year is empty
    }

    for (char c : year) {
        if (!std::isdigit(c)) {
            cout<<"Invalid year : \n";
            return 0; // Year contains invalid characters
        }
    }

   if(stoi(year)>currentYear || stoi(year)<999) 
   {cout<<"Invalid year : \n";
    return 0;
   }
    return stoi(year);
}
    //-----------------------------------------------------
    bool isValidDate(const string &dateOfBirth, int currentYear = 9999) {
    if (dateOfBirth.length() != 10) {
        return false;
    }

    if (dateOfBirth[2] != '-' || dateOfBirth[5] != '-') {
        return false;
    }

    for (int i = 0; i < 10; i++) {
        if (i == 2 || i == 5) {
            continue;
        }
        if (!isdigit(dateOfBirth[i])) {
            return false;
        }
    }

    int day = std::stoi(dateOfBirth.substr(0, 2));
    int month = std::stoi(dateOfBirth.substr(3, 2));
    int year = std::stoi(dateOfBirth.substr(6, 4));

    if (day < 1 || day > 31) {
        return false; // Check if the day is valid (1-31)
    }

    if (month < 1 || month > 12) {
        return false; // Check if the month is valid (1-12)
    }

    

    return true;
    }
    //----------------------------------------------

    float isValidCGPA(const std::string& cgpa) {
        float cgpaValue;

        for (char c : cgpa) {
            if (!std::isdigit(c) && c != '.') {
                cout<<"Invalid CGPA : \n\n";
                return -1; // CGPA contains invalid characters
            }
        }

        // Convert the string to a float
        cgpaValue = std::stof(cgpa);

        // Check if the converted value is in the valid range
        if(cgpaValue >= 0.0f && cgpaValue <= 10.0f)
        {
            return cgpaValue;
        }
        else 
        cout<<"Invalid CGPA :\n\n";
        return -1;
    }
    //----------------------------------------------

    string isCorrectPasswordFomate()
    {

    string password;
    do
    {
        cout << "Enter a 4-digit PIN as your password: ";
        cin >> password;

        if (password.length() != 4 || !isdigit(password[0]) || !isdigit(password[1]) || !isdigit(password[2]) || !isdigit(password[3]))
        {
            cout << "Invalid password. Please enter a 4-digit PIN.\n\n";
            continue;
        }

    } while (password.length() != 4 || !isdigit(password[0]) || !isdigit(password[1]) || !isdigit(password[2]) || !isdigit(password[3]));

        return password;
    }
    string passwordMaker()
    {
    string password;
    do
    {
        cout << "Enter a 4-digit PIN as your password: ";
        cin >> password;

        if (password.length() != 4 || !isdigit(password[0]) || !isdigit(password[1]) || !isdigit(password[2]) || !isdigit(password[3]))
        {
            cout << "Invalid password. Please enter a 4-digit PIN.\n\n";
            continue;
        }

    } while (password.length() != 4 || !isdigit(password[0]) || !isdigit(password[1]) || !isdigit(password[2]) || !isdigit(password[3]));

    string confirm;
    do
    {
        cout << "Confirm your password: ";
        cin >> confirm;

        if (confirm != password)
        {
            cout << "Passwords do not match. Restarting password setting.\n\n";
            return " ";
        }

    } while (confirm != password);

    return password;
    }
    //--------------------------------------------------
    string userInputCkeckPassword()
    {
        string password;
    do
    {
        cout << "Enter a 4-digit PIN as your password: ";
        cin >> password;

        if (password.length() != 4 || !isdigit(password[0]) || !isdigit(password[1]) || !isdigit(password[2]) || !isdigit(password[3]))
        {
            cout << "Invalid password. Please enter a 4-digit PIN.\n\n";
            continue;
        }

    } while (password.length() != 4 || !isdigit(password[0]) || !isdigit(password[1]) || !isdigit(password[2]) || !isdigit(password[3]));

    return password;
    }
};
//=============================================================
// Ending of Valid class
//=============================================================
// starting of student class
//=============================================================
class Student{
    private:
    string studentName;
    string studentId;
    string phoneNo;
    string dateOfBirth;
    string studentAddres;
    Valid *validObject ;
    int yearOfStudent;// example 1st year 2nd year;
    double CGPA;
    int yearOfAdmission;
    string password;
    //------------------------------
    public:
    // CONSTRUCTOR
    Student()
    {
         studentName = "";
         studentId = "";
         phoneNo = "";
         dateOfBirth = "";
         studentAddres = "";
         validObject = new Valid();
    }

    //----------------------------------------------------------
    string getName()
    {
        return studentName;
    }
    string getStudentId()
    {
        return studentId;
    }
    
    string getPhoneNo()
    {
        return phoneNo;
    }

    string getDateOfBirth()
    {
        return dateOfBirth;
    }
    string getStudentAddres()
    {
        return studentAddres;
    }

    int getYearOfStudent()
    {
        return yearOfStudent;
    }

    float getCGPA()
    {
        return CGPA;
    }

    float getYearOfAdmission()
    {
        return yearOfAdmission;
    }

    string getPassword()
    {
        return password;
    }

    // HELPER FUNCTIONS
    string setName()
    {
        string tempName = "";
        bool flag ;

        do{
            cout<<"Enter First name : ";
            string firstName;
            cin>>firstName;
            flag = validObject->isValidName(firstName);
            if(!flag )
            {
                cout<<"Invalid first name :\n";
            }
            else{
                tempName += firstName;
                tempName+=" ";
            }

        }while(!flag);

        do{
            cout<<"Enter second name : ";
            string secondName;
            cin>>secondName;
            flag = validObject->isValidName(secondName);
            if(!flag )
            {
                cout<<"Invalid second name :\n";
            }
            else{
                tempName += secondName;
            }

        }while(!flag);
        
        return tempName;
    }
    //---------------------
    string setId(int year,int numberOfStudent)
    {
        // series of id number is predifine ,
        //example :- 2022 01
        // in this example 2022 is a year and 01 means number of student 
        // by using this we can create infinite unique ids
        // and each time we add 1 in numberOfStudent ;

        /*
            in this function id series given 
            we just have to add number of sudent in series :
        */
       string id ;
       id+=to_string(year);
       if(numberOfStudent<10) id+='0';
        id += to_string(numberOfStudent);
       return id;

       // no need to check that id is valid not because id was create by us not by usere;
    }
    //---------------------
    string setphoneNumber()
    {
        string pno;
        bool flag ;
        do{
            cout<<"\nEnter you Phone number :";
            cin>>pno;
            flag = validObject->isValidPhoneNumber(pno);
        }while(!flag);

        return pno;
        
    }
    //---------------------
    
    string setAddress()
    {
        string addres;
        
        cout<<"Enter your Address : ";
        cin.ignore();
        getline(cin,addres);

        
        return addres;
    }
    //---------------------

    string setDateOfBirth(const int currentYear)
    {
        string date;
       
        bool flag;

        do{
            cout<<"Enter Date of birth (DD-MM-YYYY) : ";
             cin>>date;
            flag = validObject->isValidDate(date,currentYear);

            if(flag == 0)
            {
                cout<<"Invalid Date of Birth or Formate : \n\n";
            }
        }while(!flag);
        return date;
    }

    // string setDateOfBirth()
    // {
    //     string date;
       
    //     bool flag;

    //     do{
    //         cout<<"Enter Date of birth (DD-MM-YYYY) : ";
    //          cin>>date;
    //         flag = validObject->isValidDate(date,);

    //         if(flag == 0)
    //         {
    //             cout<<"Invalid Date of Birth or Formate : \n\n";
    //         }
    //     }while(!flag);
    //     return date;
    // }
    //---------------------
    float setCGPA()
    {
        
        float cgpaVale;
        string cgpa;
        do{
            cout<<"Enter CGPA (1 - 10) : ";
            cin>>cgpa;
            cgpaVale = validObject->isValidCGPA(cgpa);
            
        }while(cgpaVale == -1);
        return cgpaVale;
    }
    //---------------------
    int setyear()
    {
        bool flag;
        string year;
        do{
            cout<<"Enter year :(1,2,3,4) : ";
             
            cin>>year;
            flag = validObject->isValidYear(year);

        }while(flag);

        return stoi(year);
    }
    //----------------------------------------------------------
    int setYearOfAdmission(int currentYear)
    {
        string year;
        int intYear;
       
        
        do{
            cout<<"Enter Year of Admission : ";
            cin>>year;

            intYear = validObject->isValidAdmissionYear(year,currentYear);

        }while(!intYear);

       
        return intYear;
    }
    //----------------------------------------------------------

    string setPassword()
    {
    string password;
    while ( (password =validObject->passwordMaker() ) == " ")
    {

    }
    cout << "\nPassword set successfully!\n";

    return password;
    }

    string setPassword2()
    {
        // this method is use for password checking 
        // is correct Password Formate method is use for creating password and chake fomate only
    string password;
    while ( (password =validObject->isCorrectPasswordFomate() ) == " ")
    {

    }
    

    return password;
    }
    public :
    //_____________________________________________________________
    void creatNewAccount(const int year,const int numberOfStudent)
    {
        cout<<"\n======================================\n";
        studentName = setName();
        //cout<<"--------------------------------------\n";
        studentId = setId(year,numberOfStudent);
        cout<<"--------------------------------------\n";
        yearOfAdmission = setYearOfAdmission(year);
        cout<<"--------------------------------------";
        phoneNo = setphoneNumber();
        cout<<"--------------------------------------\n";
        cin.ignore();
        studentAddres = setAddress();
        cout<<"--------------------------------------\n";
        dateOfBirth = setDateOfBirth(year);
        cout<<"--------------------------------------\n";
        yearOfStudent = setyear();
        cout<<"--------------------------------------\n";
        CGPA = setCGPA();
        cout<<"--------------------------------------\n";
         password = setPassword();
         cout<<"======================================\n";
        cout<<"************\n";
        cout<<"Account Created !";
        cout<<"\n************\n";
    }
    // _____________________________________________________________
    void displayAccountDetils()
    {
        cout<<"\n========================================\n";
        cout<<"Name : "<<studentName<<endl;
        cout<<"--------------------------------------\n";
        cout<<"ID Number : "<<studentId<<endl;
        cout<<"--------------------------------------\n";
        cout<<"CGPA :"<<CGPA<<endl;
        cout<<"--------------------------------------\n";
        cout<<"Year : "<<yearOfStudent<<endl;
        cout<<"--------------------------------------\n";

        cout<<"Year of Admission : "<<yearOfAdmission<<endl;
        cout<<"--------------------------------------\n";

        cout<<"Date of Birth : "<<dateOfBirth<<endl;
        cout<<"--------------------------------------\n";
        cout<<"Phone Number : "<<phoneNo<<endl;
        cout<<"--------------------------------------\n";
        cout<<"Address : "<<studentAddres<<endl;
        cout<<"--------------------------------------\n";
    
    }

    // void displayAccountDetils()
    // {
    //     //cout<<endl<<"Name"<<"\t"<<"ID number"<<"\t"<<"CGPA"<<endl;
    //     cout<<studentName<<"\t"<<studentId<<"\t"<<CGPA<<endl;
    //     cout<<"-------------------------------------------------";
        
    
    // }
    //_________________________________________________________

    // void displayAccountList()
    // {

    // }
    
    //====================
    //Edit 
    void editName(Student * studentObject)
    {
        studentObject->studentName = studentObject->setName();
    }

    void editPhoneNumber(Student * studentObject)
    {
        studentObject->phoneNo = studentObject->setphoneNumber();
    }

    void editAddress(Student * studentObject)
    {
        studentObject->studentAddres = studentObject->setAddress();
    }

    void editDateOfBirth(Student * studentObject)
    {
        studentObject->dateOfBirth = studentObject->setDateOfBirth(9999);
    }
    void editYearOfAddmission(Student * studentObject)
    {
        studentObject->yearOfAdmission = studentObject->setYearOfAdmission(999999);
    }
    void updateCGPA(Student * studentObject)
    {
        studentObject->CGPA = studentObject->setCGPA();
    }

    void chagePassword(Student * studentObject)
    {
        studentObject->password = studentObject->setPassword2();
    }




};
//=============================================================
// end of student class
//=============================================================
// Starting oF Data Base Clases
//=============================================================

class BaseDataClass : public Student, public Valid{

    
    // Base Data class inherit  student class because we need fuctions like setname, setpassword etc in Baseclass
    // i know we can creat object also but if we creat object of student class than all the atribut of student also get space which if of no use 
    // by using inheritance we directly call all function , and atribut of student class will take space in memory only ones;
    // class which will store all student object reference
    public:
    vector<Student *>dataArray;// base array is arranged(sorted with Student ID );
    int year;// year for id seares
    // want to use static key word .
     int numberOfStudent;// total number of student which is equal to the size of base array :
    public:

    BaseDataClass()
    {
        
    }
    //-------------------------------------------------------------

   BaseDataClass(int year){
        this->year = year;
        numberOfStudent = 0;
     // Id serise can be made when new accound is created 
   }
    
    //-------------------------------------------------------------
    bool addAccount()
    {
        Student *objectOfStudent = new Student();
        objectOfStudent->creatNewAccount(year,numberOfStudent);
        dataArray.push_back(objectOfStudent);
        numberOfStudent++;
        return true;
    }
    //-------------------------------------------------------------

    
    void displayAllAcoount()
    {
        int dataArraysize = dataArray.size();
        for(int i=0; i<dataArraysize; i++)
        {
            dataArray[i]->displayAccountDetils();
        }
    }

    void working()
    {
    cout<<"Wroking : ";
    }

    //-------------------------------------------
    //-------------------------------------------

void loginMenu(Student *studentObject)
{
    
    string userInput;

    do {
        // Display colored and styled menu
        cout << BOLD_TEXT << GREEN_TEXT << "Students Management System\n" << RESET_TEXT;
        cout << GREEN_TEXT << "Menu:\n"<< RESET_TEXT;
        cout << "1. " << YELLOW_TEXT << "Edit Detalis\n" << RESET_TEXT;
        cout << "2. " << YELLOW_TEXT << "View Detalis\n" << RESET_TEXT;
        cout << "3. " << YELLOW_TEXT << "Change Password\n" << RESET_TEXT;
        // cout << "4. " << YELLOW_TEXT << "View Fees Detalis\n" << RESET_TEXT;
        // cout << "5. " << YELLOW_TEXT << "Course Detalis\n" << RESET_TEXT;
        cout << "0. " << RED_TEXT << "Exit\n" << RESET_TEXT;
        cout << "Enter your choice: ";

        // Get user input
        std::cin >> userInput;

        // Call corresponding function based on user input
        if (userInput == "1") {
           editDetalis(studentObject);
        } else if (userInput == "2") {
            viewDetalis(studentObject);
        } else if (userInput == "3") {
            //chagePassword(studentObject);
            chagePassword(studentObject);
        }
        // else if (userInput == "4") {
        //   working();// fees
        // } else if (userInput == "5") {
        //   working();// course detalis:
        // } 
        else if (userInput != "3") {
            std::cout << RED_TEXT << "Invalid choice. Please try again.\n" << RESET_TEXT;
        }

    } while (userInput != "0");

}

    void editDetalisMenu(Student *studentObject)
    {
        
    string userInput;

    do {
        // Display colored and styled menu
        cout << BOLD_TEXT << GREEN_TEXT << "Students Management System\n" << RESET_TEXT;
        cout << GREEN_TEXT << "Menu:\n" << RESET_TEXT;
        cout << "1. " << YELLOW_TEXT << "Edit Name\n" << RESET_TEXT;
        cout << "2. " << YELLOW_TEXT << "Edit Phone Number\n" << RESET_TEXT;
        cout << "3. " << YELLOW_TEXT << "Edit Address\n" << RESET_TEXT;
        cout << "4. " << YELLOW_TEXT << "Update CGPA\n" << RESET_TEXT;
        cout << "5. " << YELLOW_TEXT << "Edit Year Of Admission : \n" << RESET_TEXT;
        cout << "6. " << YELLOW_TEXT << "Edit Date OF Birth  : \n" << RESET_TEXT;
        cout << "0. " << RED_TEXT << "Exit\n" << RESET_TEXT;
        cout << "Enter your choice: ";

        // Get user input
        std::cin >> userInput;

        // Call corresponding function based on user input
        if (userInput == "1") {
            //name
           editName(studentObject);
        } else if (userInput == "2") {
            //phone no
            editPhoneNumber(studentObject);
        } else if (userInput == "3") {
            // address
            editAddress(studentObject);
        } else if (userInput == "4") {
           updateCGPA(studentObject);// CGPA
        } else if (userInput == "5") {
          editYearOfAddmission(studentObject);// year of Admission
        } else if (userInput == "6") {
          editDateOfBirth(studentObject);// DOB
        }
        else if (userInput != "6") {
            std::cout << RED_TEXT << "Invalid choice. Please try again.\n" << RESET_TEXT;
        }

    } while (userInput != "0");
    }
    //------------------------------------------
    void editDetalis(Student *objStudent)
    { 
        editDetalisMenu(objStudent);
    }

    
    //------------------------------------------

    void viewDetalis(Student *objStudent)
    {
        cout<<"Name : "<<objStudent->getName();
        cout<<endl<<"Id number : "<<objStudent->getStudentId();
        cout<<endl<<"CGPA : "<<objStudent->getCGPA();
        cout<<endl<<"Year Of Admison : "<<objStudent->getYearOfAdmission();
        cout<<endl<<"Address : "<<objStudent->getStudentAddres();
        cout<<endl<<"Phone Number : "<<objStudent->getPhoneNo();
        cout<<"DOB : "<<objStudent->getDateOfBirth(); 
        
    }

    string setId(int &chaker)
    {  
        bool flag;
        string tempId;
        do{
            cout<<"Enter Id number : ";
            cin>>tempId;

            if(tempId == "0")
            { 
                chaker = 0 ; 
                
                return "";
            }

            flag = isValidId(tempId);
            if(!flag )
            {
                cout<<"Invalid Id :\n";
            }
        }while(!flag);
        return tempId;
    }

    string setId()
    {  
        bool flag;
        string tempId;
        do{
            cout<<"Enter Id number : ";
            cin>>tempId;
           
            flag = isValidId(tempId);
            if(!flag )
            {
                cout<<"Invalid Id :\n";
            }
        }while(!flag);
        return tempId;
    }

     void checkPassword(Student *obj)
    {
        string pass;
        bool flag = 0;
        do{
            pass = setPassword2();
            if(pass == obj->getPassword())
            {
                flag = 1;
            }
            else{
                flag = 0;
                cout<<"Password is not correct : ";
                cout<<"tyr agian : \n";
            }
        }while(!flag);

    }

    void loginWithId( )//here n decided after loin what will do:
    {
       
       
        string idnumber;
        Student *objectOfStudent;
        do{

            idnumber = setId();
            objectOfStudent = searchAccount(idnumber);
           

            if(objectOfStudent == NULL)
            {
                cout<<"Id number does Not found : ";
                cout<<"Try again \n";
            }
        
        }while(!objectOfStudent);

        checkPassword(objectOfStudent);

        cout<<"Login successfull !";
        
        system("CLS");  
       
        loginMenu(objectOfStudent);

    }

   

    Student *searchAccount(string idnumber)
    {
        int size = dataArray.size();
        for(int i=0; i<size; i++)
        {
            if(dataArray[i]->getStudentId()== idnumber) return dataArray[i];
        }

        return NULL;
    }

    Student *searchAccount(string idnumber, int &idx)
    {
        int size = dataArray.size();
        for(int i=0; i<size; i++)
        {
            if(dataArray[i]->getStudentId()== idnumber) 
            {
                idx = i;
                return dataArray[i];
            }
        }

        return NULL;
    }
    bool isValidId(string id)
    {
        int size = id.size();
        for(int i=0; i<size; i++)
        {
            if(id[i] < '0' || id[i]>'9') return 0;
        }

        return 1;
    }
    void deletAccount()
    {
        int idx;
         string idnumber;
        Student *objectOfStudent;
        int flag = 1;
        do{

            idnumber = setId(flag);
           
             if(flag == 0) return ;

            objectOfStudent = searchAccount(idnumber,idx);
            
          
            if(objectOfStudent == NULL)
            {
                cout<<"Id number does Not found : ";
                cout<<"Try again \n";
            }
        
        }while(!objectOfStudent);

        checkPassword(objectOfStudent);

        dataArray[idx] = nullptr;

    }
    
    //-------------------------------------------
    //-------------------------------------------
};

//=============================================================
// end oF Data Base Clases
//=============================================================
void firstPageInterphase()
{
    system("CLS");

    cout<<YELLOW_TEXT<<"-------------------------------------------------------------------------" << RESET_TEXT<<endl;
    cout << BOLD_TEXT <<  RED_TEXT << "\t\tStudents Management System\n" << RESET_TEXT;
    cout<<YELLOW_TEXT<<"-------------------------------------------------------------------------" << RESET_TEXT<<endl;

                            

}



int manu1( BaseDataClass *objOfBase)
{
    
     string userInput;

    do {
        // Display colored and styled menu
        cout << BOLD_TEXT << GREEN_TEXT << "\nStudents Management System\n" << RESET_TEXT;
        cout << BOLD_TEXT <<  RED_TEXT  "Menu:\n" << RESET_TEXT;
        cout << "1. " << YELLOW_TEXT << "Add Student\n" << RESET_TEXT;
        cout << "2. " << YELLOW_TEXT << "View All Students\n" << RESET_TEXT;
        cout << "3. " << YELLOW_TEXT << "Login Accound\n" << RESET_TEXT;
        cout << "4. " << YELLOW_TEXT << "DeletAccunt :\n" << RESET_TEXT;
        // cout << "5. " << YELLOW_TEXT << "workinng\n" << RESET_TEXT;
        // cout << "6. " << YELLOW_TEXT << "workinng\n" << RESET_TEXT;
        // cout << "7. " << YELLOW_TEXT << "workinng\n" << RESET_TEXT;
        // cout << "8. " << YELLOW_TEXT << "workinng\n" << RESET_TEXT;
        // cout << "9. " << YELLOW_TEXT << "workinng\n" << RESET_TEXT;
        // cout << "10. " << YELLOW_TEXT << "workinng\n" << RESET_TEXT;
        cout << "0. " << RED_TEXT << "Exit\n" << RESET_TEXT;
        cout << YELLOW_TEXT << "Enter your choice: "<< RESET_TEXT;

        // Get user input
        std::cin >> userInput;

        // Call corresponding function based on user input
        if (userInput == "1") {
            objOfBase->addAccount();
        } else if (userInput == "2") {
            objOfBase->displayAllAcoount();
        } else if (userInput == "3") {
            objOfBase->loginWithId();
        } else if (userInput == "4") {
            objOfBase->deletAccount();
        }
        //else if (userInput == "5") {
        //     objOfBase->working();
        // } else if (userInput == "6") {
        //     objOfBase->working();
        // } else if (userInput == "7") {
        //     objOfBase->working();
        // } else if (userInput == "8") {
        //     objOfBase->working();
        // } else if (userInput == "9") {
        //     objOfBase->working();
        // } else if (userInput == "10") {
        //     objOfBase->working();
        // } 
        else if (userInput != "0") {
            std::cout << RED_TEXT << "Invalid choice. Please try again.\n" << RESET_TEXT;
        }

    } while (userInput != "0");

    std::cout << RED_TEXT << "Exiting the program. Goodbye!\n" << RESET_TEXT;

    return 0;
}
int main()
{
    firstPageInterphase();
    BaseDataClass *obj = new BaseDataClass(2023);
    manu1(obj); 
     
}

//============================================
