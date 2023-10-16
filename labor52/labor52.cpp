#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double lnTaylor(const double x, const double eps);
double lnMath(const double x);
double lnError(const double approx, const double actual);

int main() {
    double xp, xk, dx, eps;
    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "-------------------------------------------------------------" << endl;
    cout << "|" << setw(10) << "x" << " |"
        << setw(15) << "ln(x) (math)" << " |"
        << setw(15) << "ln(x) (approx)" << " |"
        << setw(15) << "ln(x) (error)" << " |" << endl;
    cout << "-------------------------------------------------------------" << endl;

    for (double x = xp; x <= xk; x += dx) {
        double lnActual = lnMath(x);
        double lnApprox = lnTaylor(x, eps);
        double lnErr = lnError(lnApprox, lnActual);

        cout << "|" << setw(10) << setprecision(2) << x << " |"
            << setw(15) << setprecision(8) << lnActual << " |"
            << setw(15) << setprecision(8) << lnApprox << " |"
            << setw(15) << setprecision(8) << lnErr << " |" << endl;
    }
    cout << "-------------------------------------------------------------" << endl;

    return 0;
}

double lnTaylor(const double x, const double eps) {
    double lnX = 0.0;
    double term = x - 1;
    double term_power = term;
    int n = 1;

    while (fabs(term) > eps) {
        lnX += term;
        term_power *= -term;
        term = term_power / (n + 1);
        n++;
    }

    return lnX;
}

double lnMath(const double x) {
    return log(x);
}

double lnError(const double approx, const double actual) {
    return fabs(approx - actual);
}
