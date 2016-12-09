# C64Cartridge
A C64 and C128 cartridge that allow multiple cartridge images inb one physical cartridge.

![Cartridge](http://i.imgur.com/pkQG7xn.png)


A simple cartridge which can store several switch selecatble images. The type of images is also switch selectable.

Due to a stupid design mistake the upper and lower switch is not independent which means that only in total 16 locations can be used. But since some cartridges make use of only the upper or only the lower part they can shar the same index.
The design mistake can be circumvented using 8 diodes making the wire-ORing work. But since I have no real use for that many cartridges I do not intend to do another production run and test it. Another way is to skip one of the rotary switches and install a short jumper wire between the middle terminals.

![Modification](http://i.imgur.com/1ToQ6ZJ.png)

Attach a patch wire as indicated by the white dash in the picture above (in the top right corner of the back side). This will give you a design that can have at most sixteen indexes in total. But since some cartridges are only 8k in size an make use of either the upper or lower memory bank they can be combined. Then the same index provide two different cartridges and it is just a matter of setting the dipswitches to select which is used. 

This is how it goes when you do the PCB design directly out of your head and bypassing the schematic stage...

The board is availble at [OSHpark as a shared design](https://oshpark.com/shared_projects/bvZLwrlV). 

|  Designator |  Component | Vendor  #  |
|-------------|------------|------------|
|     U1      | SST39F020A |[804-39SF020A7CPHE](http://www.mouser.se/Search/ProductDetail.aspx?R=SST39SF020A-70-4C-PHE)|
|     U2      |   74LS07   |[595-SN74LS07DR](http://www.mouser.se/Search/ProductDetail.aspx?R=SN74LS07DR)|
|   C1, C2    |   0.1uF    | [BT627](http://www.bde.se/skat11_1.pdf)|
|  R1-R6      |  1k        |[603-RC0805JR-071KL](http://www.mouser.se/Search/ProductDetail.aspx?R=RC0805JR-071KL)|
|  U3-U4      | ELMA 07-0163|[BT922](http://www.bde.se/skat11_1.pdf)|
|  U5         | 2p switch  | [Aliexpress](https://www.aliexpress.com/item/10PCS-Lot-DIP-Switch-2-Way-2-54mm-Toggle-Switch-Red-Snap-Switch-Wholesale-Electronic/32505856138.html?spm=2114.13010608.0.0.X1ZaV7)|


There is a small tool as well, combine, that is used to combine several 8k or 16k cartridge images. It takes the following arguments:
```
-o <output-file>      - used to specify the output file. Only the last -o option detected.
-h <high index>       - the file is read into the high area at the index of the areas is speciied
-l <low index>        - the file is read into the low area at the index specified
-u                    - the upper 8k of the input files is read
-f <input filename>   - the input file name
```
It is possible to specify many -f options. Each -f option has to be preceeded by -h or -l and an index to specify the destination address in the ROM. a -u is optional to specify use of upper 8k of a 16k cartridge image.

For programming the Flash memory device I used a [Autoelectric TL866A](http://www.autoelectric.cn/EN/TL866_MAIN.html).



