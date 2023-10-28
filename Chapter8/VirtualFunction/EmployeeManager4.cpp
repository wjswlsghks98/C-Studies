#include <iostream>
#include <cstring>
using namespace std;

class Employee
{
    private:
        char name[100];
    public:
        Employee(char * name)
        {
            strcpy(this->name, name);
        }
        void ShowYourName() const
        {
            cout << "name: " << name << endl;
        }
        // 순수 가상함수를 정의해서 함수의 몸체가 제대로 정의되지 않음을 명시. 
        // 단순 Employee로 정의하면 오류 뜨도록 !
        virtual int GetPay() const = 0;
        virtual void ShowSalaryInfo() const = 0;
};

class PermanentWorker : public Employee
{
    private:
        int salary;
    public:
        PermanentWorker(char *name, int money) : Employee(name), salary(money) {}
        int GetPay() const
        {
            return salary;
        }
        void ShowSalaryInfo() const
        {
            ShowYourName();
            cout << "salary: " << GetPay() << endl << endl;
        }
};

class TemporaryWorker : public Employee
{
    private:
        int workTime;
        int payPerHour;
    public: 
        TemporaryWorker(char *name, int pay) : Employee(name), workTime(0), payPerHour(pay) {}
        void AddWorkTime(int time)
        {
            workTime += time;
        }
        int GetPay() const
        {
            return workTime*payPerHour;
        }
        void ShowSalaryInfo() const
        {
            ShowYourName();
            cout << "salary: " << GetPay() << endl << endl;
        }
};

class SalesWorker : public PermanentWorker
{
    private:
        int salesResult;
        double bounsRatio;
    public:
        SalesWorker(char *name, int money, double ratio) : PermanentWorker(name, money), salesResult(0), bounsRatio(ratio) {}
        void AddSalesResult(int value)
        {
            salesResult += value;
        }
        int GetPay() const
        {
            return PermanentWorker::GetPay() + (int) (salesResult * bounsRatio);
        }
        void ShowSalaryInfo() const
        {
            ShowYourName();
            cout << "salary: " << GetPay() << endl << endl;
        }
};

class EmployeeHandler
{
    private:
        Employee* empList[50];
        int empNum;
    public:
        EmployeeHandler() : empNum(0) {}
        void AddEmployee(Employee* emp)
        {
            empList[empNum++] = emp;
        }
        void ShowAllSalaryInfo() const
        {
            for(int i=0;i<empNum; i++)
                empList[i]->ShowSalaryInfo();
        }
        void ShowTotalSalary() const
        {
            int sum = 0;
            for (int i=0; i<empNum; i++)
            {
                sum += empList[i]->GetPay();
            }
            cout << "salary sum: " << sum << endl;
        }
        ~EmployeeHandler()
        {
            for (int i=0; i< empNum; i++)
                delete empList[i];

        }
};

int main(void)
{
    EmployeeHandler handler;
    handler.AddEmployee(new PermanentWorker("KIM",1000));
    handler.AddEmployee(new PermanentWorker("LEE",1500));
    // handler.AddEmployee(new PermanentWorker("JUN",2000));
    // handler.ShowAllSalaryInfo();
    // handler.ShowTotalSalary();
    
    TemporaryWorker * alba = new TemporaryWorker("Jung",700);
    alba->AddWorkTime(5);
    handler.AddEmployee(alba);

    SalesWorker * seller = new SalesWorker("Hong", 1000, 0.1);
    seller->AddSalesResult(7000);
    handler.AddEmployee(seller);

    handler.ShowAllSalaryInfo();
    handler.ShowTotalSalary();

    return 0;
}