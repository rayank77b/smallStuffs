#!/usr/bin/perl 

# simple test is there more input in sub
sub blub {
	my $l1 = shift @_;
	
	if (scalar(@_) % 2) {
		$l2 = shift @_;
		print "zweite: $l2\n";
	}
	
	print "erste: $l1\n";
}

blub("hallo","blkub");

blub("11111");


# geht the perl version
$command= $];
print "Perl version : ".$command;

# use featured functions
use v5.10;
say 'Hello, world!';
