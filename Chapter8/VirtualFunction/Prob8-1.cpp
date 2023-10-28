#include <iostream>
#include <cstring>
using namespace std;

namespace RISK_LEVEL
{
    enum {RISK_A = 30, RISK_B=20, RISK_C=10};
}

class Employee
{
    private:
        char *name;
    public:
        Employee(char *name)
        {
            this->name = new char[strlen(name)+1];
            strcpy(this->name, name);

        }  
        void ShowYourName() const 
        {
            cout << "name: " << name << endl;
        }
        // virtual int GetPay() const = 0;
        // virtual void ShowSalaryInfo() const = 0;
         // 함수의 몸체가 정의되지 않기 때문에 Employee Class로 객체를 생성할 수 없다. 
         // 위의 함수를 순수 가상함수라고 부르고, 이렇게 순수 가상함수로 선언한 클래스를 추상 클래스라 한다. 
         virtual int GetPay() const { return 0; }
         virtual void ShowSalaryInfo() const {}
         ~Employee()
         {
            delete []name;
         }
};

class PermanentWorker : public Employee
{
    private:
        int salary;
    public:
        PermanentWorker(char *name, int money) : Employee(name), salary(money)
        { }
        virtual int GetPay() const {return salary;}
        virtual void ShowSalaryInfo() const 
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
        TemporaryWorker(char *name, int pay) : Employee(name), workTime(0), payPerHour(pay) { }
        void AddWorkTime(int time)
        {
            workTime += time;
        }
        virtual int GetPay() const
        {
            return workTime * payPerHour;
        }
        virtual void ShowSalaryInfo() const
        {
            ShowYourName();
            cout << "salary: " << GetPay() << endl << endl;
        }
};

class SalesWorker : public PermanentWorker
{
    private:
        int salesResult;
        double bonusRatio;
    public:
        SalesWorker(char *name, int money, double ratio) : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio) { }
        void AddSalesResult(int value)
        {
            salesResult += value;
        }
        virtual int GetPay() const
        {
            return PermanentWorker::GetPay() + (int) (salesResult * bonusRatio);
        }
        virtual void ShowSalaryInfo() const // 여기에서 overriding 하는 이유는 overriding 된 GetPay()를 사용하기 위함이다.
        {
            ShowYourName();
            cout << "salary: " << GetPay() << endl << endl;
        }
};

class ForeignSalesWorker : public SalesWorker
{
    private:
        const int riskLevel;
    public:
        ForeignSalesWorker(char *name, int money, double ratio, double risk) : SalesWorker(name, money, ratio), riskLevel(risk) { }
        int GetRiskPay() const
        {
            return (int) (SalesWorker::GetPay() * (riskLevel/100.0));
        }
        int GetPay() const 
        {
            return SalesWorker::GetPay() + GetRiskPay();
        }
        void ShowSalaryInfo() const 
        {
            ShowYourName();
            cout << "salary: " << SalesWorker::GetPay() << endl;
            cout << "risk pay: "  << GetRiskPay() << endl;
            cout << "sum: " << GetPay() << endl << endl;
        }
};

class EmployeeHandler
{
    private:
        Employee *empList[50];
        int empNum;
    public:
        EmployeeHandler() : empNum(0) 
        {}
        void AddEmployee(Employee *emp)
        {
            empList[empNum++] = emp; 
        }
        void ShowAllSalaryInfo() const 
        {
            for (int i=0;i<empNum;i++)
            {
                empList[i]->ShowSalaryInfo();
                // virtual 선언을 했기 때문에 pointer 변수가 실제로 가리키는 객체로 들어와서 함수를 실행한다. 
                // 객체 자료형은 모두 Employee이지만, 실제 포인터가 가리키는 객체는 모두 다르다. 
                // 그에 따라 실행되는 ShowSalaryInfo 함수가 달라지게 된다.
            }
            
        }
        void ShowTotalSalary() const 
        {
            int sum = 0;
            
            for (int i=0;i<empNum;i++)
            {
                sum += empList[i]->GetPay();
            }
            
           cout << "salary sum: " << sum << endl;
        }
        ~EmployeeHandler()
        {
            for (int i=0;i<empNum;i++)
            {
                delete empList[i];
            }
        }
};

int main(void)
{
    EmployeeHandler handler;
    // handler.AddEmployee(new PermanentWorker("KIM", 1000));
    // handler.AddEmployee(new PermanentWorker("LEE", 1500));
    // // handler.AddEmployee(new PermanentWorker("JUN", 2000));

    // TemporaryWorker *alba = new TemporaryWorker("JUNG", 700);
    // alba->AddWorkTime(5);
    // handler.AddEmployee(alba);

    // SalesWorker *seller = new SalesWorker("Hong", 1000, 0.1);
    // seller->AddSalesResult(7000);
    // handler.AddEmployee(seller);
    ForeignSalesWorker *fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
    fseller1->AddSalesResult(7000);
    handler.AddEmployee(fseller1);

    ForeignSalesWorker *fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
    fseller2->AddSalesResult(7000);
    handler.AddEmployee(fseller2);

    ForeignSalesWorker *fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
    fseller3->AddSalesResult(7000);
    handler.AddEmployee(fseller3);

    handler.ShowAllSalaryInfo();
    handler.ShowTotalSalary();
    return 0;
}