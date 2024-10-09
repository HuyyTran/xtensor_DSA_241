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
  cout<<"d0 = "<<d0<<endl; // d0 = 3
  cout<<"d1 = "<<d1<<endl; // d1 = 2
  cout<<"d2 = "<<d2<<endl; // d2 = 4
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
    std::cout << "Original array before modification:\n" << a << std::endl;
    // Create a view for the first row
    auto first_row = xt::view(a, 0, xt::all());

    // Access elements of the view
    std::cout << "First element of the view: " << first_row(0) << std::endl;  // Output: 1

    // Modify an element through the view
    first_row(1) = 10.0;
    
    // View after modification
    std::cout << "Modified view: " << first_row << std::endl;  // Output: {1., 10., 3.}

    // Original array is also modified
    std::cout << "Original array after modification:\n" << a << std::endl;
    // end-------------flexible Sliced views--------------------------------
  cout << "---------------END run test_xarray_views-------------" << endl;
}

int main(int argc, char *argv[])
{
  // test_default();
  // test_svector();
  // test_xarray_basic();
  test_xarray_views();
  return 0;
}