from distutils.core import setup, Extension

extension_mod = Extension("first_val", ["firstvalmodule.c", "firstval.c"])

setup(name="firstval", ext_modules=[extension_mod])
