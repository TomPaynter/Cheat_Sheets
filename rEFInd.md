# Grub Coup

When reinstalling Ubuntu I found that the rEFInd menu ran away, this fixed it!

Install refind, on Ubuntu

```
sudo apt-add-repository ppa:rodsmith/refind
sudo apt-get update
sudo apt-get install refind
```

Then run this:

```
sudo refind-mkdefault
```

And everythings back to normal!
