pyHaversine
==============

An simple project built with [pybind11](https://github.com/pybind/pybind11).
This requires Python 3.6+; for older versions of Python, check the commit
history.

Installation
------------

 - clone this repository
 - `pip install ./pyhaversine`

CI Examples
-----------

There are examples for CI in `.github/workflows`. A simple way to produces
binary "wheels" for all platforms is illustrated in the "wheels.yml" file,
using [`cibuildwheel`][]. You can also see a basic recipe for building and
testing in `pip.yml`, and `conda.yml` has an example of a conda recipe build.


Building the documentation (no available)
--------------------------

Documentation for the example project is generated using Sphinx. Sphinx has the
ability to automatically inspect the signatures and documentation strings in
the extension module to generate beautiful documentation in a variety formats.
The following command generates HTML-based reference documentation; for other
formats please refer to the Sphinx manual:

 - `cd pyhaversine/docs`
 - `make html`

License
-------

pybind11 is provided under a BSD-style license that can be found in the LICENSE
file. By using, distributing, or contributing to this project, you agree to the
terms and conditions of this license.

Test call
---------

```python
import pyhaversine
pyhaversine.haversine((1.0, 2.0), (3.0, 4.0))
```

[`cibuildwheel`]:          https://cibuildwheel.readthedocs.io
