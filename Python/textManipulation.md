# Importing From Text File

Simply getting the data into a numpy array

[numpy.genfromtxt](https://docs.scipy.org/doc/numpy/reference/generated/numpy.genfromtxt.html)


```python
import numpy

newdata = numpy.genfromtxt('cheekydata.txt', comments='#', dtype=str)
```


# Slicing

This gets the first 5 characters of a string. Noting that the last is not inclusive

```python
mydatastring[0:6]
```
