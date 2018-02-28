#include <Python.h>

// SOURCE: http://intermediate-and-advanced-software-carpentry.readthedocs.io/en/latest/c++-wrapping.html

char first_val(char * c);

static PyObject * first_val_wrapper(PyObject * self, PyObject * args){
    char * input;
    char result;
    PyObject * ret;

    if(!PyArg_ParseTuple(args, "s", &input)){
        return NULL;
    }
    
    result = first_val(input);

    ret = PyString_FromFormat("%c", result);

    return ret;
}

static PyMethodDef Methods[] = {
    { "first_val", first_val_wrapper, METH_VARARGS, "First string value" },
    { NULL, NULL, 0, NULL}
};

DL_EXPORT(void) initfirst_val(void)
{
    Py_InitModule("first_val", Methods);
}
