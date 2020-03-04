#!/bin/bash

i=322424820

while [ $i  -lt 322424846 ]

do

   x=`printf "%d\n"  $i`

   echo $x > /tmp/lv33
   echo $x

   cat /tmp/lv33 - | ~/level03

   i=`expr $i + 1`

done
