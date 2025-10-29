// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
#define ll long long
    using namespace std;
    struct patient {
        string name;
        int age;
        int id;
        string illness;
        string gender;
        string department;
        string doctorname="not assigned";
    };
    struct doctor {
        string name;
        int id;
        string department;
    };
    class HospitalSystem {
        vector<patient>patients;
        vector<doctor>doctors;
    public:
        void addPatient()
    {
        patient p;
        cout << "Enter patient name\n";
        cin.ignore();
        string n;
        getline(cin,n); p.name = n;
        cout << "Enter patient age\n";
        int a; cin >> a; p.age = a;
        cout << "Enter patient gender\n";
        cin.ignore();
        string g; getline(cin,g); p.gender = g;
        cout << "Enter patient id\n";
        int i; cin >> i; p.id = i;
        cout << "Enter patient illness\n";
        cin.ignore();
        string ill; getline(cin,ill); p.illness = ill;
        cout << "Enter department\n";
        cin.ignore();
        string department; cin >> department;
        patients.push_back(p);
        cout << "Patient is added successfully\n";
    }
          void displayPatientinfo() {
              if (patients.empty())
              {
                  cout << "There no patient is added\n";
                  return;
              }
              for (auto& p : patients)
              {
                  cout << "patient name is: " << p.name << "\n";
                  cout << "patient ID is: " << p.id << "\n";
                  cout << "patient age is: " << p.age << "\n";
                  cout << "patient gender is: " << p.gender << "\n";
                  cout << "patient illness is: " << p.illness << "\n";
                  cout << "patient doctor is: " << p.doctorname << "\n";
                  cout << "patient department is: " << p.department << "\n";
                  cout << "==================================\n";

              }
          }
              void addDoctor() {
                  doctor d;
                  cout << "Enter doctor name\n";
                  cin.ignore(); string n;
                  cin >> n; d.name = n;
                  cout << "Enter doctor department\n";
                  cin.ignore(); string D;
                  cin >> D; d.department = D;
                  cout << "Enter doctor id\n";
                  int i;
                  cin >> i; d.id = i;
                  cout << "Doctor is added successfully\n";
                  cout << "==================================";
              }
              void displayDoctorinfo() {
                  if (doctors.empty()) {
                      cout << "No doctor added\n";
                      return;
                  }
                  for (auto& d : doctors)
                  {
                      cout << "Doctor name is: " << d.name << "\n";
                      cout << "Doctor id is: " << d.id << "\n";
                      cout << "Doctor department is: " << d.department << "\n";
                  }
                  cout << "=============================";
              }
              void searchPatient() {
                  int id;
                  cout << "Enter patient id\n";
                  cin >> id;
                  if (patients.empty())
                  {
                      cout << "nopatient exsist\n";
                      return;
                  }
                  for (auto& p : patients)
                  {
                      if (p.id == id) {
                          cout << "patient found\n";
                          displayPatientinfo();
                          return;
                      }
                  }
                  cout << "not found\n";
              }
              void assignDoctor() {
                  int pid, did;
                  cout << "Enter patient id and doctor id\n";
                  cin >> pid >> did;
                  string doctorname = "";
                  for (auto& d : doctors) {
                      if (d.id == did)
                          doctorname = d.name;
                      break;
                  }
                  if (doctors.empty()) {
                      cout << "No doctor found\n";
                      return;
                  }
                  for (auto& p : patients)
                  {
                      if (p.id == pid)
                      {
                          p.doctorname = doctorname;

                          cout << "Doctor " << doctorname << "is assigned for " << p.name << "successfully\n";
                          return;
                      }
                  }
                      cout << "patient not found\n";
                  
              }
              void deletePatient()
              {
                  int id;
                  cout << "Enter patient id\n";
                  cin >> id;
                  for (auto i = patients.begin(); i != patients.end(); i++)
                  {
                      if (i->id == id)
                      {
                          cout << "patient " << i->name << " is deleted successfully\n";
                          patients.erase(i);
                          return;
                      }
                  }
                  cout << "patient not found\n";
              }
              void menu();
    };
     void HospitalSystem:: menu() {
        int choice;
        
       
        do{
            cout << "enter your choice from 1 to 8\n";
            cin >> choice;
            switch (choice)
            {
            case 1: addPatient();
                break;
            case 2:searchPatient();
                break;

            case 3:addDoctor();
                break;
            case 4:displayDoctorinfo();
                break;
            case 5:assignDoctor();
                break;
            case 6:deletePatient();
                break;
            case 7:displayPatientinfo();
            case 8:cout << "you Exsist \n"; 
                break;

            }
        } while (choice != 8);
       
    }
     void show()
     {
         cout << "Enter 1 to add patient\n";
         cout << "Enter 2 to search patient\n";
         cout << "Enter 3 to add doctor\n";
         cout << "Enter 4 to know doctor information\n";
         cout << "Enter 5 to assign doctor\n";
         cout << "Enter 6 to delete patient\n";
         cout << "Enter 7 to know patient information\n";
         cout << "Enter 8 to Exsist\n";
     }
    int main() {

        HospitalSystem hospital;
        show();
        hospital.menu();
        return 0;
    }


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
