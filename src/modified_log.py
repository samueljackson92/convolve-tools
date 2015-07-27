import numpy as np
import numpy.ctypeslib as npct
import ctypes
from ctypes import c_int

# input type for the cos_doubles function
# must be a double array, with single dimension that is contiguous
array_1d_double = npct.ndpointer(dtype=np.double, ndim=2, flags="C_CONTIGUOUS")

# load the library, using numpy mechanisms
_lib_convolve = npct.load_library("libconvolve_tools", ".")

# setup the return typs and argument types
_lib_convolve.py_convolve.restype = None
_lib_convolve.py_convolve.argtypes = \
    [array_1d_double, array_1d_double, array_1d_double,
     c_int, c_int, c_int]


def convolve(in_array, kernel, out_array=None):

    if out_array is None:
        out_array = np.empty(in_array.shape)

    if in_array.shape != out_array.shape:
        raise RuntimeError("Size of output array must match input array")

    in_h, in_w = in_array.shape
    kernel_h, kernel_w = kernel.shape
    _lib_convolve.convolve_py(in_array, kernel, out_array,
                              in_h, in_w, kernel_h, kernel_w)

    return out_array

if __name__ == "__main__":
    a = np.zeros((10, 10), dtype=np.double)
    a[5][5] = 10.0
    k = np.zeros((5, 5), dtype=np.double)
    k[2][2] = 10.0
    o = np.zeros(a.shape, dtype=np.double)

    print convolve(a, k, o)
