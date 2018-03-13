#!/bin/sh
for i in $(ls); do rm $i/a.out 2>/dev/zeros ; done
