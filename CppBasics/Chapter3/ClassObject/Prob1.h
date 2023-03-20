namespace CAL_FORMAT
{
    enum
    {
        ADD, SUB, MUL, DIV
    };
}

class Calculator
{
    private:
        int counter[4];
    public:
        void Init();
        double Add(double num1, double num2);
        double Min(double num1, double num2);
        double Mul(double num1, double num2);
        double Div(double num1, double num2);
        void ShowOpCount();
};