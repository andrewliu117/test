#include <boost/python.hpp>
#include "test.cpp"
BOOST_PYTHON_MODULE(hello_bye)
{
   using namespace boost::python;
   def("hello", hello);
   def("bye",bye);
}
