#include <python2.6/Python.h>
#include "test.cpp"
#include <iostream>
using namespace std;

class a ca;

//static PyObject * wrap_test_fun(PyObject *self, PyObject *args) {  
//	char * command;  
//	int tmp = 0;
//	char * com2;
//	const char* str;  
//	if (!PyArg_ParseTuple(args, "sis", &command, tmp, &com2))//这句是把python的变量args转换成c的变量command  
//		return NULL;  
//	str = bye(command, tmp, com2);//调用c的函数  
//	return Py_BuildValue("s", str);//把c的返回值n转换成python的对象  
//}  



static PyObject * wrap_test_fun(PyObject *self, PyObject *args) {  
	char * command;  
	int tmp = 0;
	char * com2;
	const char* str;  
	if (!PyArg_ParseTuple(args, "sis", &command, &tmp, &com2))//这句是把python的变量args转换成c的变量command  
		return NULL;  
	str = bye(command, tmp, com2);//调用c的函数  
	return Py_BuildValue("s", str);//把c的返回值n转换成python的对象  
}  

static PyObject * wrap_set_fun(PyObject *self, PyObject *args) {  
	int tmp = 0;
	if (!PyArg_ParseTuple(args, "i", &tmp))//这句是把python的变量args转换成c的变量command  
		return NULL;  
	cout << "in wrap set fun, i="<< tmp<< endl;
	ca.set(tmp);//调用c的函数  
	cout << "in wrap set fun, after set, i="<< tmp<< endl;
	return Py_BuildValue("s","");//把c的返回值n转换成python的对象  
}  
static PyObject * wrap_print_fun(PyObject *self, PyObject *args) {  
	ca.aprint();//调用c的函数  
	return NULL;//把c的返回值n转换成python的对象  
}  

// 3 方法列表  
static PyMethodDef MyCppMethods[] = {  
	//MyCppFun1是python中注册的函数名，wrap_my_c_fun是函数指针  
	{ "MyCppFun1", wrap_test_fun, METH_VARARGS, "Execute a shell command." },  
	{ "set", wrap_set_fun, METH_VARARGS, "Execute a shell command." },  
	{ "aprint", wrap_print_fun, METH_VARARGS, "Execute a shell command." },  
	{ NULL, NULL, 0, NULL }  
};  
// 4 模块初始化方法  
PyMODINIT_FUNC initMyCppModule(void) {  
	//初始模块，把MyCppMethods初始到MyCppModule中  
	PyObject *m = Py_InitModule("MyCppModule", MyCppMethods);  
	if (m == NULL)  
		return;  
}  
