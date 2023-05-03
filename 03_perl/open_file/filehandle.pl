#!/usr/bin/perl
use strict;
use warnings;

#https://perldoc.perl.org/perlopentut
print STDERR "This is a debugging message.\n";
print STDOUT "Please enter somthing:"; 
my $response = <STDIN> || die "how come no input?";
chomp($response);
print STDOUT "response=$response Thank you!\n";
