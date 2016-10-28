#Py Plot

```python
import matplotlib.pyplot as plt
```

Read Files

```python

dataset1 = numpy.genfromtxt('file.csv', delimiter=',', usecols= 1, skip_header=1)
dataset2 = numpy.genfromtxt('file.csv', delimiter=',', usecols= 2, skip_header=1)
```
Generic Plotting:
```python

plt.close(1)
plt.figure(1)
plt.plot(PWM_3s, Thrust_3s,  color = 'r')
plt.plot(PWM_4s, Thrust_4s,  color = 'b')

#plt.xticks(numpy.linspace(0, 500, 11))
#plt.axis([10, 410,-70, -20])
plt.legend(['3S', '4S'], loc = 4)
plt.grid()
plt.xlabel("Pulse Time (ns)")
plt.ylabel("Thrust (g)")
plt.title("3s vs 4s Thrust GemFan 5030")
plt.savefig("GF5030_3sV4s_Thrust.png")
#plt.show(block=False)
plt.show()

```
