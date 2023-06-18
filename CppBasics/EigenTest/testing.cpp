#include <iostream>
#include <Eigen/Dense>

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
}

