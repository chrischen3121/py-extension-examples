#include <Python.h>

// Define C++ Class
class CppAdd {
 public:
  inline int add(int a, int b) {
    return a + b;
  };
};

// Wrap add
static PyObject *method_add(PyObject *self, PyObject *args) {
  int a, b = 0;
  /* Parse arguments */
  if(!PyArg_ParseTuple(args, "ii", &a, &b)) {
    return NULL;
  }
  CppAdd cppadd;
  return PyLong_FromLong(cppadd.add(a, b));
}

// Declare all methods
static PyMethodDef cppadd_methods[] = {
    {"add", method_add, METH_VARARGS, "addition"},
    {NULL, NULL, 0, NULL}
};

// Define module
static struct PyModuleDef cppadd_module = {
    PyModuleDef_HEAD_INIT,
    "cppadd",
    "cppadd doc",
    -1,
    cppadd_methods
};

// Module init function
PyMODINIT_FUNC PyInit_cppadd(void) {
    return PyModule_Create(&cppadd_module);
}
