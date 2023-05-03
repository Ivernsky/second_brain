#!/usr/bin/perl
use strict;
use warnings;
#perldoc perlref
my @array = (1,2,3);
my %hash  = (1,2,3,4);
my $x     = 1;

my $aref = \@array;
my $href = \%hash;
my $sref = \$x;

$aref = [2,2,3,4,5,6];
print "@{$aref}\n";
print "${$aref}[2]\n";

my $my_hash = { APR => 4, AUG => 8};
my @my_hash_keys = keys %{$my_hash};
print "%{$my_hash}\n";
print "@my_hash_keys\n";
print "${$my_hash}{APR}\n";
