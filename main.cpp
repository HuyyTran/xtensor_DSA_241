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

void test_xarray_basic()
{
  cout << "---------------BEGIN run test_xarray-------------" << endl;
  // begin-------------Initialization--------------------------------
  // xt::xarray<double>::shape_type shape = {2, 3};
  // xt::xarray<double> a0(shape);
  // xt::xarray<double> a1(shape, 2.5);
  // xt::xarray<double> a2 = {{1., 2., 3.}, {4., 5., 6.}};
  // auto a3 = xt::xarray<double>::from_shape(shape);
  // cout<<"shape = "<<xt::adapt(shape)<<endl;
  // cout<<"a0 = "<<a0<<endl;
  // cout<<"a1 = "<<a1<<endl;
  // cout<<"a2 = "<<a2<<endl;
  // cout<<"a3 = "<<a3<<endl;
  // end-------------Initialization----------------------------
  // end-------------Initialization--------------------------------
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

  // begin-------------Shape - dimensions - size--------------------------------
  // xt::xtensor<double, 3> b = {{{11., 22., 33., 5}, {33., 44., 55., 5}, {33., 44., 55., 5}},
  //                             {{131., 22., 33., 5}, {5, 343., 44., 55.}, {32., 14., 65., 2}}};
  // auto size = b.size();     // size = 24
  // auto dim = b.dimension(); // dim = 3
  // auto shape = b.shape();   // shape = {2, 3, 4}
  // auto sh0 = b.shape(0);    // sh1 = 2;
  // auto sh1 = b.shape(1);    // sh1 = 3;
  // auto sh2 = b.shape(2);    // sh1 = 4;
  // cout << b << endl;
  // cout << "size = " << size << endl;
  // cout << "dim = " << dim << endl;
  // cout << "shape = " << xt::adapt(shape) << std::endl;
  // cout << "sh0 = " << sh0 << endl;
  // cout << "sh1 = " << sh1 << endl;
  // cout << "sh2 = " << sh2 << endl;
  // end-------------Shape - dimensions - size--------------------------------

  // begin-------------RESHAPE--------------------------------
  //   xt::xarray<double> a0 = {1., 2., 3., 4., 5., 6.};
  //   cout<<"current: "<<endl;
  //   cout<<a0<<endl;
  //   cout<<"shape = "<<xt::adapt(a0.shape())<<endl; //shape = {6}
  //   cout<<"dimention= "<<a0.dimension()<<endl; //dimention= 2
  //   cout<<endl;

  //   a0.reshape({3,2});
  //   cout<<"after 1st reshape: "<<endl;
  //   cout<<a0<<endl;
  // //  {{ 1.,  2.},
  // //  { 3.,  4.},
  // //  { 5.,  6.}}
  //   cout<<"shape = "<<xt::adapt(a0.shape())<<endl; //shape = {3, 2}
  //   cout<<"dimention= "<<a0.dimension()<<endl; //dimention= 2
  //   cout<<endl;

  //   a0.reshape({2,3});
  //   cout<<"after 2nd reshape: "<<endl;
  //   cout<<a0<<endl;
  // //  {{ 1.,  2.,  3.},
  // //  { 4.,  5.,  6.}}
  //   cout<<"shape = "<<xt::adapt(a0.shape())<<endl;//shape = {2, 3}
  //   cout<<"dimention= "<<a0.dimension()<<endl; //dimention= 2
  //   // outputs {{1., 2., 3.}, {4., 5., 6. }}
  // end-------------RESHAPE--------------------------------

  // xt::xtensor_fixed<double, xt::xshape<2, 2>> c = {{1.1, 2.2}, {3.3, 4.4}};
  // std::cout << c << std::endl;

  // begin-------------RESIZE--------------------------------
  // xt::xarray<double> a0 = {1., 2., 3, 4., 3, 2};
  // a0.resize({2, 3});
  // cout<<a0<<endl;
  // end-------------RESIZE--------------------------------

  // begin-------------Element Access--------------------------------
  // xt::xarray<double> a = {{1., 2., 3.}, {4., 5., 6.}};
  // double d0 = a(0, 2);   // d0 is 3.
  // double d1 = a(1);      // d1 is a(0, 2)
  // double d2 = a[{0, 2}]; // d2 is a(0, 2)
  // cout<<"d0 = "<<d0<<endl;
  // cout<<"d1 = "<<d1<<endl;
  // cout<<"d2 = "<<d2<<endl;
  // end-------------Element Access--------------------------------

  // start-------------Data buffer--------------------------------
  // xt::xarray<double> a = {{1., 2., 3.}, {4., 5., 6.}};
  // a.data()[3] = 8.;
  // std::cout << a << std::endl;
  // Outputs {{1., 2., 3.}, {8., 5., 6.}}

  // end-------------Data buffer--------------------------------
  cout << "---------------END run test_xarray-------------" << endl;
}

void test_xarray_views(){

}


int main(int argc, char *argv[])
{
  // test_default();
  // test_svector();
  test_xarray_basic();
  // test_xarray_views();
  return 0;
}