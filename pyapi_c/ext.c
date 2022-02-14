#include <Python.h>

// Define C function
int add(int a, int b) {
  return a + b;
}

// Wrap add
static PyObject *method_add(PyObject *self, PyObject *args) {
  int a, b = 0;
  /* Parse arguments */
  if(!PyArg_ParseTuple(args, "ii", &a, &b)) {
    return NULL;
  }
  return PyLong_FromLong(add(a, b));
}

// Declare all methods
static PyMethodDef cadd_methods[] = {
    {"add", method_add, METH_VARARGS, "addition"},
    {NULL, NULL, 0, NULL}
};

// Define module
static struct PyModuleDef cadd_module = {
    PyModuleDef_HEAD_INIT,
    "cadd",
    "cadd doc",
    -1,
    cadd_methods
};

// Module init function
PyMODINIT_FUNC PyInit_cadd(void) {
    return PyModule_Create(&cadd_module);
}
