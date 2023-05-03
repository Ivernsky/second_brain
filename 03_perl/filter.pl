#!/usr/bin/perl
use strict;
use warnings;
my $a = 'gate\napple\nwhat\nkinte\n';
print "yes\n" if $a =~ /gate/;

#printf 'gate\napple\nwhat\nkinte\n' | perl -ne 'print if /e/'
#printf 'gate\napple\nwhat\nkinte\n' | perl -ne 'print if not /e/'
