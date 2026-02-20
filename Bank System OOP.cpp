#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <limits>
#include <iomanip>

using namespace std;

class clsString
{
public:
    
   static string UpperAllString(string S1)
   {
        for (int i = 0; i < S1.length(); i++)
        {
            S1[i] = toupper(S1[i]);     
        }
        
        return S1;
   }

    static vector<string> Split(string s, string delimiter)
    {
        vector<string> v;
        size_t pos = 0;
        string token;
        while ((pos = s.find(delimiter)) != string::npos)
        {
            token = s.substr(0, pos);
            v.push_back(token);
            s.erase(0, pos + delimiter.length());
        }
        v.push_back(s);
        return v;
    }

    static string NumberToText(int Number)
   {

       if (Number == 0)
       {
           return "";
       }

       if (Number >= 1 && Number <= 19)
       {
           string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
       "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
         "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

           return  arr[Number] + " ";

       }

       if (Number >= 20 && Number <= 99)
       {
           string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
           return  arr[Number / 10] + " " + NumberToText(Number % 10);
       }

       if (Number >= 100 && Number <= 199)
       {
           return  "One Hundred " + NumberToText(Number % 100);
       }

       if (Number >= 200 && Number <= 999)
       {
           return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
       }

       if (Number >= 1000 && Number <= 1999)
       {
           return  "One Thousand " + NumberToText(Number % 1000);
       }

       if (Number >= 2000 && Number <= 999999)
       {
           return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
       }

       if (Number >= 1000000 && Number <= 1999999)
       {
           return  "One Million " + NumberToText(Number % 1000000);
       }

       if (Number >= 2000000 && Number <= 999999999)
       {
           return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
       }

       if (Number >= 1000000000 && Number <= 1999999999)
       {
           return  "One Billion " + NumberToText(Number % 1000000000);
       }
       else
       {
           return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
       }


   }

};

class clsDate
{
private:
    short Day;
    short Month;
    short Year;

public:
    clsDate()
    {
        time_t t = time(0);
        tm* now = localtime(&t);
        Day = now->tm_mday;
        Month = now->tm_mon + 1;
        Year = now->tm_year + 1900;
    }


    short getDay() { return Day; }
    void setDay(short day) { Day = day; }

    short getMonth() { return Month; }
    void setMonth(short month) { Month = month; }

    short getYear() { return Year; }
    void setYear(short year) { Year = year; }

    void Print()
    {
        cout << DateToString() << endl;
    }

    static string GetSystemDateTimeString()
    {
        time_t t = time(0);
        tm* now = localtime(&t); 
        short Day, Month, Year, Second, Hour, Minute;
        Day = now ->tm_mday;
        Month = now -> tm_mon;
        Year = now -> tm_year;
        Second = now -> tm_sec;
        Hour = now -> tm_hour;
        Minute = now -> tm_min;

        return (to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year) + " _ " 
        + to_string(Hour) + ":" + to_string(Minute) + ":" + to_string(Second));
    }

    static string DateToString(clsDate Date)
    {
        return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
    }

    string DateToString()
    {
        return DateToString(*this);
    }

    static bool isLeapYear(short Year)
    {
        return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
    }

    bool isLeapYear()
    {
        return isLeapYear(Year);
    }

    static short NumberOfDaysInAYear(short Year)
    {
        return isLeapYear(Year) ? 366 : 365;
    }

    short NumberOfDaysInAYear()
    {
        return NumberOfDaysInAYear(Year);
    }

    static short NumberOfHoursInAYear(short Year)
    {
        return NumberOfDaysInAYear(Year) * 24;
    }

    short NumberOfHoursInAYear()
    {
        return NumberOfHoursInAYear(Year);
    }

    static int NumberOfMinutesInAYear(short Year)
    {
        return NumberOfHoursInAYear(Year) * 60;
    }

    int NumberOfMinutesInAYear()
    {
        return NumberOfMinutesInAYear(Year);
    }

    static int NumberOfSecondsInAYear(short Year)
    {
        return NumberOfMinutesInAYear(Year) * 60;
    }

    int NumberOfSecondsInAYear()
    {
        return NumberOfSecondsInAYear(Year);
    }

    static short NumberOfDaysInAMonth(short Month, short Year)
    {
        if (Month < 1 || Month > 12)
            return 0;
        int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
    }

};

class clsPerson 
{
private:
   string  _FirstName;
   string _LastName;
   string _Email;
   string _Phone;
public:
  
   clsPerson( string FirstName,  string LastName, string Email, string Phone)
   {
        _FirstName = FirstName;
        _LastName =  LastName;
        _Email = Email;
        _Phone = Phone;    
   }

   void SetFirstName(string FirstName)
   {
      _FirstName = FirstName;
   }
    
   string GetFirstName()
   {
       return  _FirstName;
   }
   
   void SetLastName(string LastName)
   {
      _LastName = LastName;
   }
    
   string GetLastName()
   {
       return  _LastName;
   }

   void SetEmail(string Email)
   {
      _Email = Email ;
   }
    
   string GetEmail()
   {
       return  _Email;
   }

   void SetPhone (string Phone)
   {
      _Phone = Phone;
   }
    
   string GetPhone()
   {
       return  _Phone;
   }
   
};

class clsBankClient : public clsPerson 
{
private:
    enum enMode {EmptyMode = 0, UpdateMode = 1, AddNewMode = 2};
    enMode _Mode;
    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkForDelete = false;

    static clsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData = clsString::Split(Line, Seperator);
        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stof(vClientData[6]));
    }
    
    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient (enMode::EmptyMode, "", "", "", "", "", "", 0); 
    }
    
    static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {
        string stClientRecord = "";
        stClientRecord += Client.GetFirstName() + Seperator;
        stClientRecord += Client.GetLastName() + Seperator;
        stClientRecord += Client.GetEmail() + Seperator;
        stClientRecord += Client.GetPhone() + Seperator;
        stClientRecord += Client.AccountNumber() + Seperator;
        stClientRecord += Client.GetPinCode() + Seperator;
        stClientRecord += to_string(Client.GetAccountBalance());

        return stClientRecord;
    }
    
    static void _SaveClientDataToFile(vector<clsBankClient>_vClients)
    {
        fstream MyFile;
        MyFile.open("ClientsData.txt", ios::out);

        if (MyFile.is_open())
        {
            string DataLine;
            for (clsBankClient& C : _vClients)
            {
                if (C._MarkForDelete == false)
                {
                    DataLine = _ConvertClientObjectToLine(C);
                    MyFile << DataLine << endl;
                }
                
            }
            
            MyFile.close();
        }
    }

    static vector<clsBankClient> _LoadClientDataFromFile()
    {
        vector<clsBankClient>_vClients;
        fstream MyFile;
        MyFile.open("ClientsData.txt", ios::in);

        if (MyFile.is_open())
        {
            string DataLine;
            while (getline(MyFile, DataLine))
            {
                clsBankClient Client = _ConvertLineToClientObject(DataLine);
                _vClients.push_back(Client);
            }
            
            MyFile.close();
        }

        return _vClients;
    }
    
    void _AddDataLineToFile(string stDataLine)
    {
        fstream MyFile;
        MyFile.open("ClientsData.txt", ios::in | ios:: app);

        if (MyFile.is_open())
        {
           MyFile << stDataLine << endl;
        }
        
        MyFile.close();
    }
    
    void _Update()
    {
        vector<clsBankClient>_vClients = _LoadClientDataFromFile();
        
        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }
        }

        _SaveClientDataToFile(_vClients);
    }
  
    void  _AddNewClient()
    {
        _AddDataLineToFile(_ConvertClientObjectToLine(*this));
    }
    
public:

clsBankClient(enMode Mode, string FirstName,  string LastName, string Email, string Phone,  string AccountNumber, string PinCode, float AccountBalance): 
             clsPerson(FirstName,  LastName, Email, Phone)
{
    _Mode = Mode;
    _AccountNumber = AccountNumber;
    _PinCode = PinCode;
    _AccountBalance = AccountBalance; 
}

bool IsEmpty()
{
     return (_Mode == enMode::EmptyMode);
}

string AccountNumber()
{
    return  _AccountNumber;
}

void SetPinCode(string PinCode)
{
    _PinCode = PinCode;
}
    
string GetPinCode()
{
    return _PinCode;
}

void SetAccountBalance(float AccountBalance)
{
    _AccountBalance = AccountBalance;
}
    
float GetAccountBalance()
{
    return _AccountBalance;
}

string FullName()
{
   
    return GetFirstName() + " " + GetLastName();
}

void Print()
{
    cout << endl << "Client Card" << endl;
    cout << "-----------------------" << endl;
    cout << "First Name  : " << GetFirstName()<< endl;
    cout << "Last Name   : " << GetLastName() << endl;
    cout << "FullName    : " << FullName() << endl;
    cout << "Email       : " << GetEmail() << endl;
    cout << "Phone       : " << GetPhone() << endl;
    cout << "Acc. Number : " << AccountNumber() << endl;
    cout << "Password    : " << GetPinCode() << endl;
    cout << "Balance     : " << GetAccountBalance() << endl;
    cout << "-----------------------" << endl;
}

static  clsBankClient Find(string AccountNumber)
{
    fstream MyFile;
    MyFile.open("ClientsData.txt", ios::in);

    if (MyFile.is_open())
    {
        string Line;
        while (getline(MyFile, Line))
        {
           clsBankClient Client = _ConvertLineToClientObject(Line); 

           if (Client.AccountNumber() == AccountNumber)
           {
               MyFile.close();
               return Client;
           } 
        }
        MyFile.close();
    }
    
    return _GetEmptyClientObject();
}

static clsBankClient Find (string AccountNumber, string PinCode)
{
    fstream MyFile;
    MyFile.open("ClientsData.txt", ios::in);

    if (MyFile.is_open())
    {
        string Line;
        while (getline(MyFile, Line))
        {
            clsBankClient Client = _ConvertLineToClientObject(Line);
            if ((Client.AccountNumber() == AccountNumber) && (Client.GetPinCode() == PinCode))
            {
                MyFile.close();
                return Client;
            } 
        }
        MyFile.close();
    }
    
    return _GetEmptyClientObject();
}

static bool IsClientExist(string AccountNumber)
{
    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
    return (! (Client1.IsEmpty()));
}

enum enSaveResults{svFailedEmptyObject = 0, svSucceeded = 1, svFailedAccountNumberExists = 2};

enSaveResults Save()
{
    switch (_Mode)
    {
    case enMode::EmptyMode:
    {
        return enSaveResults::svFailedEmptyObject;
    }
    
    case enMode::UpdateMode:
    {
        _Update();
        return enSaveResults::svSucceeded;
    }
    
    case enMode::AddNewMode:
    {
        if (clsBankClient::IsClientExist(_AccountNumber))
        {
            return enSaveResults::svFailedAccountNumberExists;
        }
         
        else 
        {
            _AddNewClient();
            _Mode = enMode::UpdateMode;
            return clsBankClient::enSaveResults::svSucceeded;
        }
         
    }

    default:
        return enSaveResults::svFailedEmptyObject;
    }
}

static clsBankClient GetAddNewClientObject(string AccountNumber)
{
    return clsBankClient (enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0); 
}

bool Delete()
{
    vector<clsBankClient>_vClients = _LoadClientDataFromFile();

    for (clsBankClient& C : _vClients)
    {
        if (C.AccountNumber() == _AccountNumber)
        {
            C._MarkForDelete = true;
            break;
        }
             
    }
    
    _SaveClientDataToFile(_vClients);
    *this = _GetEmptyClientObject();
    return true;
}

static vector<clsBankClient>  GetClientsList()
{
    return _LoadClientDataFromFile();
}

static float GetTotalBalances()
{
    vector<clsBankClient>_vClients = clsBankClient:: _LoadClientDataFromFile();

    float TotalBalances = 0;
    
    for (clsBankClient& Client : _vClients)
    {
        TotalBalances += Client._AccountBalance;
    }
    
    return TotalBalances;
}

void Deposit (double Amount)
{
    _AccountBalance += Amount;
    Save();
}

bool Withdraw (double Amount)
{
    if (Amount > _AccountBalance)
    {
        return false;
    }
    
    else
    {
        _AccountBalance -= Amount;
        Save();
    }
    
    return true;
}

bool TransferAmount(float Amount, clsBankClient& DestinationClient)
{
    if (Amount > _AccountBalance)
    {
        return false;
    }

    else
    {
        Withdraw(Amount);
        DestinationClient.Deposit(Amount);
        return true;
    }   
}

};

class clsInputValidate 
{
public:
    static bool IsNumberBetween(int Number, int From, int To)
    {
        return (Number >= From) && (Number <= To);
    }
    
    static bool IsNumberBetween(double Number, double From, double To)
    {
        return (Number >= From) && (Number <= To);
    }

    static int ReadIntNumber(string ErrorMessage = "Invalid input, please enter an integer: ")
    {
        int Number;
        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return Number;
    }

    static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, enter again: ")
    {
        int Number = ReadIntNumber();
        
        while (!IsNumberBetween(Number, From, To))
        {
            cout << ErrorMessage;
            Number = ReadIntNumber();
        }
        return Number;
    }

    static double ReadDblNumber(string ErrorMessage = "Invalid input, please enter a number: ")
    {
        double Number;
        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return Number;
    }

    static float ReadFltNumber(string ErrorMessage = "Invalid input, please enter a number: ")
    {
       float Number;
        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return Number;
    }
    
    static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, enter again: ")
    {
        double Number = ReadDblNumber();
        
        while (!IsNumberBetween(Number, From, To))
        {
            cout << ErrorMessage;
            Number = ReadDblNumber();
        }
        return Number;
    }
    
    static string ReadString()
    {
        string S;
        getline(cin >> ws, S);
        return S;
    }
       
    
    
    
    
};

class clsUtil
{
   
public:

    static string EncryptText(string Text, short EncryptionKey = 2)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] + EncryptionKey);

        }

        return Text;

    }

    static string  DecryptText(string Text, short EncryptionKey = 2)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] - EncryptionKey);

        }
        return Text;

    }

};

void ReadClientInfo(clsBankClient& Client)
{
    cout << "\nEnter First Name: ";
    Client.SetFirstName(clsInputValidate::ReadString());
    cout << "\nEnter Last Name: ";
    Client.SetLastName(clsInputValidate::ReadString());
    cout << "\nEnter Email: ";
    Client.SetEmail(clsInputValidate::ReadString());
    cout << "\nEnter Phone: ";
    Client.SetPhone(clsInputValidate::ReadString());
    cout << "\nEnter PinCode: ";
    Client.SetPinCode(clsInputValidate::ReadString());
    cout << "\nEnter Account Balance: ";
    Client.SetAccountBalance(clsInputValidate::ReadFltNumber());
}

void UpdateClientData()
{
    cout << "Please, Enter Client Account Number: ";
    string AccountNumber = clsInputValidate::ReadString();
    while(! (clsBankClient::IsClientExist(AccountNumber)))
    {
        cout << "\nAccount Number is not found, choose another one: " ;
        AccountNumber = clsInputValidate::ReadString();
    }
    
    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
    Client1.Print();

    cout << "Update Client Info" << endl;
    cout << "-----------------------" << endl;
    ReadClientInfo(Client1);

    clsBankClient::enSaveResults SaveResult;
    SaveResult = Client1.Save();
    switch (SaveResult)
    {
    case clsBankClient::enSaveResults::svSucceeded:
    {
        cout << "Account Updated Successfully :-)" << endl;
        Client1.Print();
        break;
    }
    
    case clsBankClient::enSaveResults::svFailedEmptyObject:
    {
        cout << "Error Account was not saved because it's Empty." << endl;
        break;
    }

    default:
        break;
    }

    cout << "-----------------------" << endl;
}

void AddNewClient()
{
    cout << "Please, Enter Client Account Number: ";
    string AccountNumber = clsInputValidate::ReadString();

    while (clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount Number Is Already used, Choose antother one: ";
        AccountNumber = clsInputValidate::ReadString();
    }
    
    clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
    ReadClientInfo(NewClient);

    clsBankClient::enSaveResults SaveResult;
    SaveResult = NewClient.Save();
    
    switch (SaveResult)
    {
    case clsBankClient::enSaveResults::svSucceeded:
    {
        cout << "\nAccount Updated Successfully :-)" << endl;
        NewClient.Print();
        break;
    }

    case clsBankClient::enSaveResults::svFailedEmptyObject:
    {
        cout << "\nError Account was not saved because it's Empty." << endl;
        break;
    }

    case clsBankClient:: enSaveResults::svFailedAccountNumberExists:
    {
        cout << "\nError Account was not saved because it's Empty." << endl;
        break;
    }
    
    default:
        break;
    }

}

void DeleteClient()
{
    string AccountNumber = "";
    cout << "Please, Enter Client Account Number: ";
    AccountNumber = clsInputValidate::ReadString();

    while (!(clsBankClient::IsClientExist(AccountNumber)))
    {
        cout << "\nAccount Number is not found, choose another one: " ;
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
    Client1.Print();

    char Answer ='n';
    cout << "Are you sure do you want to delete this client y/n: ";
    cin >> Answer;

    if((Answer == 'Y') || (Answer == 'y'))
    {
       if (Client1.Delete())
       {
          cout << "\nClient Deleted Successfully:-)\n"; 
          Client1.Print();
       }
       
       else 
       {
          cout << "\nError Client was not deleted\n";
       }
    }
    
}

void PrintClientRecordLine(clsBankClient Client)
{
    cout << "| " << left << setw(15) << Client.AccountNumber();
    cout << "| " << left << setw(20) << Client.FullName();
    cout << "| " << left << setw(12) << Client.GetPhone();
    cout << "| " << left << setw(20) << Client.GetEmail();
    cout << "| " << left << setw(10) << Client.GetPinCode();
    cout << "| " << left << setw(12) << Client.GetAccountBalance(); 
}

void ShowClientsList()
{
    vector<clsBankClient>_vClients = clsBankClient::GetClientsList(); 

    cout << "\nClients List (" <<_vClients.size() <<") Clients: ";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "| " << setw(15) << left << "Account Number";
    cout << "| " << setw(20) << left << "Client Name";
    cout << "| " << setw(12) << left << "Phone";
    cout << "| " << setw(20) << left << "Email";
    cout << "| " << setw(10) << left << "Pin Code";
    cout << "| " << setw(12) << left << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    if (_vClients.size() == 0)
    {
        cout << "\t\t\t\tNo Clients available in the system!" << endl;
    }
    
    else 
    {
        for (clsBankClient& Client : _vClients)
        {
            PrintClientRecordLine(Client);
            cout << endl;
        }
    }
    
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

}

void PrintClientBalanceLine(clsBankClient Client)
{
    cout << "| " << left << setw(15) << Client.AccountNumber();
    cout << "| " << left << setw(40) << Client.FullName();
    cout << "| " << left << setw(12) << Client.GetAccountBalance(); 
}

void ShowTotalBalances()
{
    vector <clsBankClient>_vClients = clsBankClient::GetClientsList();

    cout << "\nClients List (" <<_vClients.size() <<") Clients: ";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "| " << setw(15) << left << "Account Number";
    cout << "| " << setw(40) << left << "Client Name";
    cout << "| " << setw(12) << left << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    for (clsBankClient& Client : _vClients)
    {
        PrintClientBalanceLine(Client);
        cout << endl;
    }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    
    float TotalBalances = clsBankClient::GetTotalBalances();
    cout << "Total Balances: " << TotalBalances << endl;
    cout << "("<< clsString::NumberToText(TotalBalances) <<")";
}

class clsUser : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enMode _Mode;
    string _UserName;
    string _Password;
    int _Permissions;

    bool _MarkedForDelete = false;
    
    static clsUser _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
    {
        vector<string> vUserData;
        vUserData = clsString::Split(Line, Seperator);

        return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
            vUserData[3], vUserData[4],clsUtil::DecryptText(vUserData[5]), stoi(vUserData[6]));

    }

    static string _ConverUserObjectToLine(clsUser User, string Seperator = "#//#")
    {

        string UserRecord = "";
        UserRecord += User.GetFirstName() + Seperator;
        UserRecord += User.GetLastName() + Seperator;
        UserRecord += User.GetEmail() + Seperator;
        UserRecord += User.GetPhone()+ Seperator;
        UserRecord += User.GetUserName() + Seperator;
        UserRecord += clsUtil::EncryptText(User.GetPassword()) + Seperator;
        UserRecord += to_string(User.GetPermissions());

        return UserRecord;

    }

    static  vector <clsUser> _LoadUsersDataFromFile()
    {

        vector <clsUser> vUsers;

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                vUsers.push_back(User);
            }

            MyFile.close();

        }

        return vUsers;

    }
    
    static void _SaveUsersDataToFile(vector <clsUser> vUsers)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsUser U : vUsers)
            {
                if (U.MarkedForDeleted() == false)
                {  
                    DataLine = _ConverUserObjectToLine(U);
                    MyFile << DataLine << endl;

                }

            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.GetUserName() == _UserName)
            {
                U = *this;
                break;
            }

        }

        _SaveUsersDataToFile(_vUsers);

    }

    void _AddNew()
    {

        _AddDataLineToFile(_ConverUserObjectToLine(*this));
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }
    
    string _PrepareLogInRecord(string Separator = "#//#")
    {
        string RegisterRecord = "";
        RegisterRecord += clsDate::GetSystemDateTimeString() + Separator;
        RegisterRecord += _UserName + Separator;
        RegisterRecord += clsUtil::EncryptText(_Password) + Separator;
        RegisterRecord += to_string(_Permissions);
        return RegisterRecord;
    }

public:
    
    enum enPermissions { enAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4, 
        pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64, pShowLogInRegister = 128};
    
    struct stLoginRegisterRecord
    {
       string DateTime;
       string UserName;
       string Password;
       int Permissions;
    };

    clsUser(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string UserName, string Password,
        int Permissions) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _UserName = UserName;
        _Password = Password;
        _Permissions = Permissions;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }

    string GetUserName()
    {
        return _UserName;
    }

    void SetUserName(string UserName)
    {
        _UserName = UserName;
    }

    void SetPassword(string Password)
    {
        _Password = Password;
    }

    string GetPassword()
    {
        return _Password;
    }

    void SetPermissions(int Permissions)
    {
        _Permissions = Permissions;
    }

    int GetPermissions()
    {
        return _Permissions;
    } 

    string FullName()
    {
        return GetFirstName() + " " + GetLastName();
    }    

    static clsUser Find(string UserName)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                if (User.GetUserName() == UserName)
                {
                    MyFile.close();
                    return User;
                }
            }

            MyFile.close();

        }

        return _GetEmptyUserObject();
    }

    static clsUser Find(string UserName, string Password)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                if (User.GetUserName() == UserName && User.GetPassword() == Password)
                {
                    MyFile.close();
                    return User;
                }
            }
            MyFile.close();
        }
        return _GetEmptyUserObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };

    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {
                return enSaveResults::svFaildEmptyObject;
            }
        }

        case enMode::UpdateMode:
        {
            _Update();
            return enSaveResults::svSucceeded;

            break;
        }

        case enMode::AddNewMode:
        {
            //This will add new record to file or database
            if (clsUser::IsUserExist(_UserName))
            {
                return enSaveResults::svFaildUserExists;
            }
            else
            {
                _AddNew();
                //We need to set the mode to update after add new
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }

            break;
        }

        default:
            break;
        }

    }

    static bool IsUserExist(string UserName)
    {

        clsUser User = clsUser::Find(UserName);
        return (!User.IsEmpty());
    }

    bool Delete()
    {
        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.GetUserName() == _UserName)
            {
                U._MarkedForDelete = true;
                break;
            }

        }

        _SaveUsersDataToFile(_vUsers);

        *this = _GetEmptyUserObject();

        return true;

    }

    static clsUser GetAddNewUserObject(string UserName)
    {
        return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
    }

    static vector <clsUser> GetUsersList()
    {
        return _LoadUsersDataFromFile();
    }
    
    bool CheckAccessPermission(enPermissions Permission)
    {
        if (this->_Permissions == enPermissions::enAll)
            return true;

        if ((Permission & this->_Permissions) == Permission)
            return true;
        else
            return false;

    }
   
    void RegisterLogIn()
    {
        string stDataLine = _PrepareLogInRecord();
        fstream MyFile;
        MyFile.open("Login Register.txt", ios:: out | ios:: app); 

        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl;
            MyFile.close();
        }    
    }
    
    static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line, string Seperator = "#//#")
    {
        stLoginRegisterRecord LoginRegisterRecord;
        vector <string> LoginRegisterDataLine = clsString::Split(Line, Seperator);
        LoginRegisterRecord.DateTime = LoginRegisterDataLine[0];
        LoginRegisterRecord.UserName = LoginRegisterDataLine[1];
        LoginRegisterRecord.Password = clsUtil::DecryptText(LoginRegisterDataLine[2]);
        LoginRegisterRecord.Permissions = stoi(LoginRegisterDataLine[3]);

        return LoginRegisterRecord;

    }

    static vector <stLoginRegisterRecord> GetUsersLogInRegisterList()
    {
      
        vector<stLoginRegisterRecord> vUsersLogIn; 
        fstream MyFile;
        MyFile.open("Login Register.txt", ios:: in);
        if (MyFile.is_open())
        {
            string Line;
            stLoginRegisterRecord Record;
            while (getline(MyFile, Line))
            {
                Record =  _ConvertLoginRegisterLineToRecord(Line);
                vUsersLogIn.push_back(Record);
            }
           
            MyFile.close();
        }
        
        return vUsersLogIn;
    }
    
};

clsUser CurrentUser = clsUser::Find("", "");

class clsScreen
{
protected:
   
   static void _DrawScreenHeader(string Title, string SubTitle = "")
   {
        cout << "\t\t\t\t\t===========================================";
        cout << "\n\n\t\t\t\t\t  " << Title;

        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        
        cout << "\t\t\t\t\t===========================================";
        cout << "\n\t\t\t\t\t\t User: " << CurrentUser.GetUserName() << "\n";
        cout << "\n\t\t\t\t\t\t Date: " << clsDate::DateToString(clsDate()) << "\n\n";
   }

   static bool CheckAccessRights(clsUser::enPermissions Permission)
   {
        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t======================================";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";   
            cout << "\n\t\t\t\t\t======================================\n\n";
            return false;
        }
        
        else
        {
           return true;
        }
        
   }
   

};

class clsClientListScreen : protected clsScreen
{
private:

    static void PrintClientRecordLine(clsBankClient Client)
    {
        cout << setw(8) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(20) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.GetPhone();
        cout << "| " << setw(20) << left << Client.GetEmail();
        cout << "| " << setw(10) << left << Client.GetPinCode();
        cout << "| " << setw(12) << left << Client.GetAccountBalance();
    }

public:
    
    static void ShowClientsList()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pListClients))
        {
            return;
        }
        
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();
        string Title = "\t  Client List Screen";
        string SubTitle ="\t    (" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);
        

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout <<  setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";

        else

            for (clsBankClient Client : vClients)
            {

                PrintClientRecordLine(Client);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};

class clsAddNewClientScreen : protected clsScreen
{
private:
    static  void _ReadClientInfo(clsBankClient& Client)
    {
    cout << "\nEnter First Name: ";
    Client.SetFirstName(clsInputValidate::ReadString());
    cout << "\nEnter Last Name: ";
    Client.SetLastName(clsInputValidate::ReadString());
    cout << "\nEnter Email: ";
    Client.SetEmail(clsInputValidate::ReadString());
    cout << "\nEnter Phone: ";
    Client.SetPhone(clsInputValidate::ReadString());
    cout << "\nEnter PinCode: ";
    Client.SetPinCode(clsInputValidate::ReadString());
    cout << "\nEnter Account Balance: ";
    Client.SetAccountBalance(clsInputValidate::ReadFltNumber());
   } 

    static  void _PrintClient(clsBankClient Client)
    {
    cout << endl << "Client Card" << endl;
    cout << "-----------------------" << endl;
    cout << "First Name  : " << Client.GetFirstName()<< endl;
    cout << "Last Name   : " << Client.GetLastName() << endl;
    cout << "FullName    : " << Client.FullName() << endl;
    cout << "Email       : " << Client.GetEmail() << endl;
    cout << "Phone       : " << Client.GetPhone() << endl;
    cout << "Acc. Number : " << Client.AccountNumber() << endl;
    cout << "Password    : " << Client.GetPinCode() << endl;
    cout << "Balance     : " << Client.GetAccountBalance() << endl;
    cout << "-----------------------" << endl;
    }

public:

    static void ShowAddNewClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
        {
            return;
        }
        _DrawScreenHeader("\t  Add New Client Screen");
        vector<clsBankClient>_vClients;

        string AccountNumber ="";
        cout << "Please, Enter Client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number Is Already used, Choose antother one: ";
            AccountNumber = clsInputValidate::ReadString();   
        }
        
        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResult;
        SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResults::svSucceeded:
        {
        cout << "\nAccount Updated Successfully :-)" << endl;
        _PrintClient(NewClient);
        break;
        }

        case clsBankClient::enSaveResults::svFailedEmptyObject:
        {
            cout << "\nError Account was not saved because it's Empty." << endl;
            break;
        }

        case clsBankClient:: enSaveResults::svFailedAccountNumberExists:
        {
            cout << "\nError Account was not saved because it's Empty." << endl;
            break;
        }
    
        default:
               break;
        }
    }
    
};

class clsDeleteClientScreen : protected clsScreen
{
private:
    static  void _PrintClient(clsBankClient Client)
    {
    cout << endl << "Client Card" << endl;
    cout << "-----------------------" << endl;
    cout << "First Name  : " << Client.GetFirstName()<< endl;
    cout << "Last Name   : " << Client.GetLastName() << endl;
    cout << "FullName    : " << Client.FullName() << endl;
    cout << "Email       : " << Client.GetEmail() << endl;
    cout << "Phone       : " << Client.GetPhone() << endl;
    cout << "Acc. Number : " << Client.AccountNumber() << endl;
    cout << "Password    : " << Client.GetPinCode() << endl;
    cout << "Balance     : " << Client.GetAccountBalance() << endl;
    cout << "-----------------------" << endl;
    }

public:
    
    static void ShowDeleteClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
        {
            return;
        }
        _DrawScreenHeader("\t  Delete Client Screen");
        string AccountNumber = "";
        cout << "Please, Enter Client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!(clsBankClient::IsClientExist(AccountNumber)))
        {
            cout << "\nAccount Number is not found, choose another one: " ;
            AccountNumber = clsInputValidate::ReadString();
        }
        
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        char Answer ='n';
        cout << "Are you sure do you want to delete this client y/n: ";
        cin >> Answer;
   
        if (toupper(Answer) == 'Y')
        {
          
           if (Client1.Delete())
           {
               cout << "\nClient Deleted Successfully:-)\n"; 
               Client1.Print();
           }
       
           else 
           {
               cout << "\nError Client was not deleted\n";
           }
           
        }
        

    }
    
};

class clsUpdateClientScreen : protected clsScreen
{
private:
    static  void _ReadClientInfo(clsBankClient& Client)
    {
    cout << "\nEnter First Name: ";
    Client.SetFirstName(clsInputValidate::ReadString());
    cout << "\nEnter Last Name: ";
    Client.SetLastName(clsInputValidate::ReadString());
    cout << "\nEnter Email: ";
    Client.SetEmail(clsInputValidate::ReadString());
    cout << "\nEnter Phone: ";
    Client.SetPhone(clsInputValidate::ReadString());
    cout << "\nEnter PinCode: ";
    Client.SetPinCode(clsInputValidate::ReadString());
    cout << "\nEnter Account Balance: ";
    Client.SetAccountBalance(clsInputValidate::ReadFltNumber());
   } 

    static  void _PrintClient(clsBankClient Client)
    {
    cout << endl << "Client Card" << endl;
    cout << "-----------------------" << endl;
    cout << "First Name  : " << Client.GetFirstName()<< endl;
    cout << "Last Name   : " << Client.GetLastName() << endl;
    cout << "FullName    : " << Client.FullName() << endl;
    cout << "Email       : " << Client.GetEmail() << endl;
    cout << "Phone       : " << Client.GetPhone() << endl;
    cout << "Acc. Number : " << Client.AccountNumber() << endl;
    cout << "Password    : " << Client.GetPinCode() << endl;
    cout << "Balance     : " << Client.GetAccountBalance() << endl;
    cout << "-----------------------" << endl;
    }

public:

    static void ShowUpdateClientScreen()
    { 
        if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
        {
            return;
        }
        _DrawScreenHeader("\t  Update Client Screen");
        string AccountNumber = "";
        cout << "Please, Enter Client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
    
       while (!(clsBankClient::IsClientExist(AccountNumber)))
       {
            cout << "\nAccount Number is not found, choose another one: " ;
            AccountNumber = clsInputValidate::ReadString(); 
       }

       clsBankClient Client1 = clsBankClient::Find(AccountNumber);
       _PrintClient(Client1);

        char Answer ='n';
        cout << "Are you sure do you want to delete this client y/n: ";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            cout << "Update Client Info" << endl;
            cout << "-----------------------" << endl;
            ReadClientInfo(Client1);
    
           clsBankClient::enSaveResults SaveResult;
           SaveResult = Client1.Save();
           switch (SaveResult)
           {
           case clsBankClient::enSaveResults::svSucceeded:
           {
                cout << "Account Updated Successfully :-)" << endl;
                _PrintClient(Client1);
                break;
           }
    
           case clsBankClient::enSaveResults::svFailedEmptyObject:
           {
                cout << "Error Account was not saved because it's Empty." << endl;
                break;
           }

           default:
           break;
           }
        }
    }
       
};

class clsFindClientScreen : protected clsScreen
{
private:
    static  void _PrintClient(clsBankClient Client)
    {
    cout << endl << "Client Card" << endl;
    cout << "-----------------------" << endl;
    cout << "First Name  : " << Client.GetFirstName()<< endl;
    cout << "Last Name   : " << Client.GetLastName() << endl;
    cout << "FullName    : " << Client.FullName() << endl;
    cout << "Email       : " << Client.GetEmail() << endl;
    cout << "Phone       : " << Client.GetPhone() << endl;
    cout << "Acc. Number : " << Client.AccountNumber() << endl;
    cout << "Password    : " << Client.GetPinCode() << endl;
    cout << "Balance     : " << Client.GetAccountBalance() << endl;
    cout << "-----------------------" << endl;
    }
    
public:
     
   static void ShowFindClientScreen()
   {
        if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
        {
            return;
        }
        _DrawScreenHeader("\t  Update Client Screen");
        string AccountNumber = "";
        cout << "Please, Enter Client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
    
       while (!(clsBankClient::IsClientExist(AccountNumber)))
       {
            cout << "\nAccount Number is not found, choose another one: " ;
            AccountNumber = clsInputValidate::ReadString(); 
       }
       
       clsBankClient Client1 = clsBankClient::Find(AccountNumber);

       if (!Client1.IsEmpty())
          cout << "\nClient Found :-)\n";
       else
           cout << "\nClient was NOT Found :-(\n"; 
       _PrintClient(Client1);

   }
   
};

class clsDepositScreen : protected clsScreen
{

private:
    
    static  void _PrintClient(clsBankClient Client)
    {
    cout << endl << "Client Card" << endl;
    cout << "-----------------------" << endl;
    cout << "First Name  : " << Client.GetFirstName()<< endl;
    cout << "Last Name   : " << Client.GetLastName() << endl;
    cout << "FullName    : " << Client.FullName() << endl;
    cout << "Email       : " << Client.GetEmail() << endl;
    cout << "Phone       : " << Client.GetPhone() << endl;
    cout << "Acc. Number : " << Client.AccountNumber() << endl;
    cout << "Password    : " << Client.GetPinCode() << endl;
    cout << "Balance     : " << Client.GetAccountBalance() << endl;
    cout << "-----------------------" << endl;
    }

    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nPlease enter AccountNumber? ";
        cin >> AccountNumber;
        return AccountNumber;
    }

public:

    static void ShowDepositScreen()
    {
        _DrawScreenHeader("\t   Deposit Screen");

        string AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        double Amount = 0;
        cout << "\nPlease enter deposit amount? ";
        Amount = clsInputValidate::ReadDblNumber();

        cout << "\nAre you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            Client1.Deposit(Amount);
            cout << "\nAmount Deposited Successfully.\n";
            cout << "\nNew Balance Is: " << Client1.GetAccountBalance();
        }

        else
        {
            cout << "\nOperation was cancelled.\n";
        }

    }
};

class clsWithdrawScreen : protected clsScreen
{
private:
    
    static  void _PrintClient(clsBankClient Client)
    {
    cout << endl << "Client Card" << endl;
    cout << "-----------------------" << endl;
    cout << "First Name  : " << Client.GetFirstName()<< endl;
    cout << "Last Name   : " << Client.GetLastName() << endl;
    cout << "FullName    : " << Client.FullName() << endl;
    cout << "Email       : " << Client.GetEmail() << endl;
    cout << "Phone       : " << Client.GetPhone() << endl;
    cout << "Acc. Number : " << Client.AccountNumber() << endl;
    cout << "Password    : " << Client.GetPinCode() << endl;
    cout << "Balance     : " << Client.GetAccountBalance() << endl;
    cout << "-----------------------" << endl;
    }

    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nPlease enter AccountNumber? ";
        cin >> AccountNumber;
        return AccountNumber;
    }

public:

    static void ShowWithdrawScreen()
    {
        _DrawScreenHeader("\t   Withdraw Screen");

        string AccountNumber = _ReadAccountNumber();


        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);


        double Amount = 0;
        cout << "\nPlease enter Withdraw amount? ";
        Amount = clsInputValidate::ReadDblNumber();

        cout << "\nAre you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
           if( Client1.Withdraw(Amount))
           { 
            cout << "\nAmount Withdrew Successfully.\n";
            cout << "\nNew Balance Is: " << Client1.GetAccountBalance();
           }
           else
           {
               cout << "\nCannot withdraw, Insuffecient Balance!\n";
               cout << "\nAmout to withdraw is: " << Amount;
               cout << "\nYour Balance is: " << Client1.GetAccountBalance();
               
           }
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }

    }

};

class clsTotalBalancesScreen : protected clsScreen
{

private:

    static void _PrintClientRecordBalanceLine(clsBankClient Client)
    {
        cout << setw(25) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(40) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.GetAccountBalance();
    }

public:

    static void ShowTotalBalances()
    {

        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        string Title = "\t  Balances List Screen";
        string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;

        cout << setw(25) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(25) << left << "" << "\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;

        double TotalBalances = clsBankClient::GetTotalBalances();

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient Client : vClients)
            {
                _PrintClientRecordBalanceLine(Client);
                cout << endl;
            }

        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;
        
        cout << setw(8) << left << "" << "\t\t\t\t\t\t\t     Total Balances = " << TotalBalances << endl;
        cout << setw(8) << left << "" << "\t\t\t\t  ( " << clsString::NumberToText(TotalBalances) << ")";
    }

};

class clsTransferScreen : protected clsScreen
{
private:
    static  void _PrintClient(clsBankClient Client)
    {
    cout << endl << "Client Card" << endl;
    cout << "-----------------------" << endl;
    cout << "FullName    : " << Client.FullName() << endl;
    cout << "Acc. Number : " << Client.AccountNumber() << endl;
    cout << "Balance     : " << Client.GetAccountBalance() << endl;
    cout << "-----------------------" << endl;
    }

    static string _ReadAccountNumber(string Message) 
    {
        string AccountNumber = "";
        cout << Message;
        cin >> AccountNumber;

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "Account Number does NOT exist" << endl;
            cout << Message;
            cin >> AccountNumber; 
        }

        return AccountNumber;
    }

    static float _ReadAmount(clsBankClient Client1)
    {
        float Amount = 0;
        cout << "Enter Transfer Amount? ";
        Amount = clsInputValidate::ReadDblNumber();
        if (Amount > Client1.GetAccountBalance())
        {
            do
            {
                cout << "Amount Exceeds the available Balance, Enter another Amount? ";
                Amount = clsInputValidate::ReadDblNumber();
            } while (Amount > Client1.GetAccountBalance());
        }

        return Amount;
    }
    
    static string _PrepareTransferLogRecord(clsBankClient SourceClinet, clsBankClient DestinationClinet,
        float TransferAmount, string Separator = "#//#")
    {
        string TransferRecordLine;
        TransferRecordLine += clsDate::GetSystemDateTimeString() + Separator;
        TransferRecordLine += SourceClinet.AccountNumber() + Separator;
        TransferRecordLine += DestinationClinet.AccountNumber() + Separator;
        TransferRecordLine += to_string(TransferAmount) + Separator;
        TransferRecordLine += to_string(SourceClinet.GetAccountBalance()) + Separator;
        TransferRecordLine += to_string(DestinationClinet.GetAccountBalance()) + Separator;
        TransferRecordLine += CurrentUser.GetUserName();

        return TransferRecordLine;
    }

    static void _RegisterTransferLog(clsBankClient SourceClinet, clsBankClient DestinationClinet,
        float TransferAmount, string Separator = "#//#")
    {
        string DataLine = _PrepareTransferLogRecord(SourceClinet, DestinationClinet, TransferAmount, Separator);
        fstream MyFile;
        MyFile.open("TransferLog.txt", ios::out | ios::app);
        if (MyFile.is_open())
        {
            MyFile << DataLine << endl;
            MyFile.close();
        }
    }
    
public:
        
    static void ShowTransferScreen()
    {
        _DrawScreenHeader("\t  Balances List Screen", "");
       
        clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber("Please Enter Account Number to Transfer From: "));
        _PrintClient(SourceClient);

        clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("Please Enter Account Number to Transfer To: "));
        _PrintClient(DestinationClient);
     
        float TransferAmount = _ReadAmount(SourceClient);
        
        char Answer = 'Y';
        cout << "Are you sure You want to perform this operation? y/n? ";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            if (SourceClient.TransferAmount(TransferAmount, DestinationClient))
            {
                cout << "Transfer done successfully :-)" << endl;
                _RegisterTransferLog(SourceClient, DestinationClient, TransferAmount);
            }    
            
            else
            {
                cout << "Transfer Failed :-(" << endl;        
            }
        }

        _PrintClient(SourceClient);
        _PrintClient(DestinationClient);
    }
};

class clsTransferLogScreen : protected clsScreen
{
private:
    struct stTransferLogRecord
    {
        string DateTime;
        string SourceAccountNumber;
        string DestinationAccountNumber;
        float Amount;
        float srcBalanceAfter;
        float destBalanceAfter;
        string UserName;
    };
    
    static void _PrintTransferLogRecordLine(stTransferLogRecord TransferLogRecord)
    {
        cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLogRecord.DateTime;
        cout << "| " << setw(8) << left << TransferLogRecord.SourceAccountNumber;
        cout << "| " << setw(8) << left << TransferLogRecord.DestinationAccountNumber;
        cout << "| " << setw(8) << left << TransferLogRecord.Amount;
        cout << "| " << setw(10) << left << TransferLogRecord.srcBalanceAfter;
        cout << "| " << setw(10) << left << TransferLogRecord.destBalanceAfter;
        cout << "| " << setw(8) << left << TransferLogRecord.UserName;
    }
    
    static stTransferLogRecord _PrepareTransferLogRecord(string Line, string Separator = "#//#")
    {
        vector<string>TransferLogData = clsString::Split(Line, Separator);
        stTransferLogRecord TransferLogRecord;
        TransferLogRecord.DateTime = TransferLogData[0];
        TransferLogRecord.SourceAccountNumber = TransferLogData[1];
        TransferLogRecord.DestinationAccountNumber = TransferLogData[2];
        TransferLogRecord.Amount = stof(TransferLogData[3]);
        TransferLogRecord.srcBalanceAfter = stof(TransferLogData[4]);
        TransferLogRecord.destBalanceAfter = stof(TransferLogData[5]);
        TransferLogRecord.UserName = TransferLogData[6]; 
        return TransferLogRecord;
    }

    static vector<stTransferLogRecord>_GetTransferLogRecord()
    {
        vector<stTransferLogRecord>vTransferLogRecord;
        fstream MyFile;
        MyFile.open("TransferLog.txt", ios::in);
        if (MyFile.is_open())
        {
           string Line;
           stTransferLogRecord TransferLogRecord;
           while (getline(MyFile, Line))
           {
                TransferLogRecord = _PrepareTransferLogRecord(Line);
                vTransferLogRecord.push_back(TransferLogRecord);  
           }  
        }
        
        return vTransferLogRecord;
    }

public:   
    static void ShowTransferLogScreen()
    {   
        vector<stTransferLogRecord>vTransferLogRecord = _GetTransferLogRecord();
        string Title = "\t  Transfer Log List Screen";
        string SubTitle ="\t    (" + to_string(vTransferLogRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);
        

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout <<  setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransferLogRecord.size() == 0)
            cout << "\t\t\t\tNo Transfer Logs Available In the System!";

        else

            for (stTransferLogRecord TransferLogRecord : vTransferLogRecord)
            {
                _PrintTransferLogRecordLine(TransferLogRecord);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }   

};

class clsTransactionsScreen : protected clsScreen
{
private:
    enum enTransactionsMenueOptions {
        eDeposit = 1, eWithdraw = 2,
        eShowTotalBalance = 3, eTransfer = 4, eTransferLog = 5,eShowMainMenue = 6
    };
    
    static void _GoBackToTransactionsMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        ShowTransactionsMenue();
    }

    static int _ReadTransactionsMenueOption()
    {
        cout <<setw(37) << left << ""<< "Choose what do you want to do? [1 to 6]? ";
        int Choice = clsInputValidate::ReadIntNumberBetween(1,6,"Enter Number between 1 to 6? ");
        return Choice;
    }
     
    static void _ShowDepositScreen()
    {
        clsDepositScreen::ShowDepositScreen();
    }
    
    static void _ShowWithdrawScreen()
    {
        clsWithdrawScreen::ShowWithdrawScreen();  
    }

    static void _ShowTotalBalancesScreen()
    {
        clsTotalBalancesScreen::ShowTotalBalances(); 
    }

    static void _ShowTransferScreen()
    {
        clsTransferScreen::ShowTransferScreen(); 
    }

    static void _ShowTransferLogScreen()
    {
        clsTransferLogScreen::ShowTransferLogScreen(); 
    }

    static void _PerformTransactionsMenueOption(enTransactionsMenueOptions Choice)
    {
        switch (Choice)
        {
        case enTransactionsMenueOptions::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        
        case enTransactionsMenueOptions::eWithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        
        case enTransactionsMenueOptions::eShowTotalBalance:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        
        case enTransactionsMenueOptions::eTransfer:
        {
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eTransferLog:
        {
            system("cls");
            _ShowTransferLogScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eShowMainMenue:
        {        
            break;
        }
        
        default:
            break;
        }  
    }
    
public:

    static void ShowTransactionsMenue()
    {
        system("cls");
        if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
        {
            return;
        }
        _DrawScreenHeader("\t\tTransactions Main Screen");

            cout << setw(37) << left <<""<< "\n\n===========================================\n";
            cout << setw(37) << left << "" << "\t\t\tTransactions Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] Deposit.\n";
            cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
            cout << setw(37) << left << "" << "\t[3] TotalBalances.\n";
            cout << setw(37) << left << "" << "\t[4] Transfer.\n";
            cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
            cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
            cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenueOption((enTransactionsMenueOptions)_ReadTransactionsMenueOption());
    }
    
};

class clsListUsersScreen : protected clsScreen
{

private:
    static void _PrintUserRecordLine(clsUser User)
    {

        cout << setw(8) << left << "" << "| " << setw(12) << left << User.GetUserName();
        cout << "| " << setw(25) << left << User.FullName();
        cout << "| " << setw(12) << left << User.GetPhone();
        cout << "| " << setw(20) << left << User.GetEmail();
        cout << "| " << setw(10) << left << User.GetPassword();
        cout << "| " << setw(12) << left << User.GetPermissions();

    }

public:

    static void ShowUsersList()
    {
        
        vector <clsUser> vUsers = clsUser::GetUsersList();

        string Title = "\t  User List Screen";
        string SubTitle = "\t    (" + to_string(vUsers.size()) + ") User(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(12) << "UserName";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vUsers.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (clsUser User : vUsers)
            {

                _PrintUserRecordLine(User);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }

};

class clsAddNewUserScreen : protected clsScreen
{
private:

    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter FirstName: ";
        User.SetFirstName(clsInputValidate::ReadString());

        cout << "\nEnter LastName: ";
        User.SetLastName(clsInputValidate::ReadString());

        cout << "\nEnter Email: ";
        User.SetEmail(clsInputValidate::ReadString());

        cout << "\nEnter Phone: ";
        User.SetPhone(clsInputValidate::ReadString());

        cout << "\nEnter Password: ";
        User.SetPassword(clsInputValidate::ReadString());

        cout << "\nEnter Permission: ";
        User.SetPermissions(_ReadPermissionsToSet());
    }

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.GetFirstName();
        cout << "\nLastName    : " << User.GetLastName();
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.GetEmail();
        cout << "\nPhone       : " << User.GetPhone();
        cout << "\nUser Name   : " << User.GetUserName();
        cout << "\nPassword    : " << User.GetPassword();
        cout << "\nPermissions : " << User.GetPermissions();
        cout << "\n___________________\n";

    }

    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTranactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }

        cout << "\nRegister Login? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pShowLogInRegister;
        }

        return Permissions;

    }

public:

    static void ShowAddNewUserScreen()
    {
        
        _DrawScreenHeader("\t  Add New User Screen");

        string UserName = "";

        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();
        while (clsUser::IsUserExist(UserName))
        {
            cout << "\nUserName Is Already Used, Choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

        _ReadUserInfo(NewUser);

        clsUser::enSaveResults SaveResult;

        SaveResult = NewUser.Save();

        switch (SaveResult)
        {
        case  clsUser::enSaveResults::svSucceeded:
        {
            cout << "\nUser Addeded Successfully :-)\n";
            _PrintUser(NewUser);
            break;
        }
        case clsUser::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError User was not saved because it's Empty";
            break;

        }
        case clsUser::enSaveResults::svFaildUserExists:
        {
            cout << "\nError User was not saved because UserName is used!\n";
            break;

        }
        }
    }
};

class clsDeleteUserScreen : protected clsScreen
{

private:
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.GetFirstName();
        cout << "\nLastName    : " << User.GetLastName();
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.GetEmail();
        cout << "\nPhone       : " << User.GetPhone();
        cout << "\nUser Name   : " << User.GetUserName();
        cout << "\nPassword    : " << User.GetPassword();
        cout << "\nPermissions : " << User.GetPermissions();
        cout << "\n___________________\n";

    }

public:
    static void ShowDeleteUserScreen()
    {
        _DrawScreenHeader("\tDelete User Screen");

        string UserName = "";

        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(UserName);
        _PrintUser(User1);

        cout << "\nAre you sure you want to delete this User y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            if (User1.Delete())
            {
                cout << "\nUser Deleted Successfully :-)\n";
                _PrintUser(User1);
            }
            else
            {
                cout << "\nError User Was not Deleted\n";
            }
        }
    }

};

class clsUpdateUserScreen :protected clsScreen
{
private:
    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter FirstName: ";
        User.SetFirstName(clsInputValidate::ReadString());

        cout << "\nEnter LastName: ";
        User.SetLastName(clsInputValidate::ReadString());

        cout << "\nEnter Email: ";
        User.SetEmail(clsInputValidate::ReadString());

        cout << "\nEnter Phone: ";
        User.SetPhone(clsInputValidate::ReadString());

        cout << "\nEnter Password: ";
        User.SetPassword(clsInputValidate::ReadString());

        cout << "\nEnter Permission: ";
        User.SetPermissions(_ReadPermissionsToSet());
    }

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.GetFirstName();
        cout << "\nLastName    : " << User.GetLastName();
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.GetEmail();
        cout << "\nPhone       : " << User.GetPhone();
        cout << "\nUser Name   : " << User.GetUserName();
        cout << "\nPassword    : " << User.GetPassword();
        cout << "\nPermissions : " << User.GetPermissions();
        cout << "\n___________________\n";

    }

    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTranactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }

        cout << "\nRegister Login? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pShowLogInRegister;
        }

        return Permissions;
    }

public:

    static void ShowUpdateUserScreen()
    {
        _DrawScreenHeader("\tUpdate User Screen");

        string UserName = "";

        cout << "\nPlease Enter User UserName: ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nAccount number is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(UserName);

        _PrintUser(User1);

        cout << "\nAre you sure you want to update this User y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate User Info:";
            cout << "\n____________________\n";


            _ReadUserInfo(User1);

            clsUser::enSaveResults SaveResult;

            SaveResult = User1.Save();

            switch (SaveResult)
            {
            case  clsUser::enSaveResults::svSucceeded:
            {
                cout << "\nUser Updated Successfully :-)\n";

                _PrintUser(User1);
                break;
            }
            case clsUser::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError User was not saved because it's Empty";
                break;

            }

            }

        }

    }
};

class clsFindUserScreen :protected clsScreen
{

private:
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.GetFirstName();
        cout << "\nLastName    : " << User.GetLastName();
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.GetEmail();
        cout << "\nPhone       : " << User.GetPhone();
        cout << "\nUser Name   : " << User.GetUserName();
        cout << "\nPassword    : " << User.GetPassword();
        cout << "\nPermissions : " << User.GetPermissions();
        cout << "\n___________________\n";

    }
public:

    static void ShowFindUserScreen()
    {
        _DrawScreenHeader("\t  Find User Screen");

        string UserName;
        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(UserName);

        if (!User1.IsEmpty())
        {
            cout << "\nUser Found :-)\n";
        }
        else
        {
            cout << "\nUser Was not Found :-(\n";
        }

        _PrintUser(User1);

    }

};

class clsManageUsersScreen :protected clsScreen
{

private:
    enum enManageUsersMenueOptions {
        eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
        eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
    };

    static short ReadManageUsersMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadIntNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static void _GoBackToManageUsersMenue()
    {
        cout << "\n\nPress any key to go back to Manage Users Menue...";
        system("pause>0");
        ShowManageUsersMenue();
    }

    static void _ShowListUsersScreen()
    {
        clsListUsersScreen::ShowUsersList();
    }

    static void _ShowAddNewUserScreen()
    {
        clsAddNewUserScreen::ShowAddNewUserScreen();

    }

    static void _ShowDeleteUserScreen()
    {
        clsDeleteUserScreen::ShowDeleteUserScreen();

    }

    static void _ShowUpdateUserScreen()
    {
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }

    static void _ShowFindUserScreen()
    {
        clsFindUserScreen::ShowFindUserScreen();
    }

    static void _PerformManageUsersMenueOption(enManageUsersMenueOptions ManageUsersMenueOption)
    {
       if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
       {
           return ;
       }

        switch (ManageUsersMenueOption)
        {
        case enManageUsersMenueOptions::eListUsers:
        {
            system("cls");
            _ShowListUsersScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eAddNewUser:
        {
            system("cls");
            _ShowAddNewUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eDeleteUser:
        {
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eUpdateUser:
        {
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eFindUser:
        {
            system("cls");

            _ShowFindUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
        }
        }

    }

public:


    static void ShowManageUsersMenue()
    {
        system("cls");
        if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
        {
            return;
        }
        _DrawScreenHeader("\t Manage Users Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformManageUsersMenueOption((enManageUsersMenueOptions)ReadManageUsersMenueOption());
    }

};

class clsLoginRegisterListScreen : protected clsScreen
{
private:
    static void _PrintUserLogInRegisterRecordLine(clsUser::stLoginRegisterRecord Record)
    {
        cout << setw(8) << left << "" << "| " << setw(35) << left << Record.DateTime;
        cout << "| " << setw(20) << left << Record.UserName;
        cout << "| " << setw(20) << left << Record.Password;
        cout << "| " << setw(10) << left << Record.Permissions;
    }

public:
    
    static void ShowLoginRegisterListScreen()
    {
       if (!CheckAccessRights(clsUser::enPermissions::pShowLogInRegister))
       {
           return ;
       }
       
        vector <clsUser::stLoginRegisterRecord> vUserLoginRegisterRecord = clsUser::GetUsersLogInRegisterList();
        string Title = "\t  Login Register List Screen";
        string SubTitle ="\t    (" + to_string(vUserLoginRegisterRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);
        

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout <<  setw(8) << left << "" << "| " << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vUserLoginRegisterRecord.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";

        else

            for (clsUser::stLoginRegisterRecord Record: vUserLoginRegisterRecord)
            {

                _PrintUserLogInRegisterRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }     
};

class clsCurrency 
{
private:
  enum enMode {EmptyMode = 0, UpdateMode = 1};

  enMode _Mode;
  string _Country;
  string _CurrencyName;
  string _CurrencyCode;
  float  _Rate;

static clsCurrency _ConvertLineToCurrencyObject(string Line, string Separator = "#//#")
{
    vector<string> vCurrencyData = clsString::Split(Line, Separator);
    return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], stof(vCurrencyData[3]));
}

static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Separator = "#//#")
{
    string stCurrencyRecord;
    stCurrencyRecord += Currency.Country() + Separator; 
    stCurrencyRecord += Currency.CurrencyName() + Separator;
    stCurrencyRecord += Currency.CurrencyCode() + Separator;
    stCurrencyRecord += to_string(Currency.Rate());

    return stCurrencyRecord;
}

static vector<clsCurrency> _LoadCurrencyDataFromFile()
{
    vector<clsCurrency> _vCurrencies;
    fstream MyFile;
    MyFile.open("Currencies.txt", ios::in);
    if (MyFile.is_open())
    {
        string Line;
        while (getline(MyFile,Line))
        {
            clsCurrency Currency = _ConvertLineToCurrencyObject(Line);  
            _vCurrencies.push_back(Currency);
        }
        
        MyFile.close();
    }
    
    return _vCurrencies;
}

static void _SaveCurrencyDataToFile(vector <clsCurrency> _vCurrencies)
{
    _vCurrencies  = _LoadCurrencyDataFromFile();
    fstream MyFile;
    MyFile.open("Currencies.txt", ios::out);
    if (MyFile.is_open())
    {
        string DataLine;
        for (clsCurrency& C : _vCurrencies)
        {
            DataLine = _ConvertCurrencyObjectToLine(C);
            MyFile << DataLine << endl; 
        }
          
        MyFile.close();
    }
}

void _Update()
{
    vector<clsCurrency> _vCurrencies = _LoadCurrencyDataFromFile();
    for (clsCurrency& C : _vCurrencies)
    {
        if (C.CurrencyCode() == CurrencyCode())
        {
            C = *this;
            break;
        }
    }
    _SaveCurrencyDataToFile(_vCurrencies);
}

static clsCurrency _GetEmptyCurrencyObject()
{
    return clsCurrency(enMode::EmptyMode, "", "", "", 0);
}

public:
   
   clsCurrency(enMode Mode, string Country, string CurrencyName, string CurrencyCode, float Rate)
   {
        _Mode = Mode;
        _Country = Country;
        _CurrencyCode = CurrencyCode;
        _CurrencyName = CurrencyName;
        _Rate = Rate;
   }
   
   static vector <clsCurrency> GetAllUSDRates()
   {
        return _LoadCurrencyDataFromFile(); 
   }
   
   bool IsEmpty()
   {
        return(_Mode == enMode::EmptyMode);
   }

   string Country() 
   {
       return _Country;
   }
   
   string CurrencyName() 
   {
       return _CurrencyName;
   }

   string CurrencyCode() 
   {
       return _CurrencyCode;
   }

   void UpdateRate(float NewRate)
   {
        _Rate = NewRate;
        _Update();
   }

   float Rate()
   {
        return _Rate;
   }

   static clsCurrency FindByCurrencyCode(string CurrencyCode)
   {
        CurrencyCode = clsString::UpperAllString(CurrencyCode);
        fstream MyFile;
        MyFile.open("Currencies.txt", ios::in);
        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
                if (Currency.CurrencyCode() == CurrencyCode)
                {
                    MyFile.close();
                    return Currency;
                }  
            }    
        }      
        return _GetEmptyCurrencyObject();                   
   }

   static clsCurrency FindByCountry(string Country)
   {
        Country = clsString::UpperAllString(Country);
        fstream MyFile;
        MyFile.open("Currencies.txt", ios::in);
        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
                if (clsString::UpperAllString(Currency.Country()) == Country)
                {
                    MyFile.close();
                    return Currency;
                }    
            } 
        }
        return _GetEmptyCurrencyObject();          
   }

   static bool IsCurrencyExist(string CurrencyCode)
   {
        clsCurrency C = clsCurrency::FindByCurrencyCode(CurrencyCode);
        return (!C.IsEmpty());
   }

  static vector <clsCurrency> GetCurrenciesList()
  {
        return _LoadCurrencyDataFromFile();
  }

  float ConvertInUSD(float Amount)
  {
        return Amount / Rate();
  }

  float ConvertToAnotherCurrency(float Amount, clsCurrency Currency2)
  {
       float AmountInUSD = ConvertInUSD(Amount);
       if (Currency2.CurrencyCode() == "USD")
       {
           return AmountInUSD;
       }

       return AmountInUSD * Currency2.Rate();   
  }
  
   
};

class clsListCurrenciesScreen : protected clsScreen
{
private:
    static void _PrintCurrencyRecordLine(clsCurrency Currency)
    {
        cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
        cout << "|" << left << setw(8) << Currency.CurrencyCode();
        cout << "|" << left << setw(45) << Currency.CurrencyName();
        cout << "|" << left << setw(10) << Currency.Rate() << endl;
    }
    
public:

   static void ShowListCurrenciesScreen()
   {
        vector<clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();

        string Title = "\t Currencies List Screen";
        string SubTitle = "\t   (" + to_string(vCurrencies.size()) + ") Currencies";
        _DrawScreenHeader(Title, SubTitle);
        
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;
        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "|" << left << setw(8) << "Code";
        cout << "|" << left << setw(45) << "Name";
        cout << "|" << left << setw(10) << "Rate/(1$)" << endl;
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;


        if (vCurrencies.size() == 0)
        {
           cout << "\t\t\t\tNo Currencies Available In The System!" << endl;
        }
        
        else 
        {
            for (clsCurrency& Currency : vCurrencies)
            {
                _PrintCurrencyRecordLine(Currency);
                cout << endl;
            }

            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "_______________________________________________\n" << endl;

        }  
   }
   
};

class clsFindCurrencyScreen : protected clsScreen
{
private:
    static void _PrintCurrencyCard(clsCurrency Currency)
    {
    cout << "\nCurrency Card:\n";
    cout << "_____________________________\n";
    cout << "\nCountry    : " << Currency.Country();
    cout << "\nCode       : " << Currency.CurrencyCode();
    cout << "\nName       : " << Currency.CurrencyName();
    cout << "\nRate(1$) = : " << Currency.Rate();
    cout << "\n_____________________________\n";
    }
    
    static int _ReadFindCurrencyMenueOption()
    {
        cout << setw(37) << left << "Find By: [1] Code or [2] Country ? ";
        int Choice = clsInputValidate::ReadIntNumberBetween(1,2,"");
        return Choice;
    }

    static string _ReadString(string Message)
    {
        string S1 = "";
        cout << Message;
        cin  >> S1;
        return S1;
    }
    
    static void _ShowResults(clsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
            cout << "Currency Found :-)" << endl;
            _PrintCurrencyCard(Currency);
        }    
        else 
        {
            cout << "Currency Was not Found :-(" << endl; 
        }
    }
    
public:
  
   static void ShowFindCurrencyScreen()
   {
        _DrawScreenHeader("Find Currency Screen", "");
        int Choice = _ReadFindCurrencyMenueOption();
       
        if (Choice == 1)
        {
            string CurrencyCode = _ReadString("Please Enter Currency Code: ");
            clsCurrency Currency1 = clsCurrency::FindByCurrencyCode(CurrencyCode);
            _ShowResults(Currency1);                
        }

        else if (Choice == 2)
        {
            string Country = _ReadString("Please Enter Country Name: ");
            clsCurrency Currency1 = clsCurrency::FindByCountry(Country);
            _ShowResults(Currency1);
        }
   }
   
};

class clsUpdateRateScreen : protected clsScreen
{
private:
    static void _PrintCurrencyCard(clsCurrency Currency)
    {
    cout << "\nCurrency Card:\n";
    cout << "_____________________________\n";
    cout << "\nCountry    : " << Currency.Country();
    cout << "\nCode       : " << Currency.CurrencyCode();
    cout << "\nName       : " << Currency.CurrencyName();
    cout << "\nRate(1$) = : " << Currency.Rate();
    cout << "\n_____________________________\n";
    }

    static float _ReadRate()
    {
        cout << "Enter New Rate: ";
        float NewRate = 0;
        NewRate = clsInputValidate::ReadFltNumber();
        return NewRate;
    }
    
public:
   static void ShowUpdateRate()
   {
        _DrawScreenHeader("\tUpdate Rate Screen", "");
        cout << "Please Enter Currency Code: ";
        string CurrencyCode = clsInputValidate::ReadString();
        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency is not found, choose another one: ";
            CurrencyCode = clsInputValidate::ReadString();
        }
        
        clsCurrency Currency1 = clsCurrency::FindByCurrencyCode(CurrencyCode);
        _PrintCurrencyCard(Currency1);

        cout << "Are you sure do you want to update the rate of this currency y/n? ";
        char Answer = 'Y';
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            cout << "\n\nUpdate Currency Rate:";
            cout << "\n____________________\n";
            Currency1.UpdateRate(_ReadRate());
            cout << "\nCurrency Rate Updated Successfully :-)\n";
            _PrintCurrencyCard(Currency1);
          

        }   
   }
   
};

class clsCurrencyCalculatorScreen : protected clsScreen
{
private:
    static void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card")
    {
    cout << Title;    
    cout << "\n_____________________________\n";
    cout << "\nCountry    : " << Currency.Country();
    cout << "\nCode       : " << Currency.CurrencyCode();
    cout << "\nName       : " << Currency.CurrencyName();
    cout << "\nRate(1$) = : " << Currency.Rate();
    cout << "\n_____________________________\n";
    }
   
    static float _ReadAmount()
    {
        cout << "\nEnter Amount to Exchange: ";
        float Amount = 0;
        Amount = clsInputValidate::ReadFltNumber();
        return Amount;
    }
    
    static clsCurrency _GetCurrency(string Message)
    {
        cout << Message;
        string CurrencyCode = clsInputValidate::ReadString();
        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency is not found, choose another one: ";
            CurrencyCode = clsInputValidate::ReadString();
        }    
        clsCurrency Currency = clsCurrency::FindByCurrencyCode(CurrencyCode);
  
        return Currency;
    }
    
    static void _PrintCalculationsResult(clsCurrency Currency1, clsCurrency Currency2, float Amount)
    {
        _PrintCurrencyCard(Currency1, "\nConvert From:");
        float AmountInUSD = Currency1.ConvertInUSD(Amount);
        cout << Amount << " " << Currency1.CurrencyCode() << " = " 
                 << AmountInUSD << " USD\n" << endl;
        if (Currency2.CurrencyCode() == "USD")
        {
           return;
        }

        cout << "\nConvert From USD to:\n";
        _PrintCurrencyCard(Currency2, "\nTo:");

        float AmountInCurrency2 = Currency1.ConvertToAnotherCurrency(Amount, Currency2);
        cout << Amount << " " << Currency1.CurrencyCode() << " = " 
                << AmountInCurrency2 << " " << Currency2.CurrencyCode() << endl;
         
    }
     
public:
   static void ShowCurrencyCalculatorScreen()
   { 
        char Answer = 'Y';
        do
        {
           system("cls");
           _DrawScreenHeader("Currency Calculator Screen", "");
           
           clsCurrency CurrencyFrom = _GetCurrency("\nPlease Enter Currency 1 Code: ");
           clsCurrency CurrencyTo   = _GetCurrency("\nPlease Enter Currency 2 Code: ");
          
           float Amount = _ReadAmount();
           _PrintCalculationsResult(CurrencyFrom, CurrencyTo,  Amount);

           cout << "\nDo you want to perform another calculation y/n? ";
           cin >> Answer;
        } while (toupper(Answer) == 'Y'); 
   }  
};

class clsCurrencyExchangeScreen : protected clsScreen
{
private:
    enum enCurrencyExchangeMenueOptions {
        eListCurrencies = 1, eFindCurrency = 2,
        eUpdateRate = 3, eCurrencyCalculator = 4, eShowMainMenue = 5
    };
    
    static void _GoBackToCurrencyExchangeMenue()
    {
        cout << "\n\nPress any key to go back to Currency Exchange Menue...";
        system("pause>0");
        ShowCurrencyExchangeMenue();
    }

    static int _ReadCurrencyExchangeMenueOption()
    {
        cout <<setw(37) << left << ""<< "Choose what do you want to do? [1 to 5]? ";
        int Choice = clsInputValidate::ReadIntNumberBetween(1,5,"Enter Number between 1 to 5? ");
        return Choice;
    }
     
    static void _ShowListCurrenciesScreen()
    {
        clsListCurrenciesScreen::ShowListCurrenciesScreen();
    }
    
    static void _ShowFindCurrencyScreen()
    {
        clsFindCurrencyScreen::ShowFindCurrencyScreen();  
    }

    static void _ShowUpdateRateScreen()
    {
        clsUpdateRateScreen::ShowUpdateRate(); 
    }

    static void _ShowCurrencyCalculatorScreen()
    {
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen(); 
    }

    static void _PerformCurrencyExchangeMenueOption(enCurrencyExchangeMenueOptions Choice)
    {
        switch (Choice)
        {
        case enCurrencyExchangeMenueOptions::eListCurrencies:
        {
            system("cls");
            _ShowListCurrenciesScreen();
            _GoBackToCurrencyExchangeMenue();
            break;
        }
        
        case enCurrencyExchangeMenueOptions::eFindCurrency:
        {
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrencyExchangeMenue();
            break;
        }
        
        case enCurrencyExchangeMenueOptions::eUpdateRate:
        {
            system("cls");
            _ShowUpdateRateScreen();
            _GoBackToCurrencyExchangeMenue();
            break;
        }
        
        case enCurrencyExchangeMenueOptions::eCurrencyCalculator:
        {
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrencyExchangeMenue();
            break;
        } 

        case enCurrencyExchangeMenueOptions::eShowMainMenue:
        {        
            break;
        }
        
        default:
            break;
        }  
    }
    
public:

    static void ShowCurrencyExchangeMenue()
    {
        system("cls");
       /* if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
        {
            return;
        }*/
        _DrawScreenHeader("\t\tCurrency Exchange Main Screen");

            cout << setw(37) << left <<""<< "\n\n===========================================\n";
            cout << setw(37) << left << "" << "\t\t\tCurrency Exchange Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
            cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
            cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
            cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
            cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
            cout << setw(37) << left << "" << "===========================================\n";

        _PerformCurrencyExchangeMenueOption((enCurrencyExchangeMenueOptions)_ReadCurrencyExchangeMenueOption());
    }
    
};

class clsMainScreen :protected clsScreen
{


private:
    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eLoginRegister = 8, eCurrencyExchange = 9, eExit = 10
    };

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "   Choose what do you want to do? [1 to 10]? ";
        short Choice = clsInputValidate::ReadIntNumberBetween(1, 10, "Enter Number between 1 to 10? ");
        return Choice;
    }

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
        clsClientListScreen::ShowClientsList();
    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::ShowAddNewClientScreen();
    }

    static void _ShowDeleteClientScreen()
    { 
        clsDeleteClientScreen::ShowDeleteClientScreen();
    }

    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::ShowUpdateClientScreen();
    }

    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::ShowFindClientScreen();
    }

    static void _ShowTransactionsMenue()
    { 
        clsTransactionsScreen::ShowTransactionsMenue();
    }

    static void _ShowManageUsersMenue()
    {   
        clsManageUsersScreen::ShowManageUsersMenue();
    }
    
    static void _ShowLoginRegisterListScreen()
    {
        clsLoginRegisterListScreen::ShowLoginRegisterListScreen();
    }
    
    static void _ShowCurrencyExchangeMenue()
    {
        clsCurrencyExchangeScreen::ShowCurrencyExchangeMenue();
    }
    

    static void _Logout()
    {     
        CurrentUser = clsUser::Find("", "");  
    }


    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eLoginRegister:
            system("cls");
            _ShowLoginRegisterListScreen();
            _GoBackToMainMenue();
            break;
        
        case enMainMenueOptions::eCurrencyExchange:
            system("cls");
            _ShowCurrencyExchangeMenue();
            _GoBackToMainMenue();
            break;


        case enMainMenueOptions::eExit:
            system("cls");
            _Logout();
            break;
        }

    }

public:

    static void ShowMainMenue()
    {

        system("cls");
        _DrawScreenHeader("\t\tMain Screen\n\n");

        cout << setw(37) << left << "" << "\n\t\t\t\t\t===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "\t===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Show Login Register List.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10]Logout.\n";
        cout << setw(37) << left << "" << "\t===========================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }

};

class clsLoginScreen : protected clsScreen
{
private:
    static bool _Login()
    {
        bool LoginFailed = false;
        string Username, Password;
        int LoginFailedCounter = 0;
        do
        {
            if (LoginFailed)
            {
                LoginFailedCounter++;
                cout << "\n\t\t\t\t\tInvalid Username/Password!" << endl;
                cout << "\n\t\t\t\t\tYou have " << (3-LoginFailedCounter) << " Trial(s) to login." << endl;
            }

            if (LoginFailedCounter == 3)
            {               
                cout << "\nYou are Locked after 3 Failed Trials." << endl;
                return false;
            }

            cout << "\n\t\t\t\t\tEnter Username: ";
            cin >> Username;

            cout << "\n\t\t\t\t\tEnter Password: ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);
            LoginFailed = CurrentUser.IsEmpty();
 
        } while (LoginFailed);
        
        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenue();
        return true;
             
    }
       
public:
   static bool ShowLoginScreen()
   {
        system("cls");
        _DrawScreenHeader("\t  Login Screen\n\n");
        return _Login();
   }
   
};

int main()
{
   while (true)
   {
        if (!clsLoginScreen::ShowLoginScreen())
        {
           break;
        }        
   }
   
    return 0;
}