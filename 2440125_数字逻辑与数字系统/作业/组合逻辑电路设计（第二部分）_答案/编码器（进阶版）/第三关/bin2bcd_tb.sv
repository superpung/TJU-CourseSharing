`timescale 1ns/1ps

module bin2bcd_tb();

	logic	[7 : 0] bin;
	logic		EN;
	logic	[9 : 0]	bcd;
	logic		valid;

	integer i;

	bin2bcd UDT(.bin(bin), .EN(EN), .bcd(bcd), .valid(valid));

	initial begin
	
		bin = 8'b0000_0000;
		EN = 1'b0;
		#20;
		EN = 1'b1;
		for (i = 0; i < 256; i++) begin
			bin = i;
			#20;
		end

	end 

	initial begin
		$timeformat(-9, 0, "ns", 5);
		$monitor("At time %t: EN = %b, bin = %b, bcd = %b, valid = %b", $time, EN, bin, bcd, valid);
	end

	initial begin

		$dumpfile("bin2bcd.vcd");
		$dumpvars(0, bin2bcd_tb);

	end		

endmodule
