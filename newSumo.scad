$fn = 80;
difference(){
	cube([100,100,100], center=true);	
	translate([42,-2,-20]){
		#rotate([0,90,0]) cylinder(r=40,h=18,center=true);
	}
	translate([-42,-2,-20]){
		#rotate([0,90,0]) cylinder(r=40,h=18,center=true);
	}
	translate([0,0,-42]){
		rotate([0,0,0]) cube([60,60,18],center=true);
	}
	translate([0,0,14]){
		rotate([0,0,0]) cube([90,90,90],center=true);
	}
	translate([0,10,-34]){
		rotate([0,0,0]) cube([10,40,10],center=true);
	}
	
translate([0,-40,-48]){
	rotate([0,0,0]) cube([14,18,5],center=true);
}
translate([25,-40,-48]){
	rotate([0,0,0]) cube([14,18,5],center=true);
}
translate([-25,-40,-48]){
	rotate([0,0,0]) cube([14,18,5],center=true);
}

translate([0,-33,-48]){
	rotate([0,0,0]) cube([14,4,50],center=true);
}
translate([25,-33,-48]){
	rotate([0,0,0]) cube([14,4,50],center=true);
}
translate([-25,-33,-48]){
	rotate([0,0,0]) cube([14,4,50],center=true);
}
translate([13.5,-50,-18]){
	rotate([90,0,0]) cylinder(r=9, h=20,center=true);
}
translate([-13.5,-50,-18]){
	rotate([90,0,0]) cylinder(r=9, h=20,center=true);
}
translate([0,40,-46]){
	rotate([0,0,0]) cylinder(r=2,h=20,center=true);
}
translate([41,-41,-48]){
	rotate([0,0,0]) cylinder(r=2,h=20,center=true);
}
translate([-41,-41,-48]){
	rotate([0,0,0]) cylinder(r=2,h=20,center=true);
}
}



