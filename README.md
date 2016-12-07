# C64Cartridge
A C64 and C128 cartridge that allow multiple images,

![Cartridge](http://i.imgur.com/pkQG7xn.png)


A simple cartridge which can store several switch selecatble images. The type of images is also switch selectable.

Due to a stupid design mistake the upper and lower switch is not independent which means that only in total 16 locations can be used. But since some cartridges make use of only the upper or only the lower part they can shar the same index.
The design mistake can be circumvented using 8 diodes making the wire-ORing work. But since I have no real use for that many cartridges I do not intend to do another production run and test it.

This is how it goes when you do the PCB design directly out of your head and bypassing the schematic stage...

The board is availble at OSHpark as a shared design.

The U1 ROM used is a SST 39SF020A which can be bought from Mouser, article #, [804-39SF020A7CPHE](http://www.mouser.se/Search/ProductDetail.aspx?R=SST39SF020A-70-4C-PHE), U2 is 74LS07, Mouser # [595-SN74LS07DR](http://www.mouser.se/Search/ProductDetail.aspx?R=SN74LS07DR)

