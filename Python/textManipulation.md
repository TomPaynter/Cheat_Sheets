# Importing From Text File

Simply getting the data into a numpy array

[numpy.genfromtxt](https://docs.scipy.org/doc/numpy/reference/generated/numpy.genfromtxt.html)


```python
import numpy

newdata = numpy.genfromtxt('cheekydata.txt', comments='#', dtype=str)
```


