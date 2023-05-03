#!/usr/bin/perl
use strict;
use warnings;

#https://perldoc.perl.org/perlopentut
open(my $fh, "<", "input.txt")
    or die "can't open < input.txt: $!";

#1
while (my $line = <$fh>) {
    print "$line";
}

#2
while (<$fh>) {
    print "$_"
}

