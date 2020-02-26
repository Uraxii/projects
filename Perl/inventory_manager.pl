#!/usr/bin/perl

# This application will create and modify an invintory system.
	# Being able to use a HTML file for this would be nice.
	# If I REALLY want to, I can probably make a HTML for this and use a web server to use this anywhere.
use strict ;
use warnings ;

=comment --- FREQUENT STAEMENTS ---
print "---DEBUG--- \n" ;

=cut

#Variables used in applocation
my $input;
# --------- MAIN MENU ---------
sub menu{
print "Welcome!\n" ;
print "1) Locations\n" ;
print "2) Create Location\n" ;
print "3) Look Up\n" ;
print "4) Exit\n" ;

chomp( $input = <> ) ;
print "---DEBUG--- \$input=[$input]\n" ;

	if ($input == 1){
		## --- LIST ALL LOCATIONS ---
		print "---DEBUG--- \$input=[$input]\n" ;
	
		# --- RE-RUN MAIN MENU ROUTINE --- ; 
	}
	elsif ($input == 2){
		## --- CREATE NEW LOCATION ---
		print "---DEBUG--- \$input=[$input]\n" ;
		## --- CREATE NEW TEXT FILE	---
		print "Make another location?\n"
		print "y/n?" ;
		$input = <>
			if ($input = "y"){
				
			}
			elsif ($input = "n"){
			
			}
			else{
				print "Invalid Command.\n" ;
				print "---DEBUG--- \$input=[$input]\n" ;
			}
	elsif ($input == 3){
		## --- OPEN EACH LIST, SEARCH FOR THE ITEM, DISPLAY WHERE IT IS FOUND, AND QUANTITY ---
		print "---DEBUG--- \$input=[$input]\n" ;
	}
	elsif ($input == 4){
		print "---DEBUG--- \$input=[$input]\n" ;
		exit ;
	}
	else{
		print "ERROR [1] --- Invalid Command. Please try again." ;
		print "---DEBUG---\$input=[$input]\n" ;
		# --- RE-RUN MAIN MENU ROUTINE --- ; 
	}
}
}
# ----------------------------------

# --------- LIST LOCATIONS ---------
sub location{

}
# ----------------------------------

# ------ CREATE LOCATION -----------
sub create{

}
# ----------------------------------

# ------- SEACH FOR ITEM -----------
sub search{

}
# ----------------------------------

# ----------------------------------
# ----------------------------------

=comment --- OLD CODE ---
This is older/scratch code that was used throughout development. Mostly used as a refference point.

=cut

=comment --- OLD APP ---
This is a half-baked previous attempt I never finished.

#!usr/bin/perl
use strict ;
use warnings ;
# This program is designed to help with storage organization needs.
    # This program will allow users to assign locations to items, search for items + their locations, modify items + locations, and delete items + locations.
    # This program will not allow the deletion of locations as long as there are items stored at it.
    # This program will make a daily file detailing changes to invintory if changes were made.
    

my $file eq "invintory" ;
my $fh ;
my @lines ;
my $wtd ;
my $temp ;
my @locations ;

open ($fh,"<$file") ;
chomp ( @lines = <$fh> ) ;
close $fh ;

print "What would you like to do?\n" ;
print "Search for an item\n Add a new item\n" ;
$wtd = <STDIN> ;
print "DEBUG - [$wtd]\n" ;

# @locations is an @ to refference other @s (the locations @s that contain the item contents).
    # Using my @location will clear the array everytime I open the appliaction.
        # I suppose, I could print to a text file [Item][Location][Type][Quantity] and pull from that when I need it.
            # I could probably use recursion to populate the @s.
foreach ( @lines ){
    $_ ~= /[.*][(.*)][.*]/ ;
    $temp = $1 ;
    print "DEBUG - [$temp]\n" ;
    push ( @locations, $temp ) ;
    print "DEBUG - [@locations]\n" ;
}

exit ;
=cut

