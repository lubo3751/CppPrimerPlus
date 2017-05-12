// ex.10.04.namesp.h
namespace SALES
{
    class Sales
    {
    private:
        static const int QRTRS = 4;
        double sales[QRTRS];
        double average;
        double max;
        double min;
    public:
        Sales();
        Sales(const double ar[], int n);
        //void setSales(const double ar[], int n);
        void setSales();
        void showSales() const;
    };
}
