#!/usr/bin/perl
use strict;
use warnings;

# +< +> >>
open(my $fh, ">", "output.txt")
    or die "can't open > output.txt: $!";

print $fh  "1:this line gets printed into output.txt.\n";
printf $fh "2:this line gets printed into output.txt.\n";

