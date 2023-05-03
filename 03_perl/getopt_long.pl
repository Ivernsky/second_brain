#!/usr/bin/perl
use strict;
use warnings;
use Getopt::Long;

my $data = "file.dat";
my $length = 24;
my $verbose= 0;
my @top ;

GetOptions ("length=i" => \$length, #numeric 
            "file=s"   => \$data,   #string
            "verbose"  => \$verbose, #flag
            "top=s{,}"    => \@top    
           )
or die("Error in command line arguments\n");
print "data=> $data\n";
print "length=> $length\n";
print "verbose=> $verbose\n";
print "top=>     @top\n";
