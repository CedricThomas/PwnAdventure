#!/usr/bin/python3
from scapy.all import *
import sys
import os


translate_table = [
    (),
    (),
    (),
    (),
    (),
    (),
    (),
    (),
    (),
]

IP = "127.0.0.1"

def redirect(input, output):
    print("[+] redirecting network traffic from {} to {}".format(input, output))
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.bind((IP, input))
    while True:
         data, addr = sock.recvfrom(1024) # buffer size is 1024 bytes
         print("received message:", data)



send grosse pute de merde:

0000   00 00 00 00 00 00 00 00 00 00 00 00 08 00 45 00   ..............E.
0010   00 62 2d da 40 00 40 06 0e ba 7f 00 00 01 7f 00   .b-.@.@.........
0020   00 01 e3 da 0b b8 db 5a ea 32 47 9a c6 cd 80 18   .......Z.2G.....
0030   02 00 fe 56 00 00 01 01 08 0a 08 bc 84 32 08 bc   ...V.........2..
0040   83 c9 23 2a 14 00 67 72 6f 73 73 65 20 70 75 74   ..#*..grosse put
0050   65 20 64 65 20 6d 65 72 64 65 6d 76 8f 28 2d c7   e de merdemv.(-.
0060   e8 b0 9d c6 92 52 20 45 46 fa 12 57 00 00 00 00   .....R EF..W....

receive:

0000   00 00 00 00 00 00 00 00 00 00 00 00 08 00 45 00   ..............E.
0010   00 52 da 94 40 00 40 06 62 0f 7f 00 00 01 7f 00   .R..@.@.b.......
0020   00 01 0b b8 e3 da 47 9a c6 cd db 5a ea 60 80 18   ......G....Z.`..
0030   02 00 fe 46 00 00 01 01 08 0a 08 bc 84 70 08 bc   ...F.........p..
0040   84 32 23 2a 1b 00 00 00 14 00 67 72 6f 73 73 65   .2#*......grosse
0050   20 70 75 74 65 20 64 65 20 6d 65 72 64 65 00 00    pute de merde..


send salut:

0000   00 00 00 00 00 00 00 00 00 00 00 00 08 00 45 00   ..............E.
0010   00 53 3a dd 40 00 40 06 01 c6 7f 00 00 01 7f 00   .S:.@.@.........
0020   00 01 e3 da 0b b8 db 5b 79 8c 47 9a d3 ef 80 18   .......[y.G.....
0030   02 00 fe 47 00 00 01 01 08 0a 08 be a8 ff 08 be   ...G............
0040   a8 d6 23 2a 05 00 73 61 6c 75 74 6d 76 8f 28 2d   ..#*..salutmv.(-
0050   c7 e8 b0 9d c6 92 52 20 45 6a c3 3a 9e ff ff 00   ......R Ej.:....
0060   00                                                .

receive :

0000   00 00 00 00 00 00 00 00 00 00 00 00 08 00 45 00   ..............E.
0010   00 43 e1 34 40 00 40 06 5b 7e 7f 00 00 01 7f 00   .C.4@.@.[~......
0020   00 01 0b b8 e3 da 47 9a d3 ef db 5b 79 ab 80 18   ......G....[y...
0030   02 00 fe 37 00 00 01 01 08 0a 08 be a9 38 08 be   ...7.........8..
0040   a8 ff 23 2a 1b 00 00 00 05 00 73 61 6c 75 74 00   ..#*......salut.
0050   00                                                .
