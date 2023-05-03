#!/usr/bin/perl
use strict;
use warnings;
#perldoc intro
print "hello world";
#this is a comment 
print 
    "hello, world"
    ;
print "\n";
print 'hello world\n';
print "\n";

# perl variable types
## scalars
my $aninal = "camel";
my $answer = 42;

## arrays
my @animals = ("camel","llama","owl");
my @numbers = (23,42,69);
my @mixed   = ("camel",42,1.23);
print "animals[0]:$animals[0]\n";
print "animals[-1]:$animals[-1]\n";
print "animals[\$#animals]:$animals[$#animals]\n";
print "\@animals[0,1]:@animals[0,1]\n";
print "\@animals[0..2]:@animals[0..2]\n";

## hash
#my %fruit_color = ("apple", "red", "banana", "yellow");
my %fruit_color = ("apple"=>"red", "banana"=>"yellow");
my @fruits = keys %fruit_color;
my @colors = values %fruit_color;
print "fruit_color:$fruit_color{'apple'}\n";

## conditional and looping constructs
# if () {
# }
# elsif () {
# }
# else {
# }

# while () {
# }
# until () {
# }
#
for (my $i=0 ; $i <= 10; $i++){
    print "for: $i\n";
}

foreach (@fruits){
    print "foreach: $_\n";
}
print "foreach 0..2 -> $_\n" foreach 0..2;

## regular expressions
foreach (@fruits){
    if(/apple/) {
        print "1 match $_\n";
    }
    elsif ($_ =~ /ban/){
        print "2 match $_\n";
        my $a = $_;
        $a =~ s/na/NA/;
        #$a =~ s/na/NA/g;
        print "\$a: $a\n";
    }
}

my $email = 'google@gmail.com';
if ($email =~ /([^@]+)@(.+)/){
    print "re matching for $email\n";
    print "\$1: $1\n";
    print "\$2: $2\n";
}


## writing subroutines
sub logger {
        #my $logmessage = shift;
    my $logmessage = @_[0];
    open my $logfile, ">>", "my.log" or die "COuld not open my.log:$!";
    #print $logfile $logmessage;
    print "[INFO]:$logmessage"
}
logger("we have a logger subroutine!\n");
