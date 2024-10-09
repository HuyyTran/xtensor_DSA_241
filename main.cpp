#include "main.hpp"

//!  build g++ -fsanitize=address -o main -Iinclude -std=c++17 main.cpp
//! run : ./main
//! combo compile + run: ./run.sh && ./main
//! I've custom code runner on Mac, so that combo compile + run just need to press: Ctrl+Option+K

void test_default()
{
  cout << "---------------BEGIN run test_default-------------" << endl;
  xt::xarray<double> a = {{1., 2.}, {3., 4.}};
  std::cout << a << std::endl;

  xt::xtensor<double, 2> b = {{1., 2.}, {3., 4.}};
  std::cout << b << std::endl;

  xt::xtensor_fixed<double, xt::xshape<2, 2>> c = {{1., 2.}, {3., 4.}};
  std::cout << c << std::endl;
  cout << "---------------END run test_default-------------" << endl;
}
void test_svector()
{
  cout << "---------------BEGIN run test_svector-------------" << endl;
  xt::svector<int> vec1;
  vec1.push_back(1);
  vec1.push_back(3);
  cout << vec1[1] << endl;
  cout << vec1.size() << endl;
  vec1.pop_back();
  cout << vec1.size() << endl;
  cout << "---------------END run test_svector-------------" << endl;
}

void test_xarray()
{
  cout << "---------------BEGIN run test_xarray-------------" << endl;
  // xt::xarray<double> a = {{1., 2., 3.}, {4., 5., 6.}};
  // auto size = a.size();     // size = 6
  // auto dim = a.dimension(); // dim = 2
  // auto shape = a.shape();   // shape = {2, 3}
  // auto sh0 = a.shape(0);    // sh1 = 3;
  // auto sh1 = a.shape(1);    // sh1 = 3;
  // cout<<a<<endl;
  // cout<<"size = "<<size<<endl;
  // cout<<"dim = "<<dim<<endl;
  // cout<<"sh0 = "<<sh0<<endl;
  // cout<<"sh1 = "<<sh1<<endl;
  // cout <<"shape = "<< xt::adapt(shape) << std::endl;

  // xt::xtensor<double, 2> b = {{1., 2.}, {3., 4.}};
  // std::cout << b << std::endl;

  xt::xtensor<double, 3> b = {{{11., 22., 33., 5}, {33., 44., 55., 5}, {33., 44., 55., 5}},
                              {{131., 22., 33., 5}, {5, 343., 44., 55.}, {32., 14., 65., 2}}};
  auto size = b.size();     // size = 6
  auto dim = b.dimension(); // dim = 2
  auto shape = b.shape();   // shape = {2, 3}
  auto sh0 = b.shape(0);    // sh1 = 3;
  auto sh1 = b.shape(1);    // sh1 = 3;
  auto sh2 = b.shape(2);    // sh1 = 3;
  cout << b << endl;
  cout << "size = " << size << endl;
  cout << "dim = " << dim << endl;
  cout << "shape = " << xt::adapt(shape) << std::endl;
  cout << "sh0 = " << sh0 << endl;
  cout << "sh1 = " << sh1 << endl;
  cout << "sh2 = " << sh2 << endl;
  
  // xt::xtensor<double, 1> b1 = {11., 22., 33.};
  // std::cout << b1 << std::endl;

  // xt::xtensor_fixed<double, xt::xshape<2, 2>> c = {{1.1, 2.2}, {3.3, 4.4}};
  // std::cout << c << std::endl;
  cout << "---------------END run test_xarray-------------" << endl;
}
int main(int argc, char *argv[])
{
  // test_default();
  // test_svector();
  test_xarray();
  return 0;
}