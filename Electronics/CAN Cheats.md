# CAN Cheats!

## A bit on Masks and Filters!

A filter is the be all and end all, it decides to accept the data to the buffer or dump it. A filter will be composed of a bit field as long as the ID of the CAN message.

If the CAN ID matches the filter it is let through to the buffer.

Now the mask is like a wild	card to the filter. If the corresponding mask bit is a 1 then the filter bit MUST match the corresponding ID bit in order for it
to be passed. If its a 0 then it is a dont care bit. ie

Mask = 	0b01101101
Filter=	0b11011011
Passes=	0bx10x10x1
  ie	0b11011011
    0b01011011
    0b11001001 ect

Think of the mask as a filter bit enable function,  if it is a 0 it disables that filter checking ability.

The mask is a meh bit, if its a 0, it doesnt care and anythings let through. If its a 1 then its tough and must pass the filter test.
