uble> a = {{1., 2., 3.}, {4., 5., 6.}};
  double d0 = a(0, 2);   // d0 is 3.
  double d1 = a(1);      // d1 is a(0, 2)
  double d2 = a[{0, 2}]; // d2 is a(0, 2)
  cout<<"d0 = "<<d0<<endl;
  cout<<"d1 = "<<d1<<endl;
  cout<<"d2 = "<<d2<<endl;