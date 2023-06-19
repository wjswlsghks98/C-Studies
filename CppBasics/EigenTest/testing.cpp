#include <iostream>
#include <Eigen/Dense>
#include <matplot/matplot.h>
#include <cmath>

using Eigen::MatrixXd;

int main(void)
{
    // MatrixXd m(2,2);
    // m(0,0) = 3;
    // m(1,0) = 2.5;
    // m(0,1) = -1;
    // m(1,1) = m(1,0) + m(0,1);
    
    // std::cout << m << std::endl;
    MatrixXd m = MatrixXd::Random(3,3);
    m = (m + MatrixXd::Constant(3,3,1.2)) * 50;
    std::cout << "m = " << std::endl << m << std::endl;

    Eigen::VectorXd v(3);
    v << 1, 2, 3;
    std::cout << "m * v = " << std::endl << m * v << std::endl;

    // Testing various functions
    m.resize(9,1);
    std::cout << "Resized m = " << std::endl << m << std::endl;

    // Testing Matplot++
    using namespace matplot;

    // double lat_seattle = 47.62;
    // double lon_seattle = -122.33;
    // double lat_anchorage = 61.20;
    // double lon_anchorage = -149.9;
    // geoplot(std::vector{lat_seattle, lat_anchorage}, std::vector{lon_seattle, lon_anchorage}, "g-*");
    // geolimits({45, 62},{-155, -120});
    // show();

    std::vector<double> x = linspace(0, 2 * pi);
    std::vector<double> y = transform(x, [](auto x) {return sin(x); });
    plot(x, y, "-o");
    hold(on);
    show();
    return 0;
}

