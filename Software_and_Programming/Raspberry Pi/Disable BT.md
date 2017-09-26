# Disable Bluetooth

For some applications you need a hardware UART line, on the Pi3 its /dev/ttyAMA0, which is used as the bluetooth. To disable that and give the Hardware UART back to the GPIO:

```
sudo nano /boot/config.txt
```

Add to the end of the file

```
dtoverlay=pi3-disable-bt
```
We also need to run to stop BT modem trying to use UART

```
sudo systemctl disable hciuart
```

Thanks to:

https://openenergymonitor.org/forum-archive/node/12311.html
