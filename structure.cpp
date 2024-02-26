#include <iostream>

using namespace std;

struct student {
    int ID;
    string FirstName;
    string LastName;
    string Birthday;
    string Address;
    string ContactInfo;
    int StudentClass;
    int Marks;
    struct student* back;
    struct student* next;
};
struct student* i, * j;
struct student* Curr, * ptr;
struct student* Head = new student;
static int ID = 41110;

void search();
void Display(struct student* CURR);
void RemoveNode();
void AddNode();
void Report();
void attendence();
void Initialize();

int main() {
    Initialize();
    int loop = 1;
    int choice;
    while (loop) {
        cout << "\n\n\t\t\tStudent Database Management System";
        cout << "\n\n\t\t\t1. Add Student";
        cout << "\n\t\t\t2. Remove Student";
        cout << "\n\t\t\t3. Search Student";
        cout << "\n\t\t\t4. Attendance Report";
        cout << "\n\t\t\t5. Class Report";
        cout << "\n\t\t\t6. Exit";
        cout << "\n\n\t\t\tEnter your choice (1-6): ";
        cin >> choice;
        if (!cin >> choice) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "\n\n\t\t\tPlease enter a number!\n";
        }
        else
            switch (choice) {
            case 1:
                AddNode();
                break;
            case 2:
                RemoveNode();
                break;
            case 3:
                search();
                break;
            case 4:
                attendence();
                break;
            case 5:
                Report();
                break;
            case 6:
                cout << "\n\n\t\t\texiting.";
                loop = 0;
                break;
            default:
                cout << "\n\n\t\t\tInvalid Choice";
            }

    }

    return 0;
}


void Initialize() {
    Head->back = Head;
    Head->next = Head;
    Head->Marks = Head->StudentClass = 0;
    Head->FirstName = Head->LastName = Head->Birthday = " ";
    Head->Address = Head->ContactInfo = " ";
}

void attendence() {
    int present = 0;
    int absent = 0;
    int findClass;
    cout << "\n\n\t\t\tEnter the class to take the attendence :";
    cin >> findClass;
    if (Head->next == Head && Head->back == Head) {
        cout << "\n\n\t\t\tWe don't have a student ";
        return;
    }
    struct student* NoClass = new student();
    NoClass->StudentClass = findClass;
    bool Findclass = false;
    char Attend;

    for (i = Head->next; i != Head; i = i->next) {
        if (i->StudentClass == NoClass->StudentClass) {
            cout << "\n\n\t\t\tID :" << i->ID << "\n\n\t\t\tName :" << i->FirstName << " " << i->LastName << "\n\n\t\t\tBirthday :" << i->Birthday
                << "\n\n\t\t\tAddress :" << i->Address << "\n\n\t\t\tContact information :" << i->ContactInfo
                << "\n\n\t\t\tStudent class :" << i->StudentClass;
            cout << "\n\n\t\t\tIs the student present?:";
            cout << "\n\n\t\t\t(Y) for present";
            cout << "\n\n\t\t\t(N) for absent\n\t\t\t";
            cin >> Attend;
            if (Attend == 'Y' || Attend == 'y')
                present++;
            else if (Attend == 'N' || Attend == 'n')
                absent++;
            else {
                cout << "\n\n\t\t\tPlease enter a valid choice!";
                return;
            }
            Findclass = true;
        }
    }
    cout << "\n\n\t\t\tThe number of the Present students is : " << present;
    cout << "\n\n\t\t\tThe number of the Absent students is : " << absent;
}
void Report() {
    struct student* temp = new student();
    struct student* NoClass = new student();
    struct student* k = new student();

    int findClass;
    cout << "\n\n\t\t\tEnter the class to get report :";
    cin >> findClass;
    if (Head->next == Head && Head->back == Head) {
        cout << "\n\n\t\t\tWe don't have a student ";
        return;
    }
    //-------------------sort--------------------------
    for (k = Head->next; k->next != Head; k = k->next) {
        for (j = k->next; j != Head; j = j->next) {
            if (j->Marks > k->Marks) {
                temp->ID = k->ID;
                temp->FirstName = k->FirstName;
                temp->LastName = k->LastName;
                temp->Birthday = k->Birthday;
                temp->Address = k->Address;
                temp->ContactInfo = k->ContactInfo;
                temp->StudentClass = k->StudentClass;
                temp->Marks = k->Marks;

                k->ID = j->ID;
                k->FirstName = j->FirstName;
                k->LastName = j->LastName;
                k->Birthday = j->Birthday;
                k->Address = j->Address;
                k->ContactInfo = j->ContactInfo;
                k->StudentClass = j->StudentClass;
                k->Marks = j->Marks;

                j->ID = temp->ID;
                j->FirstName = temp->FirstName;
                j->LastName = temp->LastName;
                j->Birthday = temp->Birthday;
                j->Address = temp->Address;
                j->ContactInfo = temp->ContactInfo;
                j->StudentClass = temp->StudentClass;
                j->Marks = temp->Marks;
            }
        }
    }
    NoClass->StudentClass = findClass;
    int NoAvg = 0;
    float TotalAvg = 0;
    float Avg;
    bool FindClass = false;
    int NoAtten = 0;
    //---------------------traverse search---------------------------
    for (i = Head->next; i != Head; i = i->next) {
        if (i->StudentClass == NoClass->StudentClass) {
            cout << "\n\n\t\t\tID :" << i->ID << "\n\n\t\t\tName :" << i->FirstName << " " << i->LastName << "\n\n\t\t\tBirthday :" << i->Birthday
                << "\n\n\t\t\tAddress :" << i->Address << "\n\n\t\t\tContact information :" << i->ContactInfo
                << "\n\n\t\t\tStudent class :" << i->StudentClass << "\n\n\t\t\tMarks :" << i->Marks << "\n";
            NoAvg++;
            NoAtten++;
            TotalAvg += i->Marks;
            FindClass = true;
        }
    } //--------------print the average of class-----------------------
    Avg = TotalAvg / NoAvg;
    if (FindClass == false)
        cout << "\n\n\t\t\tWe don't have this class ";
    else
        cout << "\n\n\t\t\tThe average Marks of this class is : " << Avg;
    // --------------print the number of students----------------------
    cout << "\n\n\t\t\tThe number of students in this class is :" << NoAtten;
}

void AddNode() {
    ID++;
    struct student* newNode = new student;
    cout << "\n\n\t\t\tFirst name : ";
    cin >> newNode->FirstName;
    cout << "\n\n\t\t\tLast name : ";
    cin >> newNode->LastName;
    cout << "\n\n\t\t\tEnter The birthday : ";
    cin >> newNode->Birthday;
    cout << "\n\n\t\t\tEnter the Address : ";
    cin >> newNode->Address;
    cout << "\n\n\t\t\tEnter the Contact info : ";
    cin >> newNode->ContactInfo;
    cout << "\n\n\t\t\tEnter the class of student : ";
    cin >> newNode->StudentClass;
    cout << "\n\n\t\t\tEnter the mark of student : ";
    cin >> newNode->Marks;

    newNode->ID = ID;

    if (Head->back == Head) {
        Head->back = Head->next = newNode;
        newNode->next = newNode->back = Head;
        cout << "\n\n\t\t\tThe information of this student is : ";
        cout << "\n\n\t\t\tID :" << ID << "\n\n\t\t\tName :" << newNode->FirstName << " " << newNode->LastName << "\n\n\t\t\tBirthday :" << newNode->Birthday
            << "\n\n\t\t\tAddress :" << newNode->Address << "\n\n\t\t\tContact information :" << newNode->ContactInfo
            << "\n\n\t\t\tStudent class :" << newNode->StudentClass << "\n\n\t\t\tMarks :" << newNode->Marks;
        return;
    }
    struct student* Post = NULL, * Prev = NULL;
    for (Curr = Head->next; Curr != Head; Curr = Curr->next) {
        Post = Curr->next;
        Prev = Curr;
    }
    newNode->next = Post;
    newNode->back = Prev;
    Prev->next = Curr->back = newNode;

    cout << "\n\n\t\t\tthe information of this student is : ";
    cout << "\n\n\t\t\tID :" << ID << "\n\n\t\t\tName :" << newNode->FirstName << " " << newNode->LastName << "\n\n\t\t\tBirthday :" << newNode->Birthday
        << "\n\n\t\t\tAddress :" << newNode->Address << "\n\n\t\t\tContact information :" << newNode->ContactInfo
        << "\n\n\t\t\tStudent class :" << newNode->StudentClass << "\n\n\t\t\tMarks :" << newNode->Marks;
}
void RemoveNode() {
    string rfn;
    string rln;
    cout << "\n\n\t\t\tEnter First Name : ";
    cin >> rfn;
    cout << "\n\n\t\t\tEnter Last Name : ";
    cin >> rln;
    if (Head->next == Head && Head->back == Head) {
        cout << "\n\n\t\t\tNo students to remove!";
        return;
    }

    struct student* ToDelete = nullptr;

    for (Curr = Head->next; Curr != Head; Curr = Curr->next) {
        if (Curr->FirstName == rfn && Curr->LastName == rln) {
            ToDelete = Curr;
            break;
        }
    }

    if (ToDelete != nullptr) {
        struct student* PrevNode = ToDelete->back;
        struct student* NextNode = ToDelete->next;

        PrevNode->next = NextNode;
        NextNode->back = PrevNode;

        delete ToDelete;

        cout << "\n\n\t\t\tThe Student " << rfn << " " << rln << " removed successfully!";
    }
    else {
        cout << "\n\n\t\t\tStudent not found!";
    }
}
void Display(struct student* CURR) {

    cout << "\n\n\t\t\tID : " << CURR->ID;
    cout << "\n\n\t\t\tName : " << CURR->FirstName << " " << CURR->LastName;
    cout << "\n\n\t\t\tMarks : " << CURR->Marks;
    cout << "\n\n\t\t\tClass : " << CURR->StudentClass;
    cout << "\n\n\t\t\tDay of Birth : " << CURR->Birthday;
    cout << "\n\n\t\t\tAddress : " << CURR->Address;
    cout << "\n\n\t\t\tContact Info : " << CURR->ContactInfo;
}
void search() {
    if (Head->back == Head && Head->next == Head) {
        cout << "\n\n\t\t\tList is Empty"; return;
    }
    struct student* CURR;
    int SrchID;
    cout << "\n\n\t\t\tEnter The ID : ";
    cin >> SrchID;
    for (CURR = Head->back; CURR != Head; CURR = CURR->back) {
        if (SrchID == CURR->ID) 
            break;
    }
    if (CURR == Head) {
        cout << "\n\n\t\t\tStudent not found!"; return;
    }
    else {
        Display(CURR);
    }
}
