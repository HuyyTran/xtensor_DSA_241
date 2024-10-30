#include "main.hpp"
#include <iostream>
#include <string>
using namespace std;

//!  build g++ -fsanitize=address -o main -Iinclude -std=c++17 main.cpp
//! run : ./main
//! combo compile + run: ./run.sh && ./main
//! I've custom code runner on Mac, so that combo compile + run just need to press: Ctrl+Option+K

// Function declarations
void test_default();
void test_svector();
void test_xarray_basic();
void test_xarray_views();
void test_shuffle();
void test_operators(const std::string &op);
void test_mathematical_function();

void print_available_tests()
{
  std::cout << "Available tests:" << std::endl;
  std::cout << "  ./main test_default" << std::endl;
  std::cout << "  ./main test_svector" << std::endl;
  std::cout << "  ./main test_xarray_basic" << std::endl;
  std::cout << "  ./main test_xarray_views" << std::endl;
  std::cout << "  ./main test_shuffle" << std::endl;
  std::cout << "  ./main test_operators <operator>" << std::endl;
  std::cout << "  ./main test_mathematical_function" << std::endl;
}

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    std::cerr << "Usage: " << argv[0] << " <test_name>" << std::endl;
    print_available_tests();
    return 1;
  }

  std::string test_name = argv[1];

  if (test_name == "test_default")
  {
    test_default();
  }
  else if (test_name == "test_svector")
  {
    test_svector();
  }
  else if (test_name == "test_xarray_basic")
  {
    test_xarray_basic();
  }
  else if (test_name == "test_xarray_views")
  {
    test_xarray_views();
  }
  else if (test_name == "test_shuffle")
  {
    test_shuffle();
  }
  else if (test_name == "test_operators")
  {
    if (argc < 3)
    {
      std::cerr << "Usage: " << argv[0] << " test_operators <operator>" << std::endl;
      return 1;
    }
    std::string op = argv[2];
    test_operators(op);
  }
  else if (test_name == "test_mathematical_function")
  {
    test_mathematical_function();
  }
  else
  {
    std::cerr << "Unknown test name: " << test_name << std::endl;
    print_available_tests();
    return 1;
  }

  return 0;
}

void test_mathematical_function()
{
  cout << "---------------BEGIN run test_mathematical_function-------------" << endl;
  xt::xarray<double> x = {1, 5, 7};
  xt::xarray<double> y = {0.09, 0.2447, 0.6652};
  xt::xarray<double> X = {{1.0, 2.0},
                          {3.0, 4.0}};
  xt::xarray<double> DY = {{0.1, 0.2},
                           {0.0, 1.1}};
  xt::xarray<bool> m_aMask = {{true, false},
                              {true, true}};
  // Result of xt::where
  auto result = xt::where(m_aMask, X, 0.0);
  // result would be: {{1.0, 0.0},
  //                   {3.0, 4.0}}
  // cout<<result<<endl;
  xt::xarray<double> Y = {{-1.0, 0.0},
                          {0.0, 1.0}};
  auto res = Y >= 0;
  cout << "res = " << res << endl;
  auto res2 = res * X;
  cout << "res2 = " << res2 << endl;
  auto res3 = 1 / (X + 3);
  cout << "res3 = " << res3 << endl;

  auto exp = xt::exp(X); // Computes e^1, e^2, e^3, e^4 element-wise
  cout << "exp = " << exp << endl;
  auto exp2 = xt::exp2(X); // Computes 2^1, 2^2, 2^3, 2^4 element-wise
  cout << "exp2 = " << exp2 << endl;
  auto expm1 = xt::expm1(X); // Computes e^1-1, e^2-1, e^3-1, e^4-1 element-wise
  cout << "expm1 = " << expm1 << endl;

  auto tanh = xt::tanh(X); // Computes tanh(1), tanh(2), tanh(3), tanh(4) element-wise
  cout << "tanh = " << tanh << endl;

  auto DX = DY * (1 - tanh * tanh);
  cout << "DX = " << DX << endl;

  auto sum = xt::sum(X);
  cout << "sum = " << sum + 1 << endl;

  auto diag = xt::diag(x);
  cout << "diag = " << diag << endl;

  auto outer = xt::linalg::outer(y, y);
  cout << "outer = " << outer << endl;

  // Define the matrix Delta_z
  xt::xarray<double> Delta_z = {
      {0.0819, -0.0220, -0.0599},
      {-0.0220, 0.1848, -0.1635},
      {-0.0599, -0.1635, 0.2229}
  };

  // Define the vector
  xt::xarray<double> vec = {0.1, 0.2, 0.3};

  // Compute the dot product
  auto resz = xt::linalg::dot(Delta_z, vec);

  // Print the result
  std::cout << "Result of Delta_z dot vec: " << resz << std::endl;

  double N_norm = X.shape()[0];
  cout<< "N_norm(X) = "<<N_norm<<endl;

  double sum_log = xt::sum(x * xt::log(x))();
  cout<< "sum_log = "<<sum_log<<endl;

  cout << "---------------END run test_mathematical_function-------------" << endl;
}
void test_operators(const std::string &op)
{
  std::cout << "---------------BEGIN run test_operators-------------" << std::endl;
  xt::xarray<double> a = {{1., 2.}, {3., 4.}};
  std::cout << "Array a:\n"
            << a << std::endl;

  xt::xarray<double> b = {{2., 3.}, {1., 0.}};
  std::cout << "Array b:\n"
            << b << std::endl;

  xt::xarray<double> res;

  if (op == "+")
  {
    res = a + b;
  }
  else if (op == "-")
  {
    res = a - b;
  }
  else if (op == "*")
  {
    res = a * b;
  }
  else if (op == "/")
  {
    res = a / b;
  }
  else if (op == "r")
  {
    res = a > b;
  }
  else
  {
    std::cerr << "Unknown operator: " << op << std::endl;
    return;
  }

  std::cout << "Result of a " << op << " b:\n"
            << res << std::endl;
  std::cout << "---------------END run test_operators-------------" << std::endl;
}
void test_default()
{
  cout << "---------------BEGIN run test_default-------------" << endl;
  xt::xarray<double> X = {{1.0, 2.0},
                          {3.0, 4.0}};

  xt::xarray<bool> m_aMask = {{true, false},
                              {true, true}};
  // Result of xt::where
  auto result = xt::where(m_aMask, X, 0.0);
  // result would be: {{1.0, 0.0},
  //                   {3.0, 4.0}}
  // cout<<result<<endl;
  xt::xarray<double> Y = {{-1.0, 0.0},
                          {0.0, 1.0}};
  auto res = Y >= 0;
  cout << "res = " << res << endl;
  auto res2 = res * X;
  cout << "res2 = " << res2 << endl;
  auto res3 = 1 / (X + 3);
  cout << "res3 = " << res3 << endl;

  auto exp = xt::exp(X); // Computes e^1, e^2, e^3, e^4 element-wise
  cout << "exp = " << exp << endl;
  auto exp2 = xt::exp2(X); // Computes 2^1, 2^2, 2^3, 2^4 element-wise
  cout << "exp2 = " << exp2 << endl;
  auto expm1 = xt::expm1(X); // Computes e^1-1, e^2-1, e^3-1, e^4-1 element-wise
  cout << "expm1 = " << expm1 << endl;

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
  cout << "---------------BEGIN run test_xarray_basic-------------" << endl;
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
  xt::xarray<double> a = {{1., 2., 3.}, {4., 5., 6.}};
  double d0 = a(0, 2);
  double d1 = a(1);
  double d2 = a[3];
  cout << "d0 = " << d0 << endl; // d0 = 3
  cout << "d1 = " << d1 << endl; // d1 = 2
  cout << "d2 = " << d2 << endl; // d2 = 4
  // end-------------Element Access--------------------------------

  // start-------------Data buffer--------------------------------
  // xt::xarray<double> a = {{1., 2., 3.}, {4., 5., 6.}};
  // a.data()[3] = 8.;
  // std::cout << a << std::endl;
  // Outputs {{1., 2., 3.}, {8., 5., 6.}}

  // end-------------Data buffer--------------------------------
  cout << "---------------END run test_xarray_basic-------------" << endl;
}

void test_xarray_views()
{
  cout << "---------------BEGIN run test_xarray_views-------------" << endl;
  // begin-------------Sliced views--------------------------------
  // std::vector<size_t> shape = {3, 2, 4};
  // xt::xarray<int> a(shape);

  // // View with same number of dimensions
  // auto v1 = xt::view(a, xt::range(1, 3), xt::all(), xt::range(1, 3));
  // cout<<"v1 = "<<v1<<endl;
  // // => v1.shape() = { 2, 2, 2 }
  // // => v1(0, 0, 0) = a(1, 0, 1)
  // // => v1(1, 1, 1) = a(2, 1, 2)

  // // View reducing the number of dimensions
  // auto v2 = xt::view(a, 1, xt::all(), xt::range(0, 4, 2));
  // cout<<"v2 = "<<v2<<endl;
  // // => v2.shape() = { 2, 2 }
  // // => v2(0, 0) = a(1, 0, 0)
  // // => v2(1, 1) = a(1, 1, 2)

  // // View increasing the number of dimensions
  // auto v3 = xt::view(a, xt::all(), xt::all(), xt::newaxis(), xt::all());
  // cout<<"v3 = "<<v3<<endl;
  // // => v3.shape() = { 3, 2, 1, 4 }
  // // => v3(0, 0, 0, 0) = a(0, 0, 0)

  // // View with non contiguous slices
  // auto v4 = xt::view(a, xt::drop(0), xt::all(), xt::keep(0, 3));
  // cout<<"v4 = "<<v4<<endl;
  // // => v4.shape() = { 2, 2, 2 }
  // // => v4(0, 0, 0) = a(1, 0, 0)
  // // => v4(1, 1, 1) = a(2, 1, 3)

  // // View built with negative index
  // auto v5 = xt::view(a, -2, xt::all(), xt::range(0, 4, 2));
  // cout<<"v5 = "<<v5<<endl;
  // // => v5 == v2
  // end-------------Sliced views--------------------------------

  // start-------------xt::random::shuffle--------------------------------
  // Initialize a 2D xarray
  // xt::xarray<double> a = {{1., 2., 3.}, {4., 5., 6.}, {7., 8., 9.}};
  // std::cout << "Original array:\n" << a << std::endl;

  // // Create a random number engine
  // std::random_device rd;
  // std::mt19937 engine(rd());

  // // Shuffle the array along the first axis
  // xt::random::shuffle(a, engine);
  // std::cout << "Shuffled array:\n" << a << std::endl;
  // end-------------xt::random::shuffle--------------------------------
  // start-------------flexible Sliced views--------------------------------
  // Create a 2D array
  xt::xarray<double> a = {{1., 2., 3.}, {4., 5., 6.}};
  std::cout << "Original array before modification:\n"
            << a << std::endl;
  // Create a view for the first row
  auto first_row = xt::view(a, 0, xt::all());

  // Access elements of the view
  std::cout << "First element of the view: " << first_row(0) << std::endl; // Output: 1

  // Modify an element through the view
  first_row(1) = 10.0;

  // View after modification
  std::cout << "Modified view: " << first_row << std::endl; // Output: {1., 10., 3.}

  // Original array is also modified
  std::cout << "Original array after modification:\n"
            << a << std::endl;
  // end-------------flexible Sliced views--------------------------------
  cout << "---------------END run test_xarray_views-------------" << endl;
}

void test_shuffle()
{
  cout << "---------------BEGIN run test_shuffle-------------" << endl;
  // Define a 2D xarray
  xt::xarray<int> arr = {{1, 2, 3},
                         {4, 5, 6},
                         {7, 8, 9}};
  xt::xarray<int> arr_index;
  arr_index = xt::arange<int>(8);

  std::cout << "Original array:\n"
            << arr_index << "\n";

  // Create a random engine
  xt::random::default_engine_type engine(0);

  // Shuffle the array along the first axis (rows)
  xt::random::shuffle(arr_index, engine);

  std::cout << "Shuffled array:\n"
            << arr_index << "\n";

  cout << "---------------END run test_shuffle-------------" << endl;
}
