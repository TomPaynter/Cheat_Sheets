Open and close serial port:


- Timeout - Timeout for read string, returns after x characters or timeout
- Baudrate - Serial Baudrate
- Device path - Note that the * wild card does NOT work!


```python
import serial
ser = serial.Serial('/dev/ttyUSB0', baudrate=230400, timeout=1)  # open serial port

ser.close()
```

Read 100 bytes from serial or until timeout occurs:


```python
mydatastring = ser.read(100)
```
